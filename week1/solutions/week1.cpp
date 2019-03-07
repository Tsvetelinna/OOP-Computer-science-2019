#include <iostream>
#include <cassert>
using namespace std;

template <typename T>
struct DynArray {
    T *raw;
    int size;
    int capacity;
};

template <typename T>
DynArray<T> create(int initialCapacity = 2);

template <typename T>
void push_back(DynArray<T>& arr, T element);

template <typename T>
void resize(DynArray<T>& arr);

template <typename T>
void pop_back(DynArray<T>& arr);

template <typename T>
void remove(DynArray<T>& arr, int index);

template <typename T>
T get(DynArray<T>& arr, int index);

template <typename T>
void map(DynArray<T>& arr, T (*func)(T));

template <typename T>
void filter(DynArray<T>& arr, bool (*func)(T));

template <typename T>
void print(DynArray<T>& arr);

// simple function to pass to map
template <typename T>
T inc(T x) {
    return x + 1;
}

// simple function to pass to filter
bool isEven(int x) {
    return x % 2 == 0;
}

int main() {

    DynArray<int> dynArray = create<int>(2);
    push_back(dynArray, 12);
    push_back(dynArray, -8);
    push_back(dynArray, 777);
    push_back(dynArray, 7);
    push_back(dynArray, 7777777);
    push_back(dynArray, -17);

    // create pointer to inc(int)
    int (*increment)(int) = &inc;

    map(dynArray, increment);
    remove(dynArray, 2);

    print(dynArray);

    // directly pass isEven(int) to filter
    filter(dynArray, isEven);

    cout << endl;
    print(dynArray);

    return 0;
}

template <typename T>
DynArray<T> create(int initialCapacity) {
    DynArray<T> dynArray;
    dynArray.capacity = initialCapacity;
    dynArray.size = 0;
    dynArray.raw = new T[dynArray.capacity];

    return dynArray;
}

template <typename T>
void push_back(DynArray<T>& arr, T element) {
    if (arr.size == arr.capacity) {
        resize(arr);
    }
    
    arr.raw[arr.size++] = element;
}

template <typename T>
void resize(DynArray<T>& arr) {
    arr.capacity *= 2;

    T* old = arr.raw;
    arr.raw = new T[arr.capacity];

    for (int i = 0; i < arr.size; i++) {
        arr.raw[i] = old[i];
    }

    delete[] old;
}

template <typename T>
void pop_back(DynArray<T>& arr) {
    arr.size--;
}

template <typename T>
void remove(DynArray<T>& arr, int index) {
    assert(index >= 0 && index < arr.size);

    for (int i = index; i < arr.size - 1; i++) {
        arr.raw[i] = arr.raw[i + 1];
    }

    arr.size--;
}

template <typename T>
T get(DynArray<T>& arr, int index) {
    assert(index >= 0 && index < arr.size);

    return arr.raw[index];
}

template <typename T>
void map(DynArray<T>& arr, T (*func)(T)) {
    for (int i = 0; i < arr.size; i++) {
        arr.raw[i] = func(arr.raw[i]);
    }
}

template <typename T>
void filter(DynArray<T>& arr, bool (*func)(T)) {
    for (int i = 0; i < arr.size; i++) {
        if (!func(arr.raw[i])) {
            remove(arr, i);
            i--;
        }
    }
}

template <typename T>
void print(DynArray<T>& arr) {
    cout << "DynArray: \n";
    cout << "\tsize: " << arr.size << endl;
    cout << "\telements: \n";
    
    for (int i = 0; i < arr.size; i++) {
        cout << "\t\t" << get(arr, i) << endl;
    }
}
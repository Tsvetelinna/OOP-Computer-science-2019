#include <iostream>
#include "Person.h"

using namespace std;

const int SET_INITIAL_CAPACITY = 8;

template <typename T>
using MapFn = T (*)(T);

template <typename T>
using Predicate = bool (*)(T);

template <typename ResultT, typename ElementT>
using ReduceFn = ResultT (*)(ResultT, ElementT);

template <typename T>
class Set {

private:
    int setSize;
    int capacity;
    T* arr;

    void copy(const Set<T>& other) {

        this->setSize = other.setSize;
        this->capacity = other.capacity;
        this->arr = new T[capacity];

        for (int i = 0; i < this->setSize; i++) {

            this->arr[i] = other.arr[i];
        }
    }

    void erase() {

        delete[] arr;
    }

    void resize() {

        this->capacity *= 2;

        T* old = arr;
        this->arr = new T[capacity];

        for (int i = 0; i < this->setSize; i++) {

            this->arr[i] = old[i];
        }

        delete[] old;
    }

public:

    Set<T>() {

        this->capacity = SET_INITIAL_CAPACITY;
        this->setSize = 0;
        this->arr = new T[capacity];
    }

    Set<T>(const Set<T>& other) {

        copy(other);
    }

    Set<T>& operator=(const Set<T>& other) {

        if (&other!= this) {

            erase();
            copy(other);
        }

        return *this;
    }

    ~Set<T>() {

        erase();
    }

    bool contains(T element) const {

        for (int i = 0; i < this->setSize; i++) {

            if (this->arr[i] == element) {

                return true;
            }
        }

        return false;
    }

    bool add(T element) {

        if (contains(element)) {

            return false;
        }

        if (this->setSize >= this->capacity) {

            resize();
        }

        this->arr[setSize++] = element;

        return true;
    }

    bool isEmpty() const {

        return (this->setSize == 0);
    }

    int size() const {

        return this->setSize;
    }

    bool remove(T element) {

        if (!contains(element)) {

            return false;
        }

        for (int i = 0; i < this->setSize; i++) {

            if (this->arr[i] == element) {

                for (int j = i; j < this->setSize - 1; j++) {

                    this->arr[j] = arr[j + 1];
                }

                this->setSize--;
                this->arr[setSize] = T();
                break;
            }
        }

        return true;
    }

    bool operator==(const Set& other) const {

        if (this->setSize != other.setSize) {

            return false;
        }

        for (int i = 0; i < size(); i++) {

            if (!contains(other.arr[i])) {

                return false;
            }
        }

        return true;
    }

    Set<T> operator+(const Set<T>& other) const {

        Set<T> set = *this;

        for (int i = 0; i < other.size(); i++) {

            set.add(other.arr[i]);
        }

        return set;
    }

    Set<T> operator*(const Set<T>& other) const {

        Set<T> set;

        for (int i = 0; i < size(); i++) {

            if (other.contains(arr[i])) {

                set.add(arr[i]);
            }
        }

        return set;
    }

    Set<T> operator-(const Set<T>& other) const {

        Set<T> ret = *this;

        for (int i = 0; i < other.size(); i++) {

            ret.remove(other.arr[i]);
        }

        return ret;
    }

    Set<T> map(MapFn<T> mapFn) const {


        Set<T> set;

        for (int i = 0; i < this->setSize; i++) {


            set.add(mapFn(this->arr[i]));
        }

        return set;
    }

    Set<T> filter(Predicate<T> predicate) {


        Set<T> set;

        for (int i = 0; i < this->setSize; i++) {


            if (predicate(this->arr[i])) {


                set.add(this->arr[i]);
            }
        }

        return set;
    }

    template <typename ResultT>
    ResultT reduce(ReduceFn<ResultT, T> reduceFn, ResultT initialValue) {

        ResultT result = initialValue;

        for (int i = 0; i < this->setSize; i++) {

            result = reduceFn(result, this->arr[i]);
        }

        return result;
    }

    void print() const {

        for (int i = 0; i < setSize; i++) {

            cout << this->arr[i] << " ";
        }

        cout << "\n\n";
    }

private:
   
};

Person mapIncrementAge(Person person) {

    person.setAge(person.getAge() + 1);
    return person;
}

bool filterAllPeopleHave18(Person person) {

    return person.getAge() >= 18;
}

bool reduceAllPeopleHaveDrivingLicense(bool initialValue, Person person) {

    return initialValue && person.getDrivingLicense();
}


int main() {


    return 0;
}
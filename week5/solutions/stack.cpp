#include <iostream>
using namespace std;

template <typename T>
void Stack<T>::copy(const Stack<T>& s) {

    top = nullptr;

    Element<T>* pointer = s.top;
    Stack<T> temp;

    while(pointer != nullptr) {
        temp.push(pointer->data);
        pointer = pointer->next;
    }

    while(!temp.empty()) {
        push(temp.pop());
    }
}

template <typename T>
void Stack<T>::erase() {

    while(!empty()) {
        pop();
    }
}

template <typename T>
Stack<T>::Stack() {
    top = nullptr;
}

template <typename T>
Stack<T>::Stack(const Stack<T>& s) {
    copy(s);
}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other) {

    if(&other != this) {
        erase();
        copy(other);
    }

    return *this;
}

template <typename T>
Stack<T>::~Stack() {
    erase();
}

template <typename T>
bool Stack<T>::empty() const {

    return top == nullptr;
}

template <typename T>
T Stack<T>::peek() const {

    if (top == nullptr) {

        cout << "Stack is empty" << endl;
        return T();
    }

    return top->data;
}

template <typename T>
void Stack<T>::push(T x) {

    Element<T>* pointer = new Element<T>;
    pointer->data = x;
    pointer->next = top;
    top = pointer;

}

template <typename T>
T Stack<T>::pop() {

    if(empty()) {

        cout << "Stack is empty" << endl;
        return T();
    }

    Element<T>* pointer = top;
    T x = pointer->data;
    top = top->next;
    delete pointer;

    return x;
}

template <typename T>
void Stack<T>::print() {

    Element<T>* temp = top;

    while(temp != nullptr) {
        cout << temp->data;
        temp = temp->next;
    }

    cout << endl;
}
 
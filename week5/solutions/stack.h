#pragma once

template <typename T>
struct Element {
    T data;
    Element<T>* next;
};

template <typename T>
class Stack {
private:
    Element<T>* top;

    void copy(const Stack<T>& s);

    void erase();

public:
    Stack<T>();

    Stack<T>(const Stack<T>& s);

    Stack<T>& operator=(const Stack<T>& other);

    ~Stack();

    bool empty() const;

    T peek() const;

    void push(T x);

    T pop();

    void print();
 
};

#include "stack.cpp"

// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template<typename T, int size>
class TStack {
 private:
    T *arr;
    int tIndex;

 public:
    TStack() {
        arr = new T[size];
        tIndex = -1;
    }
    bool isEmpty() {
        return tIndex == -1;
    }
    void push(T value) {
        arr[++tIndex] = value;
    }
    T& pop() {
        return arr[tIndex--];
    }
    bool isFull() const {
        return tIndex == size;
    }
    T& get() const {
        return arr[tIndex];
    }
};

#endif  // INCLUDE_TSTACK_H_

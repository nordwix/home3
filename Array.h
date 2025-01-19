#pragma once
#include <iostream>

template<typename T>
class Array {
private:
    T* data;
    size_t size;
    void clear();
public:
    Array();
    Array(size_t n);
    Array(size_t n, int min, int max);
    Array(size_t n, T x);
    Array(const Array& other);
    ~Array();
    void display() const;
    void fillRandom(int min, int max);
    void resize(size_t newSize);
    void sort();
    T getMin() const;
    T getMax() const;
    void append(T value);
    void remove(size_t index);
};

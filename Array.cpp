#include "Array.h"
template<typename T>
void Array<T>::clear() {
    delete[] data;
    data = nullptr;
    size = 0;
}
template<typename T>
Array<T>::Array() : data(nullptr), size(0) {}
template<typename T>
Array<T>::Array(size_t n) : size(n) {
    data = new T[size]{ 0 };
}
template<typename T>
Array<T>::Array(size_t n, int min, int max) : size(n) {
    data = new T[size];
    fillRandom(min, max);
}
template<typename T>
Array<T>::Array(size_t n, T x) : size(n) {
    data = new T[size];
    for (size_t i = 0; i < size; ++i) {
        data[i] = x;
    }
}
template<typename T>
Array<T>::Array(const Array& other) : size(other.size) {
    data = new T[size];
    for (size_t i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
}
template<typename T>
Array<T>::~Array() {
    clear();
}
template<typename T>
void Array<T>::display() const {
    for (size_t i = 0; i < size; ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}
template<typename T>
void Array<T>::fillRandom(int min, int max) {
    for (size_t i = 0; i < size; ++i) {
        while (data[i] < min)
        {
            data[i] = rand() % max + 1;
        }
    }
}
template<typename T>
void Array<T>::resize(size_t newSize) {
    T* newData = new T[newSize]{ 0 };
    size_t minSize = (size < newSize) ? size : newSize;
    for (size_t i = 0; i < minSize; ++i) {
        newData[i] = data[i];
    }
    clear();
    data = newData;
    size = newSize;
}
template<typename T>
void Array<T>::sort() {
    for (size_t i = 0; i < size - 1; ++i) {
        for (size_t j = 0; j < size - i - 1; ++j) {
            if (data[j] > data[j + 1]) {
                T temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}
template<typename T>
T Array<T>::getMin() const {
    int minValue = data[0];
    for (size_t i = 1; i < size; ++i) {
        if (data[i] < minValue) {
            minValue = data[i];
        }
    }
    return minValue;
}
template<typename T>
T Array<T>::getMax() const {
    int maxValue = data[0];
    for (size_t i = 1; i < size; ++i) {
        if (data[i] > maxValue) {
            maxValue = data[i];
        }
    }
    return maxValue;
}
template<typename T>
void Array<T>::append(T value) {
    resize(size + 1);
    data[size - 1] = value;
}
template<typename T>
void Array<T>::remove(size_t index) {
    if (index >= size) {
        return;
    }
    for (size_t i = index; i < size - 1; ++i) {
        data[i] = data[i + 1];
    }
    resize(size - 1);
}

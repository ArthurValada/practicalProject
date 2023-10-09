//
// Created by arthur on 09/10/23.
//

#pragma ide diagnostic ignored "NullDereference"
#include "DynamicArray.h"

template<class T>
DynamicArray<T>::DynamicArray() {
    this->capacity = 1;
    this->size = 0;
    this->array = new T[capacity];
}

template<class T>
[[maybe_unused]] DynamicArray<T>::DynamicArray(int capacity) {

    this->capacity = capacity;
    this->array = new T[capacity];
    this->size = 0;

}

template<class T>
[[maybe_unused]] int DynamicArray<T>::getSize() const {
    return this->size;
}

template<class T>
[[maybe_unused]] int DynamicArray<T>::getCapacity() const {
    return this->capacity;
}

template<class T>
[[maybe_unused]] void DynamicArray<T>::push_back(T value) {

    if (size == capacity) {
        this->growArray();
    }

    this->array[size] = value;

    this->size++;

}

template<class T>
[[maybe_unused]] void DynamicArray<T>::pop_back() {

    this->array[size - 1] = 0;

    this->size--;

    if (size == (capacity / 2)) {
        shrinkArray();
    }

}

template<class T>
void DynamicArray<T>::growArray() {

    T* temp = new T[capacity * 2];

    capacity = capacity * 2;

    for (int i = 0; i < size; i++) {
        temp[i] = this->array[i];
    }

    delete[] array;

    array = temp;

}

template<class T>
void DynamicArray<T>::shrinkArray() {

    this->capacity = size;
    int* temp = new T[capacity];

    for (int i = 0; i < size; i++) {
        temp[i] = this->array[i];
    }

    delete[] array;

    array = temp;

}

template<class T>
void DynamicArray<T>::insertAt(int index, T value) {

    if (size == capacity) {
        growArray();
    }

    for (int i = size - 1; i >= index; i--) {
        this->array[i + 1] = array[i];
    }

    this->array[index] = value;
    this->size++;

}

template<class T>
void DynamicArray<T>::deleteAt(int index) {

    for (int i = index; i < size; i++) {
        this->array[i] = array[i + 1];
    }

    this->array[size - 1] = 0;

    this->size--;

    if (size == (capacity / 2)) {
        shrinkArray();
    }

}

template<class T>
bool DynamicArray<T>::isEmpty() const {
    if (size == 0) {
        return true;
    }
    else {
        return false;
    }
}

#pragma clang diagnostic pop
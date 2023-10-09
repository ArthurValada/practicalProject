//
// Created by arthur on 09/10/23.
//

#ifndef PRATICALPROJECT_DYNAMICARRAY_H
#define PRATICALPROJECT_DYNAMICARRAY_H

template<class T>
class DynamicArray {
private:

    T* array = nullptr;
    int size{};
    int capacity{};

public:
    // Default constructor with size 1
    DynamicArray();

    [[maybe_unused]] explicit DynamicArray(int capacity);

    [[maybe_unused]] [[nodiscard]] int getSize() const;

    [[maybe_unused]] [[nodiscard]] int getCapacity() const;

    [[maybe_unused]] void push_back(T value);

    [[maybe_unused]] void pop_back();

    void growArray();

    void shrinkArray();

    void insertAt(int index, T value);

    void deleteAt(int index);

    [[nodiscard]] bool isEmpty() const;
};

#endif //PRATICALPROJECT_DYNAMICARRAY_H

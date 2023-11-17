//
// Created by arthur on 17/10/23.
//

#ifndef PRACTICALPROJECT_DYNAMICVECTOR_H
#define PRACTICALPROJECT_DYNAMICVECTOR_H

#include <cstdlib>
#include <initializer_list>
#include <iterator>

template<class T>
class DynamicVector {
private:
    T *_data;
    std::size_t _size;
    std::size_t _capacity;

    void _grow() {
        std::size_t newCapacity;
        if(_capacity!=0){
            newCapacity = _capacity * 2;
        }
        else{
            newCapacity = 2;
        }
        T *newData = new T[newCapacity];

        if(_capacity!=0){
            if(_size!=0){
                for (auto i = 0; i <= _size; i++) {
                    newData[i] = _data[i];
                }
            }
            delete[] _data;
        }

        _data = newData;
        _capacity=newCapacity;
    }

    void _shrink() {
        _capacity = _size;

        T *newData = new T[_size];

        for (auto i = 0; i < _size; i++) {
            newData[i] = _data[i];
        }

        delete[] _data;

        _data = newData;
    }

public:

    struct Iterator {

        explicit Iterator(T *ptr) : m_ptr(ptr) {}

        T &operator*() const { return *m_ptr; }

        T *operator->() { return m_ptr; }

        Iterator &operator++() {
            m_ptr++;
            return *this;
        }

        Iterator operator++(int) {
            Iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        friend bool operator==(const Iterator &a, const Iterator &b) { return a.m_ptr == b.m_ptr; };

        friend bool operator!=(const Iterator &a, const Iterator &b) { return a.m_ptr != b.m_ptr; };

    private:
        T *m_ptr;
    };

    DynamicVector() : _data(nullptr), _size(0), _capacity(0) {}

    explicit DynamicVector(std::size_t capacity) : _data(new T[capacity]), _size(capacity), _capacity(capacity) {}

    DynamicVector(const std::initializer_list<T> &data) : _size(data.size()), _capacity(data.size()),_data{} {

        _data = new T[_size];

        int _currentIndex = 0;

        for (const auto &element: data) {
            _data[_currentIndex] = element;
            _currentIndex++;
        }
    }

    DynamicVector(T* data, std::size_t size):_data(data), _size(size),_capacity(size){}

    [[nodiscard]] std::size_t getCapacity() {
        return this->_capacity;
    }

    [[nodiscard]] const std::size_t &getCapacity() const {
        return this->_capacity;
    }

    [[nodiscard]] std::size_t getSize() {
        return this->_size;
    }

    [[nodiscard]] const std::size_t &getSize() const {
        return this->_size;
    }

    void push_back(T value) {
        if (_size + 1 == _capacity or _size == _capacity) {
            _grow();
        }

        _data[_size] = value;
        _size++;
    }

    void push(T value){
        if(_size>=_capacity){
            _grow();
        }

        for(auto i = _size;i>0;i--){
            _data[i] = _data[i-1];
        }

        _data[0] = value;

        _size++;
    }

    void remove_at(std::size_t index){
        for(auto i = index;i<_size-1;i++){
            _data[i]=_data[i+1];
        }
        _size--;
        _shrink();
    }

    T* getData() const {
        return this->_data;
    }

    Iterator begin() {
        return Iterator(&_data[0]);
    }

    Iterator begin() const {
        return Iterator(&_data[0]);
    }

    Iterator end() {
        return Iterator(&_data[_size]);
    }

    Iterator end() const {
        return Iterator(&_data[_size]);
    }
};

#endif //PRACTICALPROJECT_DYNAMICVECTOR_H
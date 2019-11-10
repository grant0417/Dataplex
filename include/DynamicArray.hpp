/*
Copyright (c) 2019 Inverse Palindrome
Dataplex - DynamicArray.hpp
http://inversepalindrome.com
*/


#pragma once

#include <cstddef>
#include <iterator>


namespace Dataplex
{
    template<typename T>
    class DynamicArray
    {
    public:
        DynamicArray();
        DynamicArray(const DynamicArray<T>& array);
        DynamicArray<T>& operator=(const DynamicArray<T>& array);
        DynamicArray(DynamicArray<T>&& array);
        DynamicArray<T>& operator=(DynamicArray<T>&& array);
        explicit DynamicArray(std::size_t capacity);
        DynamicArray(std::initializer_list<T> list);

        ~DynamicArray();

        T* begin();
        const T* begin() const;

        T* end();
        const T* end() const;

        std::reverse_iterator<T*> rbegin();
        std::reverse_iterator<const T*> rbegin() const;

        std::reverse_iterator<T*> rend();
        std::reverse_iterator<const T*> rend() const;

        T& operator[](std::size_t pos);
        const T& operator[](std::size_t pos) const;

        void push_back(const T& data);
        void pop_back();

        void insert(const T& data, std::size_t pos);
        void erase(std::size_t pos);

        void reserve(std::size_t capacity);
        void clear();

        std::size_t size() const;
        std::size_t capacity() const;
        bool is_empty() const;

    private:
        std::size_t _size;
        std::size_t _capacity;
        T* _array;

        void swap(DynamicArray<T>& array);
    };
}

template<typename T>
Dataplex::DynamicArray<T>::DynamicArray() :
    _size(0),
    _capacity(1),
    _array(new T[_capacity])
{
}

template<typename T>
Dataplex::DynamicArray<T>::DynamicArray(const DynamicArray<T>& array) :
    DynamicArray()
{
    for (std::size_t i = 0; i < array.size(); ++i)
    {
        push_back(array[i]);
    }
}

template<typename T>
Dataplex::DynamicArray<T>& Dataplex::DynamicArray<T>::operator=(const DynamicArray<T>& array) 
{
    DynamicArray<T> temp(array);
    swap(temp);

    return *this;
}

template<typename T>
Dataplex::DynamicArray<T>::DynamicArray(DynamicArray<T>&& array) :
    DynamicArray()
{
    swap(array);
}

template<typename T>
Dataplex::DynamicArray<T>& Dataplex::DynamicArray<T>::operator=(DynamicArray<T>&& array)
{
    swap(array);

    return *this;
}

template<typename T>
Dataplex::DynamicArray<T>::DynamicArray(std::size_t capacity) :
    DynamicArray()
{
    reserve(capacity);
}

template<typename T>
Dataplex::DynamicArray<T>::DynamicArray(std::initializer_list<T> list) :
    DynamicArray()
{
    for (const auto& data : list)
    {
        push_back(data);
    }
}

template<typename T>
Dataplex::DynamicArray<T>::~DynamicArray()
{
    clear();
}

template<typename T>
T* Dataplex::DynamicArray<T>::begin()
{
    return _array;
}

template<typename T>
const T* Dataplex::DynamicArray<T>::begin() const
{
    return _array;
}

template<typename T>
T* Dataplex::DynamicArray<T>::end()
{
    return _array + _size;
}

template<typename T>
const T* Dataplex::DynamicArray<T>::end() const
{
    return _array + _size;
}

template<typename T>
std::reverse_iterator<T*> Dataplex::DynamicArray<T>::rbegin()
{
    return std::make_reverse_iterator<T*>(end());
}

template<typename T>
std::reverse_iterator<const T*> Dataplex::DynamicArray<T>::rbegin() const
{
    return std::make_reverse_iterator<const T*>(end());
}

template<typename T>
std::reverse_iterator<T*> Dataplex::DynamicArray<T>::rend()
{
    return std::make_reverse_iterator<T*>(begin());
}

template<typename T>
std::reverse_iterator<const T*> Dataplex::DynamicArray<T>::rend() const
{
    return std::make_reverse_iterator<const T*>(begin());
}

template<typename T>
T& Dataplex::DynamicArray<T>::operator[](std::size_t pos)
{
    return _array[pos];
}

template<typename T>
const T& Dataplex::DynamicArray<T>::operator[](std::size_t pos) const
{
    return _array[pos];
}

template<typename T>
void Dataplex::DynamicArray<T>::push_back(const T& data)
{
    if (_size == _capacity)
    {
        reserve(_capacity * 2);
    }

    _array[_size++] = data;
}

template <typename T>
void Dataplex::DynamicArray<T>::pop_back()
{
    if (is_empty())
    {
        throw std::out_of_range("Can't pop back empty dynamic array!");
    }

    --_size;
    _array[_size].~T();
}

template<typename T>
void Dataplex::DynamicArray<T>::insert(const T& data, std::size_t pos)
{
    if (_size == _capacity)
    {
        reserve(_capacity * 2);
    }

    for (std::size_t i = _size - 1; i > pos; --i)
    {
        _array[i + 1] = _array[i];
    }

    _array[pos] = data;

    ++_size;
}

template<typename T>
void Dataplex::DynamicArray<T>::erase(std::size_t pos)
{
    if (pos >= _size)
    {
        throw std::out_of_range("Erase position outside of existing range!");
    }

    for (std::size_t i = pos; i < _size; ++i)
    {
        _array[pos] = _array[pos + 1];
    }

    --_size;
}

template<typename T>
void Dataplex::DynamicArray<T>::reserve(std::size_t capacity)
{
    auto newArray = new T[capacity];

    for (std::size_t i = 0; i < _size; ++i)
    {
        newArray[i] = _array[i];
    }

    _capacity = capacity;

    delete[] _array;

    _array = newArray;
}

template<typename T>
void Dataplex::DynamicArray<T>::clear()
{
    delete[] _array;

    _size = 0;
    _capacity = 0;
    _array = nullptr;
}

template<typename T>
std::size_t Dataplex::DynamicArray<T>::size() const
{
    return _size;
}

template<typename T>
std::size_t Dataplex::DynamicArray<T>::capacity() const
{
    return _capacity;
}

template<typename T>
bool Dataplex::DynamicArray<T>::is_empty() const
{
    return _size == 0;
}

template<typename T>
void Dataplex::DynamicArray<T>::swap(DynamicArray<T>& array)
{
    using std::swap;

    swap(_size, array._size);
    swap(_capacity, array._capacity);
    swap(_array, array._array);
}
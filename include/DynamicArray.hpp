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

        void insert(const T& t, std::size_t pos);
        void erase(std::size_t pos);

        void reserve(std::size_t capacity);
        void clear();

        std::size_t size() const;
        bool is_empty() const;

    private:
        T* _array;
        std::size_t _size;
        std::size_t _capacity;
    };
}

template<typename T>
Dataplex::DynamicArray<T>::DynamicArray() :
    _size(0),
    _capacity(0)
{
}

template<typename T>
Dataplex::DynamicArray<T>::DynamicArray(const DynamicArray<T>& array) :
    DynamicArray()
{

}

template<typename T>
Dataplex::DynamicArray<T>& Dataplex::DynamicArray<T>::operator=(const DynamicArray<T>& array) 
{
    return *this;
}

template<typename T>
Dataplex::DynamicArray<T>::DynamicArray(DynamicArray<T>&& array) :
    DynamicArray()
{

}

template<typename T>
Dataplex::DynamicArray<T>& Dataplex::DynamicArray<T>::operator=(DynamicArray<T>&& array)
{
    return *this;
}

template<typename T>
Dataplex::DynamicArray<T>::DynamicArray(std::initializer_list<T> list)
{

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
void Dataplex::DynamicArray<T>::push_back(const T& t)
{

}

template <typename T>
void Dataplex::DynamicArray<T>::pop_back()
{

}

template<typename T>
void Dataplex::DynamicArray<T>::insert(const T& t, std::size_t pos)
{

}

template<typename T>
void Dataplex::DynamicArray<T>::erase(std::size_t pos)
{

}

template<typename T>
void Dataplex::DynamicArray<T>::reserve(std::size_t capacity)
{
    _capacity = capacity;
}

template<typename T>
void Dataplex::DynamicArray<T>::clear()
{

}

template<typename T>
std::size_t Dataplex::DynamicArray<T>::size() const
{
    return _size;
}

template<typename T>
bool Dataplex::DynamicArray<T>::is_empty() const
{
    return _size == 0;
}
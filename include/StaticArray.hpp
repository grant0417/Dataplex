/*
Copyright (c) 2019 Inverse Palindrome
Dataplex - StaticArray.hpp
http://inversepalindrome.com
*/


#pragma once

#include <cstddef>
#include <iterator>


namespace Dataplex
{
    template<typename T, std::size_t N>
    class StaticArray
    {
    public:
        StaticArray();

        T* begin();
        const T* begin() const;

        T* end();
        const T* end() const;

        T& operator[](std::size_t index);
        const T& operator[](std::size_t index) const;

        std::size_t size() const;
        bool is_empty() const;

    private:
        T _array[N];
        std::size_t _size;
    };
}

template<typename T, std::size_t N>
Dataplex::StaticArray<T, N>::StaticArray() :
    _size(N)
{ 
}

template<typename T, std::size_t N>
T* Dataplex::StaticArray<T, N>::begin()
{
    return _array;
}

template<typename T, std::size_t N>
const T* Dataplex::StaticArray<T, N>::begin() const
{
    return _array;
}

template<typename T, std::size_t N>
T* Dataplex::StaticArray<T, N>::end()
{
    return _array + N;
}

template<typename T, std::size_t N>
const T* Dataplex::StaticArray<T, N>::end() const
{
    return _array + N;
}

template<typename T, std::size_t N>
T& Dataplex::StaticArray<T, N>::operator[](std::size_t index)
{
    if (index >= _size)
    {
        throw std::out_of_range("Index position out of range!");
    }

    return _array[index];
}

template<typename T, std::size_t N>
const T& Dataplex::StaticArray<T, N>::operator[](std::size_t index) const
{
    if (index >= _size)
    {
        throw std::out_of_range("Index position out of range!");
    }

    return _array[index];
}

template<typename T, std::size_t N>
std::size_t Dataplex::StaticArray<T, N>::size() const
{
    return _size;
}

template<typename T, std::size_t N>
bool Dataplex::StaticArray<T, N>::is_empty() const
{
    return _size == 0;
}
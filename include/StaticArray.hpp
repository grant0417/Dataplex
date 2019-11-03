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
    struct StaticArray
    {
        T* begin();
        const T* begin() const;

        T* end();
        const T* end() const;

        std::reverse_iterator<T*> rbegin();
        std::reverse_iterator<const T*> rbegin() const;

        std::reverse_iterator<T*> rend();
        std::reverse_iterator<const T*> rend() const;

        T& operator[](std::size_t index);
        const T& operator[](std::size_t index) const;

        std::size_t size() const;
        bool is_empty() const;

        T _array[N];
    };
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
std::reverse_iterator<T*> Dataplex::StaticArray<T, N>::rbegin()
{
    return std::make_reverse_iterator<T*>(end());
}

template<typename T, std::size_t N>
std::reverse_iterator<const T*> Dataplex::StaticArray<T, N>::rbegin() const
{
    return std::make_reverse_iterator<const T*>(end());
}

template<typename T, std::size_t N>
std::reverse_iterator<T*> Dataplex::StaticArray<T, N>::rend()
{
    return std::make_reverse_iterator<T*>(begin());
}

template<typename T, std::size_t N>
std::reverse_iterator<const T*> Dataplex::StaticArray<T, N>::rend() const
{
    return std::make_reverse_iterator<const T*>(begin());
}

template<typename T, std::size_t N>
T& Dataplex::StaticArray<T, N>::operator[](std::size_t index)
{
    if (index >= N)
    {
        throw std::out_of_range("Index position out of range!");
    }

    return _array[index];
}

template<typename T, std::size_t N>
const T& Dataplex::StaticArray<T, N>::operator[](std::size_t index) const
{
    if (index >= N)
    {
        throw std::out_of_range("Index position out of range!");
    }

    return _array[index];
}

template<typename T, std::size_t N>
std::size_t Dataplex::StaticArray<T, N>::size() const
{
    return N;
}

template<typename T, std::size_t N>
bool Dataplex::StaticArray<T, N>::is_empty() const
{
    return N == 0;
}
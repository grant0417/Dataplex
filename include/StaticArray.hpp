/*
Copyright (c) 2019 Inverse Palindrome
Dataplex - StaticArray.hpp
http://inversepalindrome.com
*/


#pragma once

#include <cstddef>


namespace Dataplex
{
    template<typename T, std::size_t N>
    class StaticArray
    {
    public:
        StaticArray();

        std::size_t size() const;

    private:
        std::size_t _size;
    };
}

template<typename T, std::size_t N>
Dataplex::StaticArray<T, N>::StaticArray() :
    size(N)
{ 
}

template<typename T, std::size_t N>
std::size_t Dataplex::StaticArray<T, N>::size() const
{
    return _size
}
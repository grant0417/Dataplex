/*
Copyright (c) 2019 Inverse Palindrome
Dataplex - DynamicArray.hpp
http://inversepalindrome.com
*/


#pragma once

#include <cstddef>


namespace Dataplex
{
    template<typename T>
    class DynamicArray
    {
    public:
        DynamicArray();

        void push_back(const T& data);
        void pop_back();

        void insert(const T& t, std::size_t pos);
        void erase(std::size_t pos);

        std::size_t size() const;
        bool is_empty() const;

    private:
        std::size_t _size;
    };
}

template<typename T>
Dataplex::DynamicArray<T>::DynamicArray() :
    size(0)
{
}

template<typename T>
void Dataplex::DynamicArray<T>::push_back(const T& t)
{
    auto node = std::make_unique<Node>(t);


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
std::size_t Dataplex::DynamicArray<T>::size() const
{
    return _size;
}

template<typename T>
bool Dataplex::DynamicArray<T>::is_empty() const
{
    return _size == 0;
}
/*
Copyright (c) 2019 Inverse Palindrome
Dataplex - Queue.hpp
http://inversepalindrome.com
*/


#pragma once

#include "DynamicArray.hpp"


namespace Dataplex
{
    template<typename T>
    class Queue
    {
    public:
        T& front();
        const T& front() const;

        void push(const T& data);
        void pop();

        std::size_t size() const;
        bool is_empty() const;

    private:
        DynamicArray<T> _array;
    };
}

template<typename T>
T& Dataplex::Queue<T>::front()
{
    if (is_empty())
    {
        throw std::out_of_range("No element exists in the queue!");
    }

    return _array[0];
}

template<typename T>
const T& Dataplex::Queue<T>::front() const
{
    if (is_empty())
    {
        throw std::out_of_range("No element exists in the queue!");
    }

    return _array[0];
}

template<typename T>
void Dataplex::Queue<T>::push(const T& data)
{
    _array.push_back(data);
}

template<typename T>
void Dataplex::Queue<T>::pop()
{
    if (is_empty())
    {
        throw std::out_of_range("Can't pop empty queue!");
    }

    _array.erase(0);
}

template<typename T>
std::size_t Dataplex::Queue<T>::size() const
{
    return _array.size();
}

template<typename T>
bool Dataplex::Queue<T>::is_empty() const
{
    return _array.is_empty();
}
/*
Copyright (c) 2019 Inverse Palindrome
Dataplex - Stack.hpp
http://inversepalindrome.com
*/


#pragma once

#include "DynamicArray.hpp"


namespace Dataplex
{
    template<typename T>
    class Stack
    {
    public:
        T& top();
        const T& top() const;

        void push(const T& data);
        void pop();

        std::size_t size() const;
        bool is_empty() const;

    private:
        DynamicArray<T> _array;
    };
}

template<typename T>
T& Dataplex::Stack<T>::top()
{
    if (is_empty())
    {
        throw std::out_of_range("No element exists in the stack!");
    }

    return _array[_array.size() - 1];
}

template<typename T>
const T& Dataplex::Stack<T>::top() const
{
    if (is_empty())
    {
        throw std::out_of_range("No element exists in the stack!");
    }

    return _array[_array.size() - 1];
}

template<typename T>
void Dataplex::Stack<T>::push(const T& data)
{
    _array.push_back(data);
}

template<typename T>
void Dataplex::Stack<T>::pop()
{
    if (is_empty())
    {
        throw std::out_of_range("Can't pop empty stack!");
    }

    _array.pop_back();
}

template<typename T>
std::size_t Dataplex::Stack<T>::size() const
{
    return _array.size();
}

template<typename T>
bool Dataplex::Stack<T>::is_empty() const
{
    return _array.is_empty();
}
/*
Copyright (c) 2019 Inverse Palindrome
Dataplex - PriorityQueue.hpp
http://inversepalindrome.com
*/


#pragma once


#include "DynamicArray.hpp"

#include <algorithm>
#include <functional>


namespace Dataplex
{
    template<typename T, typename Comp = std::less<T>>
    class PriorityQueue
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
        Comp cmp;
    };
}

template<typename T, typename Comp>
T& Dataplex::PriorityQueue<T, Comp>::front()
{
    if (is_empty())
    {
        throw std::out_of_range("No element exists in the priority queue!");
    }

    return _array[0];
}

template<typename T, typename Comp>
const T& Dataplex::PriorityQueue<T, Comp>::front() const
{
    if (is_empty())
    {
        throw std::out_of_range("No element exists in the priority queue!");
    }

    return _array[0];
}

template<typename T, typename Comp>
void Dataplex::PriorityQueue<T, Comp>::push(const T& data)
{
    if (!is_empty())
    {
        
    }

    _array.push_back(data);

    std::make_heap(_array.begin(), _array.end(), cmp);
}

template<typename T, typename Comp>
void Dataplex::PriorityQueue<T, Comp>::pop()
{
    if (is_empty())
    {
        throw std::out_of_range("Can't pop empty priority queue!");
    }

    std::pop_heap(_array.begin(), _array.end(), cmp); 
    _array.pop_back();
}

template<typename T, typename Comp>
std::size_t Dataplex::PriorityQueue<T, Comp>::size() const
{
    return _array.size();
}

template<typename T, typename Comp>
bool Dataplex::PriorityQueue<T, Comp>::is_empty() const
{
    return _array.is_empty();
}
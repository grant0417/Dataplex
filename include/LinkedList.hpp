/*
Copyright (c) 2019 Inverse Palindrome
Dataplex - LinkedList.hpp
http://inversepalindrome.com
*/


#pragma once

#include <cstddef>


namespace Dataplex
{
    template<typename T>
    class LinkedList
    {
    public:
        LinkedList();

        void push_back(const T& t);
        void pop_back();

        void insert(const T& t, std::size_t pos);
        void erase(std::size_t pos);

        std::size_t size() const;
        bool is_empty() const;

    private:
        struct Node
        {
            Node* next;
            T data;
        };

        Node* head;
        Node* tail;

        std::size_t _size;
    };
}


template<typename T>
Dataplex::LinkedList<T>::LinkedList() :
    head(nullptr),
    tail(nullptr)
{
}

template<typename T>
void Dataplex::LinkedList<T>::push_back(const T& t)
{

}

template <typename T>
void Dataplex::LinkedList<T>::pop_back()
{

}

template<typename T>
void Dataplex::LinkedList<T>::insert(const T& t, std::size_t pos)
{

}

template<typename T>
void Dataplex::LinkedList<T>::erase(std::size_t pos)
{

}

template<typename T>
std::size_t Dataplex::LinkedList<T>::size() const
{
    return _size;
}

template<typename T>
bool Dataplex::LinkedList<T>::is_empty() const
{
    return _size == 0;
}
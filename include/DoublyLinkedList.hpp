/*
Copyright (c) 2019 Inverse Palindrome
Dataplex - DoublyLinkedList.hpp
http://inversepalindrome.com
*/


#pragma once

#include <cstddef>


namespace Dataplex
{
    template<typename T>
    class DoublyLinkedList
    {
    public:
        DoublyLinkedList();
        ~DoublyLinkedList();

        T& head();
        const T& head() const;

        T& tail();
        const T& tail() const;

        void push_back(const T& t);
        void pop_back();

        void insert(const T& t, std::size_t pos);
        void erase(std::size_t pos);

        std::size_t size() const;
        bool is_empty() const;

    private:
        struct Node
        {
            explicit Node(const T& data);

            T data;
            Node* next;
            Node* prev;
        };

        Node* _head;
        Node* _tail;

        std::size_t _size;
    };
}

template<typename T>
Dataplex::DoublyLinkedList<T>::DoublyLinkedList() :
    _head(nullptr),
    _tail(nullptr),
    size(0)
{
}

template<typename T>
Dataplex::DoublyLinkedList<T>::~DoublyLinkedList()
{

}

template<typename T>
T& Dataplex::DoublyLinkedList<T>::head()
{
    if (!head)
    {
        throw std::out_of_range("Head not initialized!");
    }

    return _head->data;
}

template<typename T>
const T& Dataplex::DoublyLinkedList<T>::head() const
{
    if (!head)
    {
        throw std::out_of_range("Head not initialized!");
    }

    return _head->data;
}

template<typename T>
T& Dataplex::DoublyLinkedList<T>::tail()
{
    if (!tail)
    {
        throw std::out_of_range("Tail not initialized!");
    }

    return _tail->data;
}

template<typename T>
const T& Dataplex::DoublyLinkedList<T>::tail() const
{
    if (!tail)
    {
        throw std::out_of_range("Tail not initialized!");
    }

    return _tail->data;
}

template<typename T>
void Dataplex::DoublyLinkedList<T>::push_back(const T& t)
{
    auto node = new Node(T);

    
}

template <typename T>
void Dataplex::DoublyLinkedList<T>::pop_back()
{
    
}

template<typename T>
void Dataplex::DoublyLinkedList<T>::insert(const T& t, std::size_t pos)
{

}

template<typename T>
void Dataplex::DoublyLinkedList<T>::erase(std::size_t pos)
{

}

template<typename T>
std::size_t Dataplex::DoublyLinkedList<T>::size() const
{
    return _size;
}

template<typename T>
bool Dataplex::DoublyLinkedList<T>::is_empty() const
{
    return _size == 0;
}

template<typename T>
Dataplex::DoublyLinkedList<T>::Node::Node(const T& data) :
    data(data),
    next(nullptr),
    prev(nullptr)
{
}
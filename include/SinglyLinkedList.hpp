/*
Copyright (c) 2019 Inverse Palindrome
Dataplex - SinglyLinkedList.hpp
http://inversepalindrome.com
*/


#pragma once

#include <cstddef>
#include <exception>


namespace Dataplex
{
    template<typename T>
    class SinglyLinkedList
    {
    public:
        SinglyLinkedList();
        ~SinglyLinkedList();

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

            Node* next;
            T data;
        };

        Node* _head;
        Node* _tail;

        std::size_t _size;
    };
}

template<typename T>
Dataplex::SinglyLinkedList<T>::SinglyLinkedList() :
    _head(nullptr),
    _tail(nullptr),
    _size(0)
{
}

template<typename T>
Dataplex::SinglyLinkedList<T>::~SinglyLinkedList()
{
    Node* curr = _head;

    while (curr != nullptr)
    {
        Node* next = curr->next;

        delete curr;

        curr = next;
    }

    _head = nullptr;
    _tail = nullptr;
}

template<typename T>
T& Dataplex::SinglyLinkedList<T>::head()
{
    if (!head)
    {
        throw std::out_of_range("Head not initialized!");
    }

    return _head->data;
}

template<typename T>
const T& Dataplex::SinglyLinkedList<T>::head() const
{
    if (!head)
    {
        throw std::out_of_range("Head not initialized!");
    }

    return _head->data;
}

template<typename T>
T& Dataplex::SinglyLinkedList<T>::tail()
{
    if (!tail)
    {
        throw std::out_of_range("Tail not initialized!");
    }

    return _tail->data;
}

template<typename T>
const T& Dataplex::SinglyLinkedList<T>::tail() const
{
    if (!tail)
    {
        throw std::out_of_range("Tail not initialized!");
    }

    return _tail->data;
}

template<typename T>
void Dataplex::SinglyLinkedList<T>::push_back(const T& t)
{
    Node* node = new Node(t);

    if (!_head)
    {
        _head = node;
        _tail = _head;
    }
    else
    {
        _tail->next = node;
        _tail = node; 
    }

    ++_size;
}

template <typename T>
void Dataplex::SinglyLinkedList<T>::pop_back()
{
    if (!_head)
    {
        return;
    }
    else if (_head == _tail)
    {
        delete _head;

        _head = nullptr;
        _tail = nullptr;
    }
    else
    {
        Node* curr = _head;
        Node* prev = nullptr;

        while (curr->next != nullptr)
        {
            prev = curr;
            curr = curr->next;
        }

        _tail = prev;
        prev->next = nullptr;

        delete curr;
    }

    --_size;
}

template<typename T>
void Dataplex::SinglyLinkedList<T>::insert(const T& t, std::size_t pos)
{
    if (pos < 0 || pos > _size)
    {
        return;
    }
    else if (pos == _size)
    {
        push_back(t);
    }
    else
    {
        Node* curr = _head;

        for (std::size_t i = 0; i <= pos; ++i)
        {
            curr = curr->next;
        }

        Node* node = new Node(t);
        node->next = curr;
        curr = node;

        ++_size;
    }
}

template<typename T>
void Dataplex::SinglyLinkedList<T>::erase(std::size_t pos)
{
    if (pos < 0 || pos >= _size)
    {
        return;
    }
    else if (pos == _size - 1)
    {
        pop_back();
    }
    else
    {
        Node* curr = _head;
        Node* prev = nullptr;

        for (std::size_t i = 0; i <= pos; ++i)
        {
            prev = curr;
            curr = curr->next;
        }

        Node* next = curr->next;
        delete curr;

        prev->next = next;

        --_size;
    }
}

template<typename T>
std::size_t Dataplex::SinglyLinkedList<T>::size() const
{
    return _size;
}

template<typename T>
bool Dataplex::SinglyLinkedList<T>::is_empty() const
{
    return _size == 0;
}

template<typename T>
Dataplex::SinglyLinkedList<T>::Node::Node(const T& data) :
    next(nullptr),
    data(data)
{
}
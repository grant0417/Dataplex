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

        class Iterator;

        Iterator begin();
        const Iterator begin() const;

        Iterator end();
        const Iterator end() const;

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

        class Iterator
        {
        public:
            Iterator();
            explicit Iterator(Node* node);

            T* operator->();
            T const* operator->() const;

            T& operator*();
            const T& operator*() const;

            Iterator& operator++();
            Iterator operator++(int);

            bool operator==(const Iterator& iterator) const;
            bool operator!=(const Iterator& iterator) const;

        private:
            Node* node;
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
typename Dataplex::SinglyLinkedList<T>::Iterator Dataplex::SinglyLinkedList<T>::begin()
{
    return Iterator(_head);
}

template<typename T>
typename const Dataplex::SinglyLinkedList<T>::Iterator Dataplex::SinglyLinkedList<T>::begin() const
{
    return Iterator(_head);
}

template<typename T>
typename Dataplex::SinglyLinkedList<T>::Iterator Dataplex::SinglyLinkedList<T>::end()
{
    return Iterator(nullptr);
}

template<typename T>
typename const Dataplex::SinglyLinkedList<T>::Iterator Dataplex::SinglyLinkedList<T>::end() const
{
    return Iterator(nullptr);
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
    if (pos > _size)
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
    if (pos >= _size)
    {
        throw std::out_of_range("Position to remove outside of existing range!");
    }
    else if (pos == _size - 1)
    {
        pop_back();
    }
    else
    {
        Node* curr = _head;
        Node* prev = nullptr;

        for (std::size_t i = 1; i < pos; ++i)
        {
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;
        delete curr;

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

template<typename T>
Dataplex::SinglyLinkedList<T>::Iterator::Iterator() :
    node(_head)
{
}

template<typename T>
Dataplex::SinglyLinkedList<T>::Iterator::Iterator(Node* node) :
    node(node)
{
}

template<typename T>
T* Dataplex::SinglyLinkedList<T>::Iterator::operator->()
{
    return &node->data;
}

template<typename T>
T const* Dataplex::SinglyLinkedList<T>::Iterator::operator->() const
{
    return &node->data;
}

template<typename T>
T& Dataplex::SinglyLinkedList<T>::Iterator::operator*()
{
    return node->data;
}

template<typename T>
const T& Dataplex::SinglyLinkedList<T>::Iterator::operator*() const
{
    return node->data;
}

template<typename T>
typename Dataplex::SinglyLinkedList<T>::Iterator& Dataplex::SinglyLinkedList<T>::Iterator::operator++()
{
    if (node)
    {
        node = node->next;
    }

    return *this;
}

template<typename T>
typename Dataplex::SinglyLinkedList<T>::Iterator Dataplex::SinglyLinkedList<T>::Iterator::operator++(int)
{
    Iterator iterator = *this;
    ++*this;

    return iterator;
}

template<typename T>
bool Dataplex::SinglyLinkedList<T>::Iterator::operator!=(const Iterator& iterator) const
{
    return node != iterator.node;
}

template<typename T>
bool Dataplex::SinglyLinkedList<T>::Iterator::operator==(const Iterator& iterator) const
{
    return node == iterator.node;
}
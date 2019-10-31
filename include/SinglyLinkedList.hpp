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
        SinglyLinkedList(const SinglyLinkedList<T>& list);
        SinglyLinkedList& operator=(const SinglyLinkedList<T>& list);
        SinglyLinkedList(SinglyLinkedList<T>&& list);
        SinglyLinkedList& operator=(SinglyLinkedList<T>&& list);
        SinglyLinkedList(std::initializer_list<T> list);

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

        void push_front(const T& data);
        void push_back(const T& data);

        void pop_front();
        void pop_back();

        void insert(const T& data, std::size_t pos);
        void erase(std::size_t pos);

        void clear();

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

            Iterator& operator=(Node* node);

            T* operator->();
            T const* operator->() const;

            T& operator*();
            const T& operator*() const;

            Iterator& operator++();
            Iterator operator++(int);

            bool operator==(const Iterator& iterator) const;
            bool operator!=(const Iterator& iterator) const;

        private:
            Node* _node;
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
Dataplex::SinglyLinkedList<T>::SinglyLinkedList(const Dataplex::SinglyLinkedList<T>& list) :
    SinglyLinkedList()
{
    auto node = list._head;

    while (node != nullptr)
    {
        push_back(node->data);
        node = node->next;
    }
}

template<typename T>
Dataplex::SinglyLinkedList<T>& Dataplex::SinglyLinkedList<T>::operator=(const Dataplex::SinglyLinkedList<T>& list)
{
    Dataplex::SinglyLinkedList<T> temp(list);
    std::swap(_head, temp._head);
    std::swap(_tail, temp._tail);
    std::swap(_size, temp._size);

    return *this;
}

template<typename T>
Dataplex::SinglyLinkedList<T>::SinglyLinkedList(Dataplex::SinglyLinkedList<T>&& list) :
    SinglyLinkedList()
{
    std::swap(_head, list._head);
    std::swap(_tail, list._tail);
    std::swap(_size, list._size);
}

template<typename T>
Dataplex::SinglyLinkedList<T>& Dataplex::SinglyLinkedList<T>::operator=(SinglyLinkedList&& list)
{
    std::swap(_head, list.head);
    std::swap(_tail, list._tail);
    std::swap(_size, list._size);

    return *this;
}

template<typename T>
Dataplex::SinglyLinkedList<T>::SinglyLinkedList(std::initializer_list<T> list) :
    SinglyLinkedList()
{
    for (const auto& data : list)
    {
        push_back(data);
    }
}

template<typename T>
Dataplex::SinglyLinkedList<T>::~SinglyLinkedList()
{
    clear();
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
    if (!_head)
    {
        throw std::out_of_range("Head not initialized!");
    }

    return _head->data;
}

template<typename T>
const T& Dataplex::SinglyLinkedList<T>::head() const
{
    if (!_head)
    {
        throw std::out_of_range("Head not initialized!");
    }

    return _head->data;
}

template<typename T>
T& Dataplex::SinglyLinkedList<T>::tail()
{
    if (!_tail)
    {
        throw std::out_of_range("Tail not initialized!");
    }

    return _tail->data;
}

template<typename T>
const T& Dataplex::SinglyLinkedList<T>::tail() const
{
    if (!_tail)
    {
        throw std::out_of_range("Tail not initialized!");
    }

    return _tail->data;
}

template<typename T>
void Dataplex::SinglyLinkedList<T>::push_front(const T& data)
{
    Node* node = new Node(data);

    if (!_head)
    {
        _head = node;
        _tail = _head;
    }
    else
    {
        node->next = _head;
        _head = node;
    }

    ++_size;
}

template<typename T>
void Dataplex::SinglyLinkedList<T>::push_back(const T& data)
{
    Node* node = new Node(data);

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

template<typename T>
void Dataplex::SinglyLinkedList<T>::pop_front()
{
    if (!_head)
    {
        throw std::out_of_range("No existing elements to remove!");

    }
    else if (_head == _tail)
    {
        delete _head;

        _head = nullptr;
        _tail = nullptr;

        --_size;
    }
    else
    {
        Node* curr = _head;

        _head = curr->next;
        delete curr;

        --_size;
    }
}

template <typename T>
void Dataplex::SinglyLinkedList<T>::pop_back()
{
    if (!_head)
    {
        throw std::out_of_range("No existing elements to remove!");
    }
    else if (_head == _tail)
    {
        delete _head;

        _head = nullptr;
        _tail = nullptr;

        --_size;
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

        --_size;
    }
}

template<typename T>
void Dataplex::SinglyLinkedList<T>::insert(const T& data, std::size_t pos)
{
    if (pos > _size)
    {
        throw std::out_of_range("Position to insert outside of existing range!");
    }
    else if (pos == 0)
    {
        push_front(data);
    }
    else if (pos == _size)
    {
        push_back(data);
    }
    else
    {
        Node* prev = _head;
        Node* curr = _head->next;;

        for (std::size_t i = 1; i < pos; ++i)
        {
            prev = curr;
            curr = curr->next;
        }

        Node* node = new Node(data);
        prev->next = node;
        node->next = curr;

        ++_size;
    }
}

template<typename T>
void Dataplex::SinglyLinkedList<T>::erase(std::size_t pos)
{
    if (!_head)
    {
        throw std::out_of_range("No existing elements to remove!");
    }
    else if (pos >= _size)
    {
        throw std::out_of_range("Position to remove outside of existing range!");
    }
    else if (pos == 0)
    {
        pop_front();
    }
    else if (pos == _size - 1)
    {
        pop_back();
    }
    else
    {
        Node* prev = _head;
        Node* curr = _head->next;

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
void Dataplex::SinglyLinkedList<T>::clear()
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

    _size = 0;
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
    _node(_head)
{
}

template<typename T>
Dataplex::SinglyLinkedList<T>::Iterator::Iterator(Node* node) :
    _node(node)
{
}

template<typename T>
typename Dataplex::SinglyLinkedList<T>::Iterator& Dataplex::SinglyLinkedList<T>::Iterator::operator=(Node* node)
{
    _node = node;
    return *this;
}

template<typename T>
T* Dataplex::SinglyLinkedList<T>::Iterator::operator->()
{
    return &_node->data;
}

template<typename T>
T const* Dataplex::SinglyLinkedList<T>::Iterator::operator->() const
{
    return &_node->data;
}

template<typename T>
T& Dataplex::SinglyLinkedList<T>::Iterator::operator*()
{
    return _node->data;
}

template<typename T>
const T& Dataplex::SinglyLinkedList<T>::Iterator::operator*() const
{
    return _node->data;
}

template<typename T>
typename Dataplex::SinglyLinkedList<T>::Iterator& Dataplex::SinglyLinkedList<T>::Iterator::operator++()
{
    if (_node)
    {
        _node = _node->next;
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
    return _node != iterator._node;
}

template<typename T>
bool Dataplex::SinglyLinkedList<T>::Iterator::operator==(const Iterator& iterator) const
{
    return _node == iterator._node;
}
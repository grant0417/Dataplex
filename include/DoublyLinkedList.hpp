/*
Copyright (c) 2019 Inverse Palindrome
Dataplex - DoublyLinkedList.hpp
http://inversepalindrome.com
*/


#pragma once

#include <cstddef>
#include <exception>


namespace Dataplex
{
    template<typename T>
    class DoublyLinkedList
    {
    public:
        DoublyLinkedList();
        DoublyLinkedList(const DoublyLinkedList<T>& list);
        DoublyLinkedList& operator=(const DoublyLinkedList<T>& list);
        DoublyLinkedList(DoublyLinkedList<T>&& list);
        DoublyLinkedList& operator=(DoublyLinkedList<T>&& list);
        DoublyLinkedList(std::initializer_list<T> list);

        ~DoublyLinkedList();

        class Iterator;

        Iterator begin();
        const Iterator begin() const;

        Iterator end();
        const Iterator end() const;

        T& head();
        const T& head() const;

        T& tail();
        const T& tail() const;

        void push_front(const T& t);
        void push_back(const T& t);

        void pop_front();
        void pop_back();

        void insert(const T& t, std::size_t pos);
        void erase(std::size_t pos);

        void clear();

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

            Iterator& operator--();
            Iterator operator--(int);

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
Dataplex::DoublyLinkedList<T>::DoublyLinkedList() :
    _head(nullptr),
    _tail(nullptr),
    _size(0)
{
}

template<typename T>
Dataplex::DoublyLinkedList<T>::DoublyLinkedList(const Dataplex::DoublyLinkedList<T>& list)
{

}

template<typename T>
Dataplex::DoublyLinkedList<T>& Dataplex::DoublyLinkedList<T>::operator=(const Dataplex::DoublyLinkedList<T>& list)
{

}

template<typename T>
Dataplex::DoublyLinkedList<T>::DoublyLinkedList(Dataplex::DoublyLinkedList<T>&& list)
{

}

template<typename T>
Dataplex::DoublyLinkedList<T>& Dataplex::DoublyLinkedList<T>::operator=(DoublyLinkedList&& list)
{

}

template<typename T>
Dataplex::DoublyLinkedList<T>::DoublyLinkedList(std::initializer_list<T> list) :
    DoublyLinkedList()
{
    for (const auto& data : list)
    {
        push_back(data);
    }
}

template<typename T>
Dataplex::DoublyLinkedList<T>::~DoublyLinkedList()
{
    clear();
}

template<typename T>
typename Dataplex::DoublyLinkedList<T>::Iterator Dataplex::DoublyLinkedList<T>::begin()
{
    return Iterator(_head);
}

template<typename T>
typename const Dataplex::DoublyLinkedList<T>::Iterator Dataplex::DoublyLinkedList<T>::begin() const
{
    return Iterator(_head);
}

template<typename T>
typename Dataplex::DoublyLinkedList<T>::Iterator Dataplex::DoublyLinkedList<T>::end()
{
    return Iterator(nullptr);
}

template<typename T>
typename const Dataplex::DoublyLinkedList<T>::Iterator Dataplex::DoublyLinkedList<T>::end() const
{
    return Iterator(nullptr);
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
void Dataplex::DoublyLinkedList<T>::push_front(const T& t)
{
    
}

template<typename T>
void Dataplex::DoublyLinkedList<T>::push_back(const T& t)
{
    auto node = new Node(T);

    
}

template<typename T>
void Dataplex::DoublyLinkedList<T>::pop_front()
{

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
void Dataplex::DoublyLinkedList<T>::clear()
{
    _size = 0;
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

template<typename T>
Dataplex::DoublyLinkedList<T>::Iterator::Iterator() :
    _node(_head)
{
}

template<typename T>
Dataplex::DoublyLinkedList<T>::Iterator::Iterator(Node* node) :
    _node(node)
{
}

template<typename T>
typename Dataplex::DoublyLinkedList<T>::Iterator& Dataplex::DoublyLinkedList<T>::Iterator::operator=(Node* node)
{
    _node = node;
    return *this;
}

template<typename T>
T* Dataplex::DoublyLinkedList<T>::Iterator::operator->()
{
    return &_node->data;
}

template<typename T>
T const* Dataplex::DoublyLinkedList<T>::Iterator::operator->() const
{
    return &_node->data;
}

template<typename T>
T& Dataplex::DoublyLinkedList<T>::Iterator::operator*()
{
    return _node->data;
}

template<typename T>
const T& Dataplex::DoublyLinkedList<T>::Iterator::operator*() const
{
    return _node->data;
}

template<typename T>
typename Dataplex::DoublyLinkedList<T>::Iterator& Dataplex::DoublyLinkedList<T>::Iterator::operator++()
{
    if (_node)
    {
        _node = _node->next;
    }

    return *this;
}

template<typename T>
typename Dataplex::DoublyLinkedList<T>::Iterator Dataplex::DoublyLinkedList<T>::Iterator::operator++(int)
{
    Iterator iterator = *this;
    ++* this;

    return iterator;
}

template<typename T>
typename Dataplex::DoublyLinkedList<T>::Iterator& Dataplex::DoublyLinkedList<T>::Iterator::operator--()
{
    if (_node)
    {
        _node = _node->prev;
    }

    return *this;
}

template<typename T>
typename Dataplex::DoublyLinkedList<T>::Iterator Dataplex::DoublyLinkedList<T>::Iterator::operator--(int)
{
    Iterator iterator = *this;
    --*this;

    return iterator;
}

template<typename T>
bool Dataplex::DoublyLinkedList<T>::Iterator::operator!=(const Iterator& iterator) const
{
    return _node != iterator._node;
}

template<typename T>
bool Dataplex::DoublyLinkedList<T>::Iterator::operator==(const Iterator& iterator) const
{
    return _node == iterator._node;
}
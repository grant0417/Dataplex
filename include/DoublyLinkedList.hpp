/*
Copyright (c) 2019 Inverse Palindrome
Dataplex - DoublyLinkedList.hpp
http://inversepalindrome.com
*/


#pragma once

#include <cstddef>
#include <iterator>
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
        class ConstIterator;

        class ReverseIterator;
        class ConstReverseIterator;

        Iterator begin();
        ConstIterator begin() const;

        Iterator end();
        ConstIterator end() const;

        ReverseIterator rbegin();
        ConstReverseIterator rbegin() const;

        ReverseIterator rend();
        ConstReverseIterator rend() const;

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

            T data;
            Node* next;
            Node* prev;
        };

        class Iterator
        {
            using value_type = T;
            using difference_type = std::ptrdiff_t;
            using pointer = T*;
            using reference = T&;
            using iterator_category = std::bidirectional_iterator_tag;

        public:
            explicit Iterator(Node* node);

            Iterator& operator=(Node* node);

            T& operator*();
            T* operator->();

            Iterator& operator++();
            Iterator operator++(int);

            Iterator& operator--();
            Iterator operator--(int);

            bool operator==(const Iterator& iterator) const;
            bool operator!=(const Iterator& iterator) const;

        private:
            Node* _node;
        };

        class ConstIterator
        {
            using value_type = T;
            using difference_type = std::ptrdiff_t;
            using pointer = T*;
            using reference = T&;
            using iterator_category = std::bidirectional_iterator_tag;

        public:
            explicit ConstIterator(Node* node);

            ConstIterator& operator=(Node* node);

            const T& operator*() const;
            const T* operator->() const;

            ConstIterator& operator++();
            ConstIterator operator++(int);

            ConstIterator& operator--();
            ConstIterator operator--(int);

            bool operator==(const ConstIterator& iterator) const;
            bool operator!=(const ConstIterator& iterator) const;

        private:
            Node* _node;
        };

        class ReverseIterator
        {
            using value_type = T;
            using difference_type = std::ptrdiff_t;
            using pointer = T*;
            using reference = T&;
            using iterator_category = std::bidirectional_iterator_tag;
            
        public:
            explicit ReverseIterator(Node* node);

            ReverseIterator& operator=(Node* node);

            T& operator*();
            T* operator->();

            ReverseIterator& operator++();
            ReverseIterator operator++(int);

            ReverseIterator& operator--();
            ReverseIterator operator--(int);

            bool operator==(const ReverseIterator& iterator) const;
            bool operator!=(const ReverseIterator& iterator) const;

        private:
            Node* _node;
        };

        class ConstReverseIterator
        {
            using value_type = T;
            using difference_type = std::ptrdiff_t;
            using pointer = T*;
            using reference = T&;
            using iterator_category = std::bidirectional_iterator_tag;

        public:
            explicit ConstReverseIterator(Node* node);

            ConstReverseIterator& operator=(Node* node);

            const T& operator*() const;
            const T* operator->() const;

            ConstReverseIterator& operator++();
            ConstReverseIterator operator++(int);

            ConstReverseIterator& operator--();
            ConstReverseIterator operator--(int);

            bool operator==(const ConstReverseIterator& iterator) const;
            bool operator!=(const ConstReverseIterator& iterator) const;

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
Dataplex::DoublyLinkedList<T>::DoublyLinkedList(const Dataplex::DoublyLinkedList<T>& list) :
    DoublyLinkedList()
{
    auto node = list._head;

    while (node != nullptr)
    {
        push_back(node->data);
        node = node->next;
    }
}

template<typename T>
Dataplex::DoublyLinkedList<T>& Dataplex::DoublyLinkedList<T>::operator=(const Dataplex::DoublyLinkedList<T>& list)
{
    Dataplex::SinglyLinkedList<T> temp(list);
    std::swap(_head, temp._head);
    std::swap(_tail, temp._tail);
    std::swap(_size, temp._size);

    return *this;
}

template<typename T>
Dataplex::DoublyLinkedList<T>::DoublyLinkedList(Dataplex::DoublyLinkedList<T>&& list) :
    DoublyLinkedList()
{
    std::swap(_head, list._head);
    std::swap(_tail, list._tail);
    std::swap(_size, list._size);
}

template<typename T>
Dataplex::DoublyLinkedList<T>& Dataplex::DoublyLinkedList<T>::operator=(DoublyLinkedList&& list)
{
    std::swap(_head, list._head);
    std::swap(_tail, list._tail);
    std::swap(_size, list._size);

    return *this;
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
typename Dataplex::DoublyLinkedList<T>::ConstIterator Dataplex::DoublyLinkedList<T>::begin() const
{
    return ConstIterator(_head);
}

template<typename T>
typename Dataplex::DoublyLinkedList<T>::Iterator Dataplex::DoublyLinkedList<T>::end()
{
    return Iterator(nullptr);
}

template<typename T>
typename Dataplex::DoublyLinkedList<T>::ConstIterator Dataplex::DoublyLinkedList<T>::end() const
{
    return ConstIterator(nullptr);
}

template<typename T>
typename Dataplex::DoublyLinkedList<T>::ReverseIterator Dataplex::DoublyLinkedList<T>::rbegin()
{
    return ReverseIterator(_tail);
}

template<typename T>
typename Dataplex::DoublyLinkedList<T>::ConstReverseIterator Dataplex::DoublyLinkedList<T>::rbegin() const
{
    return ConstReverseIterator(_tail);
}

template<typename T>
typename Dataplex::DoublyLinkedList<T>::ReverseIterator Dataplex::DoublyLinkedList<T>::rend()
{
    return ReverseIterator(nullptr);
}

template<typename T>
typename Dataplex::DoublyLinkedList<T>::ConstReverseIterator Dataplex::DoublyLinkedList<T>::rend() const
{
    return ConstReverseIterator(nullptr);
}

template<typename T>
T& Dataplex::DoublyLinkedList<T>::head()
{
    if (!_head)
    {
        throw std::out_of_range("Head not initialized!");
    }

    return _head->data;
}

template<typename T>
const T& Dataplex::DoublyLinkedList<T>::head() const
{
    if (!_head)
    {
        throw std::out_of_range("Head not initialized!");
    }

    return _head->data;
}

template<typename T>
T& Dataplex::DoublyLinkedList<T>::tail()
{
    if (!_tail)
    {
        throw std::out_of_range("Tail not initialized!");
    }

    return _tail->data;
}

template<typename T>
const T& Dataplex::DoublyLinkedList<T>::tail() const
{
    if (!_tail)
    {
        throw std::out_of_range("Tail not initialized!");
    }

    return _tail->data;
}

template<typename T>
void Dataplex::DoublyLinkedList<T>::push_front(const T& data)
{
    auto node = new Node(data);

    if (!_head)
    {
        _head = node;
        _tail = _head;
    }
    else
    {
        node->next = _head;
        _head->prev = node;
        _head = node;
    }

    ++_size;
}

template<typename T>
void Dataplex::DoublyLinkedList<T>::push_back(const T& data)
{
    auto node = new Node(data);

    if (!_head)
    {
        _head = node;
        _tail = _head;
    }
    else
    {
        _tail->next = node;
        node->prev = _tail;
        _tail = node;
    }

    ++_size;
}

template<typename T>
void Dataplex::DoublyLinkedList<T>::pop_front()
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
        _head->prev = nullptr;

        delete curr;

        --_size;
    }
}

template <typename T>
void Dataplex::DoublyLinkedList<T>::pop_back()
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
        Node* curr = _tail;
        _tail = _tail->prev;
        _tail->next = nullptr;

        delete curr;

        --_size;
    }
}

template<typename T>
void Dataplex::DoublyLinkedList<T>::insert(const T& data, std::size_t pos)
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
        Node* curr = _head;

        for (std::size_t i = 1; i < pos; ++i)
        {
            curr = curr->next;
        }

        Node* node = new Node(data);
        node->next = curr->next;
        node->prev = curr;
        curr->next = node;
        curr->next->prev = node;

        ++_size;
    }
}

template<typename T>
void Dataplex::DoublyLinkedList<T>::erase(std::size_t pos)
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
        Node* curr = _head->next;

        for (std::size_t i = 1; i < pos; ++i)
        {
            curr = curr->next;
        }

        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;

        delete curr;

        --_size;
    }
}

template<typename T>
void Dataplex::DoublyLinkedList<T>::clear()
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
T& Dataplex::DoublyLinkedList<T>::Iterator::operator*()
{
    return _node->data;
}

template<typename T>
T* Dataplex::DoublyLinkedList<T>::Iterator::operator->()
{
    return &_node->data;
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
    auto iterator = *this;
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
    auto iterator = *this;
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

template<typename T>
Dataplex::DoublyLinkedList<T>::ConstIterator::ConstIterator(Node* node) :
    _node(node)
{
}

template<typename T>
typename Dataplex::DoublyLinkedList<T>::ConstIterator& Dataplex::DoublyLinkedList<T>::ConstIterator::operator=(Node* node)
{
    _node = node;
    return *this;
}

template<typename T>
const T& Dataplex::DoublyLinkedList<T>::ConstIterator::operator*() const
{
    return _node->data;
}

template<typename T>
const T* Dataplex::DoublyLinkedList<T>::ConstIterator::operator->() const
{
    return &_node->data;
}

template<typename T>
typename Dataplex::DoublyLinkedList<T>::ConstIterator& Dataplex::DoublyLinkedList<T>::ConstIterator::operator++()
{
    if (_node)
    {
        _node = _node->next;
    }

    return *this;
}

template<typename T>
typename Dataplex::DoublyLinkedList<T>::ConstIterator Dataplex::DoublyLinkedList<T>::ConstIterator::operator++(int)
{
    auto iterator = *this;
    ++* this;

    return iterator;
}

template<typename T>
typename Dataplex::DoublyLinkedList<T>::ConstIterator& Dataplex::DoublyLinkedList<T>::ConstIterator::operator--()
{
    if (_node)
    {
        _node = _node->prev;
    }

    return *this;
}

template<typename T>
typename Dataplex::DoublyLinkedList<T>::ConstIterator Dataplex::DoublyLinkedList<T>::ConstIterator::operator--(int)
{
    auto iterator = *this;
    --* this;

    return iterator;
}

template<typename T>
bool Dataplex::DoublyLinkedList<T>::ConstIterator::operator!=(const ConstIterator& iterator) const
{
    return _node != iterator._node;
}

template<typename T>
bool Dataplex::DoublyLinkedList<T>::ConstIterator::operator==(const ConstIterator& iterator) const
{
    return _node == iterator._node;
}

template<typename T>
Dataplex::DoublyLinkedList<T>::ReverseIterator::ReverseIterator(Node* node) :
    _node(node)
{
}

template<typename T>
typename Dataplex::DoublyLinkedList<T>::ReverseIterator& Dataplex::DoublyLinkedList<T>::ReverseIterator::operator=(Node* node)
{
    _node = node;
    return *this;
}

template<typename T>
T& Dataplex::DoublyLinkedList<T>::ReverseIterator::operator*()
{
    return _node->data;
}

template<typename T>
T* Dataplex::DoublyLinkedList<T>::ReverseIterator::operator->()
{
    return &_node->data;
}

template<typename T>
typename Dataplex::DoublyLinkedList<T>::ReverseIterator& Dataplex::DoublyLinkedList<T>::ReverseIterator::operator++()
{
    if (_node)
    {
        _node = _node->prev;
    }

    return *this;
}

template<typename T>
typename Dataplex::DoublyLinkedList<T>::ReverseIterator Dataplex::DoublyLinkedList<T>::ReverseIterator::operator++(int)
{
    auto iterator = *this;
    ++* this;

    return iterator;
}

template<typename T>
typename Dataplex::DoublyLinkedList<T>::ReverseIterator& Dataplex::DoublyLinkedList<T>::ReverseIterator::operator--()
{
    if (_node)
    {
        _node = _node->next;
    }

    return *this;
}

template<typename T>
typename Dataplex::DoublyLinkedList<T>::ReverseIterator Dataplex::DoublyLinkedList<T>::ReverseIterator::operator--(int)
{
    auto iterator = *this;
    --* this;

    return iterator;
}

template<typename T>
bool Dataplex::DoublyLinkedList<T>::ReverseIterator::operator!=(const ReverseIterator& iterator) const
{
    return _node != iterator._node;
}

template<typename T>
bool Dataplex::DoublyLinkedList<T>::ReverseIterator::operator==(const ReverseIterator& iterator) const
{
    return _node == iterator._node;
}

template<typename T>
Dataplex::DoublyLinkedList<T>::ConstReverseIterator::ConstReverseIterator(Node* node) :
    _node(node)
{
}

template<typename T>
typename Dataplex::DoublyLinkedList<T>::ConstReverseIterator& Dataplex::DoublyLinkedList<T>::ConstReverseIterator::operator=(Node* node)
{
    _node = node;
    return *this;
}

template<typename T>
const T& Dataplex::DoublyLinkedList<T>::ConstReverseIterator::operator*() const
{
    return _node->data;
}

template<typename T>
const T* Dataplex::DoublyLinkedList<T>::ConstReverseIterator::operator->() const
{
    return &_node->data;
}

template<typename T>
typename Dataplex::DoublyLinkedList<T>::ConstReverseIterator& Dataplex::DoublyLinkedList<T>::ConstReverseIterator::operator++()
{
    if (_node)
    {
        _node = _node->prev;
    }

    return *this;
}

template<typename T>
typename Dataplex::DoublyLinkedList<T>::ConstReverseIterator Dataplex::DoublyLinkedList<T>::ConstReverseIterator::operator++(int)
{
    auto iterator = *this;
    ++* this;

    return iterator;
}

template<typename T>
typename Dataplex::DoublyLinkedList<T>::ConstReverseIterator& Dataplex::DoublyLinkedList<T>::ConstReverseIterator::operator--()
{
    if (_node)
    {
        _node = _node->next;
    }

    return *this;
}

template<typename T>
typename Dataplex::DoublyLinkedList<T>::ConstReverseIterator Dataplex::DoublyLinkedList<T>::ConstReverseIterator::operator--(int)
{
    auto iterator = *this;
    --* this;

    return iterator;
}

template<typename T>
bool Dataplex::DoublyLinkedList<T>::ConstReverseIterator::operator!=(const ConstReverseIterator& iterator) const
{
    return _node != iterator._node;
}

template<typename T>
bool Dataplex::DoublyLinkedList<T>::ConstReverseIterator::operator==(const ConstReverseIterator& iterator) const
{
    return _node == iterator._node;
}
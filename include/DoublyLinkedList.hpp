/*
Copyright (c) 2019 Inverse Palindrome
Dataplex - DoublyLinkedList.hpp
http://inversepalindrome.com
*/


#pragma once

#include <memory>
#include <cstddef>


namespace Dataplex
{
    template<typename T>
    class DoublyLinkedList
    {
    public:
        DoublyLinkedList();

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
            std::unique_ptr<Node> next;
            std::unique_ptr<Node> prev;
        };

        std::unique_ptr<Node> head;
        std::unique_ptr<Node> tail;

        std::size_t _size;
    };
}

template<typename T>
Dataplex::DoublyLinkedList<T>::DoublyLinkedList() :
    size(0)
{
}

template<typename T>
void Dataplex::DoublyLinkedList<T>::push_back(const T& t)
{
    auto node = std::make_unique<Node>(t);

    
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
    data(data)
{
}
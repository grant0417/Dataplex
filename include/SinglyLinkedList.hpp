/*
Copyright (c) 2019 Inverse Palindrome
Dataplex - SinglyLinkedList.hpp
http://inversepalindrome.com
*/


#pragma once

#include <memory>
#include <cstddef>


namespace Dataplex
{
    template<typename T>
    class SinglyLinkedList
    {
    public:
        SinglyLinkedList();

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

            std::unique_ptr<Node> next;
            T data;
        };

        std::unique_ptr<Node> head;
        std::unique_ptr<Node> tail;

        std::size_t _size;
    };
}

template<typename T>
Dataplex::SinglyLinkedList<T>::SinglyLinkedList() :
    size(0)
{
}

template<typename T>
void Dataplex::SinglyLinkedList<T>::push_back(const T& t)
{
    auto node = std::make_unique<Node>(t);

    if (head)
    {
        tail->next = std::move(node);
        tail = tail->next;
    }
    else
    {
        head = std::move(node);
        tail = std::move(head);
    }
}

template <typename T>
void Dataplex::SinglyLinkedList<T>::pop_back()
{
    if (!head)
    {
        return;
    }
    else if (head == tail)
    {
        head = nullptr;
        tail = nullptr;
    }
    else
    {

    }
}

template<typename T>
void Dataplex::SinglyLinkedList<T>::insert(const T& t, std::size_t pos)
{

}

template<typename T>
void Dataplex::SinglyLinkedList<T>::erase(std::size_t pos)
{

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
    data(data)
{
}
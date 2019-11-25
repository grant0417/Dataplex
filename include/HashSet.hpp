/*
Copyright (c) 2019 Inverse Palindrome
Dataplex - HashSet.hpp
http://inversepalindrome.com
*/


#pragma once


namespace Dataplex
{
    template<typename T>
    class HashSet
    {
    public:
        HashSet(const HashSet<T>& hashSet);
        HashSet<T>& operator=(const HashSet<T>& hashSet);
        HashSet(HashSet<T>&& hashSet);
        HashSet<T>& operator==(HashSet<T>&& hashSet);

        ~HashSet();

    private:
    };
}

template<typename T>
Dataplex::HashSet<T>::HashSet(const HashSet<T>& hashSet)
{

}

template<typename T>
Dataplex::HashSet<T>& Dataplex::HashSet<T>::operator=(const HashSet<T>& hashSet)
{
    return *this
}

template<typename T>
Dataplex::HashSet<T>::HashSet(HashSet<T>&& hashSet)
{

}

template<typename T>
Dataplex::HashSet<T>& Dataplex::HashSet<T>::operator==(HashSet<T>&& hashSet)
{
    return *this;
}

template<typename T>
Dataplex::HashSet<T>::~HashSet()
{

}
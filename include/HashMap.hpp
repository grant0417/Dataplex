/*
Copyright (c) 2019 Inverse Palindrome
Dataplex - HashMap.hpp
http://inversepalindrome.com
*/


#pragma once


namespace Dataplex
{
    template<typename Key, typename Value>
    class HashMap
    {
    public:
        HashMap(const HashMap<Key, Value>& hashMap);
        HashMap<Key, Value>& operator=(const HashMap <Key, Value>& hashMap);
        HashMap(HashMap<Key, Value>&& hashMap);
        HashMap<Key, Value>& operator=(HashMap<Key, Value>&& hashMap);

        ~HashMap();

    private:
    };
}

template<typename Key, typename Value>
Dataplex::HashMap<Key, Value>::HashMap(const HashMap<Key, Value>& hashMap)
{

}

template<typename Key, typename Value>
Dataplex::HashMap<Key, Value>& Dataplex::HashMap<Key, Value>::operator=(const HashMap<Key, Value>& hashMap)
{
    return *this;
}

template<typename Key, typename Value>
Dataplex::HashMap<Key, Value>::HashMap(HashMap<Key, Value>&& hashMap)
{
    
}

template<typename Key, typename Value>
Dataplex::HashMap<Key, Value>& Dataplex::HashMap<Key, Value>::operator=(HashMap<Key, Value>&& hashMap)
{
    return *this;
}

template<typename Key, typename Value>
Dataplex::HashMap<Key, Value>::~HashMap()
{

}
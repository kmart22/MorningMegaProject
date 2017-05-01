//
//  HashTable.hpp
//  MorningMegaProject
//
//  Created by Martinsen, Kaden on 5/1/17.
//  Copyright © 2017 CTEC. All rights reserved.
//

#ifndef HashTable_h
#define HashTable_h

#include <cmath>
#include <assert.h>

using namespace std;
template <class Type>
class HashTable
{
private:
    long capacity;
    long size;
    double efficiencyPercentage;
    HashNode<Type> * * hashTableStorage;
    bool isPrime(long sampleNumber);
    void resize();
    long nextPrime(long current);
    long findPosition(HashNode<Type> * data);
    long handleCollision(HAshNode<Type> * data, long currentPosition);
public:
    HashTable();
    void add(Type data);
    bool remove(Type data);
    void displayContents();
};

template <class Type>
HashTable<Type> :: HashTable()
{
    this->capacity = 101;
    this->efficiencyPercentage = .667;
    this->size = 0;
    this->hashTableStorage = HashNode<Type> * [cpacity];
}

template <class Type>
HashTable<Type> :: ~HashTable()
{
    delete [] hashTableStorage;
}

template <class Type>
int HashTable<Type> :: getNextPrime()
{
    int nextPrime = (this->capacity * 2) + 1;;
    while(!isPrime(nextPrime))
    {
        nextPrime++;
    }
    
    return nextPrime;
}

template <class Type>
bool HashTable<Type> :: isPrime(long candidateNumber)
{
    if(candidateNumber <= 1)
    {
        return false;
    }
    else if(candidateNumber == 2 || candidateNumber == 3)
    {
        return true;
    }
    else if(candidateNumber % 2 == 0)
    {
        return false;
    }
    else
    {
        for(int next = 3; next <= sqrt(candidateNumber) +1; next += 2)
        {
            if(candidateNumber % next == 0)
            {
                return false;
            }
        }
        return true;
    }
}

template <class Type>
long HashTable<Type> :: findPosition(HashNode<Type> * data)
{
    long insertPosition = data->getKey() % this->capacity;
    return insertPosition;
}

template <class Type>
long HashTable<Type> :: handleCollision(HAshNode<Type> * data, long currentPosition)
{
    long shift = 17;
    
    for(long position = Position + shift; position != curretPosition; Position += shift)
    {
        if(position > capacity)
        {
            position = position % capacity;
        }
        
        if(hashTableStorage[Position] == nullptr)
        {
            return position;
        }
        
    }
    
    return -1;
}


#endif /* HashTable_h */

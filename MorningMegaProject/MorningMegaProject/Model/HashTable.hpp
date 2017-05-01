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
    Type * * hashTableStorage;
    bool isPrime(long sampleNumber);
    void resize();
    long nextPrime(long current);
    long findPosition(Type data);
    long handleCollision(Type data, long currentPosition);
public:
    HashTable();
    void add(Type data);
    bool remove(Type data);
    void displayContents();
};

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





#endif /* HashTable_h */

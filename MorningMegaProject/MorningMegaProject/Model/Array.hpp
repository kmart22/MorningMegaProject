//
//  IntNodeArray.h
//  MorningMegaProject
//
//  Created by Martinsen, Kaden on 2/15/17.
//  Copyright © 2017 CTEC. All rights reserved.
//

#ifndef Array.hpp
#define Array.hpp

#include <assert.h>
#include "Node.hpp"

template <class Type>
class Array
{
private:
    
    Node<Type>* front;
    int size;

public:
    Array<Type>(int size);
    int getSize();
    Type getFromIndex(int index);
    void setAtIndex(int index, Type value);
    
};

//Implementation section

template <class Type>
Array<Type> :: Array()
{
    assert(size > 0);
    this->size = size;
    
    this->front = new Node<Type>();
    for(int index = 1; index < size; index++)
    {
        Node<Type> * currentNode = new Node<type>();
        currentNode->setNodePointer(front);
        front = currentNode;

    }
}

template <class Type>
type Array<Type> :: getFromIndex(int index)
{
    assert(index >=0 && index < size);
    Type value;
    
    Node<Type> * current = front;
    
    for(int position = 0; position < index; position++)
    {
        current = current->getNodePointer();
    }
    
    value = current->getNodeData();
    return value;
}

template <class Type>
void Array<Type> :: setAtIndex(int index, Type value)
{
    assert(index >= 0 && index < size);
    Node<Type> * current = front;
    for(int position = 0; position < index; position++)
    {
        current = current->getNodePointer();
    }
    
    current->setNodeData(value);
    
}

template <class Type> 



#endif /* IntNodeArray_h */

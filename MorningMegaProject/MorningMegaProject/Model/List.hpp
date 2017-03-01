//
//  List.hpp
//  MorningMegaProject
//
//  Created by Martinsen, Kaden on 2/21/17.
//  Copyright © 2017 CTEC. All rights reserved.
//

#ifndef List_h
#define List_h

#include <assert.h>
#include "Node.hpp"

template <class Type>
class List
{
private:
    Node<Type> * front;
    Node<Type> * end;
    int size;
public:
    //constructor
    List<Type>();
    
    //deconstructor
    ~List<Type>();
    
    //copyConstructor
    List<type>(const List<Type> & source);
    
    //methods
    void addAtIndex(int index, Type value);
    void addFront(Type value);
    Type remove(int index);
    Type setAtIndex(int index, Type value);
    Type getFromIndex(int index);
    bool contains(Type data);
    
    
    int getSize() const;
    Node<Type> * getFront() const;
    Node<Type> * getEnd() const;
 
};


template <class Type>
List<Type> :: List()
{
    this->size = 0;
    this->front = nullptr;
    this->end = nullptr;
}


template <class Type>
void List<Type> :: addFront(Type value)
{
     Node<Type> * first = new Node(value);
    if(size == 0)
    {
        this->front = first;
        this->end = first;
    }
    else
    {
       // Node<Type> * newFirst = new Node<type>();
       // newFirst->setNodeData(value);
        newFirst->setNodePointer(front);
        //or
        //Node<Type> * newFirst = new Node<type>(value, front);
        front = newFirst;
    }
    
    size++;
}


template <class Type>
void List<Type> :: addEnd(Type data)
{
    Node<Type> & added = new Node<Type>(data);
    if(size == 0)
    {
        this->front = added;
        this->end = added;
    }
    else
    {
        end->setNodePointer(added);
        this->end = added;
    }
    size++;
}


template <class Type>
void List<Type> :: addAtIndex(int index, Type value)
{
    //creating a new node and pointing the old one to the new one and pointing the new one to the next spot.
    assert(index >= 0 && index <= size);
    if(index ==0)
    {
        addFront(value);
        
    }
    else if(index == size)
    {
        addEnd(value);
        
    }
    else
    {
        Node<Type> * insertNode = new Node<Type>(value);
        Node<Type> * current = front;
        Node<Type> * previous = nullptr;
        
        for(int position = 0; position < index; position++)
        {
            previous = current;
            current = current->getNodePointer();
        }
        
        previous->setNodePointer(insertedNode);
        insertedNode->setNodePointer(current);
        
        size++;
    }

}

template <class Type>
Type List<Type> :: remove(int index)
{
    assert(index >= 0 && index < size);
    Type removed;
    
    Node<Type> * current = front;
    Node<Type> * previous = nullptr;
    Node<Type> * toBeRemoved = nullptr;
    
    
    if(index==0)
    {
        toBeRemoved = front;
        front = front->getNodePointer();
    }
    else if(index == size -1)
    {
        for(int spot = 0; spot < index; spot++)
        {
            previous = current;
            current = current->getNodePointer();
        }
        
        toBeRemoved = current;
        previous->setNodePointer(nullptr);
        this->end = previous;
        
    }
    else
    {
        for(int spot = 0; spot < index; spot++)
        {
            previous = current;
            current = current->getNodePointer();
        }
        
        toBeRemoved = current;
        current = toBeRemoved->getNodePointer();
        previous->setNodePointer(current);

    }
    removed = toBeRemoved->getNodeData();
    
    delete toBeRemoved;
    
    
    size--;
    return removed;

    
}


#endif /* List_h */

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

#endif /* List_h */

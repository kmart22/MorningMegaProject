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
    //constructor
    Array<Type>();
    Array<Type>(int size);
    
    //deconstructor
    ~Array<Type>();
    
    //copy constructor
    Array<Type>(const Array<Type> & toBeCopied);
    
    //Assignment Operator overload
    void operator = (const Array<Type> & toBeAssigned);
    
    //methods
    int getSize() const;
    Node<Type> * getFront() const;
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
        currentNode->setnextPointer(front);
        front = currentNode;

    }
}

template <class Type>
Node<Type<* Array<Type> :: getFront() const
{
    return front;
}


template <class Type>
type Array<Type> :: getFromIndex(int index)
{
    assert(index >=0 && index < size);
    Type value;
    
    Node<Type> * current = front;
    
    for(int position = 0; position < index; position++)
    {
        current = current->getnextPointer();
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
        current = current->getnextPointer();
    }
    
    current->setNodeData(value);
    
}


template <class Type>
int Array<Type> :: getSize() const
{
    return size;
}


template <class Type>
Array<Type> :: ~Array()
{
    int count = size;
    Node<Type> * remove = front;
    while(front != nullptr)
    {
        //move to next node in array
        front = front->getnextPointer();
        cout << "Moving to the next node. At: " << count << endl;
        //delete the front ponter
        delete remove;
        cout << "deleting the old front pointer." << endl;
        //move delete to new front
        remove = front;
        cout << "moving to new pointer." << endl;
        count--;
        cout << "front is at: " << front << " count is: " << count << endl;
        
    }
}


template <class Type>
Array<Type> :: Array(const Array<Type> & toBeCopied)
{
    this->size = toBeCopied.getSize();
    
    //Build data Structure
    this->front = new Node<Type>();
    for(int index = 1; index < size; index++)
    {
        Node<type> * temp = new Node<Type>();
        temp->setnextPointer(front);
        front = temp;
    }
    
    Node<Type> * copyTemp = toBeCopied.getFront();
    Node<Type> * updated = this->front;
    for(int index = 0; index < size; index++)
    {
        updated->setNodeData(copyTemp->getNodeData());
        updated = updated->getnextPointer():
        copyTemp = copyTemp->getnextPointer();
    }
}




template <class Type> 
Array<Type> :: Array()
{
    //DO NOT USE!!!
    
    
}


#endif /* IntNodeArray_h */

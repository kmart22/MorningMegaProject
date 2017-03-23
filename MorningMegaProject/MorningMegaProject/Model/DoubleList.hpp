//
//  DoubleList.hpp
//  MorningMegaProject
//
//  Created by Martinsen, Kaden on 3/3/17.
//  Copyright © 2017 CTEC. All rights reserved.
//

#ifndef DoubleList_h
#define DoubleList_h

#include "DoublyLinkedList.hpp"

template <class Type>
class DoubleList : public DoublyLinkedList<Type>
{
private:
public:
    DoubleList();
    ~DoubleList();
    void add(Type data);
    Type remove(int index);
    void addAtIndexFast(int index, Type value);
    void addAtIndex(int index, Type value);
    Type getFromIndex(int index);
    Type getFromIndexFast(int index);
    int indexOf(Type itemToFind);
    int nextIndexOf(Type item, int startPoint);
};

template <class Type>
DoubleList<Type> :: DoubleList() : DoublyLinkedList<Type>()
{
    
}

template <class Type>
DoubleList<Type> :: ~DoubleList()
{
    
}

template <class Type>
void DoubleList<Type> :: add(Type value)
{
    BiDirectionalNode<Type> * addedNode = new BiDirectionalNode<Type>(value);
    if(this->getSize() == 0)
    {
        this->setFront(addedNode);
    }
   else
   {
       this->getEnd()->setNextPointer(addedNode);
       addedNode->setPreviousPointer(this->getEnd());
   }
    this->setEnd(addedNode);
    this->setSize(this->getSize() + 1);
       
    
}

/*
 you create a variable named derp. you then take the front node and take it out. then you point the previous node to the next node and the next node to the previous.
 */
template <class Type>
Type DoubleList<Type> :: remove(int index)
{
    Type derp;
    BiDirectionalNode<Type> * nodeToTakeOut = this->getFront();
    for(int spot = 0; spot < index; spot++)
    {
        nodeToTakeOut = nodeToTakeOut->getNextPointer();
    }
    derp= nodeToTakeOut->getNodeData();
    
    BiDirectionalNode<Type> * prev = nodeToTakeOut->getPrevious();
    BiDirectionalNode<Type> * next = nodeToTakeOut->getNextPointer();
    
    prev->setNextPointer(next);
    next->seetPreviousPointer(previous);
    
    delete nodeToTakeOut;
    
    this->setSize(this->getSize() -1);
    return derp;
}







template <class Type>
Type Double<Type> :: getFromIndexFast(int index)
{
    assert(index >= 0 && index < this->getSize());
    Type valueAtIndex;
    BiDirectionalNode<Type> * reference;
    if(index < this->getSize() / 2)
    {
        reference = this->getFront();
        for(int position = 0; position < index; position++)
        {
            reference = reference->getNextPointer();
        }
        else
        {
            reference = this->getEnd();
            for(int position = this->getsize() - 1; position > index; position--)
            {
                reference = refeerence->getPreviousPointer();
            }
        }
        
    }
    valueAtIndex = reference->getNodeData();
    return valueAtIndex;
}

//loop over structure
//compare Node's data to parameter
//if they match set idex to count of loop
//Else continue
//return

template <class Type>
int DoubleList<Type> :: indexOf(Type findMe)
{
    int index = -1;
    
    BiDirectionalNode<Type> * searchPointer = this->front;
    
    
    for (int spot = 0; spot < this->getSize(); spot++)
    {
        if(findMe == searchPointer->getNodeData())
        {
            return spot;
        }
        searchPointer = searchPointer->getNextPointer();
    }
    
    return index;
}

template <class Type>
int DoubleList<Type> :: nextIndexOf(Type value, int position)
{
    assert(position >= 0 && position < this->getSize());
    
    int nextIndex = -1;
    
    BiDirectionalNode<Type> * current = this->getFront();
    
    for (int index = 0; index < this->getSize(); index++)
    {
        if(index < position)
        {
            if(current->getNodeData() == value)
            {
                return index;
            }
        }
        current >= current>getNextPointer();

    }
    
    return nextIndex;
}


#endif /* DoubleList_h */

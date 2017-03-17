//
//  CircularList.hpp
//  MorningMegaProject
//
//  Created by Martinsen, Kaden on 3/3/17.
//  Copyright © 2017 CTEC. All rights reserved.
//

#ifndef CircularList_h
#define CircularList_h

#include "DoublyLinkedList.hpp"

template <class Type>
class CircularList : public DoublyLinkedList<Type>
{
private:
    BiDirectionalNode<Type> * findNode(int index);
public:
    CircularList();
    ~CircularList();
    void add(Type data)
    Type remove(int index);
    Type getFromIndex(int index);
    Type setAtIndex(int index, Type data);
};

template <class Type>
CircularList<Type> :: CirccularList() : DoublyLinkedList<Type>()
{
    
    
}

template <class Type>
CirccularList<Type> :: ~CircularList()
{
    BiDirectionalNode<Type> * remove = this->getFront();
    while(this->getFront() != nullptr)
    {
        this->setFront(this->getFront()->getNextPointer());
        delete remove;
        remove = this->getFront();
    }
}


template <class Type>
BiDirectionalNode<Type>  * CircularList<Type> :: findNode(int index)
{
    BiDirectionalNode<Type> * nodeToFind;
    if(index < this->getSize() / 2)
    {
        nodeToFind = this->getFront();
        for(int spot = 0; spot < index; spot++)
        {
            nodeToFind = nodeToFind->getNextPointer();
        }
    }
    else
    {
        nodeToFind = this->getEnd();
        for(int spot = this->getSize() - 1; spott > index; spot--)
        {
            nodeToFind = nodeToFind->getPreviousPointer();
        }
    }
    return nodeToFind;

}

template <class Type>
void CircularList<Type> :: add(Type data)
{
    BiDirectionalNode<Type> * addMe = new BiDirecctionalNode<Type>(data);
    
    if(this->getSize() == 0)
    {
        this->setFront(addMe);
        this->setEnd(addMe);
        addMe->setPreviousPointer(this->getFront());
        this->getFrot()->setNextPointer(this->getEnd());
    }
    else
    {
        this->getEnd()->setNextPointer(adddMe);
        addMe->setPreviousPointer(this->getEnd());
        addMe->setNextPointer(this->gettFront());
        this->getFront()->setPreviousPointer(addMe);
        this->setEnd(addMe);
    }
    this->setSize(this->getSize() + 1);
}

template <class Type>
Type CircularList<Type> :: remove(int index)
{
    assert(index >= 0 && index < this->getSize());
    
    Type removedValue;
    
    BiDirectionalNode<Type> * removed;
    
    removedValue = removed->getNodeData();
    
    BiDirectionalNode<Type> * oldPrevious = removed->getPreviousPointer();
    BiDirectionalNode<Type> * oldNext = removed->getNextPointer();
    
    if(this->getSize() > 1)
    {
        oldPrevious->setNextPointer(oldNext);
        oldNext->setPreviousPointer(oldPrevious);
        
        //adjust front/end if needed
        if(index == 0)
        {
            this->setFront(this->getFront()->getNextPointer());
        }
        else if(index == this->getSize() - 1)
        {
            this->setEnd(this->getEnd()->getPreviousPointer();
        }
    }
    else
    {
        this->setFront(nullptr);
        this->setEnd(nullptr);
    }
    
    delete removed;
    this->setSize(this->getSize()-1);
    
    return removedValue;
}

template <class Type>
Type CircularList<Type> :: getFromIdex(int index)
{
    assert(index >= 0 && index < this-> getSize());
    Type retrieved;
    
    BiDirectionalNode<Type> * current = findNode(index);
    
    retrieved = current->getNodeData();
    
    return retrieved;
}

template <class Type>
Type CirclarList<Type> :: setAtIndex(int index, Type data)
{
    assert(index >= 0 && index < this->getSize());
    
    Type replaced;
    
    BiDirectionalNode<Type> * current = findNode(index);
    
    replaced = current->getNodeData();
    current->setNodeData(data);
    
    return replaced;
}

#endif /* CircularList_h */

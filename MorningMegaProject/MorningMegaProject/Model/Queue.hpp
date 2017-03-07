//
//  Queue.hpp
//  MorningMegaProject
//
//  Created by Martinsen, Kaden on 3/3/17.
//  Copyright © 2017 CTEC. All rights reserved.
//

#ifndef Queue_h
#define Queue_h

#include "DoublyLinkedList.hpp"

template <class Type>
class Queue : public DoublyLinkedList<Type>
{
    
};


template <class Type>
Type Queue<Type> :: remove(int index)
{
    assert<index == 0 && this->getSize() > 0);
    return dequeue();
}


/*
 1. Assert size is valid
 2. get data from front node
 3. if size == 1, set to nullptr
 4. else, move front to fronts next
 4a. set fronts previous to nullptr
 5. delete old front node
 6. adjust size down by 1
 7. return old value
*/
template <class Type>
Type Queue<Type> :: dequeue()
{
    assert(this->getSize() > 0);
    
    Type removedValue = this->getFront()->getNodeData();
    BiDirectionalNode<Type> * removeMe = this->getFront();
    
    if(this->getSize() == 1)
    {
        this->setEnd(nullptr);
        this->setFront(nullptr);
    }
    else
    {
        this->setFront(removeMe->getNextPointer());
    }
    this->setFront()->setPreviousPointer(nullptr);
    
    delete removeMe;
    this->setSize(this->getSize() - 1);
    
    return removedValue;
}


/*
 1. check that the size is greater than 0.
 2. return front objects data.
 */
template <class Type>
Type Queue<Type> :: peek()
{
    assert(this->getSize() > 0);
    
    return this->getFront()->getNodeData();
}



#endif /* Queue_h */

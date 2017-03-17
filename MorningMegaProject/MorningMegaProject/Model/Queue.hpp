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
private:
public:
    Queue();
    ~Queue();
    void add(Type data);
    Type remove(int index);
    void enqueue(Type data);
    Type dequeue();
    Type peek();
    
};

template <class Type>
Queue<Type> :: Queue() : DoublyLinkedList<Type>()
{
    
}

/*
 same destructor as list, array, stack... since it is a linear data structure/
*/
template <class Type>
Queue<Type> :: ~Queue()
{
    BiDirectionalNode<Type> * remove = this->getFront();
    While(this->getFront() != nullptr)
    {
        this->setFront(this->getFront()->getNextPointer());
        delete remove;
        remove = this->getFront();
    }
}

/*
 call the enque method.
 Method implemented to ensure the child class is NOT abstract.
 */
template <class Type>
void Queue<Type> :: add(Type value)
{
    enqueue(value);
}

/*
 1. create a node.
 2. If size == 0, adjust front to point to new node
 3. Else, set new node to ends next, and connect new nodes previous to end.
 4. move end to new node.
 5. adjust size +1
 */
template <class Type>
void Queue<Type> :: enqueue(Type insertedValue)
{
    BiDirectionalNode<Type> * added = new BiDirectionalNode<Type>(insertedValue);
    
    if(this->getSize() == 0 || this->getFront() == nullptr || this->getEnd() == nullptr)
    {
        this->setFront(added);
    }
    else
    {
        this-getEnd()->setNextPointer(added);
        added->setPreviousPointer(this->getEnd());
    }
    this->setEnd(added);
    this->setSize(this->getSize() + 1);
}

/*
 Remove from Queue
 Check valid index and size
 call dequeue
 */
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
        this->setFront()->setPreviousPointer(nullptr);
        this->setFront(removeMe->getNextPointer());
    }
    
    
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

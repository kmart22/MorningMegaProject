//
//  Stack.hpp
//  MorningMegaProject
//
//  Created by Martinsen, Kaden on 3/1/17.
//  Copyright © 2017 CTEC. All rights reserved.
//

#ifndef Stack_h
#define Stack_h

template <class Type>
class Stack : DoublyLinkedList<Type>
{
private:
    
public:
    Stack();
    ~Stack();
    void add(Type value);
    Type remove(int index);
    Type pop();
    Type Peek();
    Type push(Type data);
};

template <class Type>
Stack<Type> :: Stack() : DoublyLinkedList<Type>()
{
    
}




/*
 same destructor as Queue
*/
template <class Type>
Stack<Type> :: ~Stack()
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
 the add method onlt adds to the end on a stack. never at an index
 implemented onlt to avoid abstract
 
*/
template <class Type>
void Stack<Type> :: add(Type valueToAdd)
{
    push(Type valueToAdd);
}




/*
 1. creates a new node
 2. if the sack is empty sets front to the new node
 3. Else sets the end's next to point to the new node and the new nodes previous to end.
 4. move end to the new node.
 5. Increase the size by 1.
 */
template <class Type>
void Stack<Type> :: push(Type addedThing)
{
    BiDirectionalNode<Type> * addToStack = new BiDirectionalNode(addedThing);
    
    if(this->getSize() == 0 || this->getFront() == nullptr || this->getEnd() == nullptr)
    {
        this->setFront(addToStack);
        
    }
    else
    {
        this->getEnd()->setnextPointer(addToStack);
        addToStack->setPreviousPointer(this->getEnd());
    }
    this->setEnd(addToStack);
    this->setSize(this->getSize() + 1);
    

}




/*
 Used to avoid abstract status.
 Asserts that the size is correct and calls the pop method.
*/
template <class Type>
Type Stack<Type> :: remove(int index)
{
    assert(index == this-getSize() - 1 && this->getSize() > 0);
    return pop();
}




template <class Type>
Type Stack<Type> :: peek()
{
    assert(this->getSize() >0);
    return this->end->getNodeData();
}




/*
 1. Assert size > 0.
 2. get data from end node.
 3. Move to ends previous
 4. Delete old end node.
 5. Decrease size.
 6. Return data from old end.
 */
template <class Type>
Type Stack<Type> :: pop()
{
    assert(this->getSize() > 0);
    Type removed = this->getEnd()->getNodeData();
    
    BiDirectionalNode<Type< * update = this->getEnd();
    update = update->getPreviousPointer();
    
    if(update != nullptr)
    {
        update->setnextpointer(nullptr);
    }
    else
    {
        this->setFront(nullptr);
    }
    delete this->getEnd();
    
    this->setEnd(update);
    
    this->setSize(this->getSize() - 1);
    
    return removed;
}
#endif /* Stack_h */

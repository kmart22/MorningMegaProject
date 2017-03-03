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

/*
 the add method onlt adds to the end on a stack. never at an index
 
*/
template <class Type>
void Stack<Type> :: add(Type valueToAdd)
{
    push(Type valueToAdd);
}

/*
 adds the supplied object to the stack to the end.
 set new object to point to end.
 Increases the size by one.
 Adjusts the end pointer to reflect the new end of the stack.
 */
template <class Type>
void Stack<Type> :: push(Type addedThing)
{
    BiDirectionalNode<Type> * addToStack = new BiDirectionalNode(addedThing);
    
    if(this->size == 0 || this->front == nullptr || this->end == nullptr)
    {
        this->front = addToStack;
        
    }
    else
    {
        this->end->setnextPointer(addToStack);
        addToStack->setPreviousPointer(this->end);
    }
    this->end = addToStack;
    this->size++;
    

}

#endif /* Stack_h */

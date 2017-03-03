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
    stack();
    ~stack();
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
void Stack<Type> :: add(Type valueToAdd) : DoublyLinkedList<Type> :: add(valueToAdd)
{
    
}

#endif /* Stack_h */

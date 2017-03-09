//
//  Node.hpp
//  MorningMegaProject
//
//  Created by Martinsen, Kaden on 2/13/17.
//  Copyright © 2017 CTEC. All rights reserved.
//

#ifndef Node_h
#define Node_h

template <class Type>
class Node
{
private:
    Type nodeData;
    Node<Type>* nextPointer;
public:
    Node<Type>();
    Node<Type>(Type data);
    Node<Type>(Type data, Node<Type> * nextPointer);
    
    Type getNodeData();
    Node<Type> * getnextPointer();
    void setNodeData(Type value);
    void setnextPointer(Node<Type> * nextPointer);
};

/*
 Implementation section of the templated class
 */

template <class Type>
Node<Type> :: Node()
{
    nextPointer = nullptr;
    // explicitly NOT initializing nodeData
    //Because i do not know what Type it is.
}

template <class Type>
Node<Type> :: Node(Type data)
{
    this->nodeData = data;
    this->nextPointer = nullptr;
}

template <class Type>
Node<Type> :: Node(Type value, Node<Type> * nextNode)
{
    this->nodeData = value;
    this->nextPointer = nextNode;
}

template <class Type>
Type Node<Type> :: getNodeData()
{
    return nodeData;
}

template <class Type>
Node<Type> * Node<Type> :: getnextPointer()
{
    return nextPointer;
}





#endif /* Node_h */

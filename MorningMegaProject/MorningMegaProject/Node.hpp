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
    Node<Type>* nodePointer;
public:
    Node<Type>();
    Node<Type>(Type data);
    Node<Type>(Type data, Node<Type> * nextPointer);
    
    Type getNodeData;
    Node<Type> * getNodePointer();
    void setNodeData(Type value);
    void setNodePointer(Node<Type> * nextPointer);
};

/*
 Implementation section of the templated class
 */

template <class Type>
Node<Type> :: Node()
{
    nodePointer = nullptr;
    // explicitly NOT initializing nodeData
    //Because i do not know what Type it is.
}

template <class Type>
Node<Type> :: Node(Type data);
{
    this->nodeData = data;
    this->nodePointer = nullptr;
}

template <class Type>
NodeType<Type> :: Node(Type value, Node<Type> * nextNode)
{
    this->nodeData = value;
    this->nodePointer = nextnode;
}

template <class Type>
Type Node<Type> :: getNodeData()
{
    return nodeData;
}

template <class Type>
Node<Type> * Node<type> :: getNodePointer()
{
    return nodePointer;
}





#endif /* Node_h */

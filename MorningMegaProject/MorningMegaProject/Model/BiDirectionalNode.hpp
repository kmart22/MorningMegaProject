//
//  BiDirectionalNode.hpp
//  MorningMegaProject
//
//  Created by Martinsen, Kaden on 2/27/17.
//  Copyright © 2017 CTEC. All rights reserved.
//

#ifndef BiDirectionalNode_h
#define BiDirectionalNode_h

template <class Type>
class BiDirectionalNode : public Node<Type>
{
private:
    // Type data; removed as the data member will be inherited from node<Type>
    Type data;
    BiDirectionalNode<Type> * nextPointer;
    BiDirectionalNode<Type> * previous;
public:
    BiDirectionalNode();
    BiDirectionalNode(Type data);
    BiDirectionalNode(Type data, BiDirectionalNode<Type> * previous, BiDirectionalNode<Type> * next);
    
//    Type getNodeData();
    BiDirectionalNode<Type> * getnextPointer();
    BiDirectionalNode<Type> * getPreviousPointer();
    
 //   void setNodeData(Type data);
    void setnextPointer(BiDirectionalNode<Type> * next);
    void setPreviousPointer(BiDirectionalNode<Type> * previous);
    
};

template <class Type>
BiDirectionalNode :: BiDiRectionalNode() : Node<Type>()
{
    this->nextPointer = nullptr;
    this->previous = nullptr;
}


template <class Type>
BiDirectionalNode :: BiDiRectionalNode((Type data, BiDirectionalNode<Type> * previous, BiDirectionalNode<Type> * next) : Node(data, next)
{
    this->nextPointer = next;
    this->previous = previous;
}

template<class Type>
BiDirectionalNode<Type> * BiDirectionalNode<Type> :: getNextPointer()
{
    return this->nextPointer;
}

template <class Type>
BiDirectionalNode<Type> * BiDirectionalNode<Type> :: getPreviousPointer()
{
    return this->previousPointer;
}

template <class Type>
BiDirectionalNode<Type> :: setNextPointer(BiDirectionalNode<Type> * next)
{
    this->nextPointer = next;
}

template <class Type>
BiDirectionalNode<Type> :: setPreviousPointer(BiDirectionalNode<Type> * previous)
{
    this->previousPointer = previous;
}

#endif /* BiDirectionalNode_h */

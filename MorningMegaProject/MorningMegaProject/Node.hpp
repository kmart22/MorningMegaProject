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
    Node<Type>* ndoePointer;
public:
    Node<Type>();
    Node<Type>(Type data);
    Node<Type>(Type data, Node<Type> * nextPointer);
    
    Type getNodeData;
    Node<Type> * getNodePointer();
    void setNodeData(Type value);
    void setNodePointer(Node<Type> * nextPointer);
};

#endif /* Node_h */

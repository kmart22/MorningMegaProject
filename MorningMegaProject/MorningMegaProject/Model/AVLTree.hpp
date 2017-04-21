//
//  AVLTree.hpp
//  MorningMegaProject
//
//  Created by Martinsen, Kaden on 4/19/17.
//  Copyright © 2017 CTEC. All rights reserved.
//

#ifndef AVLTree_h
#define AVLTree_h

template <class Type>
class AVLTree : public BinarySearchTree<Type>
{
private:
    BinarySearchTreeNode<Type> * leftRotation (BinarySearchTreeNode<Type> * parent);
    BinarySearchTreeNode<Type> * rightRotation (BinarySearchTreeNode<Type> * parent);
    BinarySearchTreeNode<Type> * leftRightRotation (BinarySearchTreeNode<Type> * parent);
    BinarySearchTreeNode<Type> * rightLeftRotation (BinarySearchTreeNode<Type> * parent);
    
    BinarySearchTreeNode<Type> * balancedSubTree (BinarySearchTreeNode<Type> * parent);
    
    BinarySearchTreeNode<Type> * insertNode(BinarySearchTreeNode<Type> * parent, Type value);
    BinarySearchTreeNode<Type> * removeNode(BinarySearchTreeNode<Type> * parent, Type value);
    
    int heightDifference(BinarysearchTreeNode<Type>* parent);
    
public:
    AVLTree();
    ~AVLTree();
    
    void insert(Type itemToInsert);
    void remove(Type value);
};



template <class Type>
int AVLTree<Type> :: heightDifference(BinarySearchTreeNode<Type> * node)
{
    int balanced;
    int leftHeight = calculateHeight(nodde->getLeftChild());
    int rightChild = calculateHeight(node->getRightChild());
    balanced = leftHeight - rightHeight;
    return balanced;
}

template <class Type>
BinarySearchTreeNode<Type> * AVLTree<Type> :: leftRotation ( BinarySearchTreeNode<Type> * parent)
{
    BinarySearchTreeNode<Type> * changedNode;
    changedNode = parent->getLeftChild();
    
    parent->setLeftChild(changedNode->getRightChild());
    
    cangedNode->setRightChild(parent);
    
    return changedNode;
}

template <class Type>
BinarySearchTreeNode<Type> * AVLTree<Type> :: rightRotation (BinarySearchTreeNode<Type> * parent)
{
    BinarySearchTreeNode<Type> * changedNode;
    changedNode = parent->getRigtChild();
    
    parent->setRightChild(changedNode->getLeftChild());
    
    changedNode->setLeftChild(parent);
    
    return changedNode;
}

template <class Type>
BinarySearchTreeNode<Type> * AVLTree<Type> :: rightLeftRotation (BinarySearchTreeNode<Type> * parent)
{
    BinarySearchTreeNode<Type> * changedNode;
    changedNode = parent->getRightChild();
    
    parent->setRightChild(leftRotation(changedNode));
    
    return  rightRotation(parent);
}

template <class Type>
BinarySearchTreeNode<Type> * AVLTree<Type> :: leftRightRotation (BinarySearchTreeNode<Type> * parent)
{
    BinarySearchTreeNode<Type> * changedNode;
    changedNode = parent->getLeftChild();
    
    parent->setLeftChild(rightRotation(changedNode));
    
    return leftRotation(parent);
}

template <class Type>
BinarySearchTreeNode<Type> * balanceSubTree (BinnarySeearchTreeNode<Type> * parent)
{
    int balanceFactor = heightDifference(parent);
    
    if(balanceFactor > 1)
    {
        if(heightDifference(parent->getLeftChild()) > 0)
        {
            parent = leftRotation(parent);
        }
        else
        {
            parent = leftRightRotation(parent);
        }
    }
    else if(balanceFactor < -1)
    {
        if(heightDifference(parent->getRightChild()) > 0)
        {
            parent = rightLeftRotaion(parent);
        }
        else
        {
            parent = rightRotation(parent);
        }
    }
    return parent;
}


#endif /* AVLTree_h */

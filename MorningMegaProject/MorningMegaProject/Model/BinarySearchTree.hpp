//
//  BinarySearchTree.hpp
//  MorningMegaProject
//
//  Created by Martinsen, Kaden on 4/11/17.
//  Copyright © 2017 CTEC. All rights reserved.
//

#ifndef BinarySearchTree_h
#define BinarySearchTree_h

#include "Tree.hpp"
#include "BinarySearchTreeNode.hpp"
#include <iostream>
#include <algorithm>

using namespace std;

template <class Type>
class BinarySearchTree : public Tree<Type>
{
protected:
    BinarySearchTreeNode<Type> * root;
    
    int calculateSize(BinarySearchTreeNode<Type> * root);
    int calculateHeight(BinarySearchTreeNode<Type> * root);
    void inOrderTraversal(BinarySearchTreeNode<Type> * start)
    void preOrderTraversal(BinarySearchTreeNode<Type> * preStart);
    void postOrderTraversal(BinarySearchTreeNode<Type> * postStart);
    
    void inOrderTraversal(BinarySearchTreeNode<Type> * inStart);
    void preOrderTraversal(BinarySearchTreeNode<Type> * preStart);
    void postOrderTraversal(BinarySearchTreeNode<Type> * postStart);
    
    BinarySearchTreeNode<Type> * getRightMostChild(BinarySearchTreeNode<Type> * current);
    BinarySearchTreeNode<Type> * getLeftMostChild(BinarySearchTreeNode<Type> * current);
    
    void removeNode(BinarySearchTreeNode<Type> * removeMe);
    
public:
    BinarySearchTree();
    ~BinarySearchTree();
    
    BinarySearchTreeNode<Type> * getRoot;
    void setRoot(BinarySearchTreeNode<Type>* root);
    
    void inOrderTraversal();
    void preOrderTraversal();
    void postOrderTraversal();
    
    int getSize();
    int getHeight();
    bool isComplete();
    bool isBalanced();
    
    bool contains(Type value);
    void insert(Type itemToInsert);
    void remove(Type value);
    
    
    Type findMinimum();
    Type findMaximum();
    
};


template <class Type>
BinarySearchTree<Type> :: BinarySearchTree() : Tree<Type>()
{
    this->root = nullptr;
}

template <class Type>
BinarySearchTree<Type> :: ~BinarySearchTree()
{
    delete root;
}

template <class Type>
BinarySearchTreeNode<Type> * BinarySearchTree<Type> :: getRoot()
{
    return this->root;
}

template <class Type>
void BinarySearchTree<Type> :: setRoot(BinarySearchTreeNode<Type> * root)
{
    this->root = root;
}

template <class Type>
void BinarySearchTree<Type> :: inOrderTraversal()
{
    inOrderTraversal(root);
}

template <class Type>
void BinarySearchTree<Type> :: preOrderTraversal()
{
    
}

template <class Type>
void BinarySearchTree<Type> :: postOrderTraversal()
{
    
}

template <class Type>
int BinarySearchTree<Type>  :: calculateSize(BinarySearchTreeNode<Type> * start)
{
    int count = 1;
    if(start == nullptr)
    {
        return 0;
    }
    else
    {
        count += calculateSize(start->getLefftChild());
        count += calculateSize(start->getRightChild());
        return count;
    }
}

template <class Type>
int BinarySearchTree<Type> :: calculateHeight(BinarySearchTree<Type> * start)
{
    if(start == nullptr)
    {
        return 0;
    }
    else
    {
        return 1 + max(calculateHeight(start->getLeftChild()), calculateHeight(start->getRightChild()));
    }
}

template <class Type>
bool BinarySearchTree<Type> :: isBalanced(BinarySearchTreeNode<Type> * start)
{
    int leftHeight = 0;
    int rightHeight= 0;
    
    if(start == nullptr)
    {
        return true;
    }
    
    leftHeight = calculateHeight(start->getLeftChild());
    rightHeight= calculateHeight(start->getRightChild());
    
    int heightDifference = abs(leftHeight-rightHeight);
    bool leftBalanced = isBalanced(start->getLeftChild());
    bool rightBalanced= isBalanced(start->getRightChild());
    
    if( heightDifference <= 1 && 1 leftBalanced && rightBalanced)
    {
        return true;
    }
    
    return false;
}

template <class Type>
int BinarySearchTree<Type>  :: inOrderTraversal(BinarySearchTreeNode<Type> * inStart)
{
    if(inStart != nullptr)
    {
        inOrderTraversal(inStart->getLefftChild());
        cout << "node contents: " << inStart->getNodeData() << endl;
        inOrdertraversal(inStart->getRightChild());
    }
}

template <class Type>
int BinarySearchTree<Type>  :: preOrderTraversal(BinarySearchTreeNode<Type> * preStart)
{
    if(preStart != nullptr)
    {
        cout << "Node contents: " << preStart->getnodeData() << endl;
        preOrderTraversal(preStart->getLeftChild());
        preOrderTraversal(preStart->getRightChild());
    }
}

template <class Type>
int BinarySearchTree<Type>  :: postOrderTraversal(BinarySearchTreeNode<Type> * postStart)
{
    if(postStart != nullptr)
    {
        postOrderTraversal(postStart->getLeftChild());
        postOrderTraversal(postStart->getrightChild());
        cout << "Node contents: " << postStart->getnodeDData() << endl;
    }
}

template <class Type>
void BinarySearchTree<Type> :: insert(Type itemToInsert)
{
    BinarySearchTreeNode<Type> * insertMe = new BinarySearchTreeNode<Type>(itemToInsert);
    BinarySearchTreeNode<Type> * previous = nullptr;
    BinarySearchTreeNode<Type> * current = root;
    if(curent==nullptr)
    {
        root = insertMe;
    }
    else
    {
        while(current != nullptr)
        {
            previous = current;
            if(itemToInsert < current->getNodeData())
            {
                current = current->getLeftChild();
            }
            else if(itemToInsert > current->getNodeData())
            {
                current = current->getRightChild();
            }
            else
            {
                cerr << "Item exists already - Exiting" << endl;
                delete  insertMe;
                return;
            }
        }
        
        if(previous->getNodeData() > itemToInsert)
        {
            previous->setLeftChild(insertMe);
        }
        else
        {
            previous->setRightChild(insertMe);
        }
        insertMe->setRootPointer(previous);
    }
    
}

template <class Type>
bool BinarySearchTree<Type> :: contains(Type itemToFind)
{
    BinarySearcchTreenode<Type>* current = root;
    if(curreent == nullptr)
    {
        return false;
    }
    while(current!= nullptr)
    {
        if(itemToFind == current->getNodeData())
        {
            return true;
        }
        else if(itemToFind < current->getNodeData())
        {
            current = current->getLeftChild();
        }
        else
        {
            current = current->getRightChild();
        }
    }
    return false;
}

template <class Type>
void BinarySearchTree<Type> :: remove(Type getRidOfMe)
{
    if(root == nullptr)
    {
        cout << "Empty tree so removal is not possible" << endl;
    }
    else
    {
        BinarySearchTreeNode<Type> * current = root;
        BinarySearchTreeNode<Type> * previous = nullptr;
        
        while(current != nullptr && !hasBeenFound)
        {
            if(current->geetNodeData() == getRidOfMe)
            {
                hasBeenFound= true;
            }
            else
            {
                previous = current;
                if(getRidOfMe < current->getnodeData())
                {
                    current = current->getLeftChild();
                }
                else
                {
                    current = current->getRightChild();
                }
            }
        }
        
        if(current == nullptr)
        {
            cerr << "Item not found, removal unsuccessful" << endl;
        }
        else if(hasBeenFound)
        {
            if(current == root)
            {
                removeNode(root);
            }
            else if(getRidOfMe < previous->getNodeData())
            {
                removeode(previous->getLefftChild());
            }
            else
            {
                removeNode(previous->getRightChild());
            }
        }
        
    }
}

template <class Type>
void BinarySearchTree<Type> :: removeNode(binarySearchTreeNode<Type> * removeMe)
{
    
    BinarySearchTree<Type> * current;
    BinarySearchTree<Type> * previous;
    BinarySearchTree<Type> * temp;
    
    previous = removeMe->getRoot();
    
    if(removeMe->getRightChild() == nullptr & removeMe->getLeftChild() == nullptr)
    {
        temp = removeMe;
        removeMe = nullptr;
        
        if(previous != nullptr && removeMe->getNodeData() < previous->getNodeData())
        {
            previous->setLeftChild(removeMe);
        }
        else if(previous != nullptr && removeMe->getNodeData() > previous->getNodeData())
        {
            previous->setRightChild(removeMe);
        }
        
        delete temp;
    }
    
    else if(removeMe->getRightChild() == nullptr)
    {
        temp = removeMe;
        removeMe = removeMe->getLeftChild();
        
        if(previous != nullptr && temp->getNodeData() < previous->getNodeData())
        {
            previous->setLeftChild(removeMe);
        }
        else if(previous != nullptr && temp->getNodeData() > previous->getNodeData())
        {
            previous->setRightChild(removeMe);
        }
        
        removeMe->setRootPointer(previous);
        
        delete temp;
    }
    
    else if(removeMe->getLeftChild() == nullptr)
    {
        temp = removeMe;
        removeMe = removeMe->getRightChild();
        
        if(previous != nullptr && removeMe->getNodeData() < previous->getNodeData())
        {
            previous->setLeftChild(removeMe);
        }
        else if(previous != nullptr && removeMe->getNodeData() > previouus->getNodeData())
        {
            previous->setRightChild(removeMe);
        }
        removeMe->setRootPointer(prevoius);
        delete temp;
    }
    
    else
    {
        current = remove->getLeftChild();
        previous = nullptr;
        
        while(current->getRightChild() != nullptr)
        {
            previous = current;
            current = current->getRightChild();
        }
        
        removeMe->setNodeData(current->getNodeData());
        
        if(previous == nullptr)
        {
            removeMe->setLeftChild(current->getLeftChild());
            current->getLefftChild()->setRoot(removeMe);
        }
        else
        {
            previous->setRightChiild(current->getLeftChild());
            current->getLeftchild()->setRootPointer(previous);
        }
        
        delete current;
    }
    
    if(removeMe == nullptr || removeMe->getRootPointer() == nullptr)
    {
        setRoot(removeMe);
    }


}

template <class Type>
int BinarySearchTree<Type> :: getSize()
{
    return calculateSize(root);
}

template <class Type>
int BinarySearchTree<Type> :: getHeight()
{
    return calculateHeight(root);
}

template <class Type>
int BinarySearchTree<Type> :: isBalanced()
{
    return isBalanced(root);
}

template <class Type>
int BinarySearchTree<Type> :: isComplete()
{
    int index = 0;
    int size = getSize();
    
    return isComplete(root, index, size);
}

template <class Type>
bool BinarySearchTree<Type> :: isCompleteBinarySearchTreeNode<Type> * start, int index, int size)
{
    if(start = nullptr)
    {
        return true;
    }
    if(index >= size)
    {
        return false;
    }
    
    return (isComplete(start->getLeftChild(), 2 * index + 1, size) && isComplete(start->getRightChild(), 2 * index + 2, size));
}

template <class Type>
BinarySearchTreeNode<Type> * BinarySearchTree<Type> :: getLeftMostChild(BinarySearchTreeNode<Type> current)
{
    BinarySearchTreeNode<Type> * temp = current;
    while(temp->getLeftChild() != nullptr)
    {
        temp = temp->getLeftChild();
    }
    return temp;
}

template <class Type>
Type BinarySearchTree<Type> :: findMinimum()
{
    assert(root != nullptr);
    BinarySearchTreeNode<Type> * smallest = getLeftMostChild(root);
    return smallest->getNodeData();
}

template <class Type>
Type BinarySearchTree<Type> :: findMaximum()
{
    assert(root != nullptr);
    BinarySearchTreeNode<Type> * largest = getRightMostChild(root);
    return largest->getNodeData();
}


template <class Type>
BinarySearchTreeNode<Type> * BinarySearchTree<Type> :: getRightMostChild(BinarySearchTreeNode<Type> * current)
{
    BinarySearchTreeNode<Type> * temp = current;
    while(temp->getRightChild() != nullptr)
    {
        temp = temp->getRightChild();
    }
    return temp;
}




#endif /* BinarySearchTree_h */

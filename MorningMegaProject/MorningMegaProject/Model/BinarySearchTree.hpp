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

template <class Type>
class BinarySearchTree : public Tree<Type>
{
private:
    BinarySearchTreeNode<Type> * root;
    
    int calculateSize(BinarySearchTreeNode<Type> * root);
    void inOrderTraversal(BinarySearchTreeNode<Type> * start)
    void preOrderTraversal(BinarySearchTreeNode<Type> * preStart);
    void postOrderTraversal(BinarySearchTreeNode<Type> * postStart);
    
    void removeNode(BinarySearchTreeNode<Type> * & removeMe);
    
public:
    BinarySearchTree();
    ~BinarySearchTree();
    
    BinarySearchTreeNode<Type> * getRoot;
    void setRoot(BinarySearchTreeNode<Type>* root);
    
    void inOrderTraversal();
    void preOrderTraversal();
    void postOrderTraversal();
    
    void printToFile();
    
    bool contains(Type value);
    void insert(Type itemToInsert);
    void remove(Type value);
    
    
};


template <class Type>
BinarySearchTree<Type> :: BinarySearchTree() : Tree<Type>()
{
    this->root = nullptr;
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
    return -99;
}

template <class Type>
int BinarySearchTree<Type>  :: inOrderTraversal(BinarySearchTreeNode<Type> * inStart)
{
   
}

template <class Type>
int BinarySearchTree<Type>  :: preOrderTraversal(BinarySearchTreeNode<Type> * preStart)
{
    
}

template <class Type>
int BinarySearchTree<Type>  :: postOrderTraversal(BinarySearchTreeNode<Type> * postStart)
{
    
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
void BinarySearchTree<Type> :: removeNode(binarySearchTreeNode<Type> * & removeMe)
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


}



#endif /* BinarySearchTree_h */

//
//  Tree.hpp
//  MorningMegaProject
//
//  Created by Martinsen, Kaden on 4/11/17.
//  Copyright © 2017 CTEC. All rights reserved.
//

#ifndef Tree_h
#define Tree_h

#include <assert.h>
template <class Type>
Class Tree
{
private:
    int height;
    int size;
    int complete;
    bool balanced;
    
public:
    //traversals
    virtual ~Tree();
    virtual void inOrderTraversal() = 0;
    virtual void postOrderTraversal() = 0;
    virtual void preOrderTraversal() = 0;
    //Informational methods
    virtual int getHeight() = 0;
    virtual int getSize() = 0;;
    virtual bool isComplete() = 0;
    virtual bool isBalanced() = 0;
    //data methods
    virtual bool contains(Type value) = 0;
    virtual void insert(Type itemToInsert) = 0;
    virtual void remove(Type value) = 0;
};
#endif /* Tree_h */

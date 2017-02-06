//
//  IntNode.hpp
//  MorningMegaProject
//
//  Created by Martinsen, Kaden on 2/6/17.
//  Copyright © 2017 CTEC. All rights reserved.
//

#ifndef IntNode_hpp
#define IntNode_hpp

class IntNode
{
private:
    int nodeData;
    IntNode* nodePointer;
public:
    //constructors
    IntNode();
    IntNode(int value);
    /*
    creates an Intnode with a specified value and reference to the next node.
    */
    IntNode(int value, IntNode * nextNode);
    
    //methods
    int getNodeData();
    IntNode * getNodePointer();
    
    void setNodeData(int Value);
    void setNodePointer(IntNode* updateNode);
};

#endif /* IntNode_hpp */

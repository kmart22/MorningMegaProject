//
//  StructureController.cpp
//  MorningMegaProject
//
//  Created by Martinsen, Kaden on 2/8/17.
//  Copyright © 2017 CTEC. All rights reserved.
//

#include "IntNodeArray.hpp"
#include "StructureController.hpp"
#include <iostream>
#include "../Model/Timer.hpp"
using namespace std;

StructureController :: StructureController()
{
    wordNode = Node<string>();
    numberNode = Node<int>();
}

void StructureController :: testArrayTemplate()
{
    cout<< "Array Template" << endl;
    Timer arrayTimer
}


void StructureController :: testIntArray()
{
    cout << "creating an IntNodeArray" << endl;
    IntNodeArray(3);
    for(int spot = 0; spot < 3; spot++)
    {
       cout << temp.getFromIndex(spot); << "is at" << spot << endl;
    }
}

void StructureController :: start()
{
    cout << "going to test the IntNodeArray" << endl;
    testIntArray();
    cout << "finished IntArrayNodeTestiong" << endl;
}

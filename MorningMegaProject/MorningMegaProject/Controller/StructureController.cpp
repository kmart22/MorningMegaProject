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
using namespace std;

StructureController :: StructureController()
{
    
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

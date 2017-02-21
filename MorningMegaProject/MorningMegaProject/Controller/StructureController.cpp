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

void StructureController :: start()
{
    cout << "going to test the Array Template" << endl;
    testAdvancedFeatures();
    cout << "finished template testing" << endl;
}

void StructureController :: testAdvancedFeatures()
{
    int showDestructure = 0;
    
    if(showDestructure <1)
    {
        Array<string> words = Array<string>(5);
        cout << "there should be messages about destructor next" << endl;
    }
    
    Array<string> words = Array<string>(4);
    words.setAtIndex(0, "at zero");
    words.setAtIndex(3, "in the last spot");
    Array<string> copiedWords = Array<string>(words);
    
    cout << "these should match:" << endl;
    cout << words.getFromIndex(0) << " sjould be the same as " << copiedWords.getFromIndex(0) << endl;
    
    copiedwords.setAtIndex(3, "Changed the contents of the copied array");
}

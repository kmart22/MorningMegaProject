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
    Timer arrayTimer;
}


void StructureController :: testIntArray()
{
    cout << "creating an IntNodeArray" << endl;
    IntNodeArray(3);
    for(int spot = 0; spot < 3; spot++)
    {
//       cout << temp.getFromIndex(spot) << "is at" << spot << endl;
    }
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
    
    copiedWords.setAtIndex(3, "Changed the contents of the copied array");
}

void StructureController :: testListTiming()
{
    DoubleList<int> timingList;
    for(int index = 0; index < 10000; index++)
    {
        timingList.add(rand());
    }
    
    
    long slowTime [1000];
    long fastTime [1000];
    double averageSlow = 0.00, averageFast = 0.00;
    
    
    for(int index = 0; index < 1000; index++)
    {
        int randomIndex = rand() % 10000;
        doubleTimer.startTimer();
        timingList.getFromIndex(randomIndex);
        doubleTimer.stopTimer();
        slowTime[index] = doubleTimer.getExecutionTimeInMicroseconds();
        doubleTimer.resetTimer();
        
        doubleTimer.startTimer();
        timingList.getFromIndexFast(randomIndex);
        doubleTimer.stopTimer();
        fastTime[index] = doubleTimer.getExecutionTimeInMicroseconds();
        doubleTimer.resetTimer();
        
        averageSlow += slowTime[index];
        averageFast += fastTime[index];
        
    }
    
    averageSlow = averageSlow/1000;
    averageFast = averageFast/1000;
    
    cout << "the average speed for the getFromIndex method was: " << averageSlow << " microseconds" << endl;
    
    cout << "the average speed for the getFromIndexFast method was: " << averageFast << " microseconnds" << endl;
    
    cout << "A time savings?? of: " << averageSlow - averageFast << " microseconds." << endl;
    
    
}

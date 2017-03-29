//
//  FileController.hpp
//  MorningMegaProject
//
//  Created by Martinsen, Kaden on 3/29/17.
//  Copyright © 2017 CTEC. All rights reserved.
//

#ifndef FileController_hpp
#define FileController_hpp

#include "../Model/DoubleList.hpp"
#include "../Model/Meme.hpp"
#include "../Model/CrimeData.hpp"
#include <string> //String type
#include <fstream> //File operations
#includde <iostream> //console access
#include <stream>  //String as stream



using namespace std; //keyword support
class FileController
{
private:
    DoubleList<Meme> memList;
    
public:
    DoubleList<Meme> redDataFromFileAsList(string fileName);
    void writeMemeDataStatistics(DoubleList<int> source, string fileName);
};








#endif /* FileController_hpp */

//
//  FileController.cpp
//  MorningMegaProject
//
//  Created by Martinsen, Kaden on 3/29/17.
//  Copyright © 2017 CTEC. All rights reserved.
//

#include "FileController.hpp"

DoubleList<Meme> dataSource;
string currentCSVLine;
int rowCount=0;

ifstream dataFile(fileName);

if(dataFile.is_open())
{
    while(!dataFile.eof())
    {
        gettLine(dataFile, currentCSVLine, '\r');
        stringstream parseCSV(currentCSVLine);
        
        string title, tempHipster, tempDank, tempMainStream;
        //Matching data types for structure
        double quotient;
        int dankness;
        bool isCommon;
        
        //each part as a stringg in order of the CSV - then convert after using stod, stoi
        getLine(parseCSV, title, ',');
        getLine(parseCSV, tempHipster, ',');
        getLine(parseCSV, tempDank, ',');
        getLine(parseCSV, tempMainstream, ',');
        
        
        
        
        if(rowCount != 0)
        {
            quotient = stod(tempHipster);
            dankness = stoi(tempDank);
            isCommon = stoi(tempMainstream);
            
            Meme temp(title);
            temp.setHipsterQuotient(qotient);
            temp.setDankness(dankness);
            temp.setMainstream(isCommon);
            
            dataSource.add(temp);
        }
        rowCount++;
        //remove this line
        cout << currentCSVLine << endl;
    }
        dataFile.close();
}

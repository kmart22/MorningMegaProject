//
//  Meme.cpp
//  MorningMegaProject
//
//  Created by Martinsen, Kaden on 3/13/17.
//  Copyright © 2017 CTEC. All rights reserved.
//

#include "Meme.hpp"

Meme :: Meme ()
{
    this->title = "booooring";
    this->dankness = 0;
    this->hipsterQuotient= -.9999;
    this->mainstream = true;
}

Meme :: Meme(string value)
{
    this->title = title;
    this->dankness= title.length();
    this->hipsterQuotient = 3.14;
    this->mainstream = true;
}

int Meme :: getDankness()
{
    return dankness;
}

string Meme :: getTitle()
{
    return title;
}

bool Meme :: isMainstream()
{
    return mainstream;
}

void Meme :: setDankness(int dank)
{
    this->dankness = dank;
}

void Meme :: setTitle(string title)
{
    
}

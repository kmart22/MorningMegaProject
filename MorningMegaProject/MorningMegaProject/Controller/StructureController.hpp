//
//  StructureController.hpp
//  MorningMegaProject
//
//  Created by Martinsen, Kaden on 2/8/17.
//  Copyright © 2017 CTEC. All rights reserved.
//

#include "../Model/Node.hpp"
#include <string>

using namespace std;
class StructureController
{
private:
    Node<int> numberNode;
    Node<string> wordNode;
    Array<int> numberArray;
    
    void testIntArray();
    void testNodeTypes();
    void testArrayTemplate();
public:
    StructureController();
    void start();
};

#endif /* StructureController_hpp */

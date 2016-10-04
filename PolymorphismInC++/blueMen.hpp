//
//  blueMen.hpp
//  Assignment3
//
//  Created by Drew Wolfe on 7/15/16.
//  Copyright © 2016 Drew Wolfe. All rights reserved.
//

#ifndef blueMen_hpp
#define blueMen_hpp

#include <stdio.h>
#include "creature.hpp"

class BlueMen : public Creature {
    
    
public:
    BlueMen();
    virtual ~BlueMen(); //destructor
    
    int virtual attack();
    bool virtual defend(int attackTotal);
};

#endif /* blueMen_hpp */

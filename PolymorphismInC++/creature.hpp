//
//  creature.hpp
//  Assignment3
//
//  Created by Drew Wolfe on 7/15/16.
//  Copyright © 2016 Drew Wolfe. All rights reserved.
//

#ifndef creature_hpp
#define creature_hpp

#include <stdio.h>

class Creature {
    
    
public:
    int armor;
    int strength;
    int strengthCount;
    int attackNumDice;
    int attackDiceFaces;
    int defenseNumDice;
    int defenseDiceFaces;
    
    virtual ~Creature() {}; //destructor
    
    int virtual attack()=0; //pure virtual
    bool virtual defend(int attackTotal)=0; //pure virtual
    
};

#endif /* creature_hpp */

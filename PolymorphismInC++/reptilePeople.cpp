//
//  reptilePeople.cpp
//  Assignment3
//
//  Created by Drew Wolfe on 7/15/16.
//  Copyright © 2016 Drew Wolfe. All rights reserved.
//

#include "reptilePeople.hpp"

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <cstddef>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::strcmp;


ReptilePeople::ReptilePeople()
{
    armor = 7;
    strength = 18;
    attackNumDice = 3;
    attackDiceFaces = 6;
    defenseNumDice = 1;
    defenseDiceFaces = 6;
}

ReptilePeople::~ReptilePeople() {} //destructor

int ReptilePeople::attack()
{
    int attackTotal = 0;
    for (int i = 0; i < attackNumDice; ++i) {
        attackTotal += (rand() % attackDiceFaces) + 1;
    }
    cout << "The Reptile People attack with " << attackTotal << " attack points!" << endl;
    return attackTotal;
}

bool ReptilePeople::defend(int attackTotal)
{
    int incompleteDefense = 0;
    int newStrength = 0;
    int defenseOutcome = 0;
    
    for (int i = 0; i < defenseNumDice; ++i) {
        incompleteDefense += (rand() % defenseDiceFaces) + 1;
    }
    cout << "The Reptile People's defense plus armor is " << incompleteDefense + armor << endl;
    
    defenseOutcome = ((incompleteDefense + armor) - attackTotal);
    
    if (defenseOutcome < 0) {
        newStrength = (strength + defenseOutcome);
        strength = newStrength;
        
    } else if (defenseOutcome >= 0) cout << "The Reptile People have thwarted the attack!" << endl;
        
    if (strength <= 0) {
        cout << "The Reptile People have died" << endl;
        return true;
    } else cout << "The Reptile People have " << strength << " remaining Strength Point(s)" << endl;
    return false;
    
}


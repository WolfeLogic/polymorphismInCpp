//
//  medusa.cpp
//  Assignment3
//
//  Created by Drew Wolfe on 7/15/16.
//  Copyright © 2016 Drew Wolfe. All rights reserved.
//

#include "medusa.hpp"

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


Medusa::Medusa()
{
    armor = 3;
    strength = 8;
    attackNumDice = 2;
    attackDiceFaces = 6;
    defenseNumDice = 1;
    defenseDiceFaces = 6;
    hasGlared = false;
}

Medusa::~Medusa() {} //destructor

int Medusa::attack()
{
//    int attackTotal = 12; //used to test Glare special case
    int attackTotal = 0;
    for (int i = 0; i < attackNumDice; ++i) {
        attackTotal += (rand() % attackDiceFaces) + 1;
    }
/*----------SPECIAL CASE BEGIN----------*/
    if (attackTotal == 12) {
        attackTotal = 1000;  //Target is "turned to stone" & Medusa wins!
        hasGlared = true;
        cout << "Medusa attacks with her Glare, turning her opponent to stone!" << endl;
/*----------SPECIAL CASE END----------*/
    } else {
        hasGlared = false;
       cout << "Medusa attacks with " << attackTotal << " attack points!" << endl;
    }
    return attackTotal;
}

bool Medusa::defend(int attackTotal)
{
/*----------SPECIAL CASE BEGIN----------*/
/* This utility prevents Medusa from being able to die when she's "glared" at
 her opponent */
    if (hasGlared) {
        return false;
    }
/*----------SPECIAL CASE END----------*/
    int incompleteDefense = 0;
    int newStrength = 0;
    int defenseOutcome = 0;
    
    for (int i = 0; i < defenseNumDice; ++i) {
        incompleteDefense += (rand() % defenseDiceFaces) + 1;
    }
    cout << "Medusa's defense plus armor is " << incompleteDefense + armor << endl;
    
    defenseOutcome = ((incompleteDefense + armor) - attackTotal);
    
    if (defenseOutcome < 0) {
        newStrength = (strength + defenseOutcome);
        strength = newStrength;
        
    } else if (defenseOutcome >= 0) cout << "Medusa has thwarted the attack!" << endl;
        
    if (strength <= 0) {
        cout << "Medusa has died" << endl;
        return true;
    } else cout << "Medusa has " << strength << " remaining Strength Point(s)" << endl;
    return false;
    
}


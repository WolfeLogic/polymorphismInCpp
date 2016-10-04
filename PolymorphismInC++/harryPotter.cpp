//
//  harryPotter.cpp
//  Assignment3
//
//  Created by Drew Wolfe on 7/15/16.
//  Copyright © 2016 Drew Wolfe. All rights reserved.
//

#include "harryPotter.hpp"

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


HarryPotter::HarryPotter()
{
    armor = 0;
    strength = 10;
    strengthCount = 2;
    attackNumDice = 2;
    attackDiceFaces = 6;
    defenseNumDice = 2;
    defenseDiceFaces = 6;
}

HarryPotter::~HarryPotter() {} //destructor

int HarryPotter::attack()
{
    int attackTotal = 0;
    for (int i = 0; i < attackNumDice; ++i) {
        attackTotal += (rand() % attackDiceFaces) + 1;
    }
    cout << "Harry Potter attacks with " << attackTotal << " attack points!" << endl;
    return attackTotal;
}

bool HarryPotter::defend(int attackTotal)
{
    int incompleteDefense = 0;
    int newStrength = 0;
    int defenseOutcome = 0;
    
    for (int i = 0; i < defenseNumDice; ++i) {
        incompleteDefense += (rand() % defenseDiceFaces) + 1;
    }
    cout << "Harry Potter's defense plus armor is " << incompleteDefense + armor << endl;
    
    defenseOutcome = ((incompleteDefense + armor) - attackTotal);
    
    if (defenseOutcome < 0) {
        newStrength = (strength + defenseOutcome);
        strength = newStrength;
        
    } else if (defenseOutcome >= 0) cout << "Harry Potter has thwarted the attack!" << endl;
        
    if (strength <= 0) {
/*----------SPECIAL CASE----------*/
        --strengthCount;
        if (strengthCount == 1) {
            cout << "Harry Potter had died, but he's miraculously come back from the dead to fight again!" << endl;
            strength = 10;
            cout << "Harry Potter has " << strength << " remaining Strength Point(s)" << endl;
            return false;
        }
        else if (strengthCount == 0) {
            cout << "Harry Potter has died... For good" << endl;
            return true;
        }
/*----------SPECIAL CASE----------*/        
    } else cout << "Harry Potter has " << strength << " remaining Strength Point(s)" << endl;
    return false;
    
}


//
//  gollum.cpp
//  Assignment3
//
//  Created by Drew Wolfe on 7/15/16.
//  Copyright © 2016 Drew Wolfe. All rights reserved.
//

#include "gollum.hpp"

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


Gollum::Gollum()
{
    armor = 3;
    strength = 8;
    attackNumDice = 1;
    attackDiceFaces = 6;
    defenseNumDice = 1;
    defenseDiceFaces = 6;
}

Gollum::~Gollum() {} //destructor

int Gollum::attack()
{
    int spCaseRoll1 = rand() % 20;
//    cout << "spCaseRoll1 = " << endl; //Validation of special case when spCaseRoll1 == spCaseRoll2 
    int spCaseRoll2 = rand() % 20;
//    cout << "spCaseRoll1 = " << endl;
    int attackTotal = 0;
    
/*----------SPECIAL CASE BEGIN----------*/
    if (spCaseRoll1 == spCaseRoll2) {
        for (int i = 0; i < 3; ++i) {
            attackTotal += (rand() % 6) + 1;
            }
/*----------SPECIAL CASE END----------*/
        } else {
            for (int i = 0; i < attackNumDice; ++i) {
                attackTotal += (rand() % attackDiceFaces) + 1;
            }
        }
    
/*----------SPECIAL CASE BEGIN----------*/
    if (spCaseRoll1 == spCaseRoll2) {
        cout << "Gollum jumps on his opponents back and attacks with " << attackTotal << " attack points!" << endl;
/*----------SPECIAL CASE END----------*/
    } else {
        cout << "Gollum attacks with " << attackTotal << " attack points!" << endl;
    }
    
    
    return attackTotal;
}

bool Gollum::defend(int attackTotal)
{
    int incompleteDefense = 0;
    int newStrength = 0;
    int defenseOutcome = 0;
    
    for (int i = 0; i < defenseNumDice; ++i) {
        incompleteDefense += (rand() % defenseDiceFaces) + 1;
    }
    cout << "Gollum's defense plus armor is " << incompleteDefense + armor << endl;
    
    defenseOutcome = ((incompleteDefense + armor) - attackTotal);
    
    if (defenseOutcome < 0) {
        newStrength = (strength + defenseOutcome);
        strength = newStrength;
        
    } else if (defenseOutcome >= 0) cout << "Gollum has thwarted the attack!" << endl;
        
    if (strength <= 0) {
        cout << "Gollum has died" << endl;
        return true;
    } else cout << "Gollum has " << strength << " remaining Strength Point(s)" << endl;
    return false;
    
}


//
//  blueMen.cpp
//  Assignment3
//
//  Created by Drew Wolfe on 7/15/16.
//  Copyright © 2016 Drew Wolfe. All rights reserved.
//

#include "blueMen.hpp"

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


BlueMen::BlueMen()
{
    armor = 3;
    strength = 12;
    attackNumDice = 2;
    attackDiceFaces = 10;
    defenseNumDice = 3;
    defenseDiceFaces = 6;
}

BlueMen::~BlueMen() {} //destructor

int BlueMen::attack()
{
    int attackTotal = 0;
    for (int i = 0; i < attackNumDice; ++i) {
        attackTotal += (rand() % attackDiceFaces) + 1;
    }
    cout << "The Blue Men attack with " << attackTotal << " attack points!" << endl;
    return attackTotal;
}

bool BlueMen::defend(int attackTotal)
{
    int incompleteDefense = 0;
    int newStrength = 0;
    int defenseOutcome = 0;
/*----------SPECIAL CASE BEGIN----------*/    
    if (strength >= 9) {
        for (int i = 0; i < defenseNumDice; ++i) {
//            cout << "Blue Men number of defense die = 3" << endl;
            incompleteDefense += (rand() % defenseDiceFaces) + 1;
        }
    } else
        if (8 >= strength && strength >= 5) {
            for (int i = 0; i < 2; ++i) {
//                cout << "Blue Men number of defense die = 2" << endl; //Validates that die decrement according to strength
                incompleteDefense += (rand() % defenseDiceFaces) + 1;
            }
        } else
            if (strength <= 4) {
                for (int i = 0; i < 1; ++i) {
//                    cout << "Blue Men number of defense die = 1" << endl;
                    incompleteDefense += (rand() % defenseDiceFaces) + 1;
                }
                
            }
/*----------SPECIAL CASE END----------*/
        
    cout << "The Blue Men's defense plus armor is " << incompleteDefense + armor << endl;
    
    defenseOutcome = ((incompleteDefense + armor) - attackTotal);
    
    if (defenseOutcome < 0) {
        newStrength = (strength + defenseOutcome);
        strength = newStrength;
        
    } else if (defenseOutcome >= 0) cout << "The Blue Men have thwarted the attack!" << endl;
        
    if (strength <= 0) {
        cout << "The Blue Men have died" << endl;
        return true;
    } else cout << "The Blue Men have " << strength << " remaining Strength Point(s)" << endl;
    return false;
    
}


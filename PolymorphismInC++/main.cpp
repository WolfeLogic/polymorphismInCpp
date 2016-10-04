//
//  main.cpp
//  Polymorphism
//
//  Created by Drew Wolfe on 7/15/16.
//  Copyright © 2016 Drew Wolfe. All rights reserved.
//
/*Fantasy combat game that pits creatures of varying attack and defense responses
 designed by default to select two (2) creatures randomly upon program execution
 and run while providing for a test mode that enables the user to select creatures
 and "battle" via non-random attack & defense responses*/

#include "creature.hpp"
#include "medusa.hpp"
#include "blueMen.hpp"
#include "gollum.hpp"
#include "harryPotter.hpp"
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

Creature* getRandomCreature();
Creature* getCreatureById(int id);
Creature* getCreatureFromUser();


int main(int argc, const char * argv[]){
    //command line access to testMode via ./program test
    bool testMode = (argc == 2 && strcmp(argv[1], "test") == 0);
    
    //Creature object instantiations
    Creature* c1 = NULL;
    Creature* c2 = NULL;
    
    //means to flag wheather creature is dead or alive
    bool dead1 = false;
    bool dead2 = false;
    
    /*testMode seeds srand() with an arbitrary constant int in order to ensure that
     output is consitant and predictable. It also presents the user with a menu from
     which to select creatures to battle*/
    if (testMode) {
        const int TEST_SEED = 4;
        srand(TEST_SEED); //constant used to seed rand so that output is predictable
        c1 = getCreatureFromUser();
        c2 = getCreatureFromUser();
    } else {
        srand(time(NULL)); //time used to seed the rand func to make more "random"
        c1 = getRandomCreature();
        c2 = getRandomCreature();
    }
    
    //While creature1 is NOT dead and creature2 is NOT dead, attack and defend
    while (!dead1 && !dead2) {
        
        int attackTotal1 = c1->attack();
        int attackTotal2 = c2->attack();
        
        dead1 = c1->defend(attackTotal2);
        dead2 = c2->defend(attackTotal1);
        
    }
    
    cout << "The battle is over!" << endl;
    
    //ALWAYS delete newly instantiated objects!
    delete c1;
    delete c2;
    
    return 0;
}

/*------------------------------FUNCTION DEFINITIONS------------------------------*/

/*-----------------------------getCreatureFromUser()-----------------------------*/
/* getCreatureFromUser() enables a user to input an integer to select the
 associated creature from a menu and outputs a fully instantiated creature via
 getCreatureByID(id). If called within testMode where srand() is seeded  with a
 const int, this fuction allows a user to test for consistancy and ensure that
 changes made elswhere within the program are affecting outcomes as expected*/

Creature* getCreatureFromUser(){
    //To store the user's menu option
    int id = 0;
    
    //Display the menu
    cout << "\nSelect one of the following opponents\n" << endl;
    cout << "0 - Medusa" << endl;
    cout << "1 - Gollum" << endl;
    cout << "2 - Harry Potter" << endl;
    cout << "3 - The Blue Men" << endl;
    cout << "4 - The Reptile People" << endl;
    cin >> id;
    //VALIDATION: While loop to validate that the user's input is a number
    while(!cin)
    {
        cin.clear();
        cin.ignore();
        while (cin.get() != '\n') continue;
        cout << "Bad input. Please enter a number: " << endl;
        
        cin >> id;
    }
    
    //Return the "selection" to the program calling the function
    return getCreatureById(id);
}

/*------------------------------getRandomCreature()------------------------------*/
/* getRandomCreature() instantiates a creature randomly to be used as an
 opponent via getCreatureById(id).*/

Creature* getRandomCreature(){
    int id = rand() % 5;
    
    return getCreatureById(id);
}

/*----------------------------getCreatureById(int id)----------------------------*/
/* getCreatureById(int id) instantiates a creature to be used as an
 opponent according to the input  parameter "id", sourced from either
 getRandomCreature() or getCreatureFromUser()*/

Creature* getCreatureById(int id){
    
    switch (id) {
        case 0:
            return new Medusa(); //only created if evaluated
        case 1:
            return new Gollum(); //creates a Gollumn pointer (Creature pointer)
        case 2:
            return new HarryPotter();
        case 3:
            return new BlueMen();
        case 4:
            return new ReptilePeople();
            
        default:
            return NULL;
    }
}

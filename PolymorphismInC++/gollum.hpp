//
//  gollum.hpp
//  Assignment3
//
//  Created by Drew Wolfe on 7/15/16.
//  Copyright © 2016 Drew Wolfe. All rights reserved.
//

#ifndef gollum_hpp
#define gollum_hpp

#include <stdio.h>
#include "creature.hpp"

class Gollum : public Creature {
    
    
public:
    Gollum();
    virtual ~Gollum(); //destructor
    
    int virtual attack();
    bool virtual defend(int attackTotal);
};

#endif /* gollum_hpp */

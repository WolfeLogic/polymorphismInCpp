//
//  medusa.hpp
//  Assignment3
//
//  Created by Drew Wolfe on 7/15/16.
//  Copyright © 2016 Drew Wolfe. All rights reserved.
//

#ifndef medusa_hpp
#define medusa_hpp

#include <stdio.h>
#include "creature.hpp"

class Medusa : public Creature {
private:
    bool hasGlared;
    
public:
    Medusa();
    virtual ~Medusa(); //destructor
    
    int virtual attack();
    bool virtual defend(int attackTotal);
};

#endif /* medusa_hpp */

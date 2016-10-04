//
//  reptilePeople.hpp
//  Assignment3
//
//  Created by Drew Wolfe on 7/15/16.
//  Copyright © 2016 Drew Wolfe. All rights reserved.
//

#ifndef reptilePeople_hpp
#define reptilePeople_hpp

#include <stdio.h>
#include "creature.hpp"

class ReptilePeople : public Creature {
    
    
public:
    ReptilePeople();
    virtual ~ReptilePeople(); //destructor
    
    int virtual attack();
    bool virtual defend(int attackTotal);
};

#endif /* reptilePeople_hpp */

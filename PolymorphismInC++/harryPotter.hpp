//
//  harryPotter.hpp
//  Assignment3
//
//  Created by Drew Wolfe on 7/15/16.
//  Copyright © 2016 Drew Wolfe. All rights reserved.
//

#ifndef harryPotter_hpp
#define harryPotter_hpp

#include <stdio.h>
#include "creature.hpp"

class HarryPotter : public Creature {
    
    
public:
    HarryPotter();
    virtual ~HarryPotter(); //destructor
    
    int virtual attack();
    bool virtual defend(int attackTotal);
};

#endif /* harryPotter_hpp */

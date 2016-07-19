//
//  fetch.hpp
//  MIPS
//
//  Created by Poonam Deshpande on 6/21/16.
//  Copyright © 2016 Poonam Deshpande. All rights reserved.
//

#ifndef fetch_hpp
#define fetch_hpp

#include <stdio.h>
#include <stdint.h>

class Fetch
{
public:
    /*----------------------------------------------------------------*/
    /* FUNCTION: fetch_next_instruction                               */
    /*----------------------------------------------------------------*/
    /* Description: Fetch next instruction to be executed
    ------------------------------------------------------------------*/
    uint32_t fetch_next_instruction (void);
};

#endif /* fetch_hpp */

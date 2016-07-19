//
//  writeback.hpp
//  MIPS
//
//  Created by Poonam Deshpande on 6/21/16.
//  Copyright © 2016 Poonam Deshpande. All rights reserved.
//

#ifndef writeback_hpp
#define writeback_hpp

#include <stdio.h>
#include <stdint.h>

class Writeback
{
public:
    
    /*----------------------------------------------------------------*/
    /* FUNCTION: writeback_to_register                                */
    /*----------------------------------------------------------------*/
    /* Description: Writes a value to the register
     
     Arguments: 1. Register address
                2. Value to write to the register
     
     Returns:   None
     
     ------------------------------------------------------------------*/
    void writeback_to_register (uint8_t register_addr,
                                uint32_t value);
};

#endif /* writeback_hpp */

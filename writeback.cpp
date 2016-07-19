//
//  writeback.cpp
//  MIPS
//
//  Created by Poonam Deshpande on 6/21/16.
//  Copyright © 2016 Poonam Deshpande. All rights reserved.
//

#include "writeback.hpp"
#include <stdint.h>

#include "registers.hpp"

class Writeback Writeback_obj;
extern class Register_file Register_file_obj;

/*----------------------------------------------------------------*/
/* FUNCTION: writeback_to_register                                */
/*----------------------------------------------------------------*/
/* Description: Writes a value to the register
 
 Arguments: 1. Register address
            2. Value to write to the register
 
 Returns:   None
 
 ------------------------------------------------------------------*/
void Writeback::writeback_to_register(uint8_t register_addr,
                                      uint32_t value)
{
    Register_file_obj.write_to_reg(register_addr, value);

} /* writeback_to_register */
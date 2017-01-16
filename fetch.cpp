//
//  fetch.cpp
//  MIPS
//
//  Created by Poonam Deshpande on 6/21/16.
//  Copyright © 2016 Poonam Deshpande. All rights reserved.
//

#include "fetch.hpp"
#include "registers.hpp"
#include "memory.hpp"

class Fetch Fetch_obj;
extern class Register_file Register_file_obj;
extern class Memory Memory_obj;

/*----------------------------------------------------------------*/
/* FUNCTION: fetch_next_instruction                               */
/*----------------------------------------------------------------*/
/* Description: Fetch next instruction to be executed
 
 Arguments: None
 
 Returns:   Next instruction to be executed
 
 ------------------------------------------------------------------*/
uint32_t Fetch::fetch_next_instruction(void)
{
    uint32_t pc_value = Register_file_obj.get_PC_and_increment();
    
    printf ("PC = %d\n", pc_value);
    
    return Memory_obj.fetch_instruction(pc_value);

} /* fetch_next_instruction */
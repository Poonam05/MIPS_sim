//
//  registers.cpp
//  MIPS
//
//  Created by Poonam Deshpande on 6/11/16.
//  Copyright © 2016 Poonam Deshpande. All rights reserved.
//

#include "registers.hpp"
#include "decode.hpp"
#include "report.hpp"
#include <stdio.h>

/* Function exit () is under stdlib.h */
#include <stdlib.h>

/* Register file definition */
class Register_file Register_file_obj;
extern class Report Report_obj;

/*----------------------------------------------------------------*/
/*                                                                */
/*                      FUNCTION DEFINITIONS                      */
/*                                                                */
/*----------------------------------------------------------------*/

/*----------------------------------------------------------------*/
/* FUNCTION: CONSTRUCTOR                                          */
/*----------------------------------------------------------------*/
/* Description: CONSTRUCTOR
 
 Arguments: None
 
 Returns:   None
 
 ------------------------------------------------------------------*/
Register_file::Register_file (void)
{
    uint8_t i;
    
    /* Set all register values to 0 */
    for (i = 0; i < 32; i++)
    {
        reg[i] = 0;
    }
    prid_reg = 0xFFFFFF00;
    reg[0]   = 10;
    reg[1]   = 20;
    reg[2]   = 30;

} /* Register Constructor */

/*----------------------------------------------------------------*/
/* FUNCTION: get_PC                                               */
/*----------------------------------------------------------------*/
/* Description: Returns program counter value
 
   Arguments: None

   Returns:   Program Counter value

------------------------------------------------------------------*/
uint32_t Register_file::get_PC (void)
{
    return pc;

} /* get_PC */


/*----------------------------------------------------------------*/
/* FUNCTION: set_PC                                               */
/*----------------------------------------------------------------*/
/* Description: Set program counter value
 
 Arguments: New PC value
 
 Returns:   None
 
 ------------------------------------------------------------------*/
void Register_file::set_PC (uint32_t new_pc_value)
{
    pc = new_pc_value;

} /* get_PC_and_increment */


/*----------------------------------------------------------------*/
/* FUNCTION: get_PC_and_increment                                 */
/*----------------------------------------------------------------*/
/* Description: Returns program counter value and then increments 
                it
 
 Arguments: None
 
 Returns:   Program Counter value before increment
 
 ------------------------------------------------------------------*/
uint32_t Register_file::get_PC_and_increment (void)
{
    uint32_t ret_val = pc;
    pc++;
    
    return ret_val;

} /* get_PC_and_increment */



/*----------------------------------------------------------------*/
/* FUNCTION: write_to_reg                                         */
/*----------------------------------------------------------------*/
/* Description: Writes a value to the register                    
                                                                
   Arguments: 1. Register address
              2. Value to write to the register
                                                                
   Returns:   None

------------------------------------------------------------------*/
void Register_file::write_to_reg (uint8_t reg_addr, uint32_t value)
{
    if (reg_addr < 31)
    {
        reg[reg_addr] = value;
        Report_obj.set_modified_reg_cycle(reg_addr);
    }
    else
    {
        printf ("reg[%d]: Invalid register access", reg_addr);
        exit (1);
    }
    
    return;

} /* write_to_reg */


/*----------------------------------------------------------------*/
/* FUNCTION: read_from_reg                                        */
/*----------------------------------------------------------------*/
/* Description: Reads the value from a register                   
                                                                
   Arguments: 1. Register address
                                                                
                                                                
   Returns:   Value contained in the specified register

------------------------------------------------------------------*/
uint32_t Register_file::read_from_reg (uint8_t reg_addr)
{
    if (reg_addr < 31)
    {
        return reg[reg_addr];
    }
    else
    {
        printf ("reg[%d]: Invalid register access", reg_addr);
        exit (1);
    }
    
} /* read_from_reg */

/*----------------------------------------------------------------*/
/* FUNCTION: get_PC_val                                           */
/*----------------------------------------------------------------*/
/* Description: Returns program counter value and then increments 
                it
 
 Arguments: None
 
 Returns:   Program Counter value before increment
 
 ------------------------------------------------------------------*/
void Register_file::set_PC_target(uint32_t target)
{
    target = target << 2;
    pc=target + (pc & 0xF000);
    
}
//used in J 



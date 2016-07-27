//
//  registers.hpp
//  MIPS
//
//  Created by Poonam Deshpande on 6/11/16.
//  Copyright © 2016 Poonam Deshpande. All rights reserved.
//

#ifndef registers_h
#define registers_h

#include <stdint.h>

/* Register File Class */
class Register_file
{
private:
    
    friend class Report;
    
    /* Computational registers */
    uint32_t reg[32];
    uint32_t pc;
    uint32_t mul_hi;
    uint32_t mul_low;
    
    /* Exception and status registers */
    
    /* Cause Register */
    uint32_t cause_reg;
    
    /* Exception Program Counter */
    uint32_t epc;
    
    /* Status register */
    uint32_t status_reg;

    /* Processor Revision Identifier Register - default to 0xFFFFFF00 */
    uint32_t prid_reg;
    
public:

    
    /*----------------------------------------------------------------*/
    /* FUNCTION: get_PC                                               */
    /*----------------------------------------------------------------*/
    /* Description: Returns program counter value
     
     Arguments: None
     
     Returns:   Program Counter value
     
    ------------------------------------------------------------------*/
    uint32_t get_PC (void);
    
    
    /*----------------------------------------------------------------*/
    /* FUNCTION: set_PC                                               */
    /*----------------------------------------------------------------*/
    /* Description: Set program counter value
     
     Arguments: New PC value
     
     Returns:   None
     
    ------------------------------------------------------------------*/
    void set_PC (uint32_t new_pc_value);
    
    
    /*----------------------------------------------------------------*/
    /* FUNCTION: get_PC_and_increment                                 */
    /*----------------------------------------------------------------*/
    /* Description: Returns program counter value and then increments
     it
     
     Arguments: None
     
     Returns:   Program Counter value before increment
     
    ------------------------------------------------------------------*/
    uint32_t get_PC_and_increment (void);

    
    /*----------------------------------------------------------------*/
    /* FUNCTION: write_to_reg                                         */
    /*----------------------------------------------------------------*/
    /* Description: Writes a value to the register
     
     Arguments: 1. Register address
     2. Value to write to the register
     
     Returns:   None
     
    ------------------------------------------------------------------*/
    void write_to_reg (uint8_t reg_addr, uint32_t value);
    
    
    /*----------------------------------------------------------------*/
    /* FUNCTION: read_from_reg                                        */
    /*----------------------------------------------------------------*/
    /* Description: Reads the value from a register
     
     Arguments: 1. Register address
     
     
     Returns:   Value contained in the specified register
     
    ------------------------------------------------------------------*/
    uint32_t read_from_reg (uint8_t reg_addr);
    
    
    
    
    /*----------------------------------------------------------------*/
    /* FUNCTION: get_PC_val                                           */
    /*----------------------------------------------------------------*/
    /* Description: Returns program counter value and then increments
            it
 
       Arguments: None
 
       Returns:   Program Counter value before increment
 
    ------------------------------------------------------------------*/
    void get_PC_val(void);

    
    
    
    
    /*----------------------------------------------------------------*/
    /* FUNCTION: CONSTRUCTOR                                          */
    /*----------------------------------------------------------------*/
    /* Description: CONSTRUCTOR
     
     Arguments: None
     
     Returns:   None
     
    ------------------------------------------------------------------*/
    Register_file (void);
    
};



#endif /* registers_h */

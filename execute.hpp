//
//  execute.hpp
//  MIPS
//
//  Created by Poonam Deshpande on 6/11/16.
//  Copyright © 2016 Poonam Deshpande. All rights reserved.
//

#ifndef execute_hpp
#define execute_hpp

#include <stdio.h>

#include "instructions.hpp"


class Execute
{
public:
    /*----------------------------------------------------------------*/
    /* FUNCTION: execute_instruction                                  */
    /*----------------------------------------------------------------*/
    /* Description: Executes the instruction and returns computed
     result
     
     Arguments: 1. Decoded instruction
                2. Operand 2 (if applicable)
                3. Operand 3 (if applicable)
                4. Is memory write valid boolean
                5. Is writeback valid boolean
     
     
     Returns:   32 bit computed value
     
     ------------------------------------------------------------------*/
    uint32_t execute_instruction (instruction_t instruction,
                                           
                                  /* Read only operand */
                                  uint32_t operand2,
                                           
                                  /* Read only operand */
                                  uint32_t operand3,
                                  
                                  /* Determine if a mem_write is valid for this instruction */
                                  bool* is_mem_write_valid,
                                  
                                  /* Determine if a mem_write is valid for this instruction */
                                  bool* is_writeback_valid);
    
    /*----------------------------------------------------------------*/
    /* FUNCTION: CONSTRUCTOR                                          */
    /*----------------------------------------------------------------*/
    /* Description: CONSTRUCTOR
     
     Arguments: None
     
     Returns:   None
     
     ------------------------------------------------------------------*/
    Execute (void);
};

#endif /* execute_hpp */

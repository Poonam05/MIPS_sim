//
//  execute.cpp
//  MIPS
//
//  Created by Poonam Deshpande on 6/11/16.
//  Copyright © 2016 Poonam Deshpande. All rights reserved.
//

#include <stdio.h>

/* Function exit () is under stdlib.h */
#include <stdlib.h>

#include "execute.hpp"

/* Required to read and write registers */
#include "registers.hpp"

class Execute Execute_obj;

/*----------------------------------------------------------------*/
/* FUNCTION: execute_instruction                                  */
/*----------------------------------------------------------------*/
/* Description: Executes the instruction and returns computed
 result
 
 Arguments: 1. Decoded instruction
            2. Operand 2 (if applicable)
            3. Operand 3 (if applicable)
 
 
 Returns:   32 bit computed value
 
 ------------------------------------------------------------------*/
uint32_t Execute::execute_instruction (instruction_t instruction,
                  
                                       /* Read only operand */
                                       uint32_t operand2,
                          
                                       /* Read only operand */
                                       uint32_t operand3,
                                       
                                       /* Determine if a mem_write is valid for this instruction */
                                       bool* is_mem_write_valid,
                                       
                                       /* Determine if a mem_write is valid for this instruction */
                                       bool* is_writeback_valid)
{
    /* Use a 64 bit result to account for overflows */
    uint64_t intermediate_result;

    switch (instruction)
    {
        /*=============================================================*/
        /* ADD rd, rs, rt : rd <- rs + rt
         
           rs = operand2, rt = operand3, rd = <return>
        */
        /*=============================================================*/
        case ADD:
            intermediate_result = operand2 + operand3;
            
            /* Mask out lower 32 bits and check if any of the high bits are set. */
            if (intermediate_result & 0xFFFFFFFF)
            {
                /* TODO!!! set overflow flag */
                
                // TODO!!!! mask out lower 32 bits and retain higher 32 bits
                
                
                /* Extract only the lower 32 bits */
                intermediate_result &= 0xFFFFFFFF;
                
            }
            
            /* There is no memory access required for this instruction. Hence, invalidate it */
            *is_mem_write_valid = 0;
            
            /* A writeback register is specified. Hence it is valid */
            *is_writeback_valid = 1;
            
            break;
            
            
            
    /*=============================================================================*/
    /* ADD Unsigned                                                 ADDU, rd, rs, rt
     
       Add contents of registers rs and rt and place 32-bit result in register rd.
     
       Do not trap on overflow.
    */
    /*=============================================================================*/
            
            case ADDU:
            intermediate_result = operand2 + operand3;
            
            // No memory access required
            *is_mem_write_valid = 0 ;
            
            //Writeback to register. Hence it is valid
            *is_writeback_valid = 1 ;
            
            break;
            
    
    
            /*=============================================================*/
            /* AND rd, rs, rt : rd <- rs & rt
             
             rs = operand2, rt = operand3, rd = <return>
             */
            /*=============================================================*/
            
        case AND:
            intermediate_result = operand2 & operand3;
            
            // No memory access required
            *is_mem_write_valid = 0 ;
            
            //Writeback to register. Hence it is valid
            *is_writeback_valid = 1 ;
            
            break;
        
        
            
    /*=============================================================================*/
    /* OR                                                              OR rd, rs, rt

       Bitwise OR contents of registers rs and rt and place the result in rd.
    */
    /*=============================================================================*/
            
        case OR:
            intermediate_result = operand2 | operand3;
            
            // No memory access required
            *is_mem_write_valid = 0 ;
            
            //Writeback to register. Hence it is valid
            *is_writeback_valid = 1 ;
            
            break;
            
    /*=============================================================================*/
    /* XOR                                                            XOR rd, rs, rt

       Bitwise exclusive OR contents of registers rs and rt and place the result in 
       rd.
    */
    /*=============================================================================*/
            
        case XOR:
            intermediate_result = operand2 ^ operand3;
            
            // No memory access required
            *is_mem_write_valid = 0 ;
            
            //Writeback to register. Hence it is valid
            *is_writeback_valid = 1 ;
            
            break;
            
   /*=============================================================================*/
    /* Shift Right Logical                                         SRL rd, rt, shamt

       Shift contents of register rt left by shamt bits, inserting zeros into low
       order bits. Place 32-bit result in register rd.
    */
    /*=============================================================================*/
  
        case SRL:
            intermediate_result = operand2 >> operand3;
            
            // No memory access required
            *is_mem_write_valid = 0 ;
            
            //Writeback to register. Hence it is valid
            *is_writeback_valid = 1 ;
            
            break;
            
            
 
    /*=============================================================================*/
    /* Shift Right Arithmetic                                      SRA rd, rt, shamt

       Shift contents of register rt right by shamt bits, sign-extending the high
       order bits. Place 32-bit result in register rd.
    */
    /*=============================================================================*/
            
         /*
            case SRA:
            intermediate_result = operand2 >> operand3;
            
            // No memory access required
            *is_mem_write_valid = 0 ;
            
            //Writeback to register. Hence it is valid
            *is_writeback_valid = 1 ;
            
            break; */
    
            
            
    /*=============================================================================*/
    /* NOR                                                            NOR rd, rs, rt

       Bitwise NOR contents of registers rs and rt and place the result in
       rd.
    */
    /*=============================================================================*/
            
            
        case NOR:
            intermediate_result = ~ (operand2 | operand3);
            
            
            // No memory access required
            *is_mem_write_valid = 0 ;
            
            //Writeback to register. Hence it is valid
            *is_writeback_valid = 1 ;
            
            break;
            
 
            
  /*=============================================================================*/
    /* Shift Left Logical                                          SLL rd, rt, shamt

       Shift contents of register rt left by shamt bits, inserting zeros into low
       order bits. Place 32-bit result in register rd.
     */
  /*=============================================================================*/
            
            
        case SLL:
            intermediate_result = operand2 << operand3;
            
            // No memory access required
            *is_mem_write_valid = 0 ;
            
            //Writeback to register. Hence it is valid
            *is_writeback_valid = 1 ;
            
            break;
            
            
            
     /*=============================================================================*/
    /* Set on Less Than Unsigned                                     SLTU rd, rs, rt

       Compare contents of registers rt to rs (as unsigned 32-bit integers).
       If register rs is less than rt, result = 1; otherwise result = 0.
    */
    /*=============================================================================*/

            
            
            case SLTU:
            if(operand2 < operand3)
            {
                intermediate_result = 1;
            }
            intermediate_result = 0;
            
            // No memory access required
            *is_mem_write_valid = 0 ;
            
            //Writeback to register. Hence it is valid
            *is_writeback_valid = 1 ;
            
            break;

        
            
            
            
            
        /*=============================================================*/
        /* MAX_INSTRUCTION_T : Hole instruction
         

         */
        /*=============================================================*/
        case MAX_INSTRUCTION_T:
            /* Hole in the pipeline. Ignore instruction. */
            break;
        
            
        
        /*=============================================================*/
        /* default : Unknown instruction
         
         
         */
        /*=============================================================*/
        default:
            printf ("Unknown instruction %d", instruction);
    }
    
    return (uint32_t)intermediate_result;

} /* execute_instruction */

/*----------------------------------------------------------------*/
/* FUNCTION: CONSTRUCTOR                                          */
/*----------------------------------------------------------------*/
/* Description: CONSTRUCTOR
 
 Arguments: None
 
 Returns:   None
 
 ------------------------------------------------------------------*/
Execute::Execute (void)
{
    
}

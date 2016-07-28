//
//  decode.cpp
//  MIPS
//
//  Created by Poonam Deshpande on 6/11/16.
//  Copyright © 2016 Poonam Deshpande. All rights reserved.
//

#include "decode.hpp"
#include "pipeline.hpp"
#include "registers.hpp"
#include <stdio.h>


class Decode Decode_obj;
extern class Register_file Register_file_obj;

/*----------------------------------------------------------------*/
/*                                                                */
/*                      FUNCTION DEFINITIONS                      */
/*                                                                */
/*----------------------------------------------------------------*/


/*----------------------------------------------------------------*/
/* FUNCTION: decode_instruction                                   */
/*----------------------------------------------------------------*/
/* Description: Decodes an opcode and returns instructions type   
                along with the operand(s)
                                                                
   Arguments: 1. MIPS instruction binary
   (Return)   2. Pointer to decoded instruction
   (Return)   3. Operand 1 (if applicable)
   (Return)   4. Operand 2 (if applicable)
                                                                
                                                                
   Returns:   Destination register address

------------------------------------------------------------------*/
uint8_t Decode::decode_instruction (uint32_t mips_instruction_binary,
                                    instruction_t* instruction,
                                    uint32_t* operand1,
                                    uint32_t* operand2,
                                    uint32_t* operand3)
{
    uint8_t opcode_26_31;
    uint8_t dest_register_addr = 0xFF;
    
    /* Hack: Set default value to a HOLE INSTRUCTION.
       TODO: REMOVE LATER */
    *instruction = MAX_INSTRUCTION_T;
    
    /* Get bits 31:26 */
    opcode_26_31 = mips_instruction_binary >> OPCODE_POSITION_31_26; //right shift op times to get opcode
    //printf ("Binary 0x%x Opcode 0x%x\n", mips_instruction_binary, opcode_26_31);

    switch (opcode_26_31)
    {
        case 0:
            dest_register_addr = decode_opcode_0 (mips_instruction_binary, instruction, operand1, operand2, operand3);
                
            break;
            
        case 2:
           decode_opcode_2 (mips_instruction_binary, instruction, operand1);
                
            break;
        
            
    }
    //printf ("Opcode: 0x%x decoded instruction %d\n", opcode_26_31, *instruction);
    
    return dest_register_addr;

} /* decode_instruction */

/*----------------------------------------------------------------*/
/* FUNCTION: decode_opcode_0                                      */
/*----------------------------------------------------------------*/
/* Description: Decodes the function code and returns             
                instruction type for opcode = 0
                along with the operand(s)
                                                                
   Arguments: 1. MIPS instruction binary
   (Return)   2. Pointer to decoded instruction
   (Return)   3. Operand 1 (if applicable)
   (Return)   4. Operand 2 (if applicable)
   (Return)   5. Operand 3 (if applicable)
                                                                
                                                                
   Returns:   Destination register address

------------------------------------------------------------------*/
uint8_t Decode::decode_opcode_0 (uint32_t mips_instruction_binary,
                                 instruction_t* instruction,
                                 uint32_t* operand1,
                                 uint32_t* operand2,
                                 uint32_t* operand3)
{
    uint8_t func_code_0_5;
    uint8_t dest_register_addr = 0xFF;
    
    /* Mask out higher order bits except the last 6 bits */
    func_code_0_5 = mips_instruction_binary & 0x3F;
    
    /* Select function */
    switch (func_code_0_5)
    {
        case ADD_FUNC:
            *instruction = ADD;
            *operand2    = get_rs_value(mips_instruction_binary);
            *operand3    = get_rt_value(mips_instruction_binary);
            dest_register_addr = get_dest_register_addr (mips_instruction_binary);
            printf ("DECODE:decode_opcode_0:Function ADD rd(%d) <- %d + %d\n", dest_register_addr, *operand2, *operand3);
            
            break;

        case ADDU_FUNC:
            *instruction = ADDU;
            *operand2    = get_rs_value(mips_instruction_binary);
            *operand3    = get_rt_value(mips_instruction_binary);
            dest_register_addr = get_dest_register_addr (mips_instruction_binary);
            printf ("DECODE:decode_opcode_0:Function ADDU rd(%d) <- %d + %d\n", dest_register_addr, *operand2, *operand3);
            
            break;
            
        case AND_FUNC:
            *instruction = AND;
            *operand2    = get_rs_value(mips_instruction_binary);
            *operand3    = get_rt_value(mips_instruction_binary);
            dest_register_addr = get_dest_register_addr (mips_instruction_binary);
            printf ("DECODE:decode_opcode_0:Function AND rd(%d) <- %d & %d\n", dest_register_addr, *operand2, *operand3);
            
            break;
            
            
        case OR_FUNC:
            *instruction = OR;
            *operand2    = get_rs_value(mips_instruction_binary);
            *operand3    = get_rt_value(mips_instruction_binary);
            dest_register_addr = get_dest_register_addr (mips_instruction_binary);
            printf ("DECODE:decode_opcode_0:Function OR rd(%d) <- %d | %d\n", dest_register_addr, *operand2, *operand3);
            
            break;
            
        case XOR_FUNC:
            *instruction = XOR;
            *operand2    = get_rs_value(mips_instruction_binary);
            *operand3    = get_rt_value(mips_instruction_binary);
            dest_register_addr = get_dest_register_addr (mips_instruction_binary);
            printf ("DECODE:decode_opcode_0:Function XOR rd(%d) <- %d ^ %d\n", dest_register_addr, *operand2, *operand3);
            
            break;
        
        case NOR_FUNC:
            *instruction = NOR;
            *operand2    = get_rs_value(mips_instruction_binary);
            *operand3    = get_rt_value(mips_instruction_binary);
            dest_register_addr = get_dest_register_addr (mips_instruction_binary);
            printf ("DECODE:decode_opcode_0:Function NOR rd(%d) <- %d NOR %d\n", dest_register_addr, *operand2, *operand3);
            
            break;
            
        case SRL_FUNC:
            *instruction = SRL;
            *operand2    = get_rt_value(mips_instruction_binary);
            *operand3    = get_shamt_value(mips_instruction_binary);
            dest_register_addr = get_dest_register_addr (mips_instruction_binary);
            printf ("DECODE:decode_opcode_0:Function SRL rd(%d) <- %d >> %d\n", dest_register_addr, *operand2, *operand3);
            
            break;
            
        case SLL_FUNC:
            *instruction = SLL;
            *operand2    = get_rt_value(mips_instruction_binary);
            *operand3    = get_shamt_value(mips_instruction_binary);
            dest_register_addr = get_dest_register_addr (mips_instruction_binary);
            printf ("DECODE:decode_opcode_0:Function SLL rd(%d) <- %d << %d\n", dest_register_addr, *operand2, *operand3);
            
            break;
            
        case SRA_FUNC:
            *instruction = SRA;
            *operand2    = get_rt_value(mips_instruction_binary);
            *operand3    = get_shamt_value(mips_instruction_binary);
            dest_register_addr = get_dest_register_addr (mips_instruction_binary);
            printf ("DECODE:decode_opcode_0:Function SLL rd(%d) <- %d >> %d\n", dest_register_addr, *operand2, *operand3);
            
            break;
            
            
        case SLTU_FUNC:
            *instruction = SLTU;
            *operand2    = get_rt_value(mips_instruction_binary);
            *operand3    = get_rs_value(mips_instruction_binary);
            dest_register_addr = get_dest_register_addr (mips_instruction_binary);
            printf ("DECODE:decode_opcode_0:Function STLU rd(%d) <- %d STLU %d\n", dest_register_addr, *operand2, *operand3);
            
            break;
            
            
            
        case SLLV_FUNC:
            *instruction = SLLV;
            *operand2    = get_rt_value(mips_instruction_binary);
            *operand3    = get_rs_value(mips_instruction_binary);
            dest_register_addr = get_dest_register_addr (mips_instruction_binary);
            printf ("DECODE:decode_opcode_0:Function SLLV rd(%d) <- %d SLLV %d\n", dest_register_addr, *operand2, *operand3);
            
            break;
            
            
        case SRAV_FUNC:
            *instruction = SRAV;
            *operand2    = get_rt_value(mips_instruction_binary);
            *operand3    = get_rs_value(mips_instruction_binary);
            dest_register_addr = get_dest_register_addr (mips_instruction_binary);
            printf ("DECODE:decode_opcode_0:Function SRAV rd(%d) <- %d SRAV %d\n", dest_register_addr, *operand2, *operand3);
            
            break;
            
            
         
        
        
       
        
        
            
        default:
            *instruction = MAX_INSTRUCTION_T;
            printf ("DECODE:decode_opcode_0:Unknown instruction binary 0x%x\n", mips_instruction_binary);
    }

    
    return dest_register_addr;
} /* decode_opcode_0 */



/*----------------------------------------------------------------*/
    /* FUNCTION: decode_opcode_2 (static)                             */
    /*----------------------------------------------------------------*/
    /* Description: Decodes the function code and returns
                    instruction type for opcode = 2
                    along with the offset
     
     Arguments: 1. MIPS instruction binary
     (Return)   2. Pointer to decoded instruction
     (Return)   3. Target to jump to 
   
     
     
     Returns:   Destination register address
     
     ------------------------------------------------------------------*/
    


void Decode::decode_opcode_2 (uint32_t mips_instruction_binary, instruction_t* instruction, uint32_t* operand1)
{
    *instruction =J;
    *operand1    =  get_target(mips_instruction_binary);
    Register_file_obj.set_PC_target(*operand1);
}





/*----------------------------------------------------------------*/
/* FUNCTION: get_dest_register_addr                               */
/*----------------------------------------------------------------*/
/* Description: Get destination register
 
 Arguments: 1. MIPS instruction binary
 
 
 Returns:   Register rd address
 
 ------------------------------------------------------------------*/
uint32_t Decode::get_dest_register_addr (uint32_t mips_instruction_binary)
{
    /* Get bits 15:11 */
    return ((mips_instruction_binary >> RD_ADDRESS_POSITION_15_11) & 0x1F);
} /* get_dest_register_addr */

/*----------------------------------------------------------------*/
/* FUNCTION: get_rd_value                                         */
/*----------------------------------------------------------------*/
/* Description: Extract destination register address rd from MIPS
                instruction binary and return value at that register
 
   Arguments: 1. MIPS instruction binary
                                      
 
                                      
   Returns:   Register value at rd register

------------------------------------------------------------------*/
uint32_t Decode::get_rd_value (uint32_t mips_instruction_binary)
{
    uint8_t register_addr;
    /* Get bits 15:11 */
    register_addr = (mips_instruction_binary >> RD_ADDRESS_POSITION_15_11) & 0x1F; // discard 11 bits.. start from 12th bit
    
    return Register_file_obj.read_from_reg(register_addr);
} /* get_rd_value */


/*----------------------------------------------------------------*/
/* FUNCTION: get_rs_value                                         */
/*----------------------------------------------------------------*/
/* Description: Extract source register address rs from MIPS
 instruction binary and return value at that register
 
 Arguments: 1. MIPS instruction binary
 
 
 Returns:   Register value at rs register

------------------------------------------------------------------*/
uint32_t Decode::get_rs_value (uint32_t mips_instruction_binary)
{
    uint8_t register_addr;
    
    /* Get bits 25:21 */
    register_addr = (mips_instruction_binary >> RS_ADDRESS_POSITION_25_21) & 0x1F;
    
    return Register_file_obj.read_from_reg(register_addr);
} /* get_rs_value */

/*----------------------------------------------------------------*/
/* FUNCTION: get_rt_value                                         */
/*----------------------------------------------------------------*/
/* Description: Extract source register address rt from MIPS
 instruction binary and return value at that register
 
 Arguments: 1. MIPS instruction binary
 
 
 Returns:   Register value at rt register

------------------------------------------------------------------*/
uint32_t Decode::get_rt_value (uint32_t mips_instruction_binary)
{
    uint8_t register_addr;

    /* Get bits 20:16 */
    register_addr = (mips_instruction_binary >> RT_ADDRESS_POSITION_20_16) & 0x1F;
    
    return Register_file_obj.read_from_reg(register_addr);
} /* get_rt_value */



/*----------------------------------------------------------------*/
/* FUNCTION: get_shamt_value                                      */
/*----------------------------------------------------------------*/
/* Description: Gets the SHift AMounT value.
 
 Arguments: 1. MIPS instruction binary
 
 
 Returns:  Value of shamt

------------------------------------------------------------------*/
uint32_t Decode::get_shamt_value (uint32_t mips_instruction_binary)
{
    uint8_t register_addr;

    /* Get bits 20:16 */
    register_addr = (mips_instruction_binary >>SHAMT_POSITION_10_6) & 0x1F;
    
    return Register_file_obj.read_from_reg(register_addr);
} /* get_rt_value */



/*----------------------------------------------------------------*/
/* FUNCTION: get_imm                                              */
/*----------------------------------------------------------------*/
/* Description: Extract immediate operand from MIPS 
                instruction binary
                                                  
   Arguments: 1. MIPS instruction binary
                                                  
                                                  
   Returns:   Immediate operand

------------------------------------------------------------------*/
uint16_t Decode::get_imm (uint32_t mips_instruction_binary)
{
    /* Get bits 15:0 */
    return ((mips_instruction_binary) & 0xFFFF);
} /* get_imm */



/*----------------------------------------------------------------*/
/* FUNCTION: get_imm                                              */
/*----------------------------------------------------------------*/
/* Description: Extract immediate operand from MIPS 
                instruction binary
                                                  
   Arguments: 1. MIPS instruction binary
                                                  
                                                  
   Returns:   Immediate operand

------------------------------------------------------------------*/
uint16_t Decode::get_target (uint32_t mips_instruction_binary)
{
    /* Get bits 15:0 */
    return ((mips_instruction_binary) & 0x03FFFFFF);
} /* get_target */




/*----------------------------------------------------------------*/
/* FUNCTION: CONSTRUCTOR                                          */
/*----------------------------------------------------------------*/
/* Description: CONSTRUCTOR
 
 Arguments: None
 
 Returns:   None
 
 ------------------------------------------------------------------*/
Decode::Decode (void)
{
    
}

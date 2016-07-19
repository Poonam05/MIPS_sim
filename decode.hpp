//
//  decode.hpp
//  MIPS
//
//  Created by Poonam Deshpande on 6/11/16.
//  Copyright © 2016 Poonam Deshpande. All rights reserved.
//

#ifndef decode_h
#define decode_h

#include <stdio.h>
#include <stdint.h>
#include "instructions.hpp"

/* 
 
 Immediate type instructions:
 
 ╔══════════╤═════════╤═════════╤══════════════════════════════════╗
 ║ opcode   │ rs      │ rt      │ immediate                        ║
 ╠══════════╪═════════╪═════════╪══════════════════════════════════╣
 ║ 31....26 │ 25...21 │ 20...16 │ 15.............................0 ║
 ╚══════════╧═════════╧═════════╧══════════════════════════════════╝


 Register type instructions:
 ╔══════════╤═════════╤═════════╤═════════╤════════╤═══════════════╗
 ║ opcode   │ rs      │ rt      │ rd      │ shamt  │ ALU function  ║
 ╠══════════╪═════════╪═════════╪═════════╪════════╪═══════════════╣
 ║ 31....26 │ 25...21 │ 20...16 │ 15...11 │ 10...6 │ 5...........0 ║
 ╚══════════╧═════════╧═════════╧═════════╧════════╧═══════════════╝

 
 J - type instructions:
 ╔══════════╤══════════════════════════════════════════════════════╗
 ║ opcode   │ target                                               ║
 ╠══════════╪══════════════════════════════════════════════════════╣
 ║ 31....26 │ 25.................................................0 ║
 ╚══════════╧══════════════════════════════════════════════════════╝
 
 Generated using: http://plaintexttools.github.io/plain-text-table
 
 Ref: Kane, Gerry (1988). MIPS RISC Architecture
 
*/




/* Field positions in MIPS instruction binaries */
#define OPCODE_POSITION_31_26       26
#define RS_ADDRESS_POSITION_25_21   21
#define RT_ADDRESS_POSITION_20_16   16
#define RD_ADDRESS_POSITION_15_11   11
#define SHAMT_POSITION_10_6          6

/* Opcodes */
#define ADD_IMM_WITH_OVERFLOW       0x08
#define ADD_IMM_WITHOUT_OVERFLOW    0x09
#define AND_IMM                     0x0C

/* Function codes */
#define SLL_FUNC                    0x00 // Added
#define SRL_FUNC                    0x02 // Added 
#define ADD_FUNC                    0x20
#define ADDU_FUNC                   0x21
#define AND_FUNC                    0x24
// Added
#define OR_FUNC                     0x25
#define XOR_FUNC                    0x26
#define NOR_FUNC                    0x27





class Decode
{
private:

    
    /*----------------------------------------------------------------*/
    /* FUNCTION: get_dest_register_addr                               */
    /*----------------------------------------------------------------*/
    /* Description: Get destination register
     
     Arguments: 1. MIPS instruction binary
     
     
     Returns:   Register rd address
     
     ------------------------------------------------------------------*/
    uint32_t get_dest_register_addr (uint32_t mips_instruction_binary);
    
    
    /*----------------------------------------------------------------*/
    /* FUNCTION: get_rd_value                                         */
    /*----------------------------------------------------------------*/
    /* Description: Extract destination register address rd from MIPS
     instruction binary and return value at that register
     
     Arguments: 1. MIPS instruction binary
     
     
     Returns:   Register value at rd register
     
     ------------------------------------------------------------------*/
    uint32_t get_rd_value (uint32_t mips_instruction_binary);
    
    
    /*----------------------------------------------------------------*/
    /* FUNCTION: get_rs_value                                         */
    /*----------------------------------------------------------------*/
    /* Description: Extract source register address rs from MIPS
     instruction binary and return value at that register
     
     Arguments: 1. MIPS instruction binary
     
     
     Returns:   Register value at rs register
     
     ------------------------------------------------------------------*/
    uint32_t get_rs_value (uint32_t mips_instruction_binary);
    
    
    /*----------------------------------------------------------------*/
    /* FUNCTION: get_rt_value                                         */
    /*----------------------------------------------------------------*/
    /* Description: Extract source register address rt from MIPS
     instruction binary and return value at that register
     
     Arguments: 1. MIPS instruction binary
     
     
     Returns:   Register value at rt register
     
     ------------------------------------------------------------------*/
    uint32_t get_rt_value (uint32_t mips_instruction_binary);
    
    
    
    /*----------------------------------------------------------------*/
    /* FUNCTION: get_shamt_value                                         */
    /*----------------------------------------------------------------*/
    /* Description: Extract the value of shamt and return it.
     
     Arguments: 1. MIPS instruction binary
     
     
     Returns:   shamt value
     ------------------------------------------------------------------*/
    uint32_t get_shamt_value (uint32_t mips_instruction_binary);
    
    
    
    /*----------------------------------------------------------------*/
    /* FUNCTION: get_imm                                              */
    /*----------------------------------------------------------------*/
    /* Description: Extract immediate operand from MIPS
     instruction binary
     
     Arguments: 1. MIPS instruction binary
     
     
     Returns:   Immediate operand
     
     ------------------------------------------------------------------*/
     uint16_t get_imm (uint32_t mips_instruction_binary);
    
    
    /*----------------------------------------------------------------*/
    /* FUNCTION: decode_opcode_0 (static)                             */
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
    uint8_t decode_opcode_0 (uint32_t mips_instruction_binary,
                             instruction_t* instruction,
                             uint32_t* operand1,
                             uint32_t* operand2,
                             uint32_t* operand3);

public:
    
    
    /*----------------------------------------------------------------*/
    /* FUNCTION: decode_instruction                                   */
    /*----------------------------------------------------------------*/
    /* Description: Decodes an opcode and returns instructions type
     along with the operand(s)
     
     Arguments: 1. MIPS instruction binary
     (Return)   2. Pointer to decoded instruction
     (Return)   3. Operand 1 (if applicable)
     (Return)   4. Operand 2 (if applicable)
     
     
     Returns:   Destination register
     
     ------------------------------------------------------------------*/
    uint8_t decode_instruction (uint32_t mips_instruction_binary,
                                instruction_t* instruction,
                                uint32_t* operand1,
                                uint32_t* operand2,
                                uint32_t* operand3);
    
    /*----------------------------------------------------------------*/
    /* FUNCTION: CONSTRUCTOR                                          */
    /*----------------------------------------------------------------*/
    /* Description: CONSTRUCTOR
     
     Arguments: None
     
     Returns:   None
     
     ------------------------------------------------------------------*/
    Decode (void);
};

#endif /* decode_h */

//
//  assembler.hpp
//  MIPS_sim
//
//  Created by Abhijeet Deshpande on 7/21/16.
//  Copyright © 2016 Poonam Deshpande. All rights reserved.
//

#ifndef assembler_hpp
#define assembler_hpp

#include <stdio.h>
#include <stdint.h>
#include "instructions.hpp"

#define ASM_FILE_PATH     "/Users/poonam/Desktop/mips_code.asm"
#define MACHINE_CODE_PATH "/Users/poonam/Desktop/machine_code.txt"

typedef enum
{
    REGISTER_TYPE  = 0,
    SHIFT_TYPE     = 1,
    IMMEDIATE_TYPE = 2,
    MAX_INSTRUCTION_TYPE
} instruction_type_t;

class Assembler
{
private:
    
    uint32_t opcode;
    uint32_t alu_function;
    uint32_t rd, rs, rt;
    uint32_t immediate;
    uint32_t shamt;
    
    /*----------------------------------------------------------------*/
    /* FUNCTION: identify_instruction                                 */
    /*----------------------------------------------------------------*/
    /* Description: Identify the instruction from a string mneumonic
     
     
     Arguments: Mneumonic string
     
     
     Returns:   Identified instruction
     
     ------------------------------------------------------------------*/
    instruction_t identify_instruction (char* instruction_mneumonic);

    /*----------------------------------------------------------------*/
    /* FUNCTION: pack_mips_binary                                     */
    /*----------------------------------------------------------------*/
    /* Description: Generate MIPS binary from the identified 
                    instruction
     
     
     Arguments: None
     
     
     Returns:   Packed MIPS binary
     
     ------------------------------------------------------------------*/
    uint32_t pack_mips_binary (instruction_type_t instruction_type);
    
public:

    /*----------------------------------------------------------------*/
    /* FUNCTION: load_data_section                                    */
    /*----------------------------------------------------------------*/
    /* Description: Loads RAM data into the data section of memory
     
     
     Arguments: None
     
     
     Returns:   None
     
     ------------------------------------------------------------------*/
    void load_data_section(void);
    
    /*----------------------------------------------------------------*/
    /* FUNCTION: load_text_section                                    */
    /*----------------------------------------------------------------*/
    /* Description: Loads assembly code into the text section of memory
     
     
     Arguments: None
     
     
     Returns:   None
     
     ------------------------------------------------------------------*/
    void load_text_section(void);


    /*----------------------------------------------------------------*/
    /* FUNCTION: CONSTRUCTOR                                          */
    /*----------------------------------------------------------------*/
    /* Description: CONSTRUCTOR
     
     Arguments: None
     
     Returns:   None
     
     ------------------------------------------------------------------*/
    Assembler (void);
};


#endif /* assembler_hpp */

//
//  memory.hpp
//  MIPS
//
//  Created by Poonam Deshpande on 6/21/16.
//  Copyright © 2016 Poonam Deshpande. All rights reserved.
//

#ifndef memory_hpp
#define memory_hpp

#include <stdio.h>
#include <stdint.h>

#define MAX_INSTRUCTION_MEMORY_SIZE  2048
#define MAX_DATA_MEMORY_SIZE         2048
#define MAX_EXCEPTION_MEMORY_SIZE    2048

class Memory
{
private:
    
    uint8_t instruction_memory[MAX_INSTRUCTION_MEMORY_SIZE];
    uint8_t data_memory[MAX_DATA_MEMORY_SIZE];
    uint8_t exception_memory[MAX_EXCEPTION_MEMORY_SIZE];

    
    /*----------------------------------------------------------------*/
    /* FUNCTION: translate_pc_addr                                    */
    /*----------------------------------------------------------------*/
    /* Description: Translate non pointer PC value to pointer that
                    that addresses the actual memory location in
                    the simulator
     
     Arguments: 1. Program counter value
     
     Returns:   Pointer to actual memory location in the simulator
     
     ------------------------------------------------------------------*/
    uint32_t* translate_pc_addr (uint32_t pc_value);
    
    /*----------------------------------------------------------------*/
    /* FUNCTION: translate_data_addr                                  */
    /*----------------------------------------------------------------*/
    /* Description: Translate non pointer memory address to pointer that
                    that addresses the actual memory location in
                    the simulator
     
     Arguments: 1. Data address
     
     Returns:   Pointer to actual memory location in the simulator
     
     ------------------------------------------------------------------*/
    uint32_t* translate_data_addr (uint32_t data_address);
    
    
public:
    
    /*----------------------------------------------------------------*/
    /* FUNCTION: fetch_instruction                                    */
    /*----------------------------------------------------------------*/
    /* Description: Fetches binary instruction from memory
     
     Arguments: 1. Program counter value
     
     Returns:   32 bit instruction binary at the location pointed by PC
     
     ------------------------------------------------------------------*/
    uint32_t fetch_instruction (uint32_t pc_value);
    
    
    /*----------------------------------------------------------------*/
    /* FUNCTION: write_data_to_memory                                 */
    /*----------------------------------------------------------------*/
    /* Description: Writes data to a specific location in the memory (in
                    data segment)
     
     Arguments: 1. Address in memory
                2. Value to write to memory
     
     Returns:   None
     
     ------------------------------------------------------------------*/
    void write_data_to_memory (uint32_t address, uint32_t value);

    
    /*----------------------------------------------------------------*/
    /* FUNCTION: write_instruction_to_memory                          */
    /*----------------------------------------------------------------*/
    /* Description: Writes to a specific location in the memory (in text
                    segment)
     
     Arguments: 1. Address in memory
                2. Value to write to memory
     
     Returns:   None
     
     ------------------------------------------------------------------*/
    void write_instruction_to_memory (uint32_t address, uint32_t value);

    
    /*----------------------------------------------------------------*/
    /* FUNCTION: CONSTRUCTOR                                          */
    /*----------------------------------------------------------------*/
    /* Description: CONSTRUCTOR
     
     Arguments: None
     
     Returns:   None
     
     ------------------------------------------------------------------*/
    Memory (void);
    
};

#endif /* memory_hpp */

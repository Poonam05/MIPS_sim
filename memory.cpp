//
//  memory.cpp
//  MIPS
//
//  Created by Poonam Deshpande on 6/21/16.
//  Copyright © 2016 Poonam Deshpande. All rights reserved.
//

#include "memory.hpp"

class Memory Memory_obj;

/*----------------------------------------------------------------*/
/* FUNCTION: translate_pc_addr                                    */
/*----------------------------------------------------------------*/
/* Description: Translate non pointer PC value to pointer that
                that addresses the actual memory location in
                the simulator
 
 Arguments: 1. Program counter value
 
 Returns:   Pointer to actual memory location in the simulator
 
 ------------------------------------------------------------------*/
uint32_t* Memory::translate_pc_addr (uint32_t pc_value)
{
    if (pc_value >= MAX_INSTRUCTION_MEMORY_SIZE)
    {
        /* TODO!!!!! Cause Program counter exception */
    }
    return ((uint32_t*)(&instruction_memory[0] + pc_value));

} /* translate_pc_addr */

/*----------------------------------------------------------------*/
/* FUNCTION: translate_data_addr                                  */
/*----------------------------------------------------------------*/
/* Description: Translate non pointer memory address to pointer that
                that addresses the actual memory location in
                the simulator
 
 Arguments: 1. Data address
 
 Returns:   Pointer to actual memory location in the simulator
 
 ------------------------------------------------------------------*/
uint32_t* Memory::translate_data_addr (uint32_t data_address)
{
    if (data_address >= MAX_DATA_MEMORY_SIZE)
    {
        /* TODO!!!!! Cause exception */
    }
    return (uint32_t*)(&data_memory[0] + data_address);

} /* translate_data_addr */

/*----------------------------------------------------------------*/
/* FUNCTION: fetch_instruction                                    */
/*----------------------------------------------------------------*/
/* Description: Fetches binary instruction from memory
 
 Arguments: 1. Program counter value
 
 Returns:   32 bit instruction binary at the location pointed by PC
 
 ------------------------------------------------------------------*/
uint32_t Memory::fetch_instruction (uint32_t pc_value)
{
    uint32_t* instruction_ptr;
    
    instruction_ptr = translate_pc_addr(pc_value);
    
    return *instruction_ptr;

} /* fetch_instruction */

/*----------------------------------------------------------------*/
/* FUNCTION: write_instruction_to_memory                          */
/*----------------------------------------------------------------*/
/* Description: Writes to a specific location in the memory (in text
 segment)
 
 Arguments: 1. Address in memory
            2. Value to write to memory
 
 Returns:   None
 
 ------------------------------------------------------------------*/
void Memory::write_instruction_to_memory (uint32_t address, uint32_t value)
{
    uint32_t* instruction_ptr;
    
    instruction_ptr = translate_pc_addr(address);
    
    *instruction_ptr = value;
    
} /* write_instruction_to_memory */

/*----------------------------------------------------------------*/
/* FUNCTION: write_data_to_memory                                 */
/*----------------------------------------------------------------*/
/* Description: Writes to a specific location in the memory (in data
                segment)
 
 Arguments: 1. Address in memory
            2. Value to write to memory
 
 Returns:   None
 
 ------------------------------------------------------------------*/
void Memory::write_data_to_memory (uint32_t address, uint32_t value)
{
    uint32_t* data_ptr;
    
    data_ptr = translate_data_addr(address);
    
    *data_ptr = value;

} /* write_data_to_memory */

/*----------------------------------------------------------------*/
/* FUNCTION: CONSTRUCTOR                                          */
/*----------------------------------------------------------------*/
/* Description: CONSTRUCTOR
 
 Arguments: None
 
 Returns:   None
 
 ------------------------------------------------------------------*/
Memory::Memory (void)
{


} /* Memory Constructor */
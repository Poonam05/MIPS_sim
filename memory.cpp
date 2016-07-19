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
    return (&instruction_memory[0] + pc_value);

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
    return (&data_memory[0] + data_address);

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
/* FUNCTION: write_to_memory                                      */
/*----------------------------------------------------------------*/
/* Description: Writes to a specific location in the memory
 
 Arguments: 1. Address in memory
            2. Value to write to memory
 
 Returns:   None
 
 ------------------------------------------------------------------*/
void Memory::write_to_memory (uint32_t address, uint32_t value)
{
    uint32_t* data_ptr;
    
    data_ptr = translate_data_addr(address);
    
    *data_ptr = value;

} /* write_to_memory */

/*----------------------------------------------------------------*/
/* FUNCTION: CONSTRUCTOR                                          */
/*----------------------------------------------------------------*/
/* Description: CONSTRUCTOR
 
 Arguments: None
 
 Returns:   None
 
 ------------------------------------------------------------------*/
Memory::Memory (void)
{
    /* TODO: REMOVE LATER Initialization to simulate an ADD instruction */
    /* ADD reg0, reg1, reg2 */
    instruction_memory[0] = 0x00 << 26;
    /* rs */
    instruction_memory[0] |= 0x01 << 21; // x= x or a
    /* rt */
    instruction_memory[0] |= 0x02 << 16;
    /* rd */
    instruction_memory[0] |= 0x00 << 11;
    /* func code */
    instruction_memory[0] |= 0x20;
    
    
    
    /* AND reg7, reg2, reg1 */
    instruction_memory[1] = 0x00 << 26;
    /* rs */
    instruction_memory[1] |= 0x01 << 21;
    /* rt */
    instruction_memory[1] |= 0x02 << 16;
    /* rd */
    instruction_memory[1] |= 0x07 << 11;
    /* func code */
    instruction_memory[1] |= 0x24;

    /* OR reg14, reg2, reg1 */
    instruction_memory[2] = 0x00 << 26;
    /* rs */
    instruction_memory[2] |= 0x01 << 21;
    /* rt */
    instruction_memory[2] |= 0x02 << 16;
    /* rd */
    instruction_memory[2] |= 0x0E << 11;
    /* func code */
    instruction_memory[2] |= 0x25;
    
    /* SRL reg14, reg2, reg1 */
    instruction_memory[3] = 0x00 << 26;
    /* rs */
    instruction_memory[3] |= 0x01 << 21;
    /* rt */
    instruction_memory[3] |= 0x02 << 16;
    /* rd */
    instruction_memory[3] |= 0x0E << 6;
    /* func code */
    instruction_memory[3] |= 0x02;
    
    /* XOR reg14, reg2, reg1 */
    instruction_memory[4] = 0x00 << 26;
    /* rs */
    instruction_memory[4] |= 0x01 << 21;
    /* rt */
    instruction_memory[4] |= 0x02 << 16;
    /* rd */
    instruction_memory[4] |= 0x0E << 11;
    /* func code */
    instruction_memory[4] |= 0x26;
    
    /* NOR reg0, reg1, reg2 */
    instruction_memory[5] = 0x00 << 26;
    /* rs */
    instruction_memory[5] |= 0x01 << 21;
    /* rt */
    instruction_memory[5] |= 0x02 << 16;
    /* rd */
    instruction_memory[5] |= 0x00 << 11;
    /* func code */
    instruction_memory[5] |= 0x27;

} /* Memory Constructor */
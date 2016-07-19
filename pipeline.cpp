//
//  pipeline.cpp
//  MIPS
//
//  Created by Poonam Deshpande on 6/19/16.
//  Copyright © 2016 Poonam Deshpande. All rights reserved.
//

#include "pipeline.hpp"
#include "fetch.hpp"
#include "decode.hpp"
#include "memory.hpp"
#include "execute.hpp"
#include "writeback.hpp"
#include "report.hpp"

class        Pipeline  Pipeline_obj;
extern class Fetch     Fetch_obj;
extern class Decode    Decode_obj;
extern class Execute   Execute_obj;
extern class Memory    Memory_obj;
extern class Writeback Writeback_obj;
extern class Report    Report_obj;


/*----------------------------------------------------------------*/
/* FUNCTION: pipeline_fetch_instruction                           */
/*----------------------------------------------------------------*/
/* Description: Fetches an opcode pointed to by the program
 counter
 
 Arguments: None
 
 
 Returns:   Binary instruction
 
 ------------------------------------------------------------------*/
uint32_t Pipeline::pipeline_fetch_instruction (void)
{
    uint32_t mips_instruction_binary;
    
    printf ("FETCH: Start\n");
    mips_instruction_binary = Fetch_obj.fetch_next_instruction();
    
    printf ("FETCH: MIPS binary instruction 0x%x\n", mips_instruction_binary);
    printf ("FETCH: End\n");
    return mips_instruction_binary;

} /* pipeline_fetch_instruction */

/*----------------------------------------------------------------*/
/* FUNCTION: pipeline_decode_instruction                          */
/*----------------------------------------------------------------*/
/* Description: Decodes an opcode and returns instructions type
 along with the operand(s)
 
 Arguments: 1. MIPS instruction binary
 (Return)   2. Pointer to decoded instruction
 (Return)   3. Operand 1 (if applicable)
 (Return)   4. Operand 2 (if applicable)
 (Return)   5. Operand 3 (if applicable)
 
 
 Returns:   Destination register (8 bit)
 
 ------------------------------------------------------------------*/
uint8_t Pipeline::pipeline_decode_instruction (uint32_t mips_instruction_binary,
                                  
                                               /* Decoded instruction */
                                               instruction_t* instruction,
                                  
                                               /* Writeable operand */
                                               uint32_t* operand1,
                                  
                                               /* Read only operand */
                                               uint32_t* operand2,
                                  
                                               /* Read only operand */
                                               uint32_t* operand3)
{
    uint32_t decoded_instruction;
    
    printf ("DECODE: Start\n");
    
    /* Decode instruction */
    decoded_instruction = Decode_obj.decode_instruction(mips_instruction_binary, instruction, operand1, operand2, operand3);

    printf ("DECODE: Instruction: %d\n", decoded_instruction);
    printf ("DECODE: End\n");
    
    return decoded_instruction;

} /* pipeline_decode_instruction */

/*----------------------------------------------------------------*/
/* FUNCTION: pipeline_execute_instruction                         */
/*----------------------------------------------------------------*/
/* Description: Executes the instruction and returns computed
 result
 
 Arguments: 1. Decoded instruction
            2. Operand 1
            3. Operand 2 (if applicable)
            4. Operand 3 (if applicable)
 
 
 Returns:   32 bit computed value
 
 
 ------------------------------------------------------------------*/
uint32_t Pipeline::pipeline_execute_instruction (instruction_t instruction,
                                       
                                                 /* Read only operand */
                                                 uint32_t operand2,
                                       
                                                 /* Read only operand */
                                                 uint32_t operand3,
                                                 
                                                 bool* is_mem_write_valid,
                                                 
                                                 bool* is_writeback_valid)
{
    uint32_t computed_result;
    
    printf ("EXECUTE: Start\n");
    
    computed_result = Execute_obj.execute_instruction (instruction, operand2, operand3, is_mem_write_valid, is_writeback_valid);
    
    if (instruction < MAX_INSTRUCTION_T)
    {
        printf ("EXECUTE: Result = %d\n", computed_result);
    }
    else
    {
        printf ("EXECUTE: Invalid Instuction\n");
    }
    printf ("EXECUTE: End\n");
    
    
    return computed_result;

} /* pipeline_execute_instruction */

/*----------------------------------------------------------------*/
/* FUNCTION: pipeline_memory_write                                */
/*----------------------------------------------------------------*/
/* Description: Writes a value to memory
 
 Arguments: 1. Memory Address
            2. Value
 
 
 Returns:   None
 
 
 ------------------------------------------------------------------*/
                                      /* Address to write at */
void Pipeline::pipeline_memory_write (uint32_t address,
                                
                                      /* Value to write */
                                      uint32_t value)
{
    printf ("MEM WRITE: Start\n");
    printf ("MEM WRITE: Write 0x%x @ 0x%x", value, address);
    
    Memory_obj.write_to_memory(address, value);
    printf ("MEM WRITE: End\n");

} /* pipeline_memory_write */

/*----------------------------------------------------------------*/
/* FUNCTION: pipeline_writeback                                   */
/*----------------------------------------------------------------*/
/* Description: Writes a value to a register
 
 Arguments: 1. Register to write to
            2. Value
 
 
 Returns:   None
 
 
 ------------------------------------------------------------------*/
                                   /* Register to write to */
void Pipeline::pipeline_writeback (uint8_t reg_addr,
                                          
                                   /* Value to write */
                                   uint32_t value)
{
    printf ("WRITEBACK: Start\n");
    /* Ensure a valid register is accessed */
    if (reg_addr < 32)
    {
        Writeback_obj.writeback_to_register(reg_addr, value);
        
        printf("WRITEBACK: Write %d to register %d\n", value, reg_addr);
    }
    printf ("WRITEBACK: End\n");

} /* pipeline_writeback */

/*----------------------------------------------------------------*/
/* FUNCTION: run_pipeline                                         */
/*----------------------------------------------------------------*/
/* Description: Runs pipeline
 
 Arguments: None
 
 
 Returns:   None
 
 
 ------------------------------------------------------------------*/
void Pipeline::run_pipeline (uint32_t cycle_count)
{

    /* TODO: Add a while loop here to loop through the list of instructions
             in memory and stop only at a halt instruction */
    
    /******************************************************************/
    /*                           FETCH STAGE                          */
    /******************************************************************/
    
    /* Fetch instruction from memory */
    pipe_fetch_ptr->mips_instruction_binary = pipeline_fetch_instruction ();
    

    /******************************************************************/
    /*                           DECODE STAGE                         */
    /******************************************************************/
    
    
    /* Decode fetched instruction */
    pipe_decode_ptr->destination_register = pipeline_decode_instruction (pipe_decode_ptr->mips_instruction_binary,
                                                                         &pipe_decode_ptr->instruction,
                                                                         &pipe_decode_ptr->operand1,
                                                                         &pipe_decode_ptr->operand2,
                                                                         &pipe_decode_ptr->operand3);

    /******************************************************************/
    /*                           EXECUTE STAGE                        */
    /******************************************************************/
    
    /* Execute decoded instruction */
    pipe_execute_ptr->computed_result = pipeline_execute_instruction(pipe_execute_ptr->instruction,
                                                                     pipe_execute_ptr->operand2,
                                                                     pipe_execute_ptr->operand3,
                                                                     &pipe_execute_ptr->is_mem_write_valid,
                                                                     &pipe_execute_ptr->is_writeback_valid);
    
    /******************************************************************/
    /*                        MEMORY WRITE STAGE                      */
    /******************************************************************/
    
    /* Typically store instructions are executed in this stage. The first operand
       is typically the value and the second operand is the offset */
    if (pipe_mem_write_ptr->is_mem_write_valid)
    {
        pipeline_memory_write(pipe_mem_write_ptr->operand2, pipe_mem_write_ptr->operand1);
    }
    
    /******************************************************************/
    /*                         WRITEBACK STAGE                        */
    /******************************************************************/
    
    /* Writeback the result to destination register */
    if (pipe_writeback_ptr->is_writeback_valid)
    {
        pipeline_writeback(pipe_writeback_ptr->destination_register,
                           pipe_writeback_ptr->computed_result);
    }
    
    /* Append status to the report after current cycle. Here, "1" is added
       to cycle count, so that cycle counting starts from 1 in the report */
    Report_obj.write_status_to_report_cycle(cycle_count + 1);
    
    increment_pipe ();
    
} /* run_pipeline */

/*----------------------------------------------------------------*/
/* FUNCTION: increment_pipe                                       */
/*----------------------------------------------------------------*/
/* Description: Increments the pointers to circular buffer such that
                all relevant pointers point to next instruction
                to operate on
 
 Arguments: None
 
 
 Returns:   None
 
 
 ------------------------------------------------------------------*/
void Pipeline::increment_pipe (void)
{
    /* Increment the pipe pointers such that new data for each stage is from
       the previous stage, i.e. DECODE STAGE gets the data from FETCh stage
       and so on. The FETCH stage points to an empty location for the new
       instruction fetch */

    class Pipe* temp;
    
    temp               = pipe_fetch_ptr;
    pipe_fetch_ptr     = pipe_writeback_ptr;
    pipe_writeback_ptr = pipe_mem_write_ptr;
    pipe_mem_write_ptr = pipe_execute_ptr;
    pipe_execute_ptr   = pipe_decode_ptr;
    pipe_decode_ptr    = temp;
    

    
    /* Invalidate fetch members */
    pipe_fetch_ptr->initialize_pipe();
    
} /* increment_pipe */

/*----------------------------------------------------------------*/
/* FUNCTION: CONSTRUCTOR                                          */
/*----------------------------------------------------------------*/
/* Description: CONSTRUCTOR
 
 Arguments: None
 
 Returns:   None
 
 ------------------------------------------------------------------*/
Pipeline::Pipeline (void)
{
    /* Initialize circular buffer pointers to point to each member in the
     pipe structure */
    pipe_fetch_ptr     = &Pipe_obj[0];
    pipe_decode_ptr    = &Pipe_obj[1];
    pipe_execute_ptr   = &Pipe_obj[2];
    pipe_mem_write_ptr = &Pipe_obj[3];
    pipe_writeback_ptr = &Pipe_obj[4];
    
} /* Pipeline Constructor */


/*----------------------------------------------------------------*/
/* FUNCTION: CONSTRUCTOR                                          */
/*----------------------------------------------------------------*/
/* Description: CONSTRUCTOR
 
 Arguments: None
 
 Returns:   None
 
 ------------------------------------------------------------------*/
Pipe::Pipe (void)
{

    /* Initialize private members with invalid values */
    
    initialize_pipe ();

} /* Pipe Constructor */

/*----------------------------------------------------------------*/
/* FUNCTION: increment_pipe                                       */
/*----------------------------------------------------------------*/
/* Description: Increments the pointers to circular buffer such that
 all relevant pointers point to next instruction
 to operate on
 
 Arguments: None
 
 
 Returns:   None
 
 
 ------------------------------------------------------------------*/
void Pipe::initialize_pipe (void)
{
    /* Initialize pipe structure */
    
    /* Invalidate fetch members */
    instruction = MAX_INSTRUCTION_T;
    mips_instruction_binary = 0xFFFFFFFF;
    operand1 = 0xFFFFFFFF;
    operand2 = 0xFFFFFFFF;
    operand3 = 0xFFFFFFFF;
    destination_register = 0xFF;
    is_mem_write_valid = 0;
    is_writeback_valid = 0;
    
} /* increment_pipe */

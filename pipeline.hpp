//
//  pipeline.hpp
//  MIPS
//
//  Created by Poonam Deshpande on 6/19/16.
//  Copyright © 2016 Poonam Deshpande. All rights reserved.
//

#ifndef pipeline_hpp
#define pipeline_hpp

#include <stdio.h>
#include "registers.hpp"
#include "decode.hpp"
#include "report.hpp"
#include "instructions.hpp"

#define PIPE_DEPTH 5

/* R2000 5-stage Instruction Pipeline
 
 ╔═════╤═════╤═════╤═════╤═════╤═════╤═════╤═════╤═════╗
 ║ IF. │ RD. │ ALU │ MEM │ WB. │     │     │     │     ║
 ╠═════╪═════╪═════╪═════╪═════╪═════╪═════╪═════╪═════╣
 ║     │ IF. │ RD. │ ALU │ MEM │ WB. │     │     │     ║
 ╟─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────╢
 ║     │     │ IF. │ RD. │ ALU │ MEM │ WB. │     │     ║
 ╟─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────╢
 ║     │     │     │ IF. │ RD. │ ALU │ MEM │ WB. │     ║
 ╟─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────╢
 ║     │     │     │     │ IF. │ RD. │ ALU │ MEM │ WB. ║
 ╚═════╧═════╧═════╧═════╧═════╧═════╧═════╧═════╧═════╝
 
 Generated using: http://plaintexttools.github.io/plain-text-table
 
 Ref: Kane, Gerry (1988). MIPS RISC Architecture
 
*/
 

/* This class stores the instructions that have been enqueued in the pipeline.
   A circular queue structure is used access each pipeline position */
class Pipe
{
    /* Befriend the parent class Pipeline to allow it to access
       the private members of this class */
    friend class Pipeline;
    
    /* Befriend class Report to allow it to tap into the Pipe
       structure and print the report */
    friend class Report;

    
    Pipe (void);
    
private:
    
    uint32_t next_pc_value;
    uint32_t mips_instruction_binary;

    instruction_t instruction;
    uint32_t operand1;
    uint32_t operand2;
    uint32_t operand3;

    uint32_t computed_result;
    
    bool is_mem_write_valid;
    uint32_t mem_write_addr;
    uint32_t mem_write_value;
    
    bool is_writeback_valid;
    /* Store destination register, since this is lost after instruction decode */
    uint8_t destination_register;

    void initialize_pipe (void);
    
};

class Pipeline
{
    
private:
    
    class Pipe* pipe_fetch_ptr;
    class Pipe* pipe_decode_ptr;
    class Pipe* pipe_execute_ptr;
    class Pipe* pipe_mem_write_ptr;
    class Pipe* pipe_writeback_ptr;
    
    /* Instantiate 5 pipe objects to create a pipeline of depth 5 */
    class Pipe Pipe_obj[PIPE_DEPTH];
    
    /* Befriend class Report to allow it to tap into the Pipe
       structure and print the report */
    friend class Report;

    
    /*----------------------------------------------------------------*/
    /* FUNCTION: pipeline_fetch_instruction                           */
    /*----------------------------------------------------------------*/
    /* Description: Fetches next instruction to be executed
     
     Arguments: None
     
     
     Returns:   Binary instruction
     
     ------------------------------------------------------------------*/
    uint32_t pipeline_fetch_instruction (void);
    
    
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
     
     
     Returns:   None
     
     ------------------------------------------------------------------*/
    uint8_t pipeline_decode_instruction (uint32_t mips_instruction_binary,
                             
                                         /* Decoded instruction */
                                         instruction_t* instruction,
                             
                                         /* Writeable operand */
                                         uint32_t* operand1,
                             
                                         /* Read only operand */
                                         uint32_t* operand2,
                             
                                         /* Read only operand */
                                         uint32_t* operand3);

    /*----------------------------------------------------------------*/
    /* FUNCTION: pipeline_execute_instruction                         */
    /*----------------------------------------------------------------*/
    /* Description: Executes the instruction and returns computed
                    result
     
     Arguments: 1. Decoded instruction
                2. Operand 2 (if applicable)
                3. Operand 3 (if applicable)
     
     
     Returns:   32 bit computed value

     
     ------------------------------------------------------------------*/
                                           /* Decoded instruction */
    uint32_t pipeline_execute_instruction (instruction_t instruction,
                              
                                           /* Read only operand */
                                           uint32_t operand2,
                              
                                           /* Read only operand */
                                           uint32_t operand3,
                                           
                                           bool* is_mem_write_valid,
                                           
                                           bool* is_writeback_valid);
    
    /*----------------------------------------------------------------*/
    /* FUNCTION: pipeline_memory_write                                */
    /*----------------------------------------------------------------*/
    /* Description: Writes a value to memory
     
     Arguments: 1. Memory Address
                2. Value
     
     
     Returns:   None
     
     
     ------------------------------------------------------------------*/
                                /* Address to write at */
    void pipeline_memory_write (uint32_t address,
                                              
                                /* Value to write */
                                uint32_t value);
    
    /*----------------------------------------------------------------*/
    /* FUNCTION: pipeline_writeback                                   */
    /*----------------------------------------------------------------*/
    /* Description: Writes a value to a register
     
     Arguments: 1. Register to write to
                2. Value
     
     
     Returns:   None
     
     
     ------------------------------------------------------------------*/
                             /* Register to write to */
    void pipeline_writeback (uint8_t reg_addr,
                                       
                             /* Value to write */
                             uint32_t value);

    /*----------------------------------------------------------------*/
    /* FUNCTION: increment_pipe                                       */
    /*----------------------------------------------------------------*/
    /* Description: Increments the pointers to circular buffer such that
                    all relevant pointers point to next instruction
                    to operate on
     
     Arguments: None
     
     
     Returns:   None
     
     
     ------------------------------------------------------------------*/
    void increment_pipe (void);
    
    
public:
    
    /*----------------------------------------------------------------*/
    /* FUNCTION: CONSTRUCTOR                                          */
    /*----------------------------------------------------------------*/
    /* Description: CONSTRUCTOR
     
     Arguments: None
     
     Returns:   None
     
     ------------------------------------------------------------------*/
    Pipeline (void);
    
    
    /*----------------------------------------------------------------*/
    /* FUNCTION: run_pipeline                                         */
    /*----------------------------------------------------------------*/
    /* Description: Runs pipeline
     
     Arguments: Current cycle count (for report generation only, 
                no functional significance)
     
     
     Returns:   None
     
     
     ------------------------------------------------------------------*/
    void run_pipeline (uint32_t cycle_count);
    

    
};

#endif /* pipeline_hpp */

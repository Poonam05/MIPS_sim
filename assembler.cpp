//
//  assembler.cpp
//  MIPS_sim
//
//  Created by Poonam Deshpande on 7/21/16.
//  Copyright © 2016 Poonam Deshpande. All rights reserved.
//

#include "assembler.hpp"
#include <stdio.h>
#include <string.h>
/* Function exit () is under stdlib.h */
#include <stdlib.h>
#include "decode.hpp"
#include "memory.hpp"

class        Assembler Assembler_obj;
extern class Memory    Memory_obj;

/*----------------------------------------------------------------*/
/* FUNCTION: load_data_section                                    */
/*----------------------------------------------------------------*/
/* Description: Loads RAM data into the data section of memory
 
 
 Arguments: None
 
 
 Returns:   None
 
 ------------------------------------------------------------------*/
void Assembler::load_data_section(void)
{
    return;
}

/*----------------------------------------------------------------*/
/* FUNCTION: load_text_section                                    */
/*----------------------------------------------------------------*/
/* Description: Loads assembly code into the text section of memory
 
 
 Arguments: None
 
 
 Returns:   None
 
 ------------------------------------------------------------------*/
void Assembler::load_text_section(void)
{
    char               instruction_mneumonic[8];
    char               arg1[12], arg2[12], arg3[12];
    instruction_type_t instruction_type = MAX_INSTRUCTION_TYPE;
    uint32_t           mips_instruction_binary;
    FILE*              asm_fp;
    FILE*              machine_code_fp;
    
    /* Counts the number of instructions read */
    uint32_t           instruction_count = 0;
    
    asm_fp = fopen (ASM_FILE_PATH, "r");
    machine_code_fp = fopen (MACHINE_CODE_PATH, "w+");
    
    while (1)
    {
        /* Read instruction from asm file */
        fscanf (asm_fp,"%s %s %s %s\n", instruction_mneumonic, arg1, arg2, arg3);

        switch (identify_instruction(instruction_mneumonic))
        {
            case ADD:
            case ADDU:
            case SUB:
            case SUBU:
            case AND:
            case OR:
            case XOR:
            case NOR:
                opcode = 0;
                instruction_type = REGISTER_TYPE;
                rd = atoi (arg1);
                rs = atoi (arg2);
                rt = atoi (arg3);
                break;
            case SLL:
            case SRL:
            case SLLV:
            case SRAV:
            case SLT:
            case SLTU:
                opcode = 0;
                instruction_type = SHIFT_TYPE;
                rd    = atoi (arg1);
                rt    = atoi (arg2);
                shamt = atoi (arg3);
                break;
            case ADDI:
            case ADDIU:
            case ANDI:
            case ORI:
            case XORI:
            case SLTI:
            case SLTIU:
                instruction_type = IMMEDIATE_TYPE;
                rt        = atoi(arg1);
                rs        = atoi (arg2);
                immediate = atoi (arg3);
                break;
            case LB:
            case LBU:
            case LH:
            case LHU:
            case LW:
            case SB:
            case SH:
            case SW:
                instruction_type = IMMEDIATE_TYPE;
                rt        = atoi (arg1);
                immediate = atoi (arg2);
                rs        = atoi (arg3);
                break;
            case BEQ:
            case BNE:
            case BLTZ:
            case BGEZ:
            case BLTZAL:
            case BGEZAL:
            case BLEZ:
            case BGTZ:
                break;
                
                
            case LUI:
                break;
            case J:
            case JAL:
                instruction_type = JUMP_TYPE;
                target        = atoi(arg1);
                break;
            default:
                printf ("Invalid instruction in asm file %s\n", instruction_mneumonic);
                exit (1);
        }
        mips_instruction_binary = pack_mips_binary (instruction_type);
        Memory_obj.write_instruction_to_memory(instruction_count, mips_instruction_binary);
        fprintf (machine_code_fp, "0x%8X\n", mips_instruction_binary);
        instruction_count++;

        /* Break out of while loop at EOF */
        if (feof(asm_fp))
        {
            break;
        }

    }
    
    fclose (asm_fp);
    fclose (machine_code_fp);
}

/*----------------------------------------------------------------*/
/* FUNCTION: identify_instruction                                 */
/*----------------------------------------------------------------*/
/* Description: Identify the instruction from a string mneumonic
 
 
 Arguments: Mneumonic string
 
 
 Returns:   Identified instruction
 
 ------------------------------------------------------------------*/
instruction_t Assembler::identify_instruction(char* instruction_mneumonic)
{
    instruction_t identified_instruction = MAX_INSTRUCTION_T;
    
    if (!strcmp (instruction_mneumonic, "ADD"))
    {
        identified_instruction = ADD;
        alu_function = ADD_FUNC;
    }
    else if (!strcmp (instruction_mneumonic, "ADDU"))
    {
        identified_instruction = ADDU;
        alu_function = ADDU_FUNC;
    }
    else if (!strcmp (instruction_mneumonic, "SUB"))
    {
        identified_instruction = SUB;
        alu_function = SUB_FUNC;
    }
    else if (!strcmp (instruction_mneumonic, "SUBU"))
    {
        identified_instruction = SUBU;
        alu_function = SUBU_FUNC;
    }
    else if (!strcmp (instruction_mneumonic, "AND"))
    {
        identified_instruction = AND;
        alu_function = AND_FUNC;
    }
    else if (!strcmp (instruction_mneumonic, "OR"))
    {
        identified_instruction = OR;
        alu_function = OR_FUNC;
    }
    else if (!strcmp (instruction_mneumonic, "XOR"))
    {
        identified_instruction = XOR;
        alu_function = XOR_FUNC;
    }
    else if (!strcmp (instruction_mneumonic, "NOR"))
    {
        identified_instruction = NOR;
        alu_function = NOR_FUNC;
    }
    else if (!strcmp (instruction_mneumonic, "SLL"))
    {
        identified_instruction = SLL;
        alu_function = SLL_FUNC;
    }
    else if (!strcmp (instruction_mneumonic, "SRL"))
    {
        identified_instruction = SRL;
        alu_function = SRL_FUNC;
    }
    else if (!strcmp (instruction_mneumonic, "SLLV"))
    {
        identified_instruction = SLLV;
        alu_function = SLLV_FUNC;
    }
    else if (!strcmp (instruction_mneumonic, "SRAV"))
    {
        identified_instruction = SRAV;
        alu_function = SRAV_FUNC;
    }
    else if (!strcmp (instruction_mneumonic, "SLT"))
    {
        identified_instruction = SLT;
        alu_function = SLT_FUNC;
    }
    else if (!strcmp (instruction_mneumonic, "SLTU"))
    {
        identified_instruction = SLTU;
        alu_function = SLTU_FUNC;
    }
    else if (!strcmp (instruction_mneumonic, "ADDI"))
    {
        identified_instruction = ADDI;
        opcode = 0x08;
    }
    else if (!strcmp (instruction_mneumonic, "ADDIU"))
    {
        identified_instruction = ADDIU;
        opcode = 0x09;
    }
    else if (!strcmp (instruction_mneumonic, "ANDI"))
    {
        identified_instruction = ANDI;
        opcode = 0x0C;
    }
    else if (!strcmp (instruction_mneumonic, "ORI"))
    {
        identified_instruction = ORI;
        opcode = 0x0D;
    }
    else if (!strcmp (instruction_mneumonic, "XORI"))
    {
        identified_instruction = XORI;
        opcode = 0x0E;
    }
    else if (!strcmp (instruction_mneumonic, "SLTI"))
    {
        identified_instruction = SLTI;
        opcode = 0x0A;
    }
    else if (!strcmp (instruction_mneumonic, "SLTIU"))
    {
        identified_instruction = SLTIU;
        opcode = 0x0B;
    }
    else if (!strcmp (instruction_mneumonic, "LUI"))
    {
        identified_instruction = LUI;
        opcode = 0x0F;
    }
    else if (!strcmp (instruction_mneumonic, "LB"))
    {
        identified_instruction = LB;
        opcode = 0x20;
    }
    else if (!strcmp (instruction_mneumonic, "LBU"))
    {
        identified_instruction = LBU;
        opcode = 0x24;
    }
    else if (!strcmp (instruction_mneumonic, "LH"))
    {
        identified_instruction = LH;
        opcode = 0x21;
    }
    else if (!strcmp (instruction_mneumonic, "LHU"))
    {
        identified_instruction = LHU;
        opcode = 0x25;
    }
    else if (!strcmp (instruction_mneumonic, "LW"))
    {
        identified_instruction = LW;
        opcode = 0x23;
    }
    else if (!strcmp (instruction_mneumonic, "SB"))
    {
        identified_instruction = SB;
        opcode = 0x28;
    }
    else if (!strcmp (instruction_mneumonic, "SH"))
    {
        identified_instruction = SH;
        opcode = 0x29;
    }
    else if (!strcmp (instruction_mneumonic, "SW"))
    {
        identified_instruction = SW;
        opcode = 0x2B;
    }
    else if (!strcmp(instruction_mneumonic, "J"))
    {
        identified_instruction = J;
        opcode = 0x02;
    }
    else if (!strcmp(instruction_mneumonic, "JAL"))
    {
        identified_instruction = JAL;
        opcode = 0x03;
    }
    else
    {
        printf ("Instruction string not found\n");
        exit (1);
    }

    printf ("[%s] Identified instruction = %d\n", instruction_mneumonic, identified_instruction);

    return identified_instruction;
}

/*----------------------------------------------------------------*/
/* FUNCTION: pack_mips_binary                                     */
/*----------------------------------------------------------------*/
/* Description: Generate MIPS binary from the identified
 instruction
 
 
 Arguments: None
 
 
 Returns:   Packed MIPS binary
 
 ------------------------------------------------------------------*/
uint32_t Assembler::pack_mips_binary (instruction_type_t instruction_type)
{
    uint32_t mips_instruction_binary;

    
    mips_instruction_binary = (opcode << 26);

    switch (instruction_type)
    {
        case REGISTER_TYPE:
            mips_instruction_binary |= alu_function;
            mips_instruction_binary |= (rs << 21);
            mips_instruction_binary |= (rt << 16);
            mips_instruction_binary |= (rd << 11);
            break;
        
        case SHIFT_TYPE:
            mips_instruction_binary |= alu_function;
            mips_instruction_binary |= (rt << 16);
            mips_instruction_binary |= (rd << 11);
            mips_instruction_binary |= (shamt << 6);
            break;
        case IMMEDIATE_TYPE:
            mips_instruction_binary |= (rs << 21);
            mips_instruction_binary |= (rt << 16);
            mips_instruction_binary |= immediate;
            break;
        case JUMP_TYPE:
            mips_instruction_binary |= (rs << 21);
            mips_instruction_binary |= (rt << 16);
            mips_instruction_binary |= immediate;
            break;
        case MAX_INSTRUCTION_TYPE:
        default:
            printf ("Bad instruction type %d", instruction_type);
            exit(1);
    }
    
    return mips_instruction_binary;
}

/*----------------------------------------------------------------*/
/* FUNCTION: CONSTRUCTOR                                          */
/*----------------------------------------------------------------*/
/* Description: CONSTRUCTOR
 
 Arguments: None
 
 Returns:   None
 
 ------------------------------------------------------------------*/
Assembler::Assembler()
{
    
}

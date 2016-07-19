//
//  instructions.hpp
//  MIPS
//
//  Created by Poonam Deshpande on 6/25/16.
//  Copyright © 2016 Poonam Deshpande. All rights reserved.
//

#ifndef instructions_h
#define instructions_h

typedef enum
{
    
    /*=============================================================================*/
    /* ADD                                                           ADD, rd, rs, rt
     
       Add contents of registers rs and rt and place 32-bit result in register rd.
     
       Trap on two's complement overflow.
    */
    /*=============================================================================*/
    ADD = 0, // Done

    
    /*=============================================================================*/
    /* ADD Unsigned                                                 ADDU, rd, rs, rt
     
       Add contents of registers rs and rt and place 32-bit result in register rd.
     
       Do not trap on overflow.
    */
    /*=============================================================================*/
    ADDU = 1,

    /*=============================================================================*/
    /* ADD Immediate                                         ADDI, rt, rs, immediate
     
       Add 16-bit sign-extended immediate to register rs and place 32-bit result
       in register rt.
     
       Do not trap on overflow
    */
    /*=============================================================================*/
    ADDI = 2,


    /*=============================================================================*/
    /* Add Immediate Unsigned                                ADDIU rt, rs, immediate

       Add 16-bit sign-extended immediate to register rs and place 32-bit result
       in register rt.
     
     Trap on two's complement overflow
    */
    /*=============================================================================*/
    ADDIU = 3,


    /*=============================================================================*/
    /* Subtract                                                      SUB, rd, rs, rt
     
       Subtract contents of registers rt from rs and place 32-bit result in 
       register rd.
     
       Trap on two's complement overflow.
    */
    /*=============================================================================*/
    SUB = 4,
    

    /*=============================================================================*/
    /* Subtract Unsigned                                            SUBU, rd, rs, rt
     
       Subtract contents of registers rt from rs and place 32-bit result in
       register rd.
     
       Do not trap on overflow.
    */
    /*=============================================================================*/
    SUBU = 5,
    

    /*=============================================================================*/
    /* Set on Less Than                                               SLT rd, rs, rt

       Compare contents of registers rt to rs (as signed 32-bit integers).
       If register rs is less than rt, result = 1; otherwise result = 0.
    */
    /*=============================================================================*/
    SLT = 6,
    

    /*=============================================================================*/
    /* Set on Less Than Unsigned                                     SLTU rd, rs, rt

       Compare contents of registers rt to rs (as unsigned 32-bit integers).
       If register rs is less than rt, result = 1; otherwise result = 0.
    */
    /*=============================================================================*/
    SLTU = 7,
    
    
    /*=============================================================================*/
    /* Set on Less Than Immediate                             SLTI rt, rs, immediate

     Compare 16-bit sign-extended immediate with register rs as signed 32-bit
     integers. Result = 1 if rs is less than immediate; otherwise result = 0.
     Place result in register rt.
    */
    /*=============================================================================*/
    SLTI = 8,


    /*=============================================================================*/
    /* Set on Less Than Unsigned Immediate                   SLTIU rt, rs, immediate

       Compare 16-bit sign-extended immediate with register rs as unsigned 32-bit
       integers. Result = 1 if rs is less than immediate; otherwise result = 0.
       Place result in register rt.
    */
    /*=============================================================================*/
    SLTIU = 9,


    /*=============================================================================*/
    /* AND                                                            AND rd, rs, rt

       Bitwise AND contents of registers rs and rt and place the result in rd.
    */
    /*=============================================================================*/
    AND = 10, // Done 
    
    
    /*=============================================================================*/
    /* AND Immediate                                          ANDI rt, rs, immediate

       Zero-extend 16-bit immediate, AND with contents of register rs and place the
       result in register rt.
    */
    /*=============================================================================*/
    ANDI = 11,

    
    /*=============================================================================*/
    /* OR                                                              OR rd, rs, rt

       Bitwise OR contents of registers rs and rt and place the result in rd.
    */
    /*=============================================================================*/
    OR = 12, //Done
    

    /*=============================================================================*/
    /* OR Immediate                                            ORI rt, rs, immediate

       Zero-extend 16-bit immediate, OR with contents of register rs and place the
       result in register rt.
    */
    /*=============================================================================*/
    ORI = 13,

    
    /*=============================================================================*/
    /* XOR                                                            XOR rd, rs, rt

       Bitwise exclusive OR contents of registers rs and rt and place the result in 
       rd.
    */
    /*=============================================================================*/
    XOR = 14, //Done
    
    
    /*=============================================================================*/
    /* XOR Immediate                                          XORI rt, rs, immediate

       Zero-extend 16-bit immediate, exclusive OR with contents of register rs and
       place the result in register rt.
    */
    /*=============================================================================*/
    XORI = 15,

    
    
    /*=============================================================================*/
    /* NOR                                                            NOR rd, rs, rt

       Bitwise NOR contents of registers rs and rt and place the result in
       rd.
    */
    /*=============================================================================*/
    NOR = 16, //Done

    
    /*=============================================================================*/
    /* Load Upper Immediate                                        LUI rt, immediate

       Shift 16-bit immediate left 16 bits. Set least significant 16 bits of word
       to zeroes. Store results in register rt.
    */
    /*=============================================================================*/
    LUI = 17,

    
    
    /*=============================================================================*/
    /* Shift Left Logical                                          SLL rd, rt, shamt

       Shift contents of register rt left by shamt bits, inserting zeros into low
       order bits. Place 32-bit result in register rd.
    */
    /*=============================================================================*/
    SLL = 18, //Done 

    
    
    /*=============================================================================*/
    /* Shift Right Logical                                         SRL rd, rt, shamt

       Shift contents of register rt left by shamt bits, inserting zeros into low
       order bits. Place 32-bit result in register rd.
    */
    /*=============================================================================*/
    SRL = 19, //Done 

    
    /*=============================================================================*/
    /* Shift Right Arithmatic                                      SRA rd, rt, shamt

       Shift contents of register rt right by shamt bits, sign-extending the high
       order bits. Place 32-bit result in register rd.
    */
    /*=============================================================================*/
    SRA = 20,

    
    /*=============================================================================*/
    /* Shift Left Logical Variable                                   SLLV rd, rt, rs

       Shift contents of register rt left. Low-order 5 bits of register rs
       specify number of bits to shift. Insert zeros into high order bits of rt and
       place 32-bit result in register rd.
    */
    /*=============================================================================*/
    SLLV = 21,

    
    /*=============================================================================*/
    /* Shift Right Arithmatic Variable                               SRAV rd, rt, rs

       Shift contents of register rt right. Low-order 5 bits of register rs
       specify number of bits to shift. Sign-extend the high order bits of rt and
       place 32-bit result in register rd.
    */
    /*=============================================================================*/
    SRAV = 22,

    
    /*=============================================================================*/
    /* Multiply                                                          MULT rs, rt

       Multiply contents of registers rs and rt as twos complement values. Place 
       64-bit result in special registers HI/LO
    */
    /*=============================================================================*/
    MULT = 23,
    

    /*=============================================================================*/
    /* Multiply Unsigned                                                MULTU rs, rt

       Multiply contents of registers rs and rt as unsigned values. Place
       64-bit result in special registers HI/LO
    */
    /*=============================================================================*/
    MULTU = 24,

    
    /*=============================================================================*/
    /* Divide                                                             DIV rs, rt

       Divide contents of registers rs by rt treating operands as twos
       complements values. Place 32-bit quotient in special register LO, and 32-bit
       remainder in HI.
    */
    /*=============================================================================*/
    DIV = 25,


    /*=============================================================================*/
    /* Divide Unsigned                                                   DIVU rs, rt

       Divide contents of registers rs by rt treating operands as unsigned values. 
       Place 32-bit quotient in special register LO, and 32-bit remainder in HI.
    */
    /*=============================================================================*/
    DIVU = 26,

    
    /*=============================================================================*/
    /* Move from HI                                                          MFHI rd
     
       Move contents of special register HI to register rd.
    */
    /*=============================================================================*/
    MFHI = 27,

    
    /*=============================================================================*/
    /* Move from LO                                                          MFLO rd
     
       Move contents of special register LO to register rd.
    */
    /*=============================================================================*/
    MFLO = 28,
    
    
    /*=============================================================================*/
    /* Move to HI                                                            MTHI rd
     
       Move contents of register rd to special register HI.
    */
    /*=============================================================================*/
    MTHI = 29,

    
    /*=============================================================================*/
    /* Move to LO                                                            MTLO rd
     
       Move contents of register rd to special register LO.
    */
    /*=============================================================================*/
    MTLO = 30,

    
    /*=============================================================================*/
    /* Load Byte                                                 LB rt, offset(base)
     
       Sign-extend 16-bit offset and add to contents of register base to form 
       address. Sign-extend contents of addressed byte and load into rt.
    */
    /*=============================================================================*/
    LB = 31,

    
    /*=============================================================================*/
    /* Load Byte Unsigned                                       LBU rt, offset(base)
     
       Sign-extend 16-bit offset and add to contents of register base to form 
       address. Sign-extend contents of addressed byte and load into rt.
    */
    /*=============================================================================*/
    LBU = 32,

    
    
    /*=============================================================================*/
    /* Load Halfword                                             LH rt, offset(base)
     
       Sign-extend 16-bit offset and add to contents of register base to form 
       address. Sign-extend contents of addressed halfword and load into rt.
    */
    /*=============================================================================*/
    LH = 33,

    
    /*=============================================================================*/
    /* Load Halfword Unsigned                                   LHU rt, offset(base)
     
       Sign-extend 16-bit offset and add to contents of register base to form 
       address. Sign-extend contents of addressed halfword and load into rt.
    */
    /*=============================================================================*/
    LHU = 34,

    
    /*=============================================================================*/
    /* Load Word                                                 LW rt, offset(base)
     
       Sign-extend 16-bit offset and add to contents of register base to form 
       address. Sign-extend contents of addressed word and load into rt.
    */
    /*=============================================================================*/
    LW = 35,

    
    /*=============================================================================*/
    /* Load Word Left                                           LWL rt, offset(base)
     
       Sign-extend 16-bit offset and add to contents of register base to form 
       address. Shift addressed word left so that addressed byte is leftmost byte
       of a word. Merge bytes from memory with contents of register rt and load
       result into register rt.
    */
    /*=============================================================================*/
    LWL = 36,


    /*=============================================================================*/
    /* Load Word Right                                          LWR rt, offset(base)
     
       Sign-extend 16-bit offset and add to contents of register base to form 
       address. Shift addressed word left so that addressed byte is rightmost byte
       of a word. Merge bytes from memory with contents of register rt and load
       result into register rt.
    */
    /*=============================================================================*/
    LWR = 37,

    
    /*=============================================================================*/
    /* Store Byte                                                SB rt, offset(base)
     
       Sign-extend 16-bit offset and add to contents of register base to form 
       address. Store least significant byte of register rt at addressed
       location.
    */
    /*=============================================================================*/
    SB = 38,
    
    
    /*=============================================================================*/
    /* Store Halfword                                            SH rt, offset(base)
     
       Sign-extend 16-bit offset and add to contents of register base to form 
       address. Store least significant halfword of register rt at addressed
       location.
    */
    /*=============================================================================*/
    SH = 39,


    /*=============================================================================*/
    /* Store Word                                                SW rt, offset(base)
     
       Sign-extend 16-bit offset and add to contents of register base to form 
       address. Store least significant word of register rt at addressed
       location.
    */
    /*=============================================================================*/
    SW = 40,


    /*=============================================================================*/
    /* Store Word Left                                          SWL rt, offset(base)
     
       Sign-extend 16-bit offset and add to contents of register base to form 
       address. Shift contents of register rt left so that leftmost byte of the word
       is in position of addressed byte. Store bytes containing original data into
       corresponding bytes at addressed byte.
    */
    /*=============================================================================*/
    SWL = 41,


    /*=============================================================================*/
    /* Store Word Right                                         SWR rt, offset(base)
     
       Sign-extend 16-bit offset and add to contents of register base to form 
       address. Shift contents of register rt right so that leftmost byte of the word
       is in position of addressed byte. Store bytes containing original data into
       corresponding bytes at addressed byte.
    */
    /*=============================================================================*/
    SWR = 42,



    /*=============================================================================*/
    /* Jump                                                                 J target
     
       Shift 26-bit target address left two bits, combine with high order 4 bits of
       PC and jump to address with a one instruction delay.
    */
    /*=============================================================================*/
    J = 43,
    


    /*=============================================================================*/
    /* Jump and Link                                                      JAL target
     
       Shift 26-bit target address left two bits, combine with high order 4 bits of
       PC and jump to address witha one instruction delay. Place address of
       instruction following delay slot in r31 (link register).
    */
    /*=============================================================================*/
    JAL = 44,



    /*=============================================================================*/
    /* Jump Register                                                           JR rs
     
       Jump to address contained in register rs with a one instruction delay.
    */
    /*=============================================================================*/
    JR = 45,


    /*=============================================================================*/
    /* Jump And Link Register                                            JALR rs, rd
     
       Jump to address contained in register rs with a one instruction delay. Place
       address of instruction following delay slot in rd.
    */
    /*=============================================================================*/
    JALR = 46,
    

    /*=============================================================================*/
    /* Branch Target Computation:
     
       All Branch instruction target addresses are computer as follows:
    
       Add address of instruction in delay slot and the 16-bit offset (shifted left
       two bits and sign-extended to 32-bits). All branches occur with a delay of
       one instruction.
    */
    /*=============================================================================*/

    
    /*=============================================================================*/
    /* Branch on Equal                                            BEQ rs, rt, offset
     
       Branch to target address if register rs = rt.
    */
    /*=============================================================================*/
    BEQ = 47,

    
    /*=============================================================================*/
    /* Branch on Not Equal                                        BNE rs, rt, offset
     
       Branch to target address if register rs != rt.
    */
    /*=============================================================================*/
    BNE = 48,
    
    /*=============================================================================*/
    /* Branch on Less than or Equal Zero                         BLEZ rs, rt, offset
     
       Branch to target address if register rs <= 0.
    */
    /*=============================================================================*/
    BLEZ = 49,

    
    /*=============================================================================*/
    /* Branch on Greater than                                        BGTZ rs, offset
     
       Branch to target address if register rs > 0.
    */
    /*=============================================================================*/
    BGTZ = 50,

    
    /*=============================================================================*/
    /* Branch on Less than                                           BLTZ rs, offset
     
       Branch to target address if register rs < 0.
    */
    /*=============================================================================*/
    BLTZ = 51,

    
    /*=============================================================================*/
    /* Branch on Greater than Equal Zero                             BGEZ rs, offset
     
       Branch to target address if register rs >= 0.
    */
    /*=============================================================================*/
    BGEZ = 52,


    /*=============================================================================*/
    /* Branch on Less than Zero and Link                           BLTZAL rs, offset
     
       Place address of instruction following delay slot in register r31 (link
       register). Branch to target address if register rs < 0.
    */
    /*=============================================================================*/
    BLTZAL = 53,


    /*=============================================================================*/
    /* Branch on Greater than or Equal Zero and Link               BLTZAL rs, offset
     
       Place address of instruction following delay slot in register r31 (link
       register). Branch to target address if register rs >= 0.
    */
    /*=============================================================================*/
    BGEZAL = 54,


    /*=============================================================================*/
    /* System Call                                                           SYSCALL
     
       Initiates system call trap, immediately transferring control to 
       exception handler.
    */
    /*=============================================================================*/
    SYSCALL = 55,


    /*=============================================================================*/
    /* Breakpoint                                                              BREAK
     
       Initiates breakpoint trap, immediately transferring control to exception 
       handler.
    */
    /*=============================================================================*/
    BREAK = 56,


    /*=============================================================================*/
    /* No Operation                                                              NOP
     
       No operation
     */
    /*=============================================================================*/
    NOP = 57,
    
    
    MAX_INSTRUCTION_T
} instruction_t;

/*
 Ref: Kane, Gerry (1988). MIPS RISC Architecture
*/

#endif /* instructions_h */

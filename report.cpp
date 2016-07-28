//
//  report.cpp
//  MIPS
//
//  Created by Poonam Deshpande on 6/22/16.
//  Copyright © 2016 Poonam Deshpande. All rights reserved.
//

#include "report.hpp"
#include "registers.hpp"
#include "pipeline.hpp"

class Report Report_obj;
extern class Register_file Register_file_obj;
extern class Pipeline      Pipeline_obj;

/*----------------------------------------------------------------*/
/* FUNCTION: write_decoded_instruction_string                     */
/*----------------------------------------------------------------*/
/* Description: Prints instruction string
 
 Arguments: 1.Instruction number defined in the decode enum

 
 Returns:   None
 
------------------------------------------------------------------*/
void Report::write_decoded_instruction_string (instruction_t instruction_num)
{
    fprintf (report_fp, "<b>DECODE:</b> Instruction: <font color=\"");
    switch (instruction_num)
    {
        case ADD:
            fprintf (report_fp, "red\">ADD r(%d) <- %d + %d",
                     Pipeline_obj.pipe_decode_ptr->destination_register,
                     Pipeline_obj.pipe_decode_ptr->operand2,
                     Pipeline_obj.pipe_decode_ptr->operand3);
            break;
        case ADDU:
            fprintf (report_fp, "red\">ADDU r(%d) <- %d + %d",
                     Pipeline_obj.pipe_decode_ptr->destination_register,
                     Pipeline_obj.pipe_decode_ptr->operand2,
                     Pipeline_obj.pipe_decode_ptr->operand3);
            break;
        case AND:
            fprintf (report_fp, "red\">AND r(%d) <- %d & %d",
                     Pipeline_obj.pipe_decode_ptr->destination_register,
                     Pipeline_obj.pipe_decode_ptr->operand2,
                     Pipeline_obj.pipe_decode_ptr->operand3);
            break;
            
         case OR:
            fprintf (report_fp, "red\">OR r(%d) <- %d | %d",
                     Pipeline_obj.pipe_decode_ptr->destination_register,
                     Pipeline_obj.pipe_decode_ptr->operand2,
                     Pipeline_obj.pipe_decode_ptr->operand3);
            break;
            
         case XOR:
            fprintf (report_fp, "red\">XOR r(%d) <- %d ^ %d",
                     Pipeline_obj.pipe_decode_ptr->destination_register,
                     Pipeline_obj.pipe_decode_ptr->operand2,
                     Pipeline_obj.pipe_decode_ptr->operand3);
            break;
            
        case NOR:
            fprintf (report_fp, "red\">NOR r(%d) <- %d NOR %d",
                     Pipeline_obj.pipe_decode_ptr->destination_register,
                     Pipeline_obj.pipe_decode_ptr->operand2,
                     Pipeline_obj.pipe_decode_ptr->operand3);
            break;
            
            
        case SRL:
            fprintf (report_fp, "red\">SRL r(%d) <- %d >> %d",
                     Pipeline_obj.pipe_decode_ptr->destination_register,
                     Pipeline_obj.pipe_decode_ptr->operand2,
                     Pipeline_obj.pipe_decode_ptr->operand3);
            break;
            
            
        case SLL:
            fprintf (report_fp, "red\">SLL r(%d) <- %d << %d",
                     Pipeline_obj.pipe_decode_ptr->destination_register,
                     Pipeline_obj.pipe_decode_ptr->operand2,
                     Pipeline_obj.pipe_decode_ptr->operand3);
            break;
            
            
        case MAX_INSTRUCTION_T:
            fprintf (report_fp, "black\">MAX_INSTRUCTION");
            break;
        default:
            fprintf (report_fp, "red\">ERROR: Invalid Instruction Reported!");
    }
    fprintf (report_fp, "</font>");
} /* write_decoded_instruction_string */

/*----------------------------------------------------------------*/
/* FUNCTION: write_executed_instruction_string                    */
/*----------------------------------------------------------------*/
/* Description: Prints executed instruction string and computed
                value
 
 Arguments: 1.Instruction number defined in the decode enum
 
 
 Returns:   None
 
 ------------------------------------------------------------------*/
void Report::write_executed_instruction_string (instruction_t instruction_num)
{
    fprintf (report_fp, "<b>EXECUTE:</b> Instruction: <font color=\"");
    switch (instruction_num)
    {
        case ADD:
            fprintf (report_fp, "red\">ADD, Computed result = %d", Pipeline_obj.pipe_execute_ptr->computed_result);
            break;
        case ADDU:
            fprintf (report_fp, "red\">ADDU, Computed result = %d", Pipeline_obj.pipe_execute_ptr->computed_result);
            break;
        case AND:
            fprintf (report_fp, "red\">AND, Computed result = %d", Pipeline_obj.pipe_execute_ptr->computed_result);
            break;
        case OR:
            fprintf (report_fp, "red\">OR, Computed result = %d", Pipeline_obj.pipe_execute_ptr->computed_result);
            break;
        case XOR:
            fprintf (report_fp, "red\">XOR, Computed result = %d", Pipeline_obj.pipe_execute_ptr->computed_result);
            break;
        case NOR:
            fprintf (report_fp, "red\">NOR, Computed result = %d", Pipeline_obj.pipe_execute_ptr->computed_result);
            break;
        case SRL:
            fprintf (report_fp, "red\">SRL, Computed result = %d", Pipeline_obj.pipe_execute_ptr->computed_result);
            break;
        case SLL:
            fprintf (report_fp, "red\">SLL, Computed result = %d", Pipeline_obj.pipe_execute_ptr->computed_result);
            break;

        case J:
            
            fprintf (report_fp, "red\">SLL, Computed result = %d", Pipeline_obj.pipe_execute_ptr->computed_result);
            break;

            
        case MAX_INSTRUCTION_T:
            fprintf (report_fp, "black\">MAX_INSTRUCTION");
            break;
        default:
            fprintf (report_fp, "red\">ERROR: Invalid Instruction Reported!");
    }
    fprintf (report_fp, "</font>");
    
} /* write_executed_instruction_string */

/*----------------------------------------------------------------*/
/* FUNCTION: write_header_to_report                               */
/*----------------------------------------------------------------*/
/* Description: Writes header to the report
 
 Arguments: None
 
 Returns:   None
 
------------------------------------------------------------------*/
void Report::write_header_to_report (void)
{

    fprintf (report_fp, "<html>\n");
    fprintf (report_fp, "<body>\n");
    fprintf (report_fp, "<h2>MIPS Simulator Report</h2>\n");

    HTML_LINE_BREAK;
    
    
} /* write_header_to_report */

/*----------------------------------------------------------------*/
/* FUNCTION: write_status_to_report_cycle                         */
/*----------------------------------------------------------------*/
/* Description: Write current cycle information to the report
 
 Arguments: 1. Cycle count
 
 Returns:   None
 
------------------------------------------------------------------*/
void Report::write_status_to_report_cycle (uint32_t cycle)
{
    uint8_t i = 0, j;
    fprintf (report_fp, "<h2>Cycle %d</h2>\n", cycle);

    
    /******************************************************************/
    /*                           FETCH STAGE                          */
    /******************************************************************/
    
    fprintf (report_fp, "<b>FETCH:</b> Instruction binary: 0x%08X\n", Pipeline_obj.pipe_fetch_ptr->mips_instruction_binary);
    HTML_LINE_BREAK;
    
    /******************************************************************/
    /*                           DECODE STAGE                         */
    /******************************************************************/
    
    write_decoded_instruction_string (Pipeline_obj.pipe_decode_ptr->instruction);
    HTML_LINE_BREAK;
    
    /******************************************************************/
    /*                           EXECUTE STAGE                        */
    /******************************************************************/
    
    write_executed_instruction_string (Pipeline_obj.pipe_execute_ptr->instruction);
    HTML_LINE_BREAK;

    /******************************************************************/
    /*                        MEMORY WRITE STAGE                      */
    /******************************************************************/
    
    if (Pipeline_obj.pipe_mem_write_ptr->is_mem_write_valid)
    {
        fprintf (report_fp, "<b>MEMORY WRITE:</b> <font color=\"red\">Write 0x%08X at memory address 0x%08X\n</font>",
                 Pipeline_obj.pipe_mem_write_ptr->mem_write_value,
                 Pipeline_obj.pipe_mem_write_ptr->mem_write_addr);
    }
    else
    {
        fprintf (report_fp, "<b>MEMORY WRITE:</b> No memory write");
    }
    HTML_LINE_BREAK;
    
    /******************************************************************/
    /*                         WRITEBACK STAGE                        */
    /******************************************************************/

    if (Pipeline_obj.pipe_writeback_ptr->is_writeback_valid)
    {
        fprintf (report_fp, "<b>WRITEBACK:</b> <font color=\"red\">Write 0x%08X to register %d</font>",
                 Pipeline_obj.pipe_writeback_ptr->computed_result,
                 Pipeline_obj.pipe_writeback_ptr->destination_register);
    }
    else
    {
        fprintf (report_fp, "<b>WRITEBACK:</b> No register writeback");
    }
    HTML_LINE_BREAK;

    /******************************************************************/
    /*                         REGISTER FILE                          */
    /******************************************************************/

    fprintf (report_fp, "<h3>Register File</h3>\n");
    
    /* Print rows */
    for (j = 0;j < 8; j++)
    {
        fprintf(report_fp, "<b><font face=\"courier\" size = \"2\" color=\"black\">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;%d&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</font></b>", j);
    }
    HTML_LINE_BREAK;
    
    for (i = 0;i < 4; i++)
    {
        /* Print Columns */
        fprintf(report_fp, "<b><font face=\"courier\" size = \"2\" color=\"black\">%02d: </font></b>", i * 8);
        
        for (j = 0;j < 8; j++)
        {
            if (reg_modified_cycle[i*8+j])
            {
                fprintf(report_fp, "<font face=\"courier\" size = \"2\" color=\"red\">0x%08X </font>", Register_file_obj.reg[i*8+j]);
                
                /* Reset the modified bit for this register */
                reg_modified_cycle[i*8+j] = 0;
            }
            else
            {
                fprintf(report_fp, "<font face=\"courier\" size = \"2\" color=\"black\">0x%08X </font>", Register_file_obj.reg[i*8+j]);
            }
        }
        HTML_LINE_BREAK;
    }

} /* write_status_to_report_cycle */

/*----------------------------------------------------------------*/
/* FUNCTION: set_modified_reg_cycle                               */
/*----------------------------------------------------------------*/
/* Description: Updates register status
 
 Arguments: 1. Register Address
 
 Returns:   None
 
------------------------------------------------------------------*/
void Report::set_modified_reg_cycle (uint8_t reg_addr)
{
    reg_modified_cycle[reg_addr] = 1;

} /* set_modified_reg_cycle */

/*----------------------------------------------------------------*/
/* FUNCTION: CONSTRUCTOR                                          */
/*----------------------------------------------------------------*/
/* Description: CONSTRUCTOR
 
 Arguments: None
 
 Returns:   None
 
 ------------------------------------------------------------------*/
Report::Report (void)
{
    
    report_fp = fopen (REPORT_PATH, "w+");
    
}

/*----------------------------------------------------------------*/
/* FUNCTION: write_end_to_report                                  */
/*----------------------------------------------------------------*/
/* Description: Writes ending delimiters to the report and closes
                the file
 
 Arguments: None
 
 Returns:   None
 
 ------------------------------------------------------------------*/
void Report::write_end_to_report (void)
{
    
    fprintf (report_fp, "</body>\n");
    fprintf (report_fp, "</html>\n");
    fclose (report_fp);
    
} /* write_end_to_report */


/*----------------------------------------------------------------*/
/* FUNCTION: DESTRUCTOR                                           */
/*----------------------------------------------------------------*/
/* Description: DESTRUCTOR
 
 Arguments: None
 
 Returns:   None
 
 ------------------------------------------------------------------*/
Report::~Report (void)
{

    fprintf (report_fp, "</body>\n");
    fprintf (report_fp, "</html>\n");
    fclose (report_fp);
    
}

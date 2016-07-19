//
//  report.hpp
//  MIPS
//
//  Created by Poonam Deshpande on 6/22/16.
//  Copyright © 2016 Poonam Deshpande. All rights reserved.
//

#ifndef report_hpp
#define report_hpp

#include <stdio.h>
#include <stdint.h>
#include "decode.hpp"

#define REPORT_PATH     "/Users/poonam/Desktop/report.html"
#define HTML_LINE_BREAK fprintf(report_fp,"<br>\n")

class Report
{
private:
    
    /* Marks registers modified in the current cycle */
    bool reg_modified_cycle[32];
    
    /* HTML report file pointer */
    FILE* report_fp;

    
    /*----------------------------------------------------------------*/
    /* FUNCTION: write_decoded_instruction_string                     */
    /*----------------------------------------------------------------*/
    /* Description: prints instruction string
    ------------------------------------------------------------------*/
    void write_decoded_instruction_string (instruction_t instruction_num);
    
    /*----------------------------------------------------------------*/
    /* FUNCTION: write_executed_instruction_string                    */
    /*----------------------------------------------------------------*/
    /* Description: prints instruction string
     ------------------------------------------------------------------*/
    void write_executed_instruction_string (instruction_t instruction_num);
    
public:
    

    /*----------------------------------------------------------------*/
    /* FUNCTION: write_header_to_report                               */
    /*----------------------------------------------------------------*/
    /* Description: Writes header to the report
    ------------------------------------------------------------------*/
    void write_header_to_report (void);
    
    /*----------------------------------------------------------------*/
    /* FUNCTION: set_modified_reg_cycle                               */
    /*----------------------------------------------------------------*/
    /* Description: Updates register status
    ------------------------------------------------------------------*/
    void set_modified_reg_cycle (uint8_t reg_addr);

    
    /*----------------------------------------------------------------*/
    /* FUNCTION: write_status_to_report_cycle                         */
    /*----------------------------------------------------------------*/
    /* Description: Write current cycle information to the report
    ------------------------------------------------------------------*/
    void write_status_to_report_cycle (uint32_t cycle);
    

    /*----------------------------------------------------------------*/
    /* FUNCTION: write_end_to_report                                  */
    /*----------------------------------------------------------------*/
    /* Description: Writes ending delimiters to the report and closes
     the file
    ------------------------------------------------------------------*/
    void write_end_to_report (void);
    
    
    /*----------------------------------------------------------------*/
    /* FUNCTION: CONSTRUCTOR                                          */
    /*----------------------------------------------------------------*/
    /* Description: CONSTRUCTOR
    ------------------------------------------------------------------*/
    Report (void);
    
    
    /*----------------------------------------------------------------*/
    /* FUNCTION: DESTRUCTOR                                           */
    /*----------------------------------------------------------------*/
    /* Description: DESTRUCTOR
    ------------------------------------------------------------------*/
    ~Report (void);
    
};





#endif /* report_hpp */

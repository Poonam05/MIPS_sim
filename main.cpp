//
//  main.cpp
//  MIPS
//
//  Created by Poonam Deshpande on 6/5/16.
//  Copyright © 2016 Poonam Deshpande. All rights reserved.
//

#include <stdio.h>
#include "main.hpp"
#include "pipeline.hpp"
#include "report.hpp"

extern class Pipeline Pipeline_obj;
extern class Report   Report_obj;

int main(int argc, const char * argv[])
{
    uint8_t i;

    Report_obj.write_header_to_report();
    for (i  = 0; i < 10; i++)
    {
        Pipeline_obj.run_pipeline (i);
    }
    
    Report_obj.write_end_to_report();
    
    return 0;

} /* main */


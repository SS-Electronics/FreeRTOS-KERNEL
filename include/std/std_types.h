/* Copyright (C) 2024 Sourav Dey
# This file is part of openAUTOSAR/BSW
#
# openAUTOSAR free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# RTOS Basic Software is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
*/


#ifndef STD_TYPES_H
#define STD_TYPES_H

/*Standard Library includes*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>


#if defined(STM32F401)
#include "../../arch/ARM/CMSIS_6/CMSIS/Core/Include/cmsis_compiler.h"
#endif






/*Typedefs*/
typedef int32_t                	Std_ReturnType;
typedef uint8_t                	boolean;



typedef uint32_t				dma_addr_t;








/* STD Definitions */
#define STD_FALSE               (0)
#define STD_TRUE                (1)

#define STD_HIGH		        (1)
#define STD_LOW			        (0)

#define STD_ACTIVE		        (1)
#define STD_IDLE		        (0)

#define STD_ON			        (1)
#define STD_OFF			        (0)


/*
 * Error Definitions 
 */
#define ERROR_NONE              (0) 
#define ERROR_NULL_PTR          ((Std_ReturnType)-1)
#define ERROR_INVALID_PARM      ((Std_ReturnType)-2)
#define ERROR_TIMEOUT           ((Std_ReturnType)-3)














#endif
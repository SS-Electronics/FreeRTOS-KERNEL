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

/* Global defines*/

# define FALSE                 0x00
# define TRUE                  0x01

#define STD_HIGH		       0x01
#define STD_LOW			       0x00

#define STD_ACTIVE		       0x01
#define STD_IDLE		       0x00

#define STD_ON			       0x01
#define STD_OFF			       0x00

#define KERNEL_OK 			   0x00u
#define KERNEL_ERR 			   (Std_ReturnType)-1

#define MEM_OP_OK			   0
#define MEM_OP_FAIL	   		   (Std_ReturnType)-1
#define MEM_OP_NULL_PTR		   (Std_ReturnType)-2


#endif
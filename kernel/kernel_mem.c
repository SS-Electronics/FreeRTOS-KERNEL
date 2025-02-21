/*
 * File:        kernel_mem.c
 * Author:      Subhajit Roy  
 *              subhajitroy005@gmail.com 
 *
 * Moudle:      Modeule Kernel [ Local Build ] 
 * Info:        Kernel Memory allocation definition
 *                            
 * Dependency:  None
 *
 * This file is part of FreeRTOS-KERNEL Project.
 *
 * FreeRTOS-KERNEL is free software: you can redistribute it and/or 
 * modify it under the terms of the GNU General Public License 
 * as published by the Free Software Foundation, either version 
 * 3 of the License, or (at your option) any later version.
 *
 * FreeRTOS-KERNEL is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the 
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License 
 *along with FreeRTOS-KERNEL. If not, see <https://www.gnu.org/licenses/>.
 */

 #include "kernel_mem.h"



void * kmalloc(size_t size)
{
	void *ret = NULL;

	ret = malloc(size);
	
	return ret;
}

int32_t kfree(void *p)
{
    if(p != NULL)
    {
        free(p);
        return MEM_OP_OK;
    }
    else
    {
        return MEM_OP_NULL_PTR;
    }
}




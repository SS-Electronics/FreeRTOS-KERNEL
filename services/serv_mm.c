/*
 * File:        serv_mm.c
 * Author:      Subhajit Roy  
 *              subhajitroy005@gmail.com 
 *
 * Moudle:      Modeule services [ Local Build ] 
 * Info:        memory management services and initialization
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
#include "serv_mm.h"






const HeapRegion_t xHeapRegions[] =  
{  
    { ( uint8_t * ) 0x20004000UL, 0x2800 }, 
    { NULL, 0 } /* Terminates the array. */  
};  




void proc_mm_init(void * arg)
{
    /* Heap memeory initialize */
    /* Pass the array into vPortDefineHeapRegions(). */  
    vPortDefineHeapRegions( xHeapRegions );
}









void vApplicationStackOverflowHook( TaskHandle_t xTask, char * pcTaskName )
{
    for( ; ; )
    {
    }
}

void vApplicationMallocFailedHook( void )
{

    while(1)
    {

    }
}
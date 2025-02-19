/*
 * File:        kernel_thread.c
 * Author:      Subhajit Roy  
 *              subhajitroy005@gmail.com 
 *
 * Moudle:      Modeule Kernel [ Local Build ] 
 * Info:        Kernel Threads definitions
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

 #include "kernel_thread.h"


static uint32_t     thread_counter = 0;


 
 Std_ReturnType  theread_create( type_thread_function thread_function, 
                                type_thread_struct * thread_handle,
                                uint32_t stack_depth_bytes,
                                uint32_t priority,
                                const char * const task_info_str,
                                void       * parameters)
{
        BaseType_t  returned =  xTaskCreate( thread_function,
                                task_info_str,
                                stack_depth_bytes,
                                parameters,
                                (UBaseType_t)priority,
                                &(thread_handle->thread_handle) );
        if( returned == pdPASS)
        {
            thread_handle->thread_id            = thread_counter++;
            return thread_counter;
        }
        else
        {
            return THEREAD_CREATE_FAILED;
        }  
}

 
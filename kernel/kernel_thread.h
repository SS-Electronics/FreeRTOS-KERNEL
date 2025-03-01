/*
 * File:        kernel_thread.h
 * Author:      Subhajit Roy  
 *              subhajitroy005@gmail.com 
 *
 * Moudle:      Modeule Kernel [ Local Build ] 
 * Info:        Kernel Threads implementation
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

 #ifndef __KERNEL_THREAD_H__
 #define __KERNEL_THREAD_H__

#include "../../FreeRTOS-KERNEL-conf/FreeRTOSConfig.h"
#include "../include/std/std_types.h"
#include "../../FreeRTOS-KERNEL-conf/OsConfig.h"
#include "./FreeRTOS-Kernel/include/FreeRTOS.h"
#include "./FreeRTOS-Kernel/include/task.h"
#include "./FreeRTOS-Kernel/include/atomic.h"


#include "kernel_thread_info.h"




#define SET_THREAD_PRIO_PRIV(prio)      ((prio)>(configMAX_PRIORITIES) ? (0) : (prio | portPRIVILEGE_BIT))
#define SET_THREAD_PRIO_UNPRIV(prio)    ((prio)>(configMAX_PRIORITIES) ? (0) : (prio ))

/**
 * struct thread_info Thread meta information
 * @flags:			    Unique Identifiers of the theread [ Non Zero val ]
 * @ fpu_state: 		FPU State
 */
typedef struct  
{
   uint32_t		flags;		/* low level flags */
   uint32_t		fpu_state;	/* see fpu.h */
}type_thread_info;



/**
 * struct thread_struct Thread Descriptors for task management
 * @thread_id:			Unique Identifiers of the theread [ Non Zero val ]
 * @ TaskHandle_t: 		Theread Handle of freeRTOS
 * @child_thread_ptr:   Pointer to the forked child struct
 * @current_cpu:		Current Execution cpu
 * @preempt_value:  	1 => preemptable, 0 => NON
 * @stack: 		        Thread Stackpointer
 */
typedef struct
{
    uint32_t                    thread_id;
    TaskHandle_t                thread_handle;
    type_thread_info            thread_info;
    uint32_t                    current_cpu;
    int32_t			            preempt_value; 
    void                        *stack;
}type_thread_struct;









typedef void (* type_thread_function )( void * arg );


 
 
 #ifdef __cplusplus
 extern "C" {
 #endif
 
 
Std_ReturnType  theread_create( type_thread_function thread_function, 
                                type_thread_struct * thread_handle,
                                uint32_t stack_depth_bytes,
                                uint32_t priority,
                                const char * const task_info_str,
                                void       * parameters);
 
 
 
 
 
 
 #ifdef __cplusplus
 }
 #endif










 #endif //__KERNEL_THREAD_H__
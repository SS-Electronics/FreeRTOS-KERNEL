/*
 * File:        main.c
 * Author:      Subhajit Roy  
 *              subhajitroy005@gmail.com 
 *
 * Moudle:      Modeule init [ Local Build ] 
 * Info:        Entry Point
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

#include "main.h"


type_irq_desc * local_desc;


void systick_cb(void * des)
{

}

static void exampleTask( void * parameters ) __attribute__( ( noreturn ) );


void task_1(void * arg)
{
    int * ptr = arg;

    while(1)
    {

    }
}

int a = 30;

type_thread_struct thread_1;


int main(void)
{
    /*
     Initialize services 
     */
    proc_mm_init(NULL);
    proc_serial_mgmt_init();
    
    
    /* 
     * Initialize kernel 
     */
    /* initilize interrupts */
    

   

    int id = theread_create(&task_1, &thread_1, 128, 1, "hello", &thread_1);

#if (__ARM_ARCH_7A__ == 0U)
	/* Service Call interrupt might be configured before kernel start     */
	/* and when its priority is lower or equal to BASEPRI, svc intruction */
	/* causes a Hard Fault.                                               */
	//NVIC_SetPriority (SVCall_IRQn, 0U);
#endif


    vTaskStartScheduler();

    while(1)
    {
        a++;   
    }
    return 0;
}


void vApplicationDaemonTaskStartupHook( void )
{

}
/*
 * File:        serv_diagnostics_mgmt.c
 * Author:      Subhajit Roy  
 *              subhajitroy005@gmail.com 
 *
 * Moudle:      Modeule services [ Local Build ] 
 * Info:        Diagnostics management
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

#include "serv_diagnostics_mgmt.h"


void cb_sys_hardfault( void * parm )
{
    int a= 30;
}

void cb_sys_busfault( void * parm )
{
    int a= 30;
}

void cb_sys_usagefault( void * parm )
{
    int a= 30;
}












 void proc_diagnostic_mgmt_init(void * arg)
 {
    Std_ReturnType status = ERROR_NONE;
    type_irq_desc* temp;

    /* register callbacks  */
    temp = register_hw_cb(KERN_IRQ_SYS_HARDFAULT, cb_sys_hardfault, 3);

    if( temp == NULL)
    {
        status |= ERROR_NULL_PTR;
    }


    temp = register_hw_cb(KERN_IRQ_SYS_BUSFAULT, cb_sys_busfault, 5);

    if( temp == NULL)
    {
        status |= ERROR_NULL_PTR;
    }

    temp = register_hw_cb(KERN_IRQ_SYS_USAGEFAULT, cb_sys_usagefault, 6);

    if( temp == NULL)
    {
        status |= ERROR_NULL_PTR;
    }

    /* Register task threads */

 }
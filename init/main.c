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


int main(void)
{
    /* Initialize hardware */

    /* 
     * Initialize kernel 
     */
    /* initilize interrupts */
    local_desc = register_hw_cb(0,systick_cb,0);



    while(1)
    {
        
    }
    return 0;
}


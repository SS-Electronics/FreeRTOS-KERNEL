/*
 * File:        stm32_f401cdu6.c
 * Author:      Subhajit Roy  
 *              subhajitroy005@gmail.com 
 *
 * Moudle:      Modeule Device [ Local Build ] 
 * Info:        STM32F401CUD6 Vectors callback implementation  
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
#include "device_irq.h"

#define NO_OF_CPU_INTERRUPTS    3
#define NO_OF_AOMM_INTERRUPTS   1



static type_device_cpu_irq_handle  cache_device_cpu_irq_handle[NO_OF_CPU_INTERRUPTS];





type_device_cpu_irq_handle * dev_get_irq_cpu_handle(uint32_t irq_idx)
{
    if(irq_idx < NO_OF_CPU_INTERRUPTS )
    {
        return &cache_device_cpu_irq_handle[irq_idx];
    }
    else
    {
        return NULL;
    }
}


void SysTick_Handler(void)
{
    if (cache_device_cpu_irq_handle[0].irq_cb != NULL)
    {
        cache_device_cpu_irq_handle[0].irq_cb();
        cache_device_cpu_irq_handle[0].irq_status = TRUE;
    }
}

void SVC_Handler(void)
{
    if (cache_device_cpu_irq_handle[1].irq_cb != NULL)
    {
        cache_device_cpu_irq_handle[1].irq_cb();
        cache_device_cpu_irq_handle[1].irq_status = TRUE;
    }
}

void PendSV_Handler(void)
{
    if (cache_device_cpu_irq_handle[2].irq_cb != NULL)
    {
        cache_device_cpu_irq_handle[2].irq_cb();
        cache_device_cpu_irq_handle[2].irq_status = TRUE;
    }
}
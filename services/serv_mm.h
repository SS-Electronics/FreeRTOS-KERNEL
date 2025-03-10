/*
 * File:        serv_mm.h
 * Author:      Subhajit Roy  
 *              subhajitroy005@gmail.com 
 *
 * Moudle:      Modeule services [ Local Build ] 
 * Info:        memory management services
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
#ifndef __SERV_MM_H__
#define __SERV_MM_H__



 #include "../include/std/std_types.h"
 #include "../kernel/kernel.h" 
 
 
 
 
 
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
 
 
void proc_mm_init(void * arg);
 
 
 
#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif
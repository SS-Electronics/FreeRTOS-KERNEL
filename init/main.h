/*
 * File:        main.h
 * Author:      Subhajit Roy  
 *              subhajitroy005@gmail.com 
 *
 * Moudle:      Modeule init [ Local Build ] 
 * Info:        Entry point
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

#ifndef __MAIN_H__
#define __MAIN_H__

#include "../kernel/kernel.h"

/* Services include for entry points */
#include "../services/serv_mm.h"
#include "../services/serv_task_mgmt.h"
#include "../services/serv_serial_mgmt.h"







#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


int main(void);


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif
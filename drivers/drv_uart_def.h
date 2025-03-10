/*
 * File:        drv_uart_def.h
 * Author:      Subhajit Roy  
 *              subhajitroy005@gmail.com 
 *
 * Moudle:      Modeule drivers [ Local Build ] 
 * Info:        UART drivers related definition
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

 #ifndef __DRV_UART_H__
 #define __DRV_UART_H__

/* Device includes  */
#include "../devices/device.h"



typedef struct 
{
    USART_TypeDef       *device_instance;
    uint32_t            baud_rate;
    uint32_t            packet_size;
    uint32_t            no_of_stop_bits;
    uint32_t            parity;
    uint32_t            mode;
    uint32_t            hw_flow_ctrl;
    uint32_t            over_sampling;
    uint8_t             *tx_buffer_ptr;
    uint32_t            tx_buffer_len;
    uint32_t            tx_byte_counter;
    uint8_t             *rx_buffer_ptr;
    uint32_t            rx_buffer_len;
    uint32_t            rx_byte_counter;
    uint32_t            error_counter;            
    /* data */
}type_drv_uart_handle;

















 #endif
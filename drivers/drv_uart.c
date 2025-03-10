/*
 * File:        drv_uart.c
 * Author:      Subhajit Roy  
 *              subhajitroy005@gmail.com 
 *
 * Moudle:      Modeule drivers [ Local Build ] 
 * Info:        UART related drivers
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

#include "drv_uart.h"




// /**
//   * @brief  Initializes the UART mode according to the specified parameters in
//   *         the UART_InitTypeDef and create the associated handle.
//   * @param  huart  Pointer to a UART_HandleTypeDef structure that contains
//   *                the configuration information for the specified UART module.
//   * @retval HAL status
//   */
//  type_drv_uart_handle drv_uart_init(UART_HandleTypeDef *huart)
//  {
//    /* Check null pointer exception */
//    if (huart == NULL)
//    {
//      return HAL_ERROR;
//    }
//    else
//    {

//    }
 
//    /* Check the parameters */
//    if (huart->Init.HwFlowCtl != UART_HWCONTROL_NONE)
//    {
//      /* The hardware flow control is available only for USART1, USART2, USART3 and USART6.
//         Except for STM32F446xx devices, that is available for USART1, USART2, USART3, USART6, UART4 and UART5.
//      */
//      assert_param(IS_UART_HWFLOW_INSTANCE(huart->Instance));
//      assert_param(IS_UART_HARDWARE_FLOW_CONTROL(huart->Init.HwFlowCtl));
//    }
//    else
//    {
//      assert_param(IS_UART_INSTANCE(huart->Instance));
//    }
//    assert_param(IS_UART_WORD_LENGTH(huart->Init.WordLength));
//    assert_param(IS_UART_OVERSAMPLING(huart->Init.OverSampling));
 
//    if (huart->gState == HAL_UART_STATE_RESET)
//    {
//      /* Allocate lock resource and initialize it */
//      huart->Lock = HAL_UNLOCKED;
 
//  #if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
//      UART_InitCallbacksToDefault(huart);
 
//      if (huart->MspInitCallback == NULL)
//      {
//        huart->MspInitCallback = HAL_UART_MspInit;
//      }
 
//      /* Init the low level hardware */
//      huart->MspInitCallback(huart);
//  #else
//      /* Init the low level hardware : GPIO, CLOCK */
//      HAL_UART_MspInit(huart);
//  #endif /* (USE_HAL_UART_REGISTER_CALLBACKS) */
//    }
 
//    huart->gState = HAL_UART_STATE_BUSY;
 
//    /* Disable the peripheral */
//    __HAL_UART_DISABLE(huart);
 
//    /* Set the UART Communication parameters */
//    UART_SetConfig(huart);
 
//    /* In asynchronous mode, the following bits must be kept cleared:
//       - LINEN and CLKEN bits in the USART_CR2 register,
//       - SCEN, HDSEL and IREN  bits in the USART_CR3 register.*/
//    CLEAR_BIT(huart->Instance->CR2, (USART_CR2_LINEN | USART_CR2_CLKEN));
//    CLEAR_BIT(huart->Instance->CR3, (USART_CR3_SCEN | USART_CR3_HDSEL | USART_CR3_IREN));
 
//    /* Enable the peripheral */
//    __HAL_UART_ENABLE(huart);
 
//    /* Initialize the UART state */
//    huart->ErrorCode = HAL_UART_ERROR_NONE;
//    huart->gState = HAL_UART_STATE_READY;
//    huart->RxState = HAL_UART_STATE_READY;
//    huart->RxEventType = HAL_UART_RXEVENT_TC;
 
//    return HAL_OK;
//  }
/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    stm32f1xx_it.c
  * @brief   Interrupt Service Routines.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f1xx_it.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/
extern DMA_HandleTypeDef hdma_adc1;

extern TIM_HandleTypeDef htim3;

/* USER CODE BEGIN EV */

/* USER CODE END EV */

/******************************************************************************/
/*           Cortex-M3 Processor Interruption and Exception Handlers          */
/******************************************************************************/
/**
  * @brief This function handles Non maskable interrupt.
  */
void NMI_Handler(void)
{
    /* USER CODE BEGIN NonMaskableInt_IRQn 0 */

    /* USER CODE END NonMaskableInt_IRQn 0 */
    /* USER CODE BEGIN NonMaskableInt_IRQn 1 */

    /* USER CODE END NonMaskableInt_IRQn 1 */
}

/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler(void)
{
    /* USER CODE BEGIN HardFault_IRQn 0 */

    /* USER CODE END HardFault_IRQn 0 */
    while (1) {
        /* USER CODE BEGIN W1_HardFault_IRQn 0 */
        /* USER CODE END W1_HardFault_IRQn 0 */
    }
}

/**
  * @brief This function handles Memory management fault.
  */
void MemManage_Handler(void)
{
    /* USER CODE BEGIN MemoryManagement_IRQn 0 */

    /* USER CODE END MemoryManagement_IRQn 0 */
    while (1) {
        /* USER CODE BEGIN W1_MemoryManagement_IRQn 0 */
        /* USER CODE END W1_MemoryManagement_IRQn 0 */
    }
}

/**
  * @brief This function handles Prefetch fault, memory access fault.
  */
void BusFault_Handler(void)
{
    /* USER CODE BEGIN BusFault_IRQn 0 */

    /* USER CODE END BusFault_IRQn 0 */
    while (1) {
        /* USER CODE BEGIN W1_BusFault_IRQn 0 */
        /* USER CODE END W1_BusFault_IRQn 0 */
    }
}

/**
  * @brief This function handles Undefined instruction or illegal state.
  */
void UsageFault_Handler(void)
{
    /* USER CODE BEGIN UsageFault_IRQn 0 */

    /* USER CODE END UsageFault_IRQn 0 */
    while (1) {
        /* USER CODE BEGIN W1_UsageFault_IRQn 0 */
        /* USER CODE END W1_UsageFault_IRQn 0 */
    }
}

/**
  * @brief This function handles System service call via SWI instruction.
  */
void SVC_Handler(void)
{
    /* USER CODE BEGIN SVCall_IRQn 0 */

    /* USER CODE END SVCall_IRQn 0 */
    /* USER CODE BEGIN SVCall_IRQn 1 */

    /* USER CODE END SVCall_IRQn 1 */
}

/**
  * @brief This function handles Debug monitor.
  */
void DebugMon_Handler(void)
{
    /* USER CODE BEGIN DebugMonitor_IRQn 0 */

    /* USER CODE END DebugMonitor_IRQn 0 */
    /* USER CODE BEGIN DebugMonitor_IRQn 1 */

    /* USER CODE END DebugMonitor_IRQn 1 */
}

/**
  * @brief This function handles Pendable request for system service.
  */
void PendSV_Handler(void)
{
    /* USER CODE BEGIN PendSV_IRQn 0 */

    /* USER CODE END PendSV_IRQn 0 */
    /* USER CODE BEGIN PendSV_IRQn 1 */

    /* USER CODE END PendSV_IRQn 1 */
}

/**
  * @brief This function handles System tick timer.
  */
void SysTick_Handler(void)
{
    /* USER CODE BEGIN SysTick_IRQn 0 */

    /* USER CODE END SysTick_IRQn 0 */
    HAL_IncTick();
    /* USER CODE BEGIN SysTick_IRQn 1 */

    /* USER CODE END SysTick_IRQn 1 */
}

/******************************************************************************/
/* STM32F1xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f1xx.s).                    */
/******************************************************************************/

/**
  * @brief This function handles DMA1 channel1 global interrupt.
  */


void DMA1_Channel1_IRQHandler(void)
{
    /* USER CODE BEGIN DMA1_Channel1_IRQn 0 */ 
//    uint32_t i, j;
//    cnt++;
//    DMA_IRQ_CNT++;
//    if(cnt>MAX_AD_CH) {
//        cnt = 0;
//        /*判断DMA传输完成中断*/
//        if(DMA_GetITStatus(DMA1_IT_TC1) != RESET) {
//            /*取值求和取平均*/
//            for(i=0; i<MAX_AD_CH; i++) {
//                AD_Data[i] = 0;
//                for(j=0; j<AD_COUNT; j++) {
//                    AD_Data[i] += ADC_ConvertedValue[j][i];
//                }
//                AD_Data[i] = AD_Data[i] / AD_COUNT;
//            }
//        }

//    }

    /* USER CODE END DMA1_Channel1_IRQn 0 */
    HAL_DMA_IRQHandler(&hdma_adc1);
    /* USER CODE BEGIN DMA1_Channel1_IRQn 1 */

    /* USER CODE END DMA1_Channel1_IRQn 1 */
}



/**
  * @brief This function handles TIM3 global interrupt.
  */
void TIM3_IRQHandler(void)
{
    static uint8_t FRAMEBUFFER_OK_CNT =0;

    /* USER CODE BEGIN TIM3_IRQn 0 */
    if(__HAL_TIM_GET_IT_SOURCE(&htim3,TIM_IT_UPDATE)==SET) { //溢出中断


        /****
        **USART 2 定时器 清除软件
        //10ms定时进程
        ****/
        if( USART2_RX_STA==1) { //正在接收串口数据
            UART2_RX_TIMEOUT_COUNT++;//串口超时计数
            if(UART2_RX_TIMEOUT_COUNT>4) { //数据接收间隔超过3ms
                //串口接收完成或结束
                USART2_RX_STA=0;
                UART2_RX_TIMEOUT_COUNT=0;
                if(m_ctrl_dev.rxlen>=M_MIN_FRAME_LENGTH) {
                    m_ctrl_dev.frameok=1;    //标记完成一帧数据接收
                } else {
                    m_ctrl_dev.rxlen=0;    //错误的数据，直接丢弃，重新开始下一次接收
                }
//                kfifo_reset(&usart2_fifo);

            }
        }
        if((m_ctrl_dev.frameok==1) &&(USART2_RX_STA==0)) {
            //正在接收串口数据
            FRAMEBUFFER_OK_CNT++;//串口超时计数
            if(FRAMEBUFFER_OK_CNT>200) { //数据接收间隔超过3ms
                //串口接收完成或结束
                FRAMEBUFFER_OK_CNT=0;
                mymemset(m_ctrl_dev.rxbuf, 0x00, M_MAX_FRAME_LENGTH); //清空缓存
                m_ctrl_dev.rxlen = 0;
                m_ctrl_dev.frameok = 0;

            }
        }

        /****
        **USART 3 定时器 清除软件
        //10ms定时进程
        ****/
        if( USART3_RX_STA==1) { //正在接收串口数据
            UART3_RX_TIMEOUT_COUNT++;//串口超时计数
            if(UART3_RX_TIMEOUT_COUNT>3) { //数据接收间隔超过3ms
                //串口接收完成或结束
                USART3_RX_STA=0;
                UART3_RX_TIMEOUT_COUNT=0;
//                kfifo_reset(&usart3_fifo);

            }
        }
        __HAL_TIM_SET_COUNTER(&htim3,0);;    //清空定时器的CNT
        __HAL_TIM_SET_AUTORELOAD(&htim3,10);//恢复原来的设置
    }
    __HAL_TIM_CLEAR_IT(&htim3, TIM_IT_UPDATE);//清除中断标志位



//    /* USER CODE END TIM3_IRQn 0 */
//   HAL_TIM_IRQHandler(&htim3);
    /* USER CODE BEGIN TIM3_IRQn 1 */

    /* USER CODE END TIM3_IRQn 1 */
}


#if 0
/**
  * @brief This function handles USART2 global interrupt.
  */
void USART2_IRQHandler(void)
{
    /* USER CODE BEGIN USART2_IRQn 0 */

    /* USER CODE END USART2_IRQn 0 */
    HAL_UART_IRQHandler(&huart2);
    /* USER CODE BEGIN USART2_IRQn 1 */

    /* USER CODE END USART2_IRQn 1 */
}

/**
  * @brief This function handles USART3 global interrupt.
  */
void USART3_IRQHandler(void)
{
    /* USER CODE BEGIN USART3_IRQn 0 */

    /* USER CODE END USART3_IRQn 0 */
    HAL_UART_IRQHandler(&huart3);
    /* USER CODE BEGIN USART3_IRQn 1 */

    /* USER CODE END USART3_IRQn 1 */
}

/**
  * @brief This function handles UART5 global interrupt.
  */
void UART5_IRQHandler(void)
{
    /* USER CODE BEGIN UART5_IRQn 0 */

    /* USER CODE END UART5_IRQn 0 */
    HAL_UART_IRQHandler(&huart5);
    /* USER CODE BEGIN UART5_IRQn 1 */

    /* USER CODE END UART5_IRQn 1 */
}
#endif
/* USER CODE BEGIN 1 */

/* USER CODE END 1 */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

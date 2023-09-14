/**
  ******************************************************************************
  * @file    GPIO/IOToggle/stm32f10x_it.c 
  * @author  MCD Application Team
  * @version V3.5.0
  * @date    08-April-2011
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and peripherals
  *          interrupt service routine.
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_it.h" 
#include "bsp_exti.h"
#include "led.h"
#include "lcd.h"
#include "bsp_GeneralTim.h" 
#include "test.h"

extern volatile uint32_t time;
extern volatile uint32_t time01;

void NMI_Handler(void)
{
}
 
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}
 
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

 
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}
 
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}
 
void SVC_Handler(void)
{
}
 
void DebugMon_Handler(void)
{
}
 
void PendSV_Handler(void)
{
}
 
void SysTick_Handler(void)
{
	
}

void  GENERAL_TIM_IRQHandler (void)
{
	if ( TIM_GetITStatus( GENERAL_TIM, TIM_IT_Update) != RESET ) 
	{	
		time++;
		time01++;
		TIM_ClearITPendingBit(GENERAL_TIM , TIM_FLAG_Update);  		 
	}		 	
}

void EXTI01_IRQHandler(void)
{
  //ȷ���Ƿ������EXTI Line�ж�
	if(EXTI_GetITStatus(EXTI01_INT_EXTI_LINE) != RESET) 
	{
		LEDC13_TOGGLE;
		TIM_Cmd(GENERAL_TIM, ENABLE);
		Chinese_Font_test();
    //����жϱ�־λ
		EXTI_ClearITPendingBit(EXTI01_INT_EXTI_LINE);     
	} 
		
	//ȷ���Ƿ������EXTI Line�ж�
	if(EXTI_GetITStatus(EXTI02_INT_EXTI_LINE) != RESET) 
	{
		LEDC13_TOGGLE;
		TIM_Cmd(GENERAL_TIM, ENABLE);
		Chinese_Font_test();
    //����жϱ�־λ
		EXTI_ClearITPendingBit(EXTI02_INT_EXTI_LINE);     
	}  
}
//void EXTI02_IRQHandler(void)
//{
//  //ȷ���Ƿ������EXTI Line�ж�
//	if(EXTI_GetITStatus(EXTI02_INT_EXTI_LINE) != RESET) 
//	{
//		LEDC13_TOGGLE;
//		TIM_Cmd(GENERAL_TIM, ENABLE);
//		Chinese_Font_test();
//    //����жϱ�־λ
//		EXTI_ClearITPendingBit(EXTI02_INT_EXTI_LINE);     
//	}  
//}

/******************************************************************************/
/*                 STM32F10x Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f10x_xx.s).                                            */
/******************************************************************************/

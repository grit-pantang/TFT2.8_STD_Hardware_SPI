#ifndef __EXTI_H
#define	__EXTI_H


#include "stm32f10x.h"


//Òý½Å¶¨Òå
#define EXTI01_INT_GPIO_PORT         GPIOB
#define EXTI01_INT_GPIO_CLK          (RCC_APB2Periph_GPIOB|RCC_APB2Periph_AFIO)
#define EXTI01_INT_GPIO_PIN          GPIO_Pin_7
#define EXTI01_INT_EXTI_PORTSOURCE   GPIO_PortSourceGPIOB
#define EXTI01_INT_EXTI_PINSOURCE    GPIO_PinSource7
#define EXTI01_INT_EXTI_LINE         EXTI_Line7
#define EXTI01_INT_EXTI_IRQ          EXTI9_5_IRQn

#define EXTI01_IRQHandler            EXTI9_5_IRQHandler



#define EXTI02_INT_GPIO_PORT         GPIOB
#define EXTI02_INT_GPIO_CLK          (RCC_APB2Periph_GPIOB|RCC_APB2Periph_AFIO)
#define EXTI02_INT_GPIO_PIN          GPIO_Pin_6
#define EXTI02_INT_EXTI_PORTSOURCE   GPIO_PortSourceGPIOB
#define EXTI02_INT_EXTI_PINSOURCE    GPIO_PinSource6
#define EXTI02_INT_EXTI_LINE         EXTI_Line6
#define EXTI02_INT_EXTI_IRQ          EXTI9_5_IRQn

#define EXTI02_IRQHandler            EXTI9_5_IRQHandler

void EXTI_Key_Config(void);


#endif /* __EXTI_H */

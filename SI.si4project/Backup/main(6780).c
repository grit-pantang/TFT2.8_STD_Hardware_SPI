
/****************************************************************************************************
//=========================================��Դ����================================================//
//     LCDģ��                STM32��Ƭ��
//      VCC          ��        DC5V/3.3V      //��Դ
//      GND          ��          GND          //��Դ��
//=======================================Һ���������߽���==========================================//
//��ģ��Ĭ��������������ΪSPI����
//     LCDģ��                STM32��Ƭ��
//    SDI(MOSI)      ��          PB15         //Һ����SPI��������д�ź�
//    SDO(MISO)      ��          PB14         //Һ����SPI�������ݶ��źţ��������Ҫ�������Բ�����
//=======================================Һ���������߽���==========================================//
//     LCDģ�� 					      STM32��Ƭ��
//       LED         ��          PB9          //Һ������������źţ��������Ҫ���ƣ���5V��3.3V
//       SCK         ��          PB13         //Һ����SPI����ʱ���ź�
//      DC/RS        ��          PB10         //Һ��������/��������ź�
//       RST         ��          PB12         //Һ������λ�����ź�
//       CS          ��          PB11         //Һ����Ƭѡ�����ź�
//=========================================������������=========================================//
//���ģ�鲻���������ܻ��ߴ��д������ܣ����ǲ���Ҫ�������ܣ�����Ҫ���д���������
//	   LCDģ��                STM32��Ƭ��
//      T_IRQ        ��          PC10         //�����������ж��ź�
//      T_DO         ��          PC2          //������SPI���߶��ź�
//      T_DIN        ��          PC3          //������SPI����д�ź�
//      T_CS         ��          PC13         //������Ƭѡ�����ź�
//      T_CLK        ��          PC0          //������SPI����ʱ���ź�
**************************************************************************************************/
/* @attention
 *
 * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
 * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
 * TIME. AS A RESULT, QD electronic SHALL NOT BE HELD LIABLE FOR ANY
 * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
 * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
 * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
**************************************************************************************************/
#include "delay.h"
#include "sys.h"
#include "lcd.h"
#include "touch.h"
#include "gui.h"
#include "test.h"
#include "bsp_exti.h"
#include "led.h"
#include "bsp_GeneralTim.h"


uint32_t time = 0; // ms ��ʱ����
uint32_t time01 = 0; // ms ��ʱ����

int main(void)
{
    SystemInit();//��ʼ��RCC ����ϵͳ��ƵΪ72MHZ
    delay_init(72);	     //��ʱ��ʼ��
    LCD_Init();	   //Һ����02��ʼ��
    delay_ms(50);
    LCD01_Init();	   //Һ����01��ʼ��
    LED_Init();
    EXTI_Key_Config();
    LCD01_Clear(BLACK);//��Ļ01
    delay_ms(50);
    LCD_Clear(BLACK);//��Ļ02
    GENERAL_TIM_Init();
    //ѭ������
    while(1)
    {
//		main_test(); 		//����������
//		Test_Color();  		//��ˢ��������
//		Test_FillRec();		//GUI���λ�ͼ����
//		Test_Circle(); 		//GUI��Բ����
//		Test_Triangle();    //GUI�����λ�ͼ����
//		English_Font_test();//Ӣ������ʾ������

//		Chinese_Font_test();//��������ʾ������

//		Pic_test();			//ͼƬ��ʾʾ������
//		Rotate_Test();   //��ת��ʾ����
        //����������������߲���Ҫ�������ܣ���ע�͵����津����������
//		Touch_Test();		//��������д����

				//TFT-SPI2
        if(time >= 5000)    /* 5000 * 1 ms = 1s ʱ�䵽 */
        {
            time = 0;
            /* LED1 ȡ�� */
            LCD_Clear(BLACK);
            TIM_Cmd(GENERAL_TIM, DISABLE);
        }
				//TFT01-SPI1
        if(time01 >= 5000)    /* 5000 * 1 ms = 1s ʱ�䵽 */
        {
            time01 = 0;
            /* LED1 ȡ�� */
//            LCD01_Clear(BLACK);
            TIM_Cmd(GENERAL_TIM, DISABLE);
        }
    }
}

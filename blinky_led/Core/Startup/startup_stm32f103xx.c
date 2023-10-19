/*******************************************************************************
  * @file      stm32f103c8t6_startup.C
  * @author    Karim Tarek
  * @brief     STM32F103xB Devices vector table for Atollic toolchain.
  *            This module performs:
  *                - Set the initial SP
  *                - Set the initial PC == Reset_Handler,
  *                - Set the vector table entries with the exceptions ISR address
  *                - calls the main()
  *            After Reset the Cortex-M3 processor is in Thread mode,
  *            priority is Privileged, and the Stack is set to Main.
  ******************************************************************************
  */


#include "stdint.h"
#include "system_stm32f1xx.h"
#include "stm32f1xx.h"

// extern constants from linker file

extern uint32_t _sidata;		// start of initialized data
extern uint32_t _sdata;			// start of data
extern uint32_t _edata;			// end of data
extern uint32_t _sbss;			// start of bss
extern uint32_t	_ebss;			// end of bss
extern uint32_t _estack; 		// top of stack


// static contstruction initializator from libc (empty in case of C language)
// used for C++

extern void __libc_init_array();

// main program entry point (the Main function)

extern int main();

/* The reset handler called after reset *
 * used for loading data from flash to ram
 * make the uninitialized data to 0
 * branch to main function
 */



void Reset_Handler(){


	//initialize data segment
	uint32_t *dataInit = &_sidata; // pointer to the start of init data
	uint32_t *data = &_sdata;      // pointer to the start of data


	while(data < &_edata)
	{
		*(data++) = *(dataInit++);
	}

	//initialize the segment
	uint32_t *bss = &_sbss;

	while(bss < &_ebss)
	{
		*(bss++) =0U;
	}


	// call systemInit function
	SystemInit();

	// call the static constructions for c++
	__libc_init_array();

	//enter main program
	main();

	//catch the case if the main function returns

	while(1);

}


//for unimplemented interrupts or faults the mc loops inside the default handler function
// this is good in the case of debugging

void Default_Handler(){

	while(1);
}



/*******************************************************************************
*
* Provide weak aliases for each Exception handler to the Default_Handler.
* As they are weak aliases, any function with the same name will override
* this definition.
*
*******************************************************************************/

__weak void NMI_Handler (void)									{Default_Handler();}
__weak void HardFault_Handler (void)							{Default_Handler();}
__weak void MemManage_Handler (void)							{Default_Handler();}
__weak void BusFault_Handler (void)								{Default_Handler();}
__weak void UsageFault_Handler (void)							{Default_Handler();}
__weak void SVC_Handler (void)									{Default_Handler();}
__weak void DebugMon_Handler  (void)							{Default_Handler();}
__weak void PendSV_Handler  (void) 								{Default_Handler();}
__weak void SysTick_Handler  (void)								{Default_Handler();}
__weak void WWDG_IRQHandler (void)								{Default_Handler();}
__weak void PVD_IRQHandler (void)								{Default_Handler();}
__weak void TAMPER_IRQHandler (void)							{Default_Handler();}
__weak void RTC_IRQHandler (void)								{Default_Handler();}
__weak void FLASH_IRQHandler (void)								{Default_Handler();}
__weak void RCC_IRQHandler (void)								{Default_Handler();}
__weak void EXTI0_IRQHandler  (void)							{Default_Handler();}
__weak void EXTI1_IRQHandler(void)								{Default_Handler();}
__weak void EXTI2_IRQHandler(void)								{Default_Handler();}
__weak void EXTI3_IRQHandler(void)								{Default_Handler();}
__weak void EXTI4_IRQHandler(void)								{Default_Handler();}
__weak void DMA1_Channel1_IRQHandler(void)						{Default_Handler();}
__weak void DMA1_Channel2_IRQHandler(void)						{Default_Handler();}
__weak void DMA1_Channel3_IRQHandler(void)						{Default_Handler();}
__weak void DMA1_Channel4_IRQHandler(void)						{Default_Handler();}
__weak void DMA1_Channel5_IRQHandler(void)						{Default_Handler();}
__weak void DMA1_Channel6_IRQHandler(void)						{Default_Handler();}
__weak void DMA1_Channel7_IRQHandler(void)						{Default_Handler();}
__weak void ADC1_2_IRQHandler(void)								{Default_Handler();}
__weak void USB_HP_CAN1_TX_IRQHandler(void)						{Default_Handler();}
__weak void USB_LP_CAN1_RX0_IRQHandler(void)					{Default_Handler();}
__weak void CAN1_RX1_IRQHandler (void)							{Default_Handler();}
__weak void CAN1_SCE_IRQHandler (void)							{Default_Handler();}
__weak void EXTI9_5_IRQHandler(void)							{Default_Handler();}
__weak void TIM1_BRK_IRQHandler (void)							{Default_Handler();}
__weak void TIM1_UP_IRQHandler (void)							{Default_Handler();}
__weak void TIM1_TRG_COM_IRQHandler (void)						{Default_Handler();}
__weak void TIM1_CC_IRQHandler (void)							{Default_Handler();}
__weak void TIM2_IRQHandler (void)								{Default_Handler();}
__weak void TIM3_IRQHandler (void)								{Default_Handler();}
__weak void TIM4_IRQHandler (void)								{Default_Handler();}
__weak void I2C1_EV_IRQHandler (void)							{Default_Handler();}
__weak void I2C1_ER_IRQHandler (void)							{Default_Handler();}
__weak void I2C2_EV_IRQHandler (void)							{Default_Handler();}
__weak void I2C2_ER_IRQHandler(void)							{Default_Handler();}
__weak void SPI1_IRQHandler (void)								{Default_Handler();}
__weak void SPI2_IRQHandler(void)								{Default_Handler();}
__weak void USART1_IRQHandler(void)								{Default_Handler();}
__weak void USART2_IRQHandler (void)							{Default_Handler();}
__weak void USART3_IRQHandler(void)								{Default_Handler();}
__weak void EXTI15_10_IRQHandler (void)							{Default_Handler();}
__weak void RTC_Alarm_IRQHandler (void)							{Default_Handler();}
__weak void USBWakeUp_IRQHandler (void)							{Default_Handler();}


// interrupt vector table section

__attribute__((section(".isr_vector")))
const void (*VectorTable[])(void) = {

		(const void (*)(void))&_estack,
		   Reset_Handler,
		   NMI_Handler,
		   HardFault_Handler,
		   MemManage_Handler,
		   BusFault_Handler,
		   UsageFault_Handler,
		   0,
		   0,
		   0,
		   0,
		   SVC_Handler,
		   DebugMon_Handler,
		   0,
		   PendSV_Handler,
		   SysTick_Handler,
		   WWDG_IRQHandler,
		   PVD_IRQHandler,
		   TAMPER_IRQHandler,
		   RTC_IRQHandler,
		   FLASH_IRQHandler,
		   RCC_IRQHandler,
		   EXTI0_IRQHandler,
		   EXTI1_IRQHandler,
		   EXTI2_IRQHandler,
		   EXTI3_IRQHandler,
		   EXTI4_IRQHandler,
		   DMA1_Channel1_IRQHandler,
		   DMA1_Channel2_IRQHandler,
		   DMA1_Channel3_IRQHandler,
		   DMA1_Channel4_IRQHandler,
		   DMA1_Channel5_IRQHandler,
		   DMA1_Channel6_IRQHandler,
		   DMA1_Channel7_IRQHandler,
		   ADC1_2_IRQHandler,
		   USB_HP_CAN1_TX_IRQHandler,
		   USB_LP_CAN1_RX0_IRQHandler,
		   CAN1_RX1_IRQHandler,
		   CAN1_SCE_IRQHandler,
		   EXTI9_5_IRQHandler,
		   TIM1_BRK_IRQHandler,
		   TIM1_UP_IRQHandler,
		   TIM1_TRG_COM_IRQHandler,
		   TIM1_CC_IRQHandler,
		   TIM2_IRQHandler,
		   TIM3_IRQHandler,
		   TIM4_IRQHandler,
		   I2C1_EV_IRQHandler,
		   I2C1_ER_IRQHandler,
		   I2C2_EV_IRQHandler,
		   I2C2_ER_IRQHandler,
		   SPI1_IRQHandler,
		   SPI2_IRQHandler,
		   USART1_IRQHandler,
		   USART2_IRQHandler,
		   USART3_IRQHandler,
		   EXTI15_10_IRQHandler,
		   RTC_Alarm_IRQHandler,
		   USBWakeUp_IRQHandler,
		   0,
		   0,
		   0,
		   0,
		   0,
		   0,
		   0,
		   BootRAM


};


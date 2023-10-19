/*
******************************************************************************
**
** @file        : LinkerScript.ld
**
** @author      : Karim Tarek
**
** @brief       : a simple  Linker script for STM32F103C8Tx Device 
**							from STM32F1 series
**
**                      64KBytes FLASH
**                      20KBytes RAM
******************************************************************************
*/

/* This is the entry point */
ENTRY(Reset_Handler)


/* the highest address of the stack in user mode */

_estack = ORIGIN(RAM) + LENGTH(RAM); /* this is the end of the Ram memory */

/* lets define Two memory sections for SRAM and FLASH 	 			*/
/* the FLASH is read/excute while the SRAM is read write 			*/
/* from the datasheet the start addresses of the Flash and SRAM 	*/
/* is 0x8000000 and 0x20000000 respectively and also their length 	*/
/* is specified in the top of the file (also in the datasheet) 		*/

MEMORY
{

	FLASH(rx):ORIGIN =0x8000000, LENGTH =64K
	RAM(rwx):ORIGIN =0x20000000, LENGTH =20K

}

/*sections */
SECTIONS 
{

	/* in the startup code we defined the section .isr_vector
	 * that contains the MSP and the vector table 
	 * for proper booting we have to relocate this section
	 * to the address 0x8000000 this is the first available
	 * memory location in the FLASH
	 */
	 
	.isr_vector :
	{
		KEEP(*(.isr_vector)); /* KEEP instructs the linker to keep this section in the final executable even if it is not referenced in any other section.  */
		. = ALIGN(4);
	
	}> FLASH

  /* The program code and other data into "FLASH" Rom type memory */

	.text :
	{
	  *(.text)
	  *(.text.*)
	  *(.rodata)
	  *(.rodate.*)
	  . = ALIGN(4); /* align data to 4 bytes */
	  _etext = .;   /* assign the value of the location pointer to symbol _etext */
	  
	 }> FLASH 

	_sidata = LOADADDR(.data)

  /* Initialized data sections into "RAM" Ram type memory */

	.data :
	{
	  _sdata = .;
	  *(.data)
	  *(.data.*)
	  . = ALIGN(4);
	  _edata = .;
	} > RAM AT> FLASH   
	
  /* Uninitialized data section into "RAM" Ram type memory */
	
	.bss :
	{
	
	_sbss = .;
	 _sbss = .;
    __bss_start__ = _sbss;
    *(.bss)
    *(.bss.*)
    . = ALIGN(4);
    _ebss = .;
    __bss_end__ = _ebss;
     . = ALIGN(4);
    end = .;
    __end__ = .;
  }> RAM
}


}

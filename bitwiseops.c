#include <stdint.h>

int main(void){
	//Address = Base Address + Offset
	volatile uint32_t *const pRCCAHBENR=(uint32_t*)0x40021014; //Enable clock peripheral
	volatile uint32_t *const pPortDMode=(uint32_t*)0x48000C00; //Configure port mode register GPIOx_MODER
	volatile uint32_t *const pPortDOutputReg=(uint32_t*)0x48000C14; //Configure output register GPIOx_ODR
	
	*pRCCAHBENR |=(1<<20);
	*pPortDMode &=~((1<<4)|(1<<5)); //Preserve other bits, clear wanted bits
	*pPortDMode|=(1<<4); //Set wanted bits (01) for output
	*pPortDOutputReg|=(1<<2); //Write to output register
	while(1){
		for(int i=0;i<20000;i++);
		*pPortDOutputReg^=(1<<2);
	}
}

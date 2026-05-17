#include <stdint.h>

int main(void){
	//Address = Base Address + Offset
	uint32_t *pRCCAHBENR=(uint32_t*)0x40021014; //Enable clock peripheral
	uint32_t *pPortDMode=(uint32_t*)0x48000C00; //Configure port mode register GPIOx_MODER
	uint32_t *pPortDOutputReg=(uint32_t*)0x48000C14; //Configure output register GPIOx_ODR

	*pRCCAHBENR |=(1<<20);
	*pPortDMode &=~((1<<4)|(1<<5)); //Preserve other bits, clear wanted bits
	*pPortDMode|=(1<<4); //Set wanted bits (01) for output
	*pPortDOutputReg|=(1<<2); //Write to output register
	while(1){
		for(int i=0;i<20000;i++);
		*pPortDOutputReg^=(1<<2);
	}
}

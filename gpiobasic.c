#include <stdint.h>

int main(void){
	//Address = Base Address + Offset
	uint32_t *pRCCAHBENR=(uint32_t*)0x40021014; //Enable clock peripheral
	uint32_t *pPortDMode=(uint32_t*)0x48000C00; //Configure port mode register GPIOx_MODER
	uint32_t *pPortDOutputReg=(uint32_t*)0x48000C14; //Configure output register GPIOx_ODR

	*pRCCAHBENR |=0x00100000;
	*pPortDMode &=0xFFFFFFCF; //Preserve other bits, clear wanted bits
	*pPortDMode|=0x00000010; //Set wanted bits (01) for output
	*pPortDOutputReg|=0x00000004; //Write to output register
	while(1){
		for(int i=0;i<100000;i++);
		*pPortDOutputReg^=0x00000004; //Toggle
	}
}

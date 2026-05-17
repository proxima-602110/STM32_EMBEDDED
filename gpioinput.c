#include <stdint.h>

int main(void){
	volatile uint32_t *const pRCCAHBENR=(volatile uint32_t *const)0x40021014;
	volatile uint32_t *const pPAModeReg=(volatile uint32_t *const)0x48000000;
	volatile uint32_t *const pPAInputReg=(volatile uint32_t *const)0x48000010;
	volatile uint32_t *const pPAOutputReg=(volatile uint32_t *const)0x48000014;
	volatile uint32_t *const pPAPUPReg=(volatile uint32_t *const)0x4800000C;

	*pRCCAHBENR|=(1<<17); //Enable clock peripheral
	*pPAPUPReg&=~((1<<20)|(1<<21));
	*pPAPUPReg|=(1<<20); //Enable internal pull up
	*pPAModeReg&=~((1<<18)|(1<<19)|(1<<20)|(1<<21)); //Clear wanted bits, PA10 is set as input (00)
	*pPAModeReg|=(1<<18); //PA9 set as output
	*pPAOutputReg&=~(1<<9);//Set GPIO low initially

	while(1){
		if(!(*pPAInputReg&(1<<10))){
			*pPAOutputReg^=(1<<9);

		}
		for(int i=0;i<100000;i++);
	}
}

//Toggle LED using BSRR (Bit Set/Reset Register)

#include <stdint.h>

#define RCCAHBENR ((volatile uint32_t *const)0x40021014)
#define GPIOC_MODER ((volatile uint32_t *const)0x48000800)
#define GPIOC_BSRR ((volatile uint32_t *const)0x48000818)

int main(void){
	*RCCAHBENR|=(1<<19);
	*GPIOC_MODER&=~((1<<5)|(1<<4));
	*GPIOC_MODER|=(1<<4);
	while(1){
		*GPIOC_BSRR = 0x00000004;
		delay(100000);
		*GPIOC_BSRR=0x00040000;
		delay(100000);
	}

}

void delay(uint32_t t){
		for(int i=0;i<t;i++);
}

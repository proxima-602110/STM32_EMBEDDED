#include <stdint.h>

#define RCCAHBENR ((volatile uint32_t *const)0x40021014)
#define GPIOC_MODER ((volatile uint32_t *const)0x48000800)
#define GPIOC_ODR ((volatile uint32_t *const)0x48000814)

void delay(uint32_t t){
	for(uint32_t i=0;i<t;i++);
}

void display(uint32_t n){
	*GPIOC_ODR^=n;
}
int main(void){
	*RCCAHBENR|=(1<<19);
	*GPIOC_MODER&=~0x00033FFF;
	*GPIOC_MODER|=0x00011555; //0x11555
	while(1){
		display(0x0000016F);
		delay(100000);
	}
}



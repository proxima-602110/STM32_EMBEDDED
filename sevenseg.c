#include "sevenseg.h"

#define RCCAHBENR_GPIOC ((volatile uint32_t *const)0x40021014)
#define GPIOC_MODER ((volatile uint32_t *const)0x48000800)
#define GPIOC_ODR ((volatile uint32_t *const)0x48000814)

uint8_t digit[]={0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x77 ,0x7C ,0x39 , 0x5E, 0x79, 0x71};

void GPIOC_CLKEN(){
	*RCCAHBENR_GPIOC |=(1<<19);
}

void set_IO(uint8_t disp_num,uint8_t a, uint8_t b, uint8_t c, uint8_t d, uint8_t e, uint8_t f, uint8_t g){
	 uint8_t segments[]={a,b,c,d,e,f,g};
	 *GPIOC_MODER &= ~(0x03<<(disp_num*2));
	 *GPIOC_MODER |= 0x01<<(disp_num*2);
	 for(int k=0;k<7;k++){
		 *GPIOC_MODER &= ~(0x03<<(segments[k]*2));
		 *GPIOC_MODER |= 0x01<<(segments[k]*2);
	 }
}

void disp_segment(uint8_t a, uint8_t b, uint8_t c, uint8_t d, uint8_t e, uint8_t f, uint8_t g){
	uint8_t segments[]={a,b,c,d,e,f,g};
	for(int i=0;i<7;i++){
		*GPIOC_ODR |= (1<<segments[i]);
	}
}

void delay_t(uint32_t t){
	for(volatile uint32_t j=0;j<t;j++);
}

void disp_digit(uint8_t X){
	*GPIOC_ODR &= ~(0xFF);
	*GPIOC_ODR |= digit[X];
}

void up_counter(uint8_t count,uint32_t delay){
	for(int t=0;t<=count;t++){
		*GPIOC_ODR &= ~(0xFF);
		*GPIOC_ODR |= digit[t];
		delay_t(delay);
	}
}

void down_counter(uint8_t count,uint32_t delay){
	for(int t=count;t>=0;t--){
		*GPIOC_ODR &= ~(0xFF);
		*GPIOC_ODR |= digit[t];
		delay_t(delay);
	}
}





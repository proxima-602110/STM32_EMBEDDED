#ifndef SEVENSEG_H
#define SEVENSEG_H
#include <stdint.h>

void GPIOC_CLKEN();
void set_IO(uint8_t disp_num,uint8_t a, uint8_t b, uint8_t c, uint8_t d, uint8_t e, uint8_t f, uint8_t g);
void disp_segment(uint8_t a, uint8_t b, uint8_t c, uint8_t d, uint8_t e, uint8_t f, uint8_t g);
void delay_t(uint32_t t);
void disp_digit(uint8_t X);
void up_counter(uint8_t count,uint32_t delay);
void down_counter(uint8_t count,uint32_t delay);

#endif

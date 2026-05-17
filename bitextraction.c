#include <stdint.h>
//Example data -> 0xB410, extract bits 9-14 and store in another variable (6 bits)
int main(void){
	uint32_t data=0xB410; //0x1011010000010000
	uint32_t shift_data=(data>>9);
	uint32_t mask=0x0000003F;
	uint32_t output=shift_data&mask;
}

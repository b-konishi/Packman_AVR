/*
* Packman.c
*
* Created: 2015/09/30 21:16:05
* Author : Admin
*/

#define F_CPU 32000000
/*
#define T0H 0.36
#define T1H 1.35
#define T0L 1.35
#define T1L 0.36
#define RESET 100
*/
#define T0H 0.3
#define T1H 1.3
#define T0L 1.3
#define T1L 0.3
#define RESET 100

#include <avr/io.h>
#include <util/delay.h>

void clock_internal_init() {
	OSC.CTRL |= OSC_RC32MEN_bm;
	loop_until_bit_is_set(OSC.STATUS, OSC_RC32MRDY_bp);
	CPU_CCP = CCP_IOREG_gc;
	CLK.CTRL = CLK_SCLKSEL_RC32M_gc;
}

void HLGenerator(int r, int g, int b) {
	if (r) {
		PORTC.OUT = 0b00000001;
		_delay_us(T1H);
		PORTC.OUT = 0b00000000;
		_delay_us(T1L);
		PORTC.OUT = 0b00000001;
		_delay_us(T1H);
		PORTC.OUT = 0b00000000;
		_delay_us(T1L);
		PORTC.OUT = 0b00000001;
		_delay_us(T1H);
		PORTC.OUT = 0b00000000;
		_delay_us(T1L);
		PORTC.OUT = 0b00000001;
		_delay_us(T1H);
		PORTC.OUT = 0b00000000;
		_delay_us(T1L);
		PORTC.OUT = 0b00000001;
		_delay_us(T1H);
		PORTC.OUT = 0b00000000;
		_delay_us(T1L);
		PORTC.OUT = 0b00000001;
		_delay_us(T1H);
		PORTC.OUT = 0b00000000;
		_delay_us(T1L);
		PORTC.OUT = 0b00000001;
		_delay_us(T1H);
		PORTC.OUT = 0b00000000;
		_delay_us(T1L);
		PORTC.OUT = 0b00000001;
		_delay_us(T1H);
		PORTC.OUT = 0b00000000;
		_delay_us(T1L);
		
	} else {
		
		PORTC.OUT = 0b00000001;
		_delay_us(T0H);
		PORTC.OUT = 0b00000000;
		_delay_us(T0L);
		PORTC.OUT = 0b00000001;
		_delay_us(T0H);
		PORTC.OUT = 0b00000000;
		_delay_us(T0L);
		PORTC.OUT = 0b00000001;
		_delay_us(T0H);
		PORTC.OUT = 0b00000000;
		_delay_us(T0L);
		PORTC.OUT = 0b00000001;
		_delay_us(T0H);
		PORTC.OUT = 0b00000000;
		_delay_us(T0L);
		PORTC.OUT = 0b00000001;
		_delay_us(T0H);
		PORTC.OUT = 0b00000000;
		_delay_us(T0L);
		PORTC.OUT = 0b00000001;
		_delay_us(T0H);
		PORTC.OUT = 0b00000000;
		_delay_us(T0L);
		PORTC.OUT = 0b00000001;
		_delay_us(T0H);
		PORTC.OUT = 0b00000000;
		_delay_us(T0L);
		PORTC.OUT = 0b00000001;
		_delay_us(T0H);
		PORTC.OUT = 0b00000000;
		_delay_us(T0L);
	}
	if (g) {
		PORTC.OUT = 0b00000001;
		_delay_us(T1H);
		PORTC.OUT = 0b00000000;
		_delay_us(T1L);
		PORTC.OUT = 0b00000001;
		_delay_us(T1H);
		PORTC.OUT = 0b00000000;
		_delay_us(T1L);
		PORTC.OUT = 0b00000001;
		_delay_us(T1H);
		PORTC.OUT = 0b00000000;
		_delay_us(T1L);
		PORTC.OUT = 0b00000001;
		_delay_us(T1H);
		PORTC.OUT = 0b00000000;
		_delay_us(T1L);
		PORTC.OUT = 0b00000001;
		_delay_us(T1H);
		PORTC.OUT = 0b00000000;
		_delay_us(T1L);
		PORTC.OUT = 0b00000001;
		_delay_us(T1H);
		PORTC.OUT = 0b00000000;
		_delay_us(T1L);
		PORTC.OUT = 0b00000001;
		_delay_us(T1H);
		PORTC.OUT = 0b00000000;
		_delay_us(T1L);
		PORTC.OUT = 0b00000001;
		_delay_us(T1H);
		PORTC.OUT = 0b00000000;
		_delay_us(T1L);
		
	} else {
		
		PORTC.OUT = 0b00000001;
		_delay_us(T0H);
		PORTC.OUT = 0b00000000;
		_delay_us(T0L);
		PORTC.OUT = 0b00000001;
		_delay_us(T0H);
		PORTC.OUT = 0b00000000;
		_delay_us(T0L);
		PORTC.OUT = 0b00000001;
		_delay_us(T0H);
		PORTC.OUT = 0b00000000;
		_delay_us(T0L);
		PORTC.OUT = 0b00000001;
		_delay_us(T0H);
		PORTC.OUT = 0b00000000;
		_delay_us(T0L);
		PORTC.OUT = 0b00000001;
		_delay_us(T0H);
		PORTC.OUT = 0b00000000;
		_delay_us(T0L);
		PORTC.OUT = 0b00000001;
		_delay_us(T0H);
		PORTC.OUT = 0b00000000;
		_delay_us(T0L);
		PORTC.OUT = 0b00000001;
		_delay_us(T0H);
		PORTC.OUT = 0b00000000;
		_delay_us(T0L);
		PORTC.OUT = 0b00000001;
		_delay_us(T0H);
		PORTC.OUT = 0b00000000;
		_delay_us(T0L);
	}
	if (b) {
		PORTC.OUT = 0b00000001;
		_delay_us(T1H);
		PORTC.OUT = 0b00000000;
		_delay_us(T1L);
		PORTC.OUT = 0b00000001;
		_delay_us(T1H);
		PORTC.OUT = 0b00000000;
		_delay_us(T1L);
		PORTC.OUT = 0b00000001;
		_delay_us(T1H);
		PORTC.OUT = 0b00000000;
		_delay_us(T1L);
		PORTC.OUT = 0b00000001;
		_delay_us(T1H);
		PORTC.OUT = 0b00000000;
		_delay_us(T1L);
		PORTC.OUT = 0b00000001;
		_delay_us(T1H);
		PORTC.OUT = 0b00000000;
		_delay_us(T1L);
		PORTC.OUT = 0b00000001;
		_delay_us(T1H);
		PORTC.OUT = 0b00000000;
		_delay_us(T1L);
		PORTC.OUT = 0b00000001;
		_delay_us(T1H);
		PORTC.OUT = 0b00000000;
		_delay_us(T1L);
		PORTC.OUT = 0b00000001;
		_delay_us(T1H);
		PORTC.OUT = 0b00000000;
		_delay_us(T1L);
		
		} else {
		
		PORTC.OUT = 0b00000001;
		_delay_us(T0H);
		PORTC.OUT = 0b00000000;
		_delay_us(T0L);
		PORTC.OUT = 0b00000001;
		_delay_us(T0H);
		PORTC.OUT = 0b00000000;
		_delay_us(T0L);
		PORTC.OUT = 0b00000001;
		_delay_us(T0H);
		PORTC.OUT = 0b00000000;
		_delay_us(T0L);
		PORTC.OUT = 0b00000001;
		_delay_us(T0H);
		PORTC.OUT = 0b00000000;
		_delay_us(T0L);
		PORTC.OUT = 0b00000001;
		_delay_us(T0H);
		PORTC.OUT = 0b00000000;
		_delay_us(T0L);
		PORTC.OUT = 0b00000001;
		_delay_us(T0H);
		PORTC.OUT = 0b00000000;
		_delay_us(T0L);
		PORTC.OUT = 0b00000001;
		_delay_us(T0H);
		PORTC.OUT = 0b00000000;
		_delay_us(T0L);
		PORTC.OUT = 0b00000001;
		_delay_us(T0H);
		PORTC.OUT = 0b00000000;
		_delay_us(T0L);
		
	}
}


int main(void)
{
	clock_internal_init();
	/*
	TWIC.SLAVE.ADDR = 0x04;
	TWIC.SLAVE.CTRLA = 0x08;
	
	while (!(TWIC.SLAVE.STATUS & 32))
	asm("NOP");
	
	TWIC.SLAVE.CTRLB = 0x03;
	
	while (1) {
	while (!(TWIC.SLAVE.STATUS & 128))
	asm("NOP");
	TWIC.SLAVE.CTRLB = 0x03;
	}*/
	
	PORTC.DIR = 0x01;
	int i;
	for (i = 0; i < 10; i++) {
		HLGenerator(1,0,0);
		HLGenerator(1,0,0);
		HLGenerator(1,0,0);
		HLGenerator(1,0,0);
		HLGenerator(1,0,0);
		_delay_ms(500);
		HLGenerator(0,1,0);
		HLGenerator(0,1,0);
		HLGenerator(0,1,0);
		HLGenerator(0,1,0);
		HLGenerator(0,1,0);
		_delay_ms(500);
		HLGenerator(0,0,1);
		HLGenerator(0,0,1);
		HLGenerator(0,0,1);
		HLGenerator(0,0,1);
		HLGenerator(0,0,1);
		_delay_ms(500);
	}
	
	/* Replace with your application code */
	while (1);
	return 0;
}


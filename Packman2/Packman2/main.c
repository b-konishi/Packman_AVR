/*
* Packman.c
*
* Created: 2015/09/30 21:16:05
* Author : Admin
*/

#define F_CPU 32000000

#define T0H 0.36
#define T1H 1.35
#define T0L 1.35
#define T1L 0.36
#define RESET 100

#include <avr/io.h>
#include <util/delay.h>

void clock_internal_init() {
	CCP = CCP_IOREG_gc;              // disable register security for oscillator update
	OSC.CTRL = OSC_RC32MEN_bm;       // enable 32MHz oscillator
	while(!(OSC.STATUS & OSC_RC32MRDY_bm)); // wait for oscillator to be ready
	CCP = CCP_IOREG_gc;              // disable register security for clock update
	CLK.CTRL = CLK_SCLKSEL_RC32M_gc; // switch to 32MHz clock
}

void wait(int time){
	if (time) {
		__asm__ __volatile__("\n"
			"nop\n\t"
			"nop\n\t"
			"nop\n\t"
			"nop\n\t"
			"nop\n\t"
			"nop\n\t"
			"nop\n\t"
			"nop\n\t"
			"nop\n\t"
			"nop\n\t"
			"nop\n\t"
			"nop\n\t"
			"nop\n\t"
			"nop\n\t"
			"nop\n\t"
			"nop\n\t"
			"nop\n\t"
			"nop\n\t"
			"nop\n\t"
			"nop\n\t"
			"nop\n\t"
			"nop\n\t"
			"nop\n\t"
			"nop\n\t"
			"nop\n\t"
			"nop\n\t"
			"nop\n\t"
			"nop\n\t"
			"nop\n\t"
			"nop\n\t"
			"nop\n\t"
			"nop\n\t"
			"nop\n\t"
			"nop\n\t"
		);
	} else if (!time) {
		__asm__ __volatile__("\n"
			"nop\n\t"
			"nop\n\t"
		);
	}
	return;
}

void HLGenerator(int port, int* data) {
	int i;
	for (i = 23; i >= 0; i--) {
		PORTA.OUT = port;
		wait(i);
		PORTA.OUT = 0;
		wait(!i);
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
	}
	*/
	//asm volatile("LDI R17, value" ::);
	
	PORTA.DIR = 0xFF;
	int red[24]	=	{1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	int green[24] = {0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0};
	int blue[24] =	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1};	
	
	int i;
	for (i = 0; i < 1000; i++) {
		HLGenerator(7, red);
		HLGenerator(7, red);
		HLGenerator(7, red);
		HLGenerator(7, red);
		HLGenerator(7, red);
		HLGenerator(7, red);
		HLGenerator(7, red);
		HLGenerator(7, red);
		HLGenerator(7, red);
		HLGenerator(7, red);
		HLGenerator(7, red);
		HLGenerator(7, red);
		HLGenerator(7, red);
		HLGenerator(7, red);
		_delay_ms(1000);
		
		HLGenerator(7, green);
		HLGenerator(7, green);
		HLGenerator(7, green);
		HLGenerator(7, green);
		HLGenerator(7, green);
		HLGenerator(7, green);
		HLGenerator(7, green);
		HLGenerator(7, green);
		HLGenerator(7, green);
		HLGenerator(7, green);
		HLGenerator(7, green);
		HLGenerator(7, green);
		HLGenerator(7, green);
		HLGenerator(7, green);
		_delay_ms(1000);
		
		HLGenerator(7, blue);
		HLGenerator(7, blue);
		HLGenerator(7, blue);
		HLGenerator(7, blue);
		HLGenerator(7, blue);
		HLGenerator(7, blue);
		HLGenerator(7, blue);
		HLGenerator(7, blue);
		HLGenerator(7, blue);
		HLGenerator(7, blue);
		HLGenerator(7, blue);
		HLGenerator(7, blue);
		HLGenerator(7, blue);
		HLGenerator(7, blue);
		_delay_ms(1000);
		
	}
		
	
	/* Replace with your application code */
	while (1);
	return 0;
}




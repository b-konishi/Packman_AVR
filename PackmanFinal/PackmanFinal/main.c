/*
* PackmanFinal.c
* Created: 2015/11/1 21:25:00
* Author : Konishi
*/

#define F_CPU 32000000

#define T0H 0.36
#define T1H 1.35
#define T0L 1.35
#define T1L 0.36
#define RESET 100

/*
 * COLUMUN:		LED-Matrix's column number
 * ROW:			LED-Matrix's row number
 * DEVIDE:		Signal-Line's devided number
 * CONTROL_LED:	Control LED number for devided number
 */
#define COLUMN 1
#define ROW 10
#define DEVIDE 1
#define CONTROL_LED COLUMN*ROW/DEVIDE

#define FILL_DATA_SIZE 6

#include <avr/io.h>
#include <util/delay.h>

void clock_internal_init() {
	CCP = CCP_IOREG_gc;              // disable register security for oscillator update
	OSC.CTRL = OSC_RC32MEN_bm;       // enable 32MHz oscillator
	while(!(OSC.STATUS & OSC_RC32MRDY_bm)); // wait for oscillator to be ready
	CCP = CCP_IOREG_gc;              // disable register security for clock update
	CLK.CTRL = CLK_SCLKSEL_RC32M_gc; // switch to 32MHz clock
}

void wait(unsigned int time){
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

/*
 * port:	PORT bit
 * *data	
 */
void HLGenerator(unsigned int port, unsigned char *data) {
	unsigned char i;
	for (i = 0; i < 3; i++) {
		// 1
		PORTA.OUT = port;
		wait(data[i]);
		PORTA.OUT = 0;
		wait(!data[i]);
		// 2
		PORTA.OUT = port;
		wait(data[i]);
		PORTA.OUT = 0;
		wait(!data[i]);
		// 3
		PORTA.OUT = port;
		wait(data[i]);
		PORTA.OUT = 0;
		wait(!data[i]);
		// 4
		PORTA.OUT = port;
		wait(data[i]);
		PORTA.OUT = 0;
		wait(!data[i]);
		// 5
		PORTA.OUT = port;
		wait(data[i]);
		PORTA.OUT = 0;
		wait(!data[i]);
		// 6
		PORTA.OUT = port;
		wait(data[i]);
		PORTA.OUT = 0;
		wait(!data[i]);
		// 7
		PORTA.OUT = port;
		wait(data[i]);
		PORTA.OUT = 0;
		wait(!data[i]);
		// 8
		PORTA.OUT = port;
		wait(data[i]);
		PORTA.OUT = 0;
		wait(!data[i]);
	}
}

/*
 * *data	data[COLUMN*ROW / DEVIDED]*DEVIDED address
 */
void send_data(unsigned char *data) {
	unsigned char i, j;
	for (i = 0; i < DEVIDE; i++) {
		for (j = 0; j < CONTROL_LED; j++) {
			HLGenerator(1<<i, &data[j+CONTROL_LED*i]);
			_delay_us(50);
		}
	}
}

int main(void)
{
	clock_internal_init();

	/*
	 * AVR		B3 B2 B1 B0 C7 C6 C5 C4 C3 C2 C1 C0 D7 D6 D5 D4 D3 D2 D1 D0 E1 E0
	 * GPIO		24 25 26 27 06 07 08 09 10 11 12 13 14 15 16 17 18 19 22 23 04 05
	 * ARRAY	18 19 20 21 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16 17 00 01
	 */
	
	
	unsigned char check = 0;
	unsigned char toggle = 0;
	unsigned char _toggle = 0;
	
	unsigned char column = 0;
	unsigned char row = 0;
	unsigned char color_data = 0;
	unsigned char fill_color_data[6] = {};
	
	unsigned char _column = 0;
	unsigned char _row = 0;

	unsigned char data[COLUMN*ROW] = {};

	unsigned int count = 0, i;
	
	PORTA.DIR = 0xff;
	PORTB.DIR = 0x00;
	PORTC.DIR = 0x00;
	PORTD.DIR = 0x00;
	PORTE.DIR = 0x00;
	/*
	while (1) {
		unsigned char a[] = {1, 0, 0};
		HLGenerator(1, a);
		_delay_ms(1000);
	}
	*/
	
	while (1) {
		check = PORTE.IN;
		if (0b01 == check) {
			if (column == (_column = (PORTC.IN & 0b00011111)) && row == (_row = (PORTD.IN & 0b00011111))) {
				continue;
			}
			column = _column;
			row = _row;
			color_data = PORTB.IN & 0b00000111;
			
			data[ROW*(column-1)+(row-1)] = color_data;
			
		} else if (0b10 == check) {
			while (count < COLUMN*ROW/FILL_DATA_SIZE) {
				if (toggle == (_toggle = (PORTC.IN & 0b10000000 >> 7))) {
					continue;
				}
				toggle = ~toggle;
				unsigned char address[] = {
					PORTC.IN & 0b00111000 >> 3,
					PORTC.IN & 0b00000111,
					PORTD.IN & 0b11100000 >> 5,
					PORTD.IN & 0b00011100 >> 2,
					(PORTD.IN & 0b00000011 << 1)|(PORTB.IN & 0b1000 >> 3),
					PORTB.IN & 0b0111
				};
				for (i = 0; i < FILL_DATA_SIZE; i++) {
					fill_color_data[i] = address[i];
				}
				for (i = 0; i < 6; i++) {
					data[i+count*6] = fill_color_data[i];
				}
				count++;
			}
		} else if (check == 0b11) {
			send_data(data);
		}
	}
	return 0;
}



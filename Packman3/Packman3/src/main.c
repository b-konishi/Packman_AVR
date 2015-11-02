
#define F_CPU 32000000
/*
#define T0H 0.36
#define T1H 1.35
#define T0L 1.35
#define T1L 0.36
#define RESET 100
*/
#define T0H 0.36
#define T1H 1.35
#define T0L 1.35
#define T1L 0.36
#define RESET 100

#define TWI_MASTER       TWIC
#define TWI_MASTER_PORT  PORTC
#define TWI_SLAVE        TWIF
#define TWI_SPEED        50000
#define TWI_MASTER_ADDR  0x50
#define TWI_SLAVE_ADDR   0x60
#define DATA_LENGTH     8

#include <asf.h>
#include <avr/io.h>
#include <util/delay.h>"

void clock_internal_init() {
	OSC.CTRL |= OSC_RC32MEN_bm;
	loop_until_bit_is_set(OSC.STATUS, OSC_RC32MRDY_bp);
	CPU_CCP = CCP_IOREG_gc;
	CLK.CTRL = CLK_SCLKSEL_RC32M_gc;
}

TWI_SLAVE_t slave;

uint8_t data[DATA_LENGTH] = {
	0x0f, 0x1f, 0x2f, 0x3f, 0x4f, 0x5f, 0x6f, 0x7f
};

uint8_t recv_data[DATA_LENGTH] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

twi_options_t m_options = {
	.speed     = TWI_SPEED,
	.chip      = TWI_MASTER_ADDR,
	.speed_reg = TWI_BAUD(sysclk_get_cpu_hz(), TWI_SPEED)
};

static void slave_process(void) {
	int i;

	for(i = 0; i < DATA_LENGTH; i++) {
		recv_data[i] = slave.receivedData[i];
	}
}

ISR(TWIF_TWIS_vect) {
	TWI_SlaveInterruptHandler(&slave);
}

void send_and_recv_twi()
{
	twi_package_t packet = {
		.addr_length = 0,
		.chip        = TWI_SLAVE_ADDR,
		.buffer      = (void *)data,
		.length      = DATA_LENGTH,
		.no_wait     = false
	};

	uint8_t i;

	sysclk_enable_peripheral_clock(&TWI_SLAVE);
	TWI_SlaveInitializeDriver(&slave, &TWI_SLAVE, *slave_process);
	TWI_SlaveInitializeModule(&slave, TWI_SLAVE_ADDR, TWI_SLAVE_INTLVL_MED_gc);

	for (i = 0; i < TWIS_SEND_BUFFER_SIZE; i++) {
		slave.receivedData[i] = 0;
	}

	cpu_irq_enable();

	do {
		// Nothing
	} while(slave.result != TWIS_RESULT_OK);
}

int main (void)
{
	/* Insert system clock initialization code here (sysclk_init()). */
	clock_internal_init();

	board_init();

	/* Insert application code here, after the board has been initialized. */
}

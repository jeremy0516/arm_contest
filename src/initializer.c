# include "initializer.h"

int init_all(){
	HAL_Init();
	FPU_init();

	if(init_port(SEG_gpio, DIN_pin) != 0 ){
		// Fail to init LED
		return -1;
	}
	if(init_port(SEG_gpio, CS_pin) != 0 ){
		// Fail to init LED
		return -1;
	}
	if(init_port(SEG_gpio, CLK_pin) != 0 ){
		// Fail to init LED
		return -1;
	}
	if(init_port(LHORN_gpio, LHORN_pin) != 0 ){
		// Fail to init LED
		return -1;
	}
	if(init_port(RHORN_gpio, RHORN_pin) != 0 ){
		// Fail to init LED
		return -1;
	}
	if(init_button(ECHO_gpio, ECHO_pin) != 0 ){
		// Fail to init LED
		return -1;
	}
	if(init_port(TRIG_gpio, TRIG_pin) != 0 ){
		// Fail to init LED
		return -1;
	}
	// Set Decode Mode to non-decode mode
	send_7seg(SEG_gpio, DIN_pin, CS_pin, CLK_pin, SEG_ADDRESS_DECODE_MODE, 0xFF);
	// Set Scan Limit to digit 0 only
	send_7seg(SEG_gpio, DIN_pin, CS_pin, CLK_pin, SEG_ADDRESS_SCAN_LIMIT, 0x07);
	// Wakeup 7seg
	send_7seg(SEG_gpio, DIN_pin, CS_pin, CLK_pin, SEG_ADDRESS_SHUTDOWN, 0x7F);
	// 7seg brightness
	send_7seg(SEG_gpio, DIN_pin, CS_pin, CLK_pin, SEG_ADDRESS_ITENSITY, 0x07);
	return 0;
}

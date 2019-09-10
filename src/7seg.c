#include "7seg.h"
#include "helper.h"


// Only allow GPIOA and GPIOB for now
// Can easily extended by adding "else if" cases
/*int init_7seg(GPIO_TypeDef* gpio, int DIN, int CS, int CLK){
	// Enable AHB2 Clock
	if(gpio==GPIOA){
		RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
	}
	else if(gpio==GPIOB){
		RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN;
	}
	else{
		// Error! Add other cases to suit other GPIO pins
		return -1;
	}

	// Set GPIO pins to output mode (01)
	// First Clear bits(&) then set bits(|)
	gpio->MODER &= ~(0b11 << (2*DIN));
	gpio->MODER |= (0b01 << (2*DIN));
	gpio->MODER &= ~(0b11 << (2*CS));
	gpio->MODER |= (0b01 << (2*CS));
	gpio->MODER &= ~(0b11 << (2*CLK));
	gpio->MODER |= (0b01 << (2*CLK));

	// Close display test
	send_7seg(gpio, DIN, CS, CLK, SEG_ADDRESS_DISPLAY_TEST, 0x00);

	return 0;
}*/

void send_7seg(GPIO_TypeDef* gpio, int DIN, int CS, int CLK, int address, int data){
	// The payload to send
	int payload = ((address&0xFF)<<8)|(data&0xFF);

	// Start the sending cycles
	// 16 data-bits + 1 CS signal
	int total_cycles = 16+1;

	for(int a=1;a<=total_cycles;a++){
		// Reset CLK when enter
		reset_gpio(gpio, CLK);

		// Set DIN according to data except for last cycle(CS)
		if(((payload>>(total_cycles-1-a))&0x1) && a!=total_cycles){
			set_gpio(gpio, DIN);
		}
		else{
			reset_gpio(gpio, DIN);
		}

		// Set CS at last cycle
		if(a==total_cycles){
			set_gpio(gpio, CS);
		}
		else{
			reset_gpio(gpio, CS);
		}

		// Set CLK when leaving (7seg set data at rising edge)
		set_gpio(gpio, CLK);
	}

	return;
}

int display_number(GPIO_TypeDef* gpio, int DIN, int CS, int CLK, int num, int num_digs){
	for(int i=1;i<=num_digs;i++){
		send_7seg(gpio, DIN, CS, CLK, i, num % 10);
		num /= 10;
	}
	for(int i=num_digs+1;i<=8;i++){
		num /= 10;
		send_7seg(gpio, DIN, CS, CLK, i, 15);
	}
	if(num != 0)
		return -1;
	return 0;
}

int display_two_decimal(GPIO_TypeDef* gpio, int DIN, int CS, int CLK, double num){
	// Set two decimal points
	int dec_1=(int)(num*10)%10;//get the number of First place after the decimal point
	int	dec_2=(int)(num*100)%10;//get the number of second place after the decimal point
	send_7seg(gpio, DIN, CS, CLK, 2, dec_1);
	send_7seg(gpio, DIN, CS, CLK, 1, dec_2);

	int number=num;
	// Set third digit, add a decimal dot
	send_7seg(gpio, DIN, CS, CLK, 3, 0x80+number%10);
	number = number/10;

	for(int i=4;i<=8;i++){
		if(number>0){
			send_7seg(gpio, DIN, CS, CLK, i, number%10);
			number = number/10;
		}
		else{
			send_7seg(gpio, DIN, CS, CLK, i, 15);
		}
	}

	return 0;
}

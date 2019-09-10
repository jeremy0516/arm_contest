#ifndef DEFINITION_H
#define DEFINITION_H

#define SEG_gpio GPIOF
#define DIN_pin 6
#define CS_pin 7
#define CLK_pin 8
#define LHORN_gpio GPIOF
#define LHORN_pin 8
#define RHORN_gpio GPIOF
#define RHORN_pin 9
#define TRIG_gpio GPIOB
#define TRIG_pin 8
#define ECHO_gpio GPIOB
#define ECHO_pin 9
// servo pin PC6 PC7
// wait_2(10) or wait_3(10) = 1s
// wait(1000) = 1s

#define pi 3.1415926
#define hor_low_bound 25                                   // must mod 5 == 0
#define hor_1st_bound 30
#define hor_2st_bound 35
#define hor_3st_bound 40
#define hor_4st_bound 45
#define hor_high_bound 50								   // must mod 5 == 0
#define ver_low_bound 40								   // must mod 5 == 0
#define ver_high_bound 45								   // must mod 5 == 0
#define hor_mid_point (hor_low_bound+hor_high_bound)/2
#define ver_mid_point (ver_low_bound+ver_high_bound)/2
#define safe_distance 95



#endif

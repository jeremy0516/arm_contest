#include "delay.h"
#include "main.h"
#include "servo.h"
#include "7seg.h"
#include "helper.h"
#include "horn.h"
#include "timer.h"
#include "hc_sr04.h"
#include "delay.h"
#include "initializer.h"
#include "motion.h"
#include "definition.h"
#include <math.h>

int main(void)
{
	int init_result = init_all();
	if (init_result != 0) return -1;

	servo();
	motion_1();
	return 0;
}

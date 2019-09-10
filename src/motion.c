# include "motion.h"

void motion_1(){
	int hor = hor_low_bound, ver = ver_low_bound, state_hor = 1, state_ver = 1;
	double distance_cm = 0.0;
	while (1)
	{
		// control servo
		TIM3->CCR1=hor; //pc6
		TIM3->CCR2=ver; //pc7

		distance_cm = get_distance(TRIG_gpio, TRIG_pin, ECHO_gpio, ECHO_pin);

		// calculate the distance correspond to each angle.
		double hor_angle = abs((double)(hor_mid_point-hor));
		double ver_angle = abs((double)(ver_mid_point-ver));
		distance_cm *= cos(hor_angle*pi/180.0);
		distance_cm *= cos(ver_angle*pi/180.0);

		if (state_hor == 1){
			if (distance_cm < safe_distance){
				if (hor >= hor_low_bound && hor <= hor_1st_bound){
					beep_L(150, 20000);
					beep_R(150, 0);
				}
				if (hor >= hor_1st_bound && hor <= hor_2st_bound){
					beep_L(150, 100);
					beep_R(150, 50);
				}
				if (hor >= hor_2st_bound && hor <= hor_3st_bound){
					beep_L(150, 100);
					beep_R(150, 100);
				}
				if (hor >= hor_3st_bound && hor <= hor_4st_bound){
					beep_L(150, 50);
					beep_R(150, 100);
				}
				if (hor >= hor_4st_bound && hor <= hor_high_bound){
					beep_L(150, 0);
					beep_R(150, 20000);
				}
				wait_2(1.0);
			}
			else{
				hor += 5;
			}

		}
		else if (state_hor == 0){
			if (distance_cm < safe_distance){
				if (hor >= hor_low_bound && hor <= hor_1st_bound){
					beep_L(150, 20000);
					beep_R(150, 0);
				}
				if (hor >= hor_1st_bound && hor <= hor_2st_bound){
					beep_L(150, 100);
					beep_R(150, 50);
				}
				if (hor >= hor_2st_bound && hor <= hor_3st_bound){
					beep_L(150, 100);
					beep_R(150, 100);
				}
				if (hor >= hor_3st_bound && hor <= hor_4st_bound){
					beep_L(150, 50);
					beep_R(150, 100);
				}
				if (hor >= hor_4st_bound && hor <= hor_high_bound){
					beep_L(150, 0);
					beep_R(150, 20000);
				}
				wait_2(1.0);
			}
			else{
				hor -= 5;
			}
		}
		if (state_ver == 1){
			if (distance_cm < safe_distance){
			}
			else{
				if (hor == hor_high_bound || hor == hor_low_bound){
					ver += 5;
				}
			}
		}
		else if (state_ver == 0){
			if (distance_cm < safe_distance){
			}
			else{
				if (hor == hor_high_bound || hor == hor_low_bound){
					ver -= 5;
				}
			}
		}

		if(hor == hor_high_bound){
			state_hor = 0;
		}
		else if (hor == hor_low_bound){
			state_hor = 1;
		}
		else if (ver == ver_high_bound){
			state_ver = 0;
		}
		else if (ver == ver_low_bound){
			state_ver = 1;
		}
	}
}

void motion_2(){
	int hor = hor_low_bound, ver = ver_low_bound, state_hor = 1, state_ver = 1;
	double distances[6];
	double distance_cm = 0.0, min;
	while (1)
	{
		// control servo.
		TIM3->CCR1=hor; //pc6
		TIM3->CCR2=ver; //pc7

		distance_cm = get_distance(TRIG_gpio, TRIG_pin, ECHO_gpio, ECHO_pin);
		distances[(hor - hor_low_bound) / 5] = distance_cm;

		// calculate the distance correspond to each angle.
		double hor_angle = abs((double)(hor_mid_point-hor));
		double ver_angle = abs((double)(ver_mid_point-ver));
		distance_cm *= cos(hor_angle*pi/180.0);
		distance_cm *= cos(ver_angle*pi/180.0);

		if (state_hor == 1){
			hor += 5;
		}
		else if (state_hor == 0){
			hor -= 5;
		}
		if (state_ver == 1){
			if (hor == hor_high_bound || hor == hor_low_bound){
				ver += 5;
			}
		}
		else if (state_ver == 0){
			if (hor == hor_high_bound || hor == hor_low_bound){
				ver -= 5;
			}
		}

		if(hor == hor_high_bound){
			state_hor = 0;
			min = distances[0];
			for (int i = 1; i < 6; i++){
				if (min > distances[i]){
					min = distances[i];
				}
			}
			if (min <= 2){
				//beep_L(150);
			}
			else{
				//beep_R(150);
			}
		}
		else if (hor == hor_low_bound){
			state_hor = 1;
			min = distances[0];
			for (int i = 1; i < 6; i++){
				if (min > distances[i]){
					min = distances[i];
				}
			}
			if (min <= 2){
				//beep_L(150);
			}
			else{
				//`beep_R(150);
			}
		}
		else if (ver == ver_high_bound){
			state_ver = 0;
		}
		else if (ver == ver_low_bound){
			state_ver = 1;
		}

	}
}

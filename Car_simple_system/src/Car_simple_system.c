/*
 ============================================================================
 Name        : Car_simple_system.c
 Author      : Mahmoud Ehab Morsy
 Version     :
 Copyright   : Your copyright notice
 Description : a Car system
 ============================================================================
 */

#include <stdio.h>
typedef enum {
	OFF, ON
} state;
state engine_state;
state AC_state;
state eng_temp_controller_state;
char onstate_menu(void);
int traffic_light_data(void);
float room_temp_data(void);
float engine_temp_data(void);
void disp_state(void);
void print_enum(state);
void pause_menu(void);
unsigned int vehicle_speed = 0; //normal speed when turning on the engine
float room_temp = 25; //suitable room temperature
float eng_temp = 10;  //suitable engine temperature when turning on the engine
int main(void) {
	char choice;
	while (1) {
		puts("a. Turn on the vehicle engine");
		puts("b. Turn off the vehicle engine");
		puts("c. Quit the system");
		fflush(stdout);
		scanf(" %c", &choice);
		if (choice == 'a') {  //Turn on the vehicle engine
			engine_state = ON;
			printf("Engine State:");
			print_enum(engine_state);
			printf("\n");
			fflush(stdout);
			while (1) {
				choice = onstate_menu();
				if (choice == 'a') {
					engine_state = OFF;
					printf("Engine State:");
					print_enum(engine_state);
					printf("\n");
					fflush(stdout);
					break;
				} else if (choice == 'b') {
					vehicle_speed = traffic_light_data();
				} else if (choice == 'c') {
					room_temp = room_temp_data();
				} else if (choice == 'd') {
					eng_temp = engine_temp_data();
				} else {
					puts("please enter a valid choice");
					continue;
				}
				if (vehicle_speed == 30) {
					if (AC_state == OFF) {
						AC_state = ON;
					}
					if (eng_temp_controller_state == OFF) {
						eng_temp_controller_state = ON;
					}
					room_temp = (room_temp * (5 / (float) 4)) + 1;
					eng_temp = (eng_temp * (5 / (float) 4)) + 1;
				}
				disp_state();
				pause_menu();
			}
		} else if (choice == 'b') {  // turn off the vehicle engine
			engine_state = OFF;
			continue;
		} else if (choice == 'c') {  //Quit the system
			puts("shutting down......");
			puts("bye:D");
			return 0;
		} else {
			puts("please enter a valid choice");
			continue;
		}
	}
}

char onstate_menu(void) {
	char choice;
	puts("a. Turn off the engine");
	puts("b. Set the traffic light color.");
	puts("c. Set the room temperature (Temperature Sensor)");
	puts("d. Set the engine temperature (Engine Temperature Sensor)");
	fflush(stdout);
	scanf(" %c", &choice);
	return choice;
}
int traffic_light_data(void) { //light sensor
	int speed = 0;
	char input;
	while (1) {
		puts("Please enter the traffic light color:");
		fflush(stdout);
		scanf(" %c", &input);
		if (input == 'G' || input == 'g') {
			speed = 100;
			break;
		} else if (input == 'O' || input == 'o') {
			speed = 30;
			break;
		} else if (input == 'R' || input == 'r') {
			speed = 0;
			break;
		} else {
			puts("invalid input!....Please enter a valid one");
			continue;
		}
	}
	return speed;
}
float room_temp_data(void) {  //temperature sensor
	int input;
	int temp;
	puts("please enter the room temperature:");
	fflush(stdout);
	scanf(" %d", &input);
	if (input < 10) {
		temp = 20;
		AC_state = ON;
	} else if (input > 30) {
		temp = 20;
		AC_state = ON;
	}
	else {
		temp = input;
		AC_state = OFF;
	}
	return temp;
}
float engine_temp_data(void) {  //engine temperature sensor
	int input;
	int temp;
	puts("please enter the engine temperature:");
	fflush(stdout);
	scanf(" %d", &input);
	if (input < 100) {
		temp = 125;
		eng_temp_controller_state = ON;
	} else if (input > 150) {
		temp = 125;
		eng_temp_controller_state = ON;
	}else {
		temp = input;
		eng_temp_controller_state = OFF;
	}
	return temp;
}
void disp_state(void) {  //current vehicle state menu
	puts("******************************************");
	printf("Engine state:");
	print_enum(engine_state);
	printf("\nAC:");
	print_enum(AC_state);
	printf("\nVehicle speed: %d Km/hr", vehicle_speed);
	printf("\nRoom Temperature: %.2f Celsius", room_temp);
	printf("\nEngine Temperature Controller State:");
	print_enum(eng_temp_controller_state);
	printf("\nEngine Temperature: %.2f Celsius\n", eng_temp);
	puts("******************************************");
}
void print_enum(state x) {  //to print enum as characters
	if (x == 1) {
		printf(" ON");
	} else {
		printf(" OFF");
	}
}
void pause_menu(void) {  //to keep state menu displayed
	char pause;
	puts("enter anything to get back to the previous menu");
	fflush(stdout);
	scanf(" %c", &pause);
	puts("******************************************");
}

#include "avr/eeprom.h"

enum Menu{menu_start, menu_on, intro, controls, settings} menu_state;
void MenuTick() 
{
	unsigned char tmpB = 0x00;
	switch(menu_state)
	{
		case menu_start:
			menu_state = menu_on;
			break;
		case menu_on:
			tmpB = ~PINA & 0x08;
			if (tmpB == 0x08) {
				menu_state = settings;
				break;
			}
			else { menu_state = menu_on; }
			break;
		case intro:
			break;
		case controls:
			break;
		case settings:
			tmpB = ~PINA & 0x08;
			if (tmpB == 0x08) {
				menu_state = menu_on;
				break;
			}
			else {
				menu_state = settings;
				break;
			}
	}
	switch (menu_state)
	{
		case menu_start:
			break;
		case menu_on:
			PORTB = 0x07;
			break;
		case intro:
			PORTB = 0x01;
			break;
		case controls:
			PORTB = 0x02;
			break;
		case settings:
			PORTB = 0x04;
			tmpB = ~PINA & 0x02;
			if (tmpB == 0x02) {
				//if (play_song == 0) { play_song = 1; }
				if (eeprom_read_byte(0) == 0) {eeprom_write_byte(0,1);}
				else { eeprom_write_byte(0,0); }
			}
			break;
			
	}
	//return menu_state;
};
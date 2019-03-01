#include <time.h>
#include <stdlib.h>

unsigned char r;
unsigned char r_limit;
unsigned char doors_opened = 0;
int room = 0;
unsigned char g_output;
enum Game{game_start, room0, room1, room2, room3, room4, room5, pause} game_state;
void GameTick()
{
	unsigned char tmpG = 0;
	switch(game_state)
	{ //Transitions
		case game_start:
			game_state = room0;
			break;
		case room0:
			tmpG = ~PINA & 0x08;
			if (tmpG == 0x08) {room = game_state; game_state = pause;}
			else {
				if (doors_opened < 3) { r_limit = 5; }
				else { r_limit = 6; }
				r = rand() % r_limit;
				while (r == 0) { r = rand() % r_limit; } //Prevents player from being randomly sent into the room they left from
			
				if (r == 1) { game_state = room1; doors_opened++; }
				else if (r == 2) { game_state = room2; doors_opened++; }
				else if (r == 3) { game_state = room3; doors_opened++; }
				else if (r == 4) { game_state = room4; doors_opened++; }
				else if (r == 5) { game_state = room5; doors_opened++; }
			}
			break;
		case room1:
		tmpG = ~PINA & 0x08;
		if (tmpG == 0x08) {room = game_state; game_state = pause;}
		else {
			if (doors_opened < 3) { r_limit = 5; }
			else { r_limit = 6; }
			r = rand() % r_limit;
			while (r == 1) { r = rand() % r_limit; }
			
			if (r == 0) { game_state = room0; doors_opened++; }
			else if (r == 2) { game_state = room2; doors_opened++; }
			else if (r == 3) { game_state = room3; doors_opened++; }
			else if (r == 4) { game_state = room4; doors_opened++; }
			else if (r == 5) { game_state = room5; doors_opened++; }
		}
			break;
		case room2:
		tmpG = ~PINA & 0x08;
		if (tmpG == 0x08) {room = game_state; game_state = pause;}
		else {
			if (doors_opened < 3) { r_limit = 5; }
			else { r_limit = 6; }
			r = rand() % r_limit;
			while (r == 2) { r = rand() % r_limit; }
		
			if (r == 0) { game_state = room0; doors_opened++; }
			else if (r == 1) { game_state = room1; doors_opened++; }
			else if (r == 3) { game_state = room3; doors_opened++; }
			else if (r == 4) { game_state = room4; doors_opened++; }
			else if (r == 5) { game_state = room5; doors_opened++; }
			}
			break;
		case room3:
		tmpG = ~PINA & 0x08;
		if (tmpG == 0x08) {room = game_state; game_state = pause;}
		else {
			if (doors_opened < 3) { r_limit = 5; }
			else { r_limit = 6; }
			r = rand() % r_limit;
			while (r == 3) { r = rand() % r_limit; }
		
			if (r == 0) { game_state = room0; doors_opened++; }
			else if (r == 1) { game_state = room1; doors_opened++; }
			else if (r == 2) { game_state = room2; doors_opened++; }
			else if (r == 4) { game_state = room4; doors_opened++; }
			else if (r == 5) { game_state = room5; doors_opened++; }
			}
			break;
		case room4:
		tmpG = ~PINA & 0x08;
		if (tmpG == 0x08) {room = game_state; game_state = pause;}
		else {
			if (doors_opened < 3) { r_limit = 5; }
			else { r_limit = 6; }
			r = rand() % r_limit;
			while (r == 4) { r = rand() % r_limit; }
		
			if (r == 0) { game_state = room0; doors_opened++; }
			else if (r == 1) { game_state = room1; doors_opened++; }
			else if (r == 2) { game_state = room2; doors_opened++; }
			else if (r == 3) { game_state = room3; doors_opened++; }
			else if (r == 5) { game_state = room5; doors_opened++; }
			}
			break;
		case room5:
		tmpG = ~PINA & 0x08;
		if (tmpG == 0x08) {room = game_state; game_state = pause;}
		else {
			if (doors_opened < 3) { r_limit = 5; }
			else { r_limit = 6; }
			r = rand() % r_limit;
			while (r == 5) { r = rand() % r_limit; }
		
			if (r == 0) { game_state = room0; doors_opened++; }
			else if (r == 1) { game_state = room1; doors_opened++; }
			else if (r == 2) { game_state = room2; doors_opened++; }
			else if (r == 3) { game_state = room3; doors_opened++; }
			else if (r == 4) { game_state = room4; doors_opened++; }
			}
			break;
		case pause:
			tmpG = ~PINA & 0x08;
			if (tmpG == 0x08) { game_state = room; }
			else { game_state = pause; }
			break;
	}
	switch(game_state) 
	{ //State Actions
		case game_start:
			break;
		case room0:
			g_output = 0x42;
			break;
		case room1:
			g_output = 0x44;
			break;
		case room2:
			g_output = 0x48;
			break;
		case room3:
			g_output = 0x50;
			break;
		case room4:
			g_output = 0x60;
			break;
		case room5:
			g_output = 0xC0;
			break;
		case pause:
			g_output = 0x61;
			break;
	}
}
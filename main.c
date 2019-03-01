/*
 *    Name: Lacey Kisselburgh E-mail: lkiss001@ucr.edu
 *    Partner's Name: Arturo Perez E-mail: apere129@ucr.edu
 *    Lab Section: 022
 *    Lab # 9  Exercise # 3 
 *    Exercise Description: This program plays short a song
 *	 
 *    I acknowledge all content contained herein, excluding template or example
 *    code, is my own original work.
 */

#include <avr/io.h>
#include "io.c"
unsigned char play_song = 1;
#include "pwm.h"
#include "start_menu.h"
#include "timer.h"

/*
typedef struct Tasks {
	signed char state;
	unsigned long int period;
	unsigned long int elapsedTime;
	int (*TickFct)(int);
} task;

task tasks[2];
const unsigned char tasksNum = 2;
const unsigned long periodSong = 25;
const unsigned long periodMenu = 100;
const unsigned long tasksPeriodGCD = 25;
*/

int main(void)
{   DDRA=0x00; PORTA=0xFF;
    DDRB = 0xFF; PORTB = 0x00; // Sets PORTB as output
	
	/*
	unsigned char x=0;
	tasks[x].state = song_start;
	tasks[x].period = periodSong;
	tasks[x].elapsedTime = tasks[x].period;
	tasks[x].TickFct = &TickFct_Song;
	++x;
	tasks[x].state = menu_start;
	tasks[x].period = periodMenu;
	tasks[x].elapsedTime = tasks[x].period;
	tasks[x].TickFct = &MenuTick;
	*/
	
	unsigned long song_elapsedTime = 25;
	unsigned long menu_elapsedTime = 100;
	const unsigned long timerPeriod = 25;
	
    TimerSet(timerPeriod);
    TimerOn();
    PWM_on();
    
    while(1)
    { 
		if (song_elapsedTime >= 25) {
			SongTick();
			song_elapsedTime = 0;
		}
		if (menu_elapsedTime >= 100) {
			MenuTick();
			menu_elapsedTime = 0;
		}
		/*
		for (x = 0; x < tasksNum; ++x) 
		{
			if ( tasks[x].elapsedTime >= tasks[x].period )
			{ // Ready
				tasks[x].state = tasks[x].TickFct(tasks[x].state);
				tasks[x].elapsedTime = 0;
			}
			tasks[x].elapsedTime += tasksPeriodGCD;
		}
		*/
        while(!TimerFlag); 
        TimerFlag = 0;
		song_elapsedTime += timerPeriod;
		menu_elapsedTime += timerPeriod;
    }
	//return 0;
}


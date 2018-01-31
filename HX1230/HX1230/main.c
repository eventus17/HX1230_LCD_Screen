/*
 * HX1230.c
 *
 * Created: 06-Oct-17 12:35:04 AM
 * Author : ScorpionIPX
 */ 

#include "global.h"
#include <avr/io.h>
#include "hx1230.h"
#include "hx_8x6_characters.h"
#include <util/delay.h>


int main(void)
{
	init_hx1230_control();
	_delay_ms(500);
	
	hx_fill_screen();
	_delay_ms(2000);
	hx_clear_screen();
	
	hx_set_coordinates(0, 0);
	hx_write_string("ScorpionIPX");
	
    while (1) 
    {
		
    }
}


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
	hx_write_char(hx_A);
	hx_write_char(hx_B);
	hx_write_char(hx_C);
	hx_write_char(hx_D);
	
	hx_write_char(hx_E);
	hx_write_char(hx_F);
	hx_write_char(hx_G);
	hx_write_char(hx_H);
	
	hx_write_char(hx_I);
	hx_write_char(hx_J);
	hx_write_char(hx_K);
	hx_write_char(hx_L);
	
	hx_set_coordinates(0, 1);
	
	hx_write_char(hx_M);
	hx_write_char(hx_N);
	hx_write_char(hx_O);
	hx_write_char(hx_P);
	
	hx_write_char(hx_Q);
	hx_write_char(hx_R);
	hx_write_char(hx_S);
	hx_write_char(hx_T);
	
	hx_write_char(hx_U);
	hx_write_char(hx_V);
	hx_write_char(hx_W);
	hx_write_char(hx_X);
	
	hx_write_char(hx_Y);
	hx_write_char(hx_Z);
	hx_set_coordinates(0, 2);
	
	hx_write_char(hx_0);
	hx_write_char(hx_1);
	hx_write_char(hx_2);
	hx_write_char(hx_3);
	hx_write_char(hx_4);
	hx_write_char(hx_5);
	hx_write_char(hx_6);
	hx_write_char(hx_7);
	hx_write_char(hx_8);
	hx_write_char(hx_9);
	
    while (1) 
    {
		
    }
}


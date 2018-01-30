/*
 * hx1230.c
 *
 * Created: 06-Oct-17 12:35:49 AM
 *  Author: ScorpionIPX
 */ 

#include "global.h"
#include "hx1230.h"
#include <util/delay.h>
#include "hx_8x6_characters.h"
#include <string.h>


void init_hx1230_control(void)
{
	// set required pins as output
	HX1230_DDR |= ((1 << HX_RST) | (1 << HX_CE) | (1 << HX_DIN) | (1 << HX_CLK));
	
	// set idle state
	CLEAR_HX_CLK;
	CLEAR_HX_RST;
	_delay_ms(50);
	SET_HX_RST;
	CLEAR_HX_CE;
	_delay_ms(1);
	SET_HX_CE;
	_delay_ms(1);
	
	// commands needed to initialize hx1230 display
	// found within a chinese data sheet
	
	hx_send_command(0x2f);
	hx_send_command(0x90);
	hx_send_command(0xa6);
	hx_send_command(0xa4);
	hx_send_command(0xaf);
	
	hx_send_command(0x40);
	hx_send_command(0xb0);
	hx_send_command(0x10);
	hx_send_command(0x00);
}

void hx_send_data(unsigned char _data)
{
	// activate hx1230
	CLEAR_HX_CE;
	
	// configure communication for data transfer
	SET_HX_DIN;
	
	// toggle clock
	SET_HX_CLK;
	CLEAR_HX_CLK;
	
	// send the actual data, MSB fiHX_RST
	for(int bit_position = 7; bit_position >= 0; bit_position--)
	{
		// calculate bit to be send
		if(((_data >> bit_position) & 1) == 1)
		{
			SET_HX_DIN;
		}
		else
		{
			CLEAR_HX_DIN;
		}
		
		// toggle clock
		SET_HX_CLK;
		CLEAR_HX_CLK;
	}
	
	// deactivate hx1230
	SET_HX_CE;
}

void hx_send_command(unsigned char _command)
{
	// activate hx1230
	CLEAR_HX_CE;
	
	// configure communication for command transfer
	CLEAR_HX_DIN;
	
	// toggle clock
	SET_HX_CLK;
	CLEAR_HX_CLK;
	
	// send the actual command, MSB fiHX_RST
	for(int bit_position = 7; bit_position >= 0; bit_position--)
	{
		// calculate bit to be send
		if(((_command >> bit_position) & 1) == 1)
		{
			SET_HX_DIN;
		}
		else
		{
			CLEAR_HX_DIN;
		}
		
		// toggle clock
		SET_HX_CLK;
		CLEAR_HX_CLK;
	}
	
	// deactivate hx1230
	SET_HX_CE;
}

void hx_set_coordinates(unsigned char _x, unsigned char _y)
{
	// 0, 0 is the upper left corner
	
	hx_send_command(0xB0 + _y);
	hx_send_command(0x10 | ((_x & 0x7F) >> 4));
	hx_send_command(0x0F & _x);
}

void hx_clear_screen(void)
{
	unsigned char col, row;
	
	hx_set_coordinates(0, 0);
	
	for(row = 0; row <= HX_MAX_ROW_ROOT; row ++)
	{
		for(col = 0; col <= HX_MAX_COL; col ++)
		{
			hx_send_data(0x00);
		}
	}
}

void hx_fill_screen(void)
{
	unsigned char col, row;
	
	hx_set_coordinates(0, 0);
	
	for(row = 0; row < 9; row ++)
	{
		for(col = 0; col < 96; col ++)
		{
			hx_send_data(0xFF);
		}
	}
}

void hx_write_char(const unsigned char _character)
{
	
	for(int row_index = 0; row_index < 6; row_index ++)
	{
		hx_send_data(HX_character[_character][row_index]);
	}
}

void hx_write_string(const char *_characters_array)
{
	int string_length = strlen(_characters_array);
	for(int char_index = 0; char_index < string_length; char_index++)
	{
		hx_write_char((const unsigned char)(_characters_array[char_index]));
	}
}
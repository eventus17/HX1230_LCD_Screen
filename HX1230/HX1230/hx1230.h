/*
 * hx1230.h
 *
 * Created: 06-Oct-17 12:36:42 AM
 *  Author: ScorpionIPX
 */ 

#include "global.h"
#include <avr/io.h>
#include "hx_8x6_characters.h"

#ifndef HX1230_H_
#define HX1230_H_

#define HX1230_PORT PORTC //port used to control hx1230
#define HX1230_DDR  DDRC //data direction register used for hx1230

#define HX_RST PC0 //external reset input
#define HX_CE  PC1 //chip enable
#define HX_DIN PC2 //serial data input
#define HX_CLK PC3 //serial clock input

#define SET_HX_RST (HX1230_PORT |= (1 << HX_RST))
#define SET_HX_CE  (HX1230_PORT |= (1 << HX_CE))
#define SET_HX_DIN (HX1230_PORT |= (1 << HX_DIN))
#define SET_HX_CLK (HX1230_PORT |= (1 << HX_CLK))

#define CLEAR_HX_RST (HX1230_PORT &= ~(1 << HX_RST))
#define CLEAR_HX_CE  (HX1230_PORT &= ~(1 << HX_CE))
#define CLEAR_HX_DIN (HX1230_PORT &= ~(1 << HX_DIN))
#define CLEAR_HX_CLK (HX1230_PORT &= ~(1 << HX_CLK))

#define HX_MAX_ROW 64
#define HX_MAX_ROW_ROOT 8
#define HX_MAX_COL 96

void init_hx1230_control(void);
void hx_send_data(unsigned char _data);
void hx_send_command(unsigned char _command);
void hx_set_coordinates(unsigned char _x, unsigned char _y);
void hx_clear_screen(void);
void hx_fill_screen(void);
void hx_write_char(const unsigned char _character);
void hx_write_string(const char *_characters_array);

#endif /* HX1230_H_ */
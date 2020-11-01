#pragma once
#ifndef SPD40_H
#define SPD40_H

#include "quantum.h"
#include "matrix.h"
#include "backlight.h"
#include <stddef.h>

#define red_led_off   PORTF |= (1<<5)
#define red_led_on    PORTF &= ~(1<<5)
#define blu_led_off   PORTF |= (1<<4)
#define blu_led_on    PORTF &= ~(1<<4)
#define grn_led_off   PORTD |= (1<<1)
#define grn_led_on    PORTD &= ~(1<<1)

#define set_led_off     red_led_off; grn_led_off; blu_led_off
#define set_led_red     red_led_on;  grn_led_off; blu_led_off
#define set_led_blue    red_led_off; grn_led_off; blu_led_on
#define set_led_green   red_led_off; grn_led_on;  blu_led_off
#define set_led_yellow  red_led_on;  grn_led_on;  blu_led_off
#define set_led_magenta red_led_on;  grn_led_off; blu_led_on
#define set_led_cyan    red_led_off; grn_led_on;  blu_led_on
#define set_led_white   red_led_on;  grn_led_on;  blu_led_on

/*
#define LED_B 5
#define LED_R 6
#define LED_G 7

#define all_leds_off PORTF &= ~(1<<LED_B) & ~(1<<LED_R) & ~(1<<LED_G)

#define red_led_on   PORTF |= (1<<LED_R)
#define red_led_off  PORTF &= ~(1<<LED_R)
#define grn_led_on   PORTF |= (1<<LED_G)
#define grn_led_off  PORTF &= ~(1<<LED_G)
#define blu_led_on   PORTF |= (1<<LED_B)
#define blu_led_off  PORTF &= ~(1<<LED_B)

#define set_led_off     PORTF &= ~(1<<LED_B) & ~(1<<LED_R) & ~(1<<LED_G)
#define set_led_red     PORTF = PORTF & ~(1<<LED_B) & ~(1<<LED_G) | (1<<LED_R)
#define set_led_blue    PORTF = PORTF & ~(1<<LED_G) & ~(1<<LED_R) | (1<<LED_B)
#define set_led_green   PORTF = PORTF & ~(1<<LED_B) & ~(1<<LED_R) | (1<<LED_G)
#define set_led_yellow  PORTF = PORTF & ~(1<<LED_B) | (1<<LED_R) | (1<<LED_G)
#define set_led_magenta PORTF = PORTF & ~(1<<LED_G) | (1<<LED_R) | (1<<LED_B)
#define set_led_cyan    PORTF = PORTF & ~(1<<LED_R) | (1<<LED_B) | (1<<LED_G)
#define set_led_white   PORTF |= (1<<LED_B) | (1<<LED_R) | (1<<LED_G)
*/

// This a shortcut to help you visually see your layout.
// The first section contains all of the arguments
// The second converts the arguments into a two-dimensional array
#define LAYOUT( \
	K11, K21, K31, K41, K51, K61, K71, K81, K15, K25, K35, K45, K55, K65, K75,  \
	K12, K22, K32, K42, K52, K62, K72, K82, K16, K26, K36, K46, K56, K66, K76,  \
	K13, K23, K33, K43, K53, K63, K73, K83, K17, K27, K37, K47, K57, K67, K77,  \
	K14, K24, K34, K44, K54, K64, K74, K84, K18, K28, K38, K48, K58, K68, K78   \
) \
{ \
	{ K11,   K21,   K31,	K41,	K51,	K61,	K71,	K81 }, \
	{ K12,   K22,   K32,	K42,	K52,	K62,	K72,	K82 }, \
	{ K13,   K23,   K33,	K43,	K53,	K63,	K73,	K83 }, \
	{ K14,   K24,   K34,	K44,	K54,	K64,	K74,	K84 }, \
	{ K15,   K25,   K35,	K45,	K55,	K65,	K75,	    }, \
	{ K16,   K26,   K36,	K46,	K56,	K66,	K76,	    }, \
	{ K17,   K27,   K37,	K47,	K57,	K67,	K77,	    }, \
	{ K18,   K28,   K38,	K48,	K58,	K68,	K78	    }  \
}

#define LAYOUT_60_ansi LAYOUT
#endif

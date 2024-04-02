// **************************************************************************
//
//               Demo program for APPS labs
//
// Subject:      Computer Architectures and Parallel systems
// Author:       Petr Olivka, petr.olivka@vsb.cz, 03/2024
// Organization: Department of Computer Science, FEECS,
//               VSB-Technical University of Ostrava, CZ
//
// File:         Main program for LEDs
//
// **************************************************************************

#include "mbed.h"

// LEDs on K64F-KIT - instances of class DigitalOut
DigitalOut g_led_PTA1( PTA1 );
DigitalOut g_led_PTA2( PTA2 );

// Button on K64F-KIT - instance of class DigitalIn
DigitalIn g_but_PTC9( PTC9 );
DigitalIn g_but_PTC10( PTC10 );
DigitalIn g_but_PTC11( PTC11 );
DigitalIn g_but_PTC12( PTC12 );

void control_from_ticker()
{
	static int l_ticks = 0;

	int32_t l_periode = 500;		// T = 0.5 sec

	if ( g_but_PTC9 == 0 )			// check button
	{
		l_periode /= 10;			// increase speed of blinking
	}

	if ( l_ticks < l_periode / 2 )	// time to switch on or off?
	{
		g_led_PTA1 = 0;				// LED Off
	}
	else
	{
		g_led_PTA1 = 1;				// LED On
	}

	l_ticks++;						// milliseconds counter
	if ( l_ticks >= l_periode )		// end of periode?
	{
		l_ticks = 0;				// start periode again
	}
}

int main()
{
	printf( "LED demo program started...\n" );

#if 1
	// modern approach with timer (and interrupt)
	Ticker l_ticker;

	l_ticker.attach( control_from_ticker, 1ms );

	while ( 1 )
	{ // infinite loop
	}

#else

	// lazy (conservative) approach
	while ( 1 )
	{
		int32_t l_periode = 500000;	// T = 500000 us = 0.5 sec

		if (g_but_PTC9 == 0) 		// button pressed?
		{
			l_periode /= 10;	    // speed up blinking
		}

		g_led_PTA1 = 0;				// LED off

		wait_us( l_periode / 2 );

		g_led_PTA1 = 1;				// LED on

		wait_us( l_periode / 2 );
	}

#endif
}

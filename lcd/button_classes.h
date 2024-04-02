#ifndef __button_classes_h__
#define __button_classes_h__

#include "mbed.h"

#define T 20
#define DBG 0
#define ARR_LEN(x) sizeof(x)/sizeof(*x)

class PWMDigOutRGB {
	Ticker 		m_ticker;
    DigitalOut 	m_r, m_g, m_b;
    uint8_t 	m_val1, m_val2, m_val3;
    uint32_t 	m_T1, m_T2, m_T3;
    uint32_t 	m_ticks1, m_ticks2, m_ticks3;
    void pwm_control();

public:
    PWMDigOutRGB(PinName t_pin1, PinName t_pin2, PinName t_pin3);
    void set_color(uint8_t t_r, uint8_t t_g, uint8_t t_b);

    uint8_t get_r() const;
    uint8_t get_g() const;
    uint8_t get_b() const;

};

class PWMDigOut {
private:
	Ticker 		m_ticker;
    DigitalOut 	m_led;
    uint8_t 	m_jas;
    uint32_t 	m_T;
    uint32_t 	m_ticks;
    void pwm_control();

public:
    PWMDigOut(PinName t_led_pin);
    void nastav_jas_proc(uint8_t t_jas);
    uint8_t get_bright() const;

};

#define T_btn 100000   // cooldown in ms?

class BTN_NOT {
private:
	Ticker 		m_ticker;
	DigitalIn 	m_btn;
	bool* 		m_state;
	uint32_t 	m_T;
	uint32_t 	m_ticks;
	bool 		m_pressed;

public:
	BTN_NOT(PinName t_pin, bool* t_state);
	void btn_control();
	int get_btn_state();
};

class BTN_SET {
private:
	Ticker 		m_ticker;
	DigitalIn 	m_btn;
	bool* 		m_true_state;
	bool* 		m_false_state;
	uint32_t 	m_T;
	uint32_t 	m_ticks;
	bool 		m_pressed;

public:
	BTN_SET(PinName t_pin, bool* t_true_state, bool* t_false_state);
	void btn_control();
};

#endif//__button_classes_h__
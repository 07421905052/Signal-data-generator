#ifndef FUNCTION_H
#define FUNCTION_H
#include "sine_wave.h"

void value_of_frequency(sine_wave *sine_wave);
void value_of_phase(sine_wave *sine_wave);
void value_of_Vpp(sine_wave *sine_wave);
void value_of_Voffset(sine_wave *sine_wave);
void value_of_Vhigh(sine_wave *sine_wave);
void value_of_Vlow(sine_wave *sine_wave);
void value_of_length(sine_wave *sine_wave);
void value_of_sample_frequency(sine_wave *sine_wave);
void value_of_noise(sine_wave *sine_wave);
void value_of_choose(sine_wave *sine_wave);
void sine_wave_menu(sine_wave *sine_wave);
void print_sine_wave_menu(sine_wave *sine_wave);
void select_sine_wave_menu_item(int input, sine_wave *sine_wave);
void coordinate(sine_wave *sine_wave);
//void go_back_to_sine_wave_menu();
#endif
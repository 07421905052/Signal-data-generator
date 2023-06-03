#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "TriWave.h"
#include "modulate.h"
void print_parameter_menu(TriWave *triwave);//////////////////////////////////
void select_parameter_menu(TriWave *triwave);
void select_parameter_item(int input, TriWave *triwave);
void change_frequency(TriWave *triwave);
void change_phase(TriWave *triwave);
void change_Vpp(TriWave *triwave);
void change_Voffset(TriWave *triwave);
void change_Vhigh(TriWave *triwave);
void change_Vlow(TriWave *triwave);
void change_Vmode(TriWave *triwave);
void change_sample_frequency(TriWave *triwave);
void change_sample_points(TriWave *triwave);
void generate_signal(TriWave *triwave);
void after_generate_menu();
void print_after_menu();
void select_after_menu(int input);
void change_noise(TriWave *triwave);

void AM_modulate(TriWave *triwave);
void print_AM_menu(Modulate *modulate);
void select_AM_menu(TriWave *triwave, Modulate *modulate);
void select_AM_item(int input, TriWave *triwave, Modulate *modulate);
void generate_modulated_signal(TriWave *triwave, Modulate *modulate);


#endif // FUNCTIONS_H

#include "sine_wave.h"

#include <iostream>
#include <regex>

sine_wave::sine_wave(){
  _frequency = 1;
  _phase = 0;
  _Vpp = 4;
  _Voffset = 0;
  _Vhigh = 2;
  _Vlow = -2;
  _length = 10;
  _sample_frequency = 1;
  _noise = 0;
  _choose = 0;
}

void sine_wave::set_frequency(double frequency){
  _frequency = frequency;
}
void sine_wave::set_phase(double phase){
  _phase = phase;
}
void sine_wave::set_Vpp(double Vpp){
  _Vpp = Vpp;
}
void sine_wave::set_Voffset(double Voffset){
  _Voffset = Voffset;
}
void sine_wave::set_Vhigh(double Vhigh){
  _Vhigh = Vhigh;
}
void sine_wave::set_Vlow(double Vlow){
  _Vlow = Vlow;
}
void sine_wave::set_length(int length){
  _length = length;
}
void sine_wave::set_sample_frequency(double sample_frequency){
  _sample_frequency = sample_frequency;
}
void sine_wave::set_noise(bool noise){
  _noise = noise;
}
void sine_wave::set_choose(bool choose){
  _choose = choose;
}

double sine_wave::get_frequency(){
  return _frequency;
}
double sine_wave::get_phase(){
  return _phase;
}
double sine_wave::get_Vpp(){
  return _Vpp;
}
double sine_wave::get_Voffset(){
  return _Voffset;
}
double sine_wave::get_Vhigh(){
  return _Vhigh;
}
double sine_wave::get_Vlow(){
  return _Vlow;
}
int sine_wave::get_length(){
  return _length;
}
double sine_wave::get_sample_frequency(){
  return _frequency;
}
bool sine_wave::get_noise(){
  return _noise;
}
bool sine_wave::get_choose(){
  return _choose;
}

   
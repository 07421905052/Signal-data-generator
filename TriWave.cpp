#include "TriWave.h"

TriWave::TriWave(){
    _frequency = 1;
    _Vpp = 2;
    _Voffset = 0;
    _Vlow = -1;
    _Vhigh = 1;
    _phase = 0;
    _Vmode = 0;
    _sample_frequency = 50; //under this default value, we should able to see 2 complete period of a 1kHz signal.
    _sample_points = 100;
    _noise = 0; //Noise function is off by default

    _unit_frequency = "kHz";
    _unit_V = "V";
}

double TriWave::get_frequency(){
    return _frequency;
}

double TriWave::get_Vpp(){
    return _Vpp;
}

double TriWave::get_Voffset(){
    return _Voffset;
}

double TriWave::get_Vlow(){
    return _Vlow;
}

double TriWave::get_Vhigh(){
    return _Vhigh;
}

double TriWave::get_phase(){
    return _phase;
}

bool TriWave::get_Vmode(){
    return _Vmode;
}

bool TriWave::get_noise(){
    return _noise;
}

double TriWave::get_sample_frequency(){
    return _sample_frequency;
}

int TriWave::get_sample_points(){
    return _sample_points;
}

string TriWave::get_unit_frequency(){
    return _unit_frequency;
}

string TriWave::get_unit_V(){
    return _unit_V;
}

void TriWave::set_frequency(double frequency){
    _frequency = frequency;
}

void TriWave::set_Vpp(double Vpp){
    _Vpp = Vpp;
}
void TriWave::set_Voffset(double Voffset){
    _Voffset = Voffset;
}
void TriWave::set_Vlow(double Vlow){
    _Vlow = Vlow;
}
void TriWave::set_Vhigh(double Vhigh){
    _Vhigh = Vhigh;
}
void TriWave::set_phase(double phase){
    _phase = phase;
}
void TriWave::set_unit_frequency(string unit_frequency){
    _unit_frequency = unit_frequency;
}
void TriWave::set_unit_V(string unit_V){
    _unit_V = unit_V;
}

void TriWave::set_Vmode(bool Vmode){
    _Vmode = Vmode;
}
void TriWave::set_noise(bool noise){
    _noise = noise;
}
void TriWave::set_sample_frequency(double sample_frequency){
    _sample_frequency = sample_frequency;
}
void TriWave::set_sample_points(int sample_points){
    _sample_points = sample_points;
}

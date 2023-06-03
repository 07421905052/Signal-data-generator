#include "modulate.h"

Modulate::Modulate(){
    _frequency = 100; //100Hz
    _depth = 100; //100%
    _type = 1; //1 for sine, 2 for square and 3 for Triangular.
}

double Modulate::get_frequency(){
    return _frequency;
}

int Modulate::get_depth(){
    return _depth;
}

int Modulate::get_type(){
    return _type;
}

void Modulate::set_frequency(double frequency){
    _frequency = frequency;
}

void Modulate::set_depth(int depth){
    _depth = depth;
}

void Modulate::set_type(int type){
    _type = type;
}

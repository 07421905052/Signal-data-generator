#include "select.h"

Select::Select(){
    _waveform1 = 1;//sin
    _waveform2 = 2;//square
    _operation = 1;//triangular

}

int Select::get_waveform1(){
    return _waveform1;
}
int Select::get_waveform2(){
    return _waveform2;
}
int Select::get_operation(){
    return _operation;
}

void Select::set_waveform1(int waveform1){
    _waveform1 = waveform1;
}

void Select::set_waveform2(int waveform2){
    _waveform2 = waveform2;
}

void Select::set_operation(int operation){
    _operation = operation;
}

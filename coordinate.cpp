#include "coordinate.h"
#include <iostream>
#include "sine_wave.h"
#include <math.h>
#include <time.h>
#include <stdio.h> 
#include <stdlib.h>

void caculate_coordinate::set_abscissa(double abscissa) { _abscissa = abscissa; }
double caculate_coordinate::get_coordinate() {
sine_wave sine_wave;//*sine_wave class object instead of an address
double A1;
double A2;
double W;
double PH;
double C1;
double C2;
A2 = sine_wave.get_Vhigh()-sine_wave.get_Vlow(); //use "." instead of -> because now sine_wave is a class object, not an address.
A1 = sine_wave.get_Vpp();
W = 2*PI*sine_wave.get_frequency();
PH = sine_wave.get_phase();
C2 = (sine_wave.get_Vhigh()+sine_wave.get_Vlow())/2;
C1 = sine_wave.get_Voffset();

if(sine_wave.get_choose() == 0){
  std::cout << "A1*sin(W*_abscissa+PH)+C1 = " << A1 << "*sin(" <<W<<"*"<<_abscissa<<"+"<<PH << std::endl;
    _coordinate = A1*sin(W*_abscissa+PH)+C1;
    }
  else{ 
    std::cout << "A2*sin(W*_abscissa+PH)+C2 = " << A2 << "*sin(" <<W<<"*"<<_abscissa<<"+"<<PH << std::endl;
    _coordinate = A2*sin(W*_abscissa+PH)+C2; 
    
  }

return _coordinate;
  }

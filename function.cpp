#include "function.h"
#include "sine_wave.h"
#include "main.h"
#include "coordinate.h"
#include <iostream>
#include <math.h>
#include <bitset>
#include <fstream>　// c++文件操作
#include <iomanip>　// 设置输出格式

void sine_wave_menu(sine_wave *sine_wave) {
  print_sine_wave_menu(sine_wave);
  int input = get_user_input(11);
  select_sine_wave_menu_item(input,sine_wave);
}

/*void go_back_to_sine_wave_menu() {
  std::string input;
  do {
    std::cout << "\nEnter 7 to go back to sine wave menu: ";
    std::cin >> input;
  } while (input != "7");
  sine_wave_menu();
}*/



void select_sine_wave_menu_item(int input, sine_wave *sine_wave) {
  switch (input) {
    case 1:
      value_of_frequency(sine_wave);
      break;
    case 2:
      value_of_phase(sine_wave);
      break;
    case 3:
      value_of_Vpp(sine_wave);
      break;
    case 4:
      value_of_Voffset(sine_wave);
      break;
    case 5:
      value_of_Vhigh(sine_wave);
      break;
    case 6:
      value_of_Vlow(sine_wave);
      break;
    case 7:
      value_of_length(sine_wave);
      break;
    case 8:
      value_of_sample_frequency(sine_wave);
      break;
    case 9:
      value_of_noise(sine_wave);
      break;
    case 10:
      value_of_choose(sine_wave);
      break;
    case 11:
      coordinate(sine_wave);
    default:
      main_menu();
      break;
  }
}

void print_sine_wave_menu(sine_wave *sine_wave){
  std::cout << "\n--------------------------- current parameter --------------------------------\n";
  std::cout << "|\t\t\t\t|\n";
  std::cout << "|\t1. Frenquancy:"<<sine_wave->get_frequency()<<" kHz\t2.Phase:"<<sine_wave->get_phase()<<" °|\n";
  std::cout << "|\t3. Vpp:"<<sine_wave->get_Vpp()<<" V\t4.Voffset:"<<sine_wave->get_Voffset()<<" V|\n";
  std::cout << "|\t5. Vhigh:"<<sine_wave->get_Vhigh()<<" V\t6.Vlow:"<<sine_wave->get_Vlow()<<" V|\n";
  std::cout << "|\t7. length:"<<sine_wave->get_length()<<" \t8.sample_frequency:"<<sine_wave->get_sample_frequency()<<" V|\n";
  std::cout << "|\t9. noise: ";
  if(sine_wave->get_noise() == 0){
    std::cout << "off";
    }
  else{
    std::cout << "on";
  }
std::cout << "|\t10. choose: ";
  if(sine_wave->get_choose() == 0){
    std::cout << "Voffset and VPP";
    }
  else{
    std::cout << "Von and Vlow";
  }

  std::cout << "|\t\t\t\t|\n";
  std::cout << "---------------------------------------------------------------------------------\n";
  std::cout << "Enter corresponding number to adjust the parameter"<<"\tEnter 11 to generate the wave";
    }

void value_of_frequency(sine_wave *sine_wave) {
   std::cout << "please enter the frequency you want to set\n";
   double frequency;
   std::cin >> frequency;
  while(frequency<=0){
    std::cout << "please enter a positive value\n";
    std::cin >> frequency;
  }
  sine_wave->set_frequency(frequency);
  sine_wave_menu(sine_wave);
}


void value_of_phase(sine_wave *sine_wave) {
   std::cout << "please enter the phase you want to set\n";
   double phase;
   std::cin >> phase;
   while(phase<-90&phase>90){
   std::cout << "please enter a value between -90 and 90\n";
   std::cin >> phase;
  }
  sine_wave->set_phase(phase);
  sine_wave_menu(sine_wave);
  }
void value_of_Vpp(sine_wave *sine_wave) {
   std::cout << "please enter the Vpp you want to set\n";
   double Vpp;
   std::cin >> Vpp;
   while(Vpp<=0){
   std::cout << "please enter a positive value\n";
   std::cin >> Vpp;
  }
  sine_wave->set_Vpp(Vpp);
  sine_wave_menu(sine_wave);
  }
void value_of_Voffset(sine_wave *sine_wave) {
   std::cout << "please enter the Voffset you want to set\n";
   double Voffset;
   std::cin >> Voffset;
  sine_wave_menu(sine_wave);
  }
void value_of_Vhigh(sine_wave *sine_wave) {
   std::cout << "please enter the frequency you want to set\n";
   double Vhigh;
   std::cin >> Vhigh;
   sine_wave->set_Vhigh(Vhigh);
  sine_wave_menu(sine_wave);
  }
void value_of_Vlow(sine_wave *sine_wave) {
   std::cout << "please enter the frequency you want to set\n";
   double Vlow;
   std::cin >> Vlow;
   sine_wave->set_Vlow(Vlow);
  sine_wave_menu(sine_wave);
  }
void value_of_length(sine_wave *sine_wave) {
   std::cout << "please enter the length you want to set\n";
   double length;
   std::cin >> length;
  while(length<=0){
    std::cout << "please enter a positive value\n";
    std::cin >> length;
  }
  sine_wave->set_frequency(length);
  sine_wave_menu(sine_wave);
}
void value_of_sample_frequency(sine_wave *sine_wave) {
   std::cout << "please enter the sample frequency you want to set\n";
   double sample_frequency;
   std::cin >> sample_frequency;
  while(sample_frequency<=0){
    std::cout << "please enter a positive value\n";
    std::cin >> sample_frequency;
  }
  sine_wave->set_sample_frequency(sample_frequency);
  sine_wave_menu(sine_wave);
}

void value_of_noise(sine_wave *sine_wave) {
   std::cout << "please enter the 1 to add the noise or enter 0 not to add nosie\n";
    bool noise;
   std::cin >> noise;
   sine_wave->set_noise(noise);
  sine_wave_menu(sine_wave);
  }

void value_of_choose(sine_wave *sine_wave) {
   std::cout << "please enter 1 if you want to follow Vpp or enter 0 to follow Vhigh and Vlow\n";
   bool choose;
   std::cin >> choose;
   sine_wave->set_choose(choose);
  sine_wave_menu(sine_wave);
  }


void coordinate(sine_wave *sine_wave){
  double Y;
  double interval;
  double length;
  //double Y; //length*sample_frequency
  std::cout << "length: " <<sine_wave->get_length() << std::endl;
  std::cout << "interval: " << (sine_wave->get_length()/(1/sine_wave->get_sample_frequency()*1000)) << std::endl;
  interval = (sine_wave->get_length()/(1/sine_wave->get_sample_frequency()*1000));
  length = sine_wave->get_length();
  /*for(double i=0; i<sine_wave->get_length(); i+(sine_wave->get_length()/(1/sine_wave->get_sample_frequency()*1000))){
    std::cout << i << std::endl;
    }*/

std::ofstream out_txt_file;
out_txt_file.open("./numbers_test.txt", std::ios::out | std::ios::trunc);
out_txt_file << std::fixed;

   srand((unsigned int)time(NULL));

  for(double i = 0; i < length ; i=i+interval){
    std::cout << i << std::endl;
    caculate_coordinate caculate_coordinate;
  caculate_coordinate.set_abscissa(i);

    double num=(double)rand()/RAND_MAX;
    double q1 = (sine_wave->get_Vpp())/10;
    double q2 = (sine_wave->get_Vhigh()-sine_wave->get_Vlow())/10;
    double p1 = (sine_wave->get_Vpp())/20;
    double p2 = (sine_wave->get_Vhigh()-sine_wave->get_Vlow())/20;
    double a;
    double Y;
  if(sine_wave->get_choose() == 0){
    a = num*q1-p1;
    }
    else{
    a = num*q2-p2;
    }
  if(sine_wave->get_noise() == 0){
  Y = caculate_coordinate.get_coordinate();
  std::cout << "["<<i<<","<<Y<<"]\n";
  }
    else{
  Y = caculate_coordinate.get_coordinate()+ a ;
  std::cout << "["<<i<<","<<Y<<"]\n";
    }
    std::bitset<16> my_byte(1000*Y);
    std::cout << my_byte << std::endl;
    std::string byte_string = my_byte.to_string();
   out_txt_file <<byte_string << std::endl;
    }
  out_txt_file.close();
  /*for(double i=0; i<sine_wave->get_length(); i+(sine_wave->get_length()/(1/sine_wave->get_sample_frequency()*1000))){
  std::cout << i << std::endl;
  caculate_coordinate caculate_coordinate;
  caculate_coordinate.set_abscissa(i);
  double Y = caculate_coordinate.get_coordinate();
  std::cout << "["<<i<<","<<Y<<"]\n";
}*/

  }

#include "Squinput.h"



void Squinput::get_input(){
std::string vsf;
std::string vsp;
std::string vwf;
std::string vvp;
std::string vof;
std::string vdu;
std::string vno;
  
  std::string check = "n";
while ( check != "y"){
  std::cout << "\n\nEnter the required value of \n  (Round to 2 decimal places except Samplepoints&Noise)\n(upper limit: 65535)\n\n-1.SampleFrequency(Hz),\n"
<< "-2.Number of SamplePoint, \n"
<< "-3.WaveFrequency(Hz), \n"
<< "-4.Vpp(mV), \n"
<< "-5.Offset(mV), \n"
<< "-6.Duty Cycle, \n"
<< "-7.Noise (1/0)\n\nfor the squarewave ";
std:: cin >> vsf >> vsp >> vwf >> vvp >>vof >> vdu >> vno;

std::regex pattern("(\\d+).(\\d+)");
std::regex pattern2("[1,0]");
std::regex pattern3("[0].(\\d+)");
std::regex pattern4("\\d+");

if(regex_match(vsf, pattern) ){
    get_sfreq  = std::stoi(vsf);
 
}
else{
  std::cout << "\n*Error: Samplefrequency is not in the correct format";
  check = "e";
}
  
if(regex_match(vsp, pattern4)){

  get_spoint = std::stoi(vsp);

}
else{
  std::cout << "\n*Error: Samplepoints is not in the correct format";
  check = "e";
}

if(regex_match(vwf, pattern)){
  
    get_wfreq = std::stoi(vwf);
}
else{
  std::cout << "\n*Error: Wavefrequency is not in the correct format";
  check = "e";
}

if(regex_match(vvp, pattern)){
  
    get_vpp = std::stoi(vvp);

    
  
}
else{
  std::cout << "\n*Error: Vpp is not in the correct format";
  check = "e";
}

if(regex_match(vof, pattern)){
  
    get_off = std::stoi(vof);


  
}
else{
  std::cout << "\n*Error: Offset is not in the correct format(smaller than 1&round to 2 decimal places)";
  check = "e";
}

if(regex_match(vdu, pattern3)){
  
    get_duty = std::stod(vdu);
  
}
else{
  std::cout << "\n*Error: Dutycycle is not in the correct format";
  check = "e";
}

if(regex_search(vno, pattern2)){
  
  get_noise = std::stoi(vno);

    
  
}
else{
  std::cout << "\n*Error: Noise is not in the correct format";
  check = "e";
}


//mke sure the samplefrequency is over Nyquist Sampling Rate.
  
if (get_sfreq < 2*get_wfreq && check =="n"){
  std::cout << "\n*Error:Samplefrequency must bigger than 2*WaveFrequency\n\nEnter the new Samplefrequncey:";
  std::cin >> get_sfreq;
}
// check the inputs.
if (check != "e"){
  std::cout << "\n\n\nYou have set the following value:\n" << "-SampleFrequency: " << get_sfreq << "\n-Number of SamplePoint: " << get_spoint << "\n-WaveFrequency: " <<
  get_wfreq << "\n-Vpp: " << get_vpp << "\n-Offset: " << get_off << "\n-Duty Cycle: " << get_duty << "\n-Noise: " << get_noise;
  std::cout << "\n\nIs the settings correct? (y/n)";
  std::cin >> check;
  if ( check == "y"){
  std::cout << "\nThe new wave is generated\n";
}
  }
}
  
}


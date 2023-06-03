#include "Modi.h"

void Modi::select1wave(){
  
    std::string mod;
    std::cout << "\n\nYou have created 1 wave. Do you want to modify \n -1.Wave1 \n -2.No modification\n  (1/2)" << std::endl;
    std::cin >> mod;
    if(mod == "1"){
      Create create11;
      create11.wavedata1create();
      std::cout << "\nWave1 has been Modified."<< std::endl;
    }
  else{
    Squmenu squmenu1;
    squmenu1.squarewave_menu();
  }
  
}

void Modi::select2wave(){
  
    std::string mod;
    std::cout << "\n\nYou have created 2 wave. Do you want to \n --1.modify Wave1 \n --2.Wave2 \n --3.No modification\n  (1/2/3)" << std::endl;
    std::cin >> mod;
  
    if(mod == "1"){
      Create create11;
      create11.wavedata1create();
      // wavedata1create change count to 1 so we need recover count 
      // to 2
      std::ofstream count;
      count.open("count.txt");
      count << "2" << std::endl;
  count.close();
      std::cout << "\nWave1 has been Modified."<< std::endl;
    }
  
  if(mod == "2"){
      Create create22;
      create22.wavedata2create();
      std::cout << "\nWave2 has been Modified."<< std::endl;
    }
  else{
    Squmenu squmenu1;
    squmenu1.squarewave_menu();
  }
  
}

void Modi::select3wave(){
  
    std::string mod;
    std::cout << "\n\nYou have created 3 waves. Do you want to \n --1.modify Wave1 \n --2.Wave2 \n --3.Wave3\n --4.No modification\n  (1/2/3/4)" << std::endl;
  
    std::cin >> mod;
  
    if(mod == "1"){
      Create create11;
      create11.wavedata1create();
      // wavedata1create change count to 1 so we need recover count 
      // to 2
      std::ofstream count;
      count.open("count.txt");
      count << "3" << std::endl;
  count.close();
      std::cout << "\nWave1 has been Modified."<< std::endl;
    }
  
  if(mod == "2"){
      Create create22;
      create22.wavedata2create();
      std::ofstream count;
      count.open("count.txt");
      count << "3" << std::endl;
      count.close();
      std::cout << "\nWave2 has been Modified."<< std::endl;
    }

  if(mod == "3"){
      Create create33;
      create33.wavedata3create();
      std::cout << "\nWave3 has been Modified."<< std::endl;
    }
  else{
    Squmenu squmenu1;
    squmenu1.squarewave_menu();
  }
  
}
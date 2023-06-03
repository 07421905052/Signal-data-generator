#include "Create.h"

// set parameters&create wavedata
void Create::wavedata1create(){
  
  Squinput squinput;
  squinput.get_input();
  double sf = squinput.get_sfreq;
  int sp = squinput.get_spoint;
  double wf = squinput.get_wfreq;
  int vp = squinput.get_vpp;
  int of = squinput.get_off;
  double dc = squinput.get_duty;
  double no = squinput.get_noise;
  
  
  std::ofstream squwave1;
  
  // use it to open a file named 'output.txt'
  squwave1.open("squwave1.txt");
  // check if the file is not open
  if (!squwave1.is_open()) {
    // print error message and quit if a problem occurred
    std::cerr << "Error creating file!\n";
    exit(1);
  }

  
  for(int i=1; i<=sp; i++){
    
   int h=0;
    if(1.0/wf*dc < 1.0/sf*i < 1.0/wf){
      h = of;
      if(no==1){
        h = h+rand() % 10 + 0;
        
      }
      
    }
    else{
      if (fmod(1.0/sf*i,1.0/wf) < dc*(1.0/wf)){
        h = vp+of;
        if(no==1){
        h = h+rand() % 10 + 0;
       
      }
          
        }
        
      else{
      h = of;
      if(no==1){
        h = h+rand() % 10 + 0;
      }
        
    }
    }
   std::cout << h <<std::endl;
    
    int n=0, bin[16]={},length = 0;

  if( h==1 ){
    squwave1 <<"0000000000000001"<< std::endl;
  }
  else{ do
	{
		bin[n] = fmod(h,2);
		h = h / 2;
		n++;
		length++;
	} while (h != 1);
    
	bin[length] = h;
	length++;
    
    for(int a=15; a>length-1; a--){
    squwave1 << 0;
      }
	for (n = length - 1; n >= 0; n--){
		squwave1 << bin[n] ;
    }
    
	squwave1 << "\n" ;
  }
    }
  squwave1.close();
  

  //count for how many wavefile
  std::ofstream count;
  count.open("count.txt");
  count << "1" << std::endl;
  // always remember to close a filestream when done
  count.close();
}


void Create::wavedata2create(){
  
  Squinput squinput;
  squinput.get_input();
  double sf = squinput.get_sfreq;
  int sp = squinput.get_spoint;
  double wf = squinput.get_wfreq;
  int vp = squinput.get_vpp;
  int of = squinput.get_off;
  double dc = squinput.get_duty;
  double no = squinput.get_noise;
  
  
  std::ofstream squwave2;
  
  // use it to open a file named 'output.txt'
  squwave2.open("squwave2.txt");
  // check if the file is not open
  if (!squwave2.is_open()) {
    // print error message and quit if a problem occurred
    std::cerr << "Error creating file!\n";
    exit(1);
  }

  
  for(int i=1; i<=sp; i++){
    
   int h=0;
    if(1.0/wf*dc < 1.0/sf*i < 1.0/wf){
      h = of;
      if(no==1){
        h = h+rand() % 10 + 0;
        
      }
      
    }
    else{
      if (fmod(1.0/sf*i,1.0/wf) < dc*(1.0/wf)){
        h = vp+of;
        if(no==1){
        h = h+rand() % 10 + 0;
       
      }
          
        }
        
      else{
      h = of;
      if(no==1){
        h = h+rand() % 10 + 0;
      }
        
    }
    }
   std::cout << h <<std::endl;
    
    int n=0, bin[16]={},length = 0;

  if( h==1 ){
    squwave2 <<"0000000000000001"<< std::endl;
  }
  else{ do
	{
		bin[n] = fmod(h,2);
		h = h / 2;
		n++;
		length++;
	} while (h != 1);
    
	bin[length] = h;
	length++;
    
    for(int a=15; a>length-1; a--){
    squwave2 << 0;
      }
	for (n = length - 1; n >= 0; n--){
		squwave2 << bin[n] ;
    }
    
	squwave2 << "\n" ;
  }
    }
  squwave2.close();
  

  //count for how many wavefile
  std::ofstream count;
  count.open("count.txt");
  count << "2" << std::endl;
  // always remember to close a filestream when done
  count.close();
}


void Create::wavedata3create(){
  
  Squinput squinput;
  squinput.get_input();
  double sf = squinput.get_sfreq;
  int sp = squinput.get_spoint;
  double wf = squinput.get_wfreq;
  int vp = squinput.get_vpp;
  int of = squinput.get_off;
  double dc = squinput.get_duty;
  double no = squinput.get_noise;
  
  
  std::ofstream squwave3;
  
  // use it to open a file named 'output.txt'
  squwave3.open("squwave3.txt");
  // check if the file is not open
  if (!squwave3.is_open()) {
    // print error message and quit if a problem occurred
    std::cerr << "Error creating file!\n";
    exit(1);
  }

  
  for(int i=1; i<=sp; i++){
    
   int h=0;
    if(1.0/wf*dc < 1.0/sf*i < 1.0/wf){
      h = of;
      if(no==1){
        h = h+rand() % 10 + 0;
        
      }
      
    }
    else{
      if (fmod(1.0/sf*i,1.0/wf) < dc*(1.0/wf)){
        h = vp+of;
        if(no==1){
        h = h+rand() % 10 + 0;
       
      }
          
        }
        
      else{
      h = of;
      if(no==1){
        h = h+rand() % 10 + 0;
      }
        
    }
    }
   std::cout << h <<std::endl;
    
    int n=0, bin[16]={},length = 0;

  if( h==1 ){
    squwave3 <<"0000000000000001"<< std::endl;
  }
  else{ do
	{
		bin[n] = fmod(h,2);
		h = h / 2;
		n++;
		length++;
	} while (h != 1);
    
	bin[length] = h;
	length++;
    
    for(int a=15; a>length-1; a--){
    squwave3 << 0;
      }
	for (n = length - 1; n >= 0; n--){
		squwave3 << bin[n] ;
    }
    
	squwave3 << "\n" ;
  }
    }
  squwave3.close();
  

  //count for how many wavefile
  std::ofstream count;
  count.open("count.txt");
  count << "3" << std::endl;
  // always remember to close a filestream when done
  count.close();
}

//create file to contain wave data
//https://elec2645.github.io/102/constructor.html




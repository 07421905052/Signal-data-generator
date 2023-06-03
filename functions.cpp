#include "functions.h"
#include <iostream>
#include "main.h"
#include <time.h>
#include <fstream>///////////////////////////////////////////
#include <bitset>///////////////////////////////
#include <cmath>

void print_parameter_menu(TriWave *triwave){
  std::cout << "\n>> Triangular Wave\n";
  std::cout << "\n--------------- Current parameters ---------------\n";
  std::cout << "\n|\t1.Frequency: " << triwave->get_frequency() << " " << triwave->get_unit_frequency() << "\t2.Phase: " << triwave->get_phase() << ""  << std::endl;
  std::cout << "\n|\t3.Vpp: " << triwave->get_Vpp() << " " << triwave->get_unit_V() << "\t\t4.Voffset: " << triwave->get_Voffset() << " " << triwave->get_unit_V() ;
        if(triwave->get_Vmode() == 0){
            cout << "  <- CURRENT MODE" << endl;
        }
        else{
            cout << endl;
        }
  std::cout << "\n|\t5.Vhigh: " << triwave->get_Vhigh() << " " << triwave->get_unit_V() << "\t\t6.Vlow: " << triwave->get_Vlow() << " " << triwave->get_unit_V();
        if(triwave->get_Vmode() == 1){
            cout << "  <- CURRENT MODE" << endl;
        }
        else{
            cout << endl;
        }
  std::cout << "\n|\t7.Change Voltage representation mode\n";
  std::cout << "\n|\t8.Sample frequency: " << triwave->get_sample_frequency() << " " << "kHz\t9.Sample points: " << triwave->get_sample_points() << std::endl;
  std::cout << "\n|\tNoise off";
        if(triwave->get_noise() == 0){
            cout << "  <- CURRENT MODE" << endl;
        }
        else{
            cout << endl;
        }
  std::cout << "\n|\tNoise on";
        if(triwave->get_noise() == 1){
            cout << "  <- CURRENT MODE" << endl;
        }
        else{
            cout << endl;
        }
  std::cout << "\n--------------------------------------------------\n";
  std::cout << "Enter corresponding number to adjust the parameter\n";
  std::cout << "Press 10 to generate the signal\n";
  std::cout << "Press 11 to add/remove noise to/from the signal\n";
  std::cout << "Press 12 to use AM modulate mode\n";
  std::cout << "Or press 13 to go back to main menu\n";
  std::cout << "--------------------------------------------------\n";
}

void select_parameter_item(int input, TriWave *triwave){
    switch(input){
    case 1:
      change_frequency(triwave);
      break;
    case 2:
      change_phase(triwave);
      break;
    case 3:
      change_Vpp(triwave);
      break;
    case 4:
      change_Voffset(triwave);
      break;
    case 5:
      change_Vhigh(triwave);
    case 6:
      change_Vlow(triwave);
    case 7:
      change_Vmode(triwave);
    case 8:
      change_sample_frequency(triwave);
    case 9:
      change_sample_points(triwave);
    case 10:
      generate_signal(triwave);
    case 11:
      change_noise(triwave);
    case 12:
      AM_modulate(triwave);
    default:
      main_menu();
      break;
    }
}

void select_parameter_menu(TriWave *triwave){
    print_parameter_menu(triwave);
    int input = get_user_input(13);
    select_parameter_item(input, triwave);
}
void change_frequency(TriWave *triwave){
    double frequency;
    cout << "Please enter the frequency:" << endl;
    cin >> frequency;
    while(frequency <= 0){
        cout << "Please enter a positive number!";
        cin >> frequency;
    }
    triwave->set_frequency(frequency);
    select_parameter_menu(triwave); //go back to the previous menu and allow the user to modify other values.
}

void change_phase(TriWave *triwave){
    double phase;
    cout << "Please enter the phase:" << endl;
    cin >> phase;
    while(phase > 90 || phase < -90){
        cout << "Please enter a number between -90 and 90!";
        cin >> phase;
    }
    triwave->set_phase(phase);
    select_parameter_menu(triwave);
}

void change_Vpp(TriWave *triwave){
    double Vpp;
    cout << "Please enter the Vpp:" << endl;
    cin >> Vpp;
    while(Vpp <= 0){
        cout << "Please enter a positive number!";
        cin >> Vpp;
    }
    triwave->set_Vpp(Vpp);
    select_parameter_menu(triwave);
}

void change_Voffset(TriWave *triwave){
    double Voffset;
    cout << "Please enter the Voffset:" << endl;
    cin >> Voffset;

    triwave->set_Voffset(Voffset);
    select_parameter_menu(triwave);
}

void change_Vhigh(TriWave *triwave){
    double Vhigh;
    cout << "Please enter the Vhigh:" << endl;
    cin >> Vhigh;
    while(Vhigh < triwave->get_Vlow()){
        cout << "Vhigh cannot be lower than Vlow! New Vhigh value: ";
        cin >> Vhigh;
    }
    triwave->set_Vhigh(Vhigh);
    select_parameter_menu(triwave);
}

void change_Vlow(TriWave *triwave){
    double Vlow;
    cout << "Please enter the Vlow:" << endl;
    cin >> Vlow;
    while(Vlow > triwave->get_Vhigh()){
        cout << "Vlow cannot be higher than Vhigh! New Vlow value: ";
        cin >> Vlow;
    }
    triwave->set_Vlow(Vlow);
    select_parameter_menu(triwave);
}

void change_Vmode(TriWave *triwave){
    bool mode = triwave->get_Vmode();
    mode = !mode;
    triwave->set_Vmode(mode);
    select_parameter_menu(triwave);
}

void change_noise(TriWave *triwave){
    bool noise = triwave->get_noise();
    noise = !noise;
    triwave->set_noise(noise);
    select_parameter_menu(triwave);
}

void change_sample_frequency(TriWave *triwave){
    double sample_frequency;
    cout << "Please enter the sample frequency:" << endl;
    cin >> sample_frequency;
    while(sample_frequency <= 0){
        cout << "Please enter a positive number!";
        cin >> sample_frequency;
    }
    triwave->set_sample_frequency(sample_frequency);
    select_parameter_menu(triwave);
}

void change_sample_points(TriWave *triwave){
    double sample_points;
    cout << "Please enter the sample points:" << endl;
    cin >> sample_points;
    while(sample_points <= 0){
        cout << "Please enter a positive number!";
        cin >> sample_points;
    }
    triwave->set_sample_points(sample_points);
    select_parameter_menu(triwave);
}

void generate_signal(TriWave *triwave){
    double frequency;
    if(triwave->get_unit_frequency() == "kHz"){
        frequency = triwave->get_frequency()*1000;
    }
    else{
        frequency = triwave->get_frequency();
    }
    double phase = triwave->get_phase();
    double sample_frequency = triwave->get_sample_frequency()*1000;
    int sample_points = triwave->get_sample_points();
    double Voffset, Vpp;
    bool sign = 0;
    if(triwave->get_Vmode() == 0){

        Voffset = triwave->get_Voffset();
        Vpp = triwave->get_Vpp();
    }
    else{

        Voffset = (triwave->get_Vhigh()+triwave->get_Vlow())/2;
        Vpp = triwave->get_Vhigh() - triwave->get_Vlow();
    }



    double voltage[sample_points];
    voltage[0] = Voffset - (phase*Vpp/180);
    /*if(Voffset-(0.5*Vpp)==-1){
        cout << "equals" << endl;
    }
    else{
        cout << "unequals" << endl;
    }*/
    for(int i = 1; i< sample_points; i++){
    /*cout << "i = " << i << " voltage[" << i-1 << "] " ;
    if(voltage[i-1] <= Voffset-(0.5*Vpp)){
       cout << "is <= ";
       }
       else{
        cout << "isn't <= ";
       }
    cout << "to Voffset-(0.5*Vpp)" << endl;;
    cout << voltage[i-1] << " " << Voffset-(0.5*Vpp) << endl;*/

        if ((voltage[i-1]>=(Voffset+(0.5*Vpp)-0.0001)) || (voltage[i-1] <= Voffset-(0.5*Vpp)+0.0001)){
            /*cout << "triggered at i = " << i << endl;
            cout << "Voltage[" << i-1 << "] before modificate = "<< voltage[i-1] << endl;*/
            if(sign == 0){
                voltage[i-1] = Voffset+(0.5*Vpp);
                /*cout << "Voltage[" << i-1 << "] after modificate = "<< voltage[i-1] << endl;*/
                voltage[i] = voltage[i-1] - (2*Vpp*frequency/sample_frequency);
                /*cout << "Voltage[" << i << "] = "<< voltage[i] << endl;*/
                sign = !sign;
            }
            else{
                voltage[i-1] = Voffset-(0.5*Vpp);
                /*cout << "Voltage[" << i-1 << "] after modificate = "<< voltage[i-1] << endl;*/
                voltage[i] = voltage[i-1]+ (2*Vpp*frequency/sample_frequency);
                /*cout << "Voltage[" << i << "] = "<< voltage[i] << endl;*/
                sign = !sign;
            }
        }
        else{
            if(sign == 0){
                voltage[i] = voltage[i-1] + (2*Vpp*frequency/sample_frequency);
                /*cout << "Voltage[" << i << "] = "<< voltage[i] << endl;*/
            }
            else{
                voltage[i] = voltage[i-1] - (2*Vpp*frequency/sample_frequency);
                /*cout << "Voltage[" << i << "] = "<< voltage[i] << endl;*/
            }

        }
    }





    srand(time(nullptr));
    int randnumber;
    for(int i = 0; i< sample_points; i++){
        voltage[i] = voltage[i]*100;
        if(triwave->get_noise() == 1){
            randnumber = -10+rand()%(21);
            voltage[i] = voltage[i] + randnumber;
        }
    }

    /*for(int j = 0; j < sample_points; j++){
        cout << "voltage[" << j << "] = " <<voltage[j] << endl;
    }*/


    ofstream outfile;
    outfile.open("Triangular.txt");
    for(int j = 0; j < sample_points; j++){
        int aa = voltage[j];
        bitset<16> b(aa);
        string str = b.to_string();
        outfile << str << endl;
    }
    outfile.close();





    cout << "Success!" << endl;
    after_generate_menu();

}

void after_generate_menu(){
    print_after_menu();
    int input = get_user_input(2);
    select_after_menu(input);
}

void print_after_menu(){
    std::cout << "\n--------------- Continue or End? ----------------------------------\n";
    std::cout << "\n|\t1.Go back to main menu" << "\t2.Generate another Triangular wave" << std::endl;
    std::cout << "-------------------------------------------------------------------";
}

void select_after_menu(int input){
    switch(input){
        case 1:
            main_menu();
        case 2:
            menu_item_3();
        default:
            main_menu();
    }
}

void AM_modulate(TriWave *triwave){
    Modulate modulate;
    select_AM_menu(triwave, &modulate);
}

void select_AM_menu(TriWave *triwave, Modulate *modulate){
    print_AM_menu(modulate);
    int input = get_user_input(7);
    select_AM_item(input, triwave, modulate);
}

void print_AM_menu(Modulate *modulate){
    cout << "\t\tAM Modulation" << endl;
    cout << "-----------------AM Parameters------------------\n";
    cout << "\t1.Type: Sine";
    if(modulate->get_type()==1){
        cout << " <- Current Type";
    }
    cout << endl;
    cout << "\t2.Type: Square";
    if(modulate->get_type()==2){
        cout << " <- Current Type";
    }
    cout << endl;
    cout << "\t3.Type: Triangular";
    if(modulate->get_type()==3){
        cout << " <- Current Type";
    }
    cout << endl;
    cout << "\t4.Depth: " << modulate->get_depth() << "%" << endl;
    cout << "\t5.Frequency: " << modulate->get_frequency() << " Hz" << endl;
    cout << "Enter corresponding number to adjust the parameters" << endl;
    cout << "Press 6 to generate the modulated wave" << endl;
    cout << "Press 7 to go back to the previous menu" << endl;
    cout << "---------------------------------------------------" << endl;

}

void select_AM_item(int input, TriWave *triwave, Modulate *modulate){
    switch(input){
    case 1:
        modulate->set_type(1);
        select_AM_menu(triwave, modulate);
    case 2:
        modulate->set_type(2);
        select_AM_menu(triwave, modulate);
    case 3:
        modulate->set_type(3);
        select_AM_menu(triwave, modulate);
    case 4:
        int depth;
        cout << "Please enter the depth: " << endl;
        cin >> depth;
        while( (depth<0) || (depth>100) || (depth - (int)depth != 0)){
            cout << "Please enter an integer between 0 and 100! Depth: ";
            cin >> depth;
        }
        modulate->set_depth(depth);
        select_AM_menu(triwave, modulate);

    case 5:
        double frequency;
        cout << "Please enter the frequency:" << endl;
        cin >> frequency;
        while(frequency <= 0){
            cout << "Please enter a positive number! Frequency: " ;
            cin >> frequency;
        }
        modulate->set_frequency(frequency);
        select_AM_menu(triwave, modulate);
    case 6:
        generate_modulated_signal(triwave,modulate);
    default:
        select_parameter_menu(triwave);
    }



}

void generate_modulated_signal(TriWave *triwave, Modulate *modulate){ //This function will generate one complete period by default.
    double depth = modulate->get_depth() / 100.0;
    double sample_frequency = triwave->get_sample_frequency()*1000;
    double CFrequency = triwave->get_frequency()*1000;
    double AMFrequency = modulate->get_frequency();
    int sample_points = sample_frequency/AMFrequency;
    double Voffset, Vpp;
    bool sign = 0;
    if(triwave->get_Vmode() == 0){

        Voffset = triwave->get_Voffset();
        Vpp = triwave->get_Vpp();
    }
    else{

        Voffset = (triwave->get_Vhigh()+triwave->get_Vlow())/2;
        Vpp = triwave->get_Vhigh() - triwave->get_Vlow();
    }

    double voltage[sample_points];
    voltage[0] = /*Voffset*/0;

    /*cout << CFrequency << endl;
    cout << sample_frequency<< endl;
    cout << Vpp << endl;*/

    for(int i = 1; i< sample_points; i++){ //generate the data for carrier wave (triangular)


        if ((voltage[i-1]>=(/*Voffset+*/(0.5*Vpp)-0.0001)) || (voltage[i-1] <= /*Voffset*/-(0.5*Vpp)+0.0001)){

            if(sign == 0){
                voltage[i-1] = /*Voffset+*/(0.5*Vpp);

                voltage[i] = voltage[i-1] - (2*Vpp*CFrequency/sample_frequency);

                sign = !sign;
            }
            else{
                voltage[i-1] = /*Voffset*/-(0.5*Vpp);

                voltage[i] = voltage[i-1]+ (2*Vpp*CFrequency/sample_frequency);

                sign = !sign;
            }
        }
        else{
            if(sign == 0){
                voltage[i] = voltage[i-1] + (2*Vpp*CFrequency/sample_frequency);
            }
            else{
                voltage[i] = voltage[i-1] - (2*Vpp*CFrequency/sample_frequency);
            }

        }
    }

    /*for(int j = 0; j < sample_points; j++){
        cout << "voltage[" << j << "] = " <<voltage[j] << endl;
    }*/

    double modulated_wave[sample_points];
    if(modulate->get_type() == 1){
        for(int i=0; i<sample_points; i++){ //generate the data for modulated(sine) wave
            modulated_wave[i] = ((1-depth)/2)+(0.5+depth*sin(i/(sample_points/6.2832))/2);
        }
    }

    if(modulate->get_type() == 2){
        for(int i=0; i<sample_points; i++){ //generate the data for modulated(square) wave
            if(i<sample_points/2){
                modulated_wave[i] = (1-((1-depth)/2));
            }
            else{
                modulated_wave[i] = (((1-depth)/2));
            }
        }
    }

    if(modulate->get_type() == 3){
        for(int i=0; i<sample_points; i++){ //generate the data for modulated(triangular) wave
            if(i<sample_points/2){
                modulated_wave[i] = (((1-depth)/2)) + (i*depth)/(sample_points/2);
            }
            else{
                modulated_wave[i] = (1-((1-depth)/2)) - (i-(sample_points/2))*depth/(sample_points/2);
            }
        }
    }

    /*for(int j = 0; j < sample_points; j++){
        cout << "modulated_wave[" << j << "] = " <<modulated_wave[j] << endl;
    }*/

    double final_data[sample_points];
    for(int i=0; i<sample_points; i++){
        final_data[i] = Voffset + voltage[i] * modulated_wave[i];
    }


    /*for(int j = 0; j < sample_points; j++){
        cout << "final_data[" << j << "] = " <<final_data[j] << endl;
    }*/

    ofstream outfile; //output the data to a file.
    outfile.open("ModulatedTriangular.txt");
    for(int j = 0; j < sample_points; j++){
        double aa = final_data[j] * 100;
        bitset<16> b(aa);
        string str = b.to_string();
        outfile << str << endl;
    }
    outfile.close();

    cout << "Success!" << endl;
    after_generate_menu();
}


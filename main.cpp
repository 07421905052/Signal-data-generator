
#include <iostream>
#include <regex>
#include "functions.h"
#include "main.h"
#include "TriWave.h"///////////////////////////////////////////
#include <fstream>///////////////////////////////////////////
#include <bitset>///////////////////////////////
#include <time.h>///////////////////////////

#include "Squmenu.h"

#include "sine_wave.h"
#include "function.h"

#include <string>





using namespace std;

int main(int argc, char const *argv[]) {
  std::fstream file( "count.txt", std::ios::out);
  std::ofstream count;
  count.open("count.txt");
  count << "0" << std::endl;
  // always remember to close a filestream when done
  count.close();


  main_menu();
  return 0;
}

void main_menu() {
  print_main_menu();
  int input = get_user_input(5);
  select_menu_item(input);
}

int get_user_input(int a) { //修改了该函数
  int input;
  std::string input_string;
  bool valid_input = false;
  int menu_items = a;

  do {
    std::cout << "\nSelect item: ";
    std::cin >> input_string;
    valid_input = is_integer(input_string);
    // if input is not an integer, print an error message
    if (valid_input == false) {
      std::cout << "Enter an integer!\n";
    } else {  // if it is an int, check whether in range
      input = std::stoi(input_string);  // convert to int
      if (input >= 1 && input <= menu_items) {
        valid_input = true;
      } else {
        std::cout << "Invalid menu item!\n";
        valid_input = false;
      }
    }
  } while (valid_input == false);

  return input;
}

void select_menu_item(int input) {
  switch (input) {
    case 1:
      menu_item_1();
      break;
    case 2:
      menu_item_2();
      break;
    case 3:
      menu_item_3();
      break;

    case 4:
      menu_item_4();
      break;
    default:
      exit(1);
      break;
  }
}

void print_main_menu() {
  std::cout << "\n----------- Main menu -----------\n";
  std::cout << "|\t\t\t\t|\n";
  std::cout << "|\t1. Sine Wave \t\t|\n";
  std::cout << "|\t2. Square Wave \t\t|\n";
  std::cout << "|\t3. Triangular Wave \t\t|\n";
  std::cout << "|\t4. Mixed Signal\t\t|\n";
  std::cout << "|\t5. Exit\t\t\t|\n";
  std::cout << "|\t\t\t\t|\n";
  std::cout << "---------------------------------\n";
}

void go_back_to_main() {
  std::string input;
  do {
    std::cout << "\nEnter 'b' or 'B' to go back to main menu: ";
    std::cin >> input;
  } while (input != "b" && input != "B");
  main_menu();
}

// https://codereview.stackexchange.com/questions/162569/checking-if-each-char-in-a-string-is-a-decimal-digit
bool is_integer(std::string num) {
  return std::regex_match(num, std::regex("[+-]?[0-9]+"));
}

void menu_item_1() {
  sine_wave sine_wave;
  sine_wave_menu(&sine_wave);
  /*print_sine_wave_menu(&sine_wave);
  int input = get_user_input(7);
  select_sine_wave_menu_item(input);*/
  go_back_to_main();
}
void menu_item_2() {

  std::cout << "\n>> Menu 1\n";
  Squmenu squmenu;
  squmenu.squarewave_menu();
  go_back_to_main();
}


void menu_item_3() {
  TriWave triwave;

  select_parameter_menu(&triwave);

  go_back_to_main();
}


void menu_item_4() {
  std::cout << "\n>> Mixed signal\n";
  select_waves_menu();
  go_back_to_main();
}

void select_waves_menu(){
    cout << "----------Please choose the waveforms and the operation-----------" << endl;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



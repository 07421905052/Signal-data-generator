#include "Squmenu.h"

int count=0;

void Squmenu::squarewave_menu() {
  print_squarewave_menu();
  int input = get_user_input();
  select_menu_item(input);
}

int Squmenu::get_user_input() {
  int input;
  std::string input_string;
  bool valid_input = false;
  int menu_items = 4;

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

void Squmenu::select_menu_item(int input) {
  switch (input) {
    case 1:
      modi_wave();
      break;
    case 2:
      create_wave();
      break;
    case 3:
        exit_wave();
    default:
      exit(1);
      break;
  }
}

void Squmenu::print_squarewave_menu() {
  std::cout << "\n----------- Squarewave menu ----\n";
  std::cout << "|Please select the mode       |\n";
  std::cout << "|\t1. Modify wave        1    |\n";
  std::cout << "|\t2. Create wave        2    |\n";
  std::cout << "|\t3. Exit               3    |\n";
  std::cout << "|                             |\n";
  std::cout << "---------------------------------\n";
}

void Squmenu::go_back_to_squarewave_menu() {
  std::string input;
  do {
    std::cout << "\n\nEnter 'b' or 'B' to go back to main menu: ";
    std::cin >> input;
  } while (input != "b" && input != "B");
  squarewave_menu();
}

// https://codereview.stackexchange.com/questions/162569/checking-if-each-char-in-a-string-is-a-decimal-digit
bool Squmenu::is_integer(std::string num) {
  return std::regex_match(num, std::regex("[+-]?[0-9]+"));
}

void Squmenu::modi_wave() {
  std::cout << "\n>> Modify wave\n";
    std::ifstream count;
  // use it to open a file named 'input.txt'
  count.open("count.txt");
  // check if the file is not open
  if (!count.is_open()) {
    // print error message and quit if a problem occurred
    std::cerr << "Error! No input file found!\n";
    exit(1);
  }
  // create a string to hold the file contents
  std::string count_string;
  count >> count_string;
  // print to terminal
int numcount = std::stoi(count_string);

if (numcount == 0){
  std::cout << "\n  You have not created one wave.";
  go_back_to_squarewave_menu();
}

if (numcount == 1){
  Modi modi1;
  modi1.select1wave();
  go_back_to_squarewave_menu();
}
if (numcount == 2){
  Modi modi2;
  modi2.select2wave();
  go_back_to_squarewave_menu();
}
if (numcount == 3){
  Modi modi3;
  modi3.select3wave();
  go_back_to_squarewave_menu();
}
}

void Squmenu::create_wave() {
  std::ifstream count;
  // use it to open a file named 'input.txt'
  count.open("count.txt");
  // check if the file is not open
  if (!count.is_open()) {
    // print error message and quit if a problem occurred
    std::cerr << "Error! No input file found!\n";
    exit(1);
  }
  // create a string to hold the file contents
  std::string count_string;
  count >> count_string;
  // print to terminal
int numcount = std::stoi(count_string);


  if(numcount == 0){
  std::cout << "\n>> Create wave1\n";
  Create create;
  create.wavedata1create();
  go_back_to_squarewave_menu();
    }
  if(numcount == 1){
  std::cout << "\n>> Create wave2\n";
  Create create2;
  create2.wavedata2create();
  go_back_to_squarewave_menu();
    }
  if(numcount == 2){
  std::cout << "\n>> Create wave3\n";
  Create create3;
  create3.wavedata3create();
  go_back_to_squarewave_menu();
    }
  if(numcount == 3){
    std::cout << "\nYou cannot create more waves.\nMuximum number of wave  is 3.\n" << std::endl;
    go_back_to_squarewave_menu();
  }
}

void Squmenu::exit_wave(){
    main_menu();
}

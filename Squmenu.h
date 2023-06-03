#ifndef SQUMENU_H
#define SQUMENU_H
#include <regex>
#include <string>
#include "Create.h"
#include "Modi.h"
#include "main.h"

class Squmenu{
public:
void squarewave_menu();
int get_user_input();
void select_menu_item(int input);
void print_squarewave_menu();
void go_back_to_squarewave_menu();
bool is_integer(std::string num);
void modi_wave();
void create_wave();
void exit_wave();
};
#endif

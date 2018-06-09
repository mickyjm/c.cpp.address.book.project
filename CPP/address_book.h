/********************
 * <copyright information>
 * AUTHOR: Michael (Micky) Mangrobang
 * COURSE: ICS 212 Program Structure
 * INSTRUCTOR: Ravi Narayan
 * DATE CREATED: 21 November 2015
 * REVISIONS: 08 June 2018
 * FILE: address_book.h
 * DESC: Contains the majority of the project's prototypes
 ********************/
#include <string>
#ifndef PROJECT_02_PROTOTYPES_H
#define PROJECT_02_PROTOTYPES_H

/**********
 * FUNC: run_program
 * DESC: Runs the entire program
 * PARAM: None
 * RETURN: None
 **********/
void run_program();

/**********
 * FUNC: debug_function
 * DESC: Displays debug call
 * PARAM001: function_call (int): The user function that got called
 * PARAM002 (OPTIONAL): name (std::string): The user inputted name
 * PARAM003 (OPTIONAL): address (std::string): The user inputted address
 * PARAM004 (OPTIONAL): phone_number (std::string): The user inputted telephone number
 * PARAM005 (OPTIONAL): year (int): The user inputted year
 * RETURN: None
 **********/
void debug_function(int, std::string = "", std::string = "", std::string = "", int = 0);

/**********
 * FUNC: display_commands
 * DESC: Displays menu
 * PARAM: None
 * RETURN: None
 **********/
void display_commands();

/**********
 * FUNC: get_menu_selection
 * DESC: Gets input for menu selection
 * PARAM: None
 * RETURN: None
 **********/
int get_menu_selection();

/**********
 * FUNC: get_name
 * DESC: Gets input for name
 * PARAM: None
 * RETURN: name (std::string) the name of the person to add to the list
 **********/
std::string get_name();

/**********
 * FUNC: get_address
 * DESC: Gets input for address
 * PARAM: None
 * RETURN: address (std::string) the address for the person
 **********/
std::string get_address();

/**********
 * FUNC: get_birth_year
 * DESC: Gets input for birth year
 * PARAM: None
 * RETURN: birth_year (int) the birth year of the person
 **********/
int get_birth_year();

/**********
 * FUNC: get_phone_number
 * DESC: Gets input for phone_number
 * PARAM: None
 * RETURN: phone_number (std::string) the phone number for the person
 **********/
std::string get_phone_number();

/**********
 * FUNC: get_file_name
 * DESC: Gets input for file name
 * PARAM: None
 * RETURN: file_name (std::string) the name of the file to save the list into
 **********/
std::string get_file_name();
#endif

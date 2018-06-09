/********************
 * <copyright information>
 * AUTHOR: Michael Mangrobang
 * COURSE: ICS 212 Program Structure
 * INSTRUCTOR: Ravi Narayan
 * DATE CREATED: 21 November 2015
 * REVISIONS: 08 June 2018
 * FILE: project_02_display_messages.cpp
 * DESC: Source file that contains majority of the interface
 ********************/
#include "project_02_prototypes.h"
#include <iostream>

void debug_function(int function_call, std::string name, std::string address, int year, std::string phone_number) {
    std::cout << "********************\n";
    if(function_call == 1) {
        std::cout << "llist::addRecord( " << name << ", " << address << ", " << year << ", " << phone_number << " );\n";
    } else if (function_call == 2) {
        std::cout << "llist::printRecord( " << name << " )n";
    } else if(function_call == 3) {
        std::cout << "llist::modifyRecord( " << name << ", " << address << ", " << phone_number << " );\n";
    } else if (function_call == 4) {
        std::cout << "llist::printAll( );\n";
    } else if(function_call == 5) {
        std::cout << "llist::deleteRecord( " << name << " )n";
    } else if(function_call == 6) {
        std::cout << "llist::reverse( );\n";
    } // end if function_call checks
    std::cout << "********************\n";
    return; // debug_function return - end of function
}

void display_commands() {
    std::cout << "Usage: \n";
    std::cout << "\t1: Add a new record into the database.\n";
    std::cout << "\t2: Print information about a record using the name as the key. \n";
    std::cout << "\t3: Modify a record in the database using the name as the key. \n";
    std::cout << "\t4: Print all information in the database.\n";
    std::cout << "\t5: Delete an existing record from the database.\n";
	std::cout << "\t6: Reverse the order of all existing records from the database.\n";
    std::cout << "\t7: Quit the program.\n";
    std::cout << "What would you like to do?\n";
    return; // display_commands return
}

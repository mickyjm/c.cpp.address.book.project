/********************
 * <copyright information>
 * AUTHOR: Michael (Micky) Mangrobang
 * COURSE: ICS 212 Program Structure
 * INSTRUCTOR: Ravi Narayan
 * DATE CREATED: 21 November 2015
 * REVISIONS: 08 June 2018
 * FILE: address_book_main.cpp
 * DESC: Contains the main function that runs the entire project
 ********************/
#include <iostream>
#include <string>
#include "address_book.h"

int main(int argc, char *argv[]) {

    if (argc > 1) {
        std::cout << "Application does not take arguments." << std::endl;
        return -1;
    } // end if argc > 1

    // DEBUG mode only enabled if compiled with -DDEBUG flag
    #ifdef DEBUG
    {
        std::cout << "********************\n";
        std::cout << "**   DEBUG MODE   **\n";
    }
    #endif // end ifdef DEBUG

    std::cout << "********************\n";
    std::cout << "Welcome User!\n";
    std::cout << "This is Micky's Address Book App!\n";
    std::cout << "--------------------\n";
    run_program();
    std::cout << "--------------------\n";
    std::cout << "App terminated\n";
    std::cout << "********************\n";
    return 0;
}

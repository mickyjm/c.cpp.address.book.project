/********************
 * <copyright information>
 * AUTHOR: Michael Mangrobang
 * COURSE: ICS 212
 * INSTRUCTOR: Ravi Narayan
 * DATE CREATED: 21 November 2015
 * REVISIONS: 08 June 2018
 * FILE: project_02_main.cpp
 * DESC: Contains the main function that runs the entire project
 ********************/
#include <iostream>
#include <string>
#include "record.h"
#include "llist.h"
#include "project_02_prototypes.h"

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

    run_program();

    std::cout << "********************\n";
    std::cout << "Welcome User!\n";
    std::cout << "This is Micky's Address Book App!\n";
    std::cout << "-------------------\n";
    std::cout << "--------------------\n";
    std::cout << "Closing Application...\n";
    std::cout << "********************\n";

    return 0;
}

void run_program() {
    llist records(getFileName()); /* Lets user create their own .txt file */
    char *input_name = new char[32];
    char *input_address = new char[64];
    char *input_phone = new char[16];
    char dummy[4];
    int input_year = 0;
    int menu_selection = 0;

    displayCommands(0);

    do { // do while menu_selection != 7
        menu_selection = menuInput();
        switch (menu_selection) {
            case 1: // case 1 - add record
                std::cout << "--------------------\n";
                std::cout << "Add a new Record\n";
                input_name = getName();
                input_address = getAddress();
                input_year = getBirthYear();
                input_phone = getTelno();
                records.addRecord(input_name, input_address, input_year, input_phone);
                break; // end case 1
            case 2: // case 2 - print specific record by name
                std::cout << "--------------------\n";
                std::cout << "Print Record(s) with the same name\n";
                input_name = getName();
                records.printRecord(input_name);
                break; // end case 2
            case 3: // case 3 - modify specific record by name
                std::cout << "--------------------\n";
                std::cout << "Modify Record(s) with the same name\n";
                input_name = getName();
                input_address = getAddress();
                std::cin.getline(dummy, 4);
                input_phone = getTelno();
                records.modifyRecord(input_name, input_address, input_phone);
                break; // end case 3
            case 4: // case 4 - print all records
                std::cout << "--------------------\n";
                std::cout << "Printing Records...\n";
                records.printAll();
                break; // end case 4
            case 5: // case 5 - delete specific record by name
                std::cout << "--------------------\n";
                std::cout << "Delete Record(s) with the same name\n";
                input_name = getName();
                records.deleteRecord(input_name);
                break;
            case 6: // case 6 - recursively reverse order of linked list
                std::cout << "--------------------\n";
                std::cout << "Reversing the order of all the Records...\n";
                records.reverse();
                break; // end case 6
        } // end switch (menu_selection)
        if (menu_selection != 7) {
            displayCommands(0);
        } // end if menu_selection != 7
    } while (menu_selection != 7); // end while
    return; // run_program return - end of function
}

/********************
 * <copyright information>
 * AUTHOR: Michael (Micky) Mangrobang
 * COURSE: ICS 212 Program Structure
 * INSTRUCTOR: Ravi Narayan
 * DATE CREATED: 17 October 2015
 * REVISIONS: 07 June 2018
 * FILE: address_book_main.c
 * DESC: Main file that contains that runs the program
 ********************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "record.h"

/**********
 * FUNC: run_program
 * DESC: Runs the program
 * PARAM: None
 * RETURN: None
 **********/
void run_program();

/**********
* FUNC: display_menu
* DESC: Displays the menu
* PARAM: NONE
**********/
void display_menu();

// declare global variables
int debug_on = 0;

void main(int argc, char *argv[]) {
    // main function variables
    int is_debug = 0; // boolean to check if command line argument was correct

    if (argv[1] != NULL) { // check if first command line argument is not empty
        is_debug = strcmp(argv[1], "debug"); // strcmp returns 0 if there is no difference, 1 if there is a difference
        if (is_debug == 0) { // check if first command line argument is "debug"
            debug_on = 1; // turn on debug mode
            // display debug mode message
            printf("********************\n");
            printf("     DEBUG MODE\n");
        } else { // nested else if debugcmp != 0
            // display invalid argument and usage message
            printf("Invalid argument: %s\n", argv[1]);
            printf("Usage:\n");
            printf("\t./c_address_book - runs program as normal\n");
            printf("\t./c_address_book debug - runs program in debug mode\n");
            exit(0); // exit program with status 0
        } // nested end if else debug == 0
    } // end if argv[1] != NULL
    // display my welcome message
    printf("********************\n");
    printf("Welcome User!\n");
    printf("This is Micky's Address Book App!\n");
    run_program();
    // display my exit message
    printf("Goodbye.\nThank you for using Micky's Address Book App!\n");
    printf("--------------------\n");
    printf("   App terminated\n");
    printf("********************\n");
    exit(0); // exit program with status 0 - end of main function
}

void run_program() {
    // declare run_program variables
    struct record *start = NULL; // pointer to start of the linked list
    int action_selected = 0; // variable to select what action to do
    char illegal_input = '\0';  // variable to catch char input
    char *name = NULL; // char array for name input
    char *address = NULL; // char array for address input`
    int birth_year = 0; // int for birth year input
    char *phone_number = NULL; // char array for telephone number input
    char projectFile[16] = {"save.txt"}; // the save file where information is stored

    read_file(&start, projectFile);
    display_menu();

    do { // do while action_selected != 7
        scanf(" %d", &action_selected);
        switch (action_selected) {
            case 1: // case 1 - add record
                printf("Please input the record's following data.\n");
                name = get_name();
                address = get_address();
                birth_year = get_birth_year();
                phone_number = get_phone_number();
                add_record(&start, name, address, birth_year, phone_number);
                break; // end case 1
            case 2: // case 2 - print a record(s)
                if (start != NULL) {
                    printf("Who's record to print?\n");
                    name = get_name();
                    print_record(start, name);
                } else { // else if start == NULL
                    printf("--------------------\n");
                    printf("The database is empty.\n");
                } // end if start != NULL
                break; // end case 2
            case 3: // case 3 - modify a record(s)
                if (start != NULL) {
                    printf("Who's record to modify?\n");
                    name = get_name();
                    address = get_address();
                    phone_number = get_phone_number();
                    modify_record(start, name, address, phone_number);
                } else { // else if start == NULL
                    printf("--------------------\n");
                    printf("The database is empty.\n");
                } // end if start == NULL
                break; // end case 3
            case 4: // case 4 - print all records
                if (start != NULL) {
                    printf("Printing all records...\n");
                    print_all_records(start);
                } else { // else if start == NULL
                    printf("--------------------\n");
                    printf("The database is empty.\n");
                } // end if start == NULL
                break; // end case 4
            case 5: // case 5 - delete a record(s)
                if (start != NULL) {
                    printf("Who's record to delete?\n");
                    name = get_name();
                    delete_record(&start, name);
                } else { // else if start == NULL
                    printf("--------------------\n");
                    printf("The database is empty.\n");
                } // end if start != NULL
                break; // end case 5
            case 6: // case 6 - delete all records
                if (start != NULL) {
                    printf("Deleting all records... \n");
                    delete_all_records(&start);
                } else { // else if start == NULL
                    printf("--------------------\n");
                    printf("The database is empty.\n");
                } // end if start != NULL
                break; // end case 6
            case 7: // case 7 - exit program
            write_file(start, projectFile);
                /*if(start != NULL) {
                } else { // else if start == NULL
                    printf("Your database empty, so no records have been records to file: %s \n", projectFile);
                } // end if start != NULL*/
                break; // end case 7
            default: // case if input is not an integer
                /* Takes and removes inputs thats not an integer */
                while ((illegal_input = getchar()) != '\n') {
                    putchar(illegal_input);
                }
                printf("Illegal option.\n");
        } // end switch (action_selected)
        if (action_selected != 7) {
            display_menu();
        } // end if action_selected != 7
    } while(action_selected != 7); // end do while (action_selected != 7)
    return; // run_program return - end of function
}

void display_menu(int message) {
    // displays menu
    printf("--------------------\n");
    printf("Select an action:\n");
    printf("\t1: Add a new record into the database.\n");
    printf("\t2: Print information about a record using the name as the key.\n");
    printf("\t3: Modify a record in the database using the name as the key.\n");
    printf("\t4: Print all information in the database.\n");
    printf("\t5: Delete an existing record from the database.\n");
    printf("\t6: Delete all existing records from the database.\n");
    printf("\t7: Quit the program.\n");
    printf("What would you like to do?\n");
    return; // display_menu return - end of function
}

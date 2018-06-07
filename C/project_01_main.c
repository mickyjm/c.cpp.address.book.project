/********************
 * <copyright information>
 * AUTHOR: Michael (Micky) Mangrobang
 * COURSE: ICS 212 Program Structure
 * INSTRUCTOR: Ravi Narayan
 * DATE CREATED: 17 October 2015
 * REVISIONS: 07 June 2018
 * FILE: address_book_main.c
 * DESC: Main function file that contains the main function to run the whole application. Asks the user what to do and calls upon the other functions within the other source files
 ********************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "record.h"
//#include "project_01_display_messages.c"
//#include "project_01_get_input.c"
//#include "project_01_iofunctions.c"
//#include "project_01_database.c"

/**********
 * FUNC: debugError
 * DESC: Displays the illegal command line input and calls calls the displayMenu function to display commands
 * Parameters: illegal[] (char) : Takes in command line if the second string is not "debug"
 **********/
void debugError(char illegal[]);

/**
 * FUNC: endApp
 * DESC: Ends applications and displays the application's termination message
 **/
void endApp();

int debugOn;

void main(int argc, char *argv[]) {
    int debugcmp;
    struct record *start = NULL;
    int input;
    char illegalInput;
    char *name;
    char *address;
    int birthyear;
    char *telno;

    char projectFile[256] = {"project_01_file.txt"};

    if(argv[1] != NULL) {
        debugcmp = strcmp(argv[1], "debug");

        if(debugcmp == 0) {
            debugOn = 1;
            debugMessage();
            readfile(&start, projectFile);
            displayCommands(1);
        } else {
            debugError(argv[1]);
        }
    } else {
        welcomeMessage();
        readfile(&start, projectFile);
        displayCommands(1);
    }

    do {
        scanf(" %d", &input);
        switch(input) {
        case 1:
            printf("Please input the records following data. \n");
            name = getName();
            address = getAddress();
            birthyear = getBirthyear();
            telno = getTelno();
            addRecord(&start, name, address, birthyear, telno);
            displayCommands(0);
            break;
        case 2:
            if(start == NULL) {
                emptyDatabase();
                displayCommands(0);
                break;
            }
            printf("Who's record to print? \n");
            name = getName();
            printRecord(start, name);
            displayCommands(0);
            break;
        case 3:
            if(start == NULL) {
                emptyDatabase();
                displayCommands(0);
                break;
            }
            printf("Who's record to modify? \n");
            name = getName();
            address = getAddress();
            telno = getTelno();
            modifyRecord(start, name, address, telno);
            displayCommands(0);
            break;
        case 4:
            if(start == NULL) {
                emptyDatabase();
                displayCommands(0);
                break;
            }
            printf("Printing all records... \n");
            printAllRecords(start);
            displayCommands(0);
            break;
        case 5:
            if(start == NULL) {
                emptyDatabase();
                displayCommands(0);
                break;
            }
            printf("Who's record to delete? \n");
            name = getName();
            deleteRecord(&start, name);
            displayCommands(0);
            break;
        case 6:
            if(start == NULL) {
                emptyDatabase();
                displayCommands(0);
                break;
            }
            printf("Deleting all records... \n");
            cleanUp(&start);
            displayCommands(0);
            break;
        case 7:
            if(start == NULL) {
                printf("Your database empty, so no records have been records to file: %s \n", projectFile);
                endApp();
                break;
            }
            writefile(start, projectFile);
            endApp();
            break;
        default:
            /*Takes and removes inputs thats not an integer*/
            while ((illegalInput = getchar()) != '\n') {
                putchar(illegalInput);
            }
            printf("\nIllegal option. \n");
            displayCommands(0);
        }

    } while(input != 7);
}

void debugError(char illegal[]) {
    printf("Invalid argument: %s \n", illegal);
    printf("Usage: debug");
    printf("\tor NO arguments (0)");
    exit(0);
}

void endApp() {
    endMessage();
    exit(0);
}

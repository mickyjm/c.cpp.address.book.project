/********************
 * <copyright information>
 * AUTHOR: Michael (Micky) Mangrobang
 * COURSE: ICS 212 Program Structure
 * INSTRUCTOR: Ravi Narayan
 * DATE: 17 October 2015
 * REVISIONS: 07 June 2018
 * FILE: project_01_display_messages.c
 * DESC: Source file that contains majority of the printf() functions to display the menu and interface messages
 ********************/
 #include <stdio.h>

/**********
 * FUNC: debugMessage
 * DESC: Displays the debug mode enabled message and calls the welcomeMessage() function
 **********/
void debugMessage();

/**********
 * FUNC: welcomeMessage
 * DESC: Displays the function and the name of the application and the owner of the application, "Micky", which is my nickname
 **********/
void welcomeMessage();

/**********
 * FUNC: displayCommands
 * DESC: Displays the commands and other messages depending on the number given in the parameter
 * PARAM001: message (int) - Decides what message to display "What would you like to do?" at the start of the application and "What would you like to do next?" after the use of a function
 **********/
void displayCommands(int message);

/**********
 * FUNC: emptyDatabase
 * DESC: Displays that the database is empty when called
 **********/
void emptyDatabase();

/**********
 * FUNC: endMessage
 * DESC: Displays that the application has ended
 **********/
void endMessage();

void debugMessage() {
    printf("******************** \n");
    printf("     DEBUG MODE \n");
    printf("******************** \n\n");
    welcomeMessage();
}

void welcomeMessage() {
    printf("Welcome User! \nThis is Micky's Address Book Application! \n");
}

void displayCommands(int message) {
    printf("Usage: \n");
    printf("\t1: Add a new record into the database. \n");
    printf("\t2: Print information about a record using the name as the key. \n");
    printf("\t3: Modify a record in the database using the name as the key. \n");
    printf("\t4: Print all information in the database. \n");
    printf("\t5: Delete an existing record from the database. \n");
    printf("\t6: Delete all existing records from the database. \n");
    printf("\t7: Quit the program. \n");

    if(message == 1) {
        printf("What would you like to do? \n\n");
    } else if(message == 0) {
        printf("What would you like to do next? \n\n");
    }
}

void emptyDatabase() {
    printf("~~~~~~~~~~~~~~~ \n");
    printf("The database is empty. \n");
    printf("~~~~~~~~~~~~~~~ \n");
}

void endMessage() {
    printf("Goodbye. \nThank you for using Micky's Address Book Application! \n");
    printf("---------------------- \n");
    printf("Application terminated \n");
    printf("---------------------- \n\n");
}

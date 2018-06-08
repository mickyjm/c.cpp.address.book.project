/********************
 * <copyright information>
 * AUTHOR: Michael (Micky) Mangrobang
 * COURSE: ICS 212 Program Structure
 * INSTRUCTOR: Ravi Narayan
 * DATE CREATED: 17 October 2015
 * REVISIONS: 07 June 2018
 * FILE: project_01_display_messages.c
 * DESC: Source file that contains majority of the printf() functions to display the menu and interface messages
 ********************/
 #include <stdio.h>

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

void emptyDatabase() {
    printf("~~~~~~~~~~~~~~~ \n");
    printf("The database is empty. \n");
    printf("~~~~~~~~~~~~~~~ \n");
}

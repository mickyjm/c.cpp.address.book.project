/*****************************************************************
*
* NAME: Michael Mangrobang
*
* HOMEWORK: Project 02
*
* CLASS: ICS 212
*
* INSTRUCTOR: Ravi Narayan
*
* DATE: November 21, 2015
*
* FILE: project_02_prototypes.h
*
* DESCRIPTION: Contains the majority of the project's prototypes
*
*****************************************************************/

#ifndef PROJECT_02_PROTOTYPES_H
#define PROJECT_02_PROTOTYPES_H

/*****************************************************************
*
* Function name: debugMessage
*
* DESCRIPTION: Displays if debug mode is on or not
*
*****************************************************************/

void debugMessage();

/*****************************************************************
*
* Function name: debugFunction
*
* DESCRIPTION: Displays debug call
*
* Parameters: functionCall (int): The user function that got called
*             name (char[]): The user inputted name
*             address (char[]): The user inputted address
*             year (int): The user inputted year
*             telno (char[]): The user inputted telephone number
*
*****************************************************************/

void debugFunction(int, char[], char[], int, char[]);

/*****************************************************************
*
* Function name: welcomeMessage
*
* DESCRIPTION: Displays Welcome Message on start-up
*
*****************************************************************/

void welcomeMessage();

/*****************************************************************
*
* Function name: displayCommands
*
* DESCRIPTION: Displays available commands for the application
*
* Parameters: message (int): Decide what message to show
*
*****************************************************************/

void displayCommands(int);

/*****************************************************************
*
* Function name: endMessage
*
* DESCRIPTION: Displays ending of application message
*
*****************************************************************/

void endMessage();

/*****************************************************************
*
* Function name: menuInput
*
* DESCRIPTION: Gets user input for the menu. Repeatedly asks for a
*              valid integer
*
* Return values: input (int): A number from 1 - 7 for the menu
*
*****************************************************************/

int menuInput();

/*****************************************************************
*
* Function name: getName
*
* DESCRIPTION: Gets user input for the record's address
*
* Return values: name (char[]): User inputted name
*
*****************************************************************/

char *getName();

/*****************************************************************
*
* Function name: getAddress
*
* DESCRIPTION: Gets user input for the record's address
*
* Return values: address (char[]): User inputted address
*
*****************************************************************/

char *getAddress();

/*****************************************************************
*
* Function name: getBirthYear
*
* DESCRIPTION: Gets user input for the record's birth year
*
* Return values: birthYear (int): User inputted birth year
*
*****************************************************************/

int getBirthYear();

/*****************************************************************
*
* Function name: getTelno
*
* DESCRIPTION: Gets user input for the record's telephone number
*
* Return values: telno (char[]): User inputted telephone number
*
*****************************************************************/

char *getTelno();

/*****************************************************************
*
* Function name: getFileName
*
* DESCRIPTION: Gets user input for the user's own custom save file
*
* Return values: file (char[]): User inputted file name
*
*****************************************************************/

char *getFileName();
#endif

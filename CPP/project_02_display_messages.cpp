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
* FILE: project_02_display_messages.cpp
*
* DESCRIPTION: Source file that contains majority of the interface
*
*****************************************************************/

#include "project_02_prototypes.h"
#include <iostream>
using namespace std;

void debugMessage()
{

    cout << "********************" << endl;
    cout << "**   DEBUG MODE   **" << endl;
    cout << "********************" << endl << endl;

    welcomeMessage();

}

void debugFunction(int functionCall, char name[], char address[], int year, char telno[])
{

	cout << "---------------" << endl << "***************" << endl;

	if(functionCall == 1)
	{
		cout << "llist::addRecord( " << name << ", " << address << ", " << year << ", " << telno << " );" << endl;
	}
	else if (functionCall == 2)
	{
		cout << "llist::printRecord( " << name << " );" << endl;
	}
	else if(functionCall == 3)
	{
		cout << "llist::modifyRecord( " << name << ", " << address << ", " << telno << " );" << endl;
	}
	else if (functionCall == 4)
	{
		cout << "llist::printAll( );" << endl;
	}
	else if(functionCall == 5)
	{
		cout << "llist::deleteRecord( " << name << " );" << endl;
	}
	else if(functionCall == 6)
	{
		cout << "llist::reverse( );" << endl;
	}

	cout << "***************" << endl;

}

void welcomeMessage()
{

	cout << "~~~~~~~~~~~~~~~" << endl;
    cout << "Welcome User!" << endl << "This is Micky's Address Book Application!" << endl;
	cout << "~~~~~~~~~~~~~~~" << endl;

}

void displayCommands(int message)
{

    cout << "Usage: \n\t";
    cout << "1: Add a new record into the database. \n\t";
    cout << "2: Print information about a record using the name as the key. \n\t";
    cout << "3: Modify a record in the database using the name as the key. \n\t";
    cout << "4: Print all information in the database. \n\t";
    cout << "5: Delete an existing record from the database. \n\t";
	cout << "6: Reverse the order of all existing records from the database. \n\t";
    cout << "7: Quit the program. \n";

    if(message == 1)
    {
        cout << "What would you like to do?" << endl << endl;
    }
    else if(message == 0)
    {
        cout << "What would you like to do next?" << endl << endl;
    }

}

void endMessage()
{

    cout << "Thank you for using Micky's Address Book Application!" << endl;
    cout << "======================" << endl;
    cout << "Application terminated" << endl;
    cout << "======================" << endl << endl;

}

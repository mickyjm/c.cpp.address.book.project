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
* FILE: project_02_get_input.cpp
*
* DESCRIPTION: Source file that contains all input functions
*
*****************************************************************/

#include "project_02_prototypes.h"
#include <iostream>
#include <string>
using namespace std;

int menuInput()
{

    int input;

    cin >> input;

    while(cin.fail() || input < 1 || input > 7)
    {

        if(cin.fail())
        {
            cout << "Your input was not an integer." << endl;
            cout << "Please enter an integer: ";
        }
        else if(input < 1 || input > 7)
        {
            cout << "Not a valid choice." << endl;

			displayCommands(1);
        }

        cin.clear();
        cin.ignore(256, '\n');
        cin >> input;
    }

	cin.clear();

    return input;
	
}

char *getName()
{

    char *name;

    name = new char[25];

    cin.clear();
    cin.ignore(256, '\n');

    cout << "Please enter the person's NAME: ";

    cin.getline(name, 25);
	cin.clear();

    return name;

}

char *getAddress()
{

    char *address;

    address = new char[80];

    cout << "Please enter the person's ADDRESS (Enter '$' when you're finished): " << endl;

    cin.getline(address, 80, '$');
	cin.clear();

    return address;

}

int getBirthYear()
{

    int birthYear;

    cout << "Please enter the person's BIRTH YEAR: ";

    cin >> birthYear;

    while(cin.fail())
    {
        cout << "Not an integer, please enter an integer: ";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> birthYear;
    }

	cin.clear();
	cin.ignore(256, '\n');

    return birthYear;

}

char *getTelno()
{

    char *telno;

    telno = new char[15];

    cout << "Please enter the contact's TELEPHONE NUMBER: ";

    cin.getline(telno, 15);
    cin.clear();

    return telno;

}

char *getFileName()
{

	char *input;
	char *file;
	int count;

	input = new char[128];
	file = new char[16];
	
	welcomeMessage();

	cout << "Please enter your FILE NAME" << endl << "(ONLY the first 11 characters will be accepted, '.txt' file extension will be added): ";

	cin.getline(input, 128, '\n');

	for(count = 0; count < 11 && input[count] != '\0'; count++)
	{
		file[count] = input[count];
	}
	
	file[count++] = '.';
	file[count++] = 't';
	file[count++] = 'x';
	file[count++] = 't';

	while(count < 16)
	{
		file[count++] = '\0';
	}

	cin.clear();

	return file;

}

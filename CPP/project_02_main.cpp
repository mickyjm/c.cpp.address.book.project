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
 * FILE: project_02_main.cpp
 *
 * DESCRIPTION: Contains the main function that runs the entire project
 *
 *****************************************************************/

#include "record.h"
#include "llist.h"
#include "project_02_prototypes.h"
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{

	if (argc > 1)
	{
		cout << "Application does not take arguements." << endl;

		return -1;
	}

	#ifdef DEBUG
	{
		debugMessage();
	}
	#endif

	//llist records; /* Uses default .txt file */
    
	llist records(getFileName()); /* Lets user create their own .txt file */

	char *input_name;
	char *input_address;
	char *input_phone;
	char dummy[16];

    int input_year;
	int menuSelect;

	input_name = new char[25];
	input_address = new char[80];
	input_phone = new char[15];

	displayCommands(1);

    do
    {

        menuSelect = menuInput();

        switch (menuSelect)
        {
        case 1:
            cout << "~~~~~~~~~~~~~~~" << endl << "Add a new Record" << endl << "---------------" << endl;
            input_name = getName();
            input_address = getAddress();
            input_year = getBirthYear();
            input_phone = getTelno();
            records.addRecord(input_name, input_address, input_year, input_phone);
            break;

        case 2:
			cout << "~~~~~~~~~~~~~~~" << endl << "Print Record(s) with the same name" << endl << "---------------" << endl;
			input_name = getName();
			records.printRecord(input_name);
            break;

        case 3:
			cout << "~~~~~~~~~~~~~~~" << endl << "Modify Record(s) with the same name" << endl << "---------------" << endl;
			input_name = getName();
			input_address = getAddress();
			cin.getline(dummy, 15);
			input_phone = getTelno();
			records.modifyRecord(input_name, input_address, input_phone);
            break;

        case 4:
			cout << "~~~~~~~~~~~~~~~" << endl << "Printing Records..." << endl;
			records.printAll();
            break;

        case 5:
			cout << "~~~~~~~~~~~~~~~" << endl << "Delete Record(s) with the same name" << endl << "---------------" << endl;
			input_name = getName();
			records.deleteRecord(input_name);
            break;

        case 6:
			cout << "~~~~~~~~~~~~~~~" << endl << "Reversing the order of all the Records..." << endl;
			records.reverse();
			break;
        }

		if (menuSelect != 7)
		{
			displayCommands(0);
		}

    } while (menuSelect != 7);

	cout << "~~~~~~~~~~~~~~~" << endl << "Closing Application..." << endl << "---------------" << endl;

    return 0;

}

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
* FILE: list.cpp
*
* DESCRIPTION: Source file that contains all functions of the
*              llist header
*
*****************************************************************/

#include "record.h"
#include "llist.h"
#include "project_02_prototypes.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

llist::llist()
{

	char file[16] = { "project_02.txt" };
	int i;
	int read;

	start = NULL;

	for (i = 0; i < 16; i++)
	{
		filename[i] = file[i];
	}

	welcomeMessage();

	read = readfile();

	if (read < 0)
	{
		cout << "'" << filename << " was not found." << endl << "Therefore, no records have been added to the database and '" << filename << "' will be created." << endl;
		cout << "~~~~~~~~~~~~~~~" << endl;
	}
	else if (read == 0)
	{
		cout << "'" << filename << "' has been found but is empty." << endl << "Therefore, no records have been added to the database." << endl;
		cout << "~~~~~~~~~~~~~~~" << endl;
	}
	else
	{
		cout << "'" << filename << "' has been read. " << read << " Records have been added to the database." << endl;
		cout << "~~~~~~~~~~~~~~~" << endl;
	}

}

llist::llist(char file[])
{

	int i;
    int read;

	start = NULL;

	for (i = 0; i < 16; i++)
	{
		filename[i] = file[i];
	}

    read = readfile();

    if (read < 0)
    {
		cout << "---------------" << endl;
		cout << "'" << filename << "' was not found." << endl << "Therefore, no records have been added to the database and '" << filename << "' will be created." << endl;
		cout << "~~~~~~~~~~~~~~~" << endl;
    }
    else if (read == 0)
    {
		cout << "---------------" << endl;
		cout << "'" << filename << "' has been found but is empty." << endl << "Therefore, no records have been added to the database." << endl;
		cout << "~~~~~~~~~~~~~~~" << endl;
    }
	else
	{
		cout << "---------------" << endl;
		cout << "'" << filename << "' has been read. " << read << " Records have been added to the database." << endl;
		cout << "~~~~~~~~~~~~~~~" << endl;
	}

}

llist::~llist()
{

	writefile();
	cleanup();
	endMessage();

}

int llist::readfile()
{

	ifstream readFile;

	struct record *temp;
	struct record *index;
	struct record *previous;
	
	int fileSize;
	int countRecords;
	
	char dummy[128];

    readFile.open(filename);

    if (!readFile.is_open())
    {
		readFile.close();
        return -1;
    }
	else
	{
		readFile.seekg(0, readFile.end);
		
		fileSize = readFile.tellg();

		if (fileSize == 0)
		{
			readFile.close();
			return 0;
		}

		readFile.seekg(0, readFile.beg);

	}

	countRecords = 0;

	previous = NULL;
	
	do
	{
		char address[80] = { " " };

		temp = new record;
		index = start;

		readFile.getline(temp->name, 25);	
		readFile.getline(temp->address, 80, '$');
		readFile >> temp->yearofbirth;
		readFile.getline(dummy, 128);
		readFile.getline(temp->telno, 15);
		readFile.getline(dummy, 128);

		countRecords++;

		while (index != NULL)
		{
			previous = index;
			index = index->next;
		}

		if (previous == NULL)
		{
			temp->next = start;
			start = temp;
		}
		else
		{
			previous->next = temp;
			temp->next = index;
		}

	} while (!readFile.eof());

	readFile.close();
	
	return countRecords;

}

int llist::writefile()
{

	ofstream writeFile;

	record *index;
	
	int written;

	writeFile.open(filename);
	
	index = start;

	written = 0;

	if (start == NULL)
	{
		cout << "The database is empty. Therefore, no records have been added to file: " << filename << endl;
		writeFile.close();
		return -1;
	}

	do
	{
		writeFile << index->name << endl;
		writeFile << index->address << "$" << endl;
		writeFile << index->yearofbirth << endl;

		if (index->next != NULL)
		{
			/* Prints '\n\n' (2 NEW LINES) when not at the end of the list to keep the same format from reading */
			writeFile << index->telno << endl << endl;
		}
		else
		{
			/* Prints '\n' (SINGLE NEW LINE) when at the end of list to keep the same format from reading */
			writeFile << index->telno << endl;
		}

		index = index->next;
		written++;

	} while (index != NULL);

	cout << written << " records have been recorded to file: " << filename << endl;

	writeFile.close();

	return 0;

}

record* llist::reverse(record *currentNode)
{

	struct record *next;

	if (currentNode->next == NULL)
	{
		start = currentNode;

		return start;
	}
	
	reverse(currentNode->next);

	next = currentNode->next;
	currentNode->next = NULL;

}

void llist::cleanup()
{

	struct record *temp;
	struct record *index;
	
	int deleted;

	if (start == NULL)
	{
		cout << "---------------" << endl;
		cout << "The Database is empty. Therefore, no records have been removed" << endl;
		cout << "~~~~~~~~~~~~~~~" << endl;

		return;
	}

	index = start;
	deleted = 0;

	while (index != NULL)
	{
		temp = index;
		index = index->next;
		start = index;

		free(temp);

		deleted++;
	}

	cout << "---------------" << endl;
	cout << deleted << " records removed from the memory." << endl;
	cout << "~~~~~~~~~~~~~~~" << endl;

}

int llist::addRecord(char inname[], char inaddress[], int inyear, char intelno[])
{
    struct record *temp;
    struct record *index;
    struct record *previous;
    
	int i;

	#ifdef DEBUG
	{
		debugFunction(1, inname, inaddress, inyear, intelno);
	}
	#endif

    temp = new record;

    for (i = 0; i < 25; i++) /* Set Record NAME */
    {
		temp->name[i] = inname[i];
    }

	for (i = 0; i < 80; i++) /* Set Record ADDRESS */
	{
		temp->address[i] = inaddress[i];
	}
    
    temp->yearofbirth = inyear; /* Set Record YEAROFBIRTH */

    for (i = 0; i < 15; i++) /* Set Record TELNO */
    {
        temp->telno[i] = intelno[i];
    }
    
    index = start;
    previous = NULL;

    while (index != NULL)
    {
        previous = index;
        index = index->next;
    }

    if (previous == NULL)
    {
		temp->next = start;
        start = temp;
    }
    else
    {
        previous->next = temp;
        temp->next = index;
    }

    cout << "---------------" << endl << "Record has been added." << endl << "~~~~~~~~~~~~~~~" << endl;

    return 1;

}

int llist::printRecord(char inname[])
{
	struct record *index;
	int printed;

	#ifdef DEBUG
	{
		debugFunction(2, inname, " ", 0, " ");
	}
	#endif

	if (start == NULL)
	{
		cout << "---------------" << endl;
		cout << "The Database is empty. Therefore, no records of " << inname << " exist." << endl;
		cout << "~~~~~~~~~~~~~~~" << endl;

		return -1;
	}
	
	index = start;
	printed = 0;

	while (index != NULL)
	{

		if ((string)inname == (string)index->name)
		{
			printed++;

			cout << "---------------" << endl;
			cout << "Record #" << printed << " of:" << endl;
			cout << "Name: " << index->name << endl;
			cout << "Address: " << endl << index->address << endl;
			cout << "Year of Birth: " << index->yearofbirth << endl;
			cout << "Telephone Number: " << index->telno << endl;
		}

		index = index->next;
	}

	if (printed == 0)
	{
		cout << "---------------" << endl;
		cout << "No records of " << inname << " found." << endl;
		cout << "~~~~~~~~~~~~~~~" << endl;
	}
	else
	{
		cout << "---------------" << endl;
		cout << printed << " records of " << inname << " printed." << endl;
		cout << "~~~~~~~~~~~~~~~" << endl;
	}

	return 1;

}

int llist::modifyRecord(char inname[], char inaddress[], char intelno[])
{
	struct record *index;
	int modified;
	int i;

	#ifdef DEBUG
	{
		debugFunction(3, inname, inaddress, 0, intelno);
	}
	#endif

	if (start == NULL)
	{
		cout << "---------------" << endl;
		cout << "The Database is empty. Therefore, no records of " << inname << " exist." << endl;
		cout << "~~~~~~~~~~~~~~~" << endl;

		return -1;
	}

	index = start;
	modified = 0;

	while (index != NULL)
	{

		if ((string)inname == (string)index->name)
		{

			for (i = 0; i < 80; i++) /* Set Record ADDRESS */
			{
				index->address[i] = inaddress[i];
			}

			for (i = 0; i < 15; i++) /* Set Record TELNO */
			{
				index->telno[i] = intelno[i];
			}

			index = index->next;

			modified++;
		}
		else
		{
			index = index->next;
		}

	}

	if (modified == 0)
	{
		cout << "---------------" << endl;
		cout << "No records of " << inname << " found." << endl;
		cout << "~~~~~~~~~~~~~~~" << endl;
	}
	else
	{
		cout << "---------------" << endl;
		cout << modified << " records of " << inname << " modified." << endl;
		cout << "~~~~~~~~~~~~~~~" << endl;
	}

	return 1;

}

void llist::printAll()
{

	struct record *index;
	int countRecords;

	#ifdef DEBUG
	{

		debugFunction(4, " ", " ", 0, " ");

	}
	#endif

	if (start == NULL)
	{
		cout << "---------------" << endl;
		cout << "The Database is empty. Therefore, no records have been printed." << endl;
		cout << "~~~~~~~~~~~~~~~" << endl;
		
		return;
	}
	else
	{

		index = start;
		countRecords = 0;

		while (index != NULL)
		{
			countRecords++;

			cout << "---------------" << endl;
			cout << "Record #" <<  countRecords << endl;
			cout << "Name: " <<  index->name << endl;
			cout << "Address: " << endl <<  index->address << endl;
			cout << "Year of Birth: " << index->yearofbirth << endl;
			cout << "Telephone Number: " << index->telno << endl;

			index = index->next;
		}

		cout << "---------------" << endl;
		cout << countRecords << " Records printed." << endl;
		cout << "~~~~~~~~~~~~~~~" << endl;
	}

}

int llist::deleteRecord(char inname[])
{

	struct record *temp;
	struct record *index;
	struct record *previous;

	int deleted;

	#ifdef DEBUG
	{

		debugFunction(5, inname, " ", 0, " ");

	}
	#endif

	if (start == NULL)
	{
		cout << "---------------" << endl;
		cout << "The Database is empty. Therefore, no records of " << inname << " exist." << endl;
		cout << "~~~~~~~~~~~~~~~" << endl;

		return -1;
	}

	index = start;
	
	deleted = 0;

	while (index != NULL)
	{

		if ((string)inname == (string)index->name)
		{
			
			if (index == start)
			{
				temp = index;
				index = index->next;
				start = index;

				delete temp;

				deleted++;
			}
			else
			{
				temp = index;
				index = index->next;
				previous->next = index;

				delete temp;

				deleted++;
			}

		}
		else
		{
			previous = index;
			index = index->next;
		}

	}

	if (deleted == 0)
	{
		cout << "---------------" << endl;
		cout << "No records of " << inname << " found." << endl;
		cout << "~~~~~~~~~~~~~~~" << endl;
	}
	else
	{
		cout << "---------------" << endl;
		cout << deleted << " records of " << inname << " deleted." << endl;
		cout << "~~~~~~~~~~~~~~~" << endl;
	}

	return 1;

}

void llist::reverse()
{

	#ifdef DEBUG
	{

	debugFunction(6, " ", " ", 0, " ");

	}
	#endif

	if (start == NULL)
	{
		cout << "---------------" << endl;
		cout << "The Database is empty. Therefore, no records can be reverse." << endl;
		cout << "~~~~~~~~~~~~~~~" << endl;

		return;
	}
	else if (start->next = NULL)
	{
		cout << "---------------" << endl;
		cout << "Only one record exists in the database. Therefore, why you trying to reverse one record?." << endl;
		cout << "~~~~~~~~~~~~~~~" << endl;

		return;
	}

	reverse(start);

	cout << "All Records have been reversed." << endl << "~~~~~~~~~~~~~~~" << endl;

}

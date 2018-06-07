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
* FILE: record.h
*
* DESCRIPTION: Header for record structure
*
*****************************************************************/

#ifndef RECORD_H
#define RECORD_H
struct record
{
	
    char name[25];
    char address[80];
	int yearofbirth;
	char telno[15];
	struct record* next;
	
};
#endif

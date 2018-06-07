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
* FILE: llist.h
*
* DESCRIPTION: Header for llist class
*
*****************************************************************/

#ifndef LLIST_H
#define LLIST_H
class llist
{

  private:
    record *start;
    char filename[16];
	int readfile();
    int writefile();
	record* reverse(record*);
	void cleanup();

  public:
    llist();
    llist(char[]);
	~llist();
	int addRecord(char[], char[], int, char[]);
    int printRecord(char[]);
    int modifyRecord(char[], char[], char[]);
    void printAll();
    int deleteRecord(char[]);
    void reverse();

};
#endif

/********************
 * <copyright information>
 * AUTHOR: Michael (Micky) Mangrobang
 * COURSE: ICS 212 Program Structure
 * INSTRUCTOR: Ravi Narayan
 * DATE: 17 October 2015
 * REVISIONS: 07 June 2018
 * FILE: project_01_iofunctions.c
 * DESC: Source file that holds the readfile and writefile functions.
 ********************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "record.h"

/**********
 * FUNC: readfile
 * DESC: Reads the given file and then stores the information into a struct record.
 * PARAM001: start (struct record **) - The address of the struct record pointer at the start of the database
 * PARAM002: filename (char []) - The name of the file to read from
 * RETURN: 0 - file is empty
 *         1 - file is not empty and records have been added into the database
 *         error - file could not be found and exits application
 **********/
int readfile(struct record **start, char filename[]);

/**********
 * FUNC: writefile
 * DESC: Writes into the given file from the stored information in the struct record
 * PARAM001: start (struct record *) - The struct record pointer at the start of the database
 * PARAM002: filename (char []) - The name of the file to write to
 * RETURN: error - file could not be found and exits application
 **********/
void writefile(struct record *start, char filename[]);

extern int debugOn;

int readfile(struct record **start, char filename[]) {
    struct record *temp;
	struct record *index;
	struct record *previous;
	long fileSize;
	int count;
    int numberChar;
	char c;
    char dummy[128];
    FILE *readFile;

    readFile = fopen(filename, "r");
	previous = NULL;

    if(debugOn) {
        printf("\n*************** \n");
        printf("Function called with paramters: \n");
        printf("readFile(&start, %s); \n", filename);
        printf("*************** \n");
    }

    if (readFile == NULL) {
        perror("Error while opening the file. \n");
		exit(0);
    } else {
        /*Reads until the end of the file*/
        fseek(readFile, 0, SEEK_END);
        /*Returns the read file pointer position in the file*/
        fileSize = ftell(readFile);

        if(fileSize == 0) {
            printf("File is empty. No records were added to the database. \n");
            fclose(readFile);
            return 0;
        }

        /*Resets the read file pointer position to the beginning of the file*/
        rewind(readFile);
    }

    do {
        char address[80] = {" "};
		index = *start;
        temp = (struct record *)malloc(sizeof(struct record));
        numberChar = 0;

        fgets(temp->name, 25, readFile);
        /*Removes the '\n' character in the string*/
        strtok(temp->name, "\n");
        /*Reads file character by character until it reads '$'*/
        fscanf(readFile, "%c", &c);
        while(c != '$') {
            /*Assigns each character to the array position including '\n' and excluding '$'*/
            address[numberChar] = c;
            numberChar++;
            fscanf(readFile, "%c", &c);
        }

        strcpy(temp->address, address);

        fscanf(readFile, " %d", &temp->yearofbirth);
        /*Dummy fgets takes in the '\n' character that fscanf did not read*/
        fgets(dummy, 128, readFile);

        fgets(temp->telno, 15, readFile);
        /*Removes the '\n' character in the string*/
        strtok(temp->telno, "\n");

        /*Dummy fgets takes in the blank linke between each record data*/
        fgets(dummy, 128, readFile);

        count++;

        while(index != NULL) {
            previous = index;
            index = index->next;
        } if(previous == NULL) {
            /*Makes sure START is still pointing to the start of the list*/
            temp->next = *start;
            *start = temp;
        } else {
            /*Makes sure the nodes are connected*/
            previous->next = temp;
            temp->next = index;
        }

    } while(!feof(readFile));

    printf("Your database has been added with %d records. \n\n", count);

    fclose(readFile);

    return 1;
}

void writefile(struct record *start, char filename[]) {
    FILE *writeFile;
    int count;

    if(debugOn) {
        printf("\n*************** \n");
        printf("Function called with paramters: \n");
        printf("writeFile(start, %s); \n", filename);
        printf("*************** \n");
    }

    writeFile = fopen(filename, "w");
    count = 0;

    if (writeFile == NULL) {
        perror("Error while opening the file. \n");
        exit(0);
    }

    do {
        fprintf(writeFile, "%s\n", start->name);
        fprintf(writeFile, "%s$\n", start->address);
        fprintf(writeFile, "%d\n", start->yearofbirth);

        if(start->next != NULL) {
            /*Prints '\n\n' (2 NEW LINES) when not at the end of the list to keep the same format from reading*/
            fprintf(writeFile, "%s\n\n", start->telno);
        } else {
            /*Prints '\n' (SINGLE NEW LINE) when at the end of list to keep the same format from reading*/
            fprintf(writeFile, "%s\n", start->telno);
        }

        start = start->next;
        count++;
    } while(start != NULL);

    printf("%d records have been recorded to file: %s. \n", count, filename);

    fclose(writeFile);
}

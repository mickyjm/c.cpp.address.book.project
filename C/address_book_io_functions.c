/********************
 * <copyright information>
 * AUTHOR: Michael (Micky) Mangrobang
 * COURSE: ICS 212 Program Structure
 * INSTRUCTOR: Ravi Narayan
 * DATE CREATED: 17 October 2015
 * REVISIONS: 07 June 2018
 * FILE: address_book_io_functions.c
 * DESC: Source file that holds the read_file and write_file functions.
 ********************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "record.h"

/**********
 * FUNC: read_file
 * DESC: Reads the given file and then stores the information into a struct record.
 * PARAM001: start (struct record **) - The address of the struct record pointer at the start of the database
 * PARAM002: file_name (char []) - The name of the file to read from
 * RETURN: 0     - file is empty
 *         1     - file is not empty and records have been added into the database
 *         error - file could not be found and exits application
 **********/
int read_file(struct record **start, char file_name[]);

/**********
 * FUNC: write_file
 * DESC: Writes into the given file from the stored information in the struct record
 * PARAM001: start (struct record *) - The struct record pointer at the start of the linked list
 * PARAM002: file_name (char []) - The name of the file to write to
 * RETURN: error - file could not be found and exits application
 **********/
void write_file(struct record *start, char file_name[]);

// global variables
extern int debug_on; // debug_on from main file

int read_file(struct record **start, char file_name[]) {
    // read_file variables
    struct record *temp = NULL; // temporary node to add into linked list
    struct record *index = NULL; // current pointer in linked list
    struct record *previous = NULL; // previous node to
    long file_char_length = 0; // file pointer position
    int record_count = 0; // count of records that was added
    int address_index = 0; // index of address array
    char c = '\0'; // address char
    char dummy[2]; // dummmy char to catch newline
    FILE *file = fopen(file_name, "r"); // file pointer

    if (debug_on) {
        // displays to check if parameters passed in correctly
        printf("********************\n");
        printf("FUNCTION CALL: read_file(&start, %s);\n", file_name);
        printf("********************\n");
    } // end if debug_on
    if (file == NULL) {
        perror("Error while opening the file.\n");
        exit(0);
    } else { // else if file exists check if it is empty
        fseek(file, 0, SEEK_END); // reads until the end of the file
        file_char_length = ftell(file); // returns read file pointer position to get file size
        if (file_char_length == 0) {
            printf("File is empty. No records were added to the database. \n");
            fclose(file);
            return 0; // read_file return
        }
        rewind(file); // resets file pointer to the beginning of the file
    } // end if file == NULL
    // else if file != NULL, read file and add nodes
    do { // do while (!feof(file)) not end of file
        // do while temporary variables
        char address[64] = {" "};

        index = *start;
        temp = (struct record *)malloc(sizeof(struct record));
        address_index = 0;
        fgets(temp->name, 25, file);
        strtok(temp->name, "\n"); // remove '\n' char in the string
        // get chars for address until '$' char
        fscanf(file, "%c", &c);
        while(c != '$') {
            address[address_index] = c;
            ++address_index;
            fscanf(file, "%c", &c);
        } // end while c!= '$'
        strcpy(temp->address, address);
        fscanf(file, " %d", &temp->birth_year);
        fgets(dummy, 2, file); // dummy fgets takes in the '\n' char fscanf did not read
        // get telephone number
        fgets(temp->phone_number, 15, file);
        strtok(temp->phone_number, "\n");
        fgets(dummy, 2, file); // dummy fgets to get newline beween each record in the file
        ++record_count;
        while (index != NULL) {
            previous = index;
            index = index->next;
        } // end while != NULL
        if(previous == NULL) {
            // makes sure START is still pointing to the start of the list
            temp->next = *start;
            *start = temp;
        } else { // else if previous != NULL
            previous->next = temp;
            temp->next = index;
        } // end if previous == NULL
    } while (!feof(file)); // end while
    printf("Your database has been added with %d records.\n", record_count);
    fclose(file);
    return 1; // read_file return - end of function
}

void write_file(struct record *start, char file_name[]) {
    // write_file variables
    FILE *file = fopen(file_name, "w");; // file pointer
    int record_count = 0; // count of how many records were saved to file

    if (debug_on) {
        printf("***************\n");
        printf("FUNCTION CALL: write_file(start, %s); \n", file_name);
        printf("***************\n");
    } // end if debug_on

    if (file == NULL) {
        perror("Error while opening the file. \n");
        exit(0);
    } // end if file == NULL

    if (start == NULL) {
        printf("You have no entries in your database, therefore no records have been added into %s.\n", file_name);
        return; // write_file return
    } // end if start == NULL

    do { // do while start != NULL
        fprintf(file, "%s\n", start->name);
        fprintf(file, "%s$\n", start->address);
        fprintf(file, "%d\n", start->birth_year);
        if (start->next != NULL) {
            /* Prints '\n\n' (2 NEW LINES) when not at the end of the list to keep the same format from reading */
            fprintf(file, "%s\n\n", start->phone_number);
        } else { // else if start->next == NULL
            /* Prints '\n' (SINGLE NEW LINE) when at the end of list to keep the same format from reading */
            fprintf(file, "%s\n", start->phone_number);
        } // end if start->next != NULL
        start = start->next;
        ++record_count;
    } while (start != NULL); // end while
    printf("%d records have been recorded to file: %s.\n", record_count, file_name);
    fclose(file);
    return; // write_file return - end of function
}

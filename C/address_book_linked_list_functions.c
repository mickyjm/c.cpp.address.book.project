/********************
 * <copyright information>
 * AUTHOR: Michael (Micky) Mangrobang
 * COURSE: ICS 212 Program Structure
 * INSTRUCTOR: Ravi Narayan
 * DATE CREATED: 17 October 2015
 * REVISIONS: 07 June 2018
 * FILE: address_book_linked_list_functions.c
 * DESC: Source file that contains functions for the linked list
 ********************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "record.h"

/**********
 * FUNC: add_record
 * DESC: Adds a new record node to the end of the list
 * PARAM001: start (struct record **start) - Address of start pointer, the start of the list
 * PARAM002: input_name (char []) - Name of person to store in the record
 * PARAM003: input_address (char []) - Address of person to store in the record
 * PARAM004: input_birth_year (int) - Birth year of person to store in the record
 * PARAM005: input_phone_number (char []) - Telephone number of the person to store in the record
 * RETURN: 1 - Record has been added to the database
 **********/
int add_record(struct record **start,char input_name[],char input_address[], int input_birth_year, char input_phone_number[]);

/**********
 * FUNC: print_record
 * DESC: Prints all records with the same name that is passed through the parameters
 * PARAM001: start (struct record *) - Start pointer, the start of the list
 * PARAM002: input_name (char []) - The person's name to find and print
 * RETURN: 1 - All records of the name given have been print_count
 **********/
int print_record(struct record *start, char input_name[]);

/**********
 * FUNC: modify_record
 * DESC: Modifies all records with the same name that is passed through the parameters, with the new address and telephone number that has been passed
 * PARAM001: start (struct record *) - Start pointer, the start of the list
 * PARAM002: input_name (char []) - The person's name to find and modify
 * PARAM003: input_address (char []) - New address of person(s) to store in the record
 * PARAM004: input_phone_number (char []) - New telephone number of the person(s) to store in the record
 * RETURN: 1 - All records of the name given have been print_count
 **********/
int modify_record(struct record *start, char input_name[], char input_address[], char input_phone_number[]);

/**********
 * FUNC: print_all_records
 * DESC: Prints all records within the database
 * PARAM001: start (struct record *) - Start pointer, the start of the list
 **********/
void print_all_records(struct record *start);

/**********
 * FUNC: delete_record
 * DESC: Deletes all records of the same name that is passed through the parameters
 * PARAM001: start (struct record **) - Address of start, the start of the list
 * PARAM002: input_name (char []) - The person's name to find and delete
 * RETURN: 1 - All records of the name given have been delete_count
 **********/
int delete_record(struct record **start, char input_name[]);

/**********
 * FUNC: delete_all_records
 * DESC: Deletes all records within the database
 * PARAM001: start (struct record **) - Addres of start, the start of the list
 **********/
void delete_all_records(struct record**start);

/**********
 * FUNC: print_debug
 * DESC: Prints debug messages of all the functions
 * PARAM001: n (int) - Determines which function has been called
 * PARAM002: input_name (char []) - Name of person passed through the parameter
 * PARAM003: input_address (char []) - Address of person passed through the parameter
 * PARAM004: input_birth_year (int) - Birth year of person passed through the parameter
 * PARAM005: input_phone_number (char []): Telephone number of the person passed through the parameter
 **********/
void print_debug(int message, char input_name[], char input_address[], int input_birth_year, char input_phone_number[]);

// global variables
extern int debug_on; // external global varable from main

int add_record(struct record **start, char input_name[], char input_address[], int input_birth_year, char input_phone_number[]) {
    // add_record variables
    struct record *temp = NULL;
    struct record *index = *start;
    struct record *previous = NULL;

    if (debug_on) {
        print_debug(1, input_name, input_address, input_birth_year, input_phone_number);
    } // end if debug_on
    temp = (struct record *) malloc(sizeof(struct record));
    strcpy(temp->name, input_name);
    strcpy(temp->address, input_address);
    temp->birth_year = input_birth_year;
    strcpy(temp->phone_number, input_phone_number);
    while (index != NULL) {
        previous = index;
        index = index->next;
    } // end while index != NULL
    if (previous == NULL) {
        /*Makes sure START is still pointing to the start of the list*/
        temp->next = *start;
        *start = temp;
    } else { // else if previous != NULL
        /*Makes sure the nodes are connected*/
        previous->next = temp;
        temp->next = index;
    } // end if previous == NULL
    printf("Record successfully added. \n");
    return 1; // add_record return
}

int print_record(struct record *start, char input_name[]) {
    // print_record variables
    struct record *index = start;
    int print_count = 0;
    int is_name = 0;

    if (debug_on) {
        print_debug(2, input_name, " ", 0, " ");
    } // end if debug_on
    while (index != NULL) {
        is_name = strcmp(index->name, input_name);
        if (is_name == 0) {
            ++print_count;
            // print record struct information
            printf("~~~~~~~~~~~~~~~~~~~~\n");
            printf("Record #%d of:\n", print_count);
            printf("Name: %s\n", index->name);
            printf("Address: %s\n", index->address);
            printf("Year of Birth: %d\n", index->birth_year);
            printf("Telephone Number: %s\n", index->phone_number);
        } // end if is_name == 0
        index = index->next;
    } // end while index != NULL
    if (print_count == 0) {
        printf("~~~~~~~~~~~~~~~~~~~~\n");
        printf("No records of %s found.\n", input_name);
    } else { // else if print_count != 0
        printf("~~~~~~~~~~~~~~~~~~~~\n");
        printf("%d records of %s print_count.\n", print_count, input_name);
    } // end if print_count == 0
    return 1; // print_record return - end of function
}

int modify_record(struct record *start, char input_name[],char input_address[], char input_phone_number[]) {
    // modify_record variables
    struct record *index = start;
    int modified_count = 0;
    int is_name = 0;

    if (debug_on) {
        print_debug(3, input_name, input_address, 0, input_phone_number);
    } // end if debug_on
    while (index != NULL) {
        is_name = strcmp(index->name, input_name);
        if(is_name == 0) {
            strcpy(index->address, input_address);
            strcpy(index->phone_number, input_phone_number);
            modified_count++;
        } // end if is_name == 0
        index = index->next;
    } // end while index != NULL
    if (modified_count == 0) {
        printf("~~~~~~~~~~~~~~~~~~~~\n");
        printf("No records of %s found.\n", input_name);
    } else { // else if modified_count != 0
        printf("~~~~~~~~~~~~~~~~~~~~\n");
        printf("%d records of %s modified.\n", modified_count, input_name);
    } // end if modified_count == 0
    return 1; // modify_record return - end of function
}

void print_all_records(struct record *start) {
    // print_all_records variables
    struct record *index = start;
    int record_count = 0;

    if (debug_on) {
        print_debug(4, " ", " ", 0, " ");
    } // end if debug_on
    while (index != NULL) {
        ++record_count;
        // print struct record information
        printf("~~~~~~~~~~~~~~~~~~~~\n");
        printf("Record #%d\n", record_count);
        printf("Name: %s\n", index->name);
        printf("Address: %s\n", index->address);
        printf("Year of Birth: %d\n", index->birth_year);
        printf("Telephone Number: %s\n", index->phone_number);
        index = index->next;
    } // end while index != NULL
    printf("~~~~~~~~~~~~~~~~~~~~\n");
    printf("%d record(s) print_count.\n", record_count);
    return; // print_all_records return - end of function
}

int delete_record(struct record **start, char input_name[]) {
    struct record *temp = NULL;
    struct record *index = *start;
    struct record *previous = NULL;
    int delete_count = 0;
    int is_name = 0;

    if (debug_on) {
        print_debug(5, input_name, " ", 0, " ");
    } // end if debug_on
    while (index != NULL) {
        is_name = strcmp(index->name, input_name);
        if (is_name == 0) {
            if (index == *start) {
                temp = index;
                index = index->next;
                *start = index;
                free(temp);
                ++delete_count;
            } else { // else if index != *start
                temp = index;
                index = index->next;
                previous->next = index;
                free(temp);
                ++delete_count;
            } // end if index == *start
        } else { // else if is_name != 0
            previous = index;
            index = index->next;
        } // end if is_name == 0
    } // end while index != NULL
    if (delete_count == 0) {
        printf("~~~~~~~~~~~~~~~~~~~~\n");
        printf("No records of %s found.\n", input_name);
    } else { // else if delete_count != 0
        printf("~~~~~~~~~~~~~~~~~~~~\n");
        printf("%d records of %s delete_count. \n", delete_count, input_name);
    } // end if delete_count == 0
    return 1; // delete_record return - end of function
}

void delete_all_records(struct record **start) {
    struct record *temp = NULL;
    struct record *index = NULL;
    int delete_count = 0;

    if(debug_on) {
        print_debug(6, " ", " ", 0, " ");
    } // end if debug_on
    index = *start;
    while (index != NULL) {
        temp = index;
        index = index->next;
        free(temp);
        delete_count++;
    } // end while index != NULL
    *start = NULL;
    printf("~~~~~~~~~~~~~~~~~~~~\n");
    printf("%d records deleted.\n", delete_count);
    return; // delete_all_records return - end of function
}

void print_debug(int message, char input_name[], char input_address[], int input_birth_year, char input_phone_number[]) {
    // displays debug message
    printf("********************\n");
    printf("FUNCTION CALL:");
    if (message == 1) {
        printf("add_record(&start, %s, %s, %d, %s);\n", input_name, input_address, input_birth_year, input_phone_number);
    } else if (message == 2) {
        printf("print_record(start, %s);\n", input_name);
    } else if (message == 3) {
        printf("modify_record(start, %s, %s, %s);\n", input_name, input_address, input_phone_number);
    } else if (message == 4) {
        printf("print_all_records(start);\n");
    } else if (message == 5) {
        printf("delete_record(&start, %s);\n", input_name);
    } else if (message == 6) {
        printf("delete_all_records(&start);\n");
    } // end if message == 1
    printf("********************\n");
    return; // print_debug return - end of function
}

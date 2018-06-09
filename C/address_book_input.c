/********************
 * <copyright information>
 * AUTHOR: Michael (Micky) Mangrobang
 * COURSE: ICS 212 Program Structure
 * INSTRUCTOR: Ravi Narayan
 * DATE CREATED: 17 October 2015
 * REVISIONS: 07 June 2018
 * FILE: address_book_input.c
 * DESC: Source file that contains the user input code to recieve input and returns the input
 ********************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**********
 * FUNC: *get_name
 * DESC: Recieves string input from the user and stores it in a pointer and returns it
 * RETURN: name (char *) - The name of the person to store in the record
 **********/
char* get_name();

/**********
 * FUNC: *get_address
 * DESC: Recieves multiple lines of string input from the user and stores it in a pointer and returns it
 * RETURN: address (char *) - The person's address to store in the record
 *****************************************************************/
char* get_address();

/**********
 * FUNC: get_birth_year
 * DESC: Recieves integer input from the user and stores it in a int and returns it. Will also deny character input
 * RETURN: birth_year (int) - The person's year of birth to store in the record
 **********/
int get_birth_year();

/**********
 * FUNC: *get_phone_number
 * DESC: Recieves string input from the user and stores it in a pointer and returns it
 * RETURN: phone_number (char *) - The person's telephone number to store in the record
 **********/
char* get_phone_number();

char* get_name() {
    // get_name variables
    char dummy[5];
    char *name = (char *)malloc(25);

    fgets(dummy, 5, stdin); // get '\n' from main menu input
    printf("Please enter the contact's NAME. \n");
    fgets(name, 25, stdin);
    strtok(name, "\n");
    return name; // get_name return - end of function
}

char* get_address() {
    // get_address variables
    char c ='\0';
    int address_char_index = 0;
    char *address = (char *) malloc(64);

    printf("Please enter the contact's ADDRESS. \n");
    printf("*NOTE: You may input multiple lines, please input '$' when you are done. \n");
    /* read input char by char until it reads '$' */
    c = getchar();
    while (address_char_index < 64 && c != '$') {
        address[address_char_index] = c;
        ++address_char_index;
        c = getchar();
    } // end while
    return address; // get_address return - end of function
}

int get_birth_year() {
    // get_birth_year variables
    char ch = 0;
    int birth_year = 0;

    printf("Please enter the contact's BIRTH YEAR. \n");
    /* Checks to see if the input is integers */
    while (scanf("%d", &birth_year) != 1) {
        while ((ch = getchar()) != '\n') {
            /* Disposes input that is not numbers */
            putchar(ch);
        } // end while getchar()
        printf(" is not an integer. Please enter an integer value. \n");
    } // end while scanf()
    return birth_year; // get_birth_year return - end of function
}

char* get_phone_number() {
    // get_phone_number variables
    char dummy[2] = {" "};
    char *phone_number = (char *) malloc(15);

    fgets(dummy, 5, stdin);
    printf("Please enter the contact's TELEPHONE NUMBER. \n");
    fgets(phone_number, 15, stdin);
    strtok(phone_number, "\n");
    return phone_number; // get_phone_number return - end of function
}

/********************
 * <copyright information>
 * COURSE: ICS 212 Program Structure
 * INSTRUCTOR: Ravi Narayan
 * DATE CREATED: 17 October 2015
 * REVISIONS: 07 June 2018 (Micky)
 * FILE: record.h
 * DESC: Struct Record header file, given by Ravi, edited by me
 ********************/
struct record {
    char name[32];
    char address[64];
    int birth_year;
    char phone_number[16];
    struct record* next;
};

/********************
 * <copyright information>
 * AUTHOR: Michael (Micky) Mangrobang
 * COURSE: ICS 212 Program Structure
 * INSTRUCTOR: Ravi Narayan
 * DATE: 21 November 2015
 * REVISIONS: 08 June 2018
 * FILE: record.h
 * DESC: Header file for record, given by Ravi Naryan, edited by me
 ********************/
#ifndef RECORD_H
#define RECORD_H
struct record {
    char name[25];
    char address[80];
    int yearofbirth;
    char telno[15];
    struct record* next;
};
#endif

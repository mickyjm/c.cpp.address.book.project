/********************
 * <copyright information>
 * AUTHOR: Michael (Micky) Mangrobang
 * COURSE: ICS 212 Program Structure
 * INSTRUCTOR: Ravi Narayan
 * DATE CREATED: 21 November 2015
 * REVISIONS: 08 June 2018
 * FILE: llist.cpp
 * DESC: Source file that contains all functions of the llist header
 ********************/
#include <iostream>
#include <fstream>
#include <string>
#include "record.h"
#include "llist.h"
#include "address_book.h"

llist::llist() {
    // llist default constructor variables
    int records_read = 0;
    // initialize class variables
    start = NULL;
    file_name = "save.txt";

    records_read = read_file();
    // print messages for files
    if (records_read < 0) {
        std::cout << "'" << file_name << " was not found.\n";
        std::cout << "Therefore, no records have been added to the list and '" << file_name << "' will be created.\n";
    } else if (records_read == 0) { // else if records_read == 0
        std::cout << "'" << file_name << "' has been found but is empty.\n";
        std::cout << "Therefore, no records have been added to the database.\n";
    } else { // else if records_read > 0
        std::cout << "'" << file_name << "' has been read. " << records_read << " records have been added to the database.\n";
    } // end if records_read < 0
    std::cout << "--------------------\n";
} // end default llist constructor

llist::llist(std::string file) {
    // llist custom constructor variables
    int records_read = 0;
    // initialize class variables
    start = NULL;
    file_name = file;

    records_read = read_file();
    // print messages for files
    if (records_read < 0) {
        std::cout << "'" << file_name << " was not found.\n";
        std::cout << "Therefore, no records have been added to the list and '" << file_name << "' will be created.\n";
    } else if (records_read == 0) { // else if records_read == 0
        std::cout << "'" << file_name << "' has been found but is empty.\n";
        std::cout << "Therefore, no records have been added to the database.\n";
    } else { // else if records_read > 0
        std::cout << "'" << file_name << "' has been read. " << records_read << " records have been added to the database.\n";
    } // end if records_read < 0
    std::cout << "--------------------\n";
} // end llist custom constructor

llist::~llist() {
    write_file();
    delete_all_records();
} // end llist deconstructor

int llist::read_file() {
    // read_file variables
    std::ifstream read_file(file_name.c_str());
    struct record *temp = NULL;
    struct record *index = NULL;
    struct record *previous = NULL;
    int file_char_length = 0;
    int record_count = 0;
    std::string dummy = "";

    if (!read_file.is_open()) {
        read_file.close();
        return -1;
    } // end if !read_file.is_open()
    read_file.seekg(0, read_file.end); // move read pointer to end of file
    file_char_length = read_file.tellg(); // return file pointer position
    if (file_char_length == 0) {
        read_file.close();
        return 0;
    } // end file_char_length == 0
    read_file.seekg(0, read_file.beg); // reset file pointer to beginning
    do { // do while !read_file.eof()
        // do while temporary variables
        std::string address = "";

        temp = new record;
        index = start;
        std::getline(read_file, temp->name);
        std::getline(read_file, temp->address, '$');
        read_file >> temp->birth_year;
        std::getline(read_file, dummy);
        std::getline(read_file, temp->phone_number);
        std::getline(read_file, dummy);
        ++record_count;
        while (index != NULL) {
            previous = index;
            index = index->next;
        } // end while index != NULL
        if (previous == NULL) {
            temp->next = start;
            start = temp;
        } else { // else if previous != NULL
            previous->next = temp;
            temp->next = index;
        } // end if previous == NULL
    } while (!read_file.eof()); // end do while
    read_file.close();
    return record_count; // read_file return - end of function
}

int llist::write_file() {
    // write_file variables
    std::ofstream write_file(file_name.c_str());
    record *index = start;
    int record_count = 0;

    if (start == NULL) {
        std::cout << "The database is empty. Therefore, no records have been added to file: " << file_name << '\n';
        write_file.close();
        return -1;
    } // end if start == NULL
    do { // do while index != NULL
        write_file << index->name << "\n";
        write_file << index->address << "$" << "\n";
        write_file << index->birth_year << "\n";
        if (index->next != NULL) {
            // Prints 2 newlines when not at the end of the list to keep the same format from reading
            write_file << index->phone_number << "\n\n";
        } else { // else if index->start == NULL
            // Prints 1 newline when at the end of list to keep the same format from reading
            write_file << index->phone_number << "\n";
        } // end if index->next != NULL
        index = index->next;
        ++record_count;
    } while (index != NULL); // end do while
    std::cout << record_count << " records have been recorded to file: " << file_name << "\n";
    write_file.close();
    return 0; // write_file return - end of function
}

record* llist::reverse_llist(record *index) {
    // reverse_llist variables
    struct record *next = NULL;

    if (index->next == NULL) {
        start = index;
        return start;
    } // end if index
    reverse_llist(index->next);
    next = index->next;
    index->next = NULL;
}

void llist::delete_all_records() {
    // delete_all_records variables
    struct record *temp = start;
    struct record *index = NULL;
    int records_deleted = 0;

    std::cout << "--------------------\n";
    if (start != NULL) {
        while (index != NULL) {
            temp = index;
            index = index->next;
            start = index;
            delete temp;
            ++records_deleted;
        } // end while index != NULL
        std::cout << records_deleted << " records removed from the memory.\n";
    } else { // else if start == NULL
        std::cout << "The Database is empty. Therefore, no records have been removed.\n";
    }// end if start != NULL
    std::cout << "--------------------\n";
    return; // delete_all_records return - end of function
}

int llist::add_record(std::string input_name, std::string input_address, int input_birth_year, std::string input_phone_number) {
    struct record *temp = NULL;
    struct record *index = start;
    struct record *previous = NULL;

    #ifdef DEBUG
    {
        debug_function(1, input_name, input_address, input_phone_number, input_birth_year);
    }
    #endif

    temp = new record;
    temp->name = input_name;
    temp->address = input_address;
    temp->birth_year = input_birth_year;
    temp->phone_number = input_phone_number;
    while (index != NULL) {
        previous = index;
        index = index->next;
    } // end while index != NULL
    if (previous == NULL) {
        temp->next = start;
        start = temp;
    } else { // else if previous != NULL
        previous->next = temp;
        temp->next = index;
    } // end if previous == NULL
    std::cout << "--------------------\n";
    std::cout << "Record has been added.\n";
    std::cout << "--------------------\n";
    return 1; // add_record return - end of function
}

int llist::print_record(std::string input_name) {
    struct record *index = start;
    int records_printed = 0;

    #ifdef DEBUG
    {
        debug_function(2, input_name);
    }
    #endif

    std::cout << "--------------------\n";
    if (start == NULL) {
        std::cout << "The Database is empty. Therefore, no records of " << input_name << " exist.\n";
        std::cout << "--------------------\n";
        return -1;
    } // end if start == NULL
    while (index != NULL) {
        if (input_name == index->name) {
            ++records_printed;
            std::cout << "====================\n";
            std::cout << "Record #" << records_printed << " of:\n";
            std::cout << "Name: " << index->name << "\n";
            std::cout << "Address: " << index->address << '\n';
            std::cout << "Year of Birth: " << index->birth_year << '\n';
            std::cout << "Telephone Number: " << index->phone_number << '\n';
        } // end if input_name == index->name
        index = index->next;
    } // end while index != NULL

    if (records_printed == 0) {
        std::cout << "No records of " << input_name << " found.\n";
    } else { // else if records_printed > 0
        std::cout << records_printed << " records of " << input_name << " printed." << '\n';
    } // end if records_printed == 0
    std::cout << "--------------------\n";
    return 1; // print_record return - end of function
}

int llist::modify_record(std::string input_name, std::string input_address, std::string input_phone_number) {
    // modify_record variables
    struct record *index = start;
    int records_modified = 0;

    #ifdef DEBUG
    {
        debug_function(3, input_name, input_address, input_phone_number);
    }
    #endif

    std::cout << "--------------------\n";
    if (start == NULL) {
        std::cout << "The Database is empty. Therefore, no records of " << input_name << " exist.\n";
        std::cout << "--------------------\n";
        return -1; // modify_record return
    } // end if start == NULL
    while (index != NULL) {
        if (input_name == index->name) {
            index->address = input_address;
            index->phone_number = input_phone_number;
            ++records_modified;
        } // end if input_name == index->name
        index = index->next;
    } // end while index != NULL
    if (records_modified == 0) {
        std::cout << "No records of " << input_name << " found.\n";
    } else { // else if records_modified != 0
        std::cout << records_modified << " records of " << input_name << " records_modified.\n";
    } // end if records_modified == 0
    std::cout << "--------------------\n";
    return 1; // modify_record return - end of function
}

void llist::print_all_records() {
    // print_all_records variables
    struct record *index = start;
    int record_count = 0;

    #ifdef DEBUG
    {
        debug_function(4);
    }
    #endif

    std::cout << "--------------------\n";
    if (start == NULL) {
        std::cout << "The Database is empty. Therefore, no records have been _printed.\n";
        std::cout << "--------------------\n";
        return; // print_all_records return
    } // end if start == NULL
    while (index != NULL) {
        ++record_count;
        std::cout << "====================\n";
        std::cout << "Record #" <<  record_count << '\n';
        std::cout << "Name: " <<  index->name << '\n';
        std::cout << "Address: " <<  index->address << '\n';
        std::cout << "Year of Birth: " << index->birth_year << '\n';
        std::cout << "Telephone Number: " << index->phone_number << '\n';
        index = index->next;
    }
    std::cout << record_count << " Records printed.\n";
    std::cout << "--------------------\n";
    return; // print_all_records return - end of function
}

int llist::delete_record(std::string input_name) {
    // delete_record variables
    struct record *temp = NULL;
    struct record *index = start;
    struct record *previous = NULL;
    int records_deleted = 0;

    #ifdef DEBUG
    {
        debug_function(5, input_name);
    }
    #endif

    std::cout << "--------------------\n";
    if (start == NULL) {
        std::cout << "The Database is empty. Therefore, no records of " << input_name << " exist.\n";
        std::cout << "--------------------\n";
        return -1; // delete_record return
    } // end if start == NULL
    while (index != NULL) {
        if (input_name == index->name) {
            temp = index;
            if (index == start) { // if index is head
                index = index->next;
                start = index;
            } else { // else if index != start (not head)
                index = index->next;
                previous->next = index;
            } // end if start == NULL (index is head)
            delete temp;
            ++records_deleted;
        } else { // else if input_name != index->name
            previous = index;
            index = index->next;
        } // end if input_name == index->name
    } // end while index != NULL
    if (records_deleted == 0) {
        std::cout << "No records of " << input_name << " found.\n";
    } else { // else if records_deleted != 0
        std::cout << records_deleted << " records of " << input_name << " records_deleted.\n";
    }
    std::cout << "--------------------\n";
    return 1; // delete_record return - end of function
}

void llist::reverse_llist() {

    #ifdef DEBUG
    {
        debug_function(6);
    }
    #endif

    std::cout << "--------------------\n";
    if (start == NULL) {
        std::cout << "The Database is empty. Therefore, no records can be reverse_llist.\n";
    } else if (start->next == NULL) {
        std::cout << "Only one record exists in the database. Why are you trying to reverse one record?.\n";
    } else { // else if start != NULL and start->next != NULL
        reverse_llist(start);
        std::cout << "All Records have been reversed.\n";
    } // end if start == NULL
    std::cout << "--------------------\n";
    return; // reverse_llist return
}

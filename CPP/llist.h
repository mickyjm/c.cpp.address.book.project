/********************
 * <copyright information>
 * COURSE: ICS 212 Program Structure
 * INSTRUCTOR: Ravi Narayan
 * DATE CREATED: 21 November 2015
 * REVISIONS: 08 June 2018 (Micky)
 * FILE: llist.h
 * DESC: Header for llist class, given by Ravi, edited me by
 ********************/
#ifndef LLIST_H
#define LLIST_H
#include <string>
class llist {
    private:
        record *start;
        std::string file_name;
        int read_file();
        int write_file();
        record* reverse_llist(record *);
        void delete_all_records();

    public:
        llist();
        llist(std::string);
        ~llist();
        int add_record(std::string, std::string, int, std::string);
        int print_record(std::string);
        int modify_record(std::string, std::string, std::string);
        void print_all_records();
        int delete_record(std::string);
        void reverse_llist();
};
#endif

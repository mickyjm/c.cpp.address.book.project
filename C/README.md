# C Address Book
ICS 212 Program Structure - Project 01; Address Book (Fall 2015)
Address book project made in C, back in Fall 2015 semester, when I took ICS 212 Program Structure.

## Compile and Run
### Compile with make:
```
$ make
```
### Run normal:
Runs program as normal.
```
$ ./c_address_book
```
### Run debug:
Displays arguments passed into function.
```
$ ./c_address_book debug
```

## Uses
```
1 - Add a new node record
2 - Print data in node with given name
3 - Modify data in node with given name
4 - Print all nodes in liked list
5 - Delete an existing node with given name
6 - Delete all nodes from linked list
7 - Exit Program
```

## Issue
- One issue is that to modify a specific record, it requires you to enter the **name**, the node you want to modify, along with the **new** address and phone number. So even if the node does not exist, you are still required to input the address and phone number. The function name and parameters were given to us, so we had to work with it.
- Another issue is that you **need** the *save.txt* file or else the program will automatically close.

## Copyright Notice
If any ICS 212 students from Ravi's class comes across this. **BE AWARE**, I modified the code to not meet the majority of his requirements.

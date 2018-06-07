/*****************************************************************
 *
 * NAME: Michael Mangrobang
 *
 * HOMEWORK: Project 1
 *
 * CLASS: ICS 212
 *
 * INSTRUCTOR: Ravi Narayan
 *
 * DATE: October 17, 2015
 *
 * FILE: project_01_display_messages.c
 *
 * DESCRIPTION: Source file that contains majority of the printf()
 *              functions to display the menu and interface messages
 *
 *****************************************************************/

/*****************************************************************
 *
 * Function name: debugMessage
 *
 * DESCRIPTION: Displays the debug mode enabled message and calls
 *              the welcomeMessage() function
 *
 *****************************************************************/

void debugMessage();

/*****************************************************************
 *
 * Function name: welcomeMessage
 *
 * DESCRIPTION: Displays the function and the name of the
 *              application and the owner of the application,
 *              "Micky", which is my nickname
 *
 *****************************************************************/

void welcomeMessage();

/*****************************************************************
 *
 * Function name: displayCommands
 *
 * DESCRIPTION: Displays the commands and other messages
 *              depending on the number given in the parameter
 *
 * Parameters: message (int) : Decides what message to display
 *                             "What would you like to do?" at the
 *                             start of the application and
 *                             "What would you like to do next?"
 *                             after the use of a function
 *
 *****************************************************************/

void displayCommands(int message);

/*****************************************************************
 *
 * Function name: emptyDatabase
 *
 * DESCRIPTION: Displays that the database is empty when called
 *
 *****************************************************************/

void emptyDatabase();

/*****************************************************************
 *
 * Function name: endMessage
 *
 * DESCRIPTION: Displays that the application has ended
 *
 *****************************************************************/

void endMessage();

void debugMessage() {
    printf("******************** \n");
    printf("     DEBUG MODE \n");
    printf("******************** \n\n");
    welcomeMessage();
}

void welcomeMessage() {
    printf("Welcome User! \nThis is Micky's Address Book Application! \n");
}

void displayCommands(int message) {
    printf("Usage: \n\t");
    printf("1: Add a new record into the database. \n\t");
    printf("2: Print information about a record using the name as the key. \n\t");
    printf("3: Modify a record in the database using the name as the key. \n\t");
    printf("4: Print all information in the database. \n\t");
    printf("5: Delete an existing record from the database. \n\t");
    printf("6: Delete all existing records from the database. \n\t");
    printf("7: Quit the program. \n");

    if(message == 1) {
        printf("What would you like to do? \n\n");
    } else if(message == 0) {
        printf("What would you like to do next? \n\n");
    }
}

void emptyDatabase() {
    printf("~~~~~~~~~~~~~~~ \n");
    printf("The database is empty. \n");
    printf("~~~~~~~~~~~~~~~ \n");
}

void endMessage() {
    printf("Goodbye. \nThank you for using Micky's Address Book Application! \n");
    printf("---------------------- \n");
    printf("Application terminated \n");
    printf("---------------------- \n\n");
}

// CONVERTING MODULE SOURCE
#define _CRT_SECURE_NO_WARNINGS // SUPPERESSSING THE SECURITY WARNINGS
#define BUFFER_SIZE 80 // DEFINING THE MACRO CONSTANT WITH VALUE 80
#define NUM_INPUT_SIZE 10 

#include <stdio.h>// INCLUDING THE STANDARD LIBRARY 
// VI
#include <string.h>// INCLUDING string.h HEADER FILE 

// Converting Module
void converting(void) { //DEFINING THE FUNCTION FOR CONVERTING
    printf("*** Start of Converting Strings to int Demo ***\n");  //DEFINING THE FUNCTION FOR CONVERTING

    char intString[BUFFER_SIZE]; //DECLARING THE CHARACTER TYPE ARRRAY WITH THE SIZE OF BUFFER_SIZE MACRO
    int intNumber; // DECLARE THE INTEGER VARIABLE intNumber

    do { // STARTING A DO-WHILE LOOP
        printf("Type an int numeric string (q - to quit):\n"); //PRINTING A STATEMENT TO TYPE THE STRING
        fgets(intString, BUFFER_SIZE, stdin); // READ THE LINE OF TEXT IN 'intString' from the input stdin
        intString[strlen(intString) - 1] = '\0'; //REMOVING THE NEW LINE CHARACTER AT THE END OF THE STRING

        if (strcmp(intString, "q") != 0) { //CHECKING IF THE VALUE OF intString IS NOT EQUAL TO "q"
            intNumber = atoi(intString); //CONVERTING THE intString INTO A NUMBER AND STORING IT IN intNumber
            printf("Converted number is %d\n", intNumber); // PRINTING THE CONVERTED INTEGER
        }

    } while (strcmp(intString, "q") != 0); // WHILE CONDITION TO LOOP UNTIL intString is equal to "q"

    printf("*** End of Converting Strings to int Demo ***\n\n");  // PRINTING THE END STATEMENT
}

// Fundamentals Module
void fundamentals(void) { // Instructions of a function "fundamentals"
    // V1
    printf("*** Start of Indexing Strings Demo ***\n"); // Prints the message on a screen

    char buffer1[BUFFER_SIZE]; // Declares an array "buffer1" with the size of "BUFFER_SIZE"
    char numInput[NUM_INPUT_SIZE];  // Declares an array "numInput" with the size of "NUM_INPUT_SIZE"
    size_t position; // Declares a variable "position"

    do { // Iteration do while
        printf("Type not empty string (q - to quit):\n");  // Prints the message on a screen
        fgets(buffer1, BUFFER_SIZE, stdin); // Reads the string input from a stream "stdin" and stores it as a character string "buffer1"
        buffer1[strlen(buffer1) - 1] = '\0'; // Defines a last character in string "buffer1" as NULL terminator

        if (strcmp(buffer1, "q") != 0) { // Executes if a string "buffer1" and a character "q" is not equal
            printf("Type the character position within the string:\n"); // Prints the message on a screen
            fgets(numInput, NUM_INPUT_SIZE, stdin); // Reads the string input from a stream "stdin" and stores it as a character string "numInput"
            numInput[strlen(numInput) - 1] = '\0'; // Defines a last character in string "numInput" as NULL terminator
            position = atoi(numInput);  // Defines an integer "position" by converting value in a character string "numInput" as an integer

            if (position >= strlen(buffer1)) { // Excecutes if an integer "position is greater than the length of character string "buffer1"
                position = strlen(buffer1) - 1; // Defines an integer "position" by the length of character string "buffer1" minus one
                printf("Too big... Position reduced to max. available\n"); // Prints the message on a screen
            } // End of if statement
            } // End of if statement

            printf("The character found at %d position is \'%c\'\n", (int)position, buffer1[position]);// Prints the message on a screen
        }

    while (strcmp(buffer1, "q") != 0); // Loops the iteration while a string "buffer1" and a character "q" is not equal

    printf("*** End of Indexing Strings Demo ***\n\n");
}

// Manipulating Module
void manipulating(void) {
        //V1
        //Concatenate two strings
    printf("*** Start of Concatenating Strings Demo ***\n");

    char string1[BUFFER_SIZE]; //Stores the first user input of strings
    char string2[BUFFER_SIZE]; //Stores the second user input of strings
    //Iteration will only end if user entered 'q'
    do {
        printf("Type the 1st string (q - to quit):\n"); 
        
        //Retrieves user input including the char '\n'
		//Number of characters should be less than the BUFFER_SIZE
        fgets(string1, BUFFER_SIZE, stdin);

        //Changes the char '\n' to '\0'
        string1[strlen(string1) - 1] = '\0'; 

        if (strcmp(string1, "q") != 0) {
            printf("Type the 2nd string:\n");

            //Retrieves user input including the char '\n'
            //Number of characters should be less than the BUFFER_SIZE
            fgets(string2, BUFFER_SIZE, stdin);

            //Changes the char '\n' to '\0'
            string2[strlen(string2) - 1] = '\0';

            //Concatenate two user inputs and will be stored to string1
            strcat(string1, string2);

            //Display the concatenated string
            printf("Concatenated string is \'%s\'\n", string1);
        }
    } while (strcmp(string1, "q") != 0);

    printf("*** End of Concatenating Strings Demo ***\n\n");
}

// Tokenizing Module

    //V1
    //Concatenate two strings
void tokenizing(void) {
    printf("*** Start of Tokenizing Words Demo ***\n");

    //Stores the first user input of strings
    char words[BUFFER_SIZE];

    //Stores the second user input of strings
    char* nextWord = NULL;
    int wordsCounter = 1;

    //Iteration will only end if user entered 'q'
    do {
        nextWord = NULL;

        // Print the start message for the Tokenizing Words Demo
        printf("Type a few words separated by space (q to quit):\n");
        fgets(words, BUFFER_SIZE, stdin);

        // Declare an array to store words with the specified buffer size
        words[strlen(words) - 1] = '\0';

        // Check if the input is not 'q' to continue tokenizing
        if (strcmp(words, "q") != 0) {

            // Initialize the strtok function with the input string
            nextWord = strtok(words, " ");
        }

        // Reset the words counter for each input
        wordsCounter = 1;

        // Start a while loop to tokenize and print each word
        while (nextWord) {
            // Print the word number and the current word
            printf("Word #%d is '%s'\n", wordsCounter++, nextWord);

            // Continue tokenizing the input string
            nextWord = strtok(NULL, " ");
        }
        // Continue the loop until the user enters 'q'
    } while (strcmp(words, "q") != 0);

    // Print the end message for the Tokenizing Words Demo
    printf("*** End of Tokenizing Words Demo ***\n\n");
}



int main(void) {
    int choice;

    do {
        printf("Select a module to run:\n");
        printf("1. Converting Module\n");
        printf("2. Fundamentals Module\n");
        printf("3. Manipulating Module\n");
        printf("4. Tokenizing Module\n");
        printf("0. Exit\n");

        scanf("%d", &choice);
        getchar(); // Consume the newline character

        // Switch based on user's choice
        switch (choice) {
        case 1:
            converting(); // Call converting module function
            break;
        case 2:
            fundamentals(); // Call fundamentals module function
            break;
        case 3:
            manipulating(); // Call manipulating module function
            break;
        case 4:
            tokenizing(); // Call tokenizing module function
            break;
        case 0:
            printf("Exiting program.\n"); // Call to exit the code
            break;
        default:
            printf("Invalid choice. Please enter a number between 0 and 4.\n"); // default case if the input doesn't match any of the above cases
        }

    } while (choice != 0);// Continue loop until user chooses to exit

    return 0;


}
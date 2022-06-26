/*
Author:     Billy Gene Ridgeway
Purpose:    Learn about pointer multiple indirection with strings.
Date:       June 26th. 2022
*/

#include <stdio.h>

#define LENGTH 3    // Define the constant LENGTH using a preprocessor directive.

char *words[LENGTH];		// Declare the array words to hold a sequence of strings. Declares a string as a pointer the address of the start of the array.

int main(int argc, char **argv) {
	char *pc;			// A pointer to a character.
	char **ppc;			// A pointer to a pointer to a character.

	printf("multiple indirection example\n\n");

	// Initialize our string array. C will automatically append the null character to the end of the string.
	words[0] = "zero";
	words[1] = "one";
	words[2] = "two";
	for (int i = 0; i < LENGTH; i++) {
		printf("%s\n", words[i]);
	}


	/*
	* B: a pointer to an array of strings
	*    - the same as a pointer to a pointer to a character
	*
	*/

	printf("\n");
	ppc = words;							// Initialize the pointer to a pointer to the address of the start of the array.
	for (int i = 0; i < LENGTH; i++) {		// Loop over each string.
		ppc = words + i;                    // Updates the address pointed to by the pointer by one. words[0]...words[2].
		pc = *ppc;                          // "pc" is moved to point to the first word stored in the string pointed to by "ppc".
		while (*pc != 0) {					// Process each character in a string pointed to by "pc" and dereferenced by '*'.
			printf("%c ", *pc);				// Print out each character of the string individually.
			pc += 1;
		}
		printf("\n");
	}

	return 0;
}

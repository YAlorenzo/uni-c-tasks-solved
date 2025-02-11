#include <stdio.h>

/*
 * Function reverse_string() takes a string as input and reverses it in-place.
 * It swaps the characters at the beginning and end of the string, moving
 * toward the center until the entire string is reversed.
 *
 * Parameters:
 * - str: A pointer to the string to be reversed.
 *
 * The function returns a pointer to the reversed string.
 *
 * Example:
 * Input: "hello"
 * Output: "olleh"
 */

char *reverse_string(char *str) {
    int length = 0;
    int j = 0;

    // Calculate the length of the string
    while (str[length] != '\0') {
        length++;
    }

    // Reverse the string by swapping characters from both ends
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i]; // temporarily store the character at the start
        str[i] = str[length - i - 1]; // place character from the end at the start
        str[length - i - 1] = temp; // place the temporary character at the end
    }

    return str; // Return the pointer to the reversed string
}



#include <stdio.h>
#include <string.h>

/*
 * Function find_shortest_line_length_in_file() reads a file ("list.txt"),
 * determines the length of each line, and finds the shortest line in the file.
 * It performs the following tasks:
 * 1. Opens the input file ("list.txt") for reading.
 * 2. Reads each line from the file.
 * 3. Determines the length of the current line.
 * 4. Compares the length of the current line to find the shortest one.
 * 5. Prints the length of the shortest line in the file.
 *
 * Input:
 * - The input file "list.txt" containing multiple lines of text.
 *
 * Output:
 * - The length of the shortest line in the file.
 */
int find_shortest_line_length_in_file() {
    FILE *fr = fopen("list.txt", "r");
    char str[100];
    int prev_min = 0;
    int min = 100;
    int i = 0;

    // Check if file opened successfully
    if (fr == NULL) {
        printf("Error: opening file.\n");
        return -1;
    }

    // Process each line in the file
    while (fgets(str, sizeof(str), fr)) {
        // Calculate the length of the current line
        while (str[i] != '\0') {
            prev_min++;
            i++;
        }

        // Update the minimum length if the current line is shorter
        if (min > prev_min) {
            min = prev_min;
        }

        // Reset for the next line
        prev_min = 0;
        i = 0;
    }

    // Close the file and check for errors
    int is_close = fclose(fr);
    if (is_close) {
        printf("Error: closing file.\n");
        return -1;
    }

    // Output the length of the shortest line
    printf("Shortest line length: %d\n", min);

    return 0;
}


int main() {
    find_shortest_line_length_in_file();
    return 0;
}

#include <stdio.h>
#include <string.h>

/* Function to process a file and modify its lines
* For odd lines, it replaces the first half of the line with '*' characters,
* and for even lines, it replaces the second half of the line with '-' characters.
* The modified content is written to an output file.
*
* Example:
* Input file (vstup.txt):
* 1234567890
* abcdefghijklm
* jozko
* anca
*
* Output file (vystup.txt):
* *****67890
* abcdefg------
* **zko
* an--
*/
int process_file_lines() {
    char str[1000];  // Buffer to hold a line from the input file
    int count_str = 1;  // Line counter
    FILE *fr = fopen("vstup.txt", "r");  // Open the input file for reading
    FILE *fw = fopen("vystup.txt", "w");  // Open the output file for writing

    // Check if the files are opened successfully
    if (fr == NULL || fw == NULL) {
        printf("Error file open!\n");
        return 1;
    }

    // Process each line of the input file
    while (fgets(str, 1000, fr) != NULL) {
        int length = strlen(str);

        // Remove newline character if it's at the end of the line
        if (str[length - 1] == '\n') {
            length--;
        }

        // Modify the line based on whether it's an odd or even line
        if (count_str % 2) {
            // For odd lines, replace the first half with '*'
            int i = 0;
            while (i < (length / 2)) {
                str[i] = '*';
                i++;
            }
        } else {
            // For even lines, replace the second half with '-'
            int i = length / 2;
            while (i < length) {
                str[i] = '-';
                i++;
            }
        }

        // Write the modified line to the output file
        fputs(str, fw);
        count_str++;
    }

    // Close the files
    fclose(fr);
    fclose(fw);

    return 0;
}

int main() {
    // Call the function to process the file
    return process_file_lines();
}

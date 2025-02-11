#include <stdio.h>

/*
 * Function compare_files() compares the contents of two files ("prvy.txt" and "druhy.txt").
 * It reads both files and performs the following tasks:
 * 1. It compares the characters of both files one by one.
 * 2. It counts and outputs the number of different characters.
 * 3. If the files have different lengths, it also prints the difference in size.
 * 4. If the files are identical, it outputs a message saying "The files are identical."
 *
 * Example:
 * Input: prvy.txt contains "Hello World!" and druhy.txt contains "Hello World?"
 * Output: "Number of different characters: 1"
 *         "One of the files is longer by 1 character"
 */

int big_or_diff(int a, int b, int is_dif) {
    if (is_dif) {
        return a > b ? a - b : b - a;  // Return the absolute difference
    } else {
        return a < b ? a : b;  // Return the smaller number
    }
}

int compare_files() {
    int diff_count = 0;
    int p_length = 0;
    int d_length = 0;
    char p_ch;
    char d_ch;
    char prvy[100];
    char druhy[100];
    FILE *fprvy = fopen("prvy.txt", "r");
    FILE *fdruhy = fopen("druhy.txt", "r");

    // Check if files are opened successfully
    if (fprvy == NULL || fdruhy == NULL) {
        printf("Error opening files!\n");
        return 1;
    }

    // Read first file and count non-space characters
    while ((p_ch = fgetc(fprvy)) != EOF) {
        prvy[p_length] = p_ch;
        if (p_ch != ' ') {
            p_length++;
        }
    }

    // Read second file and count non-space characters
    while ((d_ch = fgetc(fdruhy)) != EOF) {
        druhy[d_length] = d_ch;
        if (d_ch != ' ') {
            d_length++;
        }
    }

    // Compare files character by character and count differences
    for (int i = 0; i < big_or_diff(p_length, d_length, 0); i++) {
        if (prvy[i] != druhy[i]) {
            diff_count++;
        }
    }

    // Output results
    if (diff_count == 0) {
        printf("The files are identical\n");
    } else {
        printf("Number of different characters: %d\n", diff_count);
        if (p_length != d_length) {
            printf("One of the files is longer by %d characters\n", big_or_diff(p_length, d_length, 1));
        } else {
            printf("The files have the same size: %d characters\n", p_length);
        }
    }

    // Close files
    fclose(fprvy);
    fclose(fdruhy);

    return 0;
}

int main() {
    compare_files();
    return 0;
}

#include <stdio.h>

/*
 * Function write_number_triangle_to_file() prompts the user to enter a number of rows (1 to 15).
 * It performs the following tasks:
 * 1. Reads an integer from the user.
 * 2. If the number is outside the range [1, 15], it prints an error message and exits.
 * 3. Writes a triangular pattern to a file named "CISLA.TXT".
 *    - Each row starts with its index followed by a decreasing sequence of numbers.
 *
 * Output:
 * 1. A triangular pattern saved in the file "CISLA.TXT".
 *
 * Example:
 * Input: 4
 * Output in file:
 * 1: 4 3 2 1
 * 2: 3 2 1
 * 3: 2 1
 * 4: 1
*/

void write_number_triangle_to_file() {
    int row, col;
    printf("Enter the number of rows (1 to 15): ");
    scanf("%d", &row);

    if (row < 1 || row > 15) {
        printf("Error: Number out of range.\n");
        return;
    }

    FILE *file = fopen("CISLA.TXT", "w");
    if (file == NULL) {
        printf("Error: Could not open file for writing.\n");
        return;
    }

    col = row;
    for (int i = 1; i <= row; i++) {
        fprintf(file, "%d: ", i);
        for (int j = col; j > 0; j--) {
            fprintf(file, "%d ", j);
        }
        fprintf(file, "\n");
        col--;
    }

    fclose(file);
    printf("Number triangle successfully written to CISLA.TXT\n");
}


int main() {
    write_number_triangle_to_file();
    return 0;
}

#include <stdio.h>

/*
 * Function write_floyds_triangle() prompts the user to enter the number of rows (1 to 10).
 * It performs the following tasks:
 * 1. Reads an integer num_rows from the user.
 * 2. Generates Floyd's Triangle up to the specified number of rows.
 * 3. Writes the generated triangle into a file named "floyd.txt".
 *
 * Output:
 * 1. If the input is valid (between 1 and 10), the Floyd's Triangle is written to "floyd.txt".
 * 2. If the file cannot be opened, an error message is displayed.
 * 3. If the input is out of range, an error message is displayed.
 *
 * Example:
 * Input: 4
 * File Output (floyd.txt):
 * 1
 * 2 3
 * 4 5 6
 * 7 8 9 10
*/

int write_floyds_triangle() {
    int num_rows;  // Number of rows in Floyd's triangle
    int current_number = 1; // The next number to be written in the triangle
    int row_length = 1; // Length of the current row

    printf("Enter the number of rows for Floyd's Triangle (1 to 10): ");
    scanf("%d", &num_rows);

    if (num_rows >= 1 && num_rows <= 10) {
        FILE *file = fopen("floyd.txt", "w");
        if (file == NULL) {
            printf("Error: Could not open file for writing.\n");
            return 0;
        }
        // Generating Floyd's Triangle
        for (int i = 0; i < num_rows; i++) {
            for (int j = 0; j < row_length; j++) {
                fprintf(file, "%d ", current_number++);
            }
            row_length++;
            fprintf(file, "\n");
        }
        fclose(file);
        printf("Floyd's triangle has been successfully written to the file floyd.txt\n");
    } else {
        printf("Invalid input. Please enter a number between 1 and 10.\n");
    }

}

int main(){
   write_floyds_triangle();
   return 0;
}

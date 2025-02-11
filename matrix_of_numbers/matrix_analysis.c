#include <stdio.h>
#include <limits.h>

/*
 * Function load_matrix_from_file() reads a 10x10 matrix from a file.
 * It performs the following tasks:
 * 1. Opens the file specified by the user.
 * 2. Reads integers from the file and stores them in the matrix.
 * 3. Returns 0 if reading fails (e.g., file is not found or data is invalid),
 *    and 1 if the matrix is successfully loaded.
 *
 * Output:
 * 1. The matrix is successfully loaded from the file.
 *
 * Example:
 * Input: File containing integers in a 10x10 format
 * Output: A matrix of integers is loaded into the array.
 */
int load_matrix_from_file(char *filename, int matrix[10][10]) {
    FILE *fr = fopen(filename, "r");
    if (fr == NULL) {
        return 0; // Error: unable to open file
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (fscanf(fr, "%d", &matrix[i][j]) != 1) {
                fclose(fr);
                return 0; // Error: invalid data or end of file reached
            }
        }
    }

    fclose(fr); // Close the file after reading
    return 1; // Success: matrix is loaded
}

/*
 * Function analyze_matrix() analyzes the matrix and returns the maximum value.
 * It also counts the number of negative and odd elements in the matrix.
 *
 * It performs the following tasks:
 * 1. Iterates through all elements in the matrix.
 * 2. Counts the negative elements and the odd elements.
 * 3. Finds the maximum value in the matrix.
 *
 * Output:
 * 1. The function returns the maximum value found in the matrix.
 * 2. The negative and odd element counts are updated via pointers.
 *
 * Example:
 * Input: A matrix of integers.
 * Output: Returns the maximum value, negative count, and odd count.
 */
int analyze_matrix(int matrix[10][10], int *negative_count, int *odd_count) {
    int max = INT_MIN; // Initialize max value to the smallest possible integer
    *negative_count = 0; // Initialize negative count
    *odd_count = 0; // Initialize odd count

    // Iterate through all elements of the matrix
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (matrix[i][j] < 0) {
                (*negative_count)++; // Count negative numbers
            }
            if (matrix[i][j] % 2 != 0) {
                (*odd_count)++; // Count odd numbers
            }
            if (matrix[i][j] > max) {
                max = matrix[i][j]; // Update maximum value
            }
        }
    }
    return max; // Return the maximum value
}

/*
 * Function print_matrix() prints the matrix to the console.
 * It performs the following tasks:
 * 1. Iterates through all elements of the matrix.
 * 2. Prints each element in a formatted manner.
 *
 * Output:
 * 1. The matrix is printed to the console.
 *
 * Example:
 * Input: A matrix of integers.
 * Output: Prints the matrix with formatted output.
 */
void print_matrix(int matrix[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%5d", matrix[i][j]); // Print each element in the matrix
        }
        printf("\n"); // Newline after each row
    }
}

int main() {
    int matrix[10][10], negative_count, odd_count, max;

    // Load the matrix from a file
    if (load_matrix_from_file("vstup_matica.txt", matrix)) {
        // Analyze the matrix: find max, count negative and odd elements
        max = analyze_matrix(matrix, &negative_count, &odd_count);
        // Print the matrix
        print_matrix(matrix);
        // Print the analysis results
        printf("Negative numbers: %d, Odd numbers: %d, Maximum: %d\n", negative_count, odd_count, max);
    } else {
        printf("Failed to read the matrix from the file.\n"); // Error if loading fails
    }

    return 0; // End of program
}

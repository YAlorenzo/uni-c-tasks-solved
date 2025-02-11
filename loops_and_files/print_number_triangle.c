#include <stdio.h>

/*
 * Function print_number_triangle() prompts the user to enter a number of rows (1 to 15).
 * It performs the following tasks:
 * 1. Reads an integer from the user.
 * 2. If the number is outside the range [1, 15], it prints an error message and exits.
 * 3. Prints a triangular pattern where:
 *    - Each row starts with its index followed by a decreasing sequence of numbers.
 *
 * Output:
 * 1. A triangular pattern where numbers in each row decrease from left to right.
 *
 * Example:
 * Input: 4
 * Output:
 * 1: 1 2 3 4
 * 2: 1 2 3
 * 3: 1 2
 * 4: 1
*/

void print_number_triangle() {
  int row, col;
    printf("Zadajte pocet riadkov od 1 do 15: ");
    scanf("%d", &row);

    if (row < 1 || 15 < row){
        printf("Cislo nie je z daneho intervalu");
        return;
    }
    col = row;

    for (int i = 1; i <= row; i++){
        printf("%d: ", i);
        if (col != 0){
          for (int j = 1; j <= col; j++){
            printf("%d ", j);
          }
        col--;
        }
        printf("\n");
    }
}


int main(){
    print_number_triangle();
    return 0;
}

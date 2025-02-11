#include <stdio.h>

/*
 * Function write_multiples() prompts the user to enter a real number.
 * It performs the following tasks:
 * 1. Reads a floating-point number from the user.
 * 2. Writes its multiples to a file named "multiples.txt".
 * 3. Each line in the file contains:
 *    - The index (1 to 10)
 *    - The number multiplied by the index
 *    - The number multiplied by twice the index
 *    - The square of the number multiplied by the index
 *
 * Output:
 * The generated file "multiples.txt" contains formatted rows of calculations.
 *
 * Example:
 * Input: 2.5
 * Output in "multiples.txt":
 * 1:       2.50,       5.00,       2.50
 * 2:       5.00,      10.00,      10.00
 * ...
 */

void write_multiples() {
    float num;
    FILE *fw = fopen("multiples.txt", "w");

    if (fw == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter a real number: ");
    scanf("%f", &num);

    for (int i = 1; i <= 10; i++) {
        fprintf(fw, "%d: %10.2f, %10.2f, %10.2f\n", i, i * num, i * 2 * num, i * num * num);
    }

    fclose(fw);
}

int main() {
    write_multiples();
    return 0;
}

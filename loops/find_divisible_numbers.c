#include <stdio.h>

/*
 * Function find_divisible_numbers() prompts the user to enter the boundaries of an interval and a divisor.
 * It performs the following tasks:
 * 1. Iterates through the given interval.
 * 2. Checks which numbers are divisible by the given divisor.
 * 3. Prints all such numbers in the specified range.
 *
 * Output:
 * 1. The function prints all numbers within the range that are divisible by the given divisor.
 *
 * Example:
 * Input: 10 30 5
 * Output:
 * In the interval <10, 30>, the numbers divisible by 5 are: 10 15 20 25 30
 *
 * Input: 7 25 4
 * Output:
 * In the interval <7, 25>, the numbers divisible by 4 are: 8 12 16 20 24
 */

int find_divisible_numbers() {
    int bi, ei, div, i;
    printf("Zadajte hranice intervalu a delitel: ");
    scanf("%d %d %d", &bi, &ei, &div);

    printf("V intervale <%d, %d> su delitelne cislom %d cisla: ", bi, ei, div);
    for (i = bi; i <= ei; i++) {
        if (i % div == 0) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    find_divisible_numbers();

    return 0;
}

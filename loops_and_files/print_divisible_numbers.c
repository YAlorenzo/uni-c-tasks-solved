#include <stdio.h>

/*
 * Function print_divisible_numbers() prompts the user to enter an integer.
 * It performs the following tasks:
 * 1. Reads an integer from the user.
 * 2. Iterates through numbers from 1 to the given number.
 * 3. Computes the sum of integers from 1 to the current number.
 * 4. If the sum is divisible by 3, it prints the number.
 *
 * Output:
 * A list of numbers where the sum of integers from 1 to that number is divisible by 3.
 *
 * Example:
 * Input: 5
 * Output: 2 3 5
 */

void print_divisible_numbers() {
    int num, sum_k;
    printf("Enter an integer: ");
    scanf("%d", &num);

    for (int i = 1; i <= num; i++) {
        sum_k = 0;
        for (int k = 1; k <= i; k++) {
            sum_k += k;
        }
        if (sum_k % 3 == 0) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main (){
    print_divisible_numbers();
    return 0;
}

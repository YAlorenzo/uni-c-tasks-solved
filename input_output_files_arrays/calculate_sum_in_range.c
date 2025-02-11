#include <stdio.h>

/*
 * Function calculate_sum_in_range() prompts the user to enter two integers and calculates the sum of all integers
 * between these two numbers (exclusive). If the sum is zero (no numbers in the range), it prints an error message.
 * Otherwise, it prints the calculated sum.
 *
 * Input:
 *  - Two integers num1 and num2.
 *
 * Output:
 *  - If sum of integers is calculated, it displays the result.
 *  - If no sum can be calculated, it prints an error message.
 *
 * Example:
 * Input: 3 6
 * Output: sum: 12 (the sum of 4 and 5)
 */

void calculate_sum_in_range() {
    int num1, num2, sum = 0;

    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    for (int i = ++num1; i < num2; i++) {
        sum += i;
    }

    if (sum == 0) {
        printf("Cannot calculate the sum!");
        return;
    }

    printf("sum: %d", sum);
}


void calculate_sum_in_range_no_loop(){
    int num1, num2, sum = 0, n;
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    n = (num2 - num1) - 1;
    sum = (n * (num1 + num2)) / 2;
    printf("sum: %d", sum);

}

int main() {
    calculate_sum_in_range();
    return 0;
}

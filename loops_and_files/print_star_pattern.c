#include <stdio.h>

/*
 * Function print_star_pattern() prompts the user to enter an odd number
 * between 1 and 15. It then generates a symmetrical pattern using '*' and '-'
 * characters. The pattern starts with one '*' and expands until it reaches
 * the maximum width, then decreases back to one '*'.
 *
 * Output:
 * A diamond-like pattern where '*' represents stars, and '-' represents spaces.
 *
 * Example:
 * Input: 5
 * Output:
 * *----
 * **---
 * ***--
 * ****-
 * *****
 * ****-
 * ***--
 * **---
 * *----
 */

void print_star_pattern() {
    int num, count_stars = 1, is_first = 1;

    // Get user input
    printf("Enter an odd number from 1 to 15: ");
    scanf("%d", &num);

    // Validate input
    if (num < 1 || num > 15 || num % 2 == 0) {
        printf("Invalid input\n");
        return;
    }

    // Generate the pattern
    for (int i = 1; i < num * 2; i++) {
        for (int j = 1; j <= num; j++) {
            if (j <= count_stars) {
                printf("*");
            } else {
                printf("-");
            }
        }

        // Increase or decrease the number of stars
        if (is_first) {
            count_stars++;
            if (count_stars == num) {
                is_first = 0;
            }
        } else {
            count_stars--;
        }

        printf("\n");
    }
}
int main(){
    print_star_pattern();
    return 0;
}

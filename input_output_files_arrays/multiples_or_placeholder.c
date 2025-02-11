#include <stdio.h>

/*
 * Function print_multiples_or_placeholder() prompts the user to enter two integers p and k (0 < p, k < 100).
 * It then prints all integers from 1 to p, replacing the ones that are not multiples of k with " -- ".
 *
 * Input:
 *  - Two integers p and k, where 0 < p, k < 100.
 *
 * Output:
 *  - Prints integers from 1 to p, with " -- " in place of those that are not multiples of k.
 *
 * Example:
 * Input: 10 3
 * Output:
 * -- --  3 --  6 --  9 --
 */

void print_multiples_or_placeholder() {
   int num1, num2;
    printf("Zadajte dva cele cisla p a k (0 < p, k < 100): ");
    scanf("%d %d", &num1, &num2);

    for (int i = 1; i <= num1; i++){
        if(!(i % num2)){
            printf("%2d", i);
        }
        else {
            printf(" -- ");
        }
    }
}

int main() {
    print_multiples_or_placeholder();
    return 0;
}

#include <stdio.h>

/*
 * Function calculate_factorial() prompts the user to enter an integer and calculates its factorial using a loop.
 * The factorial of a number n is the product of all positive integers less than or equal to n.
 *
 * Input:
 *  - An integer num.
 *
 * Output:
 *  - The calculated factorial of num.
 *
 * Example:
 * Input: 5
 * Output: 120 (because 5! = 5 * 4 * 3 * 2 * 1 = 120)
 */

void calculate_factorial() {
   int num;
    unsigned long long fact = 1;
    printf("Zadajte cele cislo: ");
    scanf("%d", &num);

    if(num != 0){
        for(int i = 1; i <= num; i++){
            fact *= i;
        }
        printf("%llu", fact);
    }
}

int main() {
    calculate_factorial();
    return 0;
}

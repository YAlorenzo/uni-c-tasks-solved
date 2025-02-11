#include <stdio.h>

/*
 * Function draw_square() prompts the user to enter an integer N.
 * It performs the following tasks:
 * 1. Reads an integer N from the user.
 * 2. Prints an N x N square made of '*' characters.
 *
 * Output:
 * 1. A square of '*' characters with N rows and N columns.
 *
 * Example:
 * Input: 4
 * Output:
 * * * * *
 * * * * *
 * * * * *
 * * * * *
*/



void draw_square() {
    int n, i, g;
    printf("zadajte lubovolne cele cislo N a ziskajte stvorec NxN:  ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++){
        for (g = 1; g <= n; g++){
                printf("* ");
        }
        printf("\n");
    }
}

int main() {
    draw_square();
    return 0;
}

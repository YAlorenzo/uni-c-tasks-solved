#include <stdio.h>

/*
 * Function print_border_square() prompts the user to enter an integer N.
 * It performs the following tasks:
 * 1. Reads an integer N from the user.
 * 2. Prints a square pattern of '+' characters along the border and '*' characters inside the square.
 *    The square has N rows and N columns.
 *
 * Output:
 * 1. A square with '+' characters on the border and '*' characters inside.
 *
 * Example:
 * Input: 4
 * Output:
 * + + + +
 * + * * +
 * + * * +
 * + + + +
*/

void print_border_square() {
    int n, i, g, j;
    printf("Enter an integer N to generate a bordered NxN square:  ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (i == 1 || i == n || j == 1 || j == n) {
                printf("+ ");
            } else {
                printf("* ");
            }
        }
        printf("\n");
    }
}

int main(){
    print_border_square();

    return 0;
}

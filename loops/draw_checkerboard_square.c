#include <stdio.h>

/*
 * Function print_checkerboard_square() prompts the user to enter an integer N.
 * It performs the following tasks:
 * 1. Reads an integer N from the user.
 * 2. Prints a square pattern of '+' and '*' characters in a checkerboard style.
 *    The square has N rows and N columns, with alternating '+' and '*' characters.
 *    The pattern alternates each row, starting with either '+' or '*' depending on the row.
 *
 * Output:
 * 1. A checkerboard pattern of '+' and '*' characters in an NxN square.
 *
 * Example:
 * Input: 4
 * Output:
 * + * + *
 * * + * +
 * + * + *
 * * + * +
*/

int draw_checkerboard_square() {
    int n, i, j;
    printf("Enter an integer N to generate a checkerboard NxN square:  ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (i % 2 == 0) {
                if (j % 2 == 0) {
                    printf("+ ");
                } else {
                    printf("* ");
                }
            } else {
                if (j % 2 == 0) {
                    printf("* ");
                } else {
                    printf("+ ");
                }
            }
        }
        printf("\n");
    }
    return 0;
}

int main(){
    draw_checkerboard_square();
    return 0;
}

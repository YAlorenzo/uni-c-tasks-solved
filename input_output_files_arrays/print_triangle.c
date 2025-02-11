#include <stdio.h>

/*
 * Function print_triangle_pattern() generates and prints a pattern of triangles.
 * It takes the height of the triangle, the number of times the pattern is repeated horizontally,
 * and the number of times the pattern is printed.
 *
 * Parameters:
 * - h: Height of the triangle.
 * - s: The number of repetitions of the triangle pattern on each row.
 * - v: The number of times the entire pattern is printed.
 *
 * The function prints an upper and lower triangle pattern, where the numbers in the pattern
 * increment from 1 up to the current row index, and dashes "-" are used to fill the remaining spaces.
 *
 * Example:
 * Input: 3 3 2
 * Output:
    1--1--1--
    22-22-22-
    333333333
    22-22-22-
    1--1--1--
    1--1--1--
    22-22-22-
    333333333
    22-22-22-
    1--1--1--
 * (Printed 3 times)
 */
void troj(int h, int s){
     for (int i = 1; i <= h; i++){
        for (int k = 1; k <= s; k++){
            for (int j = 0; j < h; j++){
               if (j < i){
                 printf("%d", i);
               }
               else{
                 printf("-");
               }
            }
        }
        printf("\n");
    }
      for (int i = h - 1; i >= 1; i--){
         for (int k = 1; k <= s; k++){
            for (int j = 0; j < h; j++){
               if (j < i){
                 printf("%d", i);
               }
               else{
                 printf("-");
               }
            }
        }
        printf("\n");
      }

    }

int paint_troj(){
    int h, s, v;
    printf("Zdajte 3 cele cisla: ");
    scanf("%d %d %d", &h, &s, &v);

    for (int i = 1; i <= v; i++){
        troj(h, s);
    }
}

int main(){
    paint_troj();
    return 0;
}

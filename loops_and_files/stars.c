#include <stdio.h>

/*
 * This program generates a symmetrical star pattern using '*' and '-' characters.
 * The user is prompted to enter three inputs: an odd number (1-15) for the pattern size,
 * an integer (1-5) for the number of repetitions, and a character indicating alignment ('l' for vertical, any other for horizontal).
 *
 * The paint_star() function prints a single N x N pattern where '*' forms a cross and diagonals,
 * while '-' fills the rest. The draw_stars() function determines the alignment and calls paint_star()
 * accordingly. If 'l' is entered, patterns are printed one below the other. If 'r', patterns are printed in a row.
 *
 * Example:
 * Input: 9 3 l
 * Output:
    *---*---*
    -*--*--*-
    --*-*-*--
    ---***---
    *********
    ---***---
    --*-*-*--
    -*--*--*-
    *---*---*
    *---*---*
    -*--*--*-
    --*-*-*--
    ---***---
    *********
    ---***---
    --*-*-*--
    -*--*--*-
    *---*---*
    *---*---*
    -*--*--*-
    --*-*-*--
    ---***---
    *********
    ---***---
    --*-*-*--
    -*--*--*-
    *---*---*
 *
 * If a different character is entered:
 *
    *---*---**---*---**---*---*
    -*--*--*--*--*--*--*--*--*-
    --*-*-*----*-*-*----*-*-*--
    ---***------***------***---
    ***************************
    ---***------***------***---
    --*-*-*----*-*-*----*-*-*--
    -*--*--*--*--*--*--*--*--*-
    *---*---**---*---**---*---*
*/
int paint_star(int pattern_size){
    int center_pos = (pattern_size - 1) / 2 + 1;
    int start_pos = 1;
    int end_pos = pattern_size;

    for (int i = 1; i <= pattern_size; i++){
      for (int j = 1; j <= pattern_size; j++){
        if (j == center_pos || j == start_pos || j == end_pos || i == center_pos){
                printf("*");
        }
        else {
                printf("-");
        }
      }
      start_pos++;
      end_pos--;
      printf("\n");
    }
}


int draw_stars(){
    char dir;
    int num1, num2, center_pos, start_pos, end_pos;
    printf("Zadajte neparne cislo od 1 do 15: ");
    scanf("%d %d %c", &num1, &num2, &dir);

    if(num1 < 1 || 15 < num1 || num1 % 2 == 0 || num2 < 1 || num2 > 5 || (dir != 'l' && dir != 'r')){
       printf("Zly vstup");
       return;
    }

    center_pos = (num1 - 1) / 2 + 1;
    start_pos = 1;
    end_pos = num1;

    if (dir == 'l'){
         for (int v = 1; v <= num2; v++){
            paint_star(num1);
         }
    }
    else if(dir == 'r') {
      for (int i = 1; i <= num1; i++){
       for (int v = 1; v <= num2; v++){
          for (int j = 1; j <= num1; j++){
              if (j == center_pos || j == start_pos || j == end_pos || i == center_pos){
                printf("*");
              }
              else {
                printf("-");
              }
           }
       }
      start_pos++;
      end_pos--;
      printf("\n");
     }
    }
}


int main(){
   draw_stars();
   return 0;
}

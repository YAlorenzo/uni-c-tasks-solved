#include <stdio.h>

/*
 * Function check_sequence_validity() prompts the user to enter a sequence of numbers and checks if the sequence is valid.
 * The sequence is valid if each number (starting from the second number) is between half and twice the previous number.
 *
 * Input:
 *  - An integer num1 representing the number of elements in the sequence (num1 > 0).
 *  - A series of num1 integers, each representing a number in the sequence, where the first number must be between 0 and 10.
 *
 * Output:
 *  - Prints "Postupnost je spravna" if the sequence is valid, otherwise prints "Postupnost nie je spravna".
 *
 * Example:
 * Input:
 * 5
 * 4
 * 6
 * 8
 * 7
 * 10
 * Output:
 * Postupnost je spravna
 */

void check_sequence_validity() {
     int num1, num2, prev_num;
    int is_true = 1;
    printf("Zadajte pocet cisel v postupnosti: ");
    scanf("%d", &num1);
    if (num1 <= 0) {
        printf("Postupnost nie je spravna\n");
        return 0;
    }
    printf("Zadajte prve cislo (v rozsahu 0 az 10): ");
    scanf("%d", &prev_num);
    if (prev_num < 0 || prev_num > 10) {
        printf("Postupnost nie je spravna\n");
        return 0;
    }

    for (int i = 1; i < num1; i++) {
        scanf("%d", &num2);
        if (num2 < prev_num / 2 || num2 > prev_num * 2) {
            is_true = 0;
            break;
        }
        prev_num = num2;
    }

    is_true ? printf("Postupnost je spravna") : printf("Postupnost nie je spravna");
}

int main() {
    check_sequence_validity();
    return 0;
}

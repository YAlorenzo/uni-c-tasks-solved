#include <stdio.h>

/*
 * Function read_and_reverse_evens() reads integers from a file named "numbers.txt".
 * It performs the following tasks:
 * 1. Reads integers from "numbers.txt".
 * 2. Stores only even numbers in an array.
 * 3. Prints the even numbers in reverse order.
 *
 * Output:
 * A list of even numbers printed in reverse order.
 *
 * Example:
 * File "numbers.txt" contains: 3 8 12 5 4
 * Output: 4 12 8
 */

void read_and_reverse_evens() {
    int arr[100] = {0};
    int num, i = 0;
    FILE *fr = fopen("numbers.txt", "r");

    if (fr == NULL) {
        printf("Error opening file!\n");
        return;
    }

    while (fscanf(fr, "%d", &num) != EOF) {
        if (num % 2 == 0) {
            arr[i++] = num;
        }
    }

    fclose(fr);

    for (int j = i - 1; j >= 0; j--) {
        printf("%d ", arr[j]);
    }
    printf("\n");
}

int main() {
    read_and_reverse_evens();
    return 0;
}

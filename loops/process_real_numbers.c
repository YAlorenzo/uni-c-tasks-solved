/*
 * Function processRealNumbers() prompts the user to input a series of real numbers.
 * It performs the following tasks:
 * 1. Computes the average of negative numbers.
 * 2. Finds the maximum of the positive numbers.
 * 3. Counts the numbers within the range of -5.5 to 5.5.
 *
 * Output:
 * 1. The average of the negative numbers is printed (rounded to 2 decimal places).
 * 2. The maximum positive number is printed (rounded to 3 decimal places).
 * 3. The count of numbers in the range [-5.5, 5.5] is printed.
 */


int process_real_numbers()
{
    int n, i;
    float resultNeg = 0;
    float neg = 0, pos = 0, in;
    int quanNeg = 0, quanScope = 0;

    printf("Enter the number of real numbers: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        printf("Enter the %d-th number: ", i);
        scanf("%f", &in);

        if (in < 0) {
            neg += in;
            quanNeg += 1;
            resultNeg = neg / quanNeg;
        }
        else if (in >= 0) {
            if (pos < in) {
                pos = in;
            }
        }

        if (in >= -5.5 && in <= 5.5) {
            quanScope += 1;
        }
    }

    if (resultNeg == (int)resultNeg) {
        printf("Average of negative numbers: %d\n", (int)resultNeg);
    } else {
        printf("Average of negative numbers: %.2f\n", resultNeg);
    }

    if (pos == (int)pos) {
        printf("Maximum positive number: %d\n", (int)pos);
    } else {
        printf("Maximum positive number: %.3f\n", pos);
    }

    printf("Count of numbers in range [-5.5, 5.5]: %d\n", quanScope);
}


int main (){
    process_real_numbers();
}

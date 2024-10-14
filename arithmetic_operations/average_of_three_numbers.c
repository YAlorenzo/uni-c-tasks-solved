#include <stdio.h>

int calculate_average_of_three() {
    double num1, num2, num3, avg;

    printf("Enter 3 real numbers: ");
    scanf("%lf %lf %lf", &num1, &num2, &num3);

    avg = (num1 + num2 + num3) / 3;

    printf("The average of numbers %.2lf, %.2lf, %.2lf is: %.2lf\n", num1, num2, num3, avg);
    return 0;
}

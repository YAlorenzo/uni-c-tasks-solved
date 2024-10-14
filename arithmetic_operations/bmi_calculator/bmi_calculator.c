#include <stdio.h>

int calculate_bmi() {
    int weight, height;
    printf("Enter height in centimeters: ");
    scanf("%d", &height);
    printf("Enter weight in kilograms: ");
    scanf("%d", &weight);

    double heightInMeters = height / 100.0;
    double BMI = weight / (heightInMeters * heightInMeters);

    printf("BMI: %.2lf\n", BMI);
    return 0;
}

int main () {
   calculate_bmi();
}

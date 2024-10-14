#include <stdio.h>
#include <math.h>

int calculate_circle_properties() {
    double radius, circumference, area;
    printf("Enter the radius of the circle (real number): ");
    scanf("%lf", &radius);

    circumference = 2 * M_PI * radius;
    area = M_PI * radius * radius;

    printf("Circle with radius %.2lf: circumference = %.2lf, area = %.2lf\n", radius, circumference, area);

    return 0;
}


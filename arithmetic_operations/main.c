#include <stdio.h>

extern int calculate_bmi();
extern int print_special_characters();
extern int calculate_volume_and_surface();
extern int calculate_circle_properties();
extern int calculate_average_of_three();
extern int calculate_price_with_tax();

int main() {
    // Call the desired functions here
    calculate_bmi();
    print_special_characters();
    calculate_volume_and_surface();
    calculate_circle_properties();
    calculate_average_of_three();
    calculate_price_with_tax();

    return 0;
}

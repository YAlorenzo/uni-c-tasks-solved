#include <stdio.h>

int calculate_price_with_tax() {
    int price;

    printf("Enter price before tax: ");
    scanf("%d", &price);

    printf("Price before tax: %d\n", price);
    printf("Selling price with 20%% tax: %.2f\n", price * 1.2);

    return 0;
}


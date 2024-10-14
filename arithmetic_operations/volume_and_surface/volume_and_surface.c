#include <stdio.h>

int calculate_volume_and_surface() {
    int length, width, height; // length, width, height
    printf("Enter 3 integers separated by spaces: ");

    scanf("%d %d %d", &length, &width, &height);

    int volume = length * width * height;
    int surface_area = 2 * (length * width) + 2 * (length * height) + 2 * (width * height);

    printf("Volume: %d * %d * %d is %d\n", length, width, height, volume);
    printf("Surface Area: 2 * %d * %d + 2 * %d * %d + 2 * %d * %d is %d\n", length, width, length, height, width, height, surface_area);

    return 0;
}

int main () {
    calculate_volume_and_surface();
}

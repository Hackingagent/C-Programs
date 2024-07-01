#include <stdio.h>

int main() {
    int arr1[4] = {1, 2, 3, 4};
    int arr2[3] = {5, 6, 7};
    int index = 2;
    int i, j;

    // Shift elements in arr1 to make space for arr2
    for (i = 3; i >= index; i--) {
        arr1[i+3] = arr1[i];
    }

    // Copy arr2 into arr1 at the specified index
    for (j = 0; j < 4; j++) {
        arr1[index+j] = arr2[j];
    }

    // Print out the new array arr1
    for (i = 0; i < 7; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    return 0;
}


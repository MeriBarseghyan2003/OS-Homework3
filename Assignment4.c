#include <stdio.h>

int main() {
    int num = 42;
    int *ptr = &num;
    int **doublePtr = &ptr;
    printf("Value of the integer (using pointer): %d\n", *ptr);
    printf("Value of the integer (using double-pointer): %d\n", **doublePtr);

    return 0;
}

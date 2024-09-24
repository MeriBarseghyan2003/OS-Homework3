#include <stdio.h>

int main() {
    int num = 10;
    int *ptr = &num;

    printf("Address of the integer (using variable): %p\n", (void*)&num);
    printf("Address of the integer (using pointer): %p\n", (void*)ptr);
    *ptr = 20;
    printf("New value of the integer: %d\n", num);

    return 0;
}

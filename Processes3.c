#include <stdio.h>
#include <stdlib.h>  
void first_exit_function() {
    printf("First exit function called.\n");
}

void second_exit_function() {
    printf("Second exit function called.\n");
}

int main() {
    atexit(first_exit_function);
    atexit(second_exit_function);

    printf("Main function: Program is running.\n");

    printf("Calling exit() now...\n");
    exit(0);  
    printf("This line will not be printed.\n");

    return 0;
}
/*
Resource Cleanup: In real-world applications, 
atexit() can be used to automatically release 
resources such as memory, file handles, 
or network connections when the program terminates. 
This ensures that even if the program exits unexpectedly,
 resources are properly freed.

Logging: atexit() can be useful to register logging functions 
to record program termination, which can help in debugging 
or understanding program behavior.
*/
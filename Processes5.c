#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    } else if (pid == 0) {
        printf("Child process: PID = %d\n", getpid());
        exit(0); 
    } else {
        printf("Parent process: PID = %d\n", getpid());
        sleep(10); 
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t first_child = fork();

    if (first_child < 0) {
        perror("Fork failed for the first child");
        return 1;
    } else if (first_child == 0) {
        printf("First child process: PID = %d\n", getpid());
        exit(100);  
    } else {
        pid_t second_child = fork();

        if (second_child < 0) {
            perror("Fork failed for the second child");
            return 1;
        } else if (second_child == 0) {
            printf("Second child process: PID = %d\n", getpid());
            exit(200);  
        } else {
            int status;
            pid_t wpid1 = waitpid(first_child, &status, 0);
            if (wpid1 == first_child) {
                if (WIFEXITED(status)) {
                    printf("First child exited with status %d\n", WEXITSTATUS(status));
                } else {
                    printf("First child did not exit normally\n");
                }
            }

            pid_t wpid2 = waitpid(second_child, &status, 0);
            if (wpid2 == second_child) {
                if (WIFEXITED(status)) {
                    printf("Second child exited with status %d\n", WEXITSTATUS(status));
                } else {
                    printf("Second child did not exit normally\n");
                }
            }
        }
    }

    return 0;
}

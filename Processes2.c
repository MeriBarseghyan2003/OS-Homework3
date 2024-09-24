#include <stdio.h>
#include <unistd.h>    
#include <sys/wait.h>  
#include <sys/types.h> 

int main() {
    pid_t first_child = fork();

    if (first_child < 0) {
        perror("First fork failed");
        return 1;
    }
    else if (first_child == 0) {
        printf("First child process: PID = %d\n", getpid());
        return 1;
    } else {
        pid_t second_child = fork();

        if (second_child < 0) {
            perror("Second fork failed");
            return 1;
        }
        else if (second_child == 0) {
            printf("Second child process: PID = %d\n", getpid());
            return 2;
        }
        else {
            int status;
            pid_t wpid = waitpid(first_child, &status, 0); 
            if (wpid == first_child) {
                if (WIFEXITED(status)) {
                    printf("First child exited with status %d\n", WEXITSTATUS(status));
                }
            }

            pid_t child_pid = wait(&status); 
            if (child_pid == second_child) {
                if (WIFEXITED(status)) {
                    printf("Second child exited with status %d\n", WEXITSTATUS(status));
                }
            }
            printf("Parent process: PID = %d\n", getpid());
        }
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>  

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    } else if (pid == 0) {
        printf("Child process: PID = %d\n", getpid());
        exit(0); 
    } else {
        printf("Parent process: PID = %d, waiting for child PID = %d\n", getpid(), pid);
        wait(NULL);  
        printf("Child process has been cleaned up, no zombie process\n");
    }

    return 0;
}
/*
In this version, the parent process calls wait(), which pauses the execution of the parent until the child terminates.
This cleans up the child process and prevents it from becoming a zombie.
How wait() and waitpid() Prevent Zombie Processes:
When a child process terminates, its exit status and some information are still held in the process table by the kernel
until the parent acknowledges it by calling wait() or waitpid(). If the parent never does this, the child remains in the
process table as a zombie.

wait(): Causes the parent to wait for any child process to finish. Once the child finishes, its exit status is returned,
and the child is removed from the process table, preventing it from becoming a zombie.

waitpid(): Works similarly to wait(), but allows the parent to wait for a specific child process to finish, giving more
control over which child the parent waits for.

Using wait() or waitpid() ensures that the child’s resources are properly cleaned up, preventing the accumulation of zombie processes.
*/
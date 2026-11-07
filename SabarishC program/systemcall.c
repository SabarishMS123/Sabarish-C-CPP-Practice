#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    pid = fork();
    
    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    } else if (pid == 0) {
        printf("Child process:\n");
        printf("PID = %d\n", getpid());
        printf("Parent PID = %d\n", getppid());
        exit(0);
    } else {
        printf("Parent process:\n");
        printf("PID = %d\n", getpid());
        printf("Waiting for child process to exit...\n");
        wait(NULL);
        printf("Child process has exited\n");
    }
    
    return 0;
}


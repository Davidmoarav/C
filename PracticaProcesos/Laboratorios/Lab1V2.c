#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>

char* timestamp(void) {
    time_t rawtime;
    struct tm *timeinfo;
    static char buffer[80];

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", timeinfo);
    return buffer;
}

int main(int argc, char** argv){
    int status;
    int pid;
   
    if((pid = fork()) == 0){
        printf("[%s] Child process (PID = %d)\n", timestamp(), getpid());
        exit(0);
    }else{
        printf("[%s] Father process (PID = %d)\n", timestamp(), getpid());
        wait(&status);
    }

    return 0;
}

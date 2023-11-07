#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>

char* timestamp() {

  char* timestamp_buffer = malloc(100);

  struct timeval tv;
  gettimeofday(&tv, NULL);

  strftime(timestamp_buffer,100, "%Y:%m:%d %H:%M:%S",localtime(&tv.tv_sec));
  sprintf(timestamp_buffer+strlen(timestamp_buffer),":%ld",tv.tv_usec);

  return timestamp_buffer;
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

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char **argv){

    int fd[2]; 
               
    int pid, status;

    pipe(fd); 

    if((pid = fork()) == 0){
        printf("Child process: created \n");
        int number = 0;
        char *mensaje = " ";

        read(fd[0], &mensaje, sizeof(int));

        printf("Child process string read: %s \n", mensaje);

        exit(0);
    }else{
        int number = 900;
        char *mensaje = "SOY TU PADRE";

        printf("Father process\n");
      
        write(fd[1], &mensaje, sizeof(int));

        printf("Father process: string written\n");

        wait(&status); 
    }
    return 0;
}

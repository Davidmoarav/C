#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
    int pid, estado, numero = 300;

    pid = fork();

    if(pid == 0){
        printf("Numero del proceso hijo es: %d \n", numero);
        numero = 400;

        exit(0);
    }else{
        printf("Numero del proceso padre es:  %d \n", numero);
        numero = 500;

        wait(&estado);
    }
    return 0;
}

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    pid_t id_proceso;
    pid_t id_padre;

    id_proceso = getpid();
    id_padre = getppid();

    printf("Numero de identificador del proceso hijo: %d\n", id_proceso);
    printf("Numero de indentificador del proceso padre: %d\n", id_padre);

    return 0;
}

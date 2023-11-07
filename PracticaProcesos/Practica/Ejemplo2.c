#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    uid_t id_usuarioReal;
    uid_t id_usuarioEfectivo;
    gid_t id_grupoReal;
    gid_t id_grupoEfectivo;

    id_usuarioReal = getuid();
    id_usuarioEfectivo = geteuid();
    id_grupoReal = getgid();
    id_grupoEfectivo = getegid();

    printf("Identificador del usuario real: %d\n", id_usuarioReal);
    printf("Identificador del usuario efectivo: %d\n", id_usuarioEfectivo);
    printf("Identificador del grupo real: %d\n", id_grupoReal);
    printf("Identificador del grupo efectivo: %d\n", id_grupoEfectivo);

    return 0;
}

// iTz_DiLAN

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

// Estructura para definir los datos de la persona
struct Persona{
    char nombre[50];
    char apellido[50];
    char empresa[50];
    char direccion[50];
    char ciudad[50];
    char pais[50];
    char estado[50];
    char codigoPostal[50];
    char telefono1[50];
    char telefono2[50];
    char email[50];
    char web[50];
};

/*Esta función imprime una cuenta regresiva en la pantalla. 
El valor del parámetro 'valor' determina el mensajes de cuenta regresiva ("Buscando ..." o "Cargando ...") según el valor proporcionado.*/
void cuentaRegresiva(int valor){
    if(valor == 1){
        for(int i = 3; i > 0; i --){
            printf("Buscando ...\n");
            sleep(1);
        }
        printf("\n");
    }

    if(valor == 2){
        for(int i = 3; i > 0 ; i --){
            printf("Cargando ...\n");
            sleep(1);
        }
        printf("\n");
    }
}
/*Esta función abre un archivo en el modo especificado. 
El parámetro nombreArchivo especifica el nombre del archivo. 
El parámetro modo especifica el modo en el que se abrirá el archivo.*/
FILE *abrirArchivo(const char *nombreArchivo, const char *modo){
    FILE *archivo = fopen(nombreArchivo, modo);

    if(archivo == NULL){
        perror("No se pudo abrir el archiv.");
        exit(EXIT_FAILURE);
    }
    return archivo;
}
//Función para cerrar el archivo//
void cerrarArchivo(FILE *archivo){
    fclose(archivo);
}
/*Esta función agrega una persona al archivo. 
El parámetro archivo especifica el archivo al que se agregará la persona. 
El parámetro persona especifica la persona que se agregará.*/

void agregarPersona(FILE *archivo, struct Persona *persona){
    fwrite(persona, sizeof(struct Persona), 1, archivo);
}
/*Busca en el archivo una persona con el email proporcionado e imprime si se encuentra o no.*/
void buscarPorEmail(FILE *archivo, const char *email){
    struct Persona persona;
/*abre el archivo en modo lectura*/
    fseek(archivo, 0, SEEK_SET);

    printf("\n");
    printf("Buscando por el siguiente email: %s\n\n", persona.email);
    cuentaRegresiva(1);
    /*Itera sobre el archivo, leyendo una persona a la vez.
    Compara la dirección de correo electrónico de la persona actual con la dirección de correo electrónico que se está buscando.
    Si las direcciones de correo electrónico coinciden, la función imprime información sobre la persona.*/
    while(fread(&persona, sizeof(struct Persona), 1, archivo) == 1){
        if(strcmp(persona.email, email) == 0){
            printf("Persona con email '%s' SI se encontro.\n", persona.email);
            printf("Nombre: %s %s\n", persona.nombre, persona.apellido);
            printf("Email: %s\n", persona.email);
            printf("-----------------------------\n");
            return;
        }
    }

    printf("Persona con email '%s' NO encontrada.\n", persona.email);
    printf("\n");
    printf("-----------------------------\n");
}

/*Modifica un registro en el archivo según el campo especificado (nombre, apellido, empresa, etc.) y un nuevo valor.*/

void modificarRegistroPersona(FILE *archivo, const char *email, int campo, const char *nuevoValor) {
    struct Persona persona;

    fseek(archivo, 0, SEEK_SET);  // Ir al principio del archivo

    printf("Modificando registro...\n");
    cuentaRegresiva(2);
    while (fread(&persona, sizeof(struct Persona), 1, archivo) == 1) {
        if (strcmp(persona.email, email) == 0) {
            // Modificar la información de la persona
            fseek(archivo, -sizeof(struct Persona), SEEK_CUR);  // Retroceder para sobrescribir el registro

            switch (campo) {
                case 1: // firstName
                    strncpy(persona.nombre, nuevoValor, sizeof(persona.nombre) - 1);
                    break;
                case 2: // lastName
                    strncpy(persona.apellido, nuevoValor, sizeof(persona.apellido) - 1);
                    break;
                case 3: // company
                    strncpy(persona.empresa, nuevoValor, sizeof(persona.empresa) - 1);
                    break;
                // Agrega más casos según sea necesario para otros campos
                default:
                    printf("Campo no válido.\n");
                    return;
            }

            fwrite(&persona, sizeof(struct Persona), 1, archivo);
            printf("Registro de persona modificado con éxito.\n");
            printf("-----------------------------\n");
            return;
        }
    }

    printf("Persona con email '%s' no encontrada. No se realizó ninguna modificación.\n", email);
}

void mostrarRegistroPersonaPorEmail(FILE *archivo, const char *email) {
    struct Persona persona;

    fseek(archivo, 0, SEEK_SET);  // Ir al principio del archivo

    printf("Registro de la persona que tiene email: %s\n", persona.email);

    while (fread(&persona, sizeof(struct Persona), 1, archivo) == 1) {
        if (strcmp(persona.email, email) == 0) {
            // Persona encontrada, mostrar el registro
            printf("Nombre: %s %s\n", persona.nombre, persona.apellido);
            printf("Email: %s\n", persona.email);
            printf("Compañía: %s\n", persona.empresa);
            printf("Dirección: %s, %s, %s, %s, %s\n", persona.direccion, persona.ciudad, persona.pais, persona.estado, persona.codigoPostal);
            printf("Teléfono 1: %s\n", persona.telefono1);
            printf("Teléfono 2: %s\n", persona.telefono2);
            printf("Sitio web: %s\n", persona.web);
            printf("-----------------------------\n");
            return;  // Salir del bucle después de mostrar el registro
        }
    }

    printf("Persona con email '%s' NO encontrada.\n", email);
}

void mostrarRegistrosPersonas(FILE *archivo) {
    struct Persona persona;

    fseek(archivo, 0, SEEK_SET);  // Ir al principio del archivo
    
    printf("Registro de TODAS las Personas\n\n");

    int contador = 1;
    while (fread(&persona, sizeof(struct Persona), 1, archivo) == 1) {
        // Mostrar el registro de la persona
        printf("Registro de persona %d:\n", contador);
        printf("Nombre: %s %s\n", persona.nombre, persona.apellido);
        printf("Email: %s\n", persona.email);
        printf("Compañía: %s\n", persona.empresa);
        printf("Dirección: %s, %s, %s, %s, %s\n", persona.direccion, persona.ciudad, persona.pais, persona.estado, persona.codigoPostal);
        printf("Teléfono 1: %s\n", persona.telefono1);
        printf("Teléfono 2: %s\n", persona.telefono2);
        printf("Sitio web: %s\n", persona.web);
        printf("-----------------------------\n");
        contador = contador + 1;
    }
}

int main(){
    const char *nombreArchivo = "registro_persona.bin";
    FILE *archivo = abrirArchivo(nombreArchivo, "wb+");

    struct Persona persona1 = {"John", "Doe", "Company1", "Address1", "City1", "County1", "State1", "12345", "111-111-1111", "222-222-2222", "john@example.com", "www.example.com"};
    struct Persona persona2 = {"Jane", "Doe", "Company2", "Address2", "City2", "County2", "State2", "54321", "333-333-3333", "444-444-4444", "jane@example.com", "www.example.org"};

    agregarPersona(archivo, &persona1);
    agregarPersona(archivo, &persona2);

    modificarRegistroPersona(archivo, "john@example.com", 1, "Jonathan");
    
    buscarPorEmail(archivo, "john@example.com");
    buscarPorEmail(archivo, "jane@example.org");

    mostrarRegistroPersonaPorEmail(archivo, "john@example.com");

    printf("\n");

    mostrarRegistrosPersonas(archivo);
    cerrarArchivo(archivo);

    return 0;
}

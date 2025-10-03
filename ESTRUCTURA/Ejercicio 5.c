/*Crear una estructura llamada persona con sus atributos nombre, apellido, fecha de nacimiento, dirección y teléfono. 
Tanto la dirección como la fecha de nacimiento son otras estructuras (estructura anidada). Cargue con datos y luego muéstrelos.
*/

#include <stdio.h>
#include <string.h>

struct Nacimiento{
    int dia;
    int mes;
    int anio;
};

struct Direccion{
    char calle[30];
    char localidad[30];
    char pais[20];
    int numero;
};

struct Persona{
    char nombre[20];
    char apellido[20];
    struct Direccion direccion;
    struct Nacimiento nacimiento;

};

int main(){
struct Persona persona;
printf("Ingrese los siguientes datos de la persona que desee:\n");
printf("Nombre: ");
fgets(persona.nombre, 20, stdin);
persona.nombre[strcspn(persona.nombre, "\n")] = '\0';
printf("\nApellido: ");
fgets(persona.apellido, 20, stdin);
persona.apellido[strcspn(persona.apellido, "\n")] = '\0';
printf("\nDireccion\n");
printf("Calle: ");
fgets(persona.direccion.calle, 30, stdin);
persona.direccion.calle[strcspn(persona.direccion.calle, "\n")] = '\0';
printf("\nLocalidad: ");
fgets(persona.direccion.localidad, 30, stdin);
persona.direccion.localidad[strcspn(persona.direccion.localidad, "\n")] = '\0';
printf("\nPais: ");
fgets(persona.direccion.pais, 20, stdin);
persona.direccion.pais[strcspn(persona.direccion.pais, "\n")] = '\0';
printf("\nNumero: ");
scanf(" %d", &persona.direccion.numero);
printf("\nFecha de nacimiento\n");
printf("Dia: ");
scanf(" %d", &persona.nacimiento.dia);
printf("\nMes: ");
scanf(" %d", &persona.nacimiento.mes);
printf("\nAnio: ");
scanf(" %d", &persona.nacimiento.anio);

printf("\n\nSe cargaron los siguientes datos:\n");
printf("%-20s | %s\n", "Nombre", "Apellido");
printf("%-20s | %s\n", 
    persona.nombre,
    persona.apellido);
printf("\nDireccion:\n");
printf("%-30s | %-30s | %-20s | %s\n", "Calle", "Localidad", "Pais", "Numero");
printf("%-30s | %-30s | %-20s | %d\n",
    persona.direccion.calle,
    persona.direccion.localidad,
    persona.direccion.pais,
    persona.direccion.numero
);
printf("\nFecha de nacimiento:\n");
printf("%-3s | %-3s | %s\n", "Dia", "Mes", "Anio");
printf("%-3d | %-3d | %d\n", 
    persona.nacimiento.dia,
    persona.nacimiento.mes,
    persona.nacimiento.anio
);

    return 0;
}
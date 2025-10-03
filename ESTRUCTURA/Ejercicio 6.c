/*Ampliar el ejercicio anterior y modificarlo para que se cree un vector de estructuras de tamaño 2.
Cargar valores y mostrar.
*/

#include <stdio.h>
#include <string.h>
#define MAX 2

struct Nacimiento
{
    int dia;
    int mes;
    int anio;
};

struct Direccion
{
    char calle[30];
    char localidad[30];
    char pais[20];
    int numero;
};

struct Persona
{
    char nombre[20];
    char apellido[20];
    struct Direccion direccion;
    struct Nacimiento nacimiento;
};

int main()
{
    char bandera = 's';
    struct Persona persona[MAX];
    for (int i = 0; i < MAX; i++)
    {
        if (bandera == 's' || bandera == 'S')
        {
            printf("Ingrese los siguientes datos de la persona que desee:\n");
            printf("Nombre: ");
            fgets(persona[i].nombre, 20, stdin);
            persona[i].nombre[strcspn(persona[i].nombre, "\n")] = '\0';
            printf("\nApellido: ");
            fgets(persona[i].apellido, 20, stdin);
            persona[i].apellido[strcspn(persona[i].apellido, "\n")] = '\0';
            printf("\nDireccion\n");
            printf("Calle: ");
            fgets(persona[i].direccion.calle, 30, stdin);
            persona[i].direccion.calle[strcspn(persona[i].direccion.calle, "\n")] = '\0';
            printf("\nLocalidad: ");
            fgets(persona[i].direccion.localidad, 30, stdin);
            persona[i].direccion.localidad[strcspn(persona[i].direccion.localidad, "\n")] = '\0';
            printf("\nPais: ");
            fgets(persona[i].direccion.pais, 20, stdin);
            persona[i].direccion.pais[strcspn(persona[i].direccion.pais, "\n")] = '\0';
            printf("\nNumero: ");
            scanf(" %d", &persona[i].direccion.numero);
            printf("\nFecha de nacimiento\n");
            printf("Dia: ");
            scanf(" %d", &persona[i].nacimiento.dia);
            printf("\nMes: ");
            scanf(" %d", &persona[i].nacimiento.mes);
            printf("\nAnio: ");
            scanf(" %d", &persona[i].nacimiento.anio);
            if (i < MAX - 1)
            {
                printf("\nDesea ingresar los datos de otra persona\?: Si(s), No(n)\n");
                scanf(" %c", &bandera);
            }
            getchar();
        }
    }

    printf("\n\nSe cargaron los siguientes datos:\n");
    printf("%-20s | %s\n", "Nombre", "Apellido");
    for (int i = 0; i < MAX; i++)
    {
        printf("%-20s | %s\n", persona[i].nombre, persona[i].apellido);
    }
    printf("\nDireccion:\n");
    printf("%-30s | %-30s | %-20s | %s\n", "Calle", "Localidad", "Pais", "Numero");
    for (int i = 0; i < MAX; i++)
    {
        printf("%-30s | %-30s | %-20s | %d\n", persona[i].direccion.calle,
               persona[i].direccion.localidad, persona[i].direccion.pais,
               persona[i].direccion.numero);
    }
    printf("\nFecha de nacimiento:\n");
    printf("%-3s | %-3s | %s\n", "Dia", "Mes", "Anio");
    for (int i = 0; i < MAX; i++)
    {
        printf("%-3d | %-3d | %d\n", persona[i].nacimiento.dia, persona[i].nacimiento.mes,
               persona[i].nacimiento.anio);
    }
    return 0;
}
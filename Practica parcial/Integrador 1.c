/*Escriba un programa en C que lea un archivo de texto con datos de personas.
Cada línea del archivo contiene los siguientes datos: Nombre, Apellido, Edad.
El programa debe utilizar una estructura para almacenar los datos de cada persona.
La estructura debe tener los siguientes campos: nombre: char[25], apellido: char[25], edad: int.
El programa debe utilizar punteros con funciones para realizar las siguientes tareas:
Leer el archivo de texto y almacenar los datos en una estructura.
Imprimir los datos de cada persona.
Liberar la memoria reservada para las estructuras.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nombre[25];
    char apellido[25];
    int edad;
} Persona;

void IngresarPersona(Persona **, int *);
void GuardarDatos(Persona *, int);
void LeerDatos(Persona *, int);
void LiberarMemoria(Persona **, int *);
void Menu();

int main()
{
    Menu();
    return 0;
}

void Menu()
{
    char opcion = ' ';
    char volver = 's';
    Persona *persona = NULL;
    int Cant = 0;

    do
    {
        printf("Ingrese la opcion que desee ejecutar\n");
        printf("---------------------------------------\n");
        printf("a. Ingresar una persona\n");
        printf("b. Guardar sus datos en un archivo\n");
        printf("c. Leer los datos de las persoas ingresadas\n");
        printf("d. Liberar la memoria utilizada\n");
        scanf(" %c", &opcion);

        switch (opcion)
        {
        case 'a':
        case 'A':
            IngresarPersona(&persona, &Cant);
            break;
        case 'b':
        case 'B':
            GuardarDatos(persona, Cant);
            break;
        case 'c':
        case 'C':
            LeerDatos(persona, Cant);
            break;
        case 'd':
        case 'D':
            LiberarMemoria(&persona, &Cant);
            break;
        default:
            printf("No se ha seleccionado una opcion correcta\n");
            break;
        }
        printf("Desea volver al menu\?: Si(s), No(n)\n");
        scanf(" %c", &volver);
        getchar();

    } while (volver == 's' || volver == 'S');

    free(persona);
    *persona = NULL;
}

void IngresarPersona(Persona **personas, int *cant)
{

    char otro = 's';
    Persona *personas2 = NULL;

    do
    {
        personas2 = (Persona *)realloc(*personas, (*cant + 1) * sizeof(Persona));
        if (personas2 != NULL)
        {
            *personas = personas2;
            printf("Ingrese los datos de la persona\n");
            printf("Nombre: ");
            getchar();
            fgets((*personas + *cant)->nombre, 25, stdin);
            (*personas + *cant)->nombre[strcspn((*personas + *cant)->nombre, "\n")] = '\0';
            printf("\nApellido: ");
            fgets((*personas + *cant)->apellido, 25, stdin);
            (*personas + *cant)->apellido[strcspn((*personas + *cant)->apellido, "\n")] = '\0';
            printf("\nEdad: ");
            scanf(" %d", &(*personas + *cant)->edad);
            printf("\nDesea ingresar otra persona\?: Si(s), No(n)\n");
            scanf(" %c", &otro);
            (*cant)++;
        }
        else
        {
            printf("Error al ingresar persona\n");
            return;
        }
    } while (otro == 's' || otro == 'S');
}

void GuardarDatos(Persona *personas, int cant)
{
    FILE *archivo;
    archivo = fopen("datos.txt", "w");
    if (archivo != NULL)
    {
        printf("\nEl archivo se ha abierto en exito\n");
        printf("----------------------------------------\n")
        printf("Guardando los datos ingresados...\n");
        printf("----------------------------------------\n");
        for (int i = 0; i < cant; i++)
        {
            fprintf(archivo, "%s, %s, %d\n", (personas + i)->nombre, (personas + i)->apellido,
                    (personas + i)->edad);
        }
        fclose(archivo);
        printf("Los datos se han guardado con exito\n");
    }
    else
    {
        printf("Error al abrir el archivo\n");
        return;
    }
}

void LeerDatos(Persona *persona, int Cant)
{
    FILE *archivo;
    archivo = fopen("datos.txt", "r");
    if (archivo != NULL)
    {
        printf("\nLeyendo datos...\n");
        printf("------------------------\n")
        for (int i = 0; i < Cant; i++)
        {
            fscanf(archivo, "%s %s %d", (persona + i)->nombre, (persona + i)->apellido,
                   &(persona + i)->edad);
            printf("Nombre: %s Apellido: %s Edad: %d\n", (persona + i)->nombre,
                   (persona + i)->apellido, (persona + i)->edad);
        }
        fclose(archivo);
    }
    else
    {
        printf("Error al leer el archivo\n");
        return;
    }
}

void LiberarMemoria(Persona **personas, int *cant)
{
    free(*personas);
    *personas = NULL;
    *cant = 0;
    printf("La memoria se ha liberado con exito\n");
    printf("Puede ingresar nuevas personas si lo desea\n");
}
/*Desarrolle un programa que permita gestionar los datos de estudiantes de una escuela.
Para ello debes definir una estructura llamada Estudiante que almacene la siguiente información:
número de identificación (entero), nombre (cadena de caracteres), notas (arreglo de decimales) y
promedio (flotante). Implemente las siguientes funciones: Que permita al usuario ingresar datos de
un estudiante y calcular su promedio. La función debe tomar como parámetros un puntero a una
estructura Estudiante y solicitar al usuario el nombre, el id y las notas. Luego, debe calcular y
almacenar el promedio en la estructura. Que tome como entrada un arreglo de estructuras Estudiante y
su tamaño, y que guarde estos datos en un archivo de texto llamado "estudiantes.txt". Cada linea del
archivo debe contener la información de un estudiante en el siguiente formato: "ID, Nombre, Nota 1,
Nota 2, Nota 3, Promedio". Que permita buscar y mostrar los datos de un estudiante en particular
según su id. La función debe tomar como parámetros el id a buscar y el arreglo de estructuras de
estudiantes. Si se encuentra el estudiante, muestra sus datos. Implementa una función principal
(main) que permita al usuario realizar las siguientes operaciones con un menú de opciones. Registrar
un nuevo estudiante y guardar sus datos en el archivo "estudiantes.txt". Buscar y mostrar los datos
de un estudiante por id. Salir.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    float nota1;
    float nota2;
    float nota3;
} Notas;

typedef struct
{
    int id;
    char nombre[25];
    Notas notas;
    float promedio;
} Estudiante;

void IngresarEstudiante(Estudiante **, int *);
void GuardarEstudiante(Estudiante *, int);
void BuscaryMostrar(Estudiante *, int);
void Salir(Estudiante **, int *, char *);
void Menu();

int main() { 
    Menu();
    return 0; }

void Menu()
{
    Estudiante *estudiantes = NULL;
    int cant = 0;
    char opcion = ' ';
    char volver = 's';

    do
    {
        printf("Ingrese la opcion que desee ejecutar\n");
        printf("a. Ingresar un nuevo estudiante\n");
        printf("b. Guardar estudiantes en un archivo\n");
        printf("c. Buscar y mostrar datos de un estudiante\n");
        printf("d. Salir\n");
        scanf(" %c", &opcion);

        switch (opcion)
        {
        case 'a':
        case 'A':
            IngresarEstudiante(&estudiantes, &cant);
            break;
        case 'b':
        case 'B':
            GuardarEstudiante(estudiantes, cant);
            break;
        case 'c':
        case 'C':
            BuscaryMostrar(estudiantes, cant);
            break;
        case 'd':
        case 'D':
            Salir(&estudiantes, &cant, &volver);
            break;
        default:
            printf("La opcion que ha seleccionado no es valida\n");
            break;
        }
        if(opcion != 'd' && opcion != 'D'){
        printf("Desea volver al menu\?: Si(s), No(n)\n");
        scanf(" %c", &volver);
        }

    } while (volver == 's' || volver == 'S');
}

void IngresarEstudiante(Estudiante **estudiantes, int *cant)
{
    char otro = 's';
    float sumanotas = 0;
    Estudiante *estudiantes2 = NULL;

    do
    {
    estudiantes2 = (Estudiante *)realloc(*estudiantes, (*cant + 1) * sizeof(Estudiante));
    if (estudiantes2 != NULL)
    {
        *estudiantes = estudiantes2;
            printf("Ingrese los datos del estudiante\n");
            printf("Numero de identificacion: ");
            scanf(" %d", &(*estudiantes + *cant)->id);
            printf("Nombre: ");
            getchar();
            fgets((*estudiantes + *cant)->nombre, 25, stdin);
            (*estudiantes + *cant)->nombre[strcspn((*estudiantes + *cant)->nombre, "\n")] = '\0';
            printf("Notas del estudiante:\n");
            scanf(" %f", &(*estudiantes + *cant)->notas.nota1);
            scanf(" %f", &(*estudiantes + *cant)->notas.nota2);
            scanf(" %f", &(*estudiantes + *cant)->notas.nota3);
            sumanotas = (*estudiantes + *cant)->notas.nota1 + (*estudiantes + *cant)->notas.nota2 +
                        (*estudiantes + *cant)->notas.nota3;
            (*estudiantes + *cant)->promedio = sumanotas / 3;
            printf("\nDesea ingresar otro estudiante\?: Si(s), No(n)\n");
            scanf(" %c", &otro);
            (*cant)++;

        }
            else
            {
                printf("\nNo se pudo ingresar el estudiante\n");
                return;
            }
        } while (otro == 's' || otro == 'S');
}

void GuardarEstudiante(Estudiante *estudiantes, int cant)
{
    FILE *archivo;
    archivo = fopen("estudiantes.txt", "w");
    if (archivo != NULL)
    {
        printf("\nGuardando estudiantes...\n");
        printf("-------------------------------\n");
        for (int i = 0; i < cant; i++)
        {
            fprintf(archivo, "%d %s %.2f %.2f %.2f %.2f\n", (estudiantes + i)->id,
                    (estudiantes + i)->nombre, (estudiantes + i)->notas.nota1,
                    (estudiantes + i)->notas.nota2, (estudiantes + i)->notas.nota3,
                    (estudiantes + i)->promedio);
        }
        fclose(archivo);
        printf("Los estudiantes se han almacenado con exito\n");
    }
    else
    {
        printf("\nNo se han podido almacenar los estudiantes\n");
        return;
    }
}

void BuscaryMostrar(Estudiante *estudiantes, int cant)
{
    int busqueda = 0;
    int bandera = 0;

    printf("Ingrese el id del estudiante que desee buscar: ");
    scanf(" %d", &busqueda);
    for (int i = 0; i < cant; i++)
    {
        if (busqueda == (estudiantes + i)->id)
        {
            printf("El estudiante con id %d es:\n", busqueda);
            printf("%-25s | %-6s | %-6s | %-6s | %-8s\n", "Nombre", "Nota 1", "Nota 2", "Nota 3",
                   "Promedio");
            printf("%-25s | %-6.2f | %-6.2f | %-6.2f | %-8.2f\n", (estudiantes + i)->nombre,
                   (estudiantes + i)->notas.nota1, (estudiantes + i)->notas.nota2,
                   (estudiantes + i)->notas.nota3, (estudiantes + i)->promedio);
            bandera = 1;
        }
    }
    if (bandera == 0)
    {
        printf("No se ha encontrado el estudiante con id %d\n", busqueda);
    }
    bandera = 0;
}

void Salir(Estudiante **estudiantes, int *cant, char *volver)
{
    free(*estudiantes);
    *estudiantes = NULL;
    *cant = 0;
    *volver = 'n';
}
/*Crear una estructura llamada alumno con sus atributos persona (del anterior), y un arreglo de una
dimensión con las materias que cursa y otro arreglo de una dimensión con las notas de los finales.
(Ej. historial académico). Cargue con datos y luego muestre los datos.
*/

#include <stdio.h>
#include <string.h>
#define MAX 2
#define MATERIAS 2

struct Nacimiento
{
    int dia;
    int mes;
    int anio;
};

struct Direccion
{
    char calle[30];
    char provincia[20];
    int numero;
};

struct Alumno
{
    char nombre[20];
    char apellido[20];
    struct Nacimiento nacimiento;
    struct Direccion direccion;
};
struct Materia
{
    char nombre[20];
    int nota;
};
struct Historial
{
    struct Materia materias[MATERIAS];
    struct Alumno alumno;
};

void CargarHistorial(struct Historial[]);
void MostrarHistorial(struct Historial[]);

int main()
{
    struct Historial historial[MAX];
    CargarHistorial(historial);
    MostrarHistorial(historial);
    return 0;
}

void CargarHistorial(struct Historial historial[MAX])
{
    char bandera = 's';
    printf("Ingrese los alumnos que desee:\n");
    for (int i = 0; i < MAX; i++)
    {
        if (bandera == 's' || bandera == 'S')
        {
            printf("Ingrese nombre del alumno: ");
            fgets(historial[i].alumno.nombre, 20, stdin);
            historial[i].alumno.nombre[strcspn(historial[i].alumno.nombre, "\n")] = '\0';
            printf("\nIngrese apellido del alumno: ");
            fgets(historial[i].alumno.apellido, 20, stdin);
            historial[i].alumno.apellido[strcspn(historial[i].alumno.apellido, "\n")] = '\0';
            printf("\n\nDireccion alumno:\n");
            printf("Calle: ");
            fgets(historial[i].alumno.direccion.calle, 30, stdin);
            historial[i].alumno.direccion.calle[strcspn(historial[i].alumno.direccion.calle, "\n")] = '\0';
            printf("\nProvincia: ");
            fgets(historial[i].alumno.direccion.provincia, 20, stdin);
            historial[i].alumno.direccion.provincia[strcspn(
            historial[i].alumno.direccion.provincia, "\n")] = '\0';
            printf("\nNumero: ");
            scanf(" %d", &historial[i].alumno.direccion.numero);
            printf("\n\nFecha de nacimiento alumno:\n");
            printf("Dia: ");
            scanf(" %d", &historial[i].alumno.nacimiento.dia);
            printf("\nMes: ");
            scanf(" %d", &historial[i].alumno.nacimiento.mes);
            printf("\nAnio: ");
            scanf(" %d", &historial[i].alumno.nacimiento.anio);
            printf("\n\nMaterias:\n");
            for (int j = 0; j < MATERIAS; j++)
            {
                printf("Nombre materia: ");
                getchar();
                fgets(historial[i].materias[j].nombre, 20, stdin);
                historial[i].materias[j].nombre[strcspn(historial[i].materias[j].nombre, "\n")] = '\0';
                printf("\nCalificacion obtenida: ");
                scanf(" %d", &historial[i].materias[j].nota);
            }
            printf("\n");
            if (i < MAX - 1)
            {
                printf("\nDesea ingresar otro alumno\?: Si(s), No(n)\n");
                scanf(" %c", &bandera);
                getchar();
            }
        }
    }
}

void MostrarHistorial(struct Historial historial[MAX])
{
    printf("Los alumnos ingresados son:\n");
    printf("%-20s | %-20s | %-30s | %-20s | %-6s | %-20s | %-4s | %-4s | %-20s | %s\n", "Nombre",
           "Apellido", "Direccion: Calle", "Provincia", "Numero", "Nacimiento: Dia", "Mes", "Anio",
           "Materia", "Nota");
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MATERIAS; j++)
        {
            printf("%-20s | %-20s | %-30s | %-20s | %-6d | %-20d | %-4d | %-4d | %-20s | %d\n",
                   historial[i].alumno.nombre, 
                   historial[i].alumno.apellido,
                   historial[i].alumno.direccion.calle,
                   historial[i].alumno.direccion.provincia,
                   historial[i].alumno.direccion.numero, 
                   historial[i].alumno.nacimiento.dia,
                   historial[i].alumno.nacimiento.mes, 
                   historial[i].alumno.nacimiento.anio,
                   historial[i].materias[j].nombre, 
                   historial[i].materias[j].nota);
        }
    }
}

/*Desarrolle un programa que permita gestionar los datos de pacientes en un hospital.
Para ello, defina una estructura llamada PacienteHospital que almacene la siguiente información:
número de paciente (entero), nombre (cadena de caracteres), diagnóstico (cadena de caracteres) y
fecha de consulta(cadena de caracteres). Luego, implemente las siguientes funciones:
Que permita registrar un nuevo paciente (debe agregar un paciente nuevo a la lista)
Que permita leer un archivo "paciente.txt".
Que permita buscar todas las consultas que realizó un paciente.
Genere un menú de opciones con las distintas opciones que puede realizar el usuario.
Recuerde presentar la información de manera ordenada y entendible.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int dia;
    int mes;
    int anio;
} FechaConsulta;

typedef struct
{
    int nropaciente;
    char nombre[25];
    char diagnostico[30];
    FechaConsulta fechaconsulta;
} PacienteHospital;

void RegistrarPaciente(PacienteHospital **, int *);
void GuardarPacientes(PacienteHospital *, int);
void LeerArchivo(int);
void BuscarConsultas(PacienteHospital *, int);
void Salir(PacienteHospital **, int *, char *);
void Menu();

int main()
{
    Menu();
    return 0;
}

void Menu()
{
    PacienteHospital *pacientes = NULL;
    int cant = 0;
    char volver = 's';
    char opcion = ' ';

    do
    {
        printf("Ingrese la opcion que desee ejecutar\n");
        printf("a. Registrar un nuevo paciente\n");
        printf("b. Leer un archivo con los datos de los pacientes\n");
        printf("c. Buscar consultas por nombre de paciente\n");
        printf("d. Salir\n");
        scanf(" %c", &opcion);

        switch (opcion)
        {
        case 'a':
        case 'A':
            RegistrarPaciente(&pacientes, &cant);
            break;
        case 'b':
        case 'B':
            LeerArchivo(cant);
            break;
        case 'c':
        case 'C':
            BuscarConsultas(pacientes, cant);
            break;
        case 'd':
        case 'D':
            Salir(&pacientes, &cant, &volver);
            break;
        defaut:
            printf("No ha introducido una opcion valida\n");
            break;
        }
        if (opcion != 'd' && opcion != 'D')
        {
            printf("Desea volver al menu\?: Si(s), No(n)\n");
            scanf(" %c", &volver);
        }
    } while (volver == 's' || volver == 'S');
    free(pacientes);
    pacientes = NULL;
}

void RegistrarPaciente(PacienteHospital **pacientes, int *cant)
{
    PacienteHospital *pacientes2 = NULL;
    char otro = 's';

    do
    {
        pacientes2 =
            (PacienteHospital *)realloc(*pacientes, (*cant + 1) * sizeof(PacienteHospital));
        if (pacientes2 != NULL)
        {
            *pacientes = pacientes2;
            printf("Ingrese los datos del nuevo paciente\n");
            printf("Numero paciente: ");
            scanf(" %d", &(*pacientes + *cant)->nropaciente);
            printf("Nombre: ");
            getchar();
            fgets((*pacientes + *cant)->nombre, 25, stdin);
            (*pacientes + *cant)->nombre[strcspn((*pacientes + *cant)->nombre, "\n")] = '\0';
            printf("Diagnostico: ");
            fgets((*pacientes + *cant)->diagnostico, 30, stdin);
            (*pacientes + *cant)->diagnostico[strcspn((*pacientes + *cant)->diagnostico, "\n")] =
                '\0';
            printf("Fecha\n");
            printf("Dia: ");
            scanf(" %d", &(*pacientes + *cant)->fechaconsulta.dia);
            printf("Mes: ");
            scanf(" %d", &(*pacientes + *cant)->fechaconsulta.mes);
            printf("Anio: ");
            scanf(" %d", &(*pacientes + *cant)->fechaconsulta.anio);
            printf("\nDesea ingresar otro paciente\?: Si(s), No(n)\n");
            scanf(" %c", &otro);
            (*cant)++;
            getchar();
            GuardarPacientes(*pacientes, *cant);
            printf("%d\n", *cant);
        }
        else
        {
            printf("No se pudo reservar la memoria\n");
            return;
        }
    } while (otro == 's' || otro == 'S');
}

void GuardarPacientes(PacienteHospital *pacientes, int cant){
    FILE *archivo;
    archivo = fopen("paciente.txt", "w");
    if (archivo != NULL)
    {
        printf("Guardando datos...\n");
        printf("--------------------------\n");
        for (int i = 0; i < cant; i++)
        {
            fprintf(archivo, "%d %s %s %d %d %d\n", (pacientes + i)->nropaciente,
                    (pacientes + i)->nombre, (pacientes + i)->diagnostico,
                    (pacientes + i)->fechaconsulta.dia, (pacientes + i)->fechaconsulta.mes,
                    (pacientes + i)->fechaconsulta.anio);
        }
        fclose(archivo);
        printf("Datos guardados con exito\n");
        printf("--------------------------\n");
    }
    else
    {
        printf("Error al abrir el archivo\n");
        return;
    }
}

void LeerArchivo(int cant)
{
    printf("%d\n", cant);
    FILE *archivo;
    archivo = fopen("paciente.txt", "r");
    if (archivo != NULL)
    {
        printf("Leyendo datos...\n");
        PacienteHospital *lectura = NULL;
        lectura = (PacienteHospital *)malloc(cant * sizeof(PacienteHospital));
        if (lectura != NULL)
        {
            for (int i = 0; i < cant; i++)
            {
                fscanf(archivo, "%d %s %s %d %d %d\n", &(lectura + i)->nropaciente,
                       (lectura + i)->nombre, (lectura + i)->diagnostico,
                       &(lectura + i)->fechaconsulta.dia, &(lectura + i)->fechaconsulta.mes,
                       &(lectura + i)->fechaconsulta.anio);
            }
            fclose(archivo);
            printf("Los datos leidos son:\n");
            printf("---------------------------\n");
            printf("%-8s %-6s %-30s %-4s %-4s %-4s\n", "Paciente", "Nombre", "Diagnostico", "Dia",
                   "Mes", "Anio");
            for (int i = 0; i < cant; i++)
            {
                printf("%-8d %-6s %-30s %-4d %-4d %-4d\n", (lectura + i)->nropaciente,
                       (lectura + i)->nombre, (lectura + i)->diagnostico,
                       (lectura + i)->fechaconsulta.dia, (lectura + i)->fechaconsulta.mes,
                       (lectura + i)->fechaconsulta.anio);
            }
            free(lectura);
            lectura = NULL;
        }
        else
        {
            printf("No se ha podido leer el archivo\n");
        }
    }
    else
    {
        printf("No se ha podido ingresar al archivo\n");
        return;
    }
}

void BuscarConsultas(PacienteHospital *pacientes, int cant)
{
    char paciente[25];
    int bandera = 0;
    char otro = 's';

    do
    {
        printf("Ingrese el nombre del paciente que hizo las consultas: ");
        getchar();
        fgets(paciente, 25, stdin);
        paciente[strcspn(paciente, "\n")] = '\0';
        for (int i = 0; i < cant; i++)
        {
            if (strcmp(paciente, (pacientes + i)->nombre) == 0)
            {
                printf("\nEl paciente realizo las consultas:\n");
                printf("%-30s | %-4s | %-4s | %s\n", "Diagnostico", "Dia", "Mes", "Anio");
                printf("%-30s | %-4d | %-4d | %d\n", (pacientes + i)->diagnostico,
                       (pacientes + i)->fechaconsulta.dia, (pacientes + i)->fechaconsulta.mes,
                       (pacientes + i)->fechaconsulta.anio);
                bandera = 1;
                otro = 'n';
            }
        }
        if (bandera == 0)
        {
            printf("No se encontro ninguna consulta al nombre %s\n", paciente);
            printf("Desea intentar otro nombre\?: Si(s), No(n)\n");
            scanf(" %c", &otro);
        }
        bandera = 0;
    } while (otro == 's' || otro == 'S');
}

void Salir(PacienteHospital **pacientes, int *cant, char *volver)
{
    free(*pacientes);
    *pacientes = NULL;
    *cant = 0;
    *volver = 'n';
}
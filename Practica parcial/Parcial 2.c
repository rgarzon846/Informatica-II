/*Cada nodo del TDA deberá contener una estructura Alumno con los siguientes campos:

nombre (cadena de caracteres)
carrera (cadena de caracteres)
promedio (número decimal)
El programa debe llamar a las siguientes funciones:

Permitir insertar un nuevo alumno en el TDA.
Permitir eliminar un alumno del TDA según corresponda al tipo de estructura implementada.
Mostrar todos los alumnos almacenados, indicando nombre, carrera y promedio.
Calcular y mostrar el promedio general de los alumnos con promedio mayor o igual a 8 (función con retorno de valor).
Determinar y mostrar el alumno con el promedio más alto y el alumno con el promedio más bajo.
Crear un menu de opciones que se repita hasta que el usuario indique lo contrario.

Crear funciones auxiliares para si el TDA está vacía, liberar memoria y las que sean necesarias para lograr un algoritmo modular.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nombre[25];
    char carrera[25];
    float promedio;
}Alumno;

typedef struct Nodo{
    Alumno alumnos;
    struct Nodo *sig;
}Nodo;

void Menu();
void AgregarAlumno(Nodo **, Nodo **);
void EliminarAlumno(Nodo **, Nodo **);
void ImprimirAlumnos(Nodo *);
float PromedioGeneral(Nodo *);
void MayorMenor(Nodo *);
void Liberar(Nodo **);

int main(){
    Menu();
    return 0;
}

void Menu(){
    Nodo *frente = NULL;
    Nodo *fin = NULL;
    char opcion = ' ';

    do{
        printf("\n********Menu********\n");
        printf("a) Agregar un alumno a la cola\n");
        printf("b) Eliminar el primer alumno ingresado\n");
        printf("c) Imprimir la cola de alumnos\n");
        printf("d) Mostrar el promedio general de alumnos con nota mayor o igual a 8\n");
        printf("e) Mostrar el alumno con mayor promedio y el alumno con menor promedio\n");
        printf("f) Salir del menu\n");
        scanf(" %c", &opcion);

        switch(opcion){
            case 'a':
            case 'A': char otro = 's';
            while(otro == 's' || otro == 'S'){
                AgregarAlumno(&frente, &fin);
                printf("\nDesea ingresar otro alumno\?: Si(s), No(n)\n");
                scanf(" %c", &otro);
            }
            break;
            case 'b':
            case 'B': if(frente != NULL){
                EliminarAlumno(&frente, &fin);
            }else{
                printf("\nDebe ingresar alumnos\n");
            }
            break;
            case 'c':
            case 'C': if(frente != NULL){
                ImprimirAlumnos(frente);
            }else{
                printf("\nDebe ingresar alumnos\n");
            }
            break;
            case 'd':
            case 'D': if(frente != NULL){
                printf("\nEl promedio general es: %.2f\n", PromedioGeneral(frente));
            }else{
                printf("\nDebe ingresar alumnos\n");
            }
            break;
            case 'e':
            case 'E': if(frente != NULL){
               MayorMenor(frente);
            }else{
                printf("\nDebe ingresar alumnos\n");
            }
            break;
            case 'f':
            case 'F': if(frente != NULL){
                Liberar(&frente);
            }else{
                printf("\nSaliendo del menu, nada para liberar\n");
            }
            break;
            default: printf("\nNo se ha introducido una opcion valida\n");
        }
    }while(opcion != 'f' && opcion != 'F');
}

void AgregarAlumno(Nodo **frente, Nodo **fin){
    Nodo *nuevo = (Nodo *) malloc(sizeof(Nodo));

    if(nuevo != NULL){
        printf("\nIngrese los siguientes datos del alumno:\n");
        nuevo->sig = NULL;
        getchar();
        printf("Nombre: ");
        fgets(nuevo->alumnos.nombre, 25, stdin);
        nuevo->alumnos.nombre[strcspn(nuevo->alumnos.nombre, "\n")] = '\0';
        printf("Carrera: ");
        fgets(nuevo->alumnos.carrera, 25, stdin);
        nuevo->alumnos.carrera[strcspn(nuevo->alumnos.carrera, "\n")] = '\0';
        printf("Promedio: ");
        scanf(" %f", &nuevo->alumnos.promedio);

        if(*fin == NULL){
            *frente = nuevo;
            *fin = nuevo;
        }else{
            (*fin)->sig = nuevo;
            *fin = nuevo;
        }
    }else{
        printf("\nNo se ha podido añadir el alumno\n");
    }
}

void EliminarAlumno(Nodo **frente, Nodo **fin){
    Nodo *aux = *frente;
    Alumno alumno = aux->alumnos;
    free(*frente);
    *frente = aux->sig;
    if(*frente == NULL){
        *fin = NULL;
    }
    printf("\nSe ha eliminado al alumno:\n");
    printf("%-25s | %-25s | %s\n", "Nombre", "Carrera", "Promedio");
    printf("%-25s | %-25s | %.2f\n", alumno.nombre, alumno.carrera, alumno.promedio);
}

void ImprimirAlumnos(Nodo *frente){
    Nodo *aux = frente;
    printf("\nLos alumnos de la cola son:\n");
    printf("%-25s | %-25s | %s\n", "Nombre", "Carrera", "Promedio");
    while(aux != NULL){
    printf("%-25s | %-25s | %.2f\n", aux->alumnos.nombre, aux->alumnos.carrera, aux->alumnos.promedio);
    aux = aux->sig;
    }
}

float PromedioGeneral(Nodo *frente){
    Nodo *aux = frente;
    float promgeneral = 0;
    int contador = 0;
    while(aux != NULL){
        if(aux->alumnos.promedio >= 8.00){
            promgeneral += aux->alumnos.promedio;
            contador++;
        }
        aux = aux->sig;
    }
    return promgeneral/contador;
}

void MayorMenor(Nodo *frente){
    float mayor = 0;
    Alumno Mayor;
    Alumno Menor;
    Nodo *aux = frente;
    float menor = aux->alumnos.promedio;

    while(aux != NULL){
        if(aux->alumnos.promedio > mayor){
            mayor = aux->alumnos.promedio;
            Mayor = aux->alumnos;
        }
        if(aux->alumnos.promedio < menor){
            menor = aux->alumnos.promedio;
            Menor = aux->alumnos;
        }
        aux = aux->sig;
    }

    printf("\nEl alumno con el promedio mas alto es:\n");
    printf("%-25s | %-25s | %s\n", "Nombre", "Carrera", "Promedio");
    printf("%-25s | %-25s | %.2f\n", Mayor.nombre, Mayor.carrera, Mayor.promedio);
     printf("\nEl alumno con el promedio mas bajo es:\n");
    printf("%-25s | %-25s | %s\n", "Nombre", "Carrera", "Promedio");
    printf("%-25s | %-25s | %.2f\n", Menor.nombre, Menor.carrera, Menor.promedio);
}

void Liberar(Nodo **frente){
    while(*frente != NULL){
        Nodo *prox = (*frente)->sig;
        free(*frente);
        *frente = prox;
    }
    printf("\nSe ha liberado la cola con exito\n");
}


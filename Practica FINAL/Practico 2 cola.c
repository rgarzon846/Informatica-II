/*Implementa un programa que gestione los datos de un proyecto de construcción utilizando un TDA. 
El TDA debe almacenar información sobre las diferentes tareas del proyecto, incluyendo nombre de la tarea, 
duración estimada (entero) y estado de la tarea (pendiente/terminada/retrasada). Desarrolla las siguientes funciones para:

Agregar una nueva tarea al proyecto.
Mostrar la lista de tareas por consola y generar un archivo txt llamado "proyecto.txt".
Eliminar una tarea del proyecto.
Calcular el porcentaje de avance del proyecto.
Ordenar las tareas por duración estimada usando quicksort.
Crea un menú de opciones para que el usuario pueda realizar diferentes acciones.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nombre[25];
    int duracion;
    char estado[15];
}Proyecto;

typedef struct Cola{
    Proyecto proyecto;
    struct Cola *sig;
}Cola;

void AgregarProyecto(Cola **, Cola **);
void ImprimirProyectos(Cola *);
void EliminarProyecto(Cola **, Cola **);
void CalcularAvance(Cola *);
void Menu();
void LiberarCola(Cola **, Cola **);
int ColaVacia(Cola *);

int main(){
    Menu();
    return 0;
}

void Menu(){
    Cola *frente = NULL;
    Cola *fin = NULL;
    int opcion = 0;

    do{
        printf("\n********MENU********\n");
        printf("\nIngrese la opcion que desee ejecutar\n");
        printf("1) Registrar nuevo proyecto\n");
        printf("2) Imprimir la lista de proyectos registrados, crear un archivo con los mismos\n");
        printf("3) Eliminar el primer proyecto registrado\n");
        printf("4) Mostrar el avance de cada proyecto\n");
        printf("5) Salir\n");
        scanf(" %d", &opcion);

        switch(opcion){

            case 1: char otro = 's';
            while(otro == 's' || otro == 'S'){
                AgregarProyecto(&frente, &fin);
                printf("\nDesea registrar otro proyecto\?: Si(s), No(n)\n");
                scanf(" %c", &otro);
            }
            break;
            case 2: if(ColaVacia(frente)){
                ImprimirProyectos(frente);
            }else{
                printf("\nAun no se ha registrado ningun proyecto\n");
            }
            break;
            case 3: if(ColaVacia(frente)){
                EliminarProyecto(&frente, &fin);
            }else{
                printf("\nAun no se ha registrado ningun proyecto\n");
            }
            break;
            case 4: if(ColaVacia(frente)){
                CalcularAvance(frente);
            }else{
                printf("\nAun no se ha registrado ningun proyecto\n");
            }
            break;
            case 5: if(ColaVacia(frente)){
                LiberarCola(&frente, &fin);
            }else{
                printf("\nSaliendo... No hay proyectos registrados\n");
            }
            break;
            default: printf("\nNo se ha elegido una opcion valida\n");
            break;
        }
    }while(opcion != 5);
}

void AgregarProyecto(Cola **frente, Cola **fin){
    Cola *nuevo = (void *) malloc(sizeof(Cola));
    if(nuevo != NULL){
        int bandera = 0;
        printf("\nPorfavor ingrese la informacion solicitada del proyecto a registrar\n");
        printf("Nombre de la tarea: ");
        getchar();
        fgets(nuevo->proyecto.nombre, 25, stdin);
        nuevo->proyecto.nombre[strcspn(nuevo->proyecto.nombre, "\n")] = '\0';
        printf("Duracion estimada (en dias): ");
        scanf(" %d", &nuevo->proyecto.duracion);
        do{
        printf("Estado:\n");
        printf("1) Pendiente\n");
        printf("2) Terminada\n");
        printf("3) Restrasada\n");
        scanf(" %d", &bandera);
        switch(bandera){
            case 1: strcpy(nuevo->proyecto.estado, "Pendiente");
            break;
            case 2: strcpy(nuevo->proyecto.estado, "Terminada");
            break;
            case 3: strcpy(nuevo->proyecto.estado, "Retrasada");
            break;
            default: printf("\nNo ha seleccionado una opcion valida\n");
            break;
        }
        }while(bandera > 3 || bandera < 1);

        nuevo->sig = NULL;
        if(*fin == NULL){
            *frente = nuevo;
            *fin = nuevo;
        }else{
            (*fin)->sig = nuevo;
            *fin = nuevo;
        }
        printf("\nProyecto registrado con exito\n");
    }else{
        printf("\nError al crear nuevo proyecto\n");
        return;
    }
}

void ImprimirProyectos(Cola *frente){
    Cola *aux = frente;
    FILE *archivo = fopen("proyecto.txt", "w");
    if(archivo != NULL){
    fprintf(archivo, "%-25s | %-12s | %s\n", "Nombre", "Estado", "Duracion");
    while(aux != NULL){
        fprintf(archivo, "%-25s | %-12s | %d\n", aux->proyecto.nombre, aux->proyecto.estado, aux->proyecto.duracion);
        aux = aux->sig;
    }
    fclose(archivo);
    printf("\nEl archivo con los proyectos registrados se ha actualizado con exito\n");
    }else{
        printf("\nNo se ha podido abrir el archivo\n");
        return;
    }

    aux = frente;

    printf("\nLos proyectos registrados hasta el momento son:\n");
    printf("%-25s | %-12s | %s\n", "Nombre", "Estado", "Duracion");
    while(aux != NULL){
        printf("%-25s | %-12s | %d\n", aux->proyecto.nombre, aux->proyecto.estado, aux->proyecto.duracion);
        aux = aux->sig;
    } 
}

void EliminarProyecto(Cola **frente, Cola **fin){
    Proyecto proyecto = (*frente)->proyecto;
    Cola *aux = *frente;
    *(frente) = aux->sig;
    if(*frente == NULL){
        *fin == NULL;
    }
    free(aux);
    printf("\nEl proyecto eliminado ha sido el proyecto:\n");
    printf("%-25s | %-12s | %s\n", "Nombre", "Estado", "Duracion");
    printf("%-25s | %-12s | %d\n", proyecto.nombre, proyecto.estado, proyecto.duracion);
}

void CalcularAvance(Cola *frente){
    Cola *aux = frente;
    int avance = 0;

    printf("\nLos procentajes de avance son:\n");
    printf("\n%-25s | %-12s | %s\n", "Nombre", "Avance %%", "Duracion");
    while(aux != NULL){
        if(strcmp(aux->proyecto.estado, "Pendiente" ) == 0){
            avance = 0;
            printf("%-25s | %-12d%% | %d\n", aux->proyecto.nombre, avance, aux->proyecto.duracion);
        }else if(strcmp(aux->proyecto.estado, "Terminada") == 0){
            avance = 100;
            printf("%-25s | %-12d%% | %d\n", aux->proyecto.nombre, avance, aux->proyecto.duracion);
        }else if(strcmp(aux->proyecto.estado, "Retrasada") == 0){
            avance = 40;
            printf("%-25s | %-12d%% | %d\n", aux->proyecto.nombre, avance, aux->proyecto.duracion);
        }
        aux = aux->sig;
    }
}

void LiberarCola(Cola **frente, Cola **fin){
    while(*frente != NULL){
        Cola *prox = (*frente)->sig;
        free(*frente);
        *frente = prox;
    }
    *fin == NULL;
    printf("\nSe ha liberado la cola con exito\n");
}

int ColaVacia(Cola *frente){
    if(frente == NULL){
        return 0;
    }else{
        return 1;
    }
}
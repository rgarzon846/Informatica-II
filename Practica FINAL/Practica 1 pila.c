/*Desarrolla un programa para gestionar los datos de un restaurante mediante un
TDA. El TDA debe contener la información de los platos disponibles, incluyendo
nombre del plato, cantidad de platos disponibles (entero), cantidad de platos
vendidos (entero) y precio (decimal). Implementa las siguientes funciones para:

Insertar un nuevo plato en el menú.
Mostrar el menú por consola y generar un archivo txt llamado "menu.txt".
Eliminar un plato del menú.
Calcular la recaudación total de los platos vendidos.
Ordenar los platos por precio usando quicksort.(recursividad)
Además, crea un menú de opciones para que el usuario pueda interactuar con el
programa.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nombre[25];
    int disponibles;
    int vendidos;
    float precio;
}Plato;

typedef struct Platos{
    Plato plato;
    struct Platos *sig;
}Platos;

void Menu();
void InsertarPlato(Platos **);
void ImprimirMenu(Platos *);
void EliminarPlato(Platos **);
float CalcularRecaudado(Platos *);
void LiberarPila(Platos **);
int PilaVacia(Platos *);

int main(){
    Menu();    
    return 0;
}

void Menu(){
    Platos *platos = NULL;
    char opcion = ' ';

    do{
        printf("\n*******MENU DE OPCIONES*******\n");
        printf("a) Ingresar un nuevo plato\n");
        printf("b) Imprimir el menu de platillos y crear un archivo con el mismo\n");
        printf("c) Eliminar el ultimo plato ingresado al menu\n");
        printf("d) Calcular el dinero total recaudado mediante las ventas\n");
        printf("e) Salir\n");
        scanf(" %c", &opcion);

        switch(opcion){
            case 'a':
            case 'A': char otro = 's';
            while(otro == 's' || otro == 'S'){
                InsertarPlato(&platos);
                printf("\nDesea ingresar otro plato al menu\?: Si(s), No(n)\n");
                scanf(" %c", &otro);
            }
            break;
            case 'b':
            case 'B': if(PilaVacia(platos)){
                ImprimirMenu(platos);
            }else{
                printf("\nEl menu de platillos disponibles esta vacio\n");
            }
            break;
            case 'c':
            case 'C': if(PilaVacia(platos)){
                EliminarPlato(&platos);
            }else{
                printf("\nEl menu de platillos disponibles esta vacio\n");
            }
            break;
            case 'd':
            case 'D': if(PilaVacia(platos)){
                printf("\nEl total de dinero recaudado es de: %.2f\n", CalcularRecaudado(platos));
            }else{
                printf("\nEl menu de platillos disponibles esta vacio\n");
            }
            break;
            case 'e':
            case 'E': if(PilaVacia(platos)){
                LiberarPila(&platos);
            }else{
                printf("\nSaliendo... Menu vacio\n");
            }
            break;
            default: printf("\nLa opcion ingresada no es valida\n");
            break;
        }
    }while(opcion != 'e' && opcion != 'E');
}

void InsertarPlato(Platos **platos){
    Platos *nuevo = (Platos *) malloc(sizeof(Platos));
    if(nuevo != NULL){
        printf("\nIngrese los siguientes datos del plato\n");
        getchar();
        printf("Nombre: ");
        fgets(nuevo->plato.nombre, 25, stdin);
        nuevo->plato.nombre[strcspn(nuevo->plato.nombre, "\n")] = '\0';
        printf("Cantidad vendidos: ");
        scanf(" %d", &nuevo->plato.vendidos);
        printf("Cantidad disponibles: ");
        scanf(" %d", &nuevo->plato.disponibles);
        printf("Precio: ");
        scanf(" %f", &nuevo->plato.precio);
        nuevo->sig = NULL;

        if(*platos == NULL){
            *platos = nuevo;
        }else{
            nuevo->sig = *platos;
            *platos = nuevo;
        }
    }else{
        printf("\nError al agregar platillo\n");
        return;
    }
    printf("\nPlatillo registrado con exito\n");
}

void ImprimirMenu(Platos *platos){
    Platos *aux = platos;
    FILE *archivo = fopen("menu.txt", "w");
    if(archivo == NULL){
        printf("\nError al crear el archivo de menu\n");
        return;
    }else{
    printf("\n***********MENU DE PLATOS DISPONIBLES***********\n");
    fprintf(archivo, "\n***********MENU DE PLATOS DISPONIBLES***********\n");
    printf("%-25s | %s\n", "Nombre", "Precio");
    fprintf(archivo, "%-25s | %s\n", "Nombre", "Precio");
    while(aux != NULL){
        printf("%-25s | %.2f\n", aux->plato.nombre, aux->plato.precio);
        fprintf(archivo, "%-25s | %.2f\n", aux->plato.nombre, aux->plato.precio);
        aux = aux->sig;
    }
    fclose(archivo);
    printf("\nEL archivo con el menu se ha actualizado con exito\n");
}
}

void EliminarPlato(Platos **platos){
    Plato plato = (*platos)->plato;
    Platos *aux = *platos;
    *platos = aux->sig;
    free(aux);
    printf("\nEl plato eliminado ha sido el plato:\n");
    printf("%-25s | %-15s | %-15s | %s\n", "Nombre", "Vendidos", "Disponibles", "Precio");
    printf("%-25s | %-15d | %-15d | %.2f\n", plato.nombre, plato.vendidos, plato.disponibles, plato.precio);
}

float CalcularRecaudado(Platos *platos){
    Platos *aux = platos;
    float suma = 0;
    float porplato = 0;
    while(aux != NULL){
        porplato = aux->plato.vendidos * aux->plato.precio;
        suma += porplato;
        aux = aux->sig;
    }
    return suma;
}

void LiberarPila(Platos **platos){
    while(*platos != NULL){
        Platos *prox = (*platos)->sig;
        free(*platos);
        *platos = prox;
    }
    printf("El menu se ha liberado con exito\n");
}

int PilaVacia(Platos *platos){
    if(platos == NULL){
        return 0;
    }else{
        return 1;
    }
}
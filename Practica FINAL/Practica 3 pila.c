/*Crea un programa para gestionar un inventario de automóviles utilizando un TDA. 
El TDA debe contener información sobre cada automóvil, incluyendo modelo, stock (entero), 
y precio (decimal). Desarrollar las siguientes funciones para:

Agregar un nuevo modelo de automóvil al inventario.
Mostrar el inventario por consola y generar un archivo txt llamado "inventario.txt".
Eliminar un modelo de automóvil del inventario.
Calcular el valor total del inventario.
Ordenar de manera por stock de menor a mayor los modelos disponibles en el inventario usando quicksort
Diseña un menú de opciones para que el usuario pueda interactuar con el programa.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct{
    char marca[25];
    char modelo[25];
    int stock;
    double precio;
}Automovil;

typedef struct Pila{
    Automovil automovil;
    struct Pila *sig;
}Pila;

void Menu();
void AgregarAutomovil(Pila **);
void ImprimirInventario(Pila *);
void EliminarAutomovil(Pila **);
double CalcularValorTotal(Pila *);
void Mayuscula(char [25]);
void LiberarPila(Pila **);
int PilaVacia(Pila *);

int main(){
    Menu();
    return 0;
}

void Menu(){
    Pila *pila = NULL;
    int opcion = 0;

    do{
        printf("\n*********MENU*********\n");
        printf("\nIngrese la opcion que desee ejecutar\n");
        printf("1) Agregar un automovil al inventario\n");
        printf("2) Imprimir el inventario registrado\n");
        printf("3) Eliminar el ultimo automovil agregado\n");
        printf("4) Calcular el total de dinero registrado\n");
        printf("5) Salir\n");
        scanf(" %d", &opcion);

        switch(opcion){
            case 1: char otra = 's';
            while(otra == 's' || otra == 'S'){
                AgregarAutomovil(&pila);
                printf("\nDesea agregar otro automovil al inventario\?: Si(S), No(N)\n");
                scanf(" %c", &otra);
            }
            break;
            case 2: if(PilaVacia(pila)){
                ImprimirInventario(pila);
            }else{
                printf("\nAun no hay automoviles registrados\n");
            }
            break;
            case 3: if(PilaVacia(pila)){
                EliminarAutomovil(&pila);
            }else{
                printf("\nAun no hay automoviles registrados\n");
            }
            break;
            case 4: if(PilaVacia(pila)){
                printf("\nEL dinero total registrado en el inventario es de: %.2f\n", CalcularValorTotal(pila));
            }else{
                printf("\nAun no hay automoviles registrados\n");
            }
            break;
            case 5: if(PilaVacia(pila)){
                LiberarPila(&pila);
            }else{
                printf("\nSaliendo... No hay automoviles registrados\n");
            }
            break;
            default: printf("\nNo se ha introducido una opcion valida\n");
            break;
        }
    }while(opcion != 5);
}

void AgregarAutomovil(Pila **pila){
    Pila *nuevo = (void *) malloc(sizeof(Pila));
    if(nuevo != NULL){
        printf("\nIngrese la informacion solicitada sobre el automovil\n");
        printf("Marca: ");
        getchar();
        fgets(nuevo->automovil.marca, 25, stdin);
        nuevo->automovil.marca[strcspn(nuevo->automovil.marca, "\n")] = '\0';
        Mayuscula(nuevo->automovil.marca);
        printf("Modelo: ");
        fgets(nuevo->automovil.modelo, 25, stdin);
        nuevo->automovil.modelo[strcspn(nuevo->automovil.modelo, "\n")] = '\0';
        Mayuscula(nuevo->automovil.modelo);
        printf("Stock: ");
        scanf(" %d", &nuevo->automovil.stock);
        printf("Precio: ");
        scanf(" %lf", &nuevo->automovil.precio);
        nuevo->sig = NULL;

        if(PilaVacia(*pila) == 0){
            *pila = nuevo;
        }else{
           nuevo->sig = *pila;
           *pila = nuevo;
        }
        printf("\nEl automovil se ha registrado con exito\n");
    }else{
        printf("\nError al registrar nuevo automovil\n");
    }
}

void ImprimirInventario(Pila *pila){
    Pila *aux = pila;

    printf("\n********INVENTARIO********\n");
    printf("\n%-25s | %-25s | %-10s | %s\n", "Marca", "Modelo", "Stock", "Precio");
    while(aux != NULL){
        printf("%-25s | %-25s | %-10d | %.2f\n", aux->automovil.marca, aux->automovil.modelo, aux->automovil.stock, aux->automovil.precio);
        aux = aux->sig;
    }

    aux = pila;

    FILE *archivo = fopen("inventario.txt", "w");
    if(archivo != NULL){
        fprintf(archivo, "\n%-25s | %-25s | %-10s | %s\n", "Marca", "Modelo", "Stock", "Precio");
        
        while(aux != NULL){
            fprintf(archivo, "%-25s | %-25s | %-10d | %.2f\n", aux->automovil.marca, aux->automovil.modelo, aux->automovil.stock, aux->automovil.precio);
            aux = aux->sig;
        }
        fclose(archivo);
        printf("\nEl archivo con el inventario ha sido actualizado con exito\n");
    }else{
        printf("\nNo se ha podido actualizar el archivo con el inventario\n");
    }
}

void EliminarAutomovil(Pila **pila){
    Pila *aux = *pila;
    Automovil automovil = (*pila)->automovil;
    *pila = aux->sig;
    free(aux);
    printf("\nEl automovil:\n");
    printf("\n%-25s | %-25s | %-10s | %s\n", "Marca", "Modelo", "Stock", "Precio");
    printf("%-25s | %-25s | %-10d | %.2f\n", automovil.marca, automovil.modelo, automovil.stock, automovil.precio);
    printf("\nse ha eliminado\n");
}

double CalcularValorTotal(Pila *pila){
    Pila *aux = pila;
    double suma = 0;
    double porauto = 0;

    while(aux != NULL){
        porauto = aux->automovil.precio * aux->automovil.stock;
        suma += porauto;
        aux = aux->sig;
    }
    return suma;
}

void Mayuscula(char cadena[25]){
    for(int i = 0; cadena[i] != '\0'; i++){
        cadena[i] = toupper(cadena[i]);
    }
}

void LiberarPila(Pila **pila){
    while(*pila != NULL){
        Pila *prox = (*pila)->sig;
        free(*pila);
        *pila = prox;
    }
    printf("\nLa pila se ha eliminado con exito\n");
}

int PilaVacia(Pila *pila){
    if(pila == NULL){
        return 0;
    }else{
        return 1;
    }
}

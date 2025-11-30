/*Desarrolla un programa que permita la gestión de propiedades en venta y/o 
en alquiler de una inmobiliaria utilizando el TDA cola. Para ello cree la/las 
estructura/s que necesite para almacenar la siguiente información sobre código 
de propiedad (entero), m2 de terreno (decimal), m2 cubiertos (decimal), 
tipo operación (En venta/En alquiler), precio (decimal), ubicación (cadena) y el estado actual de la propiedad (Desocupada/Ocupada)

Desarrolla las siguientes funciones para: 

Registrar una nueva propiedad. 
Mostrar un listado de todas las propiedades por consola y generar un archivo .txt llamado "propiedades.txt", ambos en formato tabla. 
Borrar una propiedad 
Mostrar un listado de propiedades por tipo de operación en formato tabla. 
Calcular la cantidad de propiedades ocupadas y desocupadas. 
Crea un menú de opciones para que el usuario pueda realizar diferentes acciones antes descritas. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int codigo;
    float terreno;
    float cubiertos;
    char operacion[15];
    char ubicacion[25];
    char estado[15];
    float precio;
}Propiedad;

typedef struct Pila{
    Propiedad propiedad;
    struct Pila *sig;
}Pila;

void RegistrarPropiedad(Pila **);
void ImprimirPropiedades(Pila *);
void BorrarPropiedad(Pila **);
void ImprimirTipos(Pila *);
void CalcularEstado(Pila *);
void Menu();
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
        printf("\n*********MENU DE OPCIONES*********\n");
        printf("1) Registrar una nueva propiedad\n");
        printf("2) Imprimir las propiedades registradas y un archivo de tecto con las mismas\n");
        printf("3) Eliminar la ultima propiedad ingresada\n");
        printf("4) Imprimir las propiedades registradas por tipo de operacion\n");
        printf("5) Calcular las propiedades ocupadas y las propiedades desocupadas\n");
        printf("6) Salir\n");
        scanf(" %d", &opcion);

        switch(opcion){
            case 1: char otra = 's';
            while(otra == 's' || otra == 'S'){
                RegistrarPropiedad(&pila);
                printf("\nDesea registrar otra propiedad\?: Si(S)/No(N)\n");
                scanf(" %c", &otra);
            }
            break;
            case 2: if(PilaVacia(pila)){
                ImprimirPropiedades(pila);
            }else{
                printf("\nAun no hay propiedades registradas\n");
            }
            break;
            case 3: if(PilaVacia(pila)){
                BorrarPropiedad(&pila);
            }else{
                printf("\nAun no hay propiedades registradas\n");
            }
            break;
            case 4: if(PilaVacia(pila)){
                ImprimirTipos(pila);
            }else{
                printf("\nAun no hay propiedades registradas\n");
            }
            break;
            case 5: if(PilaVacia(pila)){
                CalcularEstado(pila);
            }else{
                printf("\nAun no hay propiedades registradas\n");
            }
            break;
            case 6: if(PilaVacia(pila)){
                LiberarPila(&pila);
            }else{
                printf("\nSaliendo... Ninguna propiedad registrada\n");
            }
            break;
            default: printf("\nNo se ha seleccionado ninguna propiedad valida\n");
            break;
        }
    }while(opcion != 6);
}

void RegistrarPropiedad(Pila **pila){
    int tipo = 0;
    int estado = 0;
    Pila *nuevo = (void *) malloc(sizeof(Pila));
    if(nuevo != NULL){
        printf("\nIngrese la siguiente informacion solicitada sobre la propiedad:\n");
        printf("Codigo: ");
        scanf(" %d", &nuevo->propiedad.codigo);
        printf("m2 de terreno: ");
        scanf(" %f", &nuevo->propiedad.terreno);
        printf("m2 cubiertos: ");
        scanf(" %f", &nuevo->propiedad.cubiertos);
        do{
        printf("Tipo de operacion\n");
        printf("1) En Venta\n");
        printf("2) En Alquiler\n");
        scanf(" %d", &tipo);
        switch(tipo){
            case 1: strcpy(nuevo->propiedad.operacion, "En Venta");
            break;
            case 2: strcpy(nuevo->propiedad.operacion, "En Alquiler");
            break;
            default: printf("\nNo se ha ingresado una opcion valida\n");
            break;
        }
    }while(tipo < 1 || tipo > 2);
        printf("\nUbicacion: ");
        getchar();
        fgets(nuevo->propiedad.ubicacion, 25, stdin);
        nuevo->propiedad.ubicacion[strcspn(nuevo->propiedad.ubicacion, "\n")] = '\0';
        do{
        printf("Estado\n");
        printf("1) Desocupada\n");
        printf("2) Ocupada\n");
        scanf(" %d", &estado);
        switch(estado){
            case 1: strcpy(nuevo->propiedad.estado, "Desocupada");
            break;
            case 2: strcpy(nuevo->propiedad.estado, "Ocupada");
            break;
            default: printf("\nNo ha ingresado una opcion valida\n");
            break;
        }
    }while(estado < 1 || estado > 3);
        printf("Precio: ");
        scanf(" %f", &nuevo->propiedad.precio);
        
        if(*pila == NULL){
            *pila = nuevo;
        }else{
            nuevo->sig = *pila;
            *pila = nuevo;
        }

    printf("\nLa propiedad se ha registrado con exito\n"); 
    }else{
        printf("\nError al registrar nueva propiedad\n");
    }
}

void ImprimirPropiedades(Pila *pila){
    Pila *aux = pila;
    printf("\nLas propiedades que han sido registradas son:\n");
    printf("%-10s | %-15s | %-15s | %-15s | %-25s | %-15s | %s\n", "Codigo", "Terreno m2", "Cubiertos m2", "Operacion", "Ubicacion", "Estado", "Precio");
    while(aux != NULL){
        printf("%-10d | %-15.2f | %-15.2f | %-15s | %-25s | %-15s | %.2f\n", aux->propiedad.codigo, aux->propiedad.terreno, aux->propiedad.cubiertos, aux->propiedad.operacion, aux->propiedad.ubicacion, aux->propiedad.estado, aux->propiedad.precio);
        aux = aux->sig;
    }

    aux = pila;

    FILE *archivo = fopen("propiedades.txt", "w");
    if(archivo != NULL){
        fprintf(archivo, "%-10s | %-15s | %-15s | %-15s | %-25s | %-15s | %s\n", "Codigo", "Terreno m2", "Cubiertos m2", "Operacion", "Ubicacion", "Estado", "Precio");
        while(aux != NULL){
        fprintf(archivo, "%-10d | %-15.2f | %-15.2f | %-15s | %-25s | %-15s | %.2f\n", aux->propiedad.codigo, aux->propiedad.terreno, aux->propiedad.cubiertos, aux->propiedad.operacion, aux->propiedad.ubicacion, aux->propiedad.estado, aux->propiedad.precio);
        aux = aux->sig;
    }
    fclose(archivo);
    printf("\nEl archivo con las propiedades registradas se ha actualizado con exito\n");
    }else{
        printf("\nNo se ha podido crear el archivo\n");
    }
}

void BorrarPropiedad(Pila **pila){
    Propiedad propiedad = (*pila)->propiedad;
    Pila *aux = *pila;
    *pila = aux->sig;
    free(aux);
    printf("\nSe ha eliminado la propiedad:\n");
    printf("%-10s | %-15s | %-15s | %-15s | %-25s | %-15s | %s\n", "Codigo", "Terreno m2", "Cubiertos m2", "Operacion", "Ubicacion", "Estado", "Precio");
    printf("%-10d | %-15.2f | %-15.2f | %-15s | %-25s | %-15s | %.2f\n", propiedad.codigo, propiedad.terreno, propiedad.cubiertos, propiedad.operacion, propiedad.ubicacion, propiedad.estado, propiedad.precio);
}

void ImprimirTipos(Pila *pila){
    Pila *aux = pila;
    int tipo = 0;
    int bandera = 0;
    printf("\nElija el tipo de operacion por el cual se mostraran las propiedades:\n");
    printf("1) En Venta\n");
    printf("2) En Alquiler\n");
    scanf(" %d", &tipo);

    switch(tipo){
        case 1: 
        printf("%-10s | %-15s | %-15s | %-15s | %-25s | %-15s | %s\n", "Codigo", "Terreno m2", "Cubiertos m2", "Operacion", "Ubicacion", "Estado", "Precio");
        while(aux != NULL){
            if(strcmp(aux->propiedad.operacion, "En Venta") == 0){
                printf("%-10d | %-15.2f | %-15.2f | %-15s | %-25s | %-15s | %.2f\n", aux->propiedad.codigo, aux->propiedad.terreno, aux->propiedad.cubiertos, aux->propiedad.operacion, aux->propiedad.ubicacion, aux->propiedad.estado, aux->propiedad.precio);
                bandera = 1;
            }
            aux = aux->sig;
        }
        if(bandera == 0){
            printf("\nNo se ha registrado ninguna propiedad en venta\n");
        }
        bandera = 0;
        break;
        case 2: 
        printf("%-10s | %-15s | %-15s | %-15s | %-25s | %-15s | %s\n", "Codigo", "Terreno m2", "Cubiertos m2", "Operacion", "Ubicacion", "Estado", "Precio");
        while(aux != NULL){
            if(strcmp(aux->propiedad.operacion, "En Alquiler") == 0){
                printf("%-10d | %-15.2f | %-15.2f | %-15s | %-25s | %-15s | %.2f\n", aux->propiedad.codigo, aux->propiedad.terreno, aux->propiedad.cubiertos, aux->propiedad.operacion, aux->propiedad.ubicacion, aux->propiedad.estado, aux->propiedad.precio);
                bandera = 1;
            }
            aux = aux->sig;
        }
        if(bandera == 0){
            printf("\nNo se han registrado propiedades en alquiler\n");
        }
        bandera = 0;
        break;
        default: printf("\nNo se ha ingresado una opcion valida\n");
        break;
    }
}

void CalcularEstado(Pila *pila){
    Pila *aux = pila;
    int desocupadas = 0;
    int ocupadas = 0;

    while(aux != NULL){
        if(strcmp(aux->propiedad.estado, "Desocupada") == 0){
            desocupadas++;
        }
        if(strcmp(aux->propiedad.estado, "Ocupada") == 0){
            ocupadas++;
        }
        aux = aux->sig;
    }

    printf("\nLa cantidad de propiedades desocupadas es de: %d\n", desocupadas);
    printf("\nLa cantidad de propiedades ocupadas es de: %d\n", ocupadas);
}

void LiberarPila(Pila **pila){
    while(*pila != NULL){
        Pila *prox = (*pila)->sig;
        free(*pila);
        *pila = prox;
    }
    printf("\nLa pila se ha liberado con exito\n");
}

int PilaVacia(Pila *pila){
    if(pila == NULL){
        return 0;
    }else{
        return 1;
    }
}
/*Desarrolla un programa que permita la gestión de propiedades en venta y/o en alquiler de una inmobiliaria utilizando el TDA cola.
Para ello cree la/las estructura/s que necesite para almacenar la siguiente información sobre código de propiedad (entero), m2 de terreno (decimal), 
m2 cubiertos (decimal), tipo operación (En venta/En alquiler), precio (decimal), ubicación (cadena) y el estado actual de la propiedad (Desocupada/Ocupada)
Desarrolla las siguientes funciones para: 
Registrar una nueva propiedad. 
Mostrar un listado de todas las propiedades por consola y generar un archivo .txt llamado "propiedades.txt", ambos en formato tabla. 
Borrar una propiedad 
Mostrar un listado de propiedades por tipo de operación en formato tabla. 
Calcular la cantidad de propiedades ocupadas y desocupadas.
Crea un menú de opciones para que el usuario pueda realizar diferentes acciones antes descritas.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int codigo;
    float terreno;
    float cubiertos;
    char operacion[15];
    float precio;
    char ubicacion[25];
    char estado[15];
}Propiedad;

typedef struct Nodo{
    Propiedad propiedades;
    struct Nodo *sig;
}Nodo;

void Menu();
void RegistrarNueva(Nodo **, Nodo **);
void ImprimirPropiedades(Nodo *);
void BorrarPropiedad(Nodo **, Nodo **);
void ListadoPorTipo(Nodo *);
void CalcularCantidad(Nodo *);
void Liberar(Nodo **, Nodo **);

int main(){
    Menu();
    return 0;
}

void Menu(){
    Nodo *frente = NULL;
    Nodo *fin = NULL;
    char opcion = ' ';

    do{
        printf("\n************MENU************\n");
        printf("\nIngrese la opcion que desea ejecutar:\n");
        printf("a) Registrar una nueva propiedad\n");
        printf("b) Imprimir lista de propiedades (En terminal y en archivo)\n");
        printf("c) Borrar la primera propiedad ingresada\n");
        printf("d) Listar propiedades por tipo de operacion\n");
        printf("e) Calcular la cantidad de propiedades ocupadas y desocupadas\n");
        printf("f) Salir del menu\n");
        scanf(" %c", &opcion);

        switch(opcion){
            case 'a':
            case 'A': char otra = 's';
            while(otra == 's' || otra == 'S'){
                RegistrarNueva(&frente, &fin);
                printf("\nDesea ingresar otra propiedad\?: Si(s), No(n)\n");
                scanf(" %c", &otra);
            }
            break;
            case 'b':
            case 'B': if(frente != NULL){
                ImprimirPropiedades(frente);
            }else{
                printf("\nDebe ingresar propiedades a la cola\n");
            }
            break;
            case 'c':
            case 'C': if(frente != NULL){
                BorrarPropiedad(&frente, &fin);
            }else{
                printf("\nDebe ingresar propiedades a la cola\n");
            }
            break;
            case 'd':
            case 'D': if(frente != NULL){
                ListadoPorTipo(frente);
            }else{
                printf("\nDebe ingresar propiedades a la cola\n");
            }
            break;
            case 'e':
            case 'E': if(frente != NULL){
                CalcularCantidad(frente);
            }else{
                printf("\nDebe ingresar propiedades a la cola\n");
            }
            break;
            case 'f':
            case 'F': if(frente != NULL){
                Liberar(&frente, &fin);
            }else{
                printf("\nSaliendo del menu, cola vacia\n");
            }
            break;
            default: printf("\nNo ha ingresado una opcion válida\n");
            break;
        }
    }while(opcion != 'f' && opcion != 'F');
}

void RegistrarNueva(Nodo **frente, Nodo **fin){
    Nodo *nuevo = (Nodo *) malloc(sizeof(Nodo));
    if(nuevo != NULL){
        printf("\nIngrese los siguientes datos de la propiedad\n");
        printf("Codigo: ");
        scanf(" %d", &nuevo->propiedades.codigo);
        printf("m2 de terreno: ");
        scanf(" %f", &nuevo->propiedades.terreno);
        printf("m2 cubiertos: ");
        scanf(" %f", &nuevo->propiedades.cubiertos);
        printf("Tipo de operacion (En alquiler/En venta): ");
        getchar();
        fgets(nuevo->propiedades.operacion, 15, stdin);
        nuevo->propiedades.operacion[strcspn(nuevo->propiedades.operacion, "\n")] = '\0';
        printf("Ubicacion: ");
        fgets(nuevo->propiedades.ubicacion, 25, stdin);
        nuevo->propiedades.ubicacion[strcspn(nuevo->propiedades.ubicacion, "\n")] = '\0';
        printf("Estado (Desocupada/Ocupada): ");
        fgets(nuevo->propiedades.estado, 15, stdin);
        nuevo->propiedades.estado[strcspn(nuevo->propiedades.estado, "\n")] = '\0';
        printf("Precio: ");
        scanf(" %f", &nuevo->propiedades.precio);
        nuevo->sig = NULL;

        if(*fin == NULL){
            *frente = nuevo;
            *fin = nuevo;
        }else{
            (*fin)->sig = nuevo;
            *fin = nuevo;
        }
    }else{
        printf("\nNo se ha podido crear el nodo\n");
    }
}

void ImprimirPropiedades(Nodo *frente){
    Nodo *aux = frente;
    printf("\nLas propiedades ingresadas hasta el moemnto son:\n");
    printf("%-8s | %-12s | %-12s | %-12s | %-25s | %-12s | %s\n", "Codigo", "Terreno m2", "Cubiertos m2", "Operacion", "Ubicacion", "Estado", "Precio");
    while(aux != NULL){
        printf("%-8d | %-12.2f | %-12.2f | %-12s | %-25s | %-12s | %.2f\n", aux->propiedades.codigo, aux->propiedades.terreno, aux->propiedades.cubiertos, aux->propiedades.operacion, aux->propiedades.estado, aux->propiedades.ubicacion, aux->propiedades.precio);
        aux = aux->sig;
    }
    aux = frente;
    FILE *archivo = fopen("propiedades.txt", "w");
    if(archivo == NULL){
        printf("\nNo se ha podido abrir el archivo\n");
    }else{
        while(aux != NULL){
        fprintf(archivo, "%-8d | %-15.2f | %-12.2f | %-12s | %-25s | %-12s | %.2f\n", aux->propiedades.codigo, aux->propiedades.terreno, aux->propiedades.cubiertos, aux->propiedades.operacion, aux->propiedades.estado, aux->propiedades.ubicacion, aux->propiedades.precio);
        aux = aux->sig;
        }
    }
    fclose(archivo);
}

void BorrarPropiedad(Nodo **frente, Nodo **fin){
    Propiedad propiedad = (*frente)->propiedades;
    Nodo *aux = *frente;
    free(*frente);
    *frente = aux->sig;
    if(*frente == NULL){
        *fin = NULL;
    }
    printf("\nSe ha eliminado la propiedad:\n");
    printf("%-8s | %-12s | %-12s | %-15s | %-25s | %-15s | %s\n", "Codigo", "Terreno m2", "Cubiertos m2", "Operacion", "Ubicacion", "Estado", "Precio");
    printf("%-8d | %-12.2f | %-12.2f | %-15s | %-25s | %-15s | %.2f\n", propiedad.codigo, propiedad.terreno, propiedad.cubiertos, propiedad.operacion, propiedad.ubicacion, propiedad.estado, propiedad.precio);   
}

void ListadoPorTipo(Nodo *frente){
    Nodo *aux = frente;

    printf("\nEn venta:\n");
    printf("%-8s | %-12s | %-12s | %-15s | %-25s | %-15s | %s\n", "Codigo", "Terreno m2", "Cubiertos m2", "Operacion", "Ubicacion", "Estado", "Precio");
    while(aux != NULL){
        if((strcmp(aux->propiedades.operacion, "En venta")) == 0 || (strcmp(aux->propiedades.operacion, "en venta")) == 0){
            printf("%-8d | %-12.2f | %-12.2f | %-15s | %-25s | %-15s | %.2f\n", aux->propiedades.codigo, aux->propiedades.terreno, aux->propiedades.cubiertos, aux->propiedades.operacion, aux->propiedades.ubicacion, aux->propiedades.estado, aux->propiedades.precio);   
        }
        aux = aux->sig;
    }

    aux = frente;
    printf("\nEn alquiler:\n");
    while(aux != NULL){
        if((strcmp(aux->propiedades.operacion, "En alquiler")) == 0 || (strcmp(aux->propiedades.operacion, "en alquiler")) == 0){
            printf("%-8d | %-12.2f | %-12.2f | %-15s | %-25s | %-15s | %.2f\n", aux->propiedades.codigo, aux->propiedades.terreno, aux->propiedades.cubiertos, aux->propiedades.operacion, aux->propiedades.ubicacion, aux->propiedades.estado, aux->propiedades.precio);   
        }
        aux = aux->sig;
    }
}

void CalcularCantidad(Nodo *frente){
    Nodo *aux = frente;
    int desocupada = 0;
    int ocupada = 0;

    while(aux != NULL){
        if((strcmp(aux->propiedades.estado, "Desocupada")) == 0 || (strcmp(aux->propiedades.estado, "desocupada")) == 0){
            desocupada++;
        }
        aux = aux->sig;
    }

    aux = frente;
   
    while(aux != NULL){
        if((strcmp(aux->propiedades.estado, "Ocupada")) == 0 || (strcmp(aux->propiedades.estado, "ocupada")) == 0){
            ocupada++;
        }
        aux = aux->sig;
    }

    printf("\nLa cantidad de propiedades ocupadas es de %d y las desocupadas es de %d\n", ocupada, desocupada);
}

void Liberar(Nodo **frente, Nodo **fin){
    while(*frente != NULL){
        Nodo *prox = (*frente)->sig;
        free(*frente);
        *frente = prox;
    }
    *fin = NULL;
    printf("\nLa cola se ha vaciado con exito\n");
}
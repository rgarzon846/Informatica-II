/*Elaborar un sistema de stock, en la cual posee una pila de productos con los
siguientes atributos: código, nombre, cantidad, precio lista. Desarrollar las
siguientes funciones:
- Agregar un nuevo producto.
- Borrar el último nodo de la pila.
- Mostrar el stock.
- Descontar stock.
- Reponer stock.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  long cod;
  char nombre[25];
  int cant;
  float precio;
} Producto;

typedef struct Nodo {
  Producto producto;
  struct Nodo *sig;
} Nodo;

void Menu();
void Agregar(Nodo **);
void Borrar(Nodo **);
void Stock(Nodo *);
void Descontar(Nodo **);
void Reponer(Nodo **);
void Liberar(Nodo **);

int main() { 
    Menu();
    return 0; }

void Menu() { 
    Nodo *p = NULL;
    char opcion = ' ';
    char volver = 's';

    do{
        printf("Ingrese la opcion que desee ejecutar\n");
        printf("a. Agregar un producto\n");
        printf("b. Borrar el ultimo producto ingresado\n");
        printf("c. Mostrar el stock ingresado\n");
        printf("d. Descontar unidades de un ptoducto\n");
        printf("e. Reponer unidades de un producto\n");
        scanf(" %c", &opcion);
        
        switch(opcion){
            case 'a':
            case 'A': char bandera = 's';
            while(bandera == 's' || bandera == 'S'){
                Agregar(&p);
                printf("\nDesea ingresar otro producto\?: Si(s), No(n)\n");
                scanf(" %c", &bandera);
            }
            break;
            case 'b':
            case 'B': if(p != NULL){
                Borrar(&p);
            }else{
                printf("\nIngrese productos a la pila\n");
            }
            break;
            case 'c':
            case 'C': if(p != NULL){
                Stock(p);
            }else{
                printf("\nIngrese productos a la pila\n");
            }
            break;
            case 'd':
            case 'D': if(p != NULL){
                Descontar(&p);
            }else{
                printf("\nIngrese productos a la pila\n");
            }break;
            case 'e':
            case 'E':if(p != NULL){
                Reponer(&p);
            }else{
                printf("\nIngrese productos a la pila\n");
            }break;
            default: printf("\nNo se ha elegido una opcion valida\n"); break;
        }
        printf("\nDesea volver al menu\?: Si(s), No(n)\n");
        scanf(" %c", &volver);
    }while(volver == 's' || volver == 'S');
    Liberar(&p);
}

void Agregar(Nodo **p) {
    Nodo *nuevo = (Nodo *)malloc(sizeof(NULL));
    printf("\nIngrese los siguientes datos los producto:\n");
    printf("Nombre: ");
    getchar();
    fgets(nuevo->producto.nombre, 25, stdin);
    nuevo->producto.nombre[strcspn(nuevo->producto.nombre, "\n")] = '\0';
    printf("Codigo: ");
    scanf(" %ld", &nuevo->producto.cod);
    printf("Cantidad: ");
    scanf(" %d", &nuevo->producto.cant);
    printf("Precio: ");
    scanf(" %f", &nuevo->producto.precio);
    nuevo->sig = *p;
    *p = nuevo;
}

void Borrar(Nodo **p) {
  Nodo *aux = *p;
  Producto producto = aux->producto;
  *p = aux->sig;
  free(aux);
  aux = *p;
  printf("\nSe ha eliminado el ultimo nodo de la pila que contenia al "
         "producto:\n");
  printf("%-25s | %-15s | %-5s | %s\n", "Nombre", "Codigo", "Stock", "Precio");
  printf("%-25s | %-15ld | %-5d | %.2f\n", producto.nombre, producto.cod,
         producto.cant, producto.precio);
}

void Stock(Nodo *p) {
  Nodo *aux = p;
  printf("\nLa lista cuenta con los siguientes productos\n");
  printf("%-25s | %-15s | %-5s | %s\n", "Nombre", "Codigo", "Stock", "Precio");
    while (aux != NULL) {
      printf("%-25s | %-15ld | %-5d | %.2f\n", aux->producto.nombre,
             aux->producto.cod, aux->producto.cant, aux->producto.precio);
      aux = aux->sig;
    }
}

void Descontar(Nodo **p){
    Nodo *aux = *p;
    char nombre[25];
    int cant = 0;
    printf("\nIngrese el nombre del producto que desee descontar stock: ");
    getchar();
    fgets(nombre, 25, stdin);
    while(aux != NULL){
        if(strcmp(nombre, aux->producto.nombre) == 0){
            printf("\nEl producto cuenta con %d unidades\n", aux->producto.cant);
            printf("\nCuantas unidades desea descontar\?: ");
            scanf(" %d", &cant);
            aux->producto.cant = cant;
        }
        aux = aux->sig;
    }
    printf("\nSe ha actualizado el stock del producto con exito\n");
}

void Reponer(Nodo **p){
    Nodo *aux = *p;
    char nombre[25];
    int cant = 0;
    printf("\nIngrese el nombre del producto que desee reponer stock: ");
    getchar();
    fgets(nombre, 25, stdin);
    while(aux != NULL){
        if(strcmp(nombre, aux->producto.nombre) == 0){
            printf("\nEl producto cuenta con %d unidades\n", aux->producto.cant);
            printf("\nCuantas unidades desea reponer\?: ");
            scanf(" %d", &cant);
            aux->producto.cant = cant;
        }
        aux = aux->sig;
    }
    printf("\nSe ha actualizado el stock del producto con exito\n");
}


void Liberar(Nodo **p){
    while(*p != NULL){
        Nodo *prox = (*p)->sig;
        free(*p);
        *p = prox;
    }
    printf("\nSe ha liberado la lista con exito\n");
}
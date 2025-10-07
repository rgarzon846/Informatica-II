/*Desarrolle un programa que cargue una pila de números enteros aleatorios.
Luego realice un menú de opciones:
- Agregar un nodo a la pila. (cuando agrega un valor, el mismo no tiene que
estar repetido en la pila)
- Borrar el último nodo de la pila.
- Imprimir pila.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Nodo {
  int valor;
  struct Nodo *sig;
} Nodo;

void Menu();
void Agregar(Nodo **);
void Borrar(Nodo **);
void Imprimir(Nodo *);
void Liberar(Nodo **);

int main() { 
  Menu();
    return 0; }

void Menu() { 
    Nodo *p = NULL;
    char opcion = ' ';
    char volver = 's';

    do{
        printf("Ingrese la opcion que desee ejecutar:\n");
        printf("a. Agregar nodo a la pila\n");
        printf("b. Borrar el ultimo nodo de la pila\n");
        printf("c. Imprimir la pila\n");
        scanf(" %c", &opcion);

        switch(opcion){
            case 'a':
            case 'A': Agregar(&p);
            break;
            case 'b':
            case 'B': if(p != NULL){
                Borrar(&p);
            }else{
                printf("\nIngrese valores\n");
            }
            break;
            case 'c':
            case 'C': if(p != NULL){
               Imprimir(p);
            }else{
                printf("\nIngrese valores\n");
            }
            break;
            default: printf("\nNo ha ingresado una opcion valida\n");
            break;
        }
        printf("\nDesea volver al menu\?: Si(s), No(n)\n");
        scanf(" %c", &volver);
    }while(volver == 's' || volver == 'S');
    Liberar(&p);
}

void Agregar(Nodo **p) {
  srand(time(NULL));
  int cant = 0;
  printf("Cuantos valores desea que la pila contenga\?: ");
  scanf(" %d", &cant);

  for (int i = 0; i < cant; i++) {
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    if (nuevo != NULL) {
      nuevo->valor = rand() % 100 + 1;
      nuevo->sig = *p;
      *p = nuevo;

      Nodo *aux = *p;
      while (aux != NULL) {
        if (aux->valor == nuevo->valor) {
          nuevo->valor = rand() % 100 + 1;
          aux = *p;
        }
        aux = aux->sig;
      }
      *p = nuevo;
    } else {
      printf("\nNo se ha podido crear el nuevo nodo\n");
    }
  }
  printf("\nLa pila se ha creado con exito\n");
}

void Borrar(Nodo **p) {
  Nodo *aux = *p;
  int valor = aux->valor;
  *p = aux->sig;
  free(aux);
  printf("\nSe ha eliminado el ultimo nodo que contenia el valor: %d\n", valor);
 
}

void Imprimir(Nodo *p) {
  Nodo *aux = p;

  printf("\nLos valores de la pila son:\n");
  while (aux != NULL) {
    printf("%d\n", aux->valor);
    aux = aux->sig;
  }
}

void Liberar(Nodo **p){
  while(*p != NULL){
    Nodo *prox = (*p)->sig;
    free(*p);
    *p = prox;
  }
  printf("\nSe ha liberado la pila con exito\n");
}
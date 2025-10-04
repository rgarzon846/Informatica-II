/*Crear un programa en el cual cargue una pila de 5 números aleatoriamente
 * (entre 1 y 10), luego los muestre a todos y muestre solo los valores pares.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Nodo {
  int valor;
  struct Nodo *sig;
} Nodo;

int main() {
  Nodo *p = NULL;
  srand(time(NULL));
  int bandera = 0;
  for (int i = 0; i < 5; i++) {
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    if (nuevo != NULL) {
      nuevo->valor = rand() % 10 + 1;
      nuevo->sig = NULL;
      if (p == NULL) {
        p = nuevo;
      } else {
        Nodo *aux = p;
        while (aux->sig != NULL) {
          aux = aux->sig;
        }
        aux->sig = nuevo;
      }
    } else {
      printf("\nNo se ha podido crear el nodo\n");
    }
  }
  Nodo *aux = p;
  printf("Los valores en la pila son:\n");
  while (aux != NULL) {
    printf("%d\n", aux->valor);
    aux = aux->sig;
  }
  aux = p;
  printf("\nLos valores pares de la pila son:\n");
  while(aux != NULL){
    if((aux->valor%2) == 0){
        printf("%d", aux->valor);
        aux = aux->sig;
        bandera = 1;
    }
  }
  if(bandera == 0){
    printf("\nNo hay valores pares en la pila\n");
  }
  bandera = 0;
  return 0;
}

/*Crear un programa en el cual cargue una cola de 5 números aleatoriamente
 * (entre 1 y 10), luego los muestre a todos y muestre solo los valores pares.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Nodo {
  int valor;
  struct Nodo *sig;
} Nodo;

int main() {
  srand(time(NULL));
  int bandera = 0;
  Nodo *fin = NULL;
  Nodo *frente = NULL;

  for (int i = 0; i < 5; i++) {
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    nuevo->valor = rand() % 10 + 1;
    nuevo->sig = NULL;

    if (nuevo != NULL) {

      if (fin == NULL) {
        frente = nuevo;
        fin = nuevo;
      } else {
        fin->sig = nuevo;
        fin = nuevo;
      }
    } else {
      printf("\nNo se ha podido crear el nodo\n");
    }
  }

  Nodo *aux = frente;
  printf("\nLos valores que se ingresaron en la cola son: ");
  while (aux != NULL) {
    printf("%d-> ", aux->valor);
     if(aux->sig == NULL){
        printf("NULL");
    }
    aux = aux->sig;
  }
  aux = frente;
  printf("\nLos valores pares de la cola son: ");
  while (aux != NULL) {
    if (aux->valor % 2 == 0) {
      printf("%d-> ", aux->valor);
      bandera = 1;
    }
    if(aux->sig == NULL){
        printf("NULL");
    }
    aux = aux->sig;
  }
  if (bandera == 0) {
    printf("\nNo hay valores pares en la cola\n");
  }
  bandera = 0;

  if (frente != NULL) {
    while (frente != NULL) {
      Nodo *prox = frente->sig;
      free(frente);
      frente = prox;
    }
    printf("\nLa cola se ha vaciado con exito\n");
  } else {
    printf("\nLa cola esta vacia\n");
  }
}
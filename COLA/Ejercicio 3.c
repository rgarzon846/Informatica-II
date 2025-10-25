/*Desarrolle un programa que cargue una cola de números enteros aleatorios y
muestre. Luego arme una función que muestre el tamaño de la cola y otra función
que muestre el valor del frente de la cola.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Nodo {
  int valor;
  struct Nodo *sig;
} Nodo;

void Tamanio(Nodo *, int);

int main() {
  srand(time(NULL));
  Nodo *frente = NULL;
  Nodo *fin = NULL;
  int cant = rand() % 10 + 1;

  for (int i = 0; i < cant; i++) {
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));

    if (nuevo != NULL) {
      nuevo->valor = rand() % 100 + 1;
      nuevo->sig = NULL;
      if (fin == NULL) {
        frente = nuevo;
        fin = nuevo;
      } else {
        fin->sig = nuevo;
        fin = nuevo;
      }
    } else {
      printf("\nNo se ha podido crear el nuevo nodo\n");
    }
  }

  printf("\nLos valores de la cola son: ");
  Nodo *aux = frente;
  while (aux != NULL) {
    printf("%d-> ", aux->valor);
    if (aux->sig == NULL) {
      printf("NULL");
    }
    aux = aux->sig;
  }
  Tamanio(frente, cant);
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

void Tamanio(Nodo *frente, int cant) {
  printf("\nEl tamaño en bytes de la cola es de %zu bytes\n",
         (sizeof(Nodo) * cant));
  printf("\nLa cola contiene %d valores\n", cant);
  printf("\nEl valor del frente es: %d\n", frente->valor);
}
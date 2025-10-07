/*Crear un programa con el siguiente menú de opciones:
- Agregar un nodo a la pila. (se deben agregar 5 valores)
- Borrar el último nodo de la pila.
- Imprimir pila.
- Suma de los valores de la pila.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
  float valor;
  struct Nodo *sig;
} Nodo;

void Menu();
void Agregar(Nodo **);
void Borrar(Nodo **);
void Imprimir(Nodo *);
float Sumar(Nodo *);
void Liberar(Nodo **);

int main() {
  Menu();
  return 0;
}

void Menu() {
  Nodo *p = NULL;
  char opcion = ' ';
  char volver = 's';

  do {
    printf("Ingrese la opcion que desee ejecutar:\n");
    printf("a. Agregar valores a la pila\n");
    printf("b. Borrar el ultimo valor de la pila\n");
    printf("c. Imprimir los valores de la pila\n");
    printf("d. Sumar todos los valores dentro de la pila\n");
    scanf(" %c", &opcion);

    switch (opcion) {
    case 'a':
    case 'A':
    Agregar(&p);
      break;
    case 'b':
    case 'B':
      if (p != NULL) {
        Borrar(&p);
      } else {
        printf("Debe ingresar valores a la pila\n");
      }
      break;
    case 'c':
    case 'C':
      if (p != NULL) {
        Imprimir(p);
      } else {
        printf("Debe ingresar valores a la pila\n");
      }
      break;
    case 'd':
    case 'D':
      if (p != NULL) {
        printf("El resultado de la suma de los valores es: %.2f\n", Sumar(p));
      } else {
        printf("Debe ingresar valores en la pila\n");
      }
      break;
    default:
      printf("No se ha ingresado una opcion valida\n");
      break;
    }
    printf("Desea volver al menu\?: Si(s), No(n)\n");
    scanf(" %c", &volver);
  } while (volver == 's' || volver == 'S');
  Liberar(&p);
}

void Agregar(Nodo **p) {
  for (int i = 0; i < 5; i++) {
    printf("Igrese un numero: ");
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    if (nuevo != NULL) {
      scanf(" %f", &nuevo->valor);
      nuevo->sig = *p;
      *p = nuevo;
    } else {
      printf("\nNo se ha podido crear el nuevo nodo\n");
    }
  }
}

void Borrar(Nodo **p) {
  Nodo *aux = *p;
  float valor = aux->valor;
  *p = aux->sig;
  free(aux);
  printf("Se ha liberado el ultimo nodo que contenia el valor: %.2f\n", valor);
}

void Imprimir(Nodo *p) {
  Nodo *aux = p;

  printf("Los valores ingresados a la pila son:\n");
  while (aux != NULL) {
    printf("%.2f\n", aux->valor);
    aux = aux->sig;
  }
}

float Sumar(Nodo *p) {
  Nodo *aux = p;
  float suma = 0;

  while (aux != NULL) {
    suma += aux->valor;
    aux = aux->sig;
  }

  return suma;
}

void Liberar(Nodo **p) {
  while (*p != NULL) {
    Nodo *prox = (*p)->sig;
    free(*p);
    *p = prox;
  }
  printf("\nSe ha eliminado la pila correctamente\n");
}
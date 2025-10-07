/*Crear un programa con el siguiente menú de opciones:
- Agregar un nodo a la pila. (se deben agregar 5 valores)
- Borrar el último nodo de la pila.
- Imprimir pila.
- Tamaño de la pila
- Mostrar el último valor de la pila
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
void Tamanio(Nodo *);
void MostrarUltimo(Nodo *);
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
    printf("a. Agregar 5 valores\n");
    printf("b. Borrar el ultimo valor de la pila\n");
    printf("c. Imprimir la pila\n");
    printf("d. Imprimir el tamaño de la pila\n");
    printf("e. Imprimir el ultimo valor\n");
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
        printf("\nDebe ingresar valores\n");
      }
      break;
    case 'c':
    case 'C':
      if (p != NULL) {
        Imprimir(p);
      } else {
        printf("\nDebe ingresar valores\n");
      }
      break;
    case 'd':
    case 'D':
      if (p != NULL) {
        Tamanio(p);
      } else {
        printf("\nDebe ingresar valores\n");
      }
      break;
    case 'e':
    case 'E':
      if (p != NULL) {
        MostrarUltimo(p);
      } else {
        printf("\nDebe ingresar valores\n");
      }
      break;
    default:
      printf("\nNo ha ingresado una opcion valida\n");
      break;
    }
    printf("\nDesea volver al menu: Si(s), No(n)\n");
    scanf(" %c", &volver);
  } while (volver == 's' || volver == 'S');
  Liberar(&p);
}

void Agregar(Nodo **p) {
  for (int i = 0; i < 5; i++) {
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    if (nuevo != NULL) {
      printf("Ingrese un valor: ");
      scanf(" %f", &nuevo->valor);
      nuevo->sig = *p;
      *p = nuevo;     
    } else {
      printf("\nNo se ha podido crear el nodo\n");
    }
  }
}

void Borrar(Nodo **p) {
  Nodo *aux = *p;
  Nodo *ant = NULL;

  while (aux->sig != NULL) {
    ant = aux;
    aux = aux->sig;
  }
  printf("\nSe ha eliminado el ultimo nodo que contenia el valor: %.2f",
         aux->valor);
  free(aux);
  ant->sig = NULL;
}

void Imprimir(Nodo *p) {
  Nodo *aux = p;
  printf("\nLa pila contiene los siguientes valores:\n");
  while (aux != NULL) {
    printf("%.2f\n", aux->valor);
    aux = aux->sig;
  }
}

void Tamanio(Nodo *p) {
  int cont = 0;
  Nodo *aux = p;
  while (aux != NULL) {
    cont++;
    aux = aux->sig;
  }
  printf("La cantidad de valores ingresados es de : %d valores", cont);
  printf("\nEl tamaño en bytes de la pila es de %zu bytes", (5 * sizeof(Nodo)));
}

void MostrarUltimo(Nodo *p) {
  Nodo *aux = p;
  while (aux->sig != NULL) {
    aux = aux->sig;
  }
  printf("El valor del ultimo nodo es: %.2f", aux->valor);
}

void Liberar(Nodo **p) {
  while (*p != NULL) {
    Nodo *prox = (*p)->sig;
    free(*p);
    *p = prox;
  }
  printf("\nLa memoria se ha liberado con exito\n");
}
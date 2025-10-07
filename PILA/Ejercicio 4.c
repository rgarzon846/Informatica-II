/*Crear un programa con el siguiente menú de opciones:
- Agregar un nodo a la pila.
- Borrar el último nodo de la pila.
- Imprimir pila.
- Cantidad de nodos en la pila.
- Cantidades de letras mayúsculas y minúsculas en la pila.

El usuario cargará la pila con letras mayúsculas o minúsculas.
Nota: Las letras en ASCII mayúsculas están entre el 65 a 90 y las minúsculas
entre  97 a 122 inclusive.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
  char letra;
  struct Nodo *sig;
} Nodo;

void Menu();
void Agregar(Nodo **);
void Borrar(Nodo **);
void Imprimir(Nodo *);
void TotalNodos(Nodo *);
void MayusMinus(Nodo *);
void Liberar(Nodo **);

int main() {
  Menu();
  return 0;
}

void Menu() {
  Nodo *p = NULL;
  char opcion = ' ';
  char volver = 's';
  char otro = 's';

  do {
    printf("Ingrese la opcion que desee ejecutar:\n");
    printf("a. Agregar una letra\n");
    printf("b. Eliminar el ultimo nodo de la pila\n");
    printf("c. Imprimir la pila ingresada\n");
    printf("d. Contar el total de nodos de la pila\n");
    printf("e. Contar la cantidad de mayusculas y minusculas de la pila\n");
    scanf(" %c", &opcion);

    switch (opcion) {
    case 'a':
    case 'A':
      while (otro == 's' || otro == 'S') {
        Agregar(&p);
        printf("\nDesea ingresar otra letra\?: Si(s), No(n)\n");
        scanf(" %c", &otro);
      }
      otro = 's';
      break;
    case 'b':
    case 'B':
      if (p != NULL) {
        Borrar(&p);
      } else {
        printf("\nIngrese letras a la pila\n");
      }
      break;
    case 'c':
    case 'C':
      if (p != NULL) {
        Imprimir(p);
      } else {
        printf("\nIngrese letras a la pila\n");
      }
      break;
    case 'd':
    case 'D':
      if (p != NULL) {
        TotalNodos(p);
      } else {
        printf("\nIngrese letras a la pila\n");
      }
      break;
    case 'e':
    case 'E':
      if (p != NULL) {
        MayusMinus(p);
      } else {
        printf("\nIngrese letras a la pila\n");
      }
      break;
    default:
      printf("\nNo ha ingresado una opcion valida\n");
      break;
    }
    printf("\nDesea volver al menu\?: Si(s), No(n)\n");
    scanf(" %c", &volver);
  } while (volver == 's' || volver == 'S');
  Liberar(&p);
}

void Agregar(Nodo **p) {
  Nodo *nuevo = (Nodo *)malloc(sizeof(NULL));
  printf("Ingrese una letra: ");
  scanf(" %c", &nuevo->letra);
  nuevo->sig = NULL;
  if (nuevo != NULL) {
    if (*p == NULL) {
      *p = nuevo;
    } else {
      Nodo *aux = *p;
      while (aux->sig != NULL) {
        aux = aux->sig;
      }
      aux->sig = nuevo;
    }
  } else {
    printf("\nNo se ha podido crear el nuevo nodo\n");
  }
}

void Borrar(Nodo **p) {
  Nodo *aux = *p;
  Nodo *ant = NULL;
  while (aux->sig != NULL) {
    ant = aux;
    aux = aux->sig;
  }
  printf("\nSe ha liberado el ultimo nodo de la pila que contenia la letra: %c",
         aux->letra);
  free(aux);
  ant->sig = NULL;
}

void Imprimir(Nodo *p) {
  Nodo *aux = p;
  printf("\nLa pila contiene las siguientes letras:\n");
  while (aux != NULL) {
    printf("%c\n", aux->letra);
    aux = aux->sig;
  }
}

void TotalNodos(Nodo *p) {
  int cont = 0;
  Nodo *aux = p;
  while (aux != NULL) {
    cont++;
    aux = aux->sig;
  }
  printf("\nLa pila contiene %d nodos", cont);
}

void MayusMinus(Nodo *p) {
  Nodo *aux = p;
  int contMayus = 0;
  int contMinus = 0;
  while (aux != NULL) {

    if (65 <= aux->letra && aux->letra <= 90) {
      contMayus++;
    }
    if (97 <= aux->letra && aux->letra <= 122) {
      contMinus++;
    }
    aux = aux->sig;
  }
  printf("\nLa cantidad de mayusculas de la pila es de %d\n", contMayus);
  printf("\nLa cantidad de minusculas de la pila es de %d\n", contMinus);
}

void Liberar(Nodo **p) {
  while (*p != NULL) {
    Nodo *prox = (*p)->sig;
    free(*p);
    *p = prox;
  }
  printf("\nLa pila se ha liberado con exito\n");
}

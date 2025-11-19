/*Desarrolla un programa para gestionar los datos de un restaurante mediante un
TDA. El TDA debe contener la información de los platos disponibles, incluyendo
nombre del plato, cantidad de platos disponibles (entero), cantidad de platos
vendidos (entero) y precio (decimal). Implementa las siguientes funciones para:

Insertar un nuevo plato en el menú.
Mostrar el menú por consola y generar un archivo txt llamado "menu.txt".
Eliminar un plato del menú.
Calcular la recaudación total de los platos vendidos.
Ordenar los platos por precio usando quicksort.(recursividad)
Además, crea un menú de opciones para que el usuario pueda interactuar con el
programa.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char nombre[25];
  int cantdispo;
  int vendidos;
  float precio;
} Plato;

typedef struct Platos {
  Plato plato;
  struct Platos *sig;
} Platos;

void Menu();
void InsertarPlato(Platos **, Platos **);
void ImprimirMenu(Platos *);
void EliminarPlato(Platos **, Platos **);
float CalcularTotal(Platos *);
// void OrdenarPlatos(Platos *);
void LiberarCola(Platos **, Platos **);
int ColaVacia(Platos *);

int main() {

  Menu();
  return 0;
}

void Menu() {
  Platos *frente = NULL;
  Platos *fin = NULL;
  char opcion = ' ';

  do {
    printf("\n********MENU********\n");
    printf("a) Ingresar un nuevo plato al menu\n");
    printf("b) Imprimir el menu disponible y crear un archivo con el mismo\n");
    printf("c) Eliminar del menu el primer plato ingresado\n");
    printf("d) Calcular el total recaudado por todos los platos vendidos\n");
    printf("e) Salir\n");
    scanf(" %c", &opcion);

    switch (opcion) {
    case 'a':
    case 'A':
      char otro = 's';
      while (otro == 's' || otro == 'S') {
        InsertarPlato(&frente, &fin);
        printf("\nDesea ingresar otro plato al menu\? Si(s), No(n)\n");
        scanf(" %c", &otro);
      }
      break;
    case 'b':
    case 'B':
      if (ColaVacia(frente)) {
        ImprimirMenu(frente);
      } else {
        printf("\nAun no hay platillos en el menu\n");
      }
      break;
    case 'c':
    case 'C':
      if (ColaVacia(frente)) {
        EliminarPlato(&frente, &fin);
      } else {
        printf("\nAun no hay platillos en el menu\n");
      }
      break;
    case 'd':
    case 'D':
      if (ColaVacia(frente)) {
        printf("\nEl total de dinero recaudado es de: %.2f\n",
               CalcularTotal(frente));
      } else {
        printf("\nAun no hay platillos en el menu\n");
      }
      break;
    case 'e':
    case 'E':
      if (ColaVacia(frente)) {
        LiberarCola(&frente, &fin);
      } else {
        printf("\nSaliendo del menu, sin platillos registrados\n");
      }
      break;
    default:
      printf("\nNo se ha ingresado una opcion valida\n");
      break;
    }
  } while (opcion != 'e' && opcion != 'E');
}

void InsertarPlato(Platos **frente, Platos **fin) {
  Platos *nuevo = (Platos *)malloc(sizeof(Platos));
  if (nuevo != NULL) {
    printf("\nIngrese los siguientes datos del plato:\n");
    printf("Nombre: ");
    getchar();
    fgets(nuevo->plato.nombre, 25, stdin);
    nuevo->plato.nombre[strcspn(nuevo->plato.nombre, "\n")] = '\0';
    printf("Cantidad disponible: ");
    scanf(" %d", &nuevo->plato.cantdispo);
    printf("Cantidad vendidos: ");
    scanf(" %d", &nuevo->plato.vendidos);
    printf("Precio: ");
    scanf(" %f", &nuevo->plato.precio);
    nuevo->sig = NULL;

    if (*fin == NULL) {
      *frente = nuevo;
      *fin = nuevo;
    } else {
      (*fin)->sig = nuevo;
      *fin = nuevo;
    }
    printf("\nEL plato se ha registrado con exito\n");
  } else {
    printf("\nError al reservar memoria\n");
    return;
  }
}

void ImprimirMenu(Platos *frente) {
  Platos *aux = frente;
  printf("\n************MENU DE PLATOS DISPONIBLES************\n");
  printf("%-25s | %s\n", "Nombre", "Precio");
  while (aux != NULL) {
    printf("%-25s | %.2f\n", aux->plato.nombre, aux->plato.precio);
    aux = aux->sig;
  }
  aux = frente;
  FILE *archivo = fopen("menu.txt", "w");
  if (archivo == NULL) {
    printf("\nNo se ha podido crear el archivo\n");
    return;
  } else {
    fprintf(archivo, "%-25s | %s\n", "Nombre", "Precio");
    while (aux != NULL) {
      fprintf(archivo, "%-25s | %.2f\n", aux->plato.nombre, aux->plato.precio);
      aux = aux->sig;
    }
    fclose(archivo);
    printf("\nEl archivo creado con el menu esta actualizado\n");
  }
}

void EliminarPlato(Platos **frente, Platos **fin) {
  Plato plato = (*frente)->plato;
  Platos *aux = *frente;
  *frente = aux->sig;
  if (*frente == NULL) {
    *fin = NULL;
  }
  free(aux);
  printf("\nEl plato eliminado ha sido:\n");
  printf("%-25s | %-15s | %-15s |%s\n", "Nombre", "Disponibles", "Vendidos",
         "Precio");
  printf("%-25s | %-15d | %-15d | %.2f\n", plato.nombre,
        plato.cantdispo, plato.vendidos, plato.precio);
}

float CalcularTotal(Platos *frente) {
  Platos *aux = frente;
  float suma = 0;
  float porplato = 0;

  while (aux != NULL) {
    porplato = aux->plato.vendidos * aux->plato.precio;
    suma += porplato;
    aux = aux->sig;
  }

  return suma;
}

/*void OrdenarPlatos(Platos *frente){
    Platos *ordenados = frente;


}*/

void LiberarCola(Platos **frente, Platos **fin) {
  while (*frente != NULL) {
    Platos *prox = (*frente)->sig;
    free(*frente);
    *frente = prox;
  }
  *fin = NULL;
  printf("\nSe ha liberado la cola con exito\n");
}

int ColaVacia(Platos *frente) {
  if (frente != NULL) {
    return 1;
  } else {
    return 0;
  }
}
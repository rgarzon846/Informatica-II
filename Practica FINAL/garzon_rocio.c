#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int nroremito;
  char centroesqui[15];
  char tipoequipo[15];
  float costodiario;
  int cantdias;
  char facturado[3];
} Remito;

typedef struct Pila {
  Remito remito;
  struct Pila *sig;
} Pila;

void RegistrarAlquiler(Pila **, int *);
void AlquileresNoFacturados(Pila *);
void BorrarAlquiler(Pila **);
void LiberarPila(Pila **);
int PilaVacia(Pila *);
void Menu();

int main() {
  Menu();
  return 0;
}

void Menu() {
  Pila *pila = NULL;
  int nroremito = 1000;
  int opcion = 0;

  do {
    printf("\n~~~~~~~~ MENU DE OPCIONES ~~~~~~~~\n");
    printf("1) Registrar un nuevo alquiler\n");
    printf("2) Mostrar alquileres que no se hayan facturado y generar un "
           "archivo con los mismos\n");
    printf("3) Eliminar un remito del registro\n");
    printf("4) Salir\n");
    scanf(" %d", &opcion);

    switch (opcion) {
    case 1:
      char otro = 's';
      while (otro == 's' || otro == 'S') {      //Un while por si la persona quiere añadir mas de un remito en la primera ejecucion de la opcion
        RegistrarAlquiler(&pila, &nroremito);
        printf("\nDesea registrar otro alquiler\?: SI(s), NO(n)\n");
        scanf(" %c", &otro);
      }
      break;
      //Cada if en los siguientes casos comprueba si la pila esta o no esta vacia y de acuerdo a ello permite que se ejecute o no la funcion
    case 2:
      if (PilaVacia(pila)) {
        AlquileresNoFacturados(pila);
      } else {
        printf("\nAun no hay alquileres en el registro\n");
      }
      break;
    case 3:
      if (PilaVacia(pila)) {
        BorrarAlquiler(&pila);
      } else {
        printf("\nAun no hay alquileres en el registro\n");
      }
      break;
    case 4:
      if (PilaVacia(pila)) {
        LiberarPila(&pila);
      } else {
        printf("\nSaliendo... Sin alquileres registrados\n");
      }
      break;
    default:
      printf("\nNo se ha ingresado una opcion valida\n");
      break;
    }
  } while (opcion != 4);
}

void RegistrarAlquiler(Pila **pila, int *nroremito) { //FUncion que permite registrar un nuevo alquiler
  int centroesqui = 0;
  int tipoequipo = 0;
  char facturado = ' ';
  Pila *nuevo = (void *)malloc(sizeof(Pila));

  if (nuevo != NULL) {
    (*nroremito)++;
    nuevo->remito.nroremito = *nroremito;

    printf("\nIngrese la informacion de remito solicitada:\n");

    printf("Centro de esqui:\n");
    printf("1) C Catedral\n");
    printf("2) Las Leñas\n");
    printf("3) Penitentes\n");
    printf("4) Chapelco\n");
    printf("5) C castor\n");
    scanf(" %d", &centroesqui);

    do {            //En do while ya que si se ingresa una opcion que no esta entre 1 y 5 debe tomarse de vuelta el dato e ingresarlo al nodo
      switch (centroesqui) {
      case 1:
        strcpy(nuevo->remito.centroesqui, "C Catedral");
        break;
      case 2:
        strcpy(nuevo->remito.centroesqui, "Las Leñas");
        break;
      case 3:
        strcpy(nuevo->remito.centroesqui, "Penitentes");
        break;
      case 4:
        strcpy(nuevo->remito.centroesqui, "Chapelco");
        break;
      case 5:
        strcpy(nuevo->remito.centroesqui, "C Castor");
        break;
      default:
        printf("\nNo ha ingresado una opcion correcta\n");
        break;
      }
    } while (centroesqui < 1 || centroesqui > 5);

    printf("Tipo de equipo:\n");
    printf("1) Junior\n");
    printf("2) Basico\n");
    printf("3) Completo\n");
    scanf(" %d", &tipoequipo);

    do {
      switch (tipoequipo) {
      case 1:
        strcpy(nuevo->remito.tipoequipo, "Junior");
        nuevo->remito.costodiario = 10000;
        break;
      case 2:
        strcpy(nuevo->remito.tipoequipo, "Basico");
        nuevo->remito.costodiario = 15000;
        break;
      case 3:
        strcpy(nuevo->remito.tipoequipo, "Completo");
        nuevo->remito.costodiario = 30000;
        break;
      default:
        printf("\nNo ha ingresado una opcion correcta\n");
        break;
      }
    } while (tipoequipo < 1 || tipoequipo > 3);

    printf("Cantidad de dias: ");
    scanf(" %d", &nuevo->remito.cantdias);

    printf("Facturado: Si(s), No(N)\n");
    scanf(" %c", &facturado);

    if (facturado == 'S' || facturado == 's') {         //Copia segun el caracter que le llegue si esta o no facturado
      strcpy(nuevo->remito.facturado, "Si");
    } else if (facturado == 'N' || facturado == 'n') {
      strcpy(nuevo->remito.facturado, "No");
    }
    nuevo->sig = NULL;

    if (*pila == NULL) {
      *pila = nuevo;        // Si la pila esta vacia el unico dato dentro de ella sera la estructura cargada recientemente
    } else {            //Si la pila ya tiene dato el ultimo dato sera el cargado recientemente y el penultimo el que era *pila antes
      nuevo->sig = *pila;
      *pila = nuevo;
    }

    printf("\nEl remito se ha generado con exito\n");
  } else {
    printf("\nError al registrar arquiler\n");
  }
}

void AlquileresNoFacturados(Pila *pila) {
  Pila *aux = pila;
  float total = 0;

  printf("\nLos alquileres no facturados son:\n");
  printf("%-15s | %-15s | %-15s | %-15s | %-15s | %-10s | %s\n", "N° Remito",
         "Centro", "Tipo", "Costo diario", "Cant dias", "Facturado", "Total");
  while (aux != NULL) {     //Recorre la pila hasta que no haya mas nodos en ella
    if (strcmp(aux->remito.facturado, "No") == 0) {     //Si el remito figura como no facturado imprime los datos del nodo, sino pasa al siguiente
      total = aux->remito.costodiario * aux->remito.cantdias;
      printf("%-15d | %-15s | %-15s | %-15.2f | %-15d | %-10s | %.2f\n",
             aux->remito.nroremito, aux->remito.centroesqui,
             aux->remito.tipoequipo, aux->remito.costodiario,
             aux->remito.cantdias, aux->remito.facturado, total);
    }
    aux = aux->sig;
  }

  aux = pila;       //El auxiliar vuelve desde el comienzo

  FILE *archivo = fopen("alquileres.txt", "w");
  if (archivo != NULL) {
    fprintf(archivo, "%-15s | %-15s | %-15s | %-15s | %-15s | %-10s | %s\n",
            "N° Remito", "Centro", "Tipo", "Costo diario", "Cant dias",
            "Facturado", "Total");
    while (aux != NULL) {
      if (strcmp(aux->remito.facturado, "No") == 0) {
        total = aux->remito.costodiario * aux->remito.cantdias;
        fprintf(archivo,
                "%-15d | %-15s | %-15s | %-15.2f | %-15d | %-10s | %.2f\n",
                aux->remito.nroremito, aux->remito.centroesqui,
                aux->remito.tipoequipo, aux->remito.costodiario,
                aux->remito.cantdias, aux->remito.facturado, total);
      }
      aux = aux->sig;
    }
    fclose(archivo);
    printf("\nEl archivo de alquileres se ha actualizado con exito\n");
  }
}

void BorrarAlquiler(Pila **pila) {
  Remito remito = (*pila)->remito;
  Pila *aux = *pila;

  *pila = aux->sig;     //Ahora el *pila sera el siguiente del que sera eliminado
  free(aux);        //Se elimina el anterior cabecera
  if (*pila == NULL) {
    printf("\nNo hay mas alquileres registrados\n");
  }

  printf("\nEL remito eliminado ha sido el remito:\n");
  printf("%-15s | %-15s | %-15s | %-15s | %-15s | %s\n", "N° Remito", "Centro",
         "Tipo", "Costo diario", "Cant dias", "Facturado");
  printf("%-15d | %-15s | %-15s | %-15.2f | %-15d | %s\n", remito.nroremito,
         remito.centroesqui, remito.tipoequipo, remito.costodiario,
         remito.cantdias, remito.facturado);
}

void LiberarPila(Pila **pila) {
  while (*pila != NULL) {
    Pila *prox = (*pila)->sig;
    free(*pila);
    *pila = prox;
  }
  printf("\nLa pila se ha liberado con exito\n");       //IMPORTANTE LIBERAR TODA LA MEMORIA UTILIZADA!!!
}

int PilaVacia(Pila *pila) {
  if (pila == NULL) {
    return 0;
  } else {
    return 1;
  }
}       //Funcion auxiliar para comprobar si la pila tiene datos

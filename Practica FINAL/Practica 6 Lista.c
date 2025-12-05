/*Desarrolla un programa que permita la gestión de reservas en una empresa de cruceros utilizando el TDA pila. 
Para ello cree la/las estructura/s que necesite para almacenar la siguiente información sobre número de reserva (entero), 
nombre del pasajero (cadena), número de cabina (entero), costo por noche (decimal), cantidad de noches (entero), 
día (entero) y mes (entero) de la reserva. 

Crea un menú de opciones que se repetirá hasta que el usuario decida finalizar el programa. Este menú debe permitir 
la elección de opciones en letras mayúsculas o minúsculas y, para cada caso, llamará a las siguientes funciones:

Registrar una nueva reserva. 
Mostrar un listado de todas las reservas por consola y generar un archivo .txt llamado "reserva_crucero.txt", ambos en formato tabla. 
Borrar una reserva 
Mostrar un listado de reservas por mes en formato tabla. El mes es ingresado por el usuario
Calcular la cantidad de reservas cuyo costo total sea mayor a 2000. 
Nota: Los datos pueden ser cargados o bien utilizar números aleatorios.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

typedef struct{
    int nroreserva;
    char nombre[25];
    int nrocabina;
    float costonoche;
    int cantnoches;
    int dia;
    int mes;
}Reserva;

typedef struct Lista{
    Reserva reserva;
    struct Lista *sig;
}Lista;

void Menu();
void RegistrarReserva(Lista **, int *);
void ImprimirReservas(Lista *);
void EliminarReserva(Lista **);
void ReservasMes(Lista *);
int CalcularReservas2000(Lista *);
int ListaVacia(Lista *);
void LiberarLista(Lista **);
void Mayuscula(char [25]);


int main(){
    Menu();
    return 0;
}

void Menu(){
    Lista *lista = NULL;
    int nroreserva = 0;
    int opcion = 0;

    do{
        printf("\n~~~~~~~~~~~ MENU DE OPCIONES ~~~~~~~~~~~\n");
        printf("1) Registrar una nueva reserva\n");
        printf("2) Imprimir las reservas registradas y un archivo con las mismas\n");
        printf("3) Eliminar una reserva\n");
        printf("4) Mostrar las reservas de un mes especifico\n");
        printf("5) Calcular las reservas que superen los 2000 pesos\n");
        printf("6) Salir\n");
        scanf(" %d", &opcion);

        switch(opcion){
            case 1: char otro = 's';
            while(otro == 's' || otro == 'S'){
                RegistrarReserva(&lista, &nroreserva);
                printf("\nDesea registrar otra reserva\?: Si(s), No(n)\n");
                scanf(" %c", &otro);
            }
            break;
            case 2: if(ListaVacia(lista)){
                ImprimirReservas(lista);
            }else{
                printf("\nAun no hay reservas registradas\n");
            }
            break;
            case 3: if(ListaVacia(lista)){
                EliminarReserva(&lista);
            }else{
                printf("\nAun no hay reservas registradas\n");
            }
            break;
            case 4: 
            if(ListaVacia(lista)){
                ReservasMes(lista);
            }else{
                printf("\nAun no hay reservas registradas\n");
            }
            break;
            case 5: if(ListaVacia(lista)){
                printf("\nLa cantidad de reservas mayores a 2000 pesos es de %d reservas\n", CalcularReservas2000(lista));
            }else{
                printf("\nAun no hay reservas registradas\n");
            }
            break;
            case 6: if(ListaVacia(lista)){
                LiberarLista(&lista);
            }else{
                printf("\nSaliendo... No hay reservas registradas\n");
            }
            break;
            default: printf("\nNo se ha elegido una opcion valida\n");
            break;
        }
    }while(opcion != 6);
}

void RegistrarReserva(Lista **lista, int *nroreserva){
    srand(time(NULL));

    Lista *nuevo = (void *) malloc(sizeof(Lista));
    if(nuevo != NULL){
        printf("\nIngrese la informacion solicitada sobre la reserva:\n");
        printf("Nombre del titular: ");
        getchar();
        fgets(nuevo->reserva.nombre, 25, stdin);
        nuevo->reserva.nombre[strcspn(nuevo->reserva.nombre, "\n")] = '\0';
        Mayuscula(nuevo->reserva.nombre);
        printf("Precio de la noche: ");
        scanf(" %f", &nuevo->reserva.costonoche);
        nuevo->reserva.nroreserva = (*nroreserva)++;
        nuevo->reserva.cantnoches = rand()%30+1;
        nuevo->reserva.dia = rand()%30+1;
        nuevo->reserva.mes = rand()%12+1;
        nuevo->reserva.nrocabina = rand()%1000+1;
        nuevo->sig = NULL;
        
        if(ListaVacia(*lista) == 0){
            *lista = nuevo;
        }else{
            Lista *aux = *lista;
            while(aux->sig != NULL){
                aux = aux->sig;
            }
            aux->sig = nuevo;
        }
    }else{
        printf("\nNo se ha podido crear la nueva reserva\n");
    }
}

void ImprimirReservas(Lista *lista){
    Lista *aux = lista;

    printf("\nLas reservas hechas hasta el momento son:\n");
    printf("%-25s | %-10s | %-15s | %-15s | %-4s | %-4s | %s\n", "Nombre", "Numero", "Valor noche", "Cant noches", "Dia", "Mes", "Nro cabina");
    while(aux != NULL){
        printf("%-25s | %-10d | %-15.2f | %-15d | %-4d | %-4d | %d\n", aux->reserva.nombre, aux->reserva.nroreserva, aux->reserva.costonoche, 
            aux->reserva.cantnoches, aux->reserva.dia, aux->reserva.mes, aux->reserva.nrocabina);
    aux = aux->sig;
    }

    aux = lista;

    FILE *archivo = fopen("reserva_crucero.txt", "w");

    if(archivo != NULL){
        fprintf(archivo, "%-25s | %-10s | %-15s | %-15s | %-4s | %-4s | %s\n", "Nombre", "Numero", "Valor noche", "Cant noches", "Dia", "Mes", "Nro cabina");
    while(aux != NULL){
        fprintf(archivo, "%-25s | %-10d | %-15.2f | %-15d | %-4d | %-4d | %d\n", aux->reserva.nombre, aux->reserva.nroreserva, aux->reserva.costonoche, 
            aux->reserva.cantnoches, aux->reserva.dia, aux->reserva.mes, aux->reserva.nrocabina);
    aux = aux->sig;
    }
    fclose(archivo);
    printf("\nEl archivo con las reservas registradas ha sido actualizado\n");
    }else{
    printf("\nNo se ha podido crear el archivo con las reservas actualizadas\n");
}
}

void EliminarReserva(Lista **lista){
    Reserva reserva;
    char nombre[25];
    Lista *aux = *lista;
    Lista *ant = NULL;

    printf("\nImgrese el nombre de la persona que hizo la reserva: ");
    getchar();
    fgets(nombre, 25, stdin);
    nombre[strcspn(nombre, "\n")] = '\0';
    Mayuscula(nombre);

    while(aux != NULL && strcmp(nombre, aux->reserva.nombre) != 0){
        ant = aux;
        aux = aux->sig;
    }
    reserva = aux->reserva;

    if(aux != NULL){
        if(ant == NULL){
            *lista = aux->sig;
        }
        else{
            ant->sig = aux->sig;
        }
        free(aux);
    }
    printf("\nLa reserva que ha sido eliminada fue:\n");
    printf("%-25s | %-10s | %-15s | %-15s | %-4s | %-4s | %s\n", "Nombre", "Numero", "Valor noche", "Cant noches", "Dia", "Mes", "Nro cabina");
    printf("%-25s | %-10d | %-15.2f | %-15d | %-4d | %-4d | %d\n", reserva.nombre, reserva.nroreserva, reserva.costonoche, 
            reserva.cantnoches, reserva.dia, reserva.mes, reserva.nrocabina);
}

void ReservasMes(Lista *lista){
    int mes = 0;
    Lista *aux = lista;
    int bandera = 0;

    printf("\nIngrese el numero del mes de las reservas que desee ver: ");
    scanf(" %d", &mes);
    printf("\nLas reservas registradas en el mes %d son:\n", mes);
    printf("%-25s | %-10s | %-15s | %-15s | %-4s | %-4s | %s\n", "Nombre", "Numero", "Valor noche", "Cant noches", "Dia", "Mes", "Nro cabina");
    while(aux != NULL){
        if(mes == aux->reserva.mes){
           printf("%-25s | %-10d | %-15.2f | %-15d | %-4d | %-4d | %d\n", aux->reserva.nombre, aux->reserva.nroreserva, aux->reserva.costonoche, 
            aux->reserva.cantnoches, aux->reserva.dia, aux->reserva.mes, aux->reserva.nrocabina);
                bandera = 1;
        }
    aux = aux->sig;
    }
    if(bandera == 0){
        printf("\nNo se ha registrado ninguna reserva en el mes %d\n", mes);
    }
}

int CalcularReservas2000(Lista *lista){
    Lista *aux = lista;
    int suma = 0;

    while(aux != NULL){
        if((aux->reserva.cantnoches * aux->reserva.costonoche) > 2000){
            suma++;
        }
        aux = aux->sig;
    }

    if(suma == 0){
        printf("\nNo hay ninguna reserva que supere los 2000\n");
        return 0;
    }
    else{
        return suma;
    }
}

void LiberarLista(Lista **lista){
    while(*lista != NULL){
        Lista *prox = (*lista)->sig;
        free(*lista);
        *lista = prox;
    }
    printf("\nLa lista se ha liberado con exito\n");
}

int ListaVacia(Lista *lista){
    if(lista == 0){
        return 0;
    }else{
        return 1;
    }
}

void Mayuscula(char cadena[25]){
    for(int i = 0; cadena[i] != '\0'; i++){
        cadena[i] = toupper(cadena[i]);
    }
}
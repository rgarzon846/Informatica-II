/*Desarrolla un programa que permita la gestión de reservas en una empresa de cruceros utilizando el TDA pila. 
Para ello cree la/las estructura/s que necesite para almacenar la siguiente información sobre número de reserva (entero), 
nombre del pasajero (cadena), número de cabina (entero), costo por noche (decimal), cantidad de noches (entero), día (entero) y mes (entero) de la reserva. 
Crea un menú de opciones  que se repetirá hasta que el usuario decida finalizar el programa. Este menú debe permitir 
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
#include <time.h>

typedef struct{
    int numreserva;
    char nombre[25];
    int cabina;
    float valornoche;
    int noches;
    int dia;
    int mes;
}Reserva;

typedef struct NodoReserva{
    Reserva reserva;
    struct NodoReserva *sig;
}NodoReserva;

void RegistrarReserva(NodoReserva **, int);
void ImprimirReservas(NodoReserva *);
void BorrarReserva(NodoReserva **);
void ReservasMes(NodoReserva *);
void CalcularReservas(NodoReserva *);
void Liberar(NodoReserva **);
void Menu();

int main(){
    Menu();
    return 0;
}

void Menu(){
    NodoReserva *pila = NULL;
    char opcion = ' ';

    do{
        printf("\n*****MENU*****\n");
        printf("\nIngrese la opcion que desee ejecutar:\n");
        printf("a) Registrar una nueva reserva\n");
        printf("b) Imprimir el listado de reservas hechas hasta el momento (tambien generar archivo)\n");
        printf("c) Borrar la ultima reserva registrada\n");
        printf("d) Mostrar reservas de un mes en especifico\n");
        printf("e) Mostrar cantidad de reservas cuyo total es mayor que 2000 pesos\n");
        printf("f) Salir\n");
        scanf(" %c", &opcion);

        switch(opcion){
            case 'a':
            case 'A': char otra = 's';
            int cont = 0;
            while(otra == 's' || otra == 'S'){
                cont++;
                RegistrarReserva(&pila, cont);
                printf("\nDesea registrar otra reserva\?: Si(s), No(n)\n");
                scanf(" %c", &otra);
            }
            break;
            case 'b':
            case 'B': if(pila != NULL){
                ImprimirReservas(pila);
            }else{
                printf("\nAun no ha ingresado ninguna reserva\n");
            }
            break;
            case 'c':
            case 'C': if(pila != NULL){
                BorrarReserva(&pila);
            }else{
                printf("\nAun no ha ingresado ninguna reserva\n");
            }
            break;
            case 'd':
            case 'D': if(pila != NULL){
                ReservasMes(pila);
            }else{
                printf("\nAun no ha ingresado ninguna reserva\n");
            }
            break;
            case 'e':
            case 'E': if(pila != NULL){
                CalcularReservas(pila);
            }else{
                printf("\nAun no ha ingresado ninguna reserva\n");
            }
            break;
            case 'f':
            case 'F': if(pila != NULL){
                Liberar(&pila);
            }else{
                printf("\nSaliendo del menu, pila vacia\n");
            }
            break;
            default: printf("\nNo se ha ingresado una opcion valida\n");
            break;
        }
    }while(opcion != 'f' && opcion != 'F');
}

void RegistrarReserva(NodoReserva **pila, int cont){
    NodoReserva *nuevo = (NodoReserva *) malloc(sizeof(NodoReserva));
    srand(time(NULL));

    if(nuevo == NULL){
        printf("\nError al cargar nueva reserva\n");
    }else{
        nuevo->sig = NULL;
        printf("Ingrese el nombre de la persona que reservo: ");
        getchar();
        fgets(nuevo->reserva.nombre, 25, stdin);
        nuevo->reserva.nombre[strcspn(nuevo->reserva.nombre, "\n")] = '\0';
        nuevo->reserva.cabina = rand()%100+1;
        nuevo->reserva.dia = rand()%31+1;
        nuevo->reserva.mes = rand()%12+1;
        nuevo->reserva.noches = rand()%31+1;
        /*nuevo->reserva.numreserva = rand()%1000+1;
        NodoReserva *aux = *pila;
        while(aux != NULL){
            if(aux->reserva.numreserva == nuevo->reserva.numreserva){
                nuevo->reserva.numreserva = rand()%1000+1;
                aux = *pila;
            }
            aux = aux->sig;
        } Si queremos que el numero de la reserva sea aleatorio*/ 
        nuevo->reserva.numreserva = cont;
        printf("Ingrese el valor de la noche: ");
        scanf(" %f", &nuevo->reserva.valornoche);
        
        if(*pila == NULL){
            *pila = nuevo;
        }else{
            nuevo->sig = *pila;
            *pila = nuevo;
        }


        printf("\nSe ha registrado la reserva con exito\n");
    }
}

void ImprimirReservas(NodoReserva *pila){
    NodoReserva *aux = pila;

    printf("\nLas reservas registradas hasta el momento son:\n");
    printf("\n%-15s | %-25s | %-15s | %-10s | %-10s | %-3s | %s\n", "Reserva N°", "Nombre", "Cabina N°", "Noches", "Valor", "Dia", "Mes");

    while(aux != NULL){
        printf("%-14d | %-25s | %-14d | %-10d | %-10.2f | %-3d | %d\n", aux->reserva.numreserva, aux->reserva.nombre, aux->reserva.cabina, aux->reserva.noches, 
            aux->reserva.valornoche, aux->reserva.dia, aux->reserva.mes);
            aux = aux->sig;
    }

    aux = pila;
    FILE *archivo = fopen("reserva_crucero.txt", "w");

    if(archivo == NULL){
        printf("\nNo se ha podido abrir el archivo\n");
    }else{
        fprintf(archivo, "%-15s | %-25s | %-15s | %-10s | %-10s | %-3s | %s\n", "Reserva N°", "Nombre", "Cabina N°", "Noches", "Valor", "Dia", "Mes");
        while(aux != NULL){
            fprintf(archivo, "%-14d | %-25s | %-14d | %-10d | %-10.2f | %-3d | %d\n", aux->reserva.numreserva, aux->reserva.nombre, aux->reserva.cabina, aux->reserva.noches, 
            aux->reserva.valornoche, aux->reserva.dia, aux->reserva.mes);
            aux = aux->sig;
        }
        fclose(archivo);
        printf("\nSe ha actualizado el archivo con las reservas registradas hasta el momento\n");

    }
}

void BorrarReserva(NodoReserva **pila){
    NodoReserva *aux = *pila;
    Reserva reserva;
    *pila = aux->sig;
    reserva = aux->reserva;
    free(aux);
    printf("\nSe ha eliminado la reserva:\n");
    printf("\n%-15s | %-25s | %-15s | %-10s | %-10s | %-3s | %s\n", "Reserva N°", "Nombre", "Cabina N°", "Noches", "Valor", "Dia", "Mes");
    printf("%-14d | %-25s | %-14d | %-10d | %-10.2f | %-3d | %d\n", reserva.numreserva, reserva.nombre, reserva.cabina, reserva.noches, 
        reserva.valornoche, reserva.dia, reserva.mes);
}

void ReservasMes(NodoReserva *pila){
    NodoReserva *aux = pila;
    int mes = 0;

    printf("\nIngrese el mes de las reservas que desee ver: ");
    scanf(" %d", &mes);
    printf("\n%-15s | %-25s | %-15s | %-10s | %-10s | %-3s | %s\n", "Reserva N°", "Nombre", "Cabina N°", "Noches", "Valor", "Dia", "Mes");
    while(aux != NULL){
        if(mes == aux->reserva.mes){
         printf("%-14d | %-25s | %-14d | %-10d | %-10.2f | %-3d | %d\n", aux->reserva.numreserva, aux->reserva.nombre, aux->reserva.cabina, aux->reserva.noches, 
            aux->reserva.valornoche, aux->reserva.dia, aux->reserva.mes);
        }
        aux = aux->sig;
    }
}

void CalcularReservas(NodoReserva *pila){
    NodoReserva *aux = pila;
    float total = 0;
    int cont = 0;
    printf("\nLas reservas con un costo total mayor a 2000 pesos son:\n");
    printf("\n%-15s | %-25s | %-15s | %-10s | %-10s | %-3s | %s\n", "Reserva N°", "Nombre", "Cabina N°", "Noches", "Valor", "Dia", "Mes");
    while(aux != NULL){
        total = aux->reserva.noches * aux->reserva.valornoche;
        if(total > 2000){
            cont++;
            printf("%-14d | %-25s | %-14d | %-10d | %-10.2f | %-3d | %d\n", aux->reserva.numreserva, aux->reserva.nombre, aux->reserva.cabina, aux->reserva.noches, 
            aux->reserva.valornoche, aux->reserva.dia, aux->reserva.mes);
        }
        aux = aux->sig;
    }
    printf("\n%d reservas en total\n", cont);
}

void Liberar(NodoReserva **pila){
    while(*pila != NULL){
        NodoReserva *prox = (*pila)->sig;
        free(*pila);
        *pila = prox;
    }
    printf("\nSe ha liberado la pila con exito\n");
}
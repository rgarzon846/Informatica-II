#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct{
    char usuario[25];
    char problema[25];
    int prioridad;
}Ticket;

typedef struct NodoTicket{
    Ticket ticket;
    struct NodoTicket *sig;
}NodoTicket;

void EncolarSolicitud(NodoTicket **, NodoTicket **);
void DesencolarPrimera(NodoTicket **, NodoTicket **);
void MostrarSolicitudes(NodoTicket *);
float PromedioPrioridad(NodoTicket *);
void MostrarPrioridad(NodoTicket *);
void Liberar(NodoTicket **, NodoTicket **);
int ColaVacia(NodoTicket *);
void Menu();

int main(){
    srand(time(NULL));
    Menu();
    return 0;
}

void Menu(){
    NodoTicket *frente = NULL;
    NodoTicket *fin = NULL;
    char opcion = ' ';

    do{
        printf("\n*****MENU DE SOLICITUDES*****\n");
        printf("\nIngrese la opcion que desee ejecutar\n");
        printf("a) Registrar una nueva solicitud\n");
        printf("b) Eliminar la primera solicitud ingresada\n");
        printf("c) Mostrar Solicitudes pendientes\n");
        printf("d) Mostrar solicitudes con mayor y con menor prioridad\n");
        printf("e) Calcular y mostrar el promedio de la suma de prioridades\n");
        printf("f) Salir\n");
        scanf(" %c", &opcion);

        switch(opcion){
            case 'a':
            case 'A': char otra = 's';
            while(otra == 's' || otra == 'S'){
                EncolarSolicitud(&frente, &fin);
                printf("\nDesea registrar otra solicitud\?: Si(s), No(n)\n");
                scanf(" %c", &otra);
            }
            break;
            case 'b':
            case 'B': if(ColaVacia(frente)){
                DesencolarPrimera(&frente, &fin);
            }else{
                printf("\nAun no se han registrado solicitudes\n");
            }
            break;
            case 'c':
            case 'C': if(ColaVacia(frente)){
                MostrarSolicitudes(frente);
            }else{
                printf("\nAun no se han registrado solicitudes\n");
            }
            break;
            case 'd':
            case 'D': if(ColaVacia(frente)){
                MostrarPrioridad(frente);
            }else{
                printf("\nAun no se han registrado solicitudes\n");
            }
            break;
            case 'e':
            case 'E': if(ColaVacia(frente)){
                printf("\nEl promedio de la suma de prioridades es: %.2f", PromedioPrioridad(frente));
            }else{
                printf("\nAun no se han registrado solicitudes\n");
            }
            break;
            case 'f':
            case 'F': if(ColaVacia(frente)){
                Liberar(&frente, &fin);
            }else{
                printf("\nSaliendo... Ninguna solicitud registrada\n");
            }
            break;
            default: printf("\nNo se ha ingresado una opcion valida\n");
        }
        }while(opcion != 'f' && opcion != 'F');
}

void EncolarSolicitud(NodoTicket **frente, NodoTicket **fin){
    NodoTicket *nuevo = (NodoTicket *) malloc(sizeof(NodoTicket));

    if(nuevo == NULL){
        printf("\nNo se ha podido crear el nuevo nodo\n");
    }else{
        nuevo->sig = NULL;
        nuevo->ticket.prioridad = rand()%5+1;
        printf("Ingrese el nombre de usuario: ");
        getchar();
        fgets(nuevo->ticket.usuario, 25, stdin);
        nuevo->ticket.usuario[strcspn(nuevo->ticket.usuario, "\n")] = '\0';
        printf("Ingrese el problema a atender: ");
        fgets(nuevo->ticket.problema, 25, stdin);
        nuevo->ticket.problema[strcspn(nuevo->ticket.problema, "\n")] = '\0';

        if(ColaVacia(*fin) == 0){
            *frente = nuevo;
            *fin = nuevo;
        }else{
            (*fin)->sig = nuevo;
            *fin = nuevo;
        }

        printf("\nSolicitud registrada con exito\n");
    }
}

void DesencolarPrimera(NodoTicket **frente, NodoTicket **fin){
    NodoTicket *aux = *frente;
    Ticket ticket = aux->ticket;
    *frente = aux->sig;
    free(aux);
    if(ColaVacia(*frente) == 0){
        *fin == NULL;
    }
    printf("\nSe elimino la solicitud:\n");
    printf("%-25s | %-25s | %s\n", "Usuario", "Problema", "Prioridad");
    printf("%-25s | %-25s | %d\n", ticket.usuario, ticket.problema, ticket.prioridad);
}

void MostrarSolicitudes(NodoTicket *frente){
    NodoTicket *aux = frente;

    printf("\nLas solicitudes pendientes son:\n\n");
    printf("%-25s | %-25s | %s\n", "Usuario", "Problema", "Prioridad");
    while(aux != NULL){
        printf("%-25s | %-25s | %d\n", aux->ticket.usuario, aux->ticket.problema, aux->ticket.prioridad);
        aux = aux->sig;
    }
}


float PromedioPrioridad(NodoTicket *frente){
    NodoTicket *aux = frente;
    int suma = 0;
    int cont = 0;

    while(aux != NULL){
        suma += aux->ticket.prioridad;
        cont++;
        aux = aux->sig;
    }
    return suma/cont;
}


void MostrarPrioridad(NodoTicket *frente){
    NodoTicket *aux = frente;
    int mayor = 0;
    int menor = aux->ticket.prioridad + 1;
    Ticket ticketmenor;
    Ticket ticketmayor;

    while(aux != NULL){
        if(aux->ticket.prioridad < menor){
            menor = aux->ticket.prioridad;
            ticketmenor = aux->ticket;
        }if(aux->ticket.prioridad > mayor){
            mayor = aux->ticket.prioridad;
            ticketmayor = aux->ticket;
        }
        aux = aux->sig;
    }

    printf("\nLa solicitud de mayor prioridad es:\n");
    printf("%-25s | %-25s | %s\n", "Usuario", "Problema", "Prioridad");
    printf("%-25s | %-25s | %d\n", ticketmenor.usuario, ticketmenor.problema, ticketmenor.prioridad);
    printf("\nLa solicitud de menor prioridad es:\n");
    printf("%-25s | %-25s | %s\n", "Usuario", "Problema", "Prioridad");
    printf("%-25s | %-25s | %d\n", ticketmayor.usuario, ticketmayor.problema, ticketmayor.prioridad);
}

void Liberar(NodoTicket **frente, NodoTicket **fin){
    while(*frente != NULL){
        NodoTicket *prox = (*frente)->sig;
        free(*frente);
        *frente = prox;
    }
    *fin = NULL;
    printf("\nSe ha liberado la cola con exito\n");
}

int ColaVacia(NodoTicket *fin){
    if(fin == NULL){
        return 0;
    }else{
        return 1;
    }
}

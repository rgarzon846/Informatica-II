/*Crear un programa con el siguiente menu de opciones: 
- Agregar un nodo a la cola. (se deben agregar 5 valores)
- Borrar el primer nodo de la cola.
- Imprimir cola.
- Suma de los valores de la cola.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
    float valor;
    struct Nodo *sig;
}Nodo;

void Menu();
void Agregar(Nodo **, Nodo**);
void Borrar(Nodo **, Nodo **);
void Imprimir(Nodo *);
float Sumar(Nodo *);
void Liberar(Nodo **);

int main(){
    Menu();
    return 0;
}

void Menu(){
    Nodo *frente = NULL;
    Nodo *fin = NULL;
    char opcion = ' ';
    char volver = 's';
    do{
        printf("\nIngrese la opcion que desee ejecutar:\n");
        printf("a. Agregar valores a la cola\n");
        printf("b. Borrar el primer valor ingresado\n");
        printf("c. Imprimir la cola\n");
        printf("d. Sumar todos los valores de la cola\n");
        scanf(" %c", &opcion);

        switch(opcion){
            case 'a':
            case 'A': Agregar(&frente, &fin);
            break;
            case 'B':
            case 'b': Borrar(&frente, &fin);
            break;
            case 'c':
            case 'C': Imprimir(frente);
            break;
            case 'd':
            case 'D': printf("El resultado de la suma de todos los valores de la cola es: %.2f\n", Sumar(frente));
            break;
            default: printf("\nNo se ha ingresado una opcion valida\n");
            break;
        }
        printf("\nDesea volver al menu\?: Si(s), No(n)\n");
        scanf(" %c", &volver);
    }while(volver == 's' || volver == 'S');
    Liberar(&frente);
}

void Agregar(Nodo **frente, Nodo **fin){
    float valor = 0;
    for(int i = 0; i < 5; i++){
        printf("\nIngrese el valor que desee: ");
        scanf(" %f", &valor);
        Nodo *nuevo = (Nodo *) malloc(sizeof(Nodo));
        nuevo->valor = valor;
        nuevo->sig = NULL;
        if(*fin == NULL){
            *frente = nuevo;
            *fin = nuevo;
        }else{
            (*fin)->sig = nuevo;
            *fin = nuevo;
            }
        }
}

void Borrar(Nodo **frente, Nodo **fin){
    if(*frente == NULL){
        printf("\nLa lista esta vacia\n");
    }else{
    Nodo *aux = *frente;
    float valor = aux->valor;
    *frente = aux->sig;
    free(aux);
    if(*frente == NULL){
        *fin == NULL;
    }
    printf("\nSe ha eliminado el valor %.2f\n", valor);
}
}

void Imprimir(Nodo *frente){
    Nodo *aux = frente;
    printf("\nLos valores de la cola son:\n");
    if(aux == NULL){
        printf("\nLa cola esta vacia\n");
    }
    while(aux != NULL){
        printf("%.2f\n", aux->valor);
        aux = aux->sig;
    }
}


float Sumar(Nodo *frente){
    Nodo *aux = frente;
    if(aux == NULL){
        printf("\nLa cola esta vacia\n");
    }
    float suma = 0;
    while(aux != NULL){
        suma += aux->valor;
        aux = aux->sig;
    }
    return suma;
}

void Liberar(Nodo **frente){
    while(*frente != NULL){
        Nodo *prox = (*frente)->sig;
        free(*frente);
        *frente = prox;
    }
    printf("\nLa lista se ha eliminado con exito\n");
}
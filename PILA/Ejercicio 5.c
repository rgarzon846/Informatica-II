/*Desarrolle un programa que cargue una pila de números enteros aleatorios.  Luego realice un menú de opciones:
- Agregar un nodo a la pila. (cuando agrega un valor, el mismo no tiene que estar repetido en la pila)
- Borrar el último nodo de la pila.
- Imprimir pila.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Nodo{
    int valor;
    struct Nodo *sig;
}Nodo;

void Menu();
void Agregar(Nodo **);
void Borrar(Nodo **);
void Imprimir(Nodo *);
void Liberar(Nodo **);

int main(){

    return 0;
}

void Menu(){
    Nodo *p = NULL;
}

void Agregar(Nodo **p){
    srand(time(NULL));
    int cant = 0;
    printf("Cuantos valores desea que la pila contenga\?: ");
    scanf(" %d", &cant);
    for(int i = 0; i < cant; i++){
    Nodo *nuevo = (Nodo *) malloc(sizeof(Nodo));
    nuevo->valor = rand()%100+1;
    nuevo->sig = NULL;

    if(nuevo != NULL){
        if(*p == NULL){
            *p = nuevo;
        }else{
            Nodo *aux = *p;
            while(aux != NULL){
                if(aux->valor == nuevo->valor){
                    nuevo->valor = rand()%100+1;
                    aux = *p;
                }
                aux = aux->sig;
            }
            aux = *p;
            while(aux->sig != NULL){
                aux = aux->sig;
            }
            aux->sig = nuevo;
        }
    }else{
        printf("\nNo se ha podido crear el nuevo nodo\n");
    }
    }
}

void Borrar(Nodo **p){
    Nodo *aux = *p;
    Nodo *ant = NULL;

    while(aux->sig != NULL){
        ant = aux;
        aux = aux->sig;
    }
    printf("\nSe ha eliminado el ultimo nodo que contenia el valor: %d\n", aux->valor);
    free(aux);
    ant->sig = NULL;
}

void Imprimir(Nodo *p){
    Nodo *aux = p;

    printf("\nLos valores de la pila son:\n");
    while(aux != NULL){
        printf("%d\n", aux->valor);
        aux = aux->sig;
    }
}
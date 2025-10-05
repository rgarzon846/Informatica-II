/*Crear un programa con el siguiente menú de opciones: 
- Agregar un nodo a la pila. (se deben agregar 5 valores)
- Borrar el último nodo de la pila.
- Imprimir pila.
- Tamaño de la pila
- Mostrar el último valor de la pila
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
    float valor;
    struct Nodo *sig;
}Nodo;

void Menu();
void Agregar(Nodo **);
void Borrar(Nodo **);
void Imprimir(Nodo *);
void Tamanio();
void MostrarUltimo(Nodo *);

int main(){

    return 0;
}

void Menu(){
    Nodo *p = NULL;
}

void Agregar(Nodo **p){
    for(int i = 0; i < 5; i++){
        Nodo *nuevo = (Nodo *) malloc(sizeof(Nodo));
        if(nuevo != NULL){
            printf("Ingrese un valor: ");
            scanf(" %f", &nuevo->valor);
            nuevo->sig = NULL;
            if(*p == NULL){
                *p = nuevo;
            }else{
                Nodo *aux = *p;
                while(aux->sig != NULL){
                    aux = aux->sig;
                }
                aux->sig = nuevo;
            }
        }else{
            printf("\nNo se ha podido crear el nodo\n");
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
    printf("\nSe ha eliminado el ultimo nodo que contenia el valor: %.2f", aux->valor);
    free(aux);
    ant->sig = NULL;
}

void Imprimir(Nodo *p){
    Nodo *aux = p;
    printf("\nLa pila contiene los siguientes valores:\n");
    while(aux != NULL){
        printf("%.2f\n", aux->valor);
        aux = aux->sig;
    }
}

void Tamanio(){
    printf("\nEl tamaño en bytes de la pila es de %zu", (5 * sizeof(Nodo)));
}
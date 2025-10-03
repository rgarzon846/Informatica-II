/*Crear un programa en el cual se solicite al usuario el ingreso de 
5 valores numéricos y luego muestre la lista. Crear una función que inserte valor y otra para imprimir la lista.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
    float valor;
    struct Nodo *sig;
}Nodo;

void Agregar(Nodo **, float);
void Mostrar(Nodo *);
void Liberar(Nodo **);

int main(){
    Nodo *p = NULL;
    float valor = 0;
    for(int i = 0; i < 5; i++){
    printf("\nIngrese un valor numerico\n");
    scanf(" %f", &valor);
    Agregar(&p, valor);
    }
    Mostrar(p);
    Liberar(&p);
    return 0;
}

void Agregar(Nodo **p, float valor){
    Nodo *nuevo = (Nodo *) malloc(sizeof(Nodo));
    nuevo->valor = valor;
    nuevo->sig = NULL;

    if(nuevo != NULL){
        if(*p == NULL){
            *p = nuevo;
        }
        else{if(*p != NULL){
            Nodo *aux = *p;
            while(aux->sig != NULL){
                aux = aux->sig;
            }
            aux->sig = nuevo;
        }
    }
    }else{
        printf("\nError al crear nodo\n");
    }
}

void Mostrar(Nodo *p){
    Nodo *aux = p;
    while(aux != NULL){
        printf("%.2f\n", aux->valor);
        aux = aux->sig;
    }
}

void Liberar(Nodo **p){
    
    while(*p != NULL){
        Nodo *prox = (*p)->sig;
        free(*p);
        *p = prox;
    }
    printf("\nSe ha liberado la lista con exito\n");
}







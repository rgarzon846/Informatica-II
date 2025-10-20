/*Crear un programa con el siguiente menú de opciones: 
- Agregar un nodo a la cola.
- Borrar el primer nodo de la cola.
- Imprimir cola.
- Cantidad de nodos en la cola.
- Cantidades de letras mayúsculas y minúsculas en la cola.

El usuario cargará la cola con letras mayúsculas o minúsculas. 

Nota: Las letras en ASCII mayúsculas están entre el 65 a 90 y las minúsculas entre  97 a 122 inclusive.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
    char letra;
    struct Nodo *sig;
}Nodo;

void Menu();
void Agregar(Nodo **, Nodo **);
void Borrar(Nodo **, Nodo **);
void Imprimir(Nodo *);
int CantNodos(Nodo *);
void CantMayMin(Nodo *);
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
        printf("a. Agregar una letra a la cola\n");
        printf("b. Borrar la ultima letra de la cola\n");
        printf("c. Imprimir la cola\n");
        printf("d. Mostrar la cantidad de nodos de la cola\n");
        printf("e. Mostrar la cantidad de mayusculas y minusculas de la cola\n");
        scanf(" %c", &opcion);

        switch(opcion){
            case 'A':
            case 'a': char otro = 's';
            while(otro == 's' || otro == 'S'){
                Agregar(&frente, &fin);
                printf("Desea ingresar otra letra\?: Si(s), No(n)\n");
                scanf(" %c", &otro);
            }
            break;
            case 'B':
            case 'b': if(frente != NULL){
                Borrar(&frente, &fin);
            }else{
                printf("\nDebe ingresar letras\n");
            }
            break;
            case 'C':
            case 'c': if(frente != NULL){
                Imprimir(frente);
            }else{
                printf("\nDebe ingresar letras\n");
            }
            break;
            case 'd':
            case 'D': if(frente != NULL){
                printf("\nLa cantidad de nodos ingresados es de: %d nodos\n", CantNodos(frente));
            }else{
                printf("\nDebe ingresar letras\n");
            }
            break;
            case 'E':
            case 'e': if(frente != NULL){
                CantMayMin(frente);
            }else{
                printf("\nDebe ingresar letras\n");
            }
            break;
            default: printf("\nNo ha ingresado una opcion valida\n");
        }
        printf("\nDesea volver al menu\?: Si(s), No(n)\n");
        scanf(" %c", &volver);

    }while(volver == 's' || volver == 'S');

    Liberar(&frente);
}

void Agregar(Nodo **frente, Nodo **fin){
    Nodo *nuevo = (Nodo *) malloc(sizeof(Nodo));

    if(nuevo != NULL){
        printf("\nIngrese una letra: ");
        scanf(" %c", &nuevo->letra);
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
    Nodo *aux = *frente;
    char letra = aux->letra;

    *frente = aux->sig;
    if(*frente == NULL){
        *fin = NULL;
    }
    free(aux);
    printf("\nSe ha eliminado la letra del primer nodo: %c\n", letra);
}

void Imprimir(Nodo *frente){
    Nodo *aux = frente;
    printf("\nLa cola contiene las letras: ");
    while(aux != NULL){
        printf("%c-> ", aux->letra);
        if(aux->sig == NULL){
            printf("NULL");
        }
        aux = aux->sig;
    }
}

int CantNodos(Nodo *frente){
    Nodo *aux = frente;
    int cant = 0;
    while(aux != NULL){
        cant++;
        aux = aux->sig;
    }
    return cant;
}

void CantMayMin(Nodo *frente){
    Nodo *aux = frente;
    int may = 0;
    int min = 0;

    while(aux != NULL){
        if(aux->letra >= 65 && aux->letra <= 90){
            may++;
        }
        if(aux->letra >= 97 && aux->letra <= 122){
            min++;
        }
        aux = aux->sig;
    }

    printf("\nLa cantidad de MAYUSCULAS en la cola es de %d MAYUSCULAS\n", may);
    printf("La cantidad de minusculas de la cola es de %d minusculas\n", min);
}

void Liberar(Nodo **frente){
    while(*frente != NULL){
        Nodo *prox = (*frente)->sig;
        free(*frente);
        *frente = prox;
    }
    printf("\nSe ha eliminado la cola con exito\n");
}
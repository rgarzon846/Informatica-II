/*Crear un programa en la cual contenga un menú de opciones con distintas operaciones:
Reserva de memoria e introducción de datos enteros
Agregar reserva de memoria e introducción de nuevos datos enteros
Mostrar los datos en el orden y orden invertido al que fueron introducidos
*/

#include <stdio.h>
#include <stdlib.h>

void Menu();
void ReservaMemoria(int *, int);
void AgregarMemoria(int *, int *, int, int);
void Mostrar(int *, int, int);

int main(){
Menu();
    return 0;
}

void Menu(){
    int *p = NULL;
    int cant = 0;
    int cant2 = 0;
    char opcion = ' ';
    char volver = 's';

    do{
    printf("Ingrese la opcion que desee ejecutar:\n");
    printf("a. Reservar memoria e introducir datos enteros\n");
    printf("b. Agregar memoria e introducir nuevos datos enteros\n");
    printf("c. Mostrar datos en el orden y en el orden invertido al que fueron introducidos\n");
    scanf(" %c", &opcion);

    switch(opcion){
        case 'A':
        case 'a': 
        printf("Ingrese la cantidad de enteros que desea almacenar:\n");
        scanf(" %d", &cant);
        p = (int *) malloc(cant * sizeof(int));
        ReservaMemoria(p, cant); break;
        case 'B':
        case 'b': 
            int *p2 = NULL;
            printf("Ingrese la cantidad de datos que desea agregar:\n");
            scanf(" %d", &cant2);
            p2 = realloc(p, cant2 * sizeof(int));
            AgregarMemoria(p, p2, cant2, cant);
            break;
        case 'C':
        case 'c': 
        Mostrar(p, cant, cant2);
        }
        break;
        default: printf("No ha elegido una opcion correcta\n"); break;
    }
    printf("Desea volver al menu\?: Si(S), No(N)\n");
    scanf(" %c", &volver);
    }while (volver == 'S' || volver == 's');
    
    free(p);
    p = NULL;
}

void ReservaMemoria(int *p, int cant){
    if(p == NULL){
        printf("Error al reservar memoria");
    }else{
    printf("Introduzca los valores que desee almacenar:\n");
    for(int i = 0; i < cant; i++){
        scanf(" %d", &*(p+i));
    }
    printf("Los datos se han almacenado con exito\n");
}
}

void AgregarMemoria(int *p, int *p2, int cant2, int cant){
    if(p2 == NULL){
        printf("Error al agregar memoria");
        free(p);
    }
        p = p2;
        printf("Ingrese los datos que desea agregar:\n");
        for(int i = cant; i < cant+cant2; i++){
            scanf(" %d", &*(p+i));
        }
        printf("Los datos se han agregado con exito\n");
    
}

void Mostrar(int *p, int cant, int cant2){
    int aux = 0;
    printf("Los datos en orden que se introdujeron son:\n");
    for(int i = 0; i < cant+cant2; i++){
        printf("%d\t", *(p+i));
    }
    printf("\n");
    
    printf("Los datos en el orden inverso que se introdujeron son:\n");
    for(int i = 0; i < (cant+cant2)/2; i++){
        aux = *(p+i);
        *(p+i) = *(p+cant+cant2-1-i);
        *(p+cant+cant2-1-i) = aux;
    }
    for(int i = 0; i < cant+cant2; i++){
        printf("%d\t", *(p+i));
    }
    printf("\n");
}
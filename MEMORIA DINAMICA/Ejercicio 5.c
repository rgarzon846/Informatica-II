/*Modificar el código para crear una función mostrar los valores.*/

#include <stdio.h>
#include <stdlib.h>

void Mostrar(char *, int, int);

int main(){
int cant = 0;
int cant2 = 0;
char *p = NULL;
char *p2 = NULL;

printf("Ingrese la cantidad de caracteres que desea almacenar:\n");
scanf(" %d", &cant);

p = (char *) malloc(cant * sizeof(char));

if(p == NULL){
    printf("Error al reservar memoria\n");
    return 1;
}else{
    printf("Ingrese los caracteres que desea almacenar:\n");
    for(int i = 0; i < cant; i++){
        scanf(" %c", &*(p+i));
    }
    Mostrar(p, cant, cant2);

    printf("Ingrese la cantidad de caracteres que desea agregar:\n");
    scanf(" %d", &cant2);

    p2 = (char *) realloc(p, cant2*sizeof(char));

    if(p2 == NULL){
        printf("Error al ampliar la memoria\n");
        free(p);
        return 1;
    }

    p = p2;
    printf("Ingrese los caracteres que desea agregar:\n");
    for(int i = cant; i < cant + cant2; i++){
        scanf(" %c", &*(p+i));
    }
    Mostrar(p, cant, cant2);

    free(p);
    p = NULL;
}
    return 0;
}

void Mostrar(char *p, int cant, int cant2){
    for(int i = 0; i < cant + cant2; i++){
        printf("%c\t", *(p+i));
    }
    printf("\n");
}
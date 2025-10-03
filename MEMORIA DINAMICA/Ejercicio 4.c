/*Cree un programa que permita reservar memoria para n caracteres (char). 
Luego cargar los n caracteres e imprimirlos por pantalla. El usuario desea agregar mas caracteres, 
por lo que ingresa la n cantidad de caracteres a agregar. Luego cargar los n caracteres, imprimirlos y finalmente liberar la memoria.*/

#include <stdio.h>
#include <stdlib.h>

int main(){
int cant = 0;
int cant2 = 0;
char *p = NULL;
char *p2 = NULL;

printf("Ingrese la cantidad de caracteres que desea almacenar:\n");
scanf(" %d", &cant);

p = (char *) malloc(cant * sizeof(char));

if(p == NULL){
    printf("El espacio no se ha podido reservar\n");
    return 1;
}else{
    printf("Ingrese los caracteres que desea almacenar:\n");
    for(int i = 0; i < cant; i++){
        scanf(" %c", &*(p+i));
    }
    printf("Los valores ingresados son:\n");
    for(int i = 0; i < cant; i++){
        printf("%c\t", *(p+i));
    }
    printf("\n");
    printf("Ingrese la cantidad de caracteres que desea agregar:\n");
    scanf(" %d", &cant2);

    p2 = realloc(p, cant2 * sizeof(char));

    if(p2 == NULL){
        printf("Error al ampliar la memoria\n");
        free(p);
        return 1;
    }
        p = p2;
        printf("Ingrese los caracteres que desea agregar:\n");
        for(int i = cant; i < cant+cant2; i++){
            scanf(" %c", &*(p+i));
        }
        printf("Los caracteres almacenados hasta el momento son:\n");
        for(int i = 0; i < cant + cant2; i++){
            printf("%c\t", *(p+i));
        }
        printf("\n");
        free(p);
        p = NULL;
}
    return 0;
}
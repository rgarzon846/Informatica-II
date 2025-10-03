/*Cree un programa que permita reservar memoria para n caracteres (char). Luego cargar los n caracteres e imprimirlos por pantalla.*/

#include <stdio.h>
#include <stdlib.h>

int main(){
int cant = 0;
char *p = NULL;

printf("Ingrese la cantidad de caracteres que desea almacenar:\n");
scanf(" %d", &cant);

p = (char *) malloc(cant * sizeof(char));

if(p == NULL){
    printf("Error al reservar memoria\n");
    return 1;
}else{
    printf("Ingrese los caracteres que desee almacenar:\n");
    for(int i = 0; i < cant; i++){
        scanf(" %c", &*(p+i));
    }
    printf("Los caracteres almacenados son:\n");
    for(int i = 0; i < cant; i++){
        printf("%c\t", *(p+i));
    }
    printf("\n");

    free(p);
    p = NULL;
}
    return 0;
}
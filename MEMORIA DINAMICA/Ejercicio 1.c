/*Cree un programa que permita reservar memoria para n valores enteros. Luego cargar los n valores, imprimirlos y liberar la memoria.*/

#include <stdio.h>
#include <stdlib.h>

int main(){
int *p = NULL;
int cant = 0;
int n = 0;

printf("Ingrese la cantidad de valores que desea almacenar:\n");
scanf(" %d", &cant);

p = (int *) malloc(cant*sizeof(int));
if(p == NULL){
    printf("El espacio de memoria requerido no esta disponible\n");
    return 1;
}else{
    printf("Ingrese los valores que desee:\n");
    for(int i = 0; i < cant; i++){
        scanf(" %d", &n);
        *(p+i) = n;
    }
    printf("Los valores son:\n");
    for(int i = 0; i < cant; i++){
        printf("%d\t", *(p+i));
    }
    printf("\n");
    free(p);
    p = NULL;
}
    return 0;
}
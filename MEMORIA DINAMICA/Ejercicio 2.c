/*Cree un programa que permita reservar memoria para n valores decimales (float). 
Luego cargar los n valores, imprimirlos y liberar la memoria.
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
float *p = NULL;
int cant = 0;


printf("Ingrese la cantidad de valores que desea ingreasar:\n");
scanf(" %d", &cant);

p = (float *) malloc(cant * sizeof(float));

if(p == NULL){
printf("Error al guardad espacio de memoria:\n");
return 1;
}else{
    printf("Ingrese los valores que desee:\n");
    for(int i = 0; i < cant; i++){
        scanf(" %f", &*(p+i));
    }
    printf("Los valores ingresados son:\n");
    for(int i = 0; i < cant; i++){
        printf(" %.2f\t", *(p+i));
    }
    printf("\n");

    free(p);
    p = NULL;
}
    return 0;
}
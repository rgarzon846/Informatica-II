/*Escribir una función que intercambie el valor de dos variables enteras usando punteros. La función debe tener la siguiente firma: void swap(int *a, int *b).*/

#include <stdio.h>

void swap(int *, int *);

int main(){
    int B = 0;
    int A = 0;
    printf("Ingrese dos valores que desee intercambiar entre si:\n");
    scanf(" %d", &A);
    scanf(" %d", &B);    
    swap(&A, &B);
    return 0;
}

void swap(int *a, int *b){
    int aux = 0;
    printf("a = %d, b = %d\n", *a, *b);
    aux = *a;
    *a = *b;
    *b = aux;
    printf("Las variables intercambiadas son: \na = %d, b= %d", *a, *b);
}
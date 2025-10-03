/*Escribir un programa que declare una variable de cada tipo (int, float, char), un puntero de cada tipo de la variable creada, 
inicialice la variable e inicialice el puntero para que apunte a las variables creadas. Luego que imprima por pantalla para cada tipo lo siguiente: 
La dirección de memoria de la variable.
El valor que almacena la variable.
El valor del puntero.
El valor al que apunta el puntero.*/

#include <stdio.h>

int main(){
int a = 10;
float b = 6.3;
char c = 'm';
int *A = &a;
float *B = &b;
char *C = &c;

printf("La direccion de memoria de a = %d, la direccion de memoria de b = %d, la direccion de memoria de c = %d", A, B, C);
printf("El valor de a es: %d, el valor de b es: %.2f, el valor de c es: %c\n", a, b, c);
printf("El valor de *A es: %d, el valor de *B es: %d, el valor de *C es: %d\n", A, B, C);
printf("El valor al que apunta *A es: %d, el valor al que apunta *B es: %.2f, el valor al que apunta *C es: %c\n", *A, *B, *C);


    return 0;
}
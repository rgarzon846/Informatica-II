/*Declarar una variable de cada tipo (int, float, char), un puntero de cada tipo de variable creada y 
asignarles las direcciones de memoria de cada variable creada. Luego, modificar el valor de cada variable utilizando 
el puntero y mostrar por pantalla el nuevo valor de cada una de las variables.*/

#include <stdio.h>

int main(){
int a = 50;
float b = 7.58;
char c = 'r';
int *A = &a;
float *B = &b;
char *C = &c;

printf("Los valores de las variables antes de ser modificados son: a = %d, b = %.2f, c = %c\n", a, b, c);

*A = 30;
*B = 93.57;
*C = 'e';

printf("Los valores de las variables despues de ser modificados son: a = %d, b = %.2f, c = %c\n", a, b, c);

    return;
}
/*Escribir una función que reciba dos números enteros por valor y los reste, y otra función que reciba dos punteros a enteros y 
los reste utilizando de punteros. Luego, desde el programa principal, solicitar al usuario que ingrese dos números enteros, 
llamar a ambas funciones para restarlos e imprimir el resultado obtenido en cada caso.*/

#include <stdio.h>

int Sumar(int *, int *);
int Restar(int *, int *);

int main(){
int num1 = 0;
int num2 = 0;

printf("Ingrese los dos numeros a sumar y restar:\n");
scanf(" %d", &num1);
scanf(" %d", &num2);

printf("El resultado de la suma es: %d\n", Sumar(&num1, &num2));
printf("El resultado de la resta es: %d\n", Restar(&num1, &num2));
    
return 0;
}

int Sumar(int *NUM1, int *NUM2){
    int total = 0;
    total = *NUM1 + *NUM2;
    return total;
}
int Restar(int *NUM1, int *NUM2){
    int total = 0;
    total = *NUM1 - *NUM2;
    return total;
}
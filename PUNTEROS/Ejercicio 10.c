/*Realice un programa que permita cargar 10 números enteros en un vector. 
Luego utilizando punteros calcule el promedio de ellos. Finalmente mostrar todos los valores y su promedio utilizando punteros.*/

#include <stdio.h>

int main(){
int v[10] = {0};
int *p = &v;
int suma = 0;
float promedio = 0;
printf("Ingrese 10 valores enteros:\n");

for(int i = 0; i < 10; i++){
scanf(" %d", &*(p+i));
suma += *(p+i);
}
promedio = (float) suma/10;
printf("\nLos valores ingresados son: ");
for(int i = 0; i< 10; i++){
printf("%d\t", *(p+i));
}
printf("\nEl promedio de los valores ingresados es: %.2f", promedio);
    return 0;
}
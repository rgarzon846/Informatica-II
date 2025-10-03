/*Desarrolle un programa que declare e inicialice un vector de 5 valores (4.5,8,2.3,1.1,3). 
Luego, se pide que calcule y muestre la sumatoria y el promedio. 
Utilice punteros para realizar el ejercicio.*/

#include <stdio.h>

int main(){
    float A[5] = {4.5,8.0,2.3,1.1,3.0};
    float *a = &A;
    float suma = 0;
    float promedio = 0;
    
    for(int i = 0; i < 5; i++){
        suma += *(a+i);
    }

    promedio = suma/5;

    printf("La sumatoria de los valores es: %.2f\n", suma);
    printf("El promedio del array es: %.2f\n", promedio);

    return 0;
}

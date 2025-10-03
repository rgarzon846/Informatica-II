/*Desarrolle un programa que declare e inicialice un vector de 5 valores aleatorios. Luego, crear 3 funciones que permitan hallar el valor máximo, 
mínimo y la sumatoria de ellos. Finalmente mostrar los resultados. Utilice punteros para realizar el ejercicio.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Maximo(int *);
int Minimo(int *);
int Suma(int, int);

int main(){
srand(time(NULL));
int a[5];

for(int i = 0; i < 5; i++){
    *(a+i) = rand()%100+1;
}

printf("El valor mas alto del array es: %d\n", Maximo(a));
printf("El valor mas pequeño del arreglo es: %d\n", Minimo(a));
printf("La suma de ambos valores es: %d\n", Suma(Maximo(a), Minimo(a)));

    return 0;
}

int Maximo(int *a){
    int maximo = *(a);

    for(int i = 0; i < 5; i++){
        if(maximo < *(a+i)){
            maximo = *(a+i);
        }
    }

    return maximo;
}

int Minimo(int *a){
    int minimo = *(a);

    for(int i = 0; i < 5; i++){
        if(minimo > *(a+i)){
            minimo = *(a+i);
        }
    }

    return minimo;
}

int Suma(int maximo, int minimo){
    return maximo + minimo;
}
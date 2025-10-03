/*Desarrolle un programa que declare e inicialice un arreglo de 2x3 con valores aleatorios. 
Luego mostrar los valores. Utilice punteros para realizar el ejercicio.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
int m[2][3];
srand(time(NULL));

for(int i = 0; i < 2; i++){
    for(int j = 0; j < 3; j++){
        *(*(m+i)+j) = rand()%100+1;
    }
}

for(int i = 0; i < 2; i++){
    for(int j = 0; j < 3; j++){
        printf("%d\t", *(*(m+i)+j));
    }
    printf("\n");
}
    return 0;
}
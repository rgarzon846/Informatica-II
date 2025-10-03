#include <stdio.h>

int main(){
int nota1 = 0;
int nota2 = 0;
int nota3 = 0;
float promedio = 0;

printf("Cargue las tres notas de los alumnos:\n");
scanf(" %d", nota1);
scanf(" %d", nota2);
scanf(" %d", nota3);

promedio = (float)(nota1 + nota2 + nota3)/3;

printf("\nEl promedio de las tres notas es: %.2f", promedio);

    return 0;
}
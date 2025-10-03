/*Desarrollar el ejercicio anterior con funciones. Crear una función que pase los valores a mayúsculas y una función que pase los valores a minúsculas. 
Desarrollar un programa que declare e inicialice un vector tipo char con el abecedario. Luego mostrar en pantalla el abecedario en mayuscula y 
minuscula,  utilizando punteros. Nota: la función para pasar a mayúscula es toupper() y a minúsculas es tolower(). 
Ejemplo: cadena[i] = tolower(cadena[i]); En código ASCII A=65*/

#include <stdio.h>
#include <ctype.h>

void Mayuscula(char *);
void Minuscula(char *);

int main(){
char ABC[26] = {' '};
char *abc = &ABC;

Mayuscula(&abc);
Minuscula(&abc);
    return 0;
}

void Mayuscula(char *abc){
int pos = 0;

printf("El aecedario en mayusculas es: ");
for(int i = 0; i < 26; i++){
    pos = 65+i;
    *(abc+i) = pos;
    printf("%c", *(abc+i));
}
printf("\n");
}
void Minuscula(char *abc){
int pos = 0;

printf("El aecedario en minusculas es: ");
for(int i = 0; i < 26; i++){
    pos = 65+i;
    *(abc+i) = pos;
    printf("%c", tolower(*(abc+i)));
}
printf("\n");
}

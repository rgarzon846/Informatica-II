/*Desarrollar un programa que declare e inicialice un vector tipo char con el abecedario. 
Luego mostrar en pantalla el abecedario en mayuscula y minuscula, utilizando punteros.
Nota: la función para pasar a mayúscula es toupper() y a minúsculas es tolower().  
Ejemplo: cadena[i] = tolower(cadena[i]); En código ASCII A=65. Agregar la lib #include <ctype.h>*/

#include <stdio.h>
#include <ctype.h>

int main(){
char ABC[26] = {' '};
char *abc = &ABC;
int pos = 0;

printf("El abecedario es: ");
for(int i = 0; i < 26; i++){
pos = 65+i;
*(abc+i) = pos;
printf("%c", *(abc+i)); 
}
printf("\n");

printf("El abecedario en minusculas es: ");
for(int i = 0; i < 26; i++){
pos = 65+i;
*(abc+i) = pos;
printf("%c", tolower(*(abc+i))); 
}
    return 0;
}



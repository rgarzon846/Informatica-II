/*Crear un programa que pregunte al usuario cuantos caracteres desea introducir, reserve espacio para dicho número de caracteres, 
le permita al usuario introducirlos desde teclado. Por último se los muestra todos seguidos y en el orden inverso al que fueron introducidos.
 Crear funciones para cargar, mostrar en orden y mostrar en orden inverso. Utilizar funciones. */

 #include <stdio.h>
 #include <stdlib.h>

 void Cargar(char *, int);
 void Mostrar(char *, int);
 void AlReves(char *, int);

 int main(){
    char *p = NULL;
    int cant = 0;

    printf("Introduzca la cantidad de caracteres que desee almacenar:\n");
    scanf(" %d", &cant);

    p = (char *) malloc(cant * sizeof(char));

    if(p == NULL){
        printf("Hubo un error al reservar la memoria\n");
        return 1;
    }else{
        Cargar(p, cant);
        Mostrar(p, cant);
        AlReves(p, cant);
    }
    return 0;
 }

 void Cargar(char *p, int cant){
    printf("Introduzca los caracteres que desea almacenar:\n");
        for(int i = 0; i < cant; i++){
            scanf(" %c", &*(p+i));
        }

 }

 void Mostrar(char *p, int cant){
    printf("Los caracteres ingresados son:\n");
    for(int i = 0; i < cant; i++){
        printf("%c\t", *(p+i));
    }
    printf("\n");
 }

 void AlReves(char *p, int cant){
    char aux = ' ';
    printf("Los caracteres ingresados ordenados al reves son:\n");
    for(int i = 0; i < cant/2; i++){
        aux = *(p+i);
        *(p+i) = *(p+cant-i-1);
        *(p+cant-i-1) = aux;
        
    }
    for(int i = 0; i < cant; i++){
        printf("%c\t", *(p+i));
    }
    printf("\n");
 }
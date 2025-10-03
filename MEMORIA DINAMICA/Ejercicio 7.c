/*Crear un programa que pregunte al usuario cuantos caracteres desea introducir, reserve espacio para dicho número de caracteres, 
le permita al usuario introducirlos desde teclado y luego mostrar por pantalla los valores. Luego, el programa pregunta cuántos 
caracteres desea agregar a la lista de elementos ya introducida, agrega espacio de memoria y solicita el ingreso de los nuevos valores. 
Por último, mostrar la lista resultante. Utilizar funciones.
*/

#include <stdio.h>
#include <stdlib.h>

void Cargar(char *, int);
void Agregar(char *, int, int);

int main(){
char *p = NULL;
int cant = 0;
int cant2 = 0;

printf("Introduzca el espacio inicial de memoria que desee almacenar:\n");
scanf(" %d", &cant);
p = (char *) malloc(cant * sizeof(char));
Cargar(p, cant);

printf("Introduzca el espacio de memoria que desee agregar:\n");
scanf(" %d", &cant2);

Agregar(p, cant2, cant);

    free(p);
    p = NULL;
    return 0;
}

void Cargar(char *p, int cant){

    if(p == NULL){
        printf("El espacio no se ha podido reservar\n");
    }else{
        printf("Ingrese los caracteres que desea almacenar:\n");
        for(int i = 0; i < cant; i++){
            scanf(" %c", &*(p+i));
        }
        printf("Los caracteres ingresados hasta el momento son:\n");
        for(int i = 0; i < cant; i++){
            printf("%c\t", *(p+i));
        }
        printf("\n");
    }
}

void Agregar(char *p, int cant2, int cant){

    char *p2 = NULL;
    
    p2 = (char *) realloc(p, cant2 * sizeof(char));

    if(p2 == NULL){
        printf("Error al agregar memoria");
        free(p);
    }
        p = p2;
        printf("Ingrese los caracteres que desea agregar:\n");
        for(int i = cant; i < cant+cant2; i++){
            scanf(" %c", &*(p+i));
        }
        printf("La lista de caracteres final es:\n");
        for(int i = 0; i < cant+cant2; i++){
            printf(" %c\t", *(p+i));
        }
        printf("\n");

}
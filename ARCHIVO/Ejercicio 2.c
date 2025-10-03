/*Escriba un programa que cree un menú de opciones que permita
a) abrir un archivo,
b) escribir un archivo,
c) leer un archivo. (Sin utilizar funciones)
*/

#include <stdio.h>

int main()
{
    FILE *archivo;
    char opcion = ' ';
    char cadena[100];
    char volver = 's';

    do{
    printf("Ingrese la opcion que desee ejecutar:\n");
    printf("a. Abrir un archivo\n");
    printf("b. Escribir un archivo\n");
    printf("c. Leer un archivo\n");
    scanf(" %c", &opcion);

    switch (opcion)
    {
    case 'a':
    case 'A':
        archivo = fopen("archivo.txt", "r");
        if (archivo == NULL)
        {
            printf("\nError al abrir el archivo\n");
            return 1;
        }
        printf("\nEL archivo se ha abierto con exito\n");
        fclose(archivo);
        archivo = NULL;
        break;
    case 'b':
    case 'B':
        archivo = fopen("archivo.txt", "w");
        if(archivo == NULL)
        {
            printf("\nError al abrir el archivo\n");
            return 1;
        }
        printf("\nIngrese lo que desee escribir en el archivo: ");
        getchar();
        fgets(cadena, 100, stdin);
        fputs(cadena, archivo);
        fclose(archivo);
        archivo = NULL;
        break;
    case 'c':
    case 'C':
        archivo = fopen("archivo.txt", "r");
        if (archivo == NULL)
        {
            printf("\nError al abrir el archivo\n");
            return 1;
        }
        printf("Leyendo archivo:\n");
        if(fgets(cadena, 100, archivo) != NULL){
            printf("%s\n", cadena);
        }else{
            printf("\nError al leer el archivo");
        }
        fclose(archivo);
        archivo = NULL;
        break;
    default:
        printf("\nNo ha seleccionado una opcion valida\n");
    }
    printf("\nDesea volver al menu\?: Si(s), No(n)\n");
    scanf(" %c", &volver);

}while(volver == 's' || volver == 'S');

    return 0;
}
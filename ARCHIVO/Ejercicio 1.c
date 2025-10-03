/*Escriba un programa que lea caracteres desde el teclado, y que escriba un diario en un archivo llamado “diario.txt”. 
Para indicar utilice la entrada EOF. Utilice la función fputc(). Para tomar los valores del teclado con la función fgetc(stdin)
*/

#include <stdio.h>

int main(){
    FILE *in;
    int ch;
    
    in = fopen("diario.txt", "w");
    
    if(in == NULL){
        printf("\nNo se ha abierto el archivo\n");
        return 1;
    }

    printf("Ingrese el caracter que desee copiar en diario:\n");
    ch = fgetc(stdin);
    if(ch != EOF){
        fputc(ch, in);
    }
    
    fclose(in);
    in = NULL;
    return 0;
}
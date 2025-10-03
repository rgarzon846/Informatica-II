/*Escriba un programa que cree un archivo llamado "datos_personales.txt” que pregunte los siguientes datos personales: 
nombre, apellido, dni, edad, nacionalidad. Luego abrir el archivo y mostrarlo. Utilice fprintf y scanf.
*/

#include <stdio.h>
#include <string.h>

int main(){
    FILE *datos;
    char nombre[20];
    char apellido[20];
    int dni = 0;
    int edad = 0;
    char nacionalidad[20];
    
    printf("Ingrese los datos que se solicitan:\n");
    printf("Nombre: ");
    fgets(nombre, 20, stdin);
    nombre[strcspn(nombre, "\n")] = '\0';
    printf("\nApellido: ");
    fgets(apellido, 20, stdin);
    nombre[strcspn(apellido, "\n")] = '\0';
    printf("\nDNI: ");
    scanf(" %d", &dni);
    printf("\nEdad: ");
    scanf(" %d", &edad);
    printf("\nNacionalidad: ");
    getchar();
    fgets(nacionalidad, 20, stdin);
    nombre[strcspn(nacionalidad, "\n")] = '\0';

    datos = fopen("datos_personales.txt", "w");
    if(datos == NULL){
        printf("Error al abrir el archivo\n");
        return 1;
    }
    fprintf(datos, "Nombre: %s\nApellido: %s\nDNI: %d\nEdad: %d\nNacionalidad: %s", nombre, apellido, dni, edad, nacionalidad);
    fclose(datos);
    printf("\nDatos ingresados con exito\n\n");

    datos = fopen("datos_personales.txt", "r");
    if(datos == NULL){
        printf("Error al abrir el archivo\n");
        return 1;
    }
    printf("Leyendo los datos...\n");
    printf("Los datos leidos son:\n");
    fscanf(datos, "%s\n%s\n%d\n%d\n%s\n", nombre, apellido, &dni, &edad, nacionalidad);
    fclose(datos);
    printf("%s\n%s\n%d\n%d\n%s", nombre, apellido, dni, edad, nacionalidad);
    datos = NULL;


    return 0;
}
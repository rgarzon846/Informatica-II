/*Crear un programa que pida los siguientes datos de una canción: Artista, Título, Duración (en segundos),Tamaño del archivo (en KB). 
Crear una estructura que almacene datos de la canción y luego los muestre por pantalla.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Cancion{
    char artista[20];
    char titulo[20];
    float duracion;
    float tamano;
};

int main(){
    struct Cancion cancion;
char nombre[20];
printf("Ingrese el nombre de una cancion: ");
fgets(cancion.titulo, sizeof(cancion.titulo), stdin);
cancion.titulo[strcspn(cancion.titulo, "\n")] = '\0';

printf("\nIngrese el nombre del artista: ");
fgets(cancion.artista, sizeof(cancion.artista), stdin);
cancion.artista[strcspn(cancion.artista, "\n")] = '\0';

printf("\nIngrese la duracion en segundos de la cancion: ");
scanf(" %f", &cancion.duracion);

printf("\nIngrese la cantidad de kB que ocupa el archivo: ");
scanf(" %f", &cancion.tamano);

printf("\nLa cancion ingresada presenta las siguientes caracteristicas:\n");
printf("|Titulo: %s\n|Artista: %s\n|Duracion: %.2fs\n|Tamano: %.2fkB\n",  cancion.titulo, cancion.artista, cancion.duracion, cancion.tamano);
    return 0;
}
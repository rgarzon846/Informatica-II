/*Ampliar el programa del ejercicio anterior, para que almacene datos de hasta 3 canciones en un vector de estructura. 
Luego crear un menú que permita las opciones: 
agregar una nueva canción
mostrar todas las canciones
buscar una canción por título*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cancion{
    char titulo[20];
    char artista[20];
    float tamano;
    float duracion;
};

void CrearCancion(struct cancion[3]);
void MostrarCanciones(struct cancion[3]);
void BuscarTitulo(struct cancion[3]);

int main(){
struct cancion canciones[3];
char opcion = ' ';
char volver = 's';

do{
printf("Ingrese la opcion que desee ejecutar:\n");
printf("a. Agregar una nueva cancion\n");
printf("b. Mostar todas las canciones\n");
printf("c. Buscar una cancion con titulo\n");
scanf(" %c", &opcion);

switch(opcion){
    case 'a':
    case 'A': CrearCancion(canciones); break;
    case 'b': 
    case 'B': MostrarCanciones(canciones); break;
    case 'c':
    case 'C': BuscarTitulo(canciones); break;
    defaul: printf("\nLa opcion que ha ingresado no es valida\n");
}
printf("\nDesea volver al menu\?: Si(S), No(N)\n");
scanf(" %c", &volver);

}while (volver == 's' || volver == 'S');

return 0;
}

void CrearCancion(struct cancion canciones[3]){
char bandera = 'S';
for(int i = 0; i < 3; i++){
    if(bandera == 's' || bandera == 'S'){
    printf("\nIngrese el titulo de la cancion: ");
    getchar();
    fgets(canciones[i].titulo, 20, stdin);
    canciones[i].titulo[strcspn(canciones[i].titulo, "\n")] = '\0';
    printf("\nIngrese el artista: ");
    getchar();
    fgets(canciones[i].artista, 20, stdin);
    canciones[i].artista[strcspn(canciones[i].artista, "\n")] = '\0';
    printf("\nIngrese la duracion de la cancion en segundos: ");
    scanf(" %f", &canciones[i].duracion);
    printf("\nIngrese la cantidad de kB que ocupa la cancion: ");
    scanf(" %f", &canciones[i].tamano);
    if(i < 2){
    printf("\nLa cancion se ha agregado con exito\n");
    printf("Desea ingresar otra cancion\?: Si(S), No(N)\n");
    scanf(" %c", &bandera);
    }
    }
}
}

void MostrarCanciones(struct cancion canciones[3]){
    printf("\nLas canciones agregadas son:\n");
    for(int i = 0; i < 3; i++){
        printf("Titulo: %s\nArtista: %s\nDuracion: %.2fs\nPeso: %.2fkB\n", canciones[i].titulo, canciones[i].artista, canciones[i].duracion, canciones[i].tamano);
    }
}

void BuscarTitulo(struct cancion canciones[3]){
    char comparacion[20];
    int bandera = 0;
    printf("\nIngrese el titulo que desee buscar: ");
    getchar();
    fgets(comparacion, 20, stdin);
    comparacion[strcspn(comparacion, "\n")] = '\0';

    for(int i = 0; i < 3; i++){
        if(strcmp(canciones[i].titulo, comparacion) == 0){
            printf("\nEL titulo es la cancion nro %d\n", i+1);
            bandera = 1;
        }
    }
    if(bandera == 0){
            printf("\nNo se ha encontrado el titulo ingresado\n");
        }
        bandera = 0;
}
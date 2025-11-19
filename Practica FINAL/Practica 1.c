/*Desarrolla un programa para gestionar los datos de un restaurante mediante un TDA. 
El TDA debe contener la información de los platos disponibles,
incluyendo nombre del plato, cantidad de platos disponibles (entero), 
cantidad de platos vendidos (entero) y precio (decimal). Implementa las siguientes funciones para:

Insertar un nuevo plato en el menú.
Mostrar el menú por consola y generar un archivo txt llamado "menu.txt".
Eliminar un plato del menú.
Calcular la recaudación total de los platos vendidos.
Ordenar los platos por precio usando quicksort.(recursividad)
Además, crea un menú de opciones para que el usuario pueda interactuar con el programa.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nombre[25];
    int cant;
    float precio;
}Plato;

typedef struct Platos{
    Plato plato;
    struct Platos *sig;
}Platos;

void Menu();
void InsertarPlato(Platos **, Platos**);
void ImprimirMenu(Platos *);
void EliminarPlato(Platos **, Platos**);
void CalcularTotal(Platos *);
void OrdenarPlatos(Platos *);

int main(){
    
    Menu();
    return 0;
}

void Menu(){
    Platos *frente = NULL;
    Platos *fin = NULL;
}

void InsertarPlato(Platos **frente, Platos **fin){
    Platos *nuevo = (Platos *) malloc(sizeof(Platos));
    if(nuevo != NULL){
    printf("\nIngrese los siguientes datos del plato:\n");
    printf("Nombre: ");
    getchar();
    fgets(nuevo->plato.nombre, 25, stdin);
    nuevo->plato.nombre[strcspn(nuevo->plato.nombre, "\n")] = '\0';
    printf("Cantidad vendida: ");
    scanf(" %d", &nuevo->plato.cant);
    printf("Precio: ");
    scanf(" %f", &nuevo->plato.precio);
    nuevo->sig = NULL;

    if(*fin == NULL){
        *frente = nuevo;
        *fin = nuevo;
    }else{
        (*fin)->sig = nuevo;
        *fin = nuevo;
    }
    printf("\nEL plato se ha registrado con exito\n");
    }else{
        printf("\nError al reservar memoria\n");
    }
   
}
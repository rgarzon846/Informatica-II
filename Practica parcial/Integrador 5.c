/*Realice el siguiente ejercicio implementando punteros, memoria dinámica, archivo y estructura.
Desarrolle un programa que permita gestionar los datos de productos en el inventario de una tienda.
Para ello, defina una estructura llamada Producto que almacene la siguiente información: código de
producto (entero), nombre del producto (cadena de caracteres), cantidad en stock (entero) y precio
unitario (flotante). Luego, implemente las siguientes funciones: Que permita registrar un nuevo
producto (debe agregar un producto nuevo a la lista) Que permita leer un archivo "productos.txt".
Que permita buscar todos los productos que tienen una cantidad de stock menor a 10.
Genere un menú de opciones con las distintas opciones que puede realizar el usuario. Recuerde
presentar la información de manera ordenada y entendible.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    long codigo;
    char nombre[25];
    int stock;
    float precio;
} Producto;

void RegistrarProducto(Producto **, int *);
void GuardarProductos(Producto *, int);
void LeerProductos(Producto *, int);
void BuscarProductos(Producto *, int);
void Salir(Producto **, int *, char *);
void Menu();

int main() { 
    Menu();
    return 0; }

void Menu()
{
    Producto *productos = NULL;
    int cant = 0;
    char volver = 's';
    char opcion = ' ';
    do
    {
        printf("Ingrese la opcion que desee ejecutar\n");
        printf("a. Registrar un producto\n");
        printf("b. Leer la lista de productos ingresados\n");
        printf("c. Buscar productos con menos de 10 unidades en stock\n");
        scanf(" %c", &opcion);

        switch (opcion)
        {
        case 'a':
        case 'A':
            RegistrarProducto(&productos, &cant);
            break;
        case 'b':
        case 'B':
            LeerProductos(productos, cant);
            break;
        case 'c':
        case 'C':
            BuscarProductos(productos, cant);
            break;
        case 'd':
        case 'D':
            Salir(&productos, &cant, &volver);
            break;
        default:
            printf("No se ha elegido una opcion valida\n");
            break;
        }
        if (opcion != 'd' && opcion != 'D')
        {
            printf("Desea volver al menu\?: Si(s), No(n)\n");
            scanf(" %c", &volver);
        }
    }while(volver == 's' || volver == 'S');
    free(productos);
    productos = NULL;
}

void RegistrarProducto(Producto **productos, int *cant)
{
    Producto *productos2 = NULL;
    char otro = 's';
    do
    {
        productos2 = (Producto *)realloc(*productos, (*cant + 1) * sizeof(Producto));

        if (productos2 != NULL)
        {
            *productos = productos2;
            printf("Ingrese la informacion del producto\n");
            printf("Codigo: ");
            scanf(" %ld", &(*productos + *cant)->codigo);
            printf("Nombre: ");
            getchar();
            fgets((*productos + *cant)->nombre, 25, stdin);
            (*productos + *cant)->nombre[strcspn((*productos + *cant)->nombre, "\n")] = '\0';
            printf("Cantidad de unidades en stock: ");
            scanf(" %d", &(*productos + *cant)->stock);
            printf("Precio unitario: ");
            scanf(" %f", &(*productos + *cant)->precio);
            (*cant)++;
            printf("Desea ingresar otro producto\?: Si(s), No(n)\n");
            scanf(" %c", &otro);
        }
        else
        {
            printf("Error al ingresar nuevo producto\n");
            return;
        }
    } while (otro == 's' || otro == 'S');
    GuardarProductos(*productos, *cant);
}

void GuardarProductos(Producto *productos, int cant)
{
    FILE *archivo;
    archivo = fopen("productos.txt", "w");
    if (archivo != NULL)
    {
        printf("Guardando productos...\n");
        printf("----------------------------------\n");
        for (int i = 0; i < cant; i++)
        {
            fprintf(archivo, "%ld %s %d %.2f\n", (productos + i)->codigo, (productos + i)->nombre,
                    (productos + i)->stock, (productos + i)->precio);
        }
        fclose(archivo);
        printf("Productos guardados con exito\n");
        printf("----------------------------------\n");
    }
    else
    {
        printf("Error al guardar productos\n");
    }
}

void LeerProductos(Producto *productos, int cant)
{
    FILE *archivo;
    Producto *lectura;
    lectura = (Producto *)malloc(cant * sizeof(Producto));
    char tamlinea[200];
    if (lectura != NULL)
    {
        archivo = fopen("productos.txt", "r");
        if (archivo != NULL)
        {
            printf("Leyendo productos\n");
            printf("----------------------------------\n");
            for (int i = 0; i < cant; i++)
            {
                fgets(tamlinea, 200, archivo);
                sscanf(tamlinea, "%ld %24[^0-9] %d %f\n", &(lectura + i)->codigo, (lectura + i)->nombre,
                       &(lectura + i)->stock, &(lectura + i)->precio);
            }
            fclose(archivo);
            printf("Productos leidos con exito\n");
            printf("----------------------------------\n");
        }
        else
        {
            printf("Error al leer lista\n");
            return;
        }
        printf("%-10s | %-25s | %-5s | %s\n", "Codigo", "Nombre", "Stock", "Precio");
        for (int i = 0; i < cant; i++)
        {
            printf("%-10ld | %-25s | %-5d | %.2f\n", (lectura + i)->codigo, (lectura + i)->nombre,
                   (lectura + i)->stock, (lectura + i)->precio);
        }
        free(lectura);
        lectura = NULL;
    }
    else
    {
        printf("No se ha podido leer el archivo");
        return;
    }
}

void BuscarProductos(Producto *productos, int cant)
{
    char nombre[25];
    int bandera = 0;
    char otro = 's';
    do
    {
        printf(
            "Ingrese el nombre del producto con menos de 10 unidades en stock que desea buscar: ");
        getchar();
        fgets(nombre, 25, stdin);
        nombre[strcspn(nombre, "\n")] = '\0';
        for (int i = 0; i < cant; i++)
        {
            if (strcmp(nombre, (productos + i)->nombre) == 0 && (productos + i)->stock < 10)
            {
                printf("El producto %s tiene las sisuientes caracteristicas:\n", nombre);
                printf("%-10s | %-25s | %-5s | %s\n", "Codigo", "Nombre", "Stock", "Precio");
                printf("%-10ld | %-25s | %-5d | %.2f\n", (productos + i)->codigo,
                       (productos + i)->nombre, (productos + i)->stock, (productos + i)->precio);
                bandera = 1;
            }
        }
        if (bandera == 0)
        {
            printf("El producto no esta en la lista o no tiene menos de 10 unidades en stock\n");
        }
        bandera = 0;
        printf("Desea buscar otro producto\?: Si(s), No(n)\n");
        scanf(" %c", &otro);
    } while (otro == 's' || otro == 'S');
}

void Salir(Producto **productos, int *cant, char *volver)
{
    free(*productos);
    *productos = NULL;
    *cant = 0;
    *volver = 'n';
}
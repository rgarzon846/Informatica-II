/*Crear un programa que cree una lista de productos, para ello utilice una estructura llamada
producto con los atributos código, nombre, cantidad y precio. Luego genere un menú de opciones en la
cual llame a las siguientes funciones: Agregar producto. Mostrar lista de productos Borre un
producto por código de producto. Mostrar una lista de los productos sin stock.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Producto
{
    long codigo;
    char nombre[25];
    int cant;
    float precio;
} Producto;

typedef struct Nodo
{
    Producto producto;
    struct Nodo *sig;
} Nodo;

void Menu();
void Agregar(Nodo **);
void Mostrar(Nodo *);
void Borrar(Nodo **);
void SinStock(Nodo *);
void Liberar(Nodo **);

int main()
{
    Menu();
    return 0;
}

void Menu()
{
    Nodo *p = NULL;
    char opcion = ' ';
    char volver = 's';

    do
    {
        printf("Ingrese la opcion que desee ejecutar:\n");
        printf("a. Agregar un producto a la lista\n");
        printf("b. Mostrar la lista de productos\n");
        printf("c. Borrar un producto de la lista\n");
        printf("d. Mostrar lista de productos sin stock\n");
        scanf(" %c", &opcion);

        switch (opcion)
        {
        case 'a':
        case 'A':
        char seguir = 's';
            while(seguir == 's' || seguir == 'S'){
            Agregar(&p);
            printf("\nDesea ingresar otro producto\?: Si(s), No(n)\n");
            scanf(" %c", &seguir);
            }
            break;
        case 'b':
        case 'B':
            Mostrar(p);
            break;
        case 'c':
        case 'C':
            Borrar(&p);
            break;
        case 'd':
        case 'D':
            SinStock(p);
            break;
        default:
            printf("No se ha ingresado una opcion valida\n");
            break;
        }
        printf("\nDesea volver al menu\?: Si(s), No(n)\n");
        scanf(" %c", &volver);
    } while (volver == 's' || volver == 'S');
    Liberar(&p);
}

void Agregar(Nodo **p)
{
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    printf("\nIngrese los siguientes datos del producto:\n");
    printf("Nombre: ");
    getchar();
    fgets(nuevo->producto.nombre, 25, stdin);
    nuevo->producto.nombre[strcspn(nuevo->producto.nombre, "\n")] = '\0';
    printf("Codigo: ");
    scanf(" %ld", &nuevo->producto.codigo);
    printf("Unidades: ");
    scanf(" %d", &nuevo->producto.cant);
    printf("Precio: ");
    scanf(" %f", &nuevo->producto.precio);
    nuevo->sig = NULL;

    if (nuevo != NULL)
    {
        if (*p == NULL)
        {
            *p = nuevo;
        }
        else
        {
            Nodo *aux = *p;
            while (aux->sig != NULL)
            {
                aux = aux->sig;
            }
            aux->sig = nuevo;
        }
    }
    else
    {
        printf("\nNo se ha podido crear un nodo nuevo\n");
    }
}

void Mostrar(Nodo *p)
{
    Nodo *aux = p;
    printf("La lista de productos ingresados es:\n");
    printf("%-25s | %-15s | %-15s | %s\n", "Nombre", "Codigo", "Unidades", "Precio");
    while (aux != NULL)
    {
        printf("%-25s | %-15ld | %-15d | %.2f\n", aux->producto.nombre, aux->producto.codigo,
               aux->producto.cant, aux->producto.precio);
        aux = aux->sig;
    }
}

void Borrar(Nodo **p)
{
    Nodo *aux = *p;
    Nodo *ant = NULL;
    long codigo = 0;
    printf("La lista de productos ingresados es:\n");
    printf("%-25s | %-15s | %-15s | %s\n", "Nombre", "Codigo", "Unidades", "Precio");
    while (aux != NULL)
    {
        printf("%-25s | %-15ld | %-15ld | %.2f\n", aux->producto.nombre, aux->producto.codigo,
               aux->producto.codigo, aux->producto.precio);
        aux = aux->sig;
    }
    aux = *p;
    printf("\nIngrese el codigo del producto que desee eliminar: ");
    scanf(" %ld", &codigo);

    while (aux != NULL && aux->producto.codigo != codigo)
    {
        ant = aux;
        aux = aux->sig;
    }
    if (aux != NULL)
    {
        if (ant != NULL)
        {
            ant->sig = aux->sig;
        }
        else
        {
            *p = aux->sig;
        }
        free(aux);
    }
    else
    {
        printf("\nNo se ha encontrado el codigo que desea eliminar\n");
    }

    aux = *p;
    printf("La lista de productos actualizada es:\n");
    printf("%-25s | %-15s | %-15s | %s\n", "Nombre", "Codigo", "Unidades", "Precio");
    while (aux != NULL)
    {
        printf("%-25s | %-15ld | %-15ld | %.2f\n", aux->producto.nombre, aux->producto.codigo,
               aux->producto.codigo, aux->producto.precio);
        aux = aux->sig;
    }
}

void SinStock(Nodo *p)
{
    Nodo *aux = p;
    int bandera = 0;
    printf("\nLos productos sin stock son:\n\n");
    while (aux != NULL)
    {
        if (aux->producto.cant == 0)
        {
            printf("%s\n", aux->producto.nombre);
            bandera = 1;
        }
        aux = aux->sig;
    }
    if(bandera == 0){
        printf("No hay productos sin stock\n");
    }
    bandera = 0;
}

void Liberar(Nodo **p)
{
    while (*p != NULL)
    {
        Nodo *prox = (*p)->sig;
        free(*p);
        *p = prox;
    }
    printf("\nLa memoria se ha liberado con exito\n");
}
/*Crear un programa en el cual solicite al usuario la cantidad de números aleatorios a cargar en la
lista. Los valores aleatorios deben ser entre el 1 y el 100. Luego cree un menú de opciones en la
cual la opción a muestra la lista de valores, la opción b calcula y muestra solo aquellos valores
múltiples de 5.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Nodo
{
    int valor;
    struct Nodo *sig;
} Nodo;

void Menu();
void Agregar(Nodo **);
void Multiplos(Nodo *);
void Mostrar(Nodo *p);
void Liberar(Nodo **, char *);

int main() { 
    Menu();    
    return 0;
}

void Menu()
{
    Nodo *p = NULL;
    char opcion = ' ';
    char volver = 's';
    int bandera = 0;
    Agregar(&p);

    do
    {
        printf("Ingrese la opcion que desee ejecutar:\n");
        printf("a. Mostrar lista de valores\n");
        printf("b. Mostrar unicamente los valores multiplos de 5\n");
        printf("c. Liberar la lista creada\n");
        scanf(" %c", &opcion);

        switch (opcion)
        {
        case 'A':
        case 'a':
            Mostrar(p);
            break;
        case 'B':
        case 'b':
            Multiplos(p);
            break;
        case 'C':
        case 'c':
            Liberar(&p, &volver);
            bandera = 1;
            break;
        default:
            printf("No ha elegido una opcion valida\n");
            break;
        }

        if (opcion != 'c' && opcion != 'C')
        {
            printf("Desea volver al menu\?: Si(s), No(n)\n");
            scanf(" %c", &volver);
        }
    } while (volver == 's' || volver == 'S');
    if (bandera == 0)
    {
        Liberar(&p, &volver);
    }
    bandera = 0;
}

void Agregar(Nodo **p)
{
    srand(time(NULL));
    int cant = 0;

    printf("Ingrese la cantidad de valores que desea almacenar: ");
    scanf(" %d", &cant);

    for (int i = 0; i < cant; i++)
    {
        Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
        nuevo->valor = rand() % 100 + 1;
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
            printf("\nError al creal nuevo nodo\n");
        }
    }
}

void Mostrar(Nodo *p)
{
    Nodo *aux = p;
    printf("La lista que se ha creado es la siguiente:\n");
    while (aux != NULL)
    {
        printf("%d\n", aux->valor);
        aux = aux->sig;
    }
}

void Multiplos(Nodo *p)
{
    Nodo *aux = p;

    printf("Los valores multiplos de 5 son:\n");
    while (aux != NULL)
    {
        if (aux->valor % 5 == 0)
        {
            printf("%d\n", aux->valor);
        }
        aux = aux->sig;
    }
}

void Liberar(Nodo **p, char *volver)
{
    while (*p != NULL)
    {
        Nodo *prox = (*p)->sig;
        free(*p);
        *p = prox;
    }
    printf("\nLa lista se ha liberado con exito\n");
    *volver = 'n';
}
/*Crear un programa en el cual cargue una lista de 5 números aleatoriamente (entre 1 y 10),
luego los muestre todos los valores. Finalmente borre un valor y vuelve a mostrar la lista
resultante. Genere un menú de opciones para las funciones.*/

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
void Mostrar(Nodo *);
void Borrar(Nodo **);
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

    Agregar(&p);
    do
    {
        printf("Ingrese la opcion que desee ejecutar:\n");
        printf("a. Mostrar los valores de la lista\n");
        printf("b. Borrar un valor de la lista\n");
        scanf(" %c", &opcion);

        switch (opcion)
        {
        case 'a':
        case 'A':
            Mostrar(p);
            break;
        case 'b':
        case 'B':
            Borrar(&p);
            break;
        default:
            printf("\nNo ha ingresado una opcion valida\n");
            break;
        }
        printf("\nDesea regresar al menu\?: Si(s), No(n)\n");
        scanf(" %c", &volver);
    } while (volver == 's' || volver == 'S');
    Liberar(&p);
}

void Agregar(Nodo **p)
{
    srand(time(NULL));

    for (int i = 0; i < 5; i++)
    {
        Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
        nuevo->sig = NULL;
        nuevo->valor = rand() % 10 + 1;

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
            printf("\nNo se ha podido crear el nuevo nodo\n");
        }
    }
}

void Mostrar(Nodo *p)
{
    Nodo *aux = p;
    printf("\nLos valores de la lista son:\n");
    while (aux != NULL)
    {
        printf("%d\n", aux->valor);
        aux = aux->sig;
    }
}

void Borrar(Nodo **p)
{
    int valor = 0;
    Nodo *aux = *p;
    Nodo *ant = NULL;

    printf("Valores de la lista:\n");
    while (aux != NULL)
    {
        printf("%d\n", aux->valor);
        aux = aux->sig;
    }
    printf("\nEscriba el valor que desee borrar: ");
    scanf(" %d", &valor);
    
    aux = *p;
    while ((aux != NULL) && (aux->valor != valor))
    {
        ant = aux;
        aux = aux->sig;
    }
    if (aux != NULL)
    {
        if (ant != NULL)
        {
            ant->sig = aux->sig;
        }else{
            *p = aux->sig;
        }
        free(aux);
    }else{
        printf("\nEl valor ingresado no esta en la lista\n");
    }

    printf("Valores de la lista actualizados:\n");
    
    aux = *p;
    while (aux != NULL)
    {
      printf("%d\n", aux->valor);
        aux = aux->sig;
    }
}

void Liberar(Nodo **p)
{
    Nodo *aux = *p;
    while (*p != NULL)
    {
        aux = (*p)->sig;
        free(*p);
        *p = aux;
    }
    printf("\nLa memoria se ha liberado con exito\n");
}
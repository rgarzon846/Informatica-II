/*Crear un programa que cargue 10 letras mayúsculas de manera aleatoria,
luego crear dos funciones una que muestre y cuente las vocales y otra que muestre y cuente las
consonantes de la lista.
*/

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
void Vocales(Nodo *);
void Consonantes(Nodo *);
void Liberar(Nodo **, char *);

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
    int bandera = 0;
    Agregar(&p);

    do
    {
        printf("Ingrese la opcion que desee ejecutar:\n");
        printf("a. Mostrar vocales de la lista\n");
        printf("b. Mostrar consonantes de la lista\n");
        printf("c. Liberar la lista\n");
        scanf(" %c", &opcion);

        switch (opcion)
        {
        case 'a':
        case 'A':
            Vocales(p);
            break;
        case 'B':
        case 'b':
            Consonantes(p);
            break;
        case 'C':
        case 'c':
            Liberar(&p, &volver);
            bandera = 1;
            break;
        default:
            printf("\nNo se ha ingresado una opcion valida\n");
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
    for (int i = 0; i < 10; i++)
    {
        Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
        if (nuevo != NULL)
        {
            nuevo->valor = rand() % (90 - 65 + 1) + 65;
            nuevo->sig = NULL;
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
            printf("\nNo se ha podido crear el nodo\n");
        }
    }
}

void Vocales(Nodo *p)
{
    Nodo *aux = p;
    int cant = 0;
    printf("\nLas volcales de la lista son:\n");
    while (aux != NULL)
    {
        if (aux->valor == 65 || aux->valor == 69 || aux->valor == 73 || aux->valor == 79 ||
            aux->valor == 85)
        {
            cant++;
            printf("%c\n", aux->valor);
        }
        aux = aux->sig;
    }
    printf("\nLa cantidad de vocales encontradas es: %d\n", cant);
}

void Consonantes(Nodo *p)
{
    Nodo *aux = p;
    int cant = 0;
    printf("\nLas consonantes de la lista son:\n");
    while (aux != NULL)
    {
        if (aux->valor != 65 && aux->valor != 69 && aux->valor != 73 && aux->valor != 79 &&
            aux->valor != 85)
        {
            cant++;
            printf("%c\n", aux->valor);
        }
        aux = aux->sig;
    }
    printf("\nLa cantidad de consonantes encontradas es: %d\n", cant);
}

void Liberar(Nodo **p, char *volver)
{
    while (*p != NULL)
    {
        Nodo *prox = *p;
        prox = (*p)->sig;
        free(*p);
        *p = prox;
    }
    printf("\nLa memoria se ha liberado con exito\n");
    *volver = 'n';
}
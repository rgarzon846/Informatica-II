/*Crear un programa que muestre un menú de opciones que admite mayuscula y minuscula.
 Para el caso a llamará a una función en la cual permite el ingreso de valores numéricos.
 Para el caso b llamará una función que muestre la lista y para el caso c llamara una
 función que calcule y retorne el promedio de los valores de la lista.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo
{
    float valores;
    struct Nodo *sig;
} Nodo;

void Agregar(Nodo **);
void Mostrar(Nodo *);
float Promedio(Nodo *);
void Liberar(Nodo **, char *);
void Menu();

int main() { 
    Menu();
    return 0; }

void Menu()
{
    Nodo *p = NULL;
    char otro = 's';
    char opcion = ' ';
    int bandera = 0;

    do
    {
        printf("Ingrese la opcion que desee ejecutar:\n");
        printf("a. Ingresar valores numericos\n");
        printf("b. Mostrar lista de valores\n");
        printf("c. Calcular el promedio de valores ingresados\n");
        printf("d. Liberar memoria\n");
        scanf(" %c", &opcion);

        switch (opcion)
        {
        case 'a':
        case 'A':
            Agregar(&p);
        break;
        case 'b':
        case 'B': 
            Mostrar(p);
        break;
        case 'c':
        case 'C': 
            printf("\nEl promedio de los valores ingresados es: %.2f\n", Promedio(p));
        break;
        case 'd':
        case 'D': 
            Liberar(&p, &otro);
            bandera = 1;
        break;
        default: printf("\nNo ha ingresado una opcion valida\n");
        }
        if(opcion != 'd' && opcion != 'D'){
            printf("\nDesea ingresar otra opcion\?: Si(s), No(n)\n");
            scanf(" %c", &otro);
        }
    }while(otro == 's' || otro == 'S');
    if(bandera == 0){
    Liberar(&p, &otro);
    }
    bandera = 0;
}

void Agregar(Nodo **p)
{
    char otro = 's';
    float valor;
    
    while (otro == 's' || otro == 'S')
    {
        printf("\nIngrese un valor numerico: ");
        scanf(" %f", &valor);
        Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
        nuevo->valores = valor;
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
        }else
        {
            printf("\nError al crear nuevo nodo\n");
        }
        printf("\nDesea ingresar otro valor\?: Si(s), No(s)\n");
        scanf(" %c", &otro);
    }
}

void Mostrar(Nodo *p)
{
    Nodo *aux = p;
    printf("\nLa lista de valores ingresados es:\n");
    while (aux != NULL)
    {
        printf("%.2f\n", aux->valores);
        aux = aux->sig;
    }
}

float Promedio(Nodo *p)
{
    Nodo *aux = p;
    float suma = 0;
    int contador = 0;

    while (aux != NULL)
    {
        suma += aux->valores;
        contador++;
        aux = aux->sig; 
    }

    return suma / contador;
}

void Liberar(Nodo **p, char *otro)
{
    while (*p != NULL)
    {
        Nodo *prox = (*p)->sig;
        free(*p);
        *p = prox;
    }
    *otro = 'n';
    printf("\nLa memoria se ha liberado con exito\n");
}
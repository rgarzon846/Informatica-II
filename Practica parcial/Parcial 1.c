/*Desarrolle un programa que permita gestionar los datos de clientes en un banco.
Para ello, defina una estructura llamada ClienteBanco que almacene
la siguiente información: número de cliente (entero), nombre (cadena de caracteres),
saldo en cuenta (flotante) y tipo de cuenta (cadena de caracteres).
El tipo de cuenta puede ser Cuenta Corriente y Caja de Ahorros.

Implemente las siguientes funciones:

Que permita registrar un nuevo cliente del banco.
Que permita guardar sus datos en un archivo "clientes.txt". Cada línea del archivo debe contener la
información de un cliente. Que permita mostrar los clientes que tienen saldos negativos. Genere un
menú de opciones con las distintas opciones que puede realizar el usuario, que se repita hasta que
el usuario desea salir. Recuerde presentar la información de manera ordenada y entendible.

Utilice punteros, memoria dinamica,estructura y archivo.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int nrocliente;
    float saldocuenta;
    char nombre[20];
    char tipocuenta[20];
} ClienteBanco;

void RegistrarNuevo(ClienteBanco **, int *);
void GuardarDatos(ClienteBanco *, int *);
// void SaldosNegativo(ClienteBanco **, int *);
void Menu();

int main()
{
    Menu();
    return 0;
}

void Menu()
{
    ClienteBanco *cliente = NULL;
    int cant = 0;
    RegistrarNuevo(&cliente, &cant);
    GuardarDatos(cliente, &cant);
    free(cliente);
}

void RegistrarNuevo(ClienteBanco **cliente, int *cant)
{
    ClienteBanco *cliente2 = NULL;
    char otro = 's';

    do
    {
        cliente2 = realloc(*cliente, (*cant + 1) * sizeof(ClienteBanco));
        if (cliente2 == NULL)
        {
            printf("Error al agregar cliente\n");
            return;
        }
        else
        {
            *cliente = cliente2;
            printf("Ingrese los datos del nuevo cliente:\n");
            printf("Nro de cliente: ");
            scanf(" %d", &(*cliente + *cant)->nrocliente);
            getchar();
            printf("\nNombre: ");
            fgets((*cliente + *cant)->nombre, 20, stdin);
            (*cliente + *cant)->nombre[strcspn((*cliente + *cant)->nombre, "\n")] = '\0';
            printf("\nTipo de cuenta: ");
            fgets((*cliente + *cant)->tipocuenta, 20, stdin);
            (*cliente + *cant)->tipocuenta[strcspn((*cliente + *cant)->tipocuenta, "\n")] = '\0';
            printf("\nSaldo en cuenta: ");
            scanf(" %f", &(*cliente + *cant)->saldocuenta);
            printf("\nCliente ingresado con exito\n");
            (*cant)++;
            printf("\nDesea ingresar otro cliente\?: Si(s), No(n)\n");
            scanf(" %c", &otro);
            getchar();
        }
    } while (otro == 's' || otro == 'S');
}

void GuardarDatos(ClienteBanco *cliente, int *cant)
{
    FILE *datos;
    datos = fopen("clientes.txt", "w");
    if (datos == NULL)
    {
        printf("Error, no se pudo acceder al archivo\n");
        return;
    }
    printf("Guuardando datos...");
    for (int i = 0; i < *cant; i++)
    {
        fprintf(datos,
                "Nro de cliente: %d, Nombre: %s, Tipo de cuenta: %s, Saldo en cuenta: %.2f\n",
                (cliente + i)->nrocliente, 
                (cliente + i)->nombre, 
                (cliente + i)->tipocuenta,
                (cliente + i)->saldocuenta);
    }
    fclose(datos);
}

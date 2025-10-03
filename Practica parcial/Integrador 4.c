/*Desarrolle un programa que permita gestionar los datos de clientes en un banco. Para ello,
defina una estructura llamada Movimientos que almacene la siguiente información: número de cliente
(entero), movimiento (flotante), saldo en cuenta (flotante) y tipo de cuenta (cadena de caracteres).
El tipo de cuenta puede ser Cuenta Corriente y Caja de Ahorros. Cuando el cliente realiza un gasto
el movimiento es negativo y cuando el cliente recibe dinero es positivo. Implemente las siguientes
funciones: Que permita registrar un nuevo movimiento de un cliente y actualizar el saldo de la
cuenta. Que permita guardar sus datos en un archivo "movimientos.txt". Cada línea del archivo debe
contener la información de un movimiento de un cliente. Que permita mostrar los movimientos de un
cliente en particular. Genere un menú de opciones con las distintas opciones que puede realizar el
usuario. Recuerde presentar la información de manera ordenada y entendible.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int nrocliente;
    float movimiento;
    float saldocuenta;
    char tipocuenta[25];
} Movimientos;

void RegistrarMovimiento(Movimientos **, int *);
void GuardarMovimientos(Movimientos *, int);
void BuscarMostrar(Movimientos *, int);
void Salir(Movimientos **, int *, char *);
void Menu();

int main()
{
    Menu();
    return 0;
}

void Menu()
{
    char opcion = ' ';
    char volver = 's';
    Movimientos *movimientos = NULL;
    int cant = 0;

    do
    {
        printf("Ingrese la opcion que desee ejecutar\n");
        printf("a. Registrar movimiento nuevo\n");
        printf("b. Guardar movimientos\n");
        printf("c. Buscar los movimientos de un cliente\n");
        printf("d. Salir\n");
        scanf(" %c", &opcion);

        switch (opcion)
        {
        case 'a':
        case 'A':
            RegistrarMovimiento(&movimientos, &cant);
            break;
        case 'b':
        case 'B':
            GuardarMovimientos(movimientos, cant);
            break;
        case 'c':
        case 'C':
            BuscarMostrar(movimientos, cant);
            break;
        case 'd':
        case 'D':
            Salir(&movimientos, &cant, &volver);
            break;
        default:
            printf("No se ha elegido una opcion valida\n");
            break;
        }

        if (opcion != 'd' && opcion != 'D')
        {
            printf("Dese volver al menu\?: Si(s), No(n)\n");
            scanf(" %c", &volver);
        }

    } while (volver == 's' || volver == 'S');
    free(movimientos);
    movimientos = NULL;
}

void RegistrarMovimiento(Movimientos **movimientos, int *cant)
{

    Movimientos *moviminetos2 = NULL;
    char tipomov = ' ';
    char otro = 's';
    char cuenta = ' ';
    char primero = ' ';
    int nrocliente = 0;
    int bandera = 0;

    do
    {
        moviminetos2 = (Movimientos *)realloc(*movimientos, (*cant + 1) * sizeof(Movimientos));
        if (moviminetos2 != NULL)
        {
            *movimientos = moviminetos2;

            printf("Es el primer movimiento que ejecuta el cliente\?: Si(s), No(n)\n");
            scanf(" %c", &primero);
            switch (primero)
            {
            case 's':
            case 'S':
                printf("Ingrese los datos del movimiento que se ha ejecutado\n");
                printf("Nro de cliente: ");
                scanf(" %d", &(*movimientos + *cant)->nrocliente);
                printf(
                    "Se ha ingresado dinero o se ha egresado dinero\?:\na. Ingreso\nb. Egreso\n");
                scanf(" %c", &tipomov);
                printf("Monto de movimiento: ");
                scanf(" %f", &(*movimientos + *cant)->movimiento);

                printf("Saldo en la cuenta antes del movimiento: ");
                scanf(" %f", &(*movimientos + *cant)->saldocuenta);
                if (tipomov == 'a' || tipomov == 'A')
                {
                    (*movimientos + *cant)->saldocuenta += (*movimientos + *cant)->movimiento;
                }
                else if (tipomov == 'b' || tipomov == 'B')
                {
                    (*movimientos + *cant)->saldocuenta -= (*movimientos + *cant)->movimiento;
                    (*movimientos + *cant)->movimiento = -(*movimientos + *cant)->movimiento;
                }
                else
                {
                    printf("No se ha ingresado una opcion valida\n");
                    return;
                }
                printf("Tipo de cuenta:\na. Cuenta corriente\nb. Caja de ahorro\n");
                scanf(" %c", &cuenta);
                if (cuenta == 'a' || cuenta == 'A')
                {
                    strcat((*movimientos + *cant)->tipocuenta, "CuentaCorriente");
                }
                else if (cuenta == 'b' || cuenta == 'B')
                {
                    strcat((*movimientos + *cant)->tipocuenta, "CajaDeAhorro");
                }
                else
                {
                    printf("No se ha ingresado una opcion valida\n");
                }
                break;

            case 'n':
            case 'N':
                printf("Ingrese los datos del movimiento que se ha ejecutado\n");
                printf("Numero de cliente: ");
                scanf(" %d", &nrocliente);
                for (int i = 0; i < *cant; i++)
                {
                    if (nrocliente == (*movimientos + i)->nrocliente)
                    {
                        (*movimientos + *cant)->nrocliente = nrocliente;
                       
                        printf("Se ha ingresado dinero o se ha egresado dinero\?:\na. Ingreso\nb. "
                               "Egreso\n");
                        scanf(" %c", &tipomov);
                        printf("Monto de movimiento: ");
                        scanf(" %f", &(*movimientos + *cant)->movimiento);
                        if (tipomov == 'a' || tipomov == 'A')
                        {
                            (*movimientos + *cant)->saldocuenta = (*movimientos + i)->saldocuenta;
                            (*movimientos + *cant)->saldocuenta +=
                                (*movimientos + *cant)->movimiento;
                        }
                        else if (tipomov == 'b' || tipomov == 'B')
                        {
                            (*movimientos + *cant)->saldocuenta = (*movimientos + i)->saldocuenta;
                            (*movimientos + *cant)->saldocuenta -=
                                (*movimientos + *cant)->movimiento;
                            (*movimientos + *cant)->movimiento =
                                -(*movimientos + *cant)->movimiento;
                        }
                        else
                        {
                            printf("No se ha ingresado una opcion valida\n");
                            return;
                        }
                        printf("Tipo de cuenta:\na. Cuenta corriente\nb. Caja de ahorro\n");
                        scanf(" %c", &cuenta);
                        if (cuenta == 'a' || cuenta == 'A')
                        {
                            strcat((*movimientos + *cant)->tipocuenta, "CuentaCorriente");
                        }
                        else if (cuenta == 'b' || cuenta == 'B')
                        {
                            strcat((*movimientos + *cant)->tipocuenta, "CajaDeAhorro");
                        }
                        else
                        {
                            printf("No se ha ingresado una opcion valida\n");
                        }
                        if (strcmp((*movimientos + *cant)->tipocuenta,
                                   (*movimientos + i)->tipocuenta) != 0)
                        {
                            printf("El movimiento se esta ejecutando en un tipo de cuenta "
                                   "diferente al anterior\n");
                        }
                        nrocliente = 0;
                        bandera = 1;
                    }
                }
                if (bandera == 0)
                {
                    printf("El cliente con numero %d no ha ejecutado ningun movimiento "
                        "anteriormente\n",
                        nrocliente);
                        return;
                    }
                    bandera = 0;
                    break;
                    default:
                    printf("No ha ingresado una respuesta valida\n");
                    break;
                }
            }
            else
            {
                printf("Error al registrar movimiento\n");
                return;
            }
            (*cant)++;
            printf("Desea ingresar otro movimiento\?: Si(s), No(n)\n");
        scanf(" %c", &otro);
        bandera = 1;
    } while (otro == 's' || otro == 'S');
}

void GuardarMovimientos(Movimientos *movimientos, int cant)
{
    FILE *archivo;
    archivo = fopen("movimientos.txt", "w");
    if (archivo != NULL)
    {
        printf("\nGuardando movimientos...\n");
        printf("-------------------------------\n");
        for (int i = 0; i < cant; i++)
        {
            fprintf(archivo, "%d %.2f %.2f %s\n", (movimientos + i)->nrocliente,
                    (movimientos + i)->movimiento, (movimientos + i)->saldocuenta,
                    (movimientos + i)->tipocuenta);
        }
        fclose(archivo);
        printf("\nLos datos se han guardado con exito\n");
        printf("----------------------------------------\n");
    }
    else
    {
        printf("Error al guardar en archivo\n");
        return;
    }
}

void BuscarMostrar(Movimientos *movimientos, int cant)
{
    int nrocliente = 0;
    int bandera = 0;
    printf("Ingrese el numero del cliente que desea buscar: ");
    scanf(" %d", &nrocliente);

    for (int i = 0; i < cant; i++)
    {
        if (nrocliente == (movimientos + i)->nrocliente)
        {
            printf("El cliente con el numero %d efectuo el movimiento:\n", nrocliente);
            printf("%-10s | %-10s | %s\n", "Movimiento", "Saldo", "Tipo de cuenta");
            printf("%-10.2f | %-10.2f | %s\n", (movimientos + i)->movimiento,
                   (movimientos + i)->saldocuenta, (movimientos + i)->tipocuenta);
            bandera = 1;
        }
    }
    if (bandera == 0)
    {
        printf("No se ha encontrado el cliente con numero %d\n", nrocliente);
    }
    bandera = 0;
}

void Salir(Movimientos **movimientos, int *cant, char *volver)
{
    free(*movimientos);
    *movimientos = NULL;
    *cant = 0;
    *volver = 'n';
}
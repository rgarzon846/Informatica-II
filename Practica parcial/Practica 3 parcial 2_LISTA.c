/*Desarrolla un programa que permita la gestión de registro de ventas en una tienda de electronica de este año utilizando el TDA lista. 
Para ello cree la/las estructura/s que necesite para almacenar la siguiente información sobre código de producto (entero), 
nombre de producto (cadena), cantidad vendida, precio unitario, día y mes. Desarrolla las siguientes funciones para: 
Registrar una nueva venta. 
Mostrar un listado de todas las ventas por consola y generar un archivo .txt llamado "ventas.txt", ambos en formato tabla. 
Borrar una venta 
Mostrar un listado de ventas por mes en formato tabla. 
Calcular la cantidad de ventas mayores a 1000. 
Crea un menú de opciones para que el usuario pueda realizar diferentes acciones antes descritas. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int dia;
    int mes;
}Fecha;

typedef struct{
    int codigo;
    char nombre[25];
    int vendidos;
    float precio;
}Producto;

typedef struct Venta{
    Fecha fecha;
    Producto producto;
    struct Venta *sig;
}Venta;

void Menu();
void RegistrarVenta(Venta **);
void ImprimirVentas(Venta *);
void BorrarVenta(Venta **);
void VentasPorMes(Venta *);
int CalcularVentas(Venta *);
void Liberar(Venta **);

int main(){
    Menu();
    return 0;
}

void Menu(){
    Venta *lista = NULL;
    char opcion = ' ';

    do{
        printf("\n*********MENU*********\n");
        printf("a) Registrar una venta nueva\n");
        printf("b) Imprimir ventas registradas y crear archivo con las mismas\n");
        printf("c) Borrar una venta\n");
        printf("d) Ver ventas ordenadas por mes\n");
        printf("e) Calcular ventas de mas de 1000 unidades\n");
        printf("f) Salir del menu\n");
        scanf(" %c", &opcion);

        switch(opcion){
            case 'a':
            case 'A': char otro = 's';
            while(otro == 's' || otro == 'S'){
                RegistrarVenta(&lista);
                printf("\nDesea registrar otra venta\?: Si(s), No(n)\n");
                scanf(" %c", &otro);
            }
            break;
            case 'b':
            case 'B': if(lista != NULL){
                ImprimirVentas(lista);
            }else{
                printf("\nAun no ha ingresado ventas al registro\n");
            }
            break;
            case 'c':
            case 'C': if(lista != NULL){
                BorrarVenta(&lista);
            }else{
                printf("\nAun no ha ingresado ventas al registro\n");
            }
            break;
            case 'd':
            case 'D': if(lista != NULL){
                VentasPorMes(lista);
            }else{
                printf("\nAun no ha ingresado ventas al registro\n");
            }
            break;
            case 'e':
            case 'E': if(lista != NULL){
                printf("Las ventas mayores a 1000 unidades son %d\n", CalcularVentas(lista));
            }else{
                printf("\nAun no ha ingresado ventas al registro\n");
            }
            break;
            case 'f':
            case 'F': if(lista != NULL){
                Liberar(&lista);
            }else{
                printf("\nSaliendo del menu, lista vacia\n");
            }
            break;
        }
    }while(opcion != 'f' && opcion != 'F');
}

void RegistrarVenta(Venta **lista){
    Venta *nuevo = (Venta *) malloc(sizeof(Venta));

    if(nuevo == NULL){
        printf("\nError al crear nueva venta\n");
    }else{
        nuevo->sig = NULL;
        printf("\nIngrese los siguientes datos del producto vendido:\n");
        printf("Codigo: ");
        scanf(" %d", &nuevo->producto.codigo);
        printf("Nombre: ");
        getchar();
        fgets(nuevo->producto.nombre, 25, stdin);
        nuevo->producto.nombre[strcspn(nuevo->producto.nombre, "\n")] = '\0';
        printf("Cantidad de unidades vendidas: ");
        scanf(" %d", &nuevo->producto.vendidos);
        printf("Precio: ");
        scanf(" %f", &nuevo->producto.precio);
        printf("Dia en que fue vendido: ");
        scanf(" %d", &nuevo->fecha.dia);
        printf("Mes en que fue vendido: ");
        scanf(" %d", &nuevo->fecha.mes);

        if(*lista == NULL){
            *lista = nuevo;
        }else{
            Venta *aux = *lista;
            while(aux->sig != NULL){
                aux = aux->sig;
            }
            aux->sig = nuevo;
        }
        printf("\nVenta registrada con exito\n");
    }
}

void ImprimirVentas(Venta *lista){
    Venta *aux = lista;

    printf("\nLas ventas registradas hasta el momento son:\n");
    printf("%-10s | %-25s | %-12s | %-10s | %-3s | %s\n", "Codigo", "Nombre", "Unidades", "Precio", "Dia", "Mes");
    while(aux != NULL){
        printf("%-10d | %-25s | %-12d | %-10.2f | %-3d | %d\n", aux->producto.codigo, aux->producto.nombre, aux->producto.vendidos, aux->producto.precio, aux->fecha.dia, aux->fecha.mes);
        aux = aux->sig;
    }

    aux = lista;

    FILE *archivo = fopen("ventas.txt", "w");

    if(archivo == NULL){
        printf("\nError al abrir el archivo\n");
    }else{
        fprintf(archivo, "%-10s | %-25s | %-12s | %-10s | %-3s | %s\n", "Codigo", "Nombre", "Unidades", "Precio", "Dia", "Mes");
        while(aux != NULL){
        fprintf(archivo, "%-10d | %-25s | %-12d | %-10.2f | %-3d | %d\n", aux->producto.codigo, aux->producto.nombre, aux->producto.vendidos, aux->producto.precio, aux->fecha.dia, aux->fecha.mes);
        aux = aux->sig;
        }
        fclose(archivo);
        printf("\nEl archivo se ha actualizado con las ventas registradas\n");
    }
}

void BorrarVenta(Venta **lista){
    int codigo = 0;
    Venta *aux = *lista;
    Venta *ant = NULL;
    Fecha fecha;
    Producto producto;

    printf("\nIngrese el codigo del producto de la venta que desee eliminar: ");
    scanf(" %d", &codigo);
    
    while(aux != NULL && aux->producto.codigo != codigo){
        ant = aux;
        aux = aux->sig;
    }

    if(aux != NULL){
        if(ant == NULL){
            *lista = aux->sig;
        }else{
            ant->sig = aux->sig;
        }
        fecha = aux->fecha;
            producto = aux->producto;
            printf("\nSe ha eliminado la venta:\n");
            printf("%-10d | %-25s | %-12d | %-10.2f | %-3d | %d\n", producto.codigo, producto.nombre, producto.vendidos, producto.precio, fecha.dia, fecha.mes);
        free(aux);
    }else{
        printf("\nNo se ha encontrado la venta que desea eliminar\n");
    }
}

void VentasPorMes(Venta *lista){
    Venta *temp = NULL;
    Venta *aux = lista;

    while(aux != NULL){
    Venta *nuevo = malloc(sizeof(Venta));
    if(nuevo == NULL){
        printf("\nNo se puede crear la lista auxiliar\n");
    }else{
        nuevo->sig = NULL;
        nuevo->fecha = aux->fecha;
        nuevo->producto = aux->producto;

        if(temp == NULL){
            temp = nuevo;
        }else{
            Venta *auxtemp = temp;
            while(auxtemp->sig != NULL){
                auxtemp = auxtemp->sig;
            }
            auxtemp->sig = nuevo;
        }
    }
    aux = aux->sig;
}
    Venta menor;

    for(Venta *i = temp; i != NULL; i = i->sig){
        for(Venta *j = i->sig; j != NULL; j = j->sig){
            if(i->fecha.mes > j->fecha.mes){
                menor.fecha = i->fecha;
                menor.producto = i->producto;
                i->fecha = j->fecha;
                i->producto = j->producto;
                j->fecha = menor.fecha;
                j->producto = menor.producto;
            }
        }
    }

    Venta *auxtemp = temp;

    printf("\nLas ventas registradas hasta el momento ordenadas por mes son:\n");
    printf("%-10s | %-25s | %-12s | %-10s | %-3s | %s\n", "Codigo", "Nombre", "Unidades", "Precio", "Dia", "Mes");
    while(auxtemp != NULL){
        printf("%-10d | %-25s | %-12d | %-10.2f | %-3d | %d\n", auxtemp->producto.codigo, auxtemp->producto.nombre, auxtemp->producto.vendidos, auxtemp->producto.precio, auxtemp->fecha.dia, auxtemp->fecha.mes);
        auxtemp = auxtemp->sig;
    }
}


int CalcularVentas(Venta *lista){
    Venta *aux = lista;
    int cont = 0;

    while(aux != NULL){
        if(aux->producto.vendidos > 1000){
            cont++;
        }
        aux = aux->sig;
    }

    return cont;
}

void Liberar(Venta **lista){
    while(*lista != NULL){
        Venta *prox = (*lista)->sig;
        free(*lista);
        *lista = prox;
    }
    printf("\nSe ha liberado la lista con exito\n");
}
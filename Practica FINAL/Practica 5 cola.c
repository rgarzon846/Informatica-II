/*Desarrolla un programa que permita la gestión de registro de ventas en una tienda de 
electronica de este año utilizando el TDA lista. Para ello cree la/las estructura/s 
que necesite para almacenar la siguiente información sobre código de producto (entero), 
nombre de producto (cadena), cantidad vendida, precio unitario, día y mes. Desarrolla las siguientes funciones para: 

Registrar una nueva venta.
Mostrar un listado de todas las ventas por consola y generar un archivo .txt llamado "ventas.txt", ambos en formato tabla. 
Borrar una venta 
Mostrar un listado de ventas por mes en formato tabla. 
Calcular la cantidad de ventas mayores a 1000. 
Crea un menú de opciones para que el usuario pueda realizar diferentes acciones antes descritas.*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int codigo;
    char nombre[25];
    int vendidos;
    float preciounidad;
    int dia;
    int mes;
}Producto;

typedef struct Cola{
    Producto producto;
    struct Cola *sig;
}Cola;

void Menu();
void RegistrarVenta(Cola **, Cola **);
void ImprimirVentas(Cola *);
void BorrarVenta(Cola **, Cola **);
void VentasMes(Cola *);
int CalcularVentas(Cola *);
int ColaVacia(Cola *);
void LiberarCola(Cola **, Cola **);


int main(){
    Menu();
    return 0;
}

void Menu(){
    Cola *frente = NULL;
    Cola *fin = NULL;
    int opcion = 0;

    do{
        printf("\n~~~~~~~~~MENU DE OPCIONES~~~~~~~~~\n");
        printf("1) Registrar una nueva venta\n");
        printf("2) Imprimir las ventas registradas y crear un archivo con las mismas\n");
        printf("3) Borrar una venta del registro\n");
        printf("4) Buscar ventas de un mes en especifico\n");
        printf("5) Calcular las ventas mayores a 1000 pesos\n");
        printf("6) Salir\n");
        scanf(" %d", &opcion);

        switch(opcion){
            case 1: char otro = 's';
            while(otro == 's' || otro == 'S'){
                RegistrarVenta(&frente, &fin);
                printf("\nDesea registrar otra venta\?: Si(S), No(N): ");
                scanf(" %c", &otro);
            }
            break;
            case 2: if(ColaVacia(frente)){
                ImprimirVentas(frente);
            }else{
                printf("\nAun no se ha registrado ninguna venta\n");
            }
            break;
            case 3: if(ColaVacia(frente)){
                BorrarVenta(&frente, &fin);
            }else{
                printf("\nAun no se ha registrado ninguna venta\n");
            }
            break;
            case 4: if(ColaVacia(frente)){
                VentasMes(frente);
            }else{
                printf("\nAun no se ha registrado ninguna venta\n");
            }
            break;
            case 5: if(ColaVacia(frente)){
                printf("\nLa cantidad de ventas mayores a 1000 pesos es de: %d\n", CalcularVentas(frente));
            }else{
                printf("\nAun no se ha registrado ninguna venta\n");
            }
            break;
            case 6: if(ColaVacia(frente)){
                LiberarCola(&frente, &fin);
            }else{
                printf("\nSaliendo... Ninguna venta registrada\n");
            }
            break;
            default: printf("\nNo se ha elegido una opcion valida\n");
            break;
        }

    }while(opcion != 6);
}

void RegistrarVenta(Cola **frente, Cola **fin){
    Cola *nuevo = (void *) malloc(sizeof(Cola));
    if(nuevo != NULL){
        printf("\nIngrese la informacion solicitada sobre el producto vendido:\n");
        printf("Codigo: ");
        scanf(" %d", &nuevo->producto.codigo);
        printf("Nombre: ");
        getchar();
        fgets(nuevo->producto.nombre, 25, stdin);
        nuevo->producto.nombre[strcspn(nuevo->producto.nombre, "\n")] = '\0';
        printf("Cantidad de unidades vendidas: ");
        scanf(" %d", &nuevo->producto.vendidos);
        printf("Precio de la unidad: ");
        scanf(" %f", &nuevo->producto.preciounidad);
        printf("Dia de la venta: ");
        scanf(" %d", &nuevo->producto.dia);
        printf("Mes de la venta: ");
        scanf(" %d", &nuevo->producto.mes);

        if(*fin == NULL){
            *frente = nuevo;
            *fin = nuevo;
        }else{
            (*fin)->sig = nuevo;
            *fin = nuevo;
        }
        printf("\nLa venta se ha registrdo con exito\n");
    }else{
        printf("\nError al registrar nueva venta\n");
    }
}

void ImprimirVentas(Cola *frente){
    Cola *aux = frente;

    printf("\nLas ventas registradas hasta el momento son:\n");
    printf("%-10s | %-25s | %-15s | %-10s | %-4s | %s\n", "Codigo", "Nombre", "Vendidos", "Precio", "Dia", "Mes");
    while(aux != NULL){
        printf("%-10d | %-25s | %-15d | %-10.2f | %-4d | %d\n", aux->producto.codigo, aux->producto.nombre, aux->producto.vendidos, aux->producto.preciounidad,
            aux->producto.dia, aux->producto.mes);
        aux = aux->sig;
    }

    aux = frente;

    FILE *archivo = fopen("ventas.txt", "w");
    if(archivo != NULL){
        fprintf(archivo, "%-10s | %-25s | %-15s | %-10s | %-4s | %s\n", "Codigo", "Nombre", "Vendidos", "Precio", "Dia", "Mes");
        while(aux != NULL){
        fprintf(archivo, "%-10d | %-25s | %-15d | %-10.2f | %-4d | %d\n", aux->producto.codigo, aux->producto.nombre, aux->producto.vendidos, aux->producto.preciounidad,
            aux->producto.dia, aux->producto.mes);
        aux = aux->sig;
    }
    fclose(archivo);
    printf("\nEl archivo con las ventas registradas se ha actualizado con exito\n");
    }else{
        printf("\nNo se ha podido crear el archivo con las ventas registradas\n");
    }
}

void BorrarVenta(Cola **frente, Cola **fin){
    Producto producto = (*frente)->producto;
    Cola *aux = *frente;

    *frente = aux->sig;
    if(*frente == NULL){
        *fin = NULL;
    }
    free(aux);

    printf("\nEl producto eliminado ha sido el producto:\n");
    printf("%-10s | %-25s | %-15s | %-10s | %-4s | %s\n", "Codigo", "Nombre", "Vendidos", "Precio", "Dia", "Mes");
    printf("%-10d | %-25s | %-15d | %-10.2f | %-4d | %d\n", producto.codigo, producto.nombre, producto.vendidos, producto.preciounidad,
            producto.dia, producto.mes);
}

void VentasMes(Cola *frente){
    Cola *aux = frente;
    int mes = 0;
    int bandera = 0;
    
    printf("\nIngrese el numero de mes que desee ver las ventas: ");
    scanf(" %d", &mes);

    printf("\nLas ventas del mes %d:\n", mes);
    printf("%-10s | %-25s | %-15s | %-10s | %-4s | %s\n", "Codigo", "Nombre", "Vendidos", "Precio", "Dia", "Mes");
    while(aux != NULL){
        if(aux->producto.mes == mes){
            printf("%-10d | %-25s | %-15d | %-10.2f | %-4d | %d\n", aux->producto.codigo, aux->producto.nombre, aux->producto.vendidos, aux->producto.preciounidad,
            aux->producto.dia, aux->producto.mes);
            bandera = 1;
        }
        aux = aux->sig;
    }
    if(bandera == 0){
        printf("\nNo se han encontrado ventas en el mes %d", mes);
    }
    bandera = 0;
}

int CalcularVentas(Cola *frente){
    int suma = 0;
    Cola *aux = frente;

    while(aux != NULL){
        if((aux->producto.vendidos*aux->producto.preciounidad) > 1000){
            suma++;
        }
        aux = aux->sig;
    }

    return suma;
}

int ColaVacia(Cola *frente){
    if(frente == NULL){
        return 0;
    }else{
        return 1;
    }
}

void LiberarCola(Cola **frente, Cola **fin){
    while(*frente != NULL){
        Cola *prox = (*frente)->sig;
        free(*frente);
        *frente = prox;
    }
    *fin = NULL;
    printf("\nSe ha liberado la cola con exito\n");
}


/*Crear una estructura llamada producto con los siguientes atributos código, nombre, stock, cantidad
vendida. Crear un vector de estructuras del tipo producto (max 10). Luego crear un menú de opciones:
mostrar todos los productos
cargar una venta (debe buscar y restar el stock y sumar la cant vendida)
reponer mercadería (debe buscar y sumar el stock)
ordenar por productos más vendidos
ordenar por productor con menor stock
*/

#include <stdio.h>
#include <string.h>
#define MAX 10

struct Producto
{
    long codigo;
    int stock;
    int vendido;
    char nombre[20];
};

void CargarProductos(struct Producto[], int *);
void MostrarProductos(struct Producto[], int *);
void CargarVenta(struct Producto[], int *);
void ReponerMerca(struct Producto[], int *);
void OrdenarMasVendidos(struct Producto[], int *);
void OrdenarStock(struct Producto[], int *);
void Menu(struct Producto[]);

int main()
{
    struct Producto productos[MAX];
    Menu(productos);
    return 0;
}

void Menu(struct Producto productos[MAX])
{
    int cant = 0;
    int *p = &cant;
    char opcion = ' ';
    char volver = 's';
    
    CargarProductos(productos, p);
    do
    {
        printf("\nIngrese la opcion que desee ejecutar:\n");
        printf("a. Mostrar productos\n");
        printf("b. Cargar venta\n");
        printf("c. Reponer mercaderia\n");
        printf("d. Ordenar por cantidad de ventas\n");
        printf("e. Ordenar por stock\n");
        scanf(" %c", &opcion);

        switch (opcion)
        {
        case 'a':
        case 'A':
            MostrarProductos(productos, p);
            break;
        case 'b':
        case 'B':
            CargarVenta(productos, p);
            break;
        case 'c':
        case 'C':
            ReponerMerca(productos, p);
            break;
        case 'd':
        case 'D':
            OrdenarMasVendidos(productos, p);
            break;
        case 'e':
        case 'E':
            OrdenarStock(productos, p);
            break;
        default:
            printf("La opcion elegida no es valida, vuelva a ingresar\n");
            break;
        }
        printf("Desea volver al menu\?: Si(s), No(n)\n");
        scanf(" %c", &volver);
    } while (volver == 's' || volver == 'S');
}

void MostrarProductos(struct Producto productos[MAX], int *p)
{
    printf("\nLos productos agregados son:\n");
    printf("%-20s | %20s | %-8s | %s\n", "Nombre", "Codigo", "Vendidos", "Stock");
    for (int i = 0; i < *p; i++)
    {
        printf("%-20s | %20ld | %-8d | %d\n", productos[i].nombre, productos[i].codigo,
               productos[i].vendido, productos[i].stock);
    }
}

void CargarProductos(struct Producto productos[MAX], int *p)
{
    char bandera = 's';

    printf("Ingrese los productos que desee\n");
    for (int i = 0; i < MAX; i++)
    {
        if (bandera == 's' || bandera == 'S')
        {
            printf("\nNombre del producto:\n");
            fgets(productos[i].nombre, 20, stdin);
            productos[i].nombre[strcspn(productos[i].nombre, "\n")] = '\0';
            printf("\nCodigo del producto:\n");
            scanf(" %ld", &productos[i].codigo);
            printf("\nStock disponible del producto:\n");
            scanf(" %d", &productos[i].stock);
            printf("\nProducto cargado con exito\n");
            productos[i].vendido = 0;
            *p = i+1;
            if (i < MAX - 1)
            {
                printf("\nDesea cargar otro producto\?: Si(s), No(n)\n");
                scanf(" %c", &bandera);
                getchar();
            }
        }
    }
}

void CargarVenta(struct Producto productos[MAX], int *p)
{
    char producto[20];
    int cantvendidos = 0;
    char otro = 's';
    int bandera = 0;
    int i;

    do
    {
        printf("\nIngrese el nombre del producto vendido:\n");
        getchar();
        fgets(producto, 20, stdin);
        producto[strcspn(producto, "\n")] = '\0';

        for (i = 0; i < *p; i++)
        {
            if (strcmp(producto, productos[i].nombre) == 0)
            {
                printf("\nIngrese la cantidad de unidades vendidas:\n");
                scanf(" %d", &cantvendidos);
                productos[i].stock = productos[i].stock -= cantvendidos;
                productos[i].vendido = productos[i].vendido += cantvendidos;
                bandera = 1;
                printf("Venta cargada con exito\n");
            }
        }
        if (bandera == 0)
        {
            printf("\nEl producto no existe, ingreselo y vuelva a intentar\n");
        }
        bandera = 0;
        printf("\nDesea ingresar otra venta\?: Si(s), No(n)\n");
        scanf(" %c", &otro);
    }while (otro == 's' || otro == 'S');
}

void ReponerMerca(struct Producto productos[MAX], int *p)
{
    char producto[20];
    int cantreponer = 0;
    char otro = 's';
    int bandera = 0;
    int i;

    do
    {
        printf("\nIngrese le nombre del producto que desee reponer:\n");
        getchar();
        fgets(producto, 20, stdin);
        producto[strcspn(producto, "\n")] = '\0';

        for (i = 0; i < *p; i++)
        {
            if (strcmp(producto, productos[i].nombre) == 0)
            {
                printf("\nIngrese la cantidad de unidades a reponer:\n");
                scanf(" %d", &cantreponer);
                productos[i].stock = productos[i].stock += cantreponer;
                bandera = 1;
                printf("Reposicion cargada con exito\n");
            }
        }
        if (bandera == 0)
        {
            printf("\nEl producto no existe, ingreselo y vuelva a intentar\n");
        }
        bandera = 0;
        printf("\nDesea reponer otro producto\?: Si(s), No(n)\n");
        scanf(" %c", &otro);
    } while (otro == 's' || otro == 'S');
}

void OrdenarMasVendidos(struct Producto productos[MAX], int *p)
{
    struct Producto aux;

    printf("\nLos productos del mas al menos vendido:\n");
    for (int i = 0; i < *p-1; i++)
    {
        for(int j = 0; j < *p-1-i; j++){
        if (productos[j].vendido < productos[j+1].vendido)
        {
            aux = productos[j];
            productos[j] = productos[j+1];
            productos[j+1] = aux;
        }
    }
}
    printf("%-20s | %20s | %-8s | %s\n", "Nombre", "Codigo", "Vendidos", "Stock");
    for (int i = 0; i < *p; i++)
    {
        printf("%-20s | %20ld | %-8d | %d\n", productos[i].nombre, productos[i].codigo,
               productos[i].vendido, productos[i].stock);
    }
}

void OrdenarStock(struct Producto productos[MAX], int *p)
{
    struct Producto aux;
    
    for (int i = 0; i < *p-1; i++)
    {
        for(int j = 0; j < *p-1-i; j++){
        if (productos[j].stock > productos[j+1].stock)      //Si se tiene mas de dos o tres miembros en el array de estructura debe utilizarse metodo con for anidado en el ordenamiento
        {
            aux = productos[j+1];
            productos[j+1] = productos[j];
            productos[j] = aux;
        }
    }
}
    printf("\nLos productos que tienen menos a los que tienen mas stock:\n");
    printf("%-20s | %20s | %-8s | %s\n", "Nombre", "Codigo", "Vendidos", "Stock");
    for (int i = 0; i < *p; i++)
    {
        printf("%-20s | %20ld | %-8d | %d\n", productos[i].nombre, productos[i].codigo,
               productos[i].vendido, productos[i].stock);
    }
}
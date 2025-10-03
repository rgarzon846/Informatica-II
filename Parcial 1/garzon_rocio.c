// TEMA B.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Estructutra de la variable vuelos
typedef struct
{
    long codigo_vuelo;
    char origen[25];
    char destino[25];
    int capacidad_pasajeros;
    int asientos_reservados;
    float precio_pasaje;
    int dato1;
    char dato2[30];
    float dato3;
} Vuelo;

//Prototipos de funciones
void RegistrarVuelo(Vuelo **, int *);
void GuardarVuelos(Vuelo *, int);
void BuscarMostrar(Vuelo *, int);
void Salir(Vuelo **, int *, char *);
void AgregarUnDato(Vuelo **, int);
void Menu();

int main() { 
    Menu();
    return 0; }

void Menu()
{
    Vuelo *vuelos = NULL;
    int cant = 0;
    char volver = 's';
    char opcion = ' ';
    do
    {
        printf("*************** MENU ***************\n");
        printf("Ingrese la opcion que desea ejecutar\n");
        printf("a. Registrar un nuevo vuelo\n");
        printf("b. Guardar los vuelos ingresados en un archivo\n");
        printf("c. Buscar vuelos hacia un destino especifico\n");
        printf("d. Agregar mas datos en la estructura del vuelo\n");
        printf("e. Salir\n");
        scanf(" %c", &opcion);

        switch (opcion)
        {
        case 'a':
        case 'A':
            RegistrarVuelo(&vuelos, &cant);
            break;
        case 'b':
        case 'B':
            GuardarVuelos(vuelos, cant);
            break;
        case 'c':
        case 'C':
            BuscarMostrar(vuelos, cant);
            break;
        case 'd':
        case 'D': 
            AgregarUnDato(&vuelos, cant);
            break;
        case 'e':
        case 'E':
            Salir(&vuelos, &cant, &volver);
            break;
        default:
            printf("No se ha introducido una opcion valida\n");
            break;
        }
        if (opcion != 'e' && opcion != 'E')
        {
            printf("Desea volver al menu\?: Si(s), No(n)\n");
            scanf(" %c", &volver);
        }
    } while (volver == 'S' || volver == 's');

    free(vuelos);
    vuelos = NULL;
}

//Utilizamos puntero a puntero para modificar el tamanio del array de estructuras
void RegistrarVuelo(Vuelo **vuelos, int *cant)
{
    char otro = 's';
    Vuelo *vuelos2 = NULL;
    do
    {
        vuelos2 = (Vuelo *)realloc(*vuelos, (*cant + 1) * sizeof(Vuelo));
        if (vuelos2 != NULL)
        {
            *vuelos = vuelos2;
            printf("Ingrese los datos solicitados para registrar un nuevo vuelo\n");
            printf("Codigo de vuelo: ");
            scanf(" %ld", &(*vuelos + *cant)->codigo_vuelo);
            printf("Lugar de origen: ");
            getchar();
            fgets((*vuelos + *cant)->origen, 25, stdin);
            (*vuelos + *cant)->origen[strcspn((*vuelos + *cant)->origen, "\n")] = '\0';
            printf("Lugar de destino: ");
            fgets((*vuelos + *cant)->destino, 25, stdin);
            (*vuelos + *cant)->destino[strcspn((*vuelos + *cant)->destino, "\n")] = '\0';
            printf("Capacidad de pasajeros: ");
            scanf(" %d", &(*vuelos + *cant)->capacidad_pasajeros);
            printf("Asientos reservados: ");
            scanf(" %d", &(*vuelos + *cant)->asientos_reservados);
            printf("Valor del pasaje: ");
            scanf(" %f", &(*vuelos + *cant)->precio_pasaje);
            (*cant)++;
            printf("\nDesea registrar otro vuelo\?: Si(s), No(n)");
            scanf(" %c", &otro);
        }
        else
        {
            printf("Error al ingresar nuevo vuelo\n");
            return;
        }

    } while (otro == 's' || otro == 'S');
}

//Se guardan los vuelos ingresados en el archivo
void GuardarVuelos(Vuelo *vuelos, int cant)
{
    FILE *archivo;
    archivo = fopen("vuelos.txt", "w");
    if (archivo != NULL)
    {
        printf("Guardando datos...\n");
        printf("------------------------------\n");
        for (int i = 0; i < cant; i++)
        {
            fprintf(archivo, "%ld %s %s %d %d %.2f %d %s %.2f\n", (vuelos + i)->codigo_vuelo,
                    (vuelos + i)->origen, (vuelos + i)->destino, (vuelos + i)->capacidad_pasajeros,
                    (vuelos + i)->asientos_reservados, (vuelos + i)->precio_pasaje, (vuelos + i)->dato1, (vuelos + i)->dato2, (vuelos + i)->dato3);
        }
        fclose(archivo);
        printf("Datos guardados con exito\n");
        printf("----------------------------------\n");
    }
    else
    {
        printf("\nError al abrir el archivo\n");
        return;
    }
}

//Realiza la busqueda del destino que se ingrese
void BuscarMostrar(Vuelo *vuelos, int cant)
{
    char destino[25];
    int bandera = 0;
    printf("Ingrese el destino que desea buscar: ");
    getchar();
    fgets(destino, 25, stdin);
    destino[strcspn(destino, "\n")] = '\0';
    printf("\nLos vuelos encontrados para el destino %s son:\n", destino);

    for (int i = 0; i < cant; i++)
    {
        if (strcmp(destino, (vuelos + i)->destino) == 0)
        {
            printf("%-20s | %-25s | %-20s | %-20s | %s\n", "Codigo de vuelo", "Origen",
                   "Capacidad pasajeros", "Asientos reservados", "Precio pasaje");
            printf("%-20ld | %-25s | %-20d | %-20d | %.2f\n", (vuelos + i)->codigo_vuelo,
                   (vuelos + i)->origen, (vuelos + i)->capacidad_pasajeros,
                   (vuelos + i)->asientos_reservados, (vuelos + i)->precio_pasaje);
            bandera = 1;
        }
    }
    if (bandera == 0)
    {
        printf("No se han encontrado vuelos para el destino ingresado\n");
    }
    bandera = 0;
}

//Libera la memoria y sale del menu
void Salir(Vuelo **vuelos, int *cant, char *volver)
{
    free(*vuelos);
    *vuelos = NULL;
    *cant = 0;
    *volver = 'n';
}

//Agrega un nuevo dato si se desea, se mostrara en las columnas "Dato entero", "Dato cadena" o "Dato decimal" segun que tipo de dato se haya ingresado. Modifica todos los vuelos
void AgregarUnDato(Vuelo **vuelos, int cant){
    char opcion = ' ';
    printf("Ingrese la opcion del tipo de dato que desea agregar\n");
    printf("a. Valor entero\n");
    printf("b. Cadena de texto\n");
    printf("c. Valor decimal\n");
    scanf(" %c", &opcion);

    switch(opcion){
        case 'a':
        case 'A': 
        for(int i = 0; i < cant; i++){
            scanf(" %d", &(*vuelos + i)->dato1);
        }
        break;
        case 'b': 
        case 'B': 
        getchar();
        for(int i = 0; i < cant; i++){
            fgets((*vuelos + i)->dato2, 25, stdin);
            (*vuelos + i)->dato2[strcspn((*vuelos + i)->dato2, "\n")] = '\0';
        }
        break;
        case 'c':
        case 'C':
        for(int i = 0; i < cant; i++){
            scanf(" %f", &(*vuelos + i)->dato3);
        }
        break;
        default: printf("No ha ingresado una opcion valida\n");
        break;
    }
    for (int i = 0; i < cant; i++)
    {
            printf("%-20s | %-25s | %-25s | %-20s | %-20s | %-20s | %-20s | %-25s | %s\n", "Codigo de vuelo", "Origen",
                   "Destino", "Capacidad pasajeros", "Asientos reservados", "Precio pasaje", "Dato entero", "Dato cadena", "Dato decimal");
            printf("%-20ld | %-25s | %-25s | %-20d | %-20d | %-20.2f | %-20d | %-25s | %.2f\n", (*vuelos + i)->codigo_vuelo,
                   (*vuelos + i)->origen, (*vuelos + i)->destino, (*vuelos + i)->capacidad_pasajeros,
                   (*vuelos + i)->asientos_reservados, (*vuelos + i)->precio_pasaje, (*vuelos + i)->dato1, (*vuelos + i)->dato2, (*vuelos + i)->dato3);
    }

}
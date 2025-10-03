/*Crear un programa que gestione el listado de los empleados de la empresa. Para ello crear una estructura Empleado,
en la cual contenga los siguientes datos: legajo, puesto de trabajo, sueldo y anios_antiguedad. 
Luego, crear un vector de estructuras del tipo empleado de tamanio 3. Crear un menu que permita las opciones: 
agregar un empleado
mostrar todos los empleados
buscar un empleado por legajo para ver si existe o no.
actualizarSueldo(float porcentaje)
ordenar por sueldo
ordenar por anios_antiguedad
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Legajo{
    int nrolegajo;
    int dni;
    char nombre[20];
    char apellido[20];
};

struct Empleado{
    struct Legajo legajo;
    char puesto[20];
    int sueldo;
    int antiguedad;
};

void AgregarEmpleado(struct Empleado[], int *);
void MostrarEmpleados(struct Empleado[], int *);
void BuscarLegajo(struct Empleado[], int *);
void ActualizarSueldo(struct Empleado[], int *);
void OrdenarSueldo(struct Empleado[], int *);
void OrdenarAntiguedad(struct Empleado[], int *);
void Menu(struct Empleado[]);

int main(){
struct Empleado empleados[3];
Menu(empleados);
    return 0;
}

void Menu(struct Empleado empleados[3]){
int cant = 0;
int *p = &cant;
char opcion = ' ';
char volver = 's';

do{
    printf("Ingrese la opcion que desee ejecutar:\n");
    printf("a. Agregar un empleado\n");
    printf("b. Mostrar todos los empleados\n");
    printf("c. Buscar empleado por legajo\n");
    printf("d. Actualizar sueldo\n");
    printf("e. Ordenar por sueldo (menor a mayor)\n");
    printf("f. Ordenar por antiguedad(menor a mayor)\n");
    scanf(" %c", &opcion);

    switch(opcion)
    {
    case 'a':
    case 'A':
        AgregarEmpleado(empleados, p); break;
    case 'b':
    case 'B':
        MostrarEmpleados(empleados, p); break;
    case 'c':
    case 'C':
        BuscarLegajo(empleados, p); break;
    case 'd':
    case 'D': 
        ActualizarSueldo(empleados, p); break;
    case 'e':
    case 'E': 
        OrdenarSueldo(empleados, p); break;
    case 'f':
    case 'F':
        OrdenarAntiguedad(empleados, p); break;
    default: printf("\nNo se ha ingresado una opcion valida\n"); break;
    }

    printf("\nDesea volver al menu\?: Si(s), No(n)\n");
    scanf(" %c", &volver);
}while(volver == 'S' || volver == 's');
}

void AgregarEmpleado(struct Empleado empleados[], int *p){
    char ingresar = 's';

    for(int i = 0; i < 3; i++){
        if(ingresar == 's' || ingresar == 'S'){
        printf("Ingrese la informacion del legajo del nuevo empleado:\n");
        printf("Nro de legajo: ");
        scanf(" %d", &empleados[i].legajo.nrolegajo);
        printf("\nIngrese el DNI: ");
        scanf(" %d", &empleados[i].legajo.dni);
        printf("\nIngrese el nombre: ");
        getchar();
        fgets(empleados[i].legajo.nombre, 20, stdin);
        empleados[i].legajo.nombre[strcspn(empleados[i].legajo.nombre, "\n")] = '\0';
        printf("\nIngrese el apellido: ");
        fgets(empleados[i].legajo.apellido, 20, stdin);
        empleados[i].legajo.apellido[strcspn(empleados[i].legajo.apellido, "\n")] = '\0';
        printf("\nIngrese el puesto: ");
        fgets(empleados[i].puesto, 20, stdin);
        empleados[i].puesto[strcspn(empleados[i].puesto, "\n")] = '\0';
        printf("\nIngrese el sueldo del nuevo empleado: ");
        scanf(" %d", &empleados[i].sueldo);
        printf("\nIngrese la antiguedad del empleado: ");
        scanf(" %d", &empleados[i].antiguedad);
        printf("\nSe ha ingresado el empleado con exito\n");
        *p = i+1;
        if(i < 2 && ingresar == 's' || ingresar == 'S'){
        printf("Desea ingresar otro empleado\?: Si(S), No(N)\n");
        scanf(" %c", &ingresar);
        }
    }
    }
}

void MostrarEmpleados(struct Empleado empleados[], int *p){
    printf("%-6s | %-10s | %-20s | %-20s | %-20s | %-20s | %s\n", "Legajo", "DNI", "Nombre", "Apellido", "Puesto", "Sueldo(pesos)", "Antiguedad(anios)");
    for(int i = 0; i < *p; i++){
        printf("%-6d | %-10d | %-20s | %-20s | %-20s | %-20d | %d\n", 
            empleados[i].legajo.nrolegajo, 
            empleados[i].legajo.dni, 
            empleados[i].legajo.nombre, 
            empleados[i].legajo.apellido, 
            empleados[i].puesto, 
            empleados[i].sueldo, 
            empleados[i].antiguedad);
        }
}

void BuscarLegajo(struct Empleado empleados[], int *p){
    char opcion = ' ';
    int Nrolegajo = 0;
    int dniempleado = 0;
    int bandera = 0;
    char otro = ' ';

    do{
    printf("Por que dato del legajo desea buscar al empleado\?:\n");
    printf("a. Nro de legajo\n");
    printf("b. DNI del empleado\n");
    scanf(" %c", &opcion);

    switch(opcion){
        case 'a':
        case 'A':
            printf("Ingrese el nro de legajo que desea buscar:\n");
            scanf(" %d", &Nrolegajo);
            for(int i = 0; i < *p; i++){
            if(empleados[i].legajo.nrolegajo == Nrolegajo){
                printf("El nro de legajo %d pertenece al empleado %s %s\n", Nrolegajo, empleados[i].legajo.nombre, empleados[i].legajo.apellido);
                bandera = 1;
            }
            }if(bandera == 0){
                printf("\nNo se ha encontrado el empleado con nro de legajo %d\n", Nrolegajo);
            }
            bandera = 0;
        break;
        case 'b':
        case 'B':
            printf("Ingrese el DNI del empleado:\n");
            scanf(" %d", &dniempleado);
            for(int i = 0; i < *p; i++){
                if(empleados[i].legajo.dni == dniempleado){
                    printf("\nEl DNI ingresado pertenece al empleado %s %s\n", empleados[i].legajo.nombre, empleados[i].legajo.apellido);
                    bandera = 1;
                }
            }
            if(bandera == 0){
                printf("\nEl DNI ingresado no pertenece a ningun empleado\n");
                printf("Desea elegir otro metodo de busqueda\?: Si(s), No(n)\n");
                scanf(" %c", &otro);
            }
            bandera = 0;
        break;
        default: printf("\nLa opcion seleccionada no es valida\n"); break;
        }
    }while(otro == 's' || otro == 'S');
}

void ActualizarSueldo(struct Empleado empleados [], int *p){
    int Nrolegajo = 0;
    float porcentaje = 0;
    int bandera = 0;

    printf("\nIngrese el nro de legajo del empleado que quiera actualizar:\n");
    scanf(" %d", &Nrolegajo);

    for(int i = 0; i < *p; i++){
        if(empleados[i].legajo.nrolegajo == Nrolegajo){
            printf("Ingrese el porcentaje de sueldo que quiera aumentar:\n");
            scanf(" %f", &porcentaje);
            empleados[i].sueldo = empleados[i].sueldo + ((empleados[i].sueldo * porcentaje) / 100);
            printf("El sueldo se ha actualizado con exito\n");
            bandera = 1;
        }
    }
    if(bandera == 0){
        printf("No se ha encontrado el empleado\n");
    }
}

void OrdenarSueldo(struct Empleado empleados[], int *p){
    struct Empleado aux;
    for(int i = 0; i < *p-1; i++){
        if(empleados[i].sueldo > empleados[i+1].sueldo){
            aux = empleados[i];
            empleados[i] = empleados[i+1];
            empleados[i+1] = aux;
        }
    }
        printf("%-6s | %-10s | %-20s | %-20s | %-20s | %-20s | %s\n", "Legajo", "DNI", "Nombre", "Apellido", "Puesto", "Sueldo(pesos)", "Antiguedad(anios)");
        for(int i = 0; i < *p; i++){
        printf("%-6d | %-10d | %-20s | %-20s | %-20s | %-20d | %d\n", 
            empleados[i].legajo.nrolegajo, 
            empleados[i].legajo.dni, 
            empleados[i].legajo.nombre, 
            empleados[i].legajo.apellido, 
            empleados[i].puesto, 
            empleados[i].sueldo, 
            empleados[i].antiguedad);
        }
}

void OrdenarAntiguedad(struct Empleado empleados[], int *p){
    struct Empleado aux;
    for(int i = 0; i < *p-1; i++){
        if(empleados[i].antiguedad > empleados[i+1].antiguedad){
            aux = empleados[i];
            empleados[i] = empleados[i+1];
            empleados[i+1] = aux;
        }
    }
        printf("%-6s | %-10s | %-20s | %-20s | %-20s | %-20s | %s\n", "Legajo", "DNI", "Nombre", "Apellido", "Puesto", "Sueldo(pesos)", "Antiguedad(anios)");
        for(int i = 0; i < *p; i++){
        printf("%-6d | %-10d | %-20s | %-20s | %-20s | %-20d | %d\n", 
            empleados[i].legajo.nrolegajo, 
            empleados[i].legajo.dni, 
            empleados[i].legajo.nombre, 
            empleados[i].legajo.apellido, 
            empleados[i].puesto, 
            empleados[i].sueldo, 
            empleados[i].antiguedad);
        }
}





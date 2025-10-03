/*Crear una estructura Actividad, las mismas corresponden a las actividades de un gym. 
Atributos: nombre, cupo, dias de la semana, horario, cant_inscriptos. 
Funciones: mostrar, buscar, mostrar actividades que aun no tienen el cupo lleno*/

#include <stdio.h>
#include <string.h>
#define CANT_ACTIVIDADES 3

struct Actividad{
 char nombre[20];
 int cupo;
 char dias[30];
 float horario;
 int inscriptos;
};

void Menu(struct Actividad[]);
void Cargar(struct Actividad[]);
void Mostrar(struct Actividad[]);
void Buscar(struct Actividad[]);
void Disponibles(struct Actividad[]);

int main(){
struct Actividad actividades[CANT_ACTIVIDADES];
Menu(actividades);
    return 0;
}

void Menu(struct Actividad actividades[CANT_ACTIVIDADES]){
    char opcion = ' ';
    char volver = ' ';

    do{
        printf("Elija la opcion que desee ejecutar:\n");
        printf("a. Cargar actividades\n");
        printf("b. Mostrar actividades cargadas\n");
        printf("c. Buscar una actividad\n");
        printf("d. Mostrar actividades con cupos disponibles\n");
        scanf(" %c", &opcion);

        switch(opcion){
            case 'a':
            case 'A': Cargar(actividades); break;
            case 'b':
            case 'B': Mostrar(actividades); break;
            case 'c':
            case 'C': Buscar(actividades); break;
            case 'd':
            case 'D': Disponibles(actividades); break;
            default: printf("No ha ingresado una opcion valida\n"); break;
        }

        printf("Desea volver al menu\?: Si(s), No(n)\n");
        scanf(" %c", &volver);
    }while(volver == 's' || volver == 'S');
}

void Cargar(struct Actividad actividades[CANT_ACTIVIDADES]){
    printf("Ingrese los siguientes datos de actividades:\n");
    for(int i = 0; i < CANT_ACTIVIDADES; i++){
        printf("\nNombre de la actividad:\n");
        getchar();
        fgets(actividades[i].nombre, 20, stdin);
        actividades[i].nombre[strcspn(actividades[i].nombre, "\n")] = '\0';
        printf("Cupo maximo de la actividad:\n");
        scanf(" %d", &actividades[i].cupo);
        printf("Dias que se realiza la actividad:\n");
        getchar();
        fgets(actividades[i].dias, 30, stdin);
        actividades[i].dias[strcspn(actividades[i].dias, "\n")] = '\0';
        printf("Horario en el que comienza la actividad:\n");
        scanf(" %f", &actividades[i].horario);
        printf("Cantidad de inscriptos hasta el momento:\n");
        scanf(" %d", &actividades[i].inscriptos);
    }
    printf("\nLas actividades se cargaron con exito\n");
}

void Mostrar(struct Actividad actividades[CANT_ACTIVIDADES]){
    printf("\nLas actividades cargadas hasta el momento:\n");
    printf("%-20s | %-5s | %-30s | %-7s | %-10s\n", "Nombre", "Cupo", "Dias", "Horario", "Inscriptos");
    for(int i = 0; i < CANT_ACTIVIDADES; i++){
        printf("%-20s | %-5d | %-30s | %-7.2f | %-10d\n",
            actividades[i].nombre,
            actividades[i].cupo,
            actividades[i].dias,
            actividades[i].horario,
            actividades[i].inscriptos);
    }
}

void Buscar(struct Actividad actividades[CANT_ACTIVIDADES]){
    char buscar[20];
    int bandera = 0;

    printf("Ingrese el nombre de la actividad que desee buscar:\n");
    getchar();
    fgets(buscar, 20, stdin);
    buscar[strcspn(buscar, "\n")] = '\0';

    for(int i = 0; i < CANT_ACTIVIDADES; i++){
        if(strcmp(actividades[i].nombre, buscar) == 0){
            printf("La actividad fue encontrada:\n");
            printf("%-20s | %-5s | %-30s | %-7s | %-10s\n", "Nombre", "Cupo", "Dias", "Horario", "Inscriptos");
            printf("%-20s | %-5d | %-30s | %-7.2f | %-10d\n",
            actividades[i].nombre,
            actividades[i].cupo,
            actividades[i].dias,
            actividades[i].horario,
            actividades[i].inscriptos);
            bandera = 1;
        }
    }
    if(bandera == 0){
        printf("La actividad no fue encontrada en la lista\n");
    }
}

void Disponibles(struct Actividad actividades[CANT_ACTIVIDADES]){
    int bandera = 0;

    printf("Las actividades con cupos disponibles son las siguientes:\n");
    printf("%-20s | %-5s | %-30s | %-7s | %-10s\n", "Nombre", "Cupo", "Dias", "Horario", "Inscriptos");
    for(int i = 0; i < CANT_ACTIVIDADES; i++){
        if(actividades[i].cupo > actividades[i].inscriptos){
            printf("%-20s | %-5d | %-30s | %-7.2f | %-10d\n",
            actividades[i].nombre,
            actividades[i].cupo,
            actividades[i].dias,
            actividades[i].horario,
            actividades[i].inscriptos);
            bandera = 1;
        }
    }
    if(bandera == 0){
        printf("No hay actividades con cupos disponibles\n");
    }
}


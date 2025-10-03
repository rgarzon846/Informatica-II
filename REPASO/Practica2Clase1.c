#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FILAS 10
#define COLUM 6

void InicializarVuelos(int [FILAS][COLUM]);
int CalcularID(int, int);
int CalcularPrecio(int);
int Estado(int);
void Menu(int [FILAS][COLUM]);
void CalcularVuelosPorParapente(int [FILAS][COLUM]);
void OrdenarPorPesoPasajero(int [FILAS][COLUM]);
void MostrarVuelosProgramados(int [FILAS][COLUM]);

int main(){
int cargar[FILAS][COLUM];
    Menu(cargar);
    return 0;
}

void InicializarVuelos(int cargar[FILAS][COLUM]){
int cod = 1001;
srand(time(NULL));

for(int i = 0; i < FILAS; i++){
    cargar[i][0] = cod + i;
    cargar[i][1] = rand()%(110-50+1)+50;
    cargar[i][2] = rand()%(3-1+1)+1;
    cargar[i][3] = CalcularID(cargar[i][1], cargar[i][2]);
    cargar[i][4] = CalcularPrecio(cargar[i][3]);
    cargar[i][5] = Estado(cargar[i][4]);
}
printf("\nEl listado de vuelos se ha inicializado con exito\n");
}

void Menu(int cargar[FILAS][COLUM]){
char opcion = ' ';
int bandera = 0;
char seguir = 's';

do{
    printf("\nIngrese la opcion que desee ejecutar: \n");
    printf("\na. Inicializar vuelos\n");
    printf("\nb. Mostrar vuelos programados\n");
    printf("\nc. Calcular vuelos por parapente\n");
    printf("\nd. Ordenar listado de vuelos\n");
    scanf(" %c", &opcion);

    switch(opcion){
        case 'a':
        case 'A': InicializarVuelos(cargar);
        bandera = 1;
        break;
        case 'b':
        case 'B': 
            if(bandera == 0){
                printf("\nDebe inicializar un vuelo antes de elegir esta opcion\n");
            }else{MostrarVuelosProgramados(cargar);}
        break;
        case 'c':
        case 'C': 
            if(bandera == 0){
                printf("\nDebe inicializar un vuelo antes de elegir esta opcion\n");
            }else{CalcularVuelosPorParapente(cargar);}
        break;
        case 'd':
        case 'D': 
            if(bandera == 0){
                printf("\nDebe inicializar un vuelo antes de elegir esta opcion\n");
            }else{OrdenarPorPesoPasajero(cargar);}
        break;
        default: printf("\nLa opcion seleccionada no existe, vuelva a intentarlo");
        break;
    }

printf("\nDesea volver al menu\?: S(Si) N(No)\n");
scanf(" %c", &seguir);
}while(seguir == 'S' || seguir == 's');
}


void MostrarVuelosProgramados(int cargar[FILAS][COLUM]){
printf("\n|Cod    |Peso   |Ins    |Para   |Precio |Estado\n");
for(int i = 0; i < FILAS; i++){
    for(int j = 0; j < COLUM; j++){
        printf("|%d\t", cargar[i][j]);
    }
    printf("\n");
}
}


void CalcularVuelosPorParapente(int cargar[FILAS][COLUM]){
    int parapente1 = 0;
    int parapente2 = 0;
    int parapente3 = 0;
    int id = 0;

    for(int i = 0; i < FILAS; i++){
    id = cargar[i][3];
    if(id == 50){
        parapente1++;
    }
    if(id == 51){
        parapente2++;
    }
    if(id == 52){
        parapente3++;
    }
    }

    printf("\nSe realizaran %d vuelos con el parapente de ID 50\n", parapente1);
    printf("\nSe realizaran %d vuelos con el parapente de ID 51\n", parapente2);
    printf("\nSe realizaran %d vuelos con el parapente de ID 52\n", parapente3);
}

void OrdenarPorPesoPasajero(int cargar[FILAS][COLUM]){
int aux = 0;

for(int i = 0; i < FILAS - 1; i++){
    for(int j = 0; j < FILAS -1-i; j++){
         if(cargar[j][1] > cargar[j+1][1]){
            for(int k = 0; k < COLUM; k++){
                aux = cargar[j][k];
                cargar[j][k] = cargar[j+1][k];
                cargar[j+1][k] = aux;
            }
         }
    }
}

printf("\nEl listado de vuelos ordenado es:\n");
printf("\n|Cod    |Peso   |Ins    |Para   |Precio |Estado\n");
for(int i = 0; i < FILAS; i++){
    for(int j = 0; j < COLUM; j++){
        printf("|%d\t", cargar[i][j]);
    }
    printf("\n");
}
}


int CalcularID(int pasajero, int id){
    int instructor = 0;
    int pesototal = 0;
    int parapente = 0;

    if(id == 1){
        instructor = 80;
    }
    if(id == 2){
        instructor = 65;
    }
    if(id == 3){
        instructor == 85;
    }

    pesototal = pasajero + instructor;

    if(pesototal >= 120 && pesototal <= 160){
        parapente = 50;
    }else{
        pesototal = 0;
    }
    if(pesototal >= 161 && pesototal <= 200){
        parapente = 51;
    }else{
        pesototal = 0;
    }
    if(pesototal >= 201 && pesototal <= 240){
        parapente == 52;
    }else{
        pesototal = 0;
    }

    return parapente;
}

int CalcularPrecio(int parapente){
int precio = 0;
    
    if(parapente == 50){
        precio = 45000;
    }
    if(parapente == 51){
        precio = 50000;
    }
    if(parapente == 52){
        precio = 55000;
    }
    if(parapente == 0){
        precio = 0;
    }

    return precio;
}

int Estado(int precio){
int estado = 0;

    if(precio != 0){
        estado = 1;
    }

    return estado;
}
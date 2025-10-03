#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FILAS 5
#define COLUM 5

void CargarBeneficiario();
void Menu(int [FILAS][COLUM]);
void PagoAsigZona(int [FILAS][COLUM]);
int CalculoZonas(int);
int CalcularPagosNacionales(int[FILAS][COLUM]);
void MostrarResumenDiario(int[FILAS][COLUM]);

int main(){
CargarBeneficiario();
    return 0;
}

void CargarBeneficiario(){
srand(time(NULL));
int Datos[FILAS][COLUM];
char salir = 'N';
char cargar = 'S';

for(int i = 0; i < FILAS; i++){
if(cargar == 'S' || cargar == 's'){
printf("Ingrese El DNI del solicitante: \n");
scanf(" %i", &Datos[i][0]);
Datos[i][1] = rand()%(4-1+1)+1;
printf("\nIngrese la cantidad de hijos del solicitante: \n");
scanf(" %i", &Datos[i][2]);
Datos[i][3] = CalculoZonas(Datos[i][1]);
Datos[i][4] = Datos[i][3]*Datos[i][2];
if(i < FILAS-1){
printf("\nDesea cargar otro solicitante\?:\nSi(S)\nNo(N)\n");
scanf(" %c", &cargar);
}
}
}

do{
Menu(Datos);
printf("\nDesea elegir otra opcion\?:\nS(Si)\nN(No)\n");
scanf(" %c", &salir);
}while(salir == 's' || salir == 'N');
cargar = 'S';
}

void Menu(int Datos[FILAS][COLUM]){
char opcion = ' ';
int Nacionales = 0;

printf("ELija la opcion que desee ejecutar: \n");
printf("\na. Pago en asignaciones por zona\n");
printf("\nb. Total de asignaciones del pais\n");
printf("\nc. Resumen diario\n");
scanf(" %c", &opcion);

switch(opcion){
case 'a':
case 'A':
    PagoAsigZona(Datos);
    break;
case 'b':
case 'B':
    Nacionales = CalcularPagosNacionales(Datos);
    printf("\nLos pagos a nivel nacional tienen un total de %d pesos\n", Nacionales);
    break;
case 'c':
case 'C':
    MostrarResumenDiario(Datos);
    break;
default:
    printf("\nLa opcion que ha seleccionado no existe\n");
    break;
}
}

int CalculoZonas(int Zona){
int SMVM = 0;
for(int i = 0; i < FILAS; i++){
    if(Zona == 1){
        SMVM = (313400*60)/100;
    }if(Zona == 2){
        SMVM = (313400*50)/100;
    }if(Zona == 3){
        SMVM = (313400*25)/100;
    }if(Zona == 4){
        SMVM = (313400*80)/100;
    }
}
return SMVM;

}

void PagoAsigZona(int Datos[FILAS][COLUM]){
int NOA = 0;
int NEA = 0;
int CENTRO = 0;
int SUR = 0;
int ZONA = 0;
int IMPORTE = 0;

for(int j = 0; j < FILAS; j++){
ZONA = Datos[j][1];
IMPORTE = Datos[j][4];

if(ZONA == 1){
NOA += IMPORTE;
printf("\nEl importe pagado en pesos en NOA es de: %d pesos\n", NOA);
}
if(ZONA == 2){
NEA += IMPORTE;
printf("\nEl importe pagado en pesos en NEA es de: %d pesos\n", NEA);
}
if(ZONA == 3){
CENTRO += IMPORTE;
printf("\nEl importe pagado en pesos en CENTRO es de: %d pesos\n", CENTRO);
}
if(ZONA == 4){
SUR += IMPORTE;
printf("\nEl importe pagado en pesos en SUR es de: %d pesos\n", SUR);
}
}
}

int CalcularPagosNacionales(int Datos[FILAS][COLUM]){
int TOTAL = 0;

for(int i = 0; i < FILAS; i++){
TOTAL += Datos[i][4];
}

return TOTAL;

}

void MostrarResumenDiario(int Datos[FILAS][COLUM]){
int aux = 0;

for(int i = 0; i < FILAS - 1; i++){
    for(int j = 0; j < FILAS - 1 - i; j++){
        if(Datos[j][1] > Datos[j+1][1]){
        for(int k = 0; k < COLUM; k++){
            aux = Datos[j][k];
            Datos[j][k] = Datos[j+1][k];
            Datos[j+1][k] = aux;
        }
    }
    }
}
printf("\nEl resumen diario es: \n");
printf("\n|DNI  |ZONA   |HIJOS  |AUH    |TOTAL\n");
for(int i = 0; i < FILAS; i++){
    for(int j = 0; j < COLUM; j++){
        printf("|%d\t", Datos[i][j]);

    }
    printf("\n");
}
}
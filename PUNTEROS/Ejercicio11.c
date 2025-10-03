/*Se desea cargar en un vector los saldos de proveedores. La cantidad de saldos es ingresada por el usuario (máximo 10). 
La carga finaliza con un saldo menor o igual a cero. Además, desarrolle las siguientes funciones para mostrar:
a. Cantidad de saldos cargados.
b. Promedio de saldos.
c. Cantidad de saldos menores al promedio.
d. Cantidad de saldos mayores al promedio.
e. Calcular cuánto fue lo recaudado en el mes.
Cada ítem es una función. Para recorrer el vector utilice punteros.
*/

#include <stdio.h>

void Menu(float *, int);
void Cantsaldos(int);
float Promedio(float *, int);
int Menores(float *, int, float);
int Mayores(float *, int, float);
float TotalMes(float *, int);

int main(){
    int cant = 0;
    float *p;
    int bandera = 0;

    printf("Ingrese la cantidad de saldos (maximo 10):\n");
    scanf(" %d", &cant);
    if(cant > 10){
        printf("La cantidad de saldos excedio los permitidos, maximo 10 saldos");
        return 1;
    }
    printf("Ingrese los saldos:\n");
    for(int i = 0; i < cant; i++){
        scanf(" %f", &*(p+i));
        if(*(p+i) <= 0){
            Menu(p, cant);
            bandera = 1;
        }
    }
    if(bandera == 0){
        Menu(p, cant);
    }
    return 0;
}

void Menu(float *p, int cant){

char opcion = ' ';
char volver = 'S';

do{
    printf("Ingrese la opcion que desea ejecutar:\n");
    printf("a. Cantidad de saldos cargados\n");
    printf("b. promedio de saldos\n");
    printf("c. Cantidad de saldos menores al promedio\n");
    printf("d. Cantidad de saldos mayores al promedio\n");
    printf("e. Calcular cuanto fue lo recaudado en el mes\n");
    scanf(" %c", &opcion);

    switch(opcion){
        case 'A':
        case 'a': Cantsaldos(cant); break;
        case 'B':
        case 'b': printf("El promedio de los saldos es: %.2f\n", Promedio(p, cant)); break;
        case 'C':
        case 'c': printf("Los saldos menores al promedio son %d\n", Menores(p, cant, Promedio(p, cant))); break;
        case 'D':
        case 'd': printf("Los saldos mayores al promedio son %d\n", Mayores(p, cant, Promedio(p, cant))); break;
        case 'E':
        case 'e': printf("El total de lo recaudado en el mes es de %.2f pesos\n", TotalMes(p, cant)); break;
        default: printf("No ha elegido una opcion valida, vuelva a elegir\n");
        break;
    }
    printf("Desea regresar al menu de opciones\?: Si(S), No(N)\n");
    scanf(" %c", &volver);
}while(volver == 'S' || volver == 's');
}

void Cantsaldos(int cant){
printf("Se cargaron %d saldos en el dia\n", cant);
}

float Promedio(float *p, int cant){
    int suma = 0;
    float promedio = 0;

    for(int i = 0; i < cant; i++){
        suma += *(p+i);
    }

    promedio = (float) suma/cant;

    return promedio;
}

int Menores(float *p, int cant, float promedio){
    int menores = 0;

    for(int i = 0; i < cant; i++){
        if(*(p+i) < promedio){
            menores++;
    }
}
    return menores;
}

int Mayores(float *p, int cant, float promedio){
    int mayores = 0;

    for(int i = 0; i < cant; i++){
        if(*(p+i) > promedio){
            mayores++;
    }
}
    return mayores;
}


float TotalMes(float *p, int cant){
    float total = 0;
    for(int i = 0; i < cant; i++){
        total += *(p+i);
    }
    return total;
}

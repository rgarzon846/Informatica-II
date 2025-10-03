/*Escribir un programa que simule una calculadora, en donde muestre un menú de opciones con las operaciones permitidas 
como a. Suma, b. Resta, c. Multiplicación y d. División, e. elevar a una potencia, f. calcular la raíz cuadrada de un número. 
Luego el programa solicita que se ingrese dos números (tipo float) y llame a la función correspondiente para hacer el cálculo. 
Luego mostrar el resultado y preguntar si desea realizar otra operación o terminar el programa. Usar punteros para la resolución de este ejercicio.*/

#include <stdio.h>
#include <math.h>

void Calculadora();
float Suma(float *, float *);
float Resta(float *, float *);
float Multiplicacion(float *, float *);
float Division(float *, float *);
float Potencia(float *, float *);
float Raiz(float *);
float Raices(float *, float *);

int main(){
Calculadora();
    return 0;
}

void Calculadora(){
char salir = 'N';
int opcion = 0;
float num1 = 0;
float num2 = 0;

do{
printf("Ingrese los numeros con los que desea operar:\n");
scanf(" %f", &num1);
scanf(" %f", &num2);
printf("Elija la opcion que desee ejecutar:\n");
printf("1. Sumar los numeros\n");
printf("2. Restar los numeros\n");
printf("3. Multiplicar los numeros\n");
printf("4. Dividir los numeros\n");
printf("5. Elevar el primer numero al segundo\n");
printf("6. Hacer la raiz cuadrada del primer numero\n");
printf("7. Raiz del primer numero con grado del segundo numero\n");
scanf(" %d", &opcion);

switch (opcion)
{
case 1:
    printf("El resultado de la suma es: %.2f\n", Suma(&num1, &num2));
    break;
case 2: 
    printf("El resultado de la resta es: %.2f\n", Resta(&num1, &num2));
    break;
case 3: 
    printf("El resultado de la multiplicacion es: %.2f\n", Multiplicacion(&num1, &num2));
    break;
case 4: 
    printf("El resultado de la division es: %.2f\n", Division(&num1, &num2));
    break;
case 5: 
    printf("El resultado de la potencia es: %.2f\n", Potencia(&num1, &num2));
    break;
case 6: 
    printf("El resultado de la raiz cuadrada del primer numero es: %.2f\n", Raiz(&num1));
    break;
case 7: 
    printf("El resultado de la raiz del primer numero con grado del segundo es: %.2f\n", Raices(&num1, &num2));
    break;
default:
    printf("La opcion elegida no existe, intente de nuevo\n");
    break;
}

printf("Desea salir de la calculadora\?: Si(S), No(N)\n");
scanf(" %c", &salir);

}while(salir == 'N' || salir == 'n');

}

float Suma(float *Num1, float *Num2){
    return *Num1 + *Num2;
}

float Resta(float *Num1, float *Num2){
    return *Num1 - *Num2;
}

float Multiplicacion(float *Num1, float *Num2){
    return *Num1 * *Num2;
}

float Division(float *Num1, float *Num2){
    return *Num1 / *Num2;
}

float Potencia(float *Num1, float *Num2){
    return pow(*Num1, *Num2);
}

float Raiz(float *Num1){
    return sqrt(*Num1);
}

float Raices(float *Num1, float *Num2){
    return pow(*Num1, (1/ *Num2));
}
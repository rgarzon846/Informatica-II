/*Se tiene un vector de 10 elementos con valores numéricos enteros. 
Luego crear una función que muestre los valores que están en posiciones impares, y otra función con las posiciones pares.
*/

#include <stdio.h>

void Pares(int *);
void Impares(int *);

int main(){
int v[10] = {0};
int *p = &v;

printf("Ingrese 10 numeros enteros:\n");
for(int i = 0; i < 10; i++){
    scanf(" %d", &*(p+i));
}
Pares(p);
Impares(p);

    return 0;
}

void Pares(int *p){
    printf("\nLos siguientes numeros estan en posiciones pares: ");
    for(int i = 0; i < 5; i++){
        printf("%d\t", *(p+(i*2)));
    }
}

void Impares(int *p){
    printf("\nLos siguientes numeros estan en posiciones impares: ");
    for(int i = 0; i < 5; i++){
        printf("%d\t", *(p+(i*2+1)));
    }
}
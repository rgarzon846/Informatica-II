#include <stdio.h>
int main() {
int c = 10;
int *p = &c;
printf("Tamaño de char: %zu byte\n", sizeof(int));
printf("Dirección de memoria de p inicial: %p\n\n", p);
for(int i=0; i<10;i++){
p++; // Mueve el puntero al siguiente char
printf("Dirección de memoria de p+%d: %p\n", i+1, p);
}
return 0;
}
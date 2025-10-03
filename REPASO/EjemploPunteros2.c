#include <stdio.h>
int main() {
int a = 10;
int *p[5];
printf("%d \n", a);
p[3]=&a;
printf("%d \n", *p[3]);
return 0;
}
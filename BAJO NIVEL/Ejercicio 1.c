#include <stdio.h>
#include <stdint.h>



int main(){
    uint16_t trama = 0b1000101010001101;        //primero se hacen las mascaras y luego se hacen los corrimientos, cada digito de exa equivale a 4 en binario
    uint8_t datos = trama & 0x07;
    uint8_t prioridad = (trama >> 7) & 0x04;
    uint8_t tipo = (trama >> 4) & 0x04;

    printf("\nTipo de dato: %X", tipo);
    printf("\nPrioridad: %X", prioridad);
    printf("\nDatos: %X", datos);
    return 0;
}
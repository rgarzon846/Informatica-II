/*Una fábrica de tornillos nos ha solicitado desarrollar un programa en C que permita  obtener e
imprimir las estadísticas de una determinada muestra de tornillos. Para ello nos indican que cada
tornillo viene caracterizado por su longitud y su diámetro y que ambas medidas deben almacenarse en
un registro con dos campos. Desarrollar un programa en C que: Solicite al usuario los datos de una
muestra de tornillos (longitud y diámetro) y los almacene en un vector. A partir de los datos
introducidos calcule y  muestre por pantalla la media de las longitudes y la media de los diámetros.
*/

#include <stdio.h>
#define TAMANIO_MUESTRA 5

struct Tornillo
{
    float longitud;
    float diametro;
};

void CargarTornillos(struct Tornillo[]);

int main()
{
    struct Tornillo tornillos[TAMANIO_MUESTRA];
    CargarTornillos(tornillos);
    return 0;
}

void CargarTornillos(struct Tornillo tornillos[TAMANIO_MUESTRA])
{
    char otro = 's';
    float suma_diametro = 0;
    float promedio_diametro = 0;
    float suma_longitud = 0;
    float promedio_longitud = 0;
    int cant = 0;
    int *p = &cant;

    printf("Ingrese las medidas solicitadas del tornillo:\n");
    for (int i = 0; i < TAMANIO_MUESTRA; i++)
    {
        if (otro == 's' || otro == 'S')
        {
            printf("Diametro[mm]:\n");
            scanf(" %f", &tornillos[i].diametro);
            suma_diametro += tornillos[i].diametro;
            printf("Longitud[mm]:\n");
            scanf(" %f", &tornillos[i].longitud);
            suma_longitud += tornillos[i].longitud;
            *p = i + 1;
            if (i < TAMANIO_MUESTRA - 1)
            {
                printf("\nDesea ingresar otro tornillo\?: Si(s), No(n)\n");
                scanf(" %c", &otro);
            }
        }
    }
    promedio_diametro = suma_diametro / *p;
    promedio_longitud = suma_longitud / *p;

    printf("\nLas muestras determinaron una media en la longitud de %.2fmm\n", promedio_longitud);
    printf("\nLas muestras determinaron una media en el diametro de %.2fmm\n", promedio_diametro);
}
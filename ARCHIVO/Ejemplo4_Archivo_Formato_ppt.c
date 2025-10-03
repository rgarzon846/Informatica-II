/* Este programa implementa el uso de las funciones fprintf() y fscanf().

1. Primero, crea un archivo llamado "registro.txt" y escribe en el
datos de varias personas con un formato especifico.

2. Despues, cierra el archivo, lo vuelve a abrir para lectura,
y utiliza fscanf() para leer los datos estructurados,
mostrandolos en la consola.
*/
#include <stdio.h>

int main() {
	FILE *fp;
	
	// ======================================================
	// PARTE 1: ESCRITURA CON fprintf()
	// ======================================================
	printf("Abriendo 'registro.txt' para escritura ('w')...\n");
	fp = fopen("registro.txt", "w");
	if (fp == NULL) {
		perror("Error al crear 'registro.txt'");
		return 1;
	}
	
	printf("Escribiendo datos con formato...\n");
	
	// Escribimos varias lineas, cada una con un nombre (string),
	// una edad (int) y una altura (float).
	fprintf(fp, "%s %d %.2f\n", "Juan", 25, 180.5);
	fprintf(fp, "%s %d %.2f\n", "Maria", 30, 165.2);
	fprintf(fp, "%s %d %.2f\n", "Carlos", 22, 175.9);
	
	// Es importante cerrar el archivo para asegurar que todos los datos
	// se escriban en el disco.
	fclose(fp);
	printf("Datos guardados y archivo cerrado.\n\n");
	
	
	// ======================================================
	// PARTE 2: LECTURA CON fscanf()
	// ======================================================
	printf("Reabriendo 'registro.txt' para lectura ('r')...\n");
	
	// Variables para almacenar los datos leídos
	char nombre[50];
	int edad;
	float altura;
	
	fp = fopen("registro.txt", "r");
	if (fp == NULL) {
		perror("Error al leer 'registro.txt'");
		return 1;
	}
	
	printf("Leyendo datos del archivo:\n-------------------------------------\n");
	// El bucle se ejecutara mientras fscanf() logre leer exitosamente
	// los 3 elementos que le pedimos en cada linea.
	// fscanf() devuelve el numero de elementos asignados con exito.
	printf("%-10s | %-4s | %s\n", "Nombre", "Edad", "Altura");
	while (fscanf(fp, "%s %d %f", nombre, &edad, &altura) == 3) {
		printf("%-10s | %-4d | %.2f\n", nombre, edad, altura);
	}
	printf("-------------------------------------\nLectura finalizada.\n");
	
	// Cerramos el archivo al terminar de leer.
	fclose(fp);
	fp=NULL;
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#define M 4 //numero de fila
#define N 5 //numero de columnas

int main() {
	int i=0, j=0;
	
	// --- PASO 1: RESERVA DE MEMORIA PARA LAS FILAS ---
	// Se declara 'A' como un "puntero a un puntero de tipo int" (int **).
	// Esto es necesario porque vamos a crear un arreglo de punteros,
	// donde cada puntero apuntara a una fila de la matriz.
	
	// malloc reserva espacio para 'M' punteros de tipo 'int *'.
	// Imagina esto como crear la "columna principal" que contendra las direcciones de cada fila.
	
	//Columnas
	int **A=(int **)malloc(M*sizeof(int *));
	// Se comprueba la reserva
	if(A==NULL){
		printf("Error al reservar memoria con malloc.\n");
		return 1;		
	}
	
	
	// --- PASO 2: RESERVA DE MEMORIA PARA LAS COLUMNAS DE CADA FILA ---
	// Este bucle itera sobre cada puntero de fila que acabamos de crear.
	
	//Filas
	for (i = 0; i < M; i++) {
		
		// Para cada puntero de fila A[i], reservamos espacio para 'N' enteros.
		// Ahora si­ estamos reservando el espacio para los datos de la matriz.
		// *(A+i) es equivalente a A[i].
		
		*(A+i)=(int *)malloc(N*sizeof(int));
		
		// Se comprueba la reserva
		if(*(A+i)==NULL){
			printf("Error al reservar memoria con malloc.\n");
			return 1;		
		}
	}
	
	
	// --- PASO 3: CARGA DE DATOS EN LA MATRIZ ---
	// Ahora que toda la memoria esta reservada, la llenamos con datos.
	
	//Carga de datos
	for (i = 0; i < M; i++) { 	//Recorre filas
		for (j = 0; j < N; j++) { //Recorre columnas
			//*(*(A+i)+j) es equivalente a A[i][j] 
			*(*(A+i)+j)=rand()%100; //Asigna un numero aleatorio del 0 al 99
		}
	}
	
	// --- PASO 4: IMPRESION DE DATOS DE LA MATRIZ ---
	// Se recorre la matriz de la misma forma que en la carga de datos.
	
	//Impresion de datos
	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++) {
			printf("%d\t", *(*(A+i)+j));
		}
		printf("\n");
	}	
	
	// --- PASO 5: LIBERACION DE LA MEMORIA (PROCESO INVERSO A LA RESERVA) ---
	// Es IMPORTANTE liberar la memoria en el orden inverso al que fue reservada
	// para evitar fugas de memoria (memory leaks).
	
	// Primero, liberamos la memoria de cada fila individualmente.
	
	//Liberacion de filas
	for (i = 0; i < M; i++) {
		free(*(A+i)); // Es igual que free(A[i]);
	}
	// Una vez que todas las filas han sido liberadas, liberamos el arreglo de punteros.
	free(A); 
	return 0;
}

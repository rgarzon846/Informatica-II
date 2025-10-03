/*1. Escriba un programa que cree un archivo llamado 
"datos_personales.txt" que pregunte los siguientes datos personales: 
nombre, apellido, dni, edad, nacionalidad. Luego abrir el archivo y 
mostrarlo.*/

#include <stdio.h>
#include <stdlib.h>

int main() {
	
	FILE *fp=NULL;
	
	char nombre[30], apellido[10], nacionalidad[20];
	long dni=0;
	int edad=0;
	
	fp=fopen("datos_personales.txt","w");
	if(fp==NULL){
		printf("Imposible abrir el archivo");
		return 1;
	}
	
	//solicito los datos
	printf("Nombre: ");
	scanf("%s",nombre);
	printf("Apellido: ");
	scanf("%s",apellido);
	printf("DNI: ");
	scanf("%ld",&dni);
	printf("Edad: ");
	scanf("%d",&edad);
	printf("Nacionalidad: ");
	scanf("%s",nacionalidad);
	
	//grabo en el archivo
	fprintf(fp,"%s\n%s\n%ld\n%d\n%s\n", nombre, apellido, dni, edad, nacionalidad);
	fclose(fp);
	
	//abrir y leer el archivo
	fp=fopen("datos_personales.txt","r");
	if(fp==NULL){
		printf("Imposible abrir el archivo");
		return 1;
	}
	
	printf("\nLeyendo archivo\n");
	while (fscanf(fp, "%s\n%s\n%ld\n%d\n%s\n", nombre, apellido, &dni, &edad, nacionalidad) == 5) {
		printf("Nombre: %s\nApellido: %s\nDNI: %ld\nEdad: %d\nNacionalidad: %s\n",
			   nombre, apellido, dni, edad, nacionalidad);
	}

	fclose(fp);
	return 0;
}

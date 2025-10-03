#include <stdio.h>
#include <string.h>

struct persona
{
	char nombre[20];
	char apellido[20];
	long celular;
};

// Prototipos de funciones
void agregar_contactos(struct persona contactos[], int cantidad);
void mostrar_contactos(struct persona contactos[], int cantidad);
void buscar_contacto(struct persona contactos[], int cantidad);

int main() {
	
	struct persona contactos[3];
	char op = ' ';
	int cantidad = 3;
	
	do {
		printf("MENU DE OPCIONES\n");
		printf("a. Agregar.\nb. Mostrar.\nc. Buscar.\n");
		scanf(" %c", &op);
		getchar();  // Limpiar el buffer de entrada
		
		switch (op) {
		case 'a':
			agregar_contactos(contactos, cantidad);
			break;
		case 'b':
			mostrar_contactos(contactos, cantidad);
			break;
		case 'c':
			buscar_contacto(contactos, cantidad);
			break;
		default:
			printf("Opcion no valida.\n");
			break;
		}
		
		printf("\n¿Desea seguir (S/N)? ");
		scanf(" %c", &op);
		getchar();  
		
	} while (op == 's' || op == 'S');
	
	return 0;
}

// Funcion para agregar contactos
void agregar_contactos(struct persona contactos[], int cantidad) {
	for (int i = 0; i < cantidad; i++) {
		printf("\nINGRESE LOS DATOS DE PERSONA %d:\n", i + 1);
		printf("Nombre: ");
		fgets(contactos[i].nombre, sizeof(contactos[i].nombre), stdin); //Permite ingresar una cadena incluyendo espacios
		contactos[i].nombre[strcspn(contactos[i].nombre, "\n")] = '\0';  // Elimina el salto de linea
		printf("Apellido: ");
		fgets(contactos[i].apellido, sizeof(contactos[i].apellido), stdin);
		contactos[i].apellido[strcspn(contactos[i].apellido, "\n")] = '\0'; 
		printf("Celular: ");
		scanf("%ld", &contactos[i].celular);
		getchar(); 
		printf("---------------------------------------------------\n");
	}
}

// Funcion para mostrar todos los contactos
void mostrar_contactos(struct persona contactos[], int cantidad) {
	for (int i = 0; i < cantidad; i++) {
		printf("\nDATOS DE PERSONA %d:\n", i + 1);
		printf("Nombre: %s\n", contactos[i].nombre);
		printf("Apellido: %s\n", contactos[i].apellido);
		printf("Celular: %ld\n", contactos[i].celular);
		printf("---------------------------------------------------\n");
	}
}

// Funcion para buscar un contacto por apellido
void buscar_contacto(struct persona contactos[], int cantidad) {
	char buscar_apellido[20];
	int bandera_encontrado = 0;
	
	printf("INGRESE APELLIDO A BUSCAR:\n");
	fgets(buscar_apellido, sizeof(buscar_apellido), stdin);
	buscar_apellido[strcspn(buscar_apellido, "\n")] = '\0'; 
	
	for (int i = 0; i < cantidad; i++) {
		if (strcmp(buscar_apellido, contactos[i].apellido) == 0) {
			printf("Persona encontrada: %s %s\n", contactos[i].nombre, contactos[i].apellido);
			printf("Celular: %ld\n", contactos[i].celular);
			bandera_encontrado = 1;
			break;
		}
	}
	if (bandera_encontrado == 0) {
		printf("No se encontro la persona buscada.\n");
	}
}

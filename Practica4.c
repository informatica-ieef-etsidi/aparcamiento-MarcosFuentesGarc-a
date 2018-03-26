#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define NPLAZAS 10

struct estructuraDePlaza {
	int estado; // 0 - Libre / 1 - Ocupada
	char tipoDeVehiculo;
	char matricula[8]; // Formato de la matr�cula: NNNNLLL
};


void main() {

	char opcion, numeroDeMatriculaIntroducido[8], usuario[7] = "marcos", usuarioIntroducido[7], password[7] = "marcos", passwordIntroducida[7];
	int i, numeroDePlazasLibres = NPLAZAS;
	struct estructuraDePlaza plaza[NPLAZAS];

	for (i = 0; i < NPLAZAS; i++) {

		plaza[i].estado = 0;

	}

	printf("\nIntroduzca su usuario: ");
	scanf("%s", usuarioIntroducido);
	printf("\nIntroduzca su contrase�a: ");
	scanf("%s", passwordIntroducida);
	getchar();

	if ((strcmp(password, passwordIntroducida) == 0) && (strcmp(usuario, usuarioIntroducido) == 0)) {


		while (1) {

			printf("\nSeleccione una de estas opciones:\n");
			printf("\n  R - Reservar plaza");
			printf("\n  A - Abandonar plaza");
			printf("\n  E - Estado del aparcamiento");
			printf("\n  B - Buscar veh�culo por matr�cula");
			printf("\n  S - Salir\n\n");
			scanf("%c", &opcion);
			getchar(); 

			switch (opcion) {

			case 'r':
			case 'R':

				if (numeroDePlazasLibres > 0) {

					numeroDePlazasLibres = numeroDePlazasLibres - 1;

					for (i = 0; i < NPLAZAS; i++) {

						if (plaza[i].estado == 0) {

							printf("\Indique su tipo de veh�culo 'M' (moto) o 'C' (coche): ");
							scanf("%c", &plaza[i].tipoDeVehiculo);
							getchar();

							if (plaza[i].tipoDeVehiculo == 'c' || plaza[i].tipoDeVehiculo == 'C' || plaza[i].tipoDeVehiculo == 'm' || plaza[i].tipoDeVehiculo == 'M') {

								plaza[i].estado = 1;
								printf("\nIndique su n�mero de matr�cula: ");
								scanf("%s", plaza[i].matricula);
								getchar();
								printf("\Su veh�culo ocupa la plaza %d", i);
								break;

							}

							else if (plaza[i].tipoDeVehiculo != 'c' && plaza[i].tipoDeVehiculo != 'C' && plaza[i].tipoDeVehiculo != 'm' && plaza[i].tipoDeVehiculo != 'M') {

								printf("\nLa opci�n introducida no es v�lida.");
								break;

							}

						}

					}

				}

				else {

					printf("\nNo hay plazas libres.");
					break;

				}

				printf("\n\n");
				system("pause");
				system("cls");
				break;

			case 'a':
			case 'A':

				printf("\nIndique su matr�cula: ");
				scanf("%s", numeroDeMatriculaIntroducido);
				getchar();

				for (i = 0; i < NPLAZAS; i++) {

					if (strcmp(numeroDeMatriculaIntroducido, plaza[i].matricula) == 0) {

						numeroDePlazasLibres = numeroDePlazasLibres + 1;
						printf("\nHa abandonado su plaza.\n");
						plaza[i].estado = 0;
						plaza[i].matricula;
						break;

					}

				}

				for (i = 0; i < NPLAZAS; i++) {

					if (strcmp(numeroDeMatriculaIntroducido, plaza[i].matricula) == 1) {

						printf("\nEl n�mero de matr�cula introducido no coincide.\n");
						break;

					}

					else

						break;

				}

				printf("\n\n");
				system("pause");
				system("cls");
				break;

			case 'e':
			case 'E':

				printf("\n");

				for (i = 0; i < NPLAZAS; i++) {

					if (plaza[i].estado == 1) {

						if (plaza[i].tipoDeVehiculo == 'c' || plaza[i].tipoDeVehiculo == 'C') {

							printf("Plaza %d - Ocupada - %s - Coche\n", i, plaza[i].matricula);

						}

						else

							printf("Plaza %d - Ocupada - %s - Moto\n", i, plaza[i].matricula);

					}

					else

						printf("Plaza %d - Libre\n", i);

				}

				printf("\n\n");
				system("pause");
				system("cls");
				break;

			case 'b':
			case 'B':

				printf("\Introduzca la matr�cula: ");
				scanf("%s", numeroDeMatriculaIntroducido);
				getchar();

				for (i = 0; i < NPLAZAS; i++) {

					if (strcmp(numeroDeMatriculaIntroducido, plaza[i].matricula) == 0) {

						printf("\nEl n�mero de matr�cula coincide con la de un veh�culo del aparcamiento que ocupa la plaza %d.", i);
						break;

					}

				}

				for (i = 0; i < NPLAZAS; i++) {

					if (strcmp(numeroDeMatriculaIntroducido, plaza[i].matricula) == 1) {

						printf("\nEl n�mero de matr�cula no coincide con la de un veh�culo del aparcamiento.");
						break;

					}

				}

				printf("\n\n");
				system("pause");
				system("cls");
				break;

			case 's':
			case 'S':

				system("pause");
				return 0;

			default:

				printf("\nLa opci�n introducida no es v�lida.\n");

				printf("\n\n");
				system("pause");
				system("cls");
				break;
			}

		} 

	}

	else

		printf("\El usuario o la contrase�a no son correctos.\n\n");
		system("pause");
		return 0;

}

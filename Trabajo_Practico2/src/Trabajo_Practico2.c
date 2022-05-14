#include <stdio.h>
#include <stdlib.h>

#include "Funciones_Genericas.h"
#include "ArrayPassenger.h"

int main(void)
{
	setbuf(stdout,NULL);

		int IdPassenger = 0;
		int seguir;
		int continuar;
		int Flag = 0;
		int *pFlag = &Flag;

		ePassenger listPassenger[SIZE];
		eStatus listStatus[STATUS_SIZE];

		InitPassengers(listPassenger, SIZE);
		InitStatus(listStatus, 4);

		ForcePassengers(listPassenger, &IdPassenger, 4, pFlag);
		ForceStatus(listStatus, STATUS_SIZE);

		do
			{
				system("cls");
				printf("#### Menu de Ingresos ###");
				printf("\n\n1-Ingreso nuevos pasajeros.\n");
				printf("2-Modificar pasajeros existentes.\n");
				printf("3-Eliminar pasajeros existentes.\n");
				printf("4-Informar pasajeros existentes.\n");
				printf("5-Salir.\n");
				fflush(stdin);
				seguir = GetIntRange("\nIngrese una opcion ", "\nOpcion incorrecta, reingrese ", 1, 5);

				switch(seguir)
				{
					case 1:
						system("cls");
						IdPassenger++;
						addOnePassenger(listPassenger, SIZE, IdPassenger, listStatus, STATUS_SIZE);
						Flag = 1;

					    	break;

					case 2:

						if(Flag != 0)
						{
							ModifyPasajero(listPassenger, SIZE, listStatus, STATUS_SIZE);
							system("cls");
						}
						else
						{
							printf("\nTiene que haber un pasajero registrado para poder acceder a esta opcion.\n\n");
							system("pause");
							system("cls");
						}
					    	break;

					case 3:

						if(Flag != 0)
						{
							system("cls");
							DeletePasseger(listPassenger, SIZE, listStatus, STATUS_SIZE);
							system("cls");
						}
						else
						{
							printf("\nTiene que haber un pasajero registrado para poder acceder a esta opcion.\n\n");
							system("pause");
							system("cls");
						}
					    	break;

					case 4:

					if(Flag != 0)
					{
						continuar = SecondayMenu(listPassenger, SIZE, listStatus, STATUS_SIZE);

						if(continuar == -1)
						{
							printf("\nSera redireccionado al menu principal\n\n");
							system("pause");
							system("cls");
						}
					}
					else
					{
						printf("\nTiene que haber un pasajero registrado para poder acceder a esta opcion.\n\n");
						system("pause");
						system("cls");
					}
				    	break;

					case 5:
						system("cls");
			            break;
				}
			}while(seguir != 5);
}

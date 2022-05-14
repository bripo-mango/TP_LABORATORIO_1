#include "ArrayPassenger.h"
#include "Funciones_Genericas.h"

void InitPassengers(ePassenger *listPassenger, int tam)
{
	int i;

	if(listPassenger != NULL)
	{
		for(i=0; i<tam; i++)
		{
			listPassenger[i].isEmpty = TRUE;
		}
	}
}

void InitStatus(eStatus *listStatus, int tam)
{
	int i;

	if(listStatus != NULL)
	{
		for(i=0; i<tam; i++)
		{
			listStatus[i].isEmpty = TRUE;
		}
	}
}

void ForceStatus(eStatus *listStatus, int tam)
{

	char description[][TAMA] = {"CANCELADO", "ACTIVO", "DEMORADO"};
	int id[] = {0,1,2};

	for(int i=0; i<tam; i++)
	{
	    if(listStatus[i].isEmpty == TRUE && listStatus != NULL)
	    {
	    	listStatus[i].idStatus = id[i];
		    strcpy(listStatus[i].description, description[i]);
		    listStatus[i].isEmpty = FALSE;
	    }
	}
}

void ForcePassengers(ePassenger *listPassenger, int *idPassenger, int tam, int *pFlag)
{
	char name[][TAMA] = {"Juan", "Mario", "Pedro", "Cristian"};
	char lastName[][TAMA] = {"Lopez", "Caastanieda", "Responde", "Saliba"};
	float price[] = {450,100,900,500};
	char flyCode[][TAMA] = {"PLF1","RNT2","H4TJ","Q2R6"};
	int type[] = {0,1,0,1};
	int status[] = {1,1,0,2};

	for(int i=0; i<tam; i++)
	{
	    if(listPassenger[i].isEmpty == TRUE && idPassenger != NULL && listPassenger != NULL)
	    {
	    	listPassenger[i].id = eGen_ObtenerID(*idPassenger);
		    strcpy(listPassenger[i].name, name[i]);
		    strcpy(listPassenger[i].lastName, lastName[i]);
		    listPassenger[i].price = price[i];
		    strcpy(listPassenger[i].flyCode, flyCode[i]);
		    listPassenger[i].typePassenger = type[i];
		    listPassenger[i].statusFlight = status[i];
		    listPassenger[i].isEmpty = FALSE;
	    	*idPassenger = listPassenger[i].id;
	    }
	}
	*pFlag = 1;
}

void PrintAllPassenger(ePassenger *listPassenger, int tam, eStatus *listStatus, int tamStatus)
{
	if(listPassenger != NULL && listStatus != NULL)
	{
		for(int i=0; i<tam; i++)
		{
			for(int j=0; j<tamStatus; j++)
			{
				if(listPassenger[i].isEmpty == FALSE && listPassenger[i].statusFlight == listStatus[j].idStatus)
				{
					PrintOnePassengerAndStatus(&listPassenger[i], &listStatus[j]);
				}
			}
		}
	}
}


void PrintAllStatus(eStatus *listStatus, int tam)
{
	for(int i=0; i<tam; i++)
	{
		if(listStatus[i].isEmpty == FALSE && listStatus != NULL)
		{
			PrintOneStatus(&listStatus[i]);
		}
	}
}

int FindPassenger(ePassenger *listPassenger, int tam, int id, int* pIndex)
{
    int todoOk = 0;

    if(listPassenger != NULL && pIndex != NULL && tam > 0)
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if(!listPassenger[i].isEmpty && listPassenger[i].id == id)
            {
                *pIndex = i;
                 break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

void PrintOnlyOnePassenger(ePassenger *aPassenger)
{
	char auxType[TAMA];

		if(aPassenger->typePassenger == 0)
			strcpy(auxType, "Extranjero");
		else
			strcpy(auxType, "Argentino");

		printf("\n*%2d %12s %12s %12.2f %13d %13s %14s\n\n", aPassenger->id,
															 aPassenger->name,
															 aPassenger->lastName,
															 aPassenger->price,
															 aPassenger->statusFlight,
															 aPassenger->flyCode,
															 auxType);
}



void PrintOnePassengerAndStatus(ePassenger *aPassenger, eStatus *aStatus)
{
	char auxType[TAMA];

		if(aPassenger->typePassenger == 0)
			strcpy(auxType, "Extranjero");
		else
			strcpy(auxType, "Argentino");

		printf("\n*%2d %12s %12s %12.2f %14s %13s %14s\n\n", aPassenger->id,
															 aPassenger->name,
															 aPassenger->lastName,
															 aPassenger->price,
															 aStatus->description,
															 aPassenger->flyCode,
															 auxType);
}

void PrintOneStatus(eStatus *listStatus)
{
	if(listStatus != NULL)
	{
		printf("\n*%4d %9s\n", listStatus->idStatus,
							   listStatus->description);
	}
}

void PrintPassengersByStatusActive(ePassenger *listPassenger, int tam, eStatus listStatus[], int tamStatus)
{
	for(int i=0; i<tam; i++)
		{
			for(int j=0; j<tamStatus; j++)
			{
				if(listPassenger[i].isEmpty == FALSE && listPassenger[i].typePassenger == listStatus[j].idStatus)
					{
						if(listPassenger[i].statusFlight == 1)
						{
							PrintOnePassengerAndStatus(&listPassenger[i], &listStatus[j]);
						}
					}
			}
		}
}


int FindStatus(eStatus *listStatus, int tam, int id, int* pIndex)
{
    int todoOk = 0;

    if(listStatus != NULL && pIndex != NULL && tam > 0)
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if(!listStatus[i].isEmpty && listStatus[i].idStatus == id)
            {
                *pIndex = i;
                 break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int FindPassengerById(ePassenger *listPassenger, int tam, int id)
{
	int i;
	int index = -1;

	for(i=0; i<tam; i++)
	{
		if(listPassenger[i].id == id && listPassenger != NULL && tam > 0)
		{
			index = i;
			break;
		}
	}
	return index;
}

int FindFreeIndexePassenger(ePassenger *listPassenger, int tam)
{
	int i;
	int index = -1;

	for(i=0; i<tam; i++)
	{
		if(listPassenger[i].isEmpty == TRUE && listPassenger != NULL && tam > 0)
		{
			index = i;
			break;
		}
	}
	return index;
}

void addOnePassenger(ePassenger *listPassenger, int tam, int idPassenger, eStatus *listStatus, int tamStatus)
{
	int i;
	i = FindFreeIndexePassenger(listPassenger, tam);

	if(i != -1 && listPassenger != NULL && listStatus != NULL && tam > 0 && tamStatus > 0)
	{
		listPassenger[i] = AddPassenger(idPassenger, listStatus, tamStatus);
		if(listPassenger[i].isEmpty == FALSE)
		{
			printf("\nPasajero cargado con exito!!\n\n");
			system("pause");
			system("cls");
		}
	}
	else
	{
		 printf("\nNo existe espacio disponible para la carga de datos\n\n");
		 system("pause");
		 system("cls");
	}
}

ePassenger AddPassenger(int idPassenger, eStatus *listStatus, int tamStatus)
{
	ePassenger AddedPassenger;
	int auxType;
	int auxIndex;

	Get_OnlyAlphabetStringWithSpaces("Ingrese el nombre del pasajero: ", "\nIngrese el nombre nuevamente(solo caracteres alfabeticos): ", AddedPassenger.name, TAMA);

	Get_OnlyAlphabetStringWithSpaces("\nIngrese el apellido del pasajero: ", "\nIngrese el apellido nuevamente(solo caracteres alfabeticos): ", AddedPassenger.lastName, TAMA);

	AddedPassenger.price = GetFloat("\nIngrese el precio del vuelo: ", "\nIngrese el precio del vuelo nuevamente (solo caracteres numericos positivos): ");

	GetString("\nIngrese el codigo de vuelo (Caracteres alfanumericos): ", AddedPassenger.flyCode, TAMA);

	PrintAllStatus(listStatus, tamStatus);
	auxType = GetInt("\nIngrese el codigo del estado de vuelo: ", "\nIngrese el codigo de nuevamente (solo caracteres numericos enteros): ");

	while(!FindStatus(listStatus, tamStatus, auxType, &auxIndex))
	{
		printf("/nERROR!!! No se ha encontrado el codigo ingresado.");
		PrintAllStatus(listStatus, tamStatus);
		auxType = GetInt("\nReigrese el codigo del estado de vuelo: ", "\nIngrese el codigo de nuevamente (solo caracteres numericos enteros): ");
	}

	AddedPassenger.statusFlight = auxType;

	AddedPassenger.typePassenger = GetIntRange("\nIngrese el tipo de pasajero (0 = Extranjero // 1 = Argentino): ", "\nReingrese el tipo de pasajero (0 = Extranjero // 1 = Argentino): ", 0, 1);

	AddedPassenger.id = idPassenger;

	AddedPassenger.isEmpty = FALSE;

	return AddedPassenger;
}


void ModifyPasajero(ePassenger *listPassenger, int tam, eStatus *listStatus, int tamStatus)
{
	int indexPassenger;
	int auxType;
	int idUser;
	char auxName[TAMA];
	char auxlastName[TAMA];
	char auxCod[TAMA];
	float auxPrice;
	int option;
	char seguir;

		system("cls");
		printf("\n\n###### Listado de pasajeros encontrados ######\n");
		printf("\n%5s %9s %13s %11s %17s %14s %10s","Codigo", "Nombre", "Apellido", "Precio", "Estado Vuelo", "Codigo Vuelo", "Tipo\n");
		PrintAllPassenger(listPassenger, tam, listStatus, tamStatus);
		idUser = GetInt("\nIngrese el codigo de pasajero de la siguiente lista: ", "Codigo no encontrado, Reingrese el codigo nuevamente: ");
		while(!FindPassenger(listPassenger, tam, idUser, &indexPassenger))
			{
				printf("/nERROR!!! No se encontro el ID ingresado.");
				PrintAllPassenger(listPassenger, tam, listStatus, tamStatus);
				idUser = GetInt("\nIngrese el codigo de pasajero de la siguiente lista", "Codigo no encontrado, Reingrese el codigo nuevamente: ");
			}

		if(indexPassenger != -1)
		{
		  system("cls");
		  printf("\n%5s %9s %13s %11s %17s %14s %10s","Codigo", "Nombre", "Apellido", "Precio", "Estado Vuelo", "Codigo Vuelo", "Tipo\n");
		  PrintOnlyOnePassenger(&listPassenger[indexPassenger]);

		  option = GetIntRange("\nSe ha encontrado la Id ingresada !!\n\nQue desea modificar? \n\n1-Nombre\n\n2-Apellido\n\n3-Precio\n\n4-Tipo Pasajero\n\n5-Codigo\n\n6-Salir\n\nIngrese una opcion: ", "Usted ha ingresado una opcion incorrecta, reingrese: ", 1, 6);
		  switch(option)
			{
				case 1:

					Get_OnlyAlphabetStringWithSpaces("\nIngrese el nuevo nombre: ", "\nError, reingrese el nombre nuevamente: ", auxName, TAMA);

					seguir = GetChar("\nEsta seguro de querer continuar? Ingrese 's' para continuar o 'n' para cancelar: ", "Error, reingrese 's' para continuar o 'n' para cancelar la modificacion: ");

					if(seguir == 's')
					{
						strcpy(listPassenger[indexPassenger].name, auxName);
						printf("\nEl Nombre ha sido modificado con exito\n");
						system("pause");
						system("cls");
					}
					else
					{
						printf("\nSe ha cancelado la modificacion del Nombre\n");
						system("pause");
						system("cls");
					}
					break;

				case 2:

					Get_OnlyAlphabetStringWithSpaces("\nIngrese el nuevo apellido: ", "\nError, reingrese el apellido nuevamente: ", auxlastName, TAMA);
					seguir = GetChar("\nEsta seguro de querer continuar? Ingrese 's' para continuar o 'n' para cancelar: ", "Error, reingrese 's' para continuar o 'n' para cancelar la modificacion: ");

					if(seguir == 's')
					{
						strcpy(listPassenger[indexPassenger].lastName, auxlastName);
						printf("\nEl Apellido se ha modificado con exito\n");
						system("pause");
						system("cls");
					}
					else
					{
						printf("\nSe ha cancelado la modificacion del Apellido\n");
						system("pause");
						system("cls");
					}
					break;

				case 3:

					auxPrice = GetFloat("\nIngrese el nuevo precio: ", "\nError, reigrese el precio nuevamente (solo caracteres numericos positivos): ");
					seguir = GetChar("\nEsta seguro de querer continuar? Ingrese 's' para continuar o 'n' para cancelar: ", "Ingrese 's' para continuar o 'n' para cancelar la modificacion: ");

					  if(seguir == 's')
					  {
						listPassenger[indexPassenger].price = auxPrice;
						printf("\nEl Precio se ha modificado con exito\n");
						system("pause");
						system("cls");
					  }
					  else
					  {
						printf("\nSe ha cancelado la modificacion del precio\n");
						system("pause");
						system("cls");
					  }
					  break;

				case 4:

					auxType = GetIntRange("\nIngrese el tipo de pasajero (0 = Extranjero // 1 = Argentino): ", "\nReingrese el tipo de pasajero (0 = Extranjero // 1 = Argentino): ", 0, 1);

					seguir = GetChar("\nEsta seguro de querer continuar? Ingrese 's' para continuar o 'n' para cancelar: ", "Ingrese 's' para continuar o 'n' para cancelar la modificacion: ");

					 if(seguir == 's')
					 {
						listPassenger[indexPassenger].typePassenger = auxType;
						printf("\nEl Tipo del pasajero se ha modificado con exito\n");
						system("pause");
						system("cls");
					 }
					 else
					 {
						printf("\nSe ha cancelado la modificacion del tipo de pasajero\n");
						system("pause");
						system("cls");
					 }
					 break;

				case 5:
					GetString("\nIngrese el codigo de vuelo: ", auxCod, TAMA);
					seguir = GetChar("\nEsta seguro de querer continuar? Ingrese 's' para continuar o 'n' para cancelar: ", "Ingrese 's' para continuar o 'n' para cancelar la modificacion: ");

					if(seguir == 's')
					{
						strcpy(listPassenger[indexPassenger].flyCode, auxCod);
						printf("\nEl Codigo de vuelo se ha modificado con exito\n");
						system("pause");
						system("cls");
					}
					else
					{
						 printf("\nSe ha cancelado la modificacion del codigo de vuelo\n");
						 system("pause");
						 system("cls");
					}
					break;

				case 6:
					 printf("\nSe ha cancelado la modificacion de datos\n");
					 system("pause");
					 system("cls");
					break;
			}
		}
		else
		{
			printf("\nNo se ha encontrado la id ingresada\n");
			system("pause");
			system("cls");
		}
}

void DeletePasseger(ePassenger *listPassenger, int tam, eStatus *listStatus, int tamStatus)
{
	int idToDelete;
	int indexPassenger;
	char seguir;

	system("cls");
	printf("\n\n### Pasajeros encontrados ###\n");
	printf("\n%5s %9s %13s %11s %17s %14s %10s","Codigo", "Nombre", "Apellido", "Precio", "Estado Vuelo", "Codigo Vuelo", "Tipo\n");
	PrintAllPassenger(listPassenger, tam, listStatus, tamStatus);
	idToDelete = GetInt("\nIngrese el codigo del pasajero a elminiar: ", "Ingrese el codigo de nuevamente (solo caracteres numericos enteros): ");

	while(!FindPassenger(listPassenger, tam, idToDelete, &indexPassenger))
	{
		printf("/nERROR!!! No se encontro el codigo ingresado.");
		PrintAllPassenger(listPassenger, tam, listStatus, tamStatus);
		idToDelete = GetInt("\nIngrese el codigo del pasajero a eliminar: ", "Ingrese el codigo de nuevamente (solo caracteres numericos enteros): ");
	}

	if(idToDelete != -1)
	{
		system("cls");

		printf("\n\nListado de pasajeros encontrados\n");
		printf("\n%5s %9s %13s %11s %17s %14s %10s","Codigo", "Nombre", "Apellido", "Precio", "Estado Vuelo", "Codigo Vuelo", "Tipo\n");
		PrintOnlyOnePassenger(&listPassenger[indexPassenger]);
		seguir = GetChar("\nSe ha encontrado la id ingresada, esta seguro de querer continuar con la baja? Ingrese s(si) o n(no): ", "\nReingrese s(si) o n(no): ");

		if(seguir == 's')
		{
			RemovePasseger(listPassenger, tam, indexPassenger, "\nSe ha eliminado el pasajero con exito!!!\n");
			system("pause");
		}
		else
		{
			printf("\nUsted ha cancelado la baja del pasajero\n");
			system("pause");
			system("cls");
		}
	}
}

void RemovePasseger(ePassenger *listaPasajeros, int tam, int index, char *mensaje)
{
	for(int i=0; i<tam; i++)
	{
		if(i == index)
		{
			printf("%s", mensaje);
			listaPasajeros[i].isEmpty = TRUE;
			break;
		}
	}
}


int SecondayMenu(ePassenger *listPassenger, int tam, eStatus *listStatus, int tamStatus)
{
	float sum;
	float average;
	int MaxPrice;
	int userResponse;
	int sortResponse;

	do
		{
			system("cls");
			printf("#### Menu Segundario Pasajeros ###");
			printf("\n\n1-Listado de pasajeros ordenados alfabeticamente por Apellido y Tipo.\n");
			printf("2-Total y promedio de los precios de los pasajes, y cuantos pasajeros superan el precio promedio.\n");
			printf("3-Listado de pasajeros por Codigo y estado de vuelo ACTIVO.\n");
			printf("4-Salir.\n");

			userResponse = GetIntRange("\nIngrese opcion: ", "Opcion invalida reingrese: \n", 1, 4);

				switch(userResponse)
					{
						case 1:
							system("cls");
							printf("1-Listado ascedente [Z-A].\n");
							printf("2-Listado descendente [A-Z].\n");
							printf("3-Salir.\n");

							sortResponse = GetIntRange("\nIngrese opcion: ", "Opcion invalida reingrese: \n", 1, 3);
							switch (sortResponse)
							{
								case 1:
									system("cls");
									printf("Listado ascendiente de pasajeros\n");
									printf("\n%5s %9s %13s %11s %17s %14s %10s","Codigo", "Nombre", "Apellido", "Precio", "Estado Vuelo", "Codigo Vuelo", "Tipo\n");
									SortPassengersByCode(listPassenger, tam, sortResponse, listStatus, tamStatus);

									system("pause");
									system("cls");

									break;

								case 2:
									system("cls");
									printf("Listado descendiente de pasajeros\n");
									printf("\n%5s %9s %13s %11s %17s %14s %10s","Codigo", "Nombre", "Apellido", "Precio", "Estado Vuelo", "Codigo Vuelo", "Tipo\n");
									SortPassengersByCode(listPassenger, tam, sortResponse, listStatus, tamStatus);

									system("pause");
									system("cls");

									break;

								case 3:

									printf("\nSe ha cancelado el ordenamiento.\n");
									system("pause");
									system("cls");
							}
									break;

						case 2:
							system("cls");
							printf("Listado de pasajeros encontrados\n");
							printf("\n%5s %9s %13s %11s %17s %14s %10s","Codigo", "Nombre", "Apellido", "Precio", "Estado Vuelo", "Codigo Vuelo", "Tipo\n");
							PrintAllPassenger(listPassenger, tam, listStatus, tamStatus);
							sum = PricesPlus(listPassenger, tam);
							average = AveragePrice(listPassenger, tam);
							MaxPrice = ShowAveragePassenger(listPassenger, tam);
							printf("\n\nLa suma total de los pasajes encontrados es: %.2f$\n", sum);
							printf("\nEl promedio de todos los pasajes encontrados es: %.2f$\n", average);
							printf("\nLa cantidad de pasajeros encontrados que superan el precio promedio son: %d\n\n", MaxPrice);
							system("pause");
							system("cls");
							break;

						case 3:
							system("cls");
							printf("Listado de los pasajeros por Codigo de vuelo y estados de vuelos (ACTIVO)\n");
							printf("\n%5s %9s %13s %11s %17s %14s %10s","Codigo", "Nombre", "Apellido", "Precio", "Estado Vuelo", "Codigo Vuelo", "Tipo\n");
							SortPassengersByCodeStatus(listPassenger, tam, listStatus, tamStatus);
							system("pause");
							system("cls");
							break;
					}

	}while(userResponse !=4);

	if(userResponse == 3 || userResponse > 3)
		userResponse = -1;
	return userResponse;
}


float PricesPlus(ePassenger *listPassenger, int tam)
{
    int i;
    float countPrices = 0;

    for(i=0; i<tam; i++)
    {
        if(listPassenger[i].isEmpty == FALSE)
        {
        	countPrices += listPassenger[i].price;
        }
    }
    return countPrices;
}

float AveragePrice(ePassenger *listPassenger, int tam)
{
    int i;
    float averagePrices = 0;

    for(i=0; i<tam; i++)
    {
        if(listPassenger[i].isEmpty == FALSE)
        {
        	averagePrices = PricesPlus(listPassenger, tam) / CountPassenger(listPassenger, tam);
        }
    }
    return averagePrices;
}


int CountPassenger(ePassenger *listPassenger, int tam)
{
    int i;
    int countPassengers = 0;

    for(i=0; i<tam; i++)
    {
        if(listPassenger[i].isEmpty == FALSE)
        {
        	countPassengers++;
        }
    }
    return countPassengers;
}


int ShowAveragePassenger(ePassenger *listPassenger, int tam)
{
    int i;
    float Promedio;
    int pasajerosMayorSueldo = 0;
    Promedio = AveragePrice(listPassenger, tam);

    for(i=0; i<tam; i++)
    {
        if(listPassenger[i].isEmpty == FALSE && listPassenger[i].price > Promedio)
        {
        	pasajerosMayorSueldo++;
        }
    }
    return pasajerosMayorSueldo;
}

void SortPassengersByCode(ePassenger *listPassenger, int tam, int response, eStatus listStatus[], int tamStatus)
{
	ePassenger auxPassenger;
	int i;
	int j;

	for(i=0; i<tam-1; i++)
	{
		for(j=i+1; j<tam; j++)
		{
			if(response == 1)
			{
				if(strcmp(listPassenger[i].lastName, listPassenger[j].lastName)<0)
				{
					auxPassenger = listPassenger[i];
					listPassenger[i] = listPassenger[j];
					listPassenger[j] = auxPassenger;

				}
				else
				{
					if((strcmp(listPassenger[i].lastName, listPassenger[j].lastName)<0) && (listPassenger[i].typePassenger > listPassenger[j].typePassenger))
						{
							{
								auxPassenger = listPassenger[i];
								listPassenger[i] = listPassenger[j];
								listPassenger[j] = auxPassenger;
							}
						}
				}
			}
			else
			{
				if(strcmp(listPassenger[i].lastName, listPassenger[j].lastName)>0)
						{
							auxPassenger = listPassenger[i];
							listPassenger[i] = listPassenger[j];
							listPassenger[j] = auxPassenger;

						}
						else
						{
							if((strcmp(listPassenger[i].lastName, listPassenger[j].lastName)>0) && (listPassenger[i].typePassenger > listPassenger[j].typePassenger))
								{
									{
										auxPassenger = listPassenger[i];
										listPassenger[i] = listPassenger[j];
										listPassenger[j] = auxPassenger;
									}
								}
						}
				}
			}
		}
	PrintAllPassenger(listPassenger, tam, listStatus, tamStatus);
}

void SortPassengersByCodeStatus(ePassenger *listPassenger, int tam, eStatus listStatus[], int tamStatus)
{
	ePassenger aux;
	int i;
	int j;

	for(i=0; i<tam-1; i++)
		{
			for(j=i+1; j<tam; j++)
			{
				if(strcmp(listPassenger[i].flyCode, listPassenger[j].flyCode)>0)
				{
					aux = listPassenger[i];
					listPassenger[i] = listPassenger[j];
					listPassenger[j] = aux;
				}
			}
		}
	PrintPassengersByStatusActive(listPassenger, tam, listStatus, tamStatus);
}


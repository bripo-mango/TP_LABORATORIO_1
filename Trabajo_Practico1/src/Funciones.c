#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Funciones.h"


void ShowData(float* priceArg, float* priceLatam)
{
	printf("\t Aerolineas = $%.2f\n", *priceArg);
	printf("\t Latam = $%.2f\n", *priceLatam);
}

int ImputValidate(char* stringImput, int rangeOptions)
{
	while(ValidateInt(stringImput) == 0 || ValidateIntRange(stringImput, rangeOptions) == 0)
		{
			printf("\nError, reingrese una opcion correcta: ");
			scanf("%s", stringImput);
		}
	return ParseInt(stringImput);
}

int ValidateInt(char* stringImput)
{
	int isInt = 1;

	for(int i=0; i < strlen(stringImput); i++)
	{
		if(!isdigit(stringImput[i]))
			{
				isInt = 0;
				break;
			}
	}
	return isInt;
}

int ValidateIntRange(char* stringImput, int rangeOptions)
{
	int isOk = 0;

	if(ParseInt(stringImput) < rangeOptions && ValidateInt(stringImput) != 0)
	{
		isOk = 1;
	}
	return isOk;
}

int ParseInt(char* stringData)
{
	return atoi(stringData);
}

float GetNum(char* welcomeMessage, char* errorMessage)
{

	char aux[buffer_size];

	printf("%s", welcomeMessage);
	fflush(stdin);
	scanf("%s", aux);

	while(ValidateFloat(aux) != 1)
	{
		printf("%s", errorMessage);
		//fflush(ingreso);
		scanf("%s", aux);
	}

	return ParseFloat(aux);
}

int ValidateFloat(char* stringImput)
{
	int i;
	int countsign = 0;
	int response;
	response = 1;

	for(i=0; i<strlen(stringImput); i++)
	{
		if(stringImput[i] == '.' || stringImput[i] == ',')
		{
			countsign++;
		}
		else
		{
			if(isdigit(stringImput[i]) == 0)
			{
				response = 0;
				break;
			}
		}
	}
	if(countsign > 1)
	{
		response = 0;
	}
	return response;
}

float ParseFloat(char* stringImput)
{
	return atof(stringImput);
}

void SecondaryMenu(char* message1, char* message2, char* message3, float* pAero, float* pLatam, int* pAeroFlag, int* pLatamFlag)
{
	char option[buffer_size];
	int validatedOption;

	do
	{
		system("cls");
		printf("\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
		ShowData(pAero, pLatam);
		printf("\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
		printf("%s", message1);
		printf("%s", message2);
		printf("%s", message3);

		printf("\n\nIngrese opcion: ");
		scanf("%s", option);
		validatedOption = ImputValidate(option, 4);

		switch(validatedOption)
		{
			case 1:
				system("cls");

				*pAero = GetNum("Ingrese el precio de aerolineas: ", "ERROR!!! Reingrese el precio de aerolineas: ");
				if(*pAero == 0)
				{
					printf("\nIngreso de 0 detectado, vuelva a subir el dato.\n\n");
					system("pause");
				}
				else
				{
					printf("\nCarga de dato exitosa!\n");
					*pAeroFlag = 1;
					system("pause");
				}

				break;

			case 2:
				system("cls");
				*pLatam = GetNum("Ingrese el precio LATAM: ", "ERROR!!! Reingrese el precio LATAM: ");
				if(*pLatam == 0)
				{
					printf("\nIngreso de 0 detectado, vuelva a subir el dato.\n\n");
					system("pause");
				}
				else
				{
					printf("\nCarga de dato exitosa!\n");
					*pLatamFlag = 1;
					system("pause");
				}
				break;

			case 3:
				printf("\nSaliendo del menu de ingresos.\n\n");
				system("pause");
				break;
		}

	}while(validatedOption != 3);
}

float DiscountPrice(float imput)
{
	return imput - (imput * 10) / 100;
}

float BitcoinPrice(float imput)
{
	return imput / 4611167.96;
}

float KmPrice(float imput, float km)
{
	return imput / km;
}

float PriceDiference(float imputAr, float imputLatam)
{
	return imputLatam - imputAr;
}

float InteresPrice(float imput)
{
	return imput + imput * (0.2);
}

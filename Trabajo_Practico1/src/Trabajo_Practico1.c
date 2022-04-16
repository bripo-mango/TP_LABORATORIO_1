/*
 ============================================================================
 Name        : Trabajo_Practico1.c
 Author      : Cespedes Braian
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"

int main(void)
{
	setbuf(stdout,NULL);

	char option[buffer_size];
	int validatedOption;
	int flagLatam, flagKm, flagShow, flagCharge, flagAr = 0;
	float aeroDiscount, aeroTax, bitAero, priceKmAero;
	float latamDiscount, latamTax, bitLatam, priceKmLatam, difPrice;
	float km = 0;
	float priceArg = 0;
	float priceLatam = 0;

	do
	{
		system("cls");
		printf("\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
		printf("\t Km = %.2fKm\n", km);
		ShowData(&priceArg, &priceLatam);
	    printf("\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
		printf("\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
	    printf("\t%c MENU DE INGRESOS %c\n",186,186);
	    printf("\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
		printf("\n1)Ingreso de kilometros del vuelo.");
		printf("\n2)Ingreso de precio de vuelo (Aerolineas, Latam).");
		printf("\n3)Calculo total de costos.");
		printf("\n4)Informe de resultados.");
		printf("\n5)Carga forzada de datos.");
		printf("\n6)Salida.");

		printf("\n\nIngresar opcion: ");
		scanf("%s", option);
		validatedOption = ImputValidate(option, 7);

		switch(validatedOption)
		{
			case 1:
				km = GetNum("\nIngrese los Km: ", "\nError!!! reingrese los Km: ");
				if(km == 0)
				{
					printf("\nIngreso de 0 detectado, vuelva a subir el dato.\n\n");
					system("pause");
				}
				else
				{
					printf("\nCarga de dato exitosa!\n");
					flagKm = 1;
					system("pause");
				}
				break;

			case 2:
				SecondaryMenu("\n1)Ingresar precio de vuelo Aerolineas Argentinas:",
							  "\n2)Ingresar precio de vuelo LATAM.",
							  "\n3)Salir.", &priceArg, &priceLatam, &flagAr, &flagLatam);
				break;

			case 3:

				if(flagKm == 1 && flagAr == 1 && flagLatam == 1)
				{
					aeroDiscount = DiscountPrice(priceArg);
					aeroTax = InteresPrice(priceArg);
					bitAero = BitcoinPrice(priceArg);
					priceKmAero = KmPrice(priceArg, km);
					latamDiscount = DiscountPrice(priceLatam);
					latamTax = InteresPrice(priceLatam);
					bitLatam = BitcoinPrice(priceLatam);
					priceKmLatam = KmPrice(priceLatam, km);
					difPrice = PriceDiference(priceArg, priceLatam);
					flagShow = 1;
					printf("\nCostos calculados con exito\n\n");
					system("pause");
				}
				else
				{
					printf("\nIngrese todos los datos antes de continuar con esta opcion.\n\n");
					system("pause");
					system("cls");
				}
				break;

			case 4:
				if(flagShow == 1)
				{
					printf("\nPrecio Aerolineas: $%.2f", priceArg);
					printf("\na) Precio con tarjeta de debito (-10%%): $%.2f", aeroDiscount);
					printf("\nb) Precio con tarjeta de credio (+20%%): $%.2f", aeroTax);
					printf("\nc) Precio pagando con bitcoin: %.5f BTC", bitAero);
					printf("\nd) Precio unitario aerolineas: $%.2f", priceKmAero);

					printf("\n\nPrecio Latam: $%.2f", priceLatam);
					printf("\na) Precio con tarjeta de debito (-10%%): $%.2f", latamDiscount);
					printf("\nb) Precio con tarjeta de credio (+20%%): $%.2f", latamTax);
					printf("\nc) Precio pagando con bitcoin: %.5f BTC", bitLatam);
					printf("\nd) Precio unitario aerolineas: $%.2f", priceKmLatam);
					printf("\n\n* La diferencia de precios es $%.2f\n\n", difPrice);


					if(flagCharge != 0)
					{
						km = 0;
						priceArg = 0;
						priceLatam = 0;
						flagAr = 0;
						flagLatam = 0;
						flagKm = 0;
					}
						flagShow = 0;
						system("pause");
						system("cls");
				}
				else
				{
					printf("\nDebe ingresar a la opcion 3 antes de mostrar los resultados\n\n");
					system("pause");
					system("cls");
				}
				break;

			case 5:
				 km = 7090;
				 priceArg = 162975;
				 priceLatam = 159339;

				 aeroDiscount = DiscountPrice(priceArg);
				 aeroTax = InteresPrice(priceArg);
				 bitAero = BitcoinPrice(priceArg);
				 priceKmAero = KmPrice(priceArg, km);
				 aeroDiscount = DiscountPrice(priceLatam);
				 aeroTax = InteresPrice(priceLatam);
				 bitAero = BitcoinPrice(priceLatam);
				 priceKmAero = KmPrice(priceLatam, km);
				 difPrice = PriceDiference(priceArg, priceLatam);

				 flagKm = 1;
				 flagCharge = 1;
				 flagAr = 1;
				 flagLatam = 1;

				 printf("\nCarga forzada realizada con exito\n\n");
				 system("pause");
				 break;

			case 6:
				printf("\nEsta saliendo del sistema de carga de datos\n\n");
				system("pause");
				break;
		}

	}while(validatedOption != 6);

}

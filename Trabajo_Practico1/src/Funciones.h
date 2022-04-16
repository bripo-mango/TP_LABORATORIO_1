/*
 * Funciones.h
 *
 *  Created on: 15 abr. 2022
 *      Author: Cespedes Braian
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#define buffer_size 50

/**
 * @fn void ShowData(float* priceArg, float* priceLatam)
 * @brief => Muestra la informacion recibida por punteros en consola.
 * @param priceArg => Primer puntero a mostrar.
 * @param priceArg => Segundo puntero a mostrar.
 *  */
void ShowData(float* priceArg, float* priceLatam);

/**
 * @fn int ImputValidate(char* stringImput, int rangeOptions)
 * @brief => Valida que el ingreso del usuario sea un numero y se encuentre en el rango deseado, parsea a entero el retorno.
 * @param stringImput => Cadena a validar.
 * @param rangeOptions => Rango de opciones a validar.
 * @return => Retorna el dato parseado a entero.
 */
int ImputValidate(char* stringImput, int rangeOptions);

/**
 * @fn int ValidateInt(char* stringImput)
 * @brief => Valida que la cadena ingresada sea entero.
 * @param stringImput => Cadena a validar.
 * @return => Retorna 1 si es entero, de lo contrario retorna 0.
 */
int ValidateInt(char* stringImput);

/**
 * @fn int ValidateIntRange(char* stringImput, int rangeOptions)
 * @brief => Valida que la cadena ingresada sea entero y este en rango.
 * @param stringImput => Cadena a validar.
 * @param rangeOptions => Rango de opciones.
 * @return => 1 si cumple condicion, de lo contrario 0.
 */
int ValidateIntRange(char* stringImput, int rangeOptions);

/**
 * @fn int ParseInt(char* stringData)
 * @brief => Parsea cadena de caracteres a entero.
 * @param stringData => Cadena a parsear.
 * @return => Cadena ya parseada a entero.
 */
int ParseInt(char* stringData);

/**
 * @fn float GetNum(char* welcomeMessage, char* errorMessage)
 * @brief => Permite el ingreso de datos del usuario, valida que cumpla la condicion que sea numerico.
 * @param welcomeMessage => Mensaje de solicitud al usuario.
 * @param errorMessage => Mensaje en caso de error.
 * @return => Retorna el numero parseado a float del usuario.
 */
float GetNum(char* welcomeMessage, char* errorMessage);

/**
 * @fn int ValidateFloat(char* stringImput)
 * @brief => Permite validar que la cadena ingresada sea flotante.
 * @param stringImput => Cadena a validar.
 * @return => En caso de que sea una cadena de flotantes retorna 1, de lo contrario 0.
 */
int ValidateFloat(char* stringImput);

/**
 * @fn ParseFloat(char* stringImput)
 * @brief => Parsea a flotante la cadena ingresada.
 * @param stringImput => Cadena a parsear.
 * @return => Cadena ya parseada a flotante.
 */
float ParseFloat(char* stringImput);

/**
 * @fn void SecondaryMenu(char* message1, char* message2, char* message3, float* pAero, float* pLatam, int* pAeroFlag, int* pLatamFlag)
 * @brief => Reproducde un menu secundario para la carga de precios de las aerolineas.
 * @param message1 => Primer mensaje a mostrar.
 * @param message2 => Segundo mensaje a mostrar.
 * @param message3 => Tercer mensaje a mostrar.
 * @param pAero => Puntero con el valor del precio de Aerolinas.
 * @param pLatam => Puntero con el valor del precio de Latam.
 * @param pAeroFlag => Flag de ingreso de precio.
 * @param pLatamFlag => Flag de ingreso de precio.
 */
void SecondaryMenu(char* message1, char* message2, char* message3, float* pAero, float* pLatam, int* pAeroFlag, int* pLatamFlag);
/**
 * @fn float DiscountPrice(float imput)
 * @brief => Calcula el descuento de un precio.
 * @param imput => Precio a calcularle el descuento.
 * @return => Retorna el precio junto al descuento calculado.
 */
float DiscountPrice(float imput);

/**
 * @fn float BitcoinPrice(float imput)
 * @brief => Calcula el precio de un vuelo en bitcoins.
 * @param imput => Precio a calcularle el valor en bitcoins.
 * @return => El valor en bitcoins del precio.
 */
float BitcoinPrice(float imput);

/**
 * @fn float KmPrice(float imput, float km)
 * @brief => Calcula el precio unitario por Km.
 * @param imput => Precio al cual calcularle el precio unitario.
 * @param km => Kilometros ingresados.
 * @return => El precio unitario por Km.
 */
float KmPrice(float imput, float km);

/**
 * @fn float PriceDiference(float imputAr, float imputLatam)
 * @brief => Calcula la diferencia de precios entre ambos vuelos.
 * @param imputArb => Precio de Aerolineas.
 * @param imputLatam => Precio de Latam.
 * @return => Diferencia entre ambos precios.
 */
float PriceDiference(float imputAr, float imputLatam);

/**
 * @fn float InteresPrice(float imput)
 * @brief => Calcula el interes de precio.
 * @param imput => Precio al cual calcularle el interes.
 * @return => Retorna el precio junto al interes generado.
 */
float InteresPrice(float imput);

#endif /* FUNCIONES_H_ */

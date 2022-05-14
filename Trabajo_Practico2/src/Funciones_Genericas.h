
#ifndef FUNCIONES_GENERICAS_H_
#define FUNCIONES_GENERICAS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define L 25 // Tam cadena de caracteres


/**
 * @fn void GetString(char*, char*, int)
 * @brief --> Permite el ingreso de una cadena de caracteres guardando el dato.
 *
 * @param message --> Mensaje.
 * @param aux --> Array donde se guarda el dato;
 * @param tam --> Tamanio del array.
 */
void GetString(char *message, char *aux, int tam);

/**
 * @fn int GetInt(char*, char*)
 * @brief --> Permite el ingreso de un dato entero, verifica de que sea un numero entero, junto con la funcion ValidarInt y lo retorna.
 *
 * @param mensaje --> Mensaje para el usuario.
 * @param messageError --> Mensaje en caso de error.
 * @return --> Retorna el numero en caso de que pase la validacion.
 */
int GetInt(char *message, char *messageError);

/**
 * @fn int GetIntRange(char*, char*, int, int)
 * @brief --> Permite el ingreso de un numero entero de acuerdo a un rango, valida junto a la funcion ValidarInt
 * y retorna el numero en caso de serlo, retorna 0 si no lo es.
 *
 * @param mensaje --> Mensaje al usuario.
 * @param messageError --> Mensaje de error.
 * @param min_range --> Rango minimo.
 * @param max_range --> Rango maximo.
 * @return --> Retorna el numero en caso de que pase la validacion, o 0 de lo contrario.
 */
int GetIntRange(char *message, char *messageError, int min_range, int max_range);

/**
 * @fn float GetFloat(char*, char*)
 * @brief --> Permite el ingreso de un numero flotante de acuerdo a un rango, valida junto a la funcion ValidarFloat
 * y retorna el numero en caso de serlo, retorna 0 si no lo es.
 *
 * @param mensaje --> Mensaje al usuario.
 * @param messageError --> Mensaje de error.
 * @return --> Retorna el numero en caso de que pase la validacion, o 0 de lo contrario.
 */
float GetFloat(char *message, char *messageError);

/**
 * @fn char GetChar(char*, char*)
 * @brief Verifica que el caracter ingresado sea s o n, si es cualquiera de ambos casos
 * retorna dicho caracter, de lo contrario retorna un error.
 *
 * @param mensaje --> Mensaje al usuario.
 * @param messageError --> Mensaje de error
 * @return --> Caracter s o n.
 */
char GetChar(char *mensaje, char *messageError);

/**
 * @fn void Get_OnlyAlphabetStringWithSpaces(char*, char*, char*, int)
 * @brief --> Permite el ingreso de un array de caracteres con espacios, valida que contenga espacios con
 * Validate_OnlyAlphabetWithSpaces y retorna el array cargandolo de manera referencial a la variable aux.
 *
 * @param MSJ --> Mensaje al usuario.
 * @param ERROR_MSJ --> Mensaje de error.
 * @param aux --> Array listo para ser cargado.
 * @param TAM --> Tamanio del array.
 */
void Get_OnlyAlphabetStringWithSpaces(char *message, char *messageError, char *aux, int TAM);

/**
 * @fn int eGen_ObtenerID(int)
 * @brief --> Genera un id incremental de acuerdo a un punto donde se quiere que comienze.
 *
 * @param Gen_idIncremental --> Punto donde se quiere comenzar a incrementar el id.
 * @return --> retorno del id incrementado.
 */
int eGen_ObtenerID(int Gen_idIncremental);


/**
 * @fn float TurnIntoFloat(char*)
 * @brief --> Transforma el array que recibe en numero flotante.
 *
 * @param stringdata --> Array a transfrormar.
 * @return --> Flotante ya modificado.
 */
float TurnIntoFloat(char *stringdata);


/**
 * @fn int TurnIntoInt(char*)
 * @brief --> Transforma el array que recibe en numero entero.
 *
 * @param stringdata --> Array a transfrormar.
 * @return --> Entero ya modificado.
 */
int TurnIntoInt(char *stringdata);

/**
 * @fn int Validate_OnlyAlphabetWithSpaces(char*)
 * @brief  --> Valida que la cadena ingresada presente espacios, si contiene algun espacio retorna 1, en caso contrario 0.
 *
 * @param aux --> Cadena a verificar
 * @return --> Retorno de espacios presentes 1, de lo contrario es 0.
 */


/**
 * @fn int ValidateFloat(char*)
 * @brief --> Valida que el dato sea flotante, si lo es retorna 1, en caso contrario 0.
 *
 * @param validfloat --> Dato a verificar.
 * @return --> Retorno de numero flotante es 1, de lo contrario es 0.
 */
int ValidateFloat(char *validfloat);

/**
 * @fn char Validatechar(char)
 * @brief --> Valida que el dato ingresado sea caracter, si lo es retorna 1, en caso contrario 0.
 *
 * @param caracter --> Dato a verificar.
 * @return --> Retorno de caracter es 1, de lo contrario es 0.
 */
char Validatechar(char caracter);

/**
 * @fn int ValidateInt(char*)
 * @brief --> Valida que el dato ingresado sea un entero, si lo es retorna 1, en caso contrario 0.
 *
 * @param numero --> Dato a verificar.
 * @return --> Retorno de entero es 1, de lo contrario es 0.
 */
int ValidateInt(char *numero);

/**
 * int ValidateNumber(char*)
 *
 * @param numero // Valida que la cadena ingresada sea numerica.
 * @return // Retorna el numero entero en caso de serlo de lo contrario retorna -1.
 */
int ValidateNumber(char *numero);

/**
 * int validarNumeroExcluyeSignos(char* numero)
 *
 * @param numero // Valida que un numero sea positivo.
 * @return // Retorna el numero entre en case de serlo de lo contrario retorna -1.
 */
int ValidateNumNoSigns(char *numero);


/**
 * int Validate_OnlyAlphabetWithSpaces(char* aux)
 *
 * @param numero // Valida que un numero sea positivo.
 * @return // Retorna el numero entre en case de serlo de lo contrario retorna -1.
 */
int Validate_OnlyAlphabetWithSpaces(char *aux);


#endif /* FUNCIONES_GENERICAS_H_ */

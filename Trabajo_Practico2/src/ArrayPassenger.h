
#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

#define TRUE 1
#define FALSE 0
#define TAMA 70
#define SIZE 2000
#define STATUS_SIZE 3

typedef struct
{
	int id;
	char name[TAMA];
	char lastName[TAMA];
	float price;
	char flyCode[10];
	int typePassenger;
	int statusFlight;
	int isEmpty;
}ePassenger;

typedef struct
{
	int idStatus;
	char description[TAMA];
	int isEmpty;
}eStatus;

/**void InitPassengers(ePassenger *listPassenger, int tam);
 *
 *
 * @param listPassenger lista de pasajeros
 * @param tam tamanio de la lista
 *
 * Inicializa la lista de pasajeros
 */
void InitPassengers(ePassenger *listPassenger, int tam);

/**void InitStatus(eStatus *listStatus, int tam);
 *
 *
 * @param listStatus lista de estados
 * @param tam tamanio de la lista
 *
 * Inicializa la lista de estados
 */
void InitStatus(eStatus *listStatus, int tam);

/**void ForcePassengers(ePassenger *listPassenger, int *idPassenger, int tam, int *pFlag);
 *
 *
 * @param listPassenger lista de pasajeros
 * @param idPassenger id a inicializar
 * @param tam tamanio de la lista
 * @param pFlag bandera de la lista para acceder a los otras opciones del menu
 *
 * Hardcodea con datos ya cargados una parte de la lista
 */

void ForcePassengers(ePassenger *listPassenger, int *idPassenger, int tam, int *pFlag);
/** void ForceStatus(eStatus *listStatus, int tam);
 *
 * @param listStatus lista de estados
 * @param tam tamanio de la lista
 *
 * Harcodea una parte de la lista de estados
 */
void ForceStatus(eStatus *listStatus, int tam);

/** void PrintAllPassenger(ePassenger *listPassenger, int tam, eStatus *listStatus, int tamStatus);
 *
 * @param listPassenger lista de pasajeros
 * @param tam tamanio de la lista de pasajeros
 * @param listStatus lista de estados
 * @param tamStatus tamanio de la lista de estados
 *
 * Muestra todos los pasajeros con sus estados
 */
void PrintAllPassenger(ePassenger *listPassenger, int tam, eStatus *listStatus, int tamStatus);

/** void PrintOnlyOnePassenger(ePassenger *aPassenger);
 *
 * @param aPassenger pasajero a mostrar
 *
 * Muestra el pasajero que se le asigne
 */
void PrintOnlyOnePassenger(ePassenger *aPassenger);

/** void PrintOnePassengerAndStatus(ePassenger *aPassenger, eStatus *aStatus);
 *
 *
 * @param aPassenger pasajero a mostrar
 * @param aStatus estado a mostrar
 *
 * Muestra el pasajero y el estado que se le asigne
 */
void PrintOnePassengerAndStatus(ePassenger *aPassenger, eStatus *aStatus);

/** void PrintAllStatus(eStatus *listStatus, int tam);
 *
 *
 * @param listStatus lista de estados
 * @param tam tamanio de la lista de estados
 *
 * Muestra todos los estados de la lista
 */
void PrintAllStatus(eStatus *listStatus, int tam);

/** void PrintPassengersByStatusActive(ePassenger *listPassenger, int tam, eStatus listStatus[], int tamStatus);
 *
 *
 * @param listPassenger lista de pasajeros
 * @param tam tamanio de la lista de pasajeros
 * @param listStatus lista de estados
 * @param tamStatus tamanio de la lista de estados
 *
 * Muestra los pasajeros con estado activo
 */
void PrintPassengersByStatusActive(ePassenger *listPassenger, int tam, eStatus listStatus[], int tamStatus);

/** int FindPassenger(ePassenger *listPassenger, int tam, int id, int* pIndex);
 *
 * @param listPassenger lista de pasajeros
 * @param tam tamanio de la lista
 * @param id id ingresada por el usuario
 * @param pIndex indice al que corresponde la id encontrada
 * @return retorna el indice en caso de que encuentre el id, de lo contrario retorna menos uno
 */
int FindPassenger(ePassenger *listPassenger, int tam, int id, int* pIndex);

/** void PrintOneStatus(eStatus *listStatus);
 *
 * @param listStatus lista de estados
 *
 * Muestra solo un estado
 */
void PrintOneStatus(eStatus *listStatus);

/** int FindStatus(eStatus *listStatus, int tam, int id, int* pIndex);
 *
 * @param listStatus lista de estados
 * @param tam tamanio de la lista
 * @param id id ingresada por el usuario
 * @param pIndex indice al que corresponde el id
 * @return retorna el indice en caso de que encuentre el id, de lo contrario retorna menos uno
 */
int FindStatus(eStatus *listStatus, int tam, int id, int* pIndex);

/** int FindPassengerById(ePassenger *listPassenger, int tam, int id);
 *
 * @param listPassenger lista de pasajeros
 * @param tam tamanio de la lista
 * @param id id ingresada por el usuario
 * @return retorna el indice de la lista
 */
int FindPassengerById(ePassenger *listPassenger, int tam, int id);

/** int FindFreeIndexePassenger(ePassenger *listPassenger, int tam);
 *
 * @param listPassenger lista de pasajeros
 * @param tam tamanio de la lista
 * @return retorna un indice libre de al lista
 *
 * busca y retorna un indice libre en la lista de pasajeros
 */
int FindFreeIndexePassenger(ePassenger *listPassenger, int tam);

/** void addOnePassenger(ePassenger *listPassenger, int tam, int idPassenger, eStatus *listStatus, int tamStatus);
 *
 * @param listPassenger lista de pasajeros
 * @param tam tamanio de la lista
 * @param idPassenger id a asignar al pasajero
 * @param listStatus lista de estados
 * @param tamStatus tam de la lista de estados
 *
 * Permite asignar un id y cargar exitosamente un pasajero a la lista
 */
void addOnePassenger(ePassenger *listPassenger, int tam, int idPassenger, eStatus *listStatus, int tamStatus);

/** ePassenger AddPassenger(int idPassenger, eStatus *listStatus, int tamStatus);
 *
 * @param idPassenger id de pasajaero a asignar
 * @param listStatus lista de estados
 * @param tamStatus tamanio de la lista
 *
 * @return pasajero con los datos ya asignados
 *
 * Permite solicitar y asignar los datos ingresados por el usuario
 */
ePassenger AddPassenger(int idPassenger, eStatus *listStatus, int tamStatus);

/** void ModifyPasajero(ePassenger *listPassenger, int tam, eStatus *listStatus, int tamStatus);
 *
 * @param listPassenger lista de pasajeros
 * @param tam tamanio de a lista
 * @param listStatus lista de estados
 * @param tamStatus tamanio de la lista
 *
 * Permite modificar un pasajero, mediante la id ingresada por el usuario
 */
void ModifyPasajero(ePassenger *listPassenger, int tam, eStatus *listStatus, int tamStatus);

/** void DeletePasseger(ePassenger *listPassenger, int tam, eStatus *listStatus, int tamStatus);
 *
 * @param listPassenger lista de pasajeros
 * @param tam tamanio de la lista
 * @param listStatus lista de estados
 * @param tamStatus tamanio de la lista
 *
 * Solicita el id y permite eliminar a un pasajero de la lista
 */
void DeletePasseger(ePassenger *listPassenger, int tam, eStatus *listStatus, int tamStatus);

/** void RemovePasseger(ePassenger *listaPasajeros, int tam, int index, char *mensaje);
 *
 * @param listaPasajeros lista de pasajeros
 * @param tam tamanio de la lista
 * @param index indice a eliminar
 * @param mensaje mensaje de confirmacion
 *
 * Cambia el estado de isEmpty a 1 en caso de que se de debaja al pasajero
 */
void RemovePasseger(ePassenger *listaPasajeros, int tam, int index, char *mensaje);

/** int SecondayMenu(ePassenger *listPassenger, int tam, eStatus *listStatus, int tamStatus);
 *
 * @param listPassenger lista de pasajeros
 * @param tam tamanio de la lista
 * @param listStatus lista de estados
 * @param tamStatus tamanio de la lista
 * @return retorna menos uno en caso de que el usuario decida salir del submenu
 *
 * Permite ingresar a un submenu para el listado e informe de la lista
 */
int SecondayMenu(ePassenger *listPassenger, int tam, eStatus *listStatus, int tamStatus);

/** float PricesPlus(ePassenger *listPassenger, int tam);
 *
 * @param listPassenger lista de pasajeros
 * @param tam tamanio de la lista
 * @return retorna el total de la suma de precios de cada empleado de la lista
 */
float PricesPlus(ePassenger *listPassenger, int tam);

/** float AveragePrice(ePassenger *listPassenger, int tam);
 *
 *
 * @param listPassenger lista de pasajeros
 * @param tam tamanio de la lista
 * @return retorna el promedio de precios de cada elemento de la lista
 */
float AveragePrice(ePassenger *listPassenger, int tam);

/** int CountPassenger(ePassenger *listPassenger, int tam);
 *
 *
 * @param listPassenger lista de pasajeros
 * @param tam tamanio de la lista
 * @return retorna la cantidad de pasajeros encontrados en la lista
 */
int CountPassenger(ePassenger *listPassenger, int tam);

/** int ShowAveragePassenger(ePassenger *listPassenger, int tam);
 *
 * @param listPassenger lista de psajeros
 * @param tam tamanio de la lista
 * @return retorna el indice de los pasajeros que superen el promedio de sueldos en la lista
 */
int ShowAveragePassenger(ePassenger *listPassenger, int tam);

/** void SortPassengersByCode(ePassenger *listPassenger, int tam, int response, eStatus listStatus[], int tamStatus);
 *
 * @param listPassenger lista de pasajeros
 * @param tam tamanio de la lista
 * @param response respuesta del usuario con el critero a listar
 * @param listStatus lista de estados
 * @param tamStatus tamanio de la lista
 *
 * Ordena y lista los elementos de la lista de pasajeros segun el codigo y apellido
 */
void SortPassengersByCode(ePassenger *listPassenger, int tam, int response, eStatus listStatus[], int tamStatus);

/** void SortPassengersByCodeStatus(ePassenger *listPassenger, int tam, eStatus listStatus[], int tamStatus);
 *
 * @param listPassenger lista de pasajeros
 * @param tam tamanio de la lista
 * @param listStatus lista de estados
 * @param tamStatus tamanio de la lista
 *
 * Ordena la lista por codigo y estado de vuelo
 */
void SortPassengersByCodeStatus(ePassenger *listPassenger, int tam, eStatus listStatus[], int tamStatus);

#endif /* ARRAYPASSENGER_H_ */

#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "publicacion.h"


/**
 * @fn int publicacion_Init(Publicacion*, int)
 * @brief Funcion que setea todos los campos isEmpty de cada elemento de tipo Publicacion en TRUE
 *
 * @param puArray: EL puntero al array de tipo Publicacion
 * @param len: La longitud del array de tipo Publicacion
 * @return (-1) Error (0) todo ok
 */
int publicacion_Init(Publicacion *pArrayPublicacion[], int len) {
    int output = -1;
    if (pArrayPublicacion != NULL && len > 0) {
        for (int x = 0; x < len; x++) {
            pArrayPublicacion[x] = NULL;
        }
        output = 0;
    }
    return output;
}

Publicacion* publicacion_NewPublicacionConParametros(int id, int clienteId, int rubro, char* descripcion)
{
    Publicacion *aux;
    if(id > 0 && clienteId > 0 && rubro >= 0 && descripcion != NULL)
    {
        aux = (Publicacion*)malloc(sizeof(Publicacion));
        if(aux != NULL)
        {
            aux->id = id;
            aux->idCliente = clienteId;
            aux->numeroRubro = rubro;
            strncpy(aux->descripcionAviso, descripcion, SIZE_AVISO);
            aux->estado = ACTIVA;
        }
    }
    return aux;
}
/**
 * @fn int publicacion_HardCodeo(Publicacion*)
 * @brief Funcion que da valores iniciales a 5 publicaciones
 *
 * @param puArray: El puntero al array de tipo Publicacion
 * @return (-1) Error (0) todo OK
 */
int publicacion_HardCodeo(Publicacion *pArrayPublicacion[]) {
    int output = -1;
    int bufferID[5] =           {   1000, 1001,   1002,   1003,   1004    };
    int bufferClienteID[5] =    {   100,  101,    102,    103,    100     };
    int bufferRubro[5] =        {   4,    1,      2,      2,      4       };

    char bufferDescripcion[5][SIZE_AVISO] = {   "SE VENDEN ZAPATOS AL POR MAYOR",
                                                "ROBERTO... QUE EN PAZ DESCANCES",
                                                "GANO ARGENTINA",
                                                "13/10/2020 - TRES ASALTOS EN EL OBELISCO EL SABADO POR LA NOCHE",
                                                "SE BUSCAR BARTENDER CON EXPERIENCA" };
    Publicacion *aux;
    if (pArrayPublicacion != NULL) {
        for (int x = 0; x < 5; x++) {
            aux = publicacion_NewPublicacionConParametros(bufferID[x], bufferClienteID[x], bufferRubro[x], bufferDescripcion[x]);
            if(aux != NULL)
            {
                pArrayPublicacion[x] = aux;
            }
        }
        output = 0;
    }
    return output;
}



/**
 * @fn int publicacion_FindById(Publicacion*, int, int, int*)
 * @brief Funcion que encuentra el indice de un elemento de tipo Publicacion en base al ID de publicacion
 *
 * @param puArray: EL puntero al array de tipo Publicacion
 * @param len: La longitud del array de tipo Publicacion
 * @param id: El ID de publicacion a comparar con los elementos del array
 * @param indexPosition: El puntero a int donde se guardara la posiscion del elemento, si se encuentra
 * @return (-1) Error (0) todo OK
 */
int publicacion_FindById(Publicacion *puArray[], int len, int id, int *indexPosition) {

    int output = -1;
    if (puArray != NULL && indexPosition != NULL && len > 0 && id > 0) {
        for (int x = 0; x < len; x++) {
            if (puArray[x] != NULL && puArray[x]->id == id) {
                *indexPosition = x;
                output = 0;
                break;
            }
        }
    }
    return output;
}

/**
 * @fn int publicacion_FindByClientId(Publicacion*, int, int, int*)
 * @brief Funcion que encuentra un indice de un elemento en base a un ID de cliente
 *
 * @param puArray: EL puntero al array de tipo Publicacion
 * @param len: La longitud del array de tipo Publicacion
 * @param id: El ID del cliente a comparar con los elementos del array
 * @param indexPosition: El puntero a int donde se guardara la posiscion del elemento, si se encuentra
 * @return (-1) Error (0) todo OK
 */
int publicacion_FindByClientId(Publicacion *puArray[], int len, int id, int *indexPosition) {

    int output = -1;
    if (puArray != NULL && indexPosition != NULL && len > 0 && id > 0) {
        for (int x = 0; x < len; x++) {
            if (puArray[x] != NULL && puArray[x]->idCliente == id) {
                *indexPosition = x;
                output = 0;
                break;
            }
        }
    }
    return output;
}

/**
 * @fn int publicacion_FindFree(Publicacion*, int, int*)
 * @brief Funcion que encuentra el primer indice libre dentro del array de tipo Publicacion
 *
 * @param puArray: EL puntero al array de tipo Publicacion
 * @param len: La longitud del array de tipo Publicacion
 * @param freeIndexPosition: EL puntero a int donde se guardara el indice libre
 * @return (-1) Error (0) todo OK
 */
int publicacion_FindFree(Publicacion *pArrayPublicacion[], int len, int *freeIndexPosition) {
    int output = -1;
    if (pArrayPublicacion != NULL && freeIndexPosition != NULL && len > 0) {
        for (int x = 0; x < len; x++) {
            if (pArrayPublicacion[x] == NULL) {
                *freeIndexPosition = x;
                output = 0;
                break;
            }
        }
    }
    return output;
}

/**
 * @fn int publicacion_GenerateId(int*)
 * @brief Funcion privada que calcula un id de forma incremental
 *
 * @param PublicacionID: El puntero a int donde se guardara el ID generado
 * @return (-1) Error (0) todo OK
 */
static int publicacion_GenerateId(int *PublicacionID) {

    int output = -1;
    static int id = 1005;
    if (PublicacionID != NULL) {
        *PublicacionID = id++;
        output = 0;
    }
    return output;
}

/**
 * @fn int publicacion_Create(Publicacion*, int, int*)
 * @brief Funcion que pide los datos de una publicacion
 *
 * @param puArray: EL puntero al array de tipo Publicacion
 * @param lenPublicacion: La longitud del array de tipo Publicacion
 * @param bufferIndice: El puntero de tipo entero donde se guardara el indice del nuevo elemento
 * @return (-1) Error (0) todo OK
 */
int publicacion_Create(Publicacion *pArrayPublicacion[], int lenPublicacion, int bufferClienteID, int *bufferIndice)
{
    int output = -1;
    int bufferIndex;
    Publicacion bufferAux;
    Publicacion *aux;


    if (pArrayPublicacion != NULL && lenPublicacion > 0&& !(publicacion_FindFree(pArrayPublicacion, lenPublicacion, &bufferIndex)))
    {
        if (!(utn_getIntConMinMax("\n(a). SELECCIONE RUBRO ENTRE [1:100] -------------> ", "Error, rubro incorrecto - reintentos",
                &bufferAux.numeroRubro, 1, 100, 3))
                && !(utn_getStringWithNumbersAndSymbols("(b). INGRESE DESCRIPCION DEL AVISO: ", "Error, reintentos",
                bufferAux.descripcionAviso, SIZE_AVISO, 3))
                && !(publicacion_GenerateId(&bufferAux.id)))
        {
            *bufferIndice = bufferIndex;
            aux = publicacion_NewPublicacionConParametros(bufferAux.id, bufferClienteID, bufferAux.numeroRubro, bufferAux.descripcionAviso);
            if(aux != NULL)
            {
                pArrayPublicacion[bufferIndex] = aux;
                output = 0;
            }
        }
    }
    return output;
}

/**
 * @fn int publicacion_Remove(Publicacion*, int, int)
 * @brief Funcion que setea el campo isEmpty en TRUE
 *
 * @param puArray: EL puntero al array de tipo Publicacion
 * @param lenPublicacion: La longitud del array de tipo Publicacion
 * @param bufferClienteID: El ID del cliente que sirve para comparar con el ID cliente dentro del array de tipo Publicacion
 * @return (-1) Error (0) todo OK
 */
int publicacion_Remove(Publicacion *puArray[], int lenPublicacion, int bufferClienteID) {
    int output = -1;

    if(puArray != NULL && lenPublicacion > 0 && bufferClienteID >= 100)
    {
        for(int x = 0; x < lenPublicacion; x++)
        {
            if(puArray[x] != NULL && puArray[x]->idCliente == bufferClienteID)
            {
                free(puArray[x]);
                puArray[x] = NULL;
                output = 0;
            }
        }
    }
    return output;
}

int publicacion_IsActive(Publicacion *pUnaPublicacion, int bufferIDPublicacion)
{
    int output = 0;

    if(pUnaPublicacion != NULL)
    {
        if(pUnaPublicacion->estado == ACTIVA)
        {
            output = 1;
        }
    }
    return output;
}

/**
 * @fn int publicacion_PrintOne(Publicacion)
 * @brief Funcion que muestra por pantalla un elemento de tipo Publicacion
 *
 * @param Publicacion: El elemento de tipo Publicacion
 * @return (-1) Error (0) todo OK
 */
int publicacion_PrintOne(Publicacion *pUnaPublicacion) {
    int output = -1;
    char estado[10];
    if(pUnaPublicacion != NULL){
        if(pUnaPublicacion->estado == ACTIVA)
        {
            sprintf(estado, "ACTIVA");
        }
        else
        {
            sprintf(estado, "PAUSADA");
        }
        printf("# %d %13d %12s %70s\n", pUnaPublicacion->id, pUnaPublicacion->numeroRubro, estado, pUnaPublicacion->descripcionAviso);

        output = 0;
    }
    return output;
}

/**
 * @fn int publicacion_printAll(Publicacion*, int)
 * @brief Funcion que imprime todos los elementos de un array de tipo Publicacion
 *
 * @param puArray: El puntero al array de tipo Publicacion
 * @param len: La longitud del array de tipo Publicacion
 * @return (-1) Error (0) todo OK
 */
int publicacion_printAll(Publicacion *pArrayPublicacion[], int len) {
    int output = -1;
    if (pArrayPublicacion != NULL && len > 0) {
        printColumnPublicacion();
        for (int x = 0; x < len; x++) {
            publicacion_PrintOne(pArrayPublicacion[x]);
        }
        output = 0;
    }
    return output;
}






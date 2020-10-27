#include "cliente.h"

#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

/* ##################### CON MEM DINAMICA ##################### */

/**
 * @fn int cliente_Init(Cliente*, int)
 * @brief Funcion que setea todos los campos isEmpty de cada elemento de tipo Cliente en TRUE
 *
 * @param pArray: EL puntero al array de tipo Cliente
 * @param len: La longitud del array de tipo Cliente
 * @return (-1) Error (0) todo ok
 */
int cliente_Init(Cliente *pArrayClientes[], int len) {
    int output = -1;
    if (pArrayClientes != NULL && len > 0) {
        for (int x = 0; x < len; x++) {
            pArrayClientes[x] = NULL;
        }
        output = 0;
    }
    return output;
}


/* ##################### SETTERS & GETTERS ##################### */

int cliente_setName(Cliente *pUnCliente, char *msg)
{
    int output = -1;
    if(pUnCliente != NULL)
    {
        if(!(utn_getString(msg, "Error, reintenos",pUnCliente->name , SIZE_STR, 3)))
        {
            output = 0;
        }
    }
    return output;
}

int cliente_setLastName(Cliente *pUnCliente, char *msg)
{
    int output = -1;
    if(pUnCliente != NULL)
    {
        if(!(utn_getString(msg, "Error, reintenos",pUnCliente->lastName , SIZE_STR, 3)))
        {
            output = 0;
        }
    }
    return output;
}

int cliente_setCuit(Cliente *pUnCliente, char *msg)
{
    int output = -1;
    int reintentos = 3;
    if(pUnCliente != NULL)
    {
        do
        {
            if(!(utn_getStringWithOnlyNumbers(msg, "Error - solo numeros,  reintentos", pUnCliente->cuit, SIZE_STR, 1))
                    && cliente_IsCuitValid(pUnCliente->cuit))
            {
                reintentos = 0;
                output = 0;
            }
            else
            {
                reintentos--;
                printf("Error - SOLO 11 numeros,  reintentos: %d\n", reintentos);
            }
        }while(reintentos > 0);
    }
    return output;
}
/**
 * @fn int cliente_HardCodeo(Cliente*)
 * @brief Funcion que da valores iniciales a 5 clientes
 *
 * @param pArray: El puntero al array de tipo Cliente
 * @return (-1) Error (0) todo OK
 */
int cliente_HardCodeo(Cliente *pArrayClientes[])
{
    int output = -1;
    int bufferID[5] =                   {   100,                  101,            102,            103,            104           };
    char bufferName[5][SIZE_STR] =      {   "EDGARDO HORACIO",    "ANGUS",        "BRIAN",        "RICARDO",      "BRUCE"       };
    char bufferLastName[5][SIZE_STR] =  {   "LORENZO",            "DICIKINSON",   "JHONSON",      "IORIO",        "DICIKINSON"  };
    char bufferCuit[5][SIZE_STR] =      {   "20336330972",        "20456787196",  "32689210751",  "29903221487",  "41107389873" };
    Cliente *aux;
    if (pArrayClientes != NULL)
    {
        for (int x = 0; x < 5; x++)
        {
            aux = cliente_NewClienteConParametros(bufferID[x],  bufferName[x], bufferLastName[x], bufferCuit[x]);
            if(aux != NULL)
            {
                pArrayClientes[x] = aux;
            }
        }
        output = 0;
    }
    return output;
}

Cliente* cliente_NewClienteSinParametros(void)
{
    Cliente *aux;
    aux = (Cliente*)malloc(sizeof(Cliente));
    if(aux != NULL)
    {
        aux->id = 0;
        strncpy(aux->name, "\0", SIZE_STR);
        strncpy(aux->lastName, "\0", SIZE_STR);
        strncpy(aux->cuit, "\0", SIZE_STR);
    }
    return aux;
}

Cliente* cliente_NewClienteConParametros(int id, char* name, char* lastName, char* cuit)
{
    Cliente *aux;
    if(name != NULL && lastName != NULL && cuit != NULL)
    {
        aux = (Cliente*)malloc(sizeof(Cliente));
        if(aux != NULL)
        {
            aux->id = id;
            strncpy(aux->name, name, SIZE_STR);
            strncpy(aux->lastName, lastName, SIZE_STR);
            strncpy(aux->cuit, cuit, SIZE_STR);
        }
    }
    return aux;
}

/**
 * @fn int cliente_FindFree(Cliente*, int, int*)
 * @brief Funcion que encuentra el primer indice libre dentro del array de tipo Cliente
 *
 * @param pArray: EL puntero al array de tipo Cliente
 * @param len: La longitud del array de tipo cliente
 * @param freeIndexPosition: EL puntero a int donde se guardara el indice libre
 * @return (-1) Error (0) todo OK
 */
int cliente_FindFree(Cliente *pArrayClientes[], int len, int *freeIndexPosition) {
    int output = -1;
    if (pArrayClientes != NULL && freeIndexPosition != NULL && len > 0) {
        for (int x = 0; x < len; x++) {
            if (pArrayClientes[x] == NULL) {
                *freeIndexPosition = x;
                output = 0;
                break;
            }
        }
    }
    return output;
}

/**
 * @fn int cliente_FindById(Cliente*, int, int, int*)
 * @brief Funcion que encuentra el indice de un elemento de tipo Cliente en base al ID
 *
 * @param pArray: EL puntero al array de tipo Cliente
 * @param len: La longitud del array de tipo Cliente
 * @param id: El ID a comparar con los elementos del array
 * @param indexPosition: El puntero a int donde se guardara la posiscion del elemento, si se encuentra
 * @return (-1) Error (0) todo OK
 */
int cliente_FindById(Cliente *pArrayClientes[], int len, int id, int *indexPosition) {

    int output = -1;
    if (pArrayClientes != NULL && indexPosition != NULL && len > 0 && id > 0) {
        for (int x = 0; x < len; x++) {
            if (pArrayClientes[x] != NULL && pArrayClientes[x]->id == id) {
                *indexPosition = x;
                output = 0;
                break;
            }
        }
    }
    return output;
}

/**
 * @fn int cliente_DoesIdExist(Cliente*, int, int)
 * @brief Funcion que pregunta si existe un determinado ID dentro del array de tipo Cliente
 *
 * @param pArray: EL puntero al array de tipo Cliente
 * @param len: La longitud del array de tipo cliente
 * @param id: El ID a comparar
 * @return (0) No existe (1) Existe
 */
int cliente_DoesIdExist(Cliente *pArrayClientes[], int len, int id) {

    int output = 0;
    if (pArrayClientes != NULL && len > 0 && id > 0) {
        for (int x = 0; x < len; x++) {
            if (pArrayClientes[x] != NULL && pArrayClientes[x]->id == id) {
                output = 1;
                break;
            }
        }
    }
    return output;
}

/**
 * @fn int cliente_GenerateId(int*)
 * @brief Funcion privada que calcula un id de forma incremental
 *
 * @param ClienteID: El puntero a int donde se guardara el ID generado
 * @return (-1) Error (0) todo OK
 */
static int cliente_GenerateId(int *ClienteID) {

    int output = -1;
    static int id = 105;
    if (ClienteID != NULL) {
        *ClienteID = id++;
        output = 0;
    }
    return output;
}

/**
 * @fn int cliente_Create(Cliente*, int)
 * @brief Funcion que solicita los campos de un elemento de tipo Cliente
 *
 * @param pArray: EL puntero al array de tipo Cliente
 * @param len: La longitud del array de tipo cliente
 * @return (-1) Error (0) todo OK
 */
int cliente_Create(Cliente *pArrayClientes[], int len) {

    int output = -1;
    int bufferIndex;
    Cliente *pClienteAux = NULL;
    //Cliente *pAux2;

    if (pArrayClientes != NULL && len > 0)
    {
        if(!(cliente_FindFree(pArrayClientes, len, &bufferIndex)))
        {
            pClienteAux = cliente_NewClienteSinParametros();
            if(pClienteAux != NULL
                    && !(cliente_GenerateId(&(pClienteAux->id)))
                    && !(cliente_setName(pClienteAux, "(a). Ingrese nombre: "))
                    && !(cliente_setLastName(pClienteAux, "(b). Ingrese apellido: "))
                    && !(cliente_setCuit(pClienteAux, "(c). Ingrese cuit: ")))
            {
                pClienteAux = cliente_NewClienteConParametros(pClienteAux->id, pClienteAux->name, pClienteAux->lastName, pClienteAux->cuit);
                if(pClienteAux != NULL)
                {
                    pArrayClientes[bufferIndex] = pClienteAux;
                    pClienteAux = NULL;
                    //pAux2 = NULL;
                    output = 0;
                }
//                    pAux2 = cliente_NewClienteConParametros(pAux1->id, pAux1->name, pAux1->lastName, pAux1->cuit);
//                    if(pAux2 != NULL)
//                    {
//                        pArrayClientes[bufferIndex] = pAux2;
//                        pAux1 = NULL;
//                        psAux2 = NULL;
//                        output = 0;
//                    }
            }
        }
        else
        {
            output = 1;
        }
    }
    return output;
}

/**
 * @fn int cliente_Remove(Cliente*, int, int)
 * @brief Funcion que busca cliente por ID y si existe lo da de baja
 *
 * @param pArray: El puntero al array de tipo Cliente
 * @param len: La longitud del array de tipo Cliente
 * @param id: El id a comparar
 * @return (-1) Error (0) todo OK
 */
int cliente_Remove(Cliente *pArrayClientes[], int index)
{
    int output = -1;
    if(pArrayClientes != NULL && index >= 0)
    {
        free(pArrayClientes[index]);
        pArrayClientes[index] = NULL;
        output = 0;
    }
    return output;
}

/**
 * @fn int cliente_Modify(Cliente*, int)
 * @brief Funcion que permite modificar campos de un elemento de tipo Cliente
 *
 * @param pArray: EL puntero al array de tipo Cliente
 * @param len: La longitud del array de tipo cliente
 * @return (-1) Error (0) todo OK
 */
int cliente_Modify(Cliente *pArrayClientes[], int len) {
    int output = -1;
    int opcionMenuModificaciones;
    int flag;
    int bufferID;
    int bufferIndex;
    int bufferResultado;
    Cliente bufferAux;

    if (pArrayClientes != NULL && len > 0) {
        do
        {
            if (!(menu_Modificar(&opcionMenuModificaciones)))
            {
                switch (opcionMenuModificaciones)
                {
                case 1:
                    if (!cliente_printAll(pArrayClientes, len) && output == -1)
                    {
                        output = 1;
                    }
                    break;
                case 2:
                    if (!(utn_getInt("\nINGRESE ID DEL CLIENTE: ","Error, reintentos", &bufferID, 3)))
                    {
                        if (cliente_FindById(pArrayClientes, len, bufferID, &bufferIndex))
                        {
                            printf("ID INVALIDO, VUELVA A LISTAR COMPLETAR O SALGA\n");
                        }
                        else
                        {
                            flag = 1;
                        }
                        output = 1;
                    }
                    break;
                case 3:
                    if (flag == 1)
                    {
                        if (!(utn_getString("\n(a). Ingrese nuevo nombre: ", "Error, reintentos", bufferAux.name,
                                SIZE_STR, 3)))
                        {
                            strncpy(pArrayClientes[bufferIndex]->name, bufferAux.name, SIZE_STR);
                            output = 0;
                        }
                    }
                    else
                    {
                        printf("DEBE INGRESAR ID PRIMERO\n");
                        output = 1;
                    }
                    break;
                case 4:
                    if (flag == 1)
                    {
                        if (!(utn_getString("(b). Ingrese nuevo apellido: ","Error, reintentos", bufferAux.lastName,SIZE_STR, 3)))
                        {
                            strncpy(pArrayClientes[bufferIndex]->lastName,bufferAux.lastName, SIZE_STR);
                            output = 0;
                        }
                    }
                    else
                    {
                        printf("DEBE INGRESAR ID PRIMERO\n");
                        output = 1;
                    }
                    break;
                case 5:
                    if (flag == 1)
                    {
                        do
                        {
                            if(!(utn_getStringWithOnlyNumbers("(c). Ingrese nuevo CUIT de 11 digitos: ", "Error - solo numeros,  reintentos", bufferAux.cuit, SIZE_STR, 3)))
                            {
                                bufferResultado = cliente_IsCuitValid(bufferAux.cuit);
                            }
                        }while(bufferResultado == 0);
                            strncpy(pArrayClientes[bufferIndex]->cuit,bufferAux.cuit, SIZE_STR);
                            output = 0;
                    }
                    else
                    {
                        printf("DEBE INGRESAR ID PRIMERO\n");
                        output = 1;
                    }
                    break;
                case 6:
                   printf("SALIENDO AL MENU PRINCIPAL\n");
                    break;
                default:
                    printf("ERROR, OPCION INVALIDA\n");
                }
            }
            printf("\nPresione una tecla para continuar");
            __fpurge(stdin);
            getchar();
            system("clear");
        } while (opcionMenuModificaciones != 6);
    }
    return output;
}

/**
 * @fn int cliente_PrintOne(Cliente)
 * @brief Funcion que muestra por pantalla un elemento de tipo Cliente
 *
 * @param Cliente: El elemento de tipo Cliente
 * @return (-1) Error (0) todo OK
 */
int cliente_PrintOne(Cliente *pUnCliente) {
    int output = -1;
    if(pUnCliente != NULL){
        printf("# %d %15s %15s %12s\n", pUnCliente->id, pUnCliente->name, pUnCliente->lastName, pUnCliente->cuit);
        output = 0;
    }
    return output;
}

/**
 * @fn int cliente_printAll(Cliente*, int)
 * @brief Funcion que imprime todos los elementos de un array de tipo Cliente
 *
 * @param pArray: El puntero al array de tipo Cliente
 * @param len: La longitud del array de tipo cliente
 * @return (-1) Error (0) todo OK
 */
int cliente_printAll(Cliente *pArrayClientes[], int len) {
    int output = -1;
    if (pArrayClientes != NULL && len > 0) {
        printColumn();
        for (int x = 0; x < len; x++) {
            cliente_PrintOne(pArrayClientes[x]);
        }
        output = 0;
    }
    return output;
}

/* ##################### SIN MEM DINAMICA ##################### */


/**
 * @fn int cliente_IsCuitValid(char*)
 * @brief Funcion que solicita verifica longitud de cuit
 *
 * @param bufferCuit: El char que almacena el cuit a verificar
 * @return (0) Error (1) todo OK
 */
int cliente_IsCuitValid(char *bufferCuit)
{
    int output = 0;
    int contador = 0;
    if(bufferCuit != NULL)
    {
        for(int x = 0; bufferCuit[x] != '\0'; x++)
        {
            contador++;
        }
        if(contador == 11)
        {
            output = 1;
        }
    }
    return output;
}



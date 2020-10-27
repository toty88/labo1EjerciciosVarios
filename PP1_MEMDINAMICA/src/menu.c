#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>
#include"utn.h"

/* ########################## MENUES ##################################*/

/**
 * @fn int menu_Principal(int*)
 * @brief Funcion que presenta el MENU PRINCIPAL al usuario
 *
 * @param pResultado: El puntero a int donde se guardara la opcion elegida por el usuario
 * @return (-1) Error (0) todo OK
 */
int menu_Principal(int *pResultado) {

    int output = -1;
    int opcion;
    if (pResultado != NULL) {
        if (!(utn_getInt(
              "\n######################################################\n"
                "################### MENU PRINCIPAL ###################\n"
                "######################################################\n"
                "(1). ALTA DE CLIENTE\n"
                "(2). MODIFICAR DATOS DE CLIENTE\n"
                "(3). BAJA DE CLIENTE\n"
                "(4). PUBLICAR\n"
                "(5). PAUSAR PUBLICACION\n"
                "(6). REANUDAR PUBLICACION\n"
                "(7). LISTAR CLIENTES CON PUBLICACIONES ACTIVAS\n"
                "(8). INFORMES\n"
                "(9). SALIR -------------> ","EROR, OPCION INVALIDA. REINTENTOS", &opcion, 3))) {

            *pResultado = opcion;
            output = 0;
        }
    }
    return output;
}

/**
 * @fn int menu_Modificar(int*)
 * @brief Funcion que presenta el MENU MODIFICACION DE CLIENTE al usuario
 *
 * @param pResultado: El puntero a int donde se guardara la opcion elegida por el usuario
 * @return (-1) Error (0) todo OK
 */
int menu_Modificar(int *pResultado) {

    int output = -1;
    int opcion;
    if(pResultado != NULL){
        if(!(utn_getInt(
                      "\n######################################################\n"
                        "################### MENU MODIFICAR ###################\n"
                        "######################################################\n"
                        "(1). LISTAR CLIENTES\n"
                        "(2). INGRESE ID DE CLIENTE\n"
                        "(3). MODIFICAR NOMBRE\n"
                        "(4). MODIFICAR APELLIDO\n"
                        "(5). MODIFICAR CUIT\n"
                        "(6). VOLVER MENU PRINCIPAL -------------> ","EROR, OPCION INVALIDA. REINTENTOS", &opcion, 3))){

            *pResultado = opcion;
            output = 0;
            }
    }
    return output;
}

/**
 * @fn int menu_Baja(int*)
 * @brief Funcion que presenta el MENU BAJA DE UN CLIENTE al usuario
 *
 * @param pResultado: El puntero a int donde se guardara la opcion elegida por el usuario
 * @return (-1) Error (0) todo OK
 */
int menu_Baja(int *pResultado){

    int output = -1;
    int opcion;
    if(pResultado != NULL){
        if(!(utn_getInt(""
                      "\n######################################################\n"
                        "##################### MENU BAJA ######################\n"
                        "######################################################\n"
                        "(1). LISTAR CLIENTES\n"
                        "(2). INGRESAR ID DEL CLIENTE A ELIMINAR\n"
                        "(3). VOLVER MENU PRINCIPAL -------------> ","EROR, OPCION INVALIDA. REINTENTOS", &opcion, 3))){

            *pResultado = opcion;
            output = 0;
        }

    }
    return output;
}

/**
 * @fn int menu_Informes(int*)
 * @brief Funcion que presenta el MENU INFORMES al usuario
 *
 * @param pResultado: El puntero a int donde se guardara la opcion elegida por el usuario
 * @return (-1) Error (0) todo OK
 */
int menu_Informes(int *pResultado) {

    int output = -1;
    int opcion;
    if (pResultado != NULL) {
        if (!(utn_getInt(
              "\n######################################################\n"
                "#################### MENU INFORMES ###################\n"
                "######################################################\n"
                "(1). LISTAR CLIENTE CON MAS AVISOS\n"
                "(2). LISTAR CANTIDAD DE AVISOS PAUSADOS\n"
                "(3). LISTAR RUBRO CON MAS AVISOS\n"
                "(4). CLIENTE CON MAS AVISOS PAUSADOS O ACTIVOS\n"
                "(5). SALIR -------------> ","EROR, OPCION INVALIDA. REINTENTOS", &opcion, 3))) {

            *pResultado = opcion;
            output = 0;
        }
    }
    return output;
}

/* ################ MENUES CLIENTES Y PUBLICACIONES ###################*/

/**
 * @fn int menu_ContratarPublicidad(int*)
 * @brief Funcion que presenta el MENU ALTA PUBLICIDAD al usuario
 *
 * @param pResultado: El puntero a int donde se guardara la opcion elegida por el usuario
 * @return (-1) Error (0) todo OK
 */
int menu_ContratarPublicidad(int *pResultado){
    int output = -1;
    int opcion;
    if(pResultado != NULL){
        if(!(utn_getInt(
          "\n######################################################\n"
            "############## MENU CONTRATAR PUBLICIDAD #############\n"
            "######################################################\n"
            "(1). LISTAR CLIENTES\n"
            "(2). INGRESE ID CLIENTE\n"
            "(3). INGRESE DATOS DEL AVISO\n"
            "(4). VOLVER MENU PRINCIPAL -------------> ","EROR, OPCION INVALIDA. REINTENTOS", &opcion, 3))){

            *pResultado = opcion;
            output = 0;
        }
    }
    return output;
}

/**
 * @fn int menu_PusarPublicacion(int*)
 * @brief Funcion que presenta el MENU PAUSAR/REANUDAR PUBLICACION al usuario
 *
 * @param pResultado: El puntero a int donde se guardara la opcion elegida por el usuario
 * @return (-1) Error (0) todo OK
 */
int menu_PusarPublicacion(int *pResultado){

    int output = -1;
    int opcion;
    if(pResultado != NULL){
        if(!(utn_getInt(""
                      "\n######################################################\n"
                        "######## MENU PAUSAR O REANUDAR PUBLICACION ##########\n"
                        "######################################################\n"
                        "(1). LISTAR PUBLICACIONES\n"
                        "(2). INGRESAR ID DE PUBLICACION A PAUSAR\n"
                        "(3). CONFIRMAR PAUSAR O REANUDAR PUBLICACION\n"
                        "(4). VOLVER MENU PRINCIPAL -------------> ","EROR, OPCION INVALIDA. REINTENTOS", &opcion, 3))){

            *pResultado = opcion;
            output = 0;
        }

    }
    return output;
}

/**
 * @fn int menu_ModificarPublicacion(int*)
 * @brief Funcion que presenta el MENU MODIFICAR PUBLICACION al usuario
 *
 * @param pResultado: El puntero a int donde se guardara la opcion elegida por el usuario
 * @return (-1) Error (0) todo OK
 */
int menu_ModificarPublicacion(int *pResultado) {

    int output = -1;
    int opcion;
    if(pResultado != NULL){
        if(!(utn_getInt(
                      "\n######################################################\n"
                        "######## MENU MODIFICAR CONTRATACION DE DIAS #########\n"
                        "######################################################\n"
                        "(1). INGRESE CUIT DE CLIENTE\n"
                        "(2). LISTAR PANTALLAS ASOCIADAS AL CUIT\n"
                        "(3). INGRESE ID DE CONTRATACION Y MODIFIQUE DIAS\n"
                        "(4). VOLVER MENU PRINCIPAL -------------> ","EROR, OPCION INVALIDA. REINTENTOS", &opcion, 3))){

            *pResultado = opcion;
            output = 0;
            }
    }
    return output;
}


/* ########################## PRINTS ##################################*/

void printColumn(void){

    char sp = ' ';

    printf(
      "\n##################################################\n"
        "############### LISTA DE CLIENTES ################\n"
        "##################################################\n");
    printf("# %1cID%10cNOMBRE%8cAPELLIDO%9cCUIT\n", sp, sp, sp, sp);
    printf("##################################################\n\n");

}

void printColumnSingleCliente(void){

    char sp = ' ';

    printf(
      "\n##################################################\n"
        "############ DATOS DEL CLIENTE OWNER #############\n"
        "##################################################\n");
    printf("# %1cID%10cNOMBRE%8cAPELLIDO%9cCUIT\n", sp, sp, sp, sp);
    printf("##################################################\n\n");

}

void printColumnPublicacion(void){

    char sp = ' ';

    printf(
      "\n########################################################################################################\n"
        "###################################### LISTA DE PUBLICACIONES ##########################################\n"
        "########################################################################################################\n");
    printf("# %1cID%10cRUBRO%8cESTADO%59cDESCRIPCION\n", sp, sp, sp, sp);
    printf("########################################################################################################\n\n");

}

void printColumnPublicacionesDeUnCliente(void){

    char sp = ' ';

    printf(
      "\n########################################################################################################\n"
        "################################ LISTA DE PUBLICACIONES DEL CLIENTE ####################################\n"
        "########################################################################################################\n");
    printf("# %1cID%10cRUBRO%8cESTADO%59cDESCRIPCION\n", sp, sp, sp, sp);
    printf("########################################################################################################\n");

}

void printColumnClientYpublicacionesActivas(void){

    char sp = ' ';

    printf(
         "\n#####################################################################\n"
           "############ LISTA DE CLIENTE CON PUBLICACIONES ACTIVAS #############\n"
           "#####################################################################\n");
    printf("# %1cID%10cNOMBRE%8cAPELLIDO%9cCUIT%5cAVISOS ACTIVOS\n", sp, sp, sp, sp, sp);
    printf("#####################################################################\n");

}

void printColumnClienteYPublicacion(void){

    char sp = ' ';

    printf(
      "\n#####################################################################################################################################################################\n"
        "####################################################### DETALLE DE CLIENTES Y DETALLE DE PUBLICACIONES ##############################################################\n"
        "#####################################################################################################################################################################\n");
    printf("# %1cID%10cNOMBRE%8cAPELLIDO%9cCUIT %1cID PUBLICACION%10cRUBRO%8cESTADO%59cDESCRIPCION\n", sp, sp, sp, sp, sp, sp, sp, sp);
    printf("#####################################################################################################################################################################\n\n");

}

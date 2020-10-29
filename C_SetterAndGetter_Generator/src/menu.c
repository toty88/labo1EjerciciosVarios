#include"menu.h"

int menu_Main(int *pResult)
{
    int output = -1;
    int option;
    if (pResult != NULL)
    {
        if (!(utn_getInt(
              "\n######################################################\n"
                "################### MENU PRINCIPAL ###################\n"
                "######################################################\n"
                "(1). INGRESE EL NOMBRE DE LA ESTRUCTURA\n"
                "(2). INGRESE TIPO Y NOMBRE DE CAMPOS DE LA ESTRUCTURA\n"
                "(3). IMPRIMIR SETTERS Y GETTERS\n"
                "(4). SALIR -------------> ","EROR, OPCION INVALIDA. REINTENTOS", &option, 3)))
        {
            *pResult = option;
            output = 0;
        }
    }
    return output;
}

int menu_Variables(int *pResult)
{
    int output = -1;
    int option;
    if (pResult != NULL)
    {
        if (!(utn_getIntConMinMax(
          "\n######################################################\n"
            "############## MENU TIPO & NOMBRE CAMPO ##############\n"
            "######################################################\n"
            "(1).  int\n"
            "(2).  int*\n"
            "(3).  char\n"
            "(4).  char*\n"
            "(5).  float\n"
            "(6).  float*\n"
            "(7).  long\n"
            "(8).  long* "
            "      OPCION -------------> ","Error, reintentos", &option, 1, 9, 3)))
        {
            *pResult = option;
            output = 0;
        }
    }
    return output;
}

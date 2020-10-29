#include<stdio.h>
#include<stdlib.h>
#include"menu.h"

int menu_Principal(int *pResultado)
{
    int output = -1;
    int opcion;
    if (pResultado != NULL)
    {
        if (!(utn_getInt(
              "\n######################################################\n"
                "################### MENU PRINCIPAL ###################\n"
                "######################################################\n"
                "(1). INGRESE EL NOMBRE DE LA ESTRUCTURA\n"
                "(2). INGRESE TIPO Y NOMBRE DE CAMPOS DE LA ESTRUCTURA\n"
                "(3). IMPRIMIR SETTERS Y GETTERS\n"
                "(4). SALIR -------------> ","EROR, OPCION INVALIDA. REINTENTOS", &opcion, 3)))
        {
            *pResultado = opcion;
            output = 0;
        }
    }
    return output;
}

int menu_Campos(int *pResultado)
{
    int output = -1;
    int opcion;
    if (pResultado != NULL)
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
            "      OPCION -------------> ","Error, reintentos", &opcion, 1, 9, 3)))
        {
            *pResultado = opcion;
            output = 0;
        }
    }
    return output;
}

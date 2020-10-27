#ifndef MENU_H_
#define MENU_H_

#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>
#include"utn.h"

/* ######################## MENUES GENERALES ############################*/

int menu_Principal(int*);
int menu_Modificar(int*);
int menu_Baja(int*);
int menu_Informes(int*);

/* ################# MENUES CLIENTES Y PUBLICACIONES ###################*/

int menu_ModificarPublicacion(int*);
int menu_ContratarPublicidad(int*);
int menu_PusarPublicacion(int*);

/* ######################## HEADERS LISTAS #############################*/

void printColumn(void);
void printColumnSingleCliente(void);
void printColumnPublicacion(void);
void printColumnClienteYPublicacion(void);
void printColumnPublicacionesDeUnCliente(void);
void printColumnClientYpublicacionesActivas(void);


#endif /* MENU_H_ */

/*
 * informes.h
 *
 *  Created on: Oct 13, 2020
 *      Author: toty
 */

#ifndef INFORMES_H_
#define INFORMES_H_

#include"cliente_publicacion.h"
#define SIZE_ARRAY_RUBROS 100

typedef struct{

    int rubro;
    int isEmpty;
}Rubro;

/* ################ CON MEM DINAMICA ################### */

int rubro_GenerarRubros(Rubro*, int, Publicacion**);
int rubro_CalcularRubroConMasAvisos(Rubro* ,int, Publicacion**, int, int*);
int informes_CalcularClientesConMasAvisos(Publicacion**, int, Cliente**, int, int*, int*);
int informes_CalcularCantidadDeAvisosPausados(Publicacion**, int, int*);
int cliente_publicacion_PrintClienteConMasAvisosActivos(Publicacion**, int, Cliente**, int, int*, int*);
int cliente_publicacion_PrintClienteConMasAvisosPusados(Publicacion**, int, Cliente**, int, int*, int*);
int informes_GenerarInformes(Publicacion**, int, Cliente**, int, Rubro*, int);
/* ################ SIN MEM DINAMICA ################### */
int cliente_publicacion_PrintClienteConMasAvisosActivosOPusados(Publicacion *pArrayPublicacion[], int lenPublicacion, Cliente *pArrayClientes[], int lenCliente, int activoPausado, int *bufferIndex, int* contadorAvisos)
;



int rubro_Init(Rubro*, int);
int rubro_ExisteRubro(Rubro*, int, int);








#endif /* INFORMES_H_ */

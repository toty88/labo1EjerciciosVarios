#ifndef PUBLICACION_H_
#define PUBLICACION_H_

#include<stdio.h>
#include"menu.h"
#include"utn.h"
#define SIZE_ARRAY_PUBLICACION 1000
#define SIZE_AVISO 64
#define FALSE 0
#define TRUE 1
#define ACTIVA 1
#define NO_ACTIVA 0 // PAUSADA

typedef struct{

	int id;
	int idCliente;
	int numeroRubro;
	char descripcionAviso[SIZE_AVISO];
	int estado;
	//int isEmpty;

}Publicacion;



/* ############# CON MEM DINAMICA ################ */
int publicacion_Init(Publicacion**, int);
Publicacion* publicacion_NewPublicacionConParametros(int, int, int, char*);
int publicacion_HardCodeo(Publicacion**);
int publicacion_FindById(Publicacion**, int, int, int*);
int publicacion_FindByClientId(Publicacion**, int, int, int*);
int publicacion_FindFree(Publicacion**, int, int*);
int publicacion_Create(Publicacion**, int, int, int*);
int publicacion_IsActive(Publicacion*, int);
int publicacion_PrintOne(Publicacion*);
int publicacion_printAll(Publicacion**, int);
/* ############# SIN MEM DINAMICA ################ */








int publicacion_Remove(Publicacion**, int, int);





#endif /* PUBLICACION_H_ */

#ifndef CLIENTE_H_
#define CLIENTE_H_

//#include<stdio.h>
#include"menu.h"
#include"utn.h"
#define SIZE_ARRAY_CLIENTES 100
#define SIZE_STR 51
#define FALSE 0
#define TRUE 1

typedef struct{

	int id;
	char name[SIZE_STR];
	char lastName[SIZE_STR];
	char cuit[SIZE_STR];
	//int isEmpty;

}Cliente;

/* ##################### CON MEM DINAMICA ##################### */
Cliente* cliente_NewClienteSinParametros(void);
Cliente* cliente_NewClienteConParametros(int, char*, char*, char*);
int cliente_Init(Cliente**, int);;
int cliente_HardCodeo(Cliente**);
int cliente_FindFree(Cliente**, int, int*);
int cliente_Create(Cliente**, int);
int cliente_FindById(Cliente**, int, int, int*);
int cliente_Modify(Cliente**, int);
int cliente_Remove(Cliente**, int);
int cliente_DoesIdExist(Cliente**, int, int);
int cliente_PrintOne(Cliente*);
int cliente_printAll(Cliente**, int);

/* ##################### SETTERS & GETTERS ##################### */
int cliente_setName(Cliente*, char*);
int cliente_setLastName(Cliente*, char*);
int cliente_setCuit(Cliente*, char*);
/* ##################### SIN MEM DINAMICA ##################### */







int cliente_IsCuitValid(char*);





#endif /* CLIENTE_H_ */

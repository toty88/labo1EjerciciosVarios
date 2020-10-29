
#ifndef GHOST_H_
#define GHOST_H_

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
#include"utn.h"
#include"menu.h"
#define SIZE_ARRAY_GHOST 50
#define SIZE_VAR_NAME 30
#define TRUE 1
#define FALSE 0

typedef struct
{
    char varType[SIZE_VAR_NAME];
    char varName[SIZE_VAR_NAME];
    int isEmpty;

}Ghost;

int ghost_Init(Ghost*, int);
int ghost_varNameToCamelCase(char*);
int ghost_removeDot(char*);
int ghost_generateSetterChar(char*, char*, char*);
int ghost_generateSetterWithoutChar(char*, char*, char*);
int ghost_generateGetterChar(char*, char*, char*);
int ghost_generateGetterWithoutChar(char*, char*, char*);
int ghost_generateIsValid(char*, char*);
int ghost_generateConstructorNew(char*);
int ghost_generateConstructorNewParam(Ghost*, int, char*);

int ghost_generateStructure(Ghost*, int, char*);
int ghost_generateConstructorsPrototypes(Ghost*, int, char*);
int ghost_generateSettersPrototypes(Ghost*, int, char*);
int ghost_generateGettersPrototypes(Ghost*, int, char*);

int ghost_copyFields(Ghost*, int, char*, char*);
int ghost_inputVariables(Ghost*, int*, char*);

int ghost_printSettersAndGetters(Ghost*, int, char*);
int ghost_printConstructors(Ghost*, int, char*);
int ghost_printConstructorsPrototypes(Ghost*, int, char*);
int ghost_printSettersPrototypes(Ghost*, int, char*);
int ghost_printGettersPrototypes(Ghost*, int, char*);
int ghost_printStructureBody(Ghost*, int, char*);


#endif /* GHOST_H_ */

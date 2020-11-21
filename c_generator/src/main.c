#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "ghost.h"
#include"utn.h"
#include"menu.h"

int main(void) {

    Ghost pArrayGhost[SIZE_ARRAY_GHOST];
    ghost_Init(pArrayGhost, SIZE_ARRAY_GHOST);

    char bufferStructureName[SIZE_VAR_NAME];
    char bufferVarName[SIZE_VAR_NAME];

    int menuOption;
    int flagCase1 = 0;
    int flagCase2 = 0;
    int varCounter = 0;

    do
    {
        if (!(menu_Main(&menuOption)))
        {
            switch (menuOption)
            {
            case 1:
                if (!(utn_getString("Ingrese nombre: ", "Error, reintentos",bufferStructureName, SIZE_VAR_NAME, 3)))
                {
                    flagCase1 = 1;
                }
                break;
            case 2:
                if(flagCase1 == 1)
                {
                    if(!(ghost_inputVariables(pArrayGhost, &varCounter, bufferVarName)))
                    {
                        flagCase2 = 1;
                    }
                }
                else
                {
                    printf("\nError, Primero debe ingresar nombre de estructura\n");
                }
                break;
            case 3:
                if(flagCase1 == 1 && flagCase2 == 1)
                {
                    if( !(ghost_printStructureBody(pArrayGhost, SIZE_ARRAY_GHOST, bufferStructureName))
                            && !(ghost_printConstructorsPrototypes(pArrayGhost, SIZE_ARRAY_GHOST, bufferStructureName))
                            && !(ghost_printSettersPrototypes(pArrayGhost, SIZE_ARRAY_GHOST, bufferStructureName))
                            && !(ghost_printGettersPrototypes(pArrayGhost, SIZE_ARRAY_GHOST, bufferStructureName))
                            && !(ghost_printIsValidPrototypes(pArrayGhost, SIZE_ARRAY_GHOST, bufferStructureName))
                            )
                    {
                        printf("\n\n<<<<<<<< PROTOTIPOS COPIADAS AL .h >>>>>>>>\n");
                    }
                    if(!(ghost_printConstructors(pArrayGhost, SIZE_ARRAY_GHOST, bufferStructureName))
                            &&!(ghost_printSettersAndGetters(pArrayGhost, SIZE_ARRAY_GHOST, bufferStructureName)))
                    {
                        printf("\n<<<<<<<< FUNCIONES COPIADAS AL .c >>>>>>>>\n");
                    }
                }
                else
                {
                    printf("\nError, Primero debe ingresar nombre estructura o cargar campos\n");
                }
                break;
            case 4:
                printf("Hasta luego\n");
                break;
            default:
                printf("Error, opcion invalida\n");
            }
        }
    } while (menuOption != 4);
    return 0;
}

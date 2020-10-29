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
        if (!(menu_Principal(&menuOption)))
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
                    if( !(ghost_printConstructors(pArrayGhost, SIZE_ARRAY_GHOST, bufferStructureName))
                            &&!(ghost_printSettersAndGetters(pArrayGhost, SIZE_ARRAY_GHOST, bufferStructureName)))
                    {
                        printf("\n<<<<<<<< FUNCIONES IMPRESAS CON EXITO >>>>>>>>\n");
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
                printf("Error, menuOption invalida\n");
            }
        }
    } while (menuOption != 4);
    return 0;
}

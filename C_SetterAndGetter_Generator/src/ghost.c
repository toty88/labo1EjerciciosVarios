#include "ghost.h"

int ghost_Init(Ghost *pArrayGhost, int len) {
    int output = -1;
    if (pArrayGhost != NULL && len > 0) {
        for (int x = 0; x < len; x++) {
            pArrayGhost[x].isEmpty = TRUE;
        }
        output = 0;
    }
    return output;
}

int ghost_generateStructure(Ghost *pArrayGhost, int len, char* varStructureName)
{
    int output = -1;
    char varStructureNameAux[SIZE_VAR_NAME];

    if(pArrayGhost != NULL && len > 0 && varStructureName != NULL)
    {
        strncpy(varStructureNameAux, varStructureName, SIZE_VAR_NAME);
        varStructureNameAux[0] = toupper(varStructureNameAux[0]);
        printf("\ntypedef struct\n{");
        for(int x = 0; x < len; x ++)
        {
            if(pArrayGhost[x].isEmpty == FALSE)
            {
                if(strncmp(pArrayGhost[x].varType, "char*", SIZE_VAR_NAME) == 0)
                {
                    printf("\n\tchar %s[SIZE_STR];", pArrayGhost[x].varName);
                }
                else
                {
                    printf("\n\t%s %s;", pArrayGhost[x].varType, pArrayGhost[x].varName);
                }
                output = 0;
            }
        }
        printf("\n\n}%s;\n", varStructureNameAux);
    }
    return output;
}
int ghost_generateConstructorsPrototypes(Ghost *pArrayGhost, int len, char* varStructureName)
{
    int output = -1;
    char varStructureNameAux[SIZE_VAR_NAME];

    if(pArrayGhost != NULL && len > 0 && varStructureName != NULL)
    {
        strncpy(varStructureNameAux, varStructureName, SIZE_VAR_NAME);
        varStructureNameAux[0] = toupper(varStructureNameAux[0]);
        printf("\n%s* %s_new(void);\n",varStructureNameAux, varStructureName);
        printf("%s* %s_newParam(",varStructureNameAux, varStructureName);
        for(int x = 0; x < len; x++)
        {
            if(pArrayGhost[x].isEmpty == FALSE)
            {
                printf("%s %s", pArrayGhost[x].varType, pArrayGhost[x].varName);
                if(pArrayGhost[x+1].isEmpty == TRUE)
                {
                    break;
                }
                else
                {
                    printf(", ");
                }
                output = 0;
            }
        }
        printf(");");
    }

    return output;
}

int ghost_generateSettersPrototypes(Ghost *pArrayGhost, int len, char* varStructureName)
{
    int output = -1;
    char varStructureNameAux[SIZE_VAR_NAME];
    char varNameVariableAux[SIZE_VAR_NAME];

    if(pArrayGhost != NULL && len > 0 && varStructureName != NULL)
    {
        strncpy(varStructureNameAux, varStructureName, SIZE_VAR_NAME);
        varStructureNameAux[0] = toupper(varStructureNameAux[0]);
        for(int x = 0; x < len; x++)
        {
           if(pArrayGhost[x].isEmpty == FALSE)
           {
               strncpy(varNameVariableAux, pArrayGhost[x].varName, SIZE_VAR_NAME);
               varNameVariableAux[0] = toupper(varNameVariableAux[0]);
               printf("\nint %s_set%s(%s* this, %s %s);", varStructureName,
                                                              varNameVariableAux,
                                                              varStructureNameAux,
                                                              pArrayGhost[x].varType,
                                                              pArrayGhost[x].varName);
               output = 0;
           }
        }
    }
    return output;
}

int ghost_generateGettersPrototypes(Ghost *pArrayGhost, int len, char* varStructureName)
{
    int output = -1;
    char varStructureNameAux[SIZE_VAR_NAME];
    char varNameVariableAux[SIZE_VAR_NAME];

    if(pArrayGhost != NULL && len > 0 && varStructureName != NULL)
    {
        strncpy(varStructureNameAux, varStructureName, SIZE_VAR_NAME);
        varStructureNameAux[0] = toupper(varStructureNameAux[0]);
        for(int x = 0; x < len; x++)
        {
           if(pArrayGhost[x].isEmpty == FALSE)
           {
               strncpy(varNameVariableAux, pArrayGhost[x].varName, SIZE_VAR_NAME);
               varNameVariableAux[0] = toupper(varNameVariableAux[0]);
               printf("\n%s %s_get%s(%s* this);", pArrayGhost[x].varType,
                                                  varStructureName,
                                                  varNameVariableAux,
                                                  varStructureNameAux);
               output = 0;
           }
        }
    }
    return output;
}

int ghost_generateSetterChar(char* varType, char* varName, char* varStructureName)
{
    int output = -1;
    char varStructureNameAux[SIZE_VAR_NAME];
    char varNameVariableAux[SIZE_VAR_NAME];


    if(varType != NULL && varName != NULL && varStructureName != NULL)
    {
        strncpy(varNameVariableAux, varName, SIZE_VAR_NAME);
        strncpy(varStructureNameAux, varStructureName, SIZE_VAR_NAME);
        varStructureNameAux[0] = toupper(varStructureNameAux[0]);
        varNameVariableAux[0] = toupper(varNameVariableAux[0]);

        printf("\nint %s_set%s(%s* this, %s %s)\n{\n", varStructureName,
                                                       varNameVariableAux,
                                                       varStructureNameAux,
                                                       varType,
                                                       varName);
        printf("\tint output = -1;\n\tif(this != NULL && IsValid%s(%s))\n",varNameVariableAux, varName);
        printf("\t{\n");
        printf("\t\tstrncpy(this->%s,%s,(int)sizeof(this->%s));\n\t\toutput = 0;\n", varName, varName, varName);
        printf("\t}\n\treturn output;\n");
        printf("}\n\n");
        output = 0;
    }
    return output;
}

int ghost_generateSetterWithoutChar(char* varType, char* varName, char* varStructureName)
{
    int output = -1;
    char varStructureNameAux[SIZE_VAR_NAME];
    char varNameVariableAux[SIZE_VAR_NAME];

    if(varType != NULL && varName != NULL && varStructureName != NULL)
    {
        strncpy(varNameVariableAux, varName, SIZE_VAR_NAME);
        strncpy(varStructureNameAux, varStructureName, SIZE_VAR_NAME);
        varStructureNameAux[0] = toupper(varStructureNameAux[0]);
        varNameVariableAux[0] = toupper(varNameVariableAux[0]);

        printf("\nint %s_set%s(%s* this, %s %s)\n{\n", varStructureName,
                                                       varNameVariableAux,
                                                       varStructureNameAux,
                                                       varType,
                                                       varName);
        printf("\tint output = -1;\n\tif(this != NULL  && IsValid%s(%s))\n",varNameVariableAux, varName);
        printf("\t{\n");
        printf("\t\tthis->%s = %s;\n\t\toutput = 0;\n", varName, varName);
        printf("\t}\n\t return output;\n");
        printf("}\n\n");
        output = 0;
    }
    return output;
}

int ghost_generateGetterChar(char* varType, char* varName, char* varStructureName)
{
    int output = -1;
    char varStructureNameAux[SIZE_VAR_NAME];
    char varNameVariableAux[SIZE_VAR_NAME];

    if(varType != NULL && varName != NULL && varStructureName != NULL)
    {
        strncpy(varNameVariableAux, varName, SIZE_VAR_NAME);
        strncpy(varStructureNameAux, varStructureName, SIZE_VAR_NAME);
        varStructureNameAux[0] = toupper(varStructureNameAux[0]);
        varNameVariableAux[0] = toupper(varNameVariableAux[0]);

        printf("\n%s %s_get%s(%s* this)\n{\n",  varType,
                                                varStructureName,
                                                varNameVariableAux,
                                                varStructureNameAux);

        printf("\treturn this->%s;\n", varName);
        printf("}\n");
        output = 0;
    }
    return output;
}

int ghost_generateGetterWithoutChar(char* varType, char* varName, char* varStructureName)
{
    int output = -1;
    char varStructureNameAux[SIZE_VAR_NAME];
    char varNameVariableAux[SIZE_VAR_NAME];

    if(varType != NULL && varName != NULL && varStructureName != NULL)
    {
        strncpy(varNameVariableAux, varName, SIZE_VAR_NAME);
        strncpy(varStructureNameAux, varStructureName, SIZE_VAR_NAME);
        varStructureNameAux[0] = toupper(varStructureNameAux[0]);
        varNameVariableAux[0] = toupper(varNameVariableAux[0]);

        printf("\n%s %s_get%s(%s* this)\n{\n",  varType,
                                                varStructureName,
                                                varNameVariableAux,
                                                varStructureNameAux);
        printf("\treturn this->%s;\n", varName);
        printf("}\n");

        output = 0;
    }
    return output;
}

int ghost_generateIsValid(char* varType, char* varName)
{
    int output = -1;
    char varNameVariableAux[SIZE_VAR_NAME];

    if(varType != NULL && varName != NULL)
    {
        strncpy(varNameVariableAux, varName, SIZE_VAR_NAME);
        varNameVariableAux[0] = toupper(varNameVariableAux[0]);
        printf("int isValid%s(%s %s)\n{\n\treturn 1;\n}\n",varNameVariableAux,varType,varName);
        output = 0;
    }
    return output;
}

int ghost_generateConstructorNewParam(Ghost *pArrayGhost, int len, char* varStructureName)
{
    int output = -1;
    char varStructureNameAux[SIZE_VAR_NAME];
    char varNameVariableAux[SIZE_VAR_NAME];
    if(pArrayGhost != NULL && len > 0 && varStructureName != NULL)
    {

        strncpy(varStructureNameAux, varStructureName, SIZE_VAR_NAME);
        varStructureNameAux[0] = toupper(varStructureNameAux[0]);
        printf("\n%s* %s_newParam(",varStructureNameAux, varStructureName);
        for(int x = 0; x < len; x++)
        {
            if(pArrayGhost[x].isEmpty == FALSE)
            {
                printf("%s %s", pArrayGhost[x].varType, pArrayGhost[x].varName);
                if(pArrayGhost[x+1].isEmpty == TRUE)
                {
                    break;
                }
                else
                {
                    printf(", ");
                }
            }
        }
        printf(")\n{\n");
        printf("\t%s* this = %s_new();\n",varStructureNameAux, varStructureName);
        printf("\tif(this != NULL)\n\t{\n");
        printf("\t\tif(");
        for(int x = 0; x < len-1; x++)
        {
            if(pArrayGhost[x].isEmpty == FALSE)
            {
                strncpy(varNameVariableAux, pArrayGhost[x].varName, SIZE_VAR_NAME);
                varNameVariableAux[0] = toupper(varNameVariableAux[0]);
                printf("!(%s_set%s(this, %s))",varStructureName,varNameVariableAux,pArrayGhost[x].varName);
                if(pArrayGhost[x+1].isEmpty == TRUE)
                {
                    break;
                }
                else
                {
                    printf("\n\t\t\t&& ");
                }
            }
        }
        printf(")\n\t\t{\n\t\t\treturn this;\n\t\t}\n\t}\n\treturn NULL\n}\n");
        output = 0;

    }
    return output;
}

int ghost_generateConstructorNew(char* varStructureName)
{
    int output = -1;
    char varStructureNameAux[SIZE_VAR_NAME];
    if(varStructureName != NULL)
    {
        strncpy(varStructureNameAux, varStructureName, SIZE_VAR_NAME);
        varStructureNameAux[0] = toupper(varStructureNameAux[0]);
        printf("\n\n%s* %s_new(void)\n{\n"
                "\treturn (%s*)malloc(sizeof(%s));\n"
                "}\n", varStructureNameAux,varStructureName,varStructureNameAux,varStructureNameAux);
        output = 0;

    }
    return output;
}

int ghost_copyFields(Ghost *pArrayGhost, int index, char* varType, char* varName)
{
    int output = -1;
    if(pArrayGhost != NULL && index >= 0 && varType != NULL && varName != NULL)
    {
        strncpy(pArrayGhost[index].varType, varType, SIZE_VAR_NAME);
        strncpy(pArrayGhost[index].varName, varName, SIZE_VAR_NAME);
        pArrayGhost[index].isEmpty = FALSE;
        output = 0;
    }
    return output;
}

int ghost_inputVariables(Ghost *pArrayGhost, int *VarCounter, char* varName)
{
    int output = -1;
    int keepGoing = TRUE;
    int bufferOption;
    int bufferVarCounter = *VarCounter;

    do
    {
       if (!(menu_Variables(&bufferOption))
           && !(utn_getString("Ingrese nombre de variable: ","Error, reintentos", varName,SIZE_VAR_NAME, 3)))
        {
            switch (bufferOption)
            {
            case 1:
                if(!(ghost_copyFields(pArrayGhost, bufferVarCounter, "int", varName)))
                {
                    output = 0;
                }
                break;
            case 2:
                if(!(ghost_copyFields(pArrayGhost, bufferVarCounter, "int*", varName)))
                {
                    output = 0;
                }
                break;
            case 3:
                if(!(ghost_copyFields(pArrayGhost, bufferVarCounter, "char", varName)))
                {
                    output = 0;
                }
                break;
            case 4:
                if(!(ghost_copyFields(pArrayGhost, bufferVarCounter, "char*", varName)))
                {
                    output = 0;
                }
                break;
            case 5:
                if(!(ghost_copyFields(pArrayGhost, bufferVarCounter, "float", varName)))
                {
                    output = 0;
                }
                break;
            case 6:
                if(!(ghost_copyFields(pArrayGhost, bufferVarCounter, "float*", varName)))
                {
                    output = 0;
                }
                break;
            case 7:
                if(!(ghost_copyFields(pArrayGhost, bufferVarCounter, "long", varName)))
                {
                    output = 0;
                }
                break;
            case 8:
                if(!(ghost_copyFields(pArrayGhost, bufferVarCounter, "long*", varName)))
                {
                    output = 0;
                }
                break;
            default:
                printf("error, vuelva a intentarlo\n");
                break;
            }
        }
       if((bufferOption > 0 && bufferOption < 9))
       {
           bufferVarCounter++;
           *VarCounter = bufferVarCounter;
       }
       if(utn_getIntConMinMax("(1). CONTINUAR\n(0). SALIR  -------------> ", "Error, reintentos", &keepGoing, 0, 1, 3))
       {
           printf("Error, volviendo al menu principal\n");
           keepGoing = FALSE;
       }
    }while (keepGoing == TRUE);
    return output;
}

int ghost_printSettersAndGetters(Ghost *pArrayGhost, int len, char* varStructureName)
{
    int output = -1;
    if(pArrayGhost != NULL && len > 0 && varStructureName != NULL)
    {

        for(int x = 0; x < len; x++)
        {
            if(pArrayGhost[x].isEmpty == FALSE)
            {
                if(((strncmp(pArrayGhost[x].varType, "char*", 50)==0 || strncmp(pArrayGhost[x].varType, "char", SIZE_VAR_NAME)==0)
                   && !(ghost_generateGetterChar(pArrayGhost[x].varType, pArrayGhost[x].varName,varStructureName))
                   && !(ghost_generateSetterChar(pArrayGhost[x].varType, pArrayGhost[x].varName,varStructureName)))
                   ||
                   (!(ghost_generateGetterWithoutChar(pArrayGhost[x].varType, pArrayGhost[x].varName,varStructureName))
                   && !(ghost_generateSetterWithoutChar(pArrayGhost[x].varType, pArrayGhost[x].varName,varStructureName))))
                    {
                        output = 0;
                    }
                ghost_generateIsValid(pArrayGhost[x].varType, pArrayGhost[x].varName);
            }
        }
    }
    return output;
}

int ghost_printConstructors(Ghost *pArrayGhost, int len, char* varStructureName)
{
    int output = -1;
    if(pArrayGhost != NULL && len > 0 && varStructureName != NULL)
    {
        if(!(ghost_generateConstructorNew(varStructureName))
                && !(ghost_generateConstructorNewParam(pArrayGhost, len, varStructureName)))
        {
            output = 0;
        }
    }
    return output;
}

int ghost_printConstructorsPrototypes(Ghost *pArrayGhost, int len, char* varStructureName)
{
    int output = -1;
    if(pArrayGhost != NULL && len > 0 && varStructureName != NULL)
    {
        if(!(ghost_generateConstructorsPrototypes(pArrayGhost, len, varStructureName)))
        {
            output = 0;
        }
    }
    return output;
}

int ghost_printSettersPrototypes(Ghost *pArrayGhost, int len, char* varStructureName)
{
    int output = -1;
    if(pArrayGhost != NULL && len > 0 && varStructureName != NULL)
    {
        if(!(ghost_generateSettersPrototypes(pArrayGhost, len, varStructureName)))
        {
            output = 0;
        }
    }
    return output;
}

int ghost_printGettersPrototypes(Ghost *pArrayGhost, int len, char* varStructureName)
{
    int output = -1;
    if(pArrayGhost != NULL && len > 0 && varStructureName != NULL)
    {
        if(!(ghost_generateGettersPrototypes(pArrayGhost, len, varStructureName)))
        {
            output = 0;
        }
    }
    return output;
}

int ghost_printStructureBody(Ghost *pArrayGhost, int len, char* varStructureName)
{
    int output = 0;
    if(pArrayGhost != NULL && len > 0 && varStructureName != NULL)
    {
        if(!(ghost_generateStructure(pArrayGhost, len, varStructureName)))
        {
            output = 0;
        }
    }
    return output;
}








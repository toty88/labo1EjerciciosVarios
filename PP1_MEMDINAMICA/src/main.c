#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>
#include"utn.h"
#include"menu.h"
#include"cliente.h"
#include"publicacion.h"
#include"cliente_publicacion.h"
#include"informes.h"


int main(void)
{
    Cliente *pArrayCliente[SIZE_ARRAY_CLIENTES];
    cliente_Init(pArrayCliente, SIZE_ARRAY_CLIENTES);
    cliente_HardCodeo(pArrayCliente);

    Publicacion *pArrayPublicacion[SIZE_ARRAY_PUBLICACION];
    publicacion_Init(pArrayPublicacion, SIZE_ARRAY_PUBLICACION);
    publicacion_HardCodeo(pArrayPublicacion);




    Rubro ruArray[SIZE_ARRAY_RUBROS];

    int flagAltaCliente = 1;
    int flagAltaPublicacion = 1;
    int bufferResultado;
    int bufferOpcionMenuPrincipal;

    do {
        if (!(menu_Principal(&bufferOpcionMenuPrincipal)))
        {
            switch (bufferOpcionMenuPrincipal)
            {
            case 1: // ALTA CLIENTE
                bufferResultado = cliente_Create(pArrayCliente, SIZE_ARRAY_CLIENTES);
                if(bufferResultado == 0)
                {
                    printf("\n >>>>> CLIENTE CREADO CON EXITO <<<<<\n");
                    flagAltaCliente = 1;
                }
                else if(bufferResultado == 1)
                {
                    printf("\n >>>>> SIN ESPACIO PARA CREAR CLIENTE <<<<<\n");
                }
                else
                {
                    printf("\n >>>>> ERROR AL QUERER CREAR CLIENTE <<<<<\n");
                }
                break;
            case 2: // MODIFICAR DATOS CLIENTES
                if(flagAltaCliente == 1)
                {
                    bufferResultado = cliente_Modify(pArrayCliente, SIZE_ARRAY_CLIENTES);
                    if(bufferResultado == 0)
                    {
                        printf("\n >>>>> CLIENTE MODIFICADO CON EXITO <<<<<\n");
                    }
                    else if(bufferResultado == 1)
                    {
                        printf("\n >>>>> NO SE REALIZO NINGUNA MODIFICACION <<<<<\n");
                    }
                    else
                    {
                        printf("\n >>>>> ERROR AL QUERER MODIFICAR CLIENTE <<<<<\n");
                    }
                }
                else
                {
                    printf("ES NECESARIO UN ALTA PARA INGRESAR A ESTA OPCION. INTENTE OPCION 1\n");
                }
                break;
            case 3: // BAJA CLIENTE
                if(flagAltaCliente == 1)
                {
                    bufferResultado = cliente_publicacion_RemoveClienteConPublicaciones(pArrayPublicacion, SIZE_ARRAY_PUBLICACION, pArrayCliente, SIZE_ARRAY_CLIENTES);
                    if(bufferResultado == 0)
                    {
                        printf("\n >>>>> CLIENTE DADO DE BAJA CON EXITO <<<<<\n");
                    }
                    else if(bufferResultado == 1)
                    {
                        printf("\n >>>>> NO SE REALIZO BAJA <<<<<\n");
                    }
                    else
                    {
                        printf("\n >>>>> ERROR AL QUERER REALIZAR BAJA <<<<<\n");
                    }
                }
                else
                {
                    printf("ES NECESARIO UN ALTA PARA INGRESAR A ESTA OPCION. INTENTE OPCION 1\n");
                }
                break;
            case 4: // ALTA PUBLICACION
                if(flagAltaCliente == 1)
                {
                    bufferResultado = cliente_publicacion_AltaPublicidad(pArrayPublicacion, SIZE_ARRAY_PUBLICACION, pArrayCliente, SIZE_ARRAY_CLIENTES);
                    if(bufferResultado == 0)
                    {
                        printf("\n >>>>> AVISO CREADO CON EXITO <<<<<\n");
                        flagAltaPublicacion = 1;
                    }
                    else if(bufferResultado == 1)
                    {
                        printf("\n >>>>> NO SE CREO NINGUN AVISO <<<<<\n");
                    }
                    else
                    {
                        printf("\n >>>>> ERROR AL QUERER CREAR AVISO <<<<<\n");
                    }
                }
                else
                {
                    printf("ES NECESARIO UN ALTA PARA INGRESAR A ESTA OPCION. INTENTE OPCION 1\n");
                }
                break;
            case 5: // PUSAR PUBLICACION
                if(flagAltaCliente == 1 && flagAltaPublicacion == 1)
                {
                    bufferResultado = cliente_publicacion_PausarReanudarPublicacion(pArrayPublicacion, SIZE_ARRAY_PUBLICACION, pArrayCliente, SIZE_ARRAY_CLIENTES, "CONFIRMA QUE DESEA PAUSAR PUBLICACION?", 0);
                    if(bufferResultado == 0)
                    {
                        printf("\n >>>>> PUBLICACION PAUSADA CON EXITO <<<<<\n");
                    }
                    else if(bufferResultado == 1)
                    {
                        printf("\n >>>>> NO SE PAUSO PUBLICACION <<<<<\n");
                    }
                    else
                    {
                        printf("\n >>>>> ERROR AL QUERER PAUSAR PUBLICACION <<<<<\n");
                    }
                }
                else
                {
                    printf("ES NECESARIO UN ALTA DE CLIENTE Y PUBLICACION. INTENTE OPCION 1 Y OPCION 4\n");
                }
                break;
            case 6: // REANUDAR PUBLICACION
                if(flagAltaCliente == 1 && flagAltaPublicacion == 1)
                {
                    bufferResultado = cliente_publicacion_PausarReanudarPublicacion(pArrayPublicacion, SIZE_ARRAY_PUBLICACION, pArrayCliente, SIZE_ARRAY_CLIENTES, "CONFIRMA QUE DESEA REANUDAR PUBLICACION?", 1);
                    if(bufferResultado == 0)
                    {
                        printf("\n >>>>> PUBLICACION REANUDADA CON EXITO <<<<<\n");
                    }
                    else if(bufferResultado == 1)
                    {
                        printf("\n >>>>> NO SE REANUDO PUBLICACION <<<<<\n");
                    }
                    else
                    {
                        printf("\n >>>>> ERROR AL QUERER REANUDAR PUBLICACION <<<<<\n");
                    }
                }
                else
                {
                    printf("ES NECESARIO UN ALTA DE CLIENTE Y PUBLICACION. INTENTE OPCION 1 Y OPCION 4\n");
                }
                break;
            case 7: // IMPRIMIR CLIENTES CON PUBLICACIONES ACTIVAS
                if(flagAltaCliente == 1 && flagAltaPublicacion == 1)
                {
                    if(!(cliente_publicacion_PrintClientesConTotalDeAvisosActivos(pArrayPublicacion, SIZE_ARRAY_PUBLICACION, pArrayCliente, SIZE_ARRAY_CLIENTES)))
                    {
                        printf("\n >>>>> PUBLICACIONES ACTIVAS IMPRESAS CON EXITO <<<<<\n");
                    }
                    else
                    {
                        printf("\n >>>>> ERROR AL QUERER IMPRIMIR PUBLICACIONES ACTIVAS <<<<<\n");
                    }
                }
                else
                {
                    printf("ES NECESARIO UN ALTA DE CLIENTE Y PUBLICACION. INTENTE OPCION 1 Y OPCION 4\n");
                }
                break;
            case 8: // INFORMES
                if(flagAltaCliente == 1 && flagAltaPublicacion == 1)
                {
                    bufferResultado = informes_GenerarInformes(pArrayPublicacion, SIZE_ARRAY_PUBLICACION, pArrayCliente, SIZE_ARRAY_CLIENTES, ruArray, SIZE_ARRAY_RUBROS);
                    if(bufferResultado == 0)
                    {
                        printf("\n >>>>> INFORME GENERADO CON EXITO <<<<<\n");
                    }
                    else if(bufferResultado == 1)
                    {
                        printf("\n >>>>> NO SE GENERA NINGUN INFORME <<<<<\n");
                    }
                    else
                    {
                        printf("\n >>>>> ERROR AL QUERER GENERAR INFORME <<<<<\n");
                    }
                }
                else
                {
                    printf("ES NECESARIO UN ALTA DE CLIENTE Y PUBLICACION. INTENTE OPCION 1 Y OPCION 4\n");
                }
                break;
            case 9: // SALIR
                printf("\n >>>>> HA SALIDO, HASTA LUEGO <<<<<\n");

                break;
            default:
                printf("\n >>>>> OPCION INVALIDA, VUELVA A INTENTAR <<<<<\n");
            }
        }
        else
        {
            printf("\nNO SE HA PODIDO CARGAR EL MENU PRINCIPAL\n");
        }
    } while (bufferOpcionMenuPrincipal != 9);
    return 0;
}


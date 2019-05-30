#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "informes.h"
#include "arraynuevo.h"



/*int informe_instrumentoMasUsadoPorMusico(Musico* pMusicos,int lenMus,Instrumento* pInstrumentos,int lenIns)
{
    int i;
    int contadorCuerdas = 0;
    int contadorPercucion = 0;
    int contadorVientoMetal = 0;
    int contadorVientoMadera = 0;
    int posicionActual;
    int ret = -1;

    if(pMusicos != NULL && pInstrumentos != NULL && lenMus > 0 && lenIns > 0)
    {
        for(i=0;i<lenMus;i++)
        {
            posicionActual = instrumento_findPosID(pInstrumentos,lenIns,pMusicos[i].idInstrumento);
            switch(pInstrumentos[posicionActual].type)
            {
            case 1:
                {
                    contadorCuerdas++;
                    break;
                }
            case 2:
                {
                    contadorPercucion++;
                    break;
                }
            case 3:
                {
                    contadorVientoMetal++;
                    break;
                }
            case 4:
                {
                    contadorVientoMadera++;
                    break;
                }

            }
        }
        if(contadorCuerdas>contadorPercucion && contadorCuerdas>contadorVientoMadera && contadorCuerdas>contadorVientoMetal)
        {
            printf("EL tipo de instrumento mas usado fue el de cuerdas");
            ret = 0;
        }
        if(contadorPercucion>contadorCuerdas && contadorPercucion>contadorVientoMadera && contadorPercucion>contadorVientoMetal)
        {
            printf("EL tipo de instrumento mas usado fue el de percucion");
            ret = 0;
        }
        if(contadorVientoMadera>contadorPercucion && contadorVientoMadera>contadorCuerdas && contadorVientoMadera>contadorVientoMetal)
        {
            printf("EL tipo de instrumento mas usado fue el de viento-madera");
            ret = 0;
        }
        if(contadorVientoMetal>contadorPercucion && contadorVientoMetal>contadorVientoMadera && contadorVientoMetal>contadorCuerdas)
        {
            printf("EL tipo de instrumento mas usado fue el de viento-metal");
            ret = 0;
        }
    }
    return ret;
}

int informe_cantidadTotalPromedioEdadesDeMusico(Musico* pMusicos,int len)
{
    int i;
    int acumulador = 0;
    int contador = 0;
    float promedio;

    if(pMusicos != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if(pMusicos[i].isEmpty == 0)
            {
                acumulador+=pMusicos[i].edad;
                contador++;
            }
        }

    promedio = acumulador / contador;

    printf("\nEl total de musicos es: %d\n",contador);
    printf("La suma de las edades es: %d",acumulador);
    printf("El promedio entre las edades de musicos es: %.2f",promedio);
    }
    return 0;
}*/

int informe_listarOrquestaPorCantidadMusicos(Orquesta* pOrquestas,int lenOrquesta,Musico* pMusicos,int lenMusico)
{
    int i;
    int contadorOrquesta = 0;
    int auxiliarOrquesta = 0;
    int posIdOrquesta;

    musico_sortMusicoIdOrquesta(pMusicos,lenMusico,0);
    if(pOrquestas != NULL && pMusicos != NULL && lenMusico > 0 && lenOrquesta > 0)
    {
        for(i=0;i<lenMusico;i++)
        {
            if(pMusicos[i].isEmpty == 0)
            {
                posIdOrquesta = orquesta_findPosID(pOrquestas,lenOrquesta,pMusicos[i].idOrquesta);
                if(posIdOrquesta != -1)
                {
                    if(posIdOrquesta == auxiliarOrquesta)
                    {
                        contadorOrquesta++;
                    }
                    pOrquestas[posIdOrquesta].cantMusicos = contadorOrquesta;
                    auxiliarOrquesta = posIdOrquesta;
                    if(pOrquestas[posIdOrquesta].cantMusicos >= 5)
                    {
                        printf("\nID Orquesta: %d\nNombre: %s\nLugar: %s\n"
                            ,pOrquestas[posIdOrquesta].idOrquesta,pOrquestas[posIdOrquesta].name,
                            pOrquestas[posIdOrquesta].place);
                        orquesta_printTipo(pOrquestas[posIdOrquesta].type);
                        printf("--------\n");
                        break;
                    }
                }
            }

        }
    }
    return 0;
}

int informe_listarMusicosConMasDe30(Orquesta* pOrquestas,int lenOrquesta,
                                    Musico* pMusicos,int lenMusico,
                                    Instrumento* pInstrumentos,int lenInstrumento)
{
    int i;
    int posIdOrquesta;
    int posIdInstrumento;
    for(i=0;i<lenMusico;i++)
    {

        if(pMusicos != NULL && pOrquestas != NULL && pMusicos != NULL &&
            lenMusico > 0 && lenOrquesta > 0 && lenInstrumento > 0)
            {
                posIdOrquesta = orquesta_findPosID(pOrquestas,lenOrquesta,pMusicos[i].idOrquesta);
                posIdInstrumento = instrumento_findPosID(pInstrumentos,lenInstrumento,pMusicos[i].idInstrumento);

                if((posIdOrquesta != -1) && (posIdInstrumento != -1))
                {
                    if(pMusicos[i].edad > 30)
                    {
                        printf("\nID Musico: %d\nNombre: %s\nApellido: %s\nEdad: %d\n"
                                "Nombre Instrumento: %s\nNombre Orquesta: %s\n"
                                ,pMusicos[i].idMusico,pMusicos[i].name,
                                pMusicos[i].surname,pMusicos[i].edad,
                                pInstrumentos[posIdInstrumento].name,pOrquestas[posIdOrquesta].name);
                                break;
                    }
                }
            }
    }
    return 0;
}

int informe_listarOrquestaCompleta(Orquesta* pOrquestas,int lenOrquesta,
                                    Musico* pMusicos,int lenMusico,
                                    Instrumento* pInstrumentos,int lenInstrumento)
{
    int i;
    int j;
    int contadorCuerdas = 0;
    int contadorPercucion = 0;
    int contadorVientoTotal = 0;

    if(pMusicos != NULL && pOrquestas != NULL && pInstrumentos != NULL &&
            lenMusico > 0 && lenOrquesta > 0 && lenInstrumento > 0)
    {
        for(i=0;i<lenOrquesta;i++)
        {
            if(pOrquestas[i].isEmpty == 0)
            {
                for(j=0;j<lenMusico;j++)
                {
                    if((pMusicos[j].isEmpty == 0) && (pOrquestas[i].idOrquesta == pMusicos[j].idOrquesta))
                    {
                        switch(pInstrumentos[pMusicos[j].idInstrumento].type)
                        {
                            case 1:
                            {
                                contadorCuerdas++;
                                break;
                            }
                            case 2:
                            {
                                contadorPercucion++;
                                break;
                            }
                            case 3:
                            {
                                contadorVientoTotal++;
                                break;
                            }
                            case 4:
                            {
                                contadorVientoTotal++;
                                break;
                            }
                        }
                    }
                }
                if(contadorCuerdas >= 5 && contadorPercucion >= 3 && contadorVientoTotal >= 2)
                {
                    printf("\nID Orquesta: %d\nNombre: %s\nLugar: %s\n"
                        ,pOrquestas[i].idOrquesta
                        ,pOrquestas[i].name
                        ,pOrquestas[i].place);
                    orquesta_printTipo(pOrquestas[i].type);
                }
            }
        }
    }
    return 0;
}

int informe_promedioMusicosPorOrquesta(Musico* pMusicos, int lenMusico,Orquesta* pOrquestas,int lenOrquesta, char* msgE, int tries)
{
    int i;
    int j;
    int contadorMusicos = 0;
    float prom;
    int contadorOrquestas = 0;

    if(pMusicos != NULL && pOrquestas != NULL && lenMusico > 0 && lenOrquesta > 0)
    {
        for(i=0;i<lenMusico;i++)
        {
            if(pMusicos[i].isEmpty == 0)
            {
                contadorMusicos++;
            }
            else
            {
                continue;
            }
        }
        for(j=0;j<lenOrquesta;j++)
        {
            if(pOrquestas[j].isEmpty == 0)
            {
                contadorOrquestas++;
            }
            else
            {
                continue;
            }
        }

        prom = (float)contadorMusicos/(float)contadorOrquestas;

        printf("El promedio de musicos es: %.2f\n",prom);
    }
    return 0;
}

int informe_listarMusicosPorTipoDeInstrumento(Musico* pMusicos,int lenMusico,Instrumento* pInstrumentos,int lenInstrumento)
{
    int i;
    int posIdInstrumento;

    musico_bubbleSortEficienteSurname(pMusicos,lenMusico,1);
    if(pMusicos != NULL && pInstrumentos != NULL && lenMusico > 0 && lenInstrumento > 0)
    {
        for(i=0;i<lenMusico;i++)
        {
            posIdInstrumento = instrumento_findPosID(pInstrumentos,lenInstrumento,pMusicos[i].idInstrumento);
            if((pMusicos[i].isEmpty == 0) && (pInstrumentos[posIdInstrumento].type == 1))
            {
                printf("\nNombre: %s\nApellido: %s\nEdad: %d\nNombre Instrumento: %s\n",
                       pMusicos[i].name,pMusicos[i].surname,pMusicos[i].edad,pInstrumentos[posIdInstrumento].name);
                instrumento_printTipo(pInstrumentos[i].type);
                printf("--------\n");
            }
        }
    }
    return 0;
}

int informe_listarOrquestaPorLugar(Orquesta* pOrquestas,int len)
{
    int i;
    int flag = -1;
    char bufferLugar[20];

    printf("\nIngrese el lugar de la orquesta a buscar\n");
    fgets(bufferLugar,20,stdin);
    bufferLugar[strlen(bufferLugar)-1]='\0';

    if(pOrquestas != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if(strcmp(pOrquestas[i].place,bufferLugar)==0)
            {
                printf("\nID Orquesta: %d\nNombre: %s\nLugar: %s\n"
                ,pOrquestas[i].idOrquesta,pOrquestas[i].name,
                pOrquestas[i].place);
                orquesta_printTipo(pOrquestas[i].type);
                printf("--------\n");
                flag = 0;
            }
        }
    if(flag)
        {
            printf("\n\tNo se encontraron valores\t\n");
        }
    }
    return 0;
}

int informe_listarMusicosPorOrquestaDeterminada(Orquesta* pOrquestas,int lenOrquesta,Musico* pMusicos,int lenMusico,Instrumento* pInstrumentos,int lenInstrumento)
{
    int i;
    int flag = -1;
    int auxiliarId;
    int posIdOrquesta;
    int posIdInstrumento;

    printf("\nIngrese el ID de la orquesta a buscar\n");
    scanf("%d",&auxiliarId);

    if(pMusicos != NULL && lenMusico > 0 && pOrquestas != NULL && lenOrquesta > 0 && pInstrumentos != NULL && lenInstrumento > 0)
    {
        for(i=0;i<lenMusico;i++)
        {
            posIdInstrumento = instrumento_findPosID(pInstrumentos,lenInstrumento,pMusicos[i].idInstrumento);
            posIdOrquesta = orquesta_findPosID(pOrquestas,lenOrquesta,pMusicos[i].idOrquesta);

            if((pMusicos[i].isEmpty == 0) && (pOrquestas[posIdOrquesta].idOrquesta == auxiliarId))
            {
                printf("\nNombre: %s\nApellido: %s\nEdad: %d\nNombre instrumento: %s"
                ,pMusicos[i].name,pMusicos[i].surname,pMusicos[i].edad,pInstrumentos[posIdInstrumento].name);
                instrumento_printTipo(pInstrumentos[posIdInstrumento].type);
                printf("--------\n");
                flag = 0;
                break;
            }
        }
    if(flag)
        {
            printf("\n\tNo se encontro orquesta correspondiente\t\n");
        }
    }
    return 0;
}

int informe_listarOrquestaConMasMusicos(Musico* pMusicos,int lenMusico,Orquesta* pOrquestas,int lenOrquesta)
{
    int i;
    int j;
    int contadorMusico = 0;
    int maximoMusicos = 0;

    musico_sortMusicoIdOrquesta(pMusicos,lenMusico,0);
    if(pMusicos != NULL && lenMusico > 0 && pOrquestas != NULL && lenOrquesta > 0)
    {
        for(i=0;i<lenOrquesta;i++)
        {
            if(pOrquestas[i].isEmpty == 0)
            {
                for(j=0;j<lenMusico;j++)
                {
                    if((pMusicos[j].isEmpty == 0) && (pOrquestas[i].idOrquesta == pMusicos[j].idOrquesta))
                    {
                        contadorMusico++;
                    }
                }
                pOrquestas[i].cantMusicos = contadorMusico;
                if(contadorMusico > maximoMusicos)
                {
                    maximoMusicos = contadorMusico;
                    break;
                }
            }
        }
        if((pOrquestas[i].isEmpty == 0) && (pOrquestas[i].cantMusicos == maximoMusicos))
            {
                printf("\nID Orquesta: %d\nNombre: %s\nLugar: %s\nCantidad de musicos: %d\n"
                    ,pOrquestas[i].idOrquesta,pOrquestas[i].name,
                    pOrquestas[i].place,pOrquestas[i].cantMusicos);
                orquesta_printTipo(pOrquestas[i].type);
                printf("--------\n");
            }
    }
    return 0;
}

void informe_crearOrquesta(Orquesta* pOrquestas)
{
    pOrquestas[0].isEmpty = 0;
    pOrquestas[0].idOrquesta = 0;
    pOrquestas[0].type = 1;
    strcpy(pOrquestas[0].name,"nombre a");
    strcpy(pOrquestas[0].place,"lugar a");
}

void informe_crearInstrumento(Instrumento* pInstrumentos)
{
    pInstrumentos[0].isEmpty = 0;
    pInstrumentos[0].idInstrumento = 0;
    pInstrumentos[0].type = 1;
    strcpy(pInstrumentos[0].name,"inst a");

    pInstrumentos[1].isEmpty = 0;
    pInstrumentos[1].idInstrumento = 1;
    pInstrumentos[1].type = 1;
    strcpy(pInstrumentos[1].name,"inst b");

    pInstrumentos[2].isEmpty = 0;
    pInstrumentos[2].idInstrumento = 2;
    pInstrumentos[2].type = 1;
    strcpy(pInstrumentos[2].name,"inst c");

    pInstrumentos[3].isEmpty = 0;
    pInstrumentos[3].idInstrumento = 3;
    pInstrumentos[3].type = 1;
    strcpy(pInstrumentos[3].name,"inst d");

    pInstrumentos[4].isEmpty = 0;
    pInstrumentos[4].idInstrumento = 4;
    pInstrumentos[4].type = 1;
    strcpy(pInstrumentos[4].name,"inst e");

    pInstrumentos[5].isEmpty = 0;
    pInstrumentos[5].idInstrumento = 5;
    pInstrumentos[5].type = 2;
    strcpy(pInstrumentos[5].name,"inst f");

    pInstrumentos[6].isEmpty = 0;
    pInstrumentos[6].idInstrumento = 6;
    pInstrumentos[6].type = 2;
    strcpy(pInstrumentos[6].name,"inst g");

    pInstrumentos[7].isEmpty = 0;
    pInstrumentos[7].idInstrumento = 7;
    pInstrumentos[7].type = 2;
    strcpy(pInstrumentos[7].name,"inst h");

    pInstrumentos[8].isEmpty = 0;
    pInstrumentos[8].idInstrumento = 8;
    pInstrumentos[8].type = 4;
    strcpy(pInstrumentos[8].name,"inst i");

    pInstrumentos[9].isEmpty = 0;
    pInstrumentos[9].idInstrumento = 9;
    pInstrumentos[9].type = 4;
    strcpy(pInstrumentos[9].name,"inst j");
}

void informe_crearMusico(Musico* pMusicos)
{
    pMusicos[0].isEmpty = 0;
    pMusicos[0].idMusico = 0;
    pMusicos[0].edad = 30;
    pMusicos[0].idOrquesta = 0;
    pMusicos[0].idInstrumento = 0;
    strcpy(pMusicos[0].name,"Mus a");
    strcpy(pMusicos[0].surname,"Amus a");


    pMusicos[1].isEmpty = 0;
    pMusicos[1].idMusico = 1;
    pMusicos[1].edad = 20;
    pMusicos[1].idOrquesta = 0;
    pMusicos[1].idInstrumento = 1;
    strcpy(pMusicos[1].name,"Mus b");
    strcpy(pMusicos[1].surname,"Amus b");

    pMusicos[2].isEmpty = 0;
    pMusicos[2].idMusico = 2;
    pMusicos[2].edad = 25;
    pMusicos[2].idOrquesta = 0;
    pMusicos[2].idInstrumento = 2;
    strcpy(pMusicos[2].name,"Mus c");
    strcpy(pMusicos[2].surname,"Amus c");

    pMusicos[3].isEmpty = 0;
    pMusicos[3].idMusico = 3;
    pMusicos[3].edad = 27;
    pMusicos[3].idOrquesta = 0;
    pMusicos[3].idInstrumento = 3;
    strcpy(pMusicos[3].name,"Mus d");
    strcpy(pMusicos[3].surname,"Amus d");

    pMusicos[4].isEmpty = 0;
    pMusicos[4].idMusico = 4;
    pMusicos[4].edad = 22;
    pMusicos[4].idOrquesta = 0;
    pMusicos[4].idInstrumento = 4;
    strcpy(pMusicos[4].name,"Mus e");
    strcpy(pMusicos[4].surname,"Amus e");

    pMusicos[5].isEmpty = 0;
    pMusicos[5].idMusico = 5;
    pMusicos[5].edad = 35;
    pMusicos[5].idOrquesta = 0;
    pMusicos[5].idInstrumento = 5;
    strcpy(pMusicos[5].name,"Mus f");
    strcpy(pMusicos[5].surname,"Amus f");

    pMusicos[6].isEmpty = 0;
    pMusicos[6].idMusico = 6;
    pMusicos[6].edad = 30;
    pMusicos[6].idOrquesta = 0;
    pMusicos[6].idInstrumento = 6;
    strcpy(pMusicos[6].name,"Mus g");
    strcpy(pMusicos[6].surname,"Amus g");

    pMusicos[7].isEmpty = 0;
    pMusicos[7].idMusico = 7;
    pMusicos[7].edad = 30;
    pMusicos[7].idOrquesta = 0;
    pMusicos[7].idInstrumento = 7;
    strcpy(pMusicos[7].name,"Mus h");
    strcpy(pMusicos[7].surname,"Amus h");

    pMusicos[8].isEmpty = 0;
    pMusicos[8].idMusico = 8;
    pMusicos[8].edad = 30;
    pMusicos[8].idOrquesta = 0;
    pMusicos[8].idInstrumento = 8;
    strcpy(pMusicos[8].name,"Mus i");
    strcpy(pMusicos[8].surname,"Amus i");

    pMusicos[9].isEmpty = 0;
    pMusicos[9].idMusico = 9;
    pMusicos[9].edad = 30;
    pMusicos[9].idOrquesta = 0;
    pMusicos[9].idInstrumento = 9;
    strcpy(pMusicos[9].name,"Mus j");
    strcpy(pMusicos[9].surname,"Amus j");
}

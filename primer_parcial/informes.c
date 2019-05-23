#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "arraynuevo.h"
#include "orquesta.h"
#include "musico.h"
#include "instrumento.h"

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
}

int informe_contarCantidadMusicosPorOrquesta(Orquesta* pOrquestas,int lenOrquesta,Musico* pMusicos,int lenMusico)
{
    int i;
    int j;
    int auxiliarCantMusicos;
    for(j=0;j<lenOrquesta;j++)
    {
        auxiliarCantMusicos = 0;
        if(pMusicos != NULL && lenMusico > 0)
        {
            for(i=0;i<lenMusico;i++)
            {
                if(pMusicos[i].idOrquesta == pOrquestas[j].idOrquesta)
                {
                    auxiliarCantMusicos++;
                }
            }
        }
        pOrquestas[j].cantMusicos = auxiliarCantMusicos;
    }
    return 0;
}

int informe_ordenarPorCantidadMusicos(Orquesta* pOrquestas,int lenOrquesta,Musico* pMusicos,int lenMusico,int orden)
{
    int ret = -1;
    int i;
    int j;
    Orquesta buffer;

    if(pOrquestas != NULL && lenOrquesta > 0)
    {
        for(i=0;i<lenOrquesta-1;i++)
        {
            for(j=i+1;j<lenOrquesta;j++)
            {
                if(orden == 0 && pOrquestas[j].cantMusicos < pOrquestas[i].cantMusicos)
                {
                    buffer = pOrquestas[i];
                    pOrquestas[i] = pOrquestas[j];
                    pOrquestas[j] = buffer;
                    ret = 0;
                }
                else if(orden == 1 && pOrquestas[j].cantMusicos > pOrquestas[i].cantMusicos)
                {
                    buffer = pOrquestas[i];
                    pOrquestas[i] = pOrquestas[j];
                    pOrquestas[j] = buffer;
                    ret = 0;
                }
            }
        }
    }
    return ret;
}*/

int musico_sortMusicosSurname(Musico* pMusicos,int len,int order)
{
    int i;
    int j;
    Musico buffer;
    int ret = -1;

    if(pMusicos != NULL && len > 0)
    {
        for(i=0;i<len-1;i++)
        {
            for(j=i+1;j<len;j++)
            {
                if(order == 1 && (strcmp(pMusicos[j].surname,pMusicos[i].surname) < 0))
                {
                    buffer = pMusicos[i];
                    pMusicos[i] = pMusicos[j];
                    pMusicos[j] = buffer;
                    ret = 0;
                }
                else if(order == 0 && (strcmp(pMusicos[j].surname,pMusicos[i].surname) > 0))
                {
                    buffer = pMusicos[i];
                    pMusicos[i] = pMusicos[j];
                    pMusicos[j] = buffer;
                    ret = 0;
                }
            }
        }
    }
    return ret;
}

int informe_listarCantidadMusicosPorOrquesta(Orquesta* pOrquestas,int lenOrquesta,Musico* pMusicos,int lenMusico)
{
    int i;
    int j;
    int auxiliarCantMusicos;
    for(j=0;j<lenOrquesta;j++)
    {
        auxiliarCantMusicos = 0;
        if(pMusicos != NULL && lenMusico > 0)
        {
            for(i=0;i<lenMusico;i++)
            {
                if(pMusicos[i].idOrquesta == pOrquestas[j].idOrquesta)
                {
                    auxiliarCantMusicos++;
                }
            }
        }
        pOrquestas[j].cantMusicos = auxiliarCantMusicos;
    }
    if(pOrquestas[j].cantMusicos > 5)
    {
        printf("\nID Orquesta: %d\nNombre: %s\nLugar: %s\n"
                ,pOrquestas[i].idOrquesta,pOrquestas[i].name,
                pOrquestas[i].place);
        orquesta_printTipo(pOrquestas[i].type);
        printf("--------\n");
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
    int contadorCuerdas = 0;
    int contadorPercucion = 0;
    int contadorVientoTotal = 0;
    int posIdOrquesta;
    int posIdInstrumento;
    int ret = -1;

    if(pMusicos != NULL && pOrquestas != NULL && pInstrumentos != NULL &&
            lenMusico > 0 && lenOrquesta > 0 && lenInstrumento > 0)
    {
        for(i=0;i<lenMusico;i++)
        {
            posIdOrquesta = orquesta_findPosID(pOrquestas,lenOrquesta,pMusicos[i].idOrquesta);
            posIdInstrumento = instrumento_findPosID(pInstrumentos,lenInstrumento,pMusicos[i].idInstrumento);

            if((posIdOrquesta != -1) && (posIdInstrumento != -1))
            {
                switch(pInstrumentos[posIdInstrumento].type)
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
        if(contadorCuerdas >= 5)
        {
            if(contadorPercucion >= 3)
            {
                if(contadorVientoTotal >= 2)
                {
                    printf("\nID Orquesta: %d\nNombre: %s\nLugar: %s\n"
                            ,pOrquestas[posIdOrquesta].idOrquesta
                            ,pOrquestas[posIdOrquesta].name
                            ,pOrquestas[posIdOrquesta].place);
                    orquesta_printTipo(pInstrumentos[posIdOrquesta].type);
                    ret = 0;
                }
            }
        }
    }
    return ret;
}

int informe_promedioMusicosPorOrquesta(Musico* pMusicos, int lenMusico,Orquesta* pOrquestas,int lenOrquesta, char* msgE, int tries)
{
    int i;
    float acumuladorTotal = 0;
    float prom;
    int auxiliarIdMusico;
    int posIdMusico;
    int contador = 0;

    if(pMusicos != NULL && pOrquestas != NULL && lenMusico > 0 && lenOrquesta > 0)
    {
        for(i=0;i<lenOrquesta;i++)
        {
            auxiliarIdMusico = musico_getID(pMusicos,lenMusico,msgE,tries);
            posIdMusico = musico_findPosID(pMusicos,lenMusico,auxiliarIdMusico);
            if(pMusicos[posIdMusico].isEmpty == 0)
            {
                acumuladorTotal += pMusicos[i].idMusico;
                contador++;
            }
        }
        prom = (float)acumuladorTotal/contador;

        printf("El promedio de musicos es: %.2f\n",prom);
    }
    return 0;
}

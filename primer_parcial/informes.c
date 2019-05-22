#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "arraynuevo.h"
#include "orquesta.h"
#include "musico.h"
#include "instrumento.h"

int informe_instrumentoMasUsadoPorMusico(Musico* pMusicos,int lenMus,Instrumento* pInstrumentos,int lenIns)
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

int informe_inicializarContador(int lenContador,int contador[])
{
    int i;
    if(contador != NULL && lenContador > 0)
    {
        for(i=0;i<lenContador;i++)
        {
            contador[i]=0;
        }
    }
    return 0;
}

int informe_contarCantidadMusicosPorOrquesta(Orquesta *arrayOrquesta,int lenOrquesta,Musico *arrayMusico,int lenMusico,int contador[],int lenContador)
{
    informe_inicializarContador(lenContador,contador);
    int i;
    int j;
    for(j=0;j<lenOrquesta;j++)
    {
        if(arrayMusico != NULL && lenMusico > 0)
        {
            for(i=0;i<lenMusico;i++)
            {
                if(arrayMusico[i].idOrquesta == arrayOrquesta[j].idOrquesta)
                {
                    contador[j]++;
                }
            }
        }
    }
    return 0;
}

int informe_ordenarPorCantidadMusicos(Orquesta *arrayOrquesta,int lenOrquesta,Musico *arrayMusico,int lenMusico,int contador[],int lenContador,int orden)
{
    informe_contarCantidadMusicosPorOrquesta(arrayOrquesta,lenOrquesta,arrayMusico,lenMusico,contador,lenContador);
    int ret = -1;
    int i;
    int j;
    Orquesta buffer;

    if(arrayOrquesta != NULL && lenOrquesta > 0)
    {
        for(i=0;i<lenOrquesta-1;i++)
        {
            for(j=i+1;j<lenOrquesta;j++)
            {
                if(orden == 0 && contador[j] < contador[i])
                {
                    buffer = arrayOrquesta[i];
                    arrayOrquesta[i] = arrayOrquesta[j];
                    arrayOrquesta[j] = buffer;
                    ret=0;
                }
                else if(orden == 1 && contador[j] > contador[i])
                {
                    buffer = arrayOrquesta[i];
                    arrayOrquesta[i] = arrayOrquesta[j];
                    arrayOrquesta[j] = buffer;
                    ret=0;
                }
            }
        }
    }
    return ret;
}

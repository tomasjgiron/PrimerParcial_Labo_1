#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraynuevo.h"
#include "orquesta.h"

#define TIPO_SINFO 1
#define TIPO_FILA 2
#define TIPO_CAMARA 3



static int generateID(void);

int orquesta_initArray(Orquesta* pOrquestas, int len)
{
    int i;

    if(pOrquestas != NULL && len > 0)
    {
       for(i=0; i<len;i++)
        {
            pOrquestas[i].isEmpty = 1;
        }
    }
    return 0;
}

int orquesta_addOrquesta(Orquesta* pOrquestas,int len, char* msgE,int tries)
{
    int indexFree;
    char bufferName[50];
    char bufferPlace[50];
    int auxiliarType;
    int ret = -1;

    if(pOrquestas != NULL && len > 0) ///SIEMPRE VALIDAR AL USAR ARRAYS
    {
        indexFree = orquesta_searchFreeSpace(pOrquestas,len);

        if(indexFree >= 0)
        {
            if((getStringLetras(bufferName,"Ingrese nombre: ",msgE,tries) == 0) &&
            (getStringLetras(bufferPlace,"Ingrese lugar: ",msgE,tries) == 0))
            {
                if((getIntInRange(&auxiliarType,"Ingrese tipo (1-Sinfonica|2-Filarmonica|3-Camara): ",
                msgE,1,3,tries) == 0))
                    {
                        strncpy(pOrquestas[indexFree].name,bufferName,sizeof(bufferName));
                        strncpy(pOrquestas[indexFree].place,bufferPlace,sizeof(bufferPlace));
                        pOrquestas[indexFree].type = auxiliarType;
                        pOrquestas[indexFree].isEmpty = 0;
                        pOrquestas[indexFree].idOrquesta = generateID();
                        ret = 0;
                    }
            }
        }
    }
    else
    {
        printf("\n~~~~El ID es invalido~~~~\n");
    }

    return ret;
}

int orquesta_searchFreeSpace(Orquesta* pOrquestas, int len)
{
    int i;
    int ret=-1;

    if(pOrquestas != NULL && len > 0)
    {
       for(i=0;i<len;i++)
        {
            if(pOrquestas[i].isEmpty==1)
            {
                ret = i;
                break;
            }
        }
    }
    return ret;
}

int orquesta_findPosID(Orquesta* pOrquestas, int len,int idOrq)
{
    int i;
    int ret=-1;

    if(pOrquestas != NULL && len > 0)
    {
      for(i = 0;i < len;i++)
        {
            if(pOrquestas[i].idOrquesta == idOrq)
            {
                ret = i;
                break;
            }
        }
    }
    return ret;
}

int orquesta_removeOrquesta(Orquesta* pOrquestas, int len,char* msgE,int tries)
{
    int auxiliarID;
    int posID;
    int ret = -1;

    if(pOrquestas != NULL && len > 0)
    {
       auxiliarID = orquesta_getID(pOrquestas,len,msgE,tries);
       if(auxiliarID >= 0)
       {
            posID = orquesta_findPosID(pOrquestas,len,auxiliarID);
            if(posID != -1)
            {
                pOrquestas[posID].isEmpty = 1;
                ret = 0;
            }
            else
            {
                printf("\n\tID inexistente\t\n");
            }

        }
    }
    return ret;
}

int orquesta_getID(Orquesta* pOrquestas, int len, char* msgE, int tries)
{
    char bufferID[20];
    int auxiliarID;
    int ret = -1;

    if(pOrquestas != NULL && len > 0)
    {
        if(getStringNumerosInt(bufferID,"\nIngrese ID Orquesta: ",msgE,tries) == 0)
        {
            auxiliarID = atoi(bufferID);
            ret = auxiliarID;
        }
    }
    return ret;
}

int orquesta_printOrquesta(Orquesta* pOrquestas,int len)
{
    int i;
    int flag = -1;

    if(pOrquestas != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if(pOrquestas[i].isEmpty == 0)
            {
                printf("\nID Orquesta: %d\nNombre: %s\nLugar: %s"
                "\nTipo (1-Sinfonica|2-Filarmonica|3-Camara): %d\n--------"
                ,pOrquestas[i].idOrquesta,pOrquestas[i].name,
                pOrquestas[i].place,pOrquestas[i].type);
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

int orquesta_printOrquestaID(Orquesta* pOrquestas,int len)
{
    int i;
    int flag = -1;

    if(pOrquestas != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if(pOrquestas[i].isEmpty == 0)
            {
                printf("\nID Orquesta: %d\n--------"
                ,pOrquestas[i].idOrquesta);
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

static int generateID(void)
{
    static int idOrq = 0;
    return idOrq++;
}


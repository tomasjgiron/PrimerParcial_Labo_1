#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraynuevo.h"
#include "instrumento.h"

#define TIPO_CUERDA 1
#define TIPO_VIENTO_MA 2
#define TIPO_VIENTO_ME 3
#define TIPO_PERCUSION 4

static int generateID(void);

int instrumento_initArray(Instrumento* pInstrumentos, int len)
{
    int i;

    if(pInstrumentos != NULL && len > 0)
    {
       for(i=0; i<len;i++)
        {
            pInstrumentos[i].isEmpty = 1;
        }
    }
    return 0;
}

int instrumento_addInstrumento(Instrumento* pInstrumentos,int len, char* msgE,int tries)
{
    int indexFree;
    char bufferName[31];
    int auxiliarType;
    int ret = -1;

    if(pInstrumentos != NULL && len > 0) ///SIEMPRE VALIDAR AL USAR ARRAYS
    {
        indexFree = instrumento_searchFreeSpace(pInstrumentos,len);

        if(indexFree >= 0)
        {
            if((getStringLetras(bufferName,"Ingrese nombre: ",msgE,tries) == 0))
            {
                if((getIntInRange(&auxiliarType,"Ingrese tipo (1-Cuerda|2-Viento Madera|3-Viento Metal|4-Percusion): ",
                msgE,1,4,tries) == 0))
                    {
                        strncpy(pInstrumentos[indexFree].name,bufferName,sizeof(bufferName));
                        pInstrumentos[indexFree].type = auxiliarType;
                        pInstrumentos[indexFree].isEmpty = 0;
                        pInstrumentos[indexFree].idInstrumento = generateID();
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

int instrumento_searchFreeSpace(Instrumento* pInstrumentos, int len)
{
    int i;
    int ret=-1;

    if(pInstrumentos != NULL && len > 0)
    {
       for(i=0;i<len;i++)
        {
            if(pInstrumentos[i].isEmpty==1)
            {
                ret = i;
                break;
            }
        }
    }
    return ret;
}

int instrumento_findPosID(Instrumento* pInstrumentos, int len,int idIns)
{
    int i;
    int ret=-1;

    if(pInstrumentos != NULL && len > 0)
    {
      for(i = 0;i < len;i++)
        {
            if(pInstrumentos[i].idInstrumento == idIns)
            {
                ret = i;
                break;
            }
        }
    }
    return ret;
}

int instrumento_removeInstrumento(Instrumento* pInstrumentos, int len,char* msgE,int tries)
{
    int auxiliarID;
    int posID;
    int ret = -1;

    if(pInstrumentos != NULL && len > 0)
    {
       auxiliarID = instrumento_getID(pInstrumentos,len,msgE,tries);
       if(auxiliarID >= 0)
       {
            posID = instrumento_findPosID(pInstrumentos,len,auxiliarID);
            if(posID != -1)
            {
                pInstrumentos[posID].isEmpty = 1;
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

int instrumento_getID(Instrumento* pInstrumentos, int len, char* msgE, int tries)
{
    char bufferID[20];
    int auxiliarID;
    int ret = -1;

    if(pInstrumentos != NULL && len > 0)
    {
        if(getStringNumerosInt(bufferID,"\nIngrese ID Instrumento: ",msgE,tries) == 0)
        {
            auxiliarID = atoi(bufferID);
            ret = auxiliarID;
        }
    }
    return ret;
}

int instrumento_printInstrumento(Instrumento* pInstrumentos,int len)
{
    int i;
    int flag = -1;

    if(pInstrumentos != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if(pInstrumentos[i].isEmpty == 0)
            {
                printf("\nID Instrumento: %d\nNombre: %s"
                "\nTipo (1-Cuerda|2-Viento Madera|3-Viento Metal|4-Percusion): %d\n--------"
                ,pInstrumentos[i].idInstrumento,pInstrumentos[i].name,
                pInstrumentos[i].type);
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

int instrumento_printInstrumentoID(Instrumento* pInstrumentos,int len)
{
    int i;
    int flag = -1;

    if(pInstrumentos != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if(pInstrumentos[i].isEmpty == 0)
            {
                printf("\nID Instrumento: %d\n--------"
                ,pInstrumentos[i].idInstrumento);
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
    static int idIns = 0;
    return idIns++;
}

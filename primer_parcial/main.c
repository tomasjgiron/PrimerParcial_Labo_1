#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraynuevo.h"
#include "musico.h"
#include "instrumento.h"
#include "orquesta.h"

#define TRIES 3
#define LEN_ORQ 1
#define LEN_INS 1
#define LEN_MUS 1

int main()
{
    Orquesta orquestas[LEN_ORQ];
    Musico musicos[LEN_MUS];
    Instrumento instrumentos[LEN_INS];
    int flagOrquesta = 0;
    int flagMusico = 0;
    int flagInstrumento = 0;
    int contadorOrquesta = 0;
    int contadorMusico = 0;
    int contadorInstrumento = 0;
    int opcion = 0;
    int escape = 10;

        orquesta_initArray(orquestas,LEN_ORQ);
        musico_initArray(musicos,LEN_MUS);
        instrumento_initArray(instrumentos,LEN_INS);
        while(opcion!=escape)
        {
            printf("\n1.ALTA ORQUESTA\n2.BAJA ORQUESTA\n3.IMPRIMIR ORQUESTAS\n~~~"
                    "\n4.ALTA MUSICO\n5.MODIFICAR MUSICO\n6.BAJA MUSICO\n7.IMPRIMIR MUSICOS\n~~~"
                    "\n8.ALTA INSTRUMENTO\n9.IMPRIMIR INSTRUMENTOS\n10.SALIR\n");

            getIntInRange(&opcion,"\nIngrese opcion: ",
                          "Informacion invalida\n",1,escape,TRIES);

            switch(opcion)
            {
                case 1:
                {
                    if(orquesta_addOrquesta(orquestas,LEN_ORQ,"Informacion invalida",TRIES) == 0)
                       {
                           flagOrquesta = 1;
                           contadorOrquesta++;
                           orquesta_printOrquestaID(orquestas,LEN_ORQ);
                       }
                    break;
                }
                case 2:
                {
                    if(flagOrquesta)
                    {
                        orquesta_printOrquesta(orquestas,LEN_ORQ);
                        if(orquesta_removeOrquesta(orquestas,LEN_ORQ,"Informacion invalida",TRIES) == 0)
                        {
                            contadorOrquesta--;
                            if(contadorOrquesta == 0)
                            {
                                flagOrquesta = 0;
                            }
                        }
                    }
                    else
                    {
                        printf("\n\tNo hay orquestas para mostrar\t\n");
                    }
                    break;
                }
                case 3:
                {
                    if(flagOrquesta)
                    {
                        orquesta_printOrquesta(orquestas,LEN_ORQ);
                    }
                    else
                    {
                        printf("\n\tNo hay orquestas para mostrar\t\n");
                    }
                    break;
                }
                case 4:
                {
                    if(flagOrquesta)
                    {
                        musico_addMusico(musicos,LEN_MUS,
                         orquestas,LEN_ORQ,
                         instrumentos,LEN_INS,
                         "Informacion invalida",TRIES);
                         flagMusico = 1;
                         contadorMusico++;
                    }
                    else
                    {
                        printf("\n\tNo hay orquestas para mostrar\t\n");
                    }
                    break;
                }
                case 5:
                {
                    if(flagMusico)
                    {
                        musico_printMusico(musicos,instrumentos,LEN_MUS,LEN_INS)
                        musico_modifyMusico(musicos,LEN_MUS,orquestas,LEN_ORQ,"Informacion invalida",3,TRIES);

                    }
                    else
                    {
                        printf("\n\tNo hay musicos para mostrar\t\n");
                    }
                    break;
                }
                case 6:
                {
                    if(flagMusico)
                    {
                        musico_printMusico(musicos,LEN_MUS);
                        if(musico_removeMusico(musicos,LEN_MUS,"Informacion invalida",TRIES))
                        {
                            contadorMusico--;
                            if(contadorMusico == 0)
                            {
                                flagMusico = 0;
                            }
                        }
                    }
                    else
                    {
                        printf("\n\tNo hay musicos para mostrar\t\n");
                    }
                    break;
                }
                case 7:
                {
                    if(flagMusico)
                    {
                        if(libro_removeLibro(musicos,LEN_MUS,"informacion invalida",TRIES) == 0)
                        {

                        }
                    }
                    else
                    {
                        printf("\n\tNo hay musicos para mostrar\t\n");
                    }
                    break;
                }
                case 8:
                {
                    if(flagMusico)
                    {
                        libro_sortLibroTitulo(musicos,LEN_MUS);
                        libro_printLibro(musicos,orquestas,LEN_ORQ,LEN_MUS);
                    }
                    else
                    {
                        printf("\n\tNo hay musicos para mostrar\t\n");
                    }
                    break;
                }
                case 9:
                {
                    if(socio_addSocio(instrumentos,LEN_INS,"informacion invalida",TRIES) == 0)
                    {
                        flagInstrumento = 1;
                        contadorInstrumento++;
                    }
                    break;
                }
                case 10:
                {
                    if(flagInstrumento)
                    {
                        socio_printSocio(instrumentos,LEN_INS);
                        socio_modifySocio(instrumentos,LEN_INS,"informacion invalida",3,TRIES);
                    }
                    else
                    {
                        printf("\n\tNo hay instrumentos para mostrar\t\n");
                    }
                    break;
                }
                case 11:
                {
                    if(flagInstrumento)
                    {
                        if(socio_removeSocio(instrumentos,LEN_INS,"informacion invalida",TRIES) == 0)
                        {
                            contadorInstrumento--;
                            if(contadorInstrumento == 0)
                            {
                                flagInstrumento = 0;
                            }
                        }
                    }
                    else
                    {
                        printf("\n\tNo hay instrumentos para mostrar\t\n");
                    }
                    break;
                }
                case 12:
                {
                    if(flagInstrumento)
                    {
                        socio_sortSocioSurnameName(instrumentos,LEN_INS,1);
                        socio_printSocio(instrumentos,LEN_INS);
                    }
                    else
                    {
                        printf("\n\tNo hay instrumentos para mostrar\t\n");
                    }
                    break;
                }
            }
        }
    return 0;
}

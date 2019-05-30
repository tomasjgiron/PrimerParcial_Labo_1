#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraynuevo.h"
#include "musico.h"
#include "instrumento.h"
#include "orquesta.h"
#include "informes.h"

#define TRIES 3
#define LEN_ORQ 50
#define LEN_INS 20
#define LEN_MUS 1000

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
    int opcionPrimaria = 0;
    int opcionSecundaria = 0;
    int escapePrimario = 11;
    int escapeSecundario = 9;
    int auxiliarIdBorrado;
    int auxiliarIdAltaOrquesta;
    int auxiliarIdAltaInstrumento;


        orquesta_initArray(orquestas,LEN_ORQ);
        musico_initArray(musicos,LEN_MUS);
        instrumento_initArray(instrumentos,LEN_INS);

        informe_crearOrquesta(orquestas);
        informe_crearInstrumento(instrumentos);
        informe_crearMusico(musicos);

        while(opcionPrimaria!=escapePrimario)
        {
            printf("\n1.ALTA ORQUESTA\n2.BAJA ORQUESTA\n3.IMPRIMIR ORQUESTAS\n~~~"
                    "\n4.ALTA MUSICO\n5.MODIFICAR MUSICO\n6.BAJA MUSICO\n7.IMPRIMIR MUSICOS\n~~~"
                    "\n8.ALTA INSTRUMENTO\n9.IMPRIMIR INSTRUMENTOS\n10.INFORMES\n11.SALIR\n");

            getIntInRange(&opcionPrimaria,"\nIngrese opcion: ",
                          "Informacion invalida\n",1,escapePrimario,TRIES);

            switch(opcionPrimaria)
            {
                case 1:
                {
                    if(orquesta_addOrquesta(orquestas,LEN_ORQ,&auxiliarIdAltaOrquesta,"Informacion invalida",TRIES) == 0)
                       {
                           flagOrquesta = 1;
                           contadorOrquesta++;
                           orquesta_printValorRepetidoInt(orquestas,LEN_ORQ,auxiliarIdAltaOrquesta);
                       }
                    break;
                }
                case 2:
                {
                    if(flagOrquesta)
                    {
                        orquesta_printOrquesta(orquestas,LEN_ORQ);
                        if(orquesta_removeOrquesta(orquestas,LEN_ORQ,&auxiliarIdBorrado,"Informacion invalida",TRIES) == 0)
                        {
                            contadorOrquesta--;
                            musico_bajaValorRepetidoInt(musicos,LEN_MUS,auxiliarIdBorrado);
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
                    //if(flagOrquesta)
                    {
                        orquesta_printOrquesta(orquestas,LEN_ORQ);

                    }
                    //else
                    {
                        //printf("\n\tNo hay orquestas para mostrar\t\n");
                    }
                    break;
                }
                case 4:
                {
                    if(flagOrquesta && flagInstrumento)
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
                        printf("\n\tNo hay orquestas y/o instrumentos para mostrar\t\n");
                    }
                    break;
                }
                case 5:
                {
                    if(flagMusico)
                    {
                        musico_printMusico(musicos,instrumentos,LEN_MUS,LEN_INS);
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
                        musico_printMusico(musicos,instrumentos,LEN_MUS,LEN_INS);
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
                    //if(flagMusico)
                    {
                        musico_printMusico(musicos,instrumentos,LEN_MUS,LEN_INS);
                    }
                    //else
                    {
                        //printf("\n\tNo hay musicos para mostrar\t\n");
                    }
                    break;
                }
                case 8:
                {
                    if(flagOrquesta)
                    {
                        if(instrumento_addInstrumento(instrumentos,LEN_INS,&auxiliarIdAltaInstrumento,"Informacion invalida",TRIES) == 0)
                       {
                           flagInstrumento = 1;
                           instrumento_printValorRepetidoInt(instrumentos,LEN_INS,auxiliarIdAltaInstrumento);
                       }
                    }
                    else
                    {
                        printf("\n\tNo hay orquestas para mostrar\t\n");
                    }
                    break;
                }
                case 9:
                {
                    //if(flagInstrumento)
                    {
                        instrumento_printInstrumento(instrumentos,LEN_INS);
                    }
                    //else
                    {
                        //printf("\n\tNo hay instrumentos para mostrar\t\n");
                    }
                    break;
                }
                case 10:
                {
                    printf("\n1.Listar orquesta +5 musicos\n2.Listar musicos +30 edad\n3.Listar orquesta lugar predeterminado\n~~~"
                    "\n4.Listar orquesta completa\n5.Listar musicos de determinada orquesta\n6.Listar orquesta con + musicos\n~~~"
                    "\n7.Listar musicos con instrumento de cuerdas\n8.Promedio de musicos por orquesta\n9.SALIR\n");

                    getIntInRange(&opcionSecundaria,"Ingrese opcion: ","Informacion invalida",1,escapeSecundario,TRIES);
                    switch(opcionSecundaria)
                    {
                    case 1:
                        {
                            informe_listarOrquestaPorCantidadMusicos(orquestas,LEN_ORQ,musicos,LEN_MUS);///funciona
                            break;
                        }
                    case 2:
                        {
                            informe_listarMusicosConMasDe30(orquestas,LEN_ORQ,musicos,LEN_MUS,instrumentos,LEN_INS);///funciona
                            break;
                        }
                    case 3:
                        {
                            informe_listarOrquestaPorLugar(orquestas,LEN_ORQ);///funciona
                            break;
                        }
                    case 4:
                        {
                            informe_listarOrquestaCompleta(orquestas,LEN_ORQ,musicos,LEN_MUS,instrumentos,LEN_INS); /// FUNCIONA
                            break;
                        }
                    case 5:
                        {
                            informe_listarMusicosPorOrquestaDeterminada(orquestas,LEN_ORQ,musicos,LEN_MUS,instrumentos,LEN_INS);///funciona
                            break;
                        }
                    case 6:
                        {
                            informe_listarOrquestaConMasMusicos(musicos,LEN_MUS,orquestas,LEN_ORQ);/// muestra basura en la cantidad de musicos
                            break;
                        }
                    case 7:
                        {
                            informe_listarMusicosPorTipoDeInstrumento(musicos,LEN_MUS,instrumentos,LEN_INS);///funciona
                            break;
                        }
                    case 8:
                        {
                            informe_promedioMusicosPorOrquesta(musicos,LEN_MUS,orquestas,LEN_ORQ,"Informacion invalida",TRIES);///funciona
                            break;
                        }
                    }
                }
            }
            fflush(stdin);
        }
    return 0;
}

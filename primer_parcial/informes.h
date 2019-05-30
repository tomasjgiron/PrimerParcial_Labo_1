#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED
#include "orquesta.h"
#include "musico.h"
#include "instrumento.h"

//int informe_instrumentoMasUsadoPorMusico(Musico* pMusicos,int lenMus,Instrumento* pInstrumentos,int lenIns);

//int informe_cantidadTotalPromedioEdadesDeMusico(Musico* pMusicos,int len);

int informe_listarOrquestaPorCantidadMusicos(Orquesta* pOrquestas,int lenOrquesta,Musico* pMusicos,int lenMusico);

int informe_listarMusicosConMasDe30(Orquesta* pOrquestas,int lenOrquesta,
                                    Musico* pMusicos,int lenMusico,
                                    Instrumento* pInstrumentos,int lenInstrumento);

int informe_listarOrquestaCompleta(Orquesta* pOrquestas,int lenOrquesta,
                                    Musico* pMusicos,int lenMusico,
                                    Instrumento* pInstrumentos,int lenInstrumento);

int informe_promedioMusicosPorOrquesta(Musico* pMusicos, int lenMusico,Orquesta* pOrquestas,int lenOrquesta, char* msgE, int tries);

int informe_listarMusicosPorTipoDeInstrumento(Musico* pMusicos,int lenMusico,Instrumento* pInstrumentos,int lenInstrumento);

int informe_listarOrquestaPorLugar(Orquesta* pOrquestas,int len);

int informe_listarMusicosPorOrquestaDeterminada(Orquesta* pOrquestas,int lenOrquesta,Musico* pMusicos,int lenMusico,Instrumento* pInstrumentos,int lenInstrumento);

int informe_listarOrquestaConMasMusicos(Musico* pMusicos,int lenMusico,Orquesta* pOrquesta,int lenOrquesta);

void informe_crearOrquesta(Orquesta* pOrquestas);

void informe_crearInstrumento(Instrumento* pInstrumentos);

void informe_crearMusico(Musico* pMusicos);

#endif // INFORMES_H_INCLUDED

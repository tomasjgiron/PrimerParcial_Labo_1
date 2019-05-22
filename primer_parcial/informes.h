#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

int informe_instrumentoMasUsadoPorMusico(Musico* pMusicos,int lenMus,Instrumento* pInstrumentos,int lenIns)

int informe_cantidadTotalPromedioEdadesDeMusico(Musico* pMusicos,int len);

int informe_inicializarContador(int lenContador,int contador[]);

int informe_contarCantidadMusicosPorOrquesta(Orquesta *arrayOrquesta,int lenOrquesta,Musico *arrayMusico,int lenMusico,int contador[],int lenContador);

int informe_ordenarPorCantidadMusicos(Orquesta *arrayOrquesta,int lenOrquesta,Musico *arrayMusico,int lenMusico,int contador[],int lenContador,int orden);

#endif // INFORMES_H_INCLUDED

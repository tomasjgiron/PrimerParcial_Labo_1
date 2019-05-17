#ifndef ORQUESTA_H_INCLUDED
#define ORQUESTA_H_INCLUDED

typedef struct
{
    int idOrquesta; /// se va autoincrementando
    char name[50];
    char place[50];
    int type;
    int isEmpty; /// lleno=0 ; vacio=1
}Orquesta;

//int orquesta_menu(Orquesta* pOrquestas,int len,char* textMenu,char* msgE,int escape,int tries);

int orquesta_initArray(Orquesta* pOrquestas, int len);

int orquesta_addOrquesta(Orquesta* pOrquestas,int len, char* msgE,int tries);

int orquesta_removeOrquesta(Orquesta* pOrquestas, int len,char* msgE,int tries);

int orquesta_printOrquesta(Orquesta* pOrquestas,int len);

int orquesta_printOrquestaID(Orquesta* pOrquestas,int len);

int orquesta_sortOrquestaSurnameName(Orquesta* pOrquestas,int len,int order);

//int orquesta_printTotalPromAboveSalary(Orquesta* pOrquestas, int len);

int orquesta_modifyOrquesta(Orquesta* pOrquestas,int len,char* msgE,int escape,int tries);


int orquesta_searchFreeSpace(Orquesta* pOrquestas, int len);

int orquesta_findPosID(Orquesta* pOrquestas, int len,int idOrq);

int orquesta_getID(Orquesta* pOrquestas, int len, char* msgE, int tries);

//int orquesta_aboveSalary(Orquesta* pOrquestas, int len, float prom);


#endif // ORQUESTA_H_INCLUDED

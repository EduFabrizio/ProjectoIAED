#ifndef HEADER1
#define HEADER1
#define MAXESTACIONAMENTOS 20
#define TRUE 1
#define FALSE 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct carro{
    char matricula1[2], matricula2[2], matricula3[2];
    int diaIn, mesIn, anoIn, horaIn, minutoIn, diaOut, mesOut, anoOut, horaOut, minutoOut, dentro;
    struct carro *next;
    struct carro *previous;
}Carro;


typedef struct estacionamento{
    char *nomeEst;
    int capacidade, lotAtual;
    float  valor15, valor15Apos1Hora, valorMaxDia;
    struct carro *Carros;
} Estacionamento;

typedef struct lstEst{
    struct lstEst *next;
    struct lstEst *previous;
    struct estacionamento *estacionamento;
} LstEst;

extern LstEst* listaEst;//declarando uma linked list de estacionamentos como variavel global



#endif 
#include "header1 - cópia.h"
#include "header2 - cópia.h"

LstEst* listaEst = NULL;

int verificaNome(char *nomeEst){//funçao auxiliar que verifica se o nome atribuido ao estacionamento ja existe
    LstEst* membroAtual = listaEst;
    while(membroAtual!=NULL){
        if(strcmp(membroAtual->estacionamento->nomeEst, nomeEst)==0){
            return TRUE;
        }
        membroAtual= membroAtual->next;
    }
    return FALSE;
}

int lstLenght(LstEst* listaEst){//funçao auxiliar que verifica o tamanho da linked list
    int i;
    LstEst* membroAtual = listaEst;
    for(i=0; membroAtual!=NULL; i++){
        membroAtual=membroAtual->next;
    }

    return i;
}

void criaParque(char str[BUFSIZ]){ //cria um parque de estacionamento e o adiciona na linked list
    char *nomeEst = (char*)malloc(BUFSIZ*sizeof(char));
    int capacidade;
    float valor15, valor15Apos1Hora, valorMaxDia;
    Estacionamento* novoEst = (Estacionamento*)malloc(sizeof(Estacionamento));
    if( sscanf(str, "%*c \"%[^\"]\" %d %f %f %f", nomeEst, &capacidade, &valor15, &valor15Apos1Hora, &valorMaxDia)!=5){
        sscanf(str, "%*c %s %d %f %f %f", nomeEst, &capacidade, &valor15, &valor15Apos1Hora, &valorMaxDia);
    }
    if(verificaNome(nomeEst)==1){
        printf("%s: parking already exists\n", nomeEst);
        free(nomeEst);
        return;
    }
    if(capacidade<=0){
        printf("%d: invalid capacity\n", capacidade);
        free(nomeEst);
        return;
    }
    if(valor15<=0.0 || valor15>=valor15Apos1Hora || valor15Apos1Hora>= valorMaxDia){
        printf("invalid cost\n");
        free(nomeEst);
        return;
    }
    if(lstLenght(listaEst)>=19){
        printf("too many parks\n");
        free(nomeEst);
        return;
    }
    strcpy(novoEst->nomeEst, nomeEst);
    free(nomeEst);
    novoEst->capacidade = capacidade;
    novoEst->valor15 = valor15;
    novoEst->valor15Apos1Hora = valor15Apos1Hora;
    novoEst->valorMaxDia = valorMaxDia;
    novoEst->lotAtual = 0;

    LstEst* novoMembro = (LstEst*)malloc(sizeof(LstEst));
    novoMembro->estacionamento = novoEst;
    novoMembro->next = NULL;

    LstEst* membroAtual = listaEst;
    if(membroAtual!= NULL){
        while (membroAtual->next!=NULL)
        {
            membroAtual = membroAtual->next;
        }
        membroAtual->next = novoMembro;
        novoMembro->previous = membroAtual;
    } else{
        listaEst = novoMembro;
        novoMembro->previous = NULL;
    }
}

void listaParque(){//lista os estacionamentos ja existentes na lista
    LstEst* membroAtual = listaEst;
    while(membroAtual!=NULL){
        printf("%s %d %d\n", membroAtual->estacionamento->nomeEst, membroAtual->estacionamento->capacidade,
         (membroAtual->estacionamento->capacidade - membroAtual->estacionamento->lotAtual));
        membroAtual=membroAtual->next;
    }
}
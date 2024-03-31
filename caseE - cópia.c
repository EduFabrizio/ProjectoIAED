#include "header1 - cópia.h"
#include "header2 - cópia.h"
/*

Estacionamento* buscaEst(char *nomeEst){
    LstEst *membroAtual = listaEst;
    while(membroAtual!=NULL){
        if(strcmp(membroAtual->estacionamento->nomeEst, nomeEst)==0){
                return (membroAtual->estacionamento);
            }
}
}

int validarMatricula(const char *par){
    if(isdigit(par[0]) && isdigit(par[1])){
        return TRUE;
    }
    else if(isupper(par[0]) && isupper(par[1])){
        return TRUE;
    }
    else {
        return FALSE;
    }
}


int checaPares(const char *par1, const char *par2, const char *par3){
    int contNum = 0; int contLet = 0;
    int i;
    const char* pares[3] = {par1, par2, par3};
    for(i=0; i<3; i++){
        if(validarMatricula(pares[i])){
            if(isdigit(pares[i][0])){
                contNum++;
            }
            else{
                contLet++;
            }
        }
        else {
            return FALSE;
        }
    }
    return (contLet>=1 && contNum>=1) ? TRUE : FALSE;
}


Carro* criaCarro(char Matricula1[2], char Matricula2[2], char Matricula3[2],
 int dia, int mes, int ano, int hora, int minuto, char *nomeEst){
    Carro* novoCarro = (Carro*)malloc(sizeof(Carro));
    memcpy(novoCarro-> matricula1, Matricula1, 2);
    memcpy(novoCarro-> matricula2, Matricula2, 2);
    memcpy(novoCarro-> matricula3, Matricula3, 2);
    novoCarro->diaIn = dia;
    novoCarro->mesIn = mes;
    novoCarro->anoIn = ano;
    novoCarro->horaIn = hora;
    novoCarro->minutoIn = minuto;
    novoCarro-> next = NULL;

    Estacionamento *estacionamento = buscaEst(nomeEst);
    if (estacionamento->Carros != NULL) {
        Carro *ultimoCarro = estacionamento->Carros;
        while (ultimoCarro->next != NULL) {
            ultimoCarro = ultimoCarro->next;
        }

        // Verificar se a data e hora do novo carro são posteriores ao último carro
        if ((ano < ultimoCarro->anoIn) ||
            (ano == ultimoCarro->anoIn && mes < ultimoCarro->mesIn) ||
            (ano == ultimoCarro->anoIn && mes == ultimoCarro->mesIn && dia < ultimoCarro->diaIn) ||
            (ano == ultimoCarro->anoIn && mes == ultimoCarro->mesIn && dia == ultimoCarro->diaIn &&
             hora < ultimoCarro->horaIn) ||
            (ano == ultimoCarro->anoIn && mes == ultimoCarro->mesIn && dia == ultimoCarro->diaIn &&
             hora == ultimoCarro->horaIn && minuto <= ultimoCarro->minutoIn)) {
            printf("Data/hora de entrada não podem ser anteriores ao último carro estacionado.\n");
            free(novoCarro);
            return NULL;
        }
    }

    // Adicionar o novo carro à lista de carros do estacionamento
    if (!estacionamento->Carros) {
        estacionamento->Carros = novoCarro;
    } else {
        Carro *temp = estacionamento->Carros;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = novoCarro;
    }


    return novoCarro;
}


void entraParque(char str[BUFSIZ]){
    char *nomeEst, *matricula1, *matricula2, *matricula3;
    int i, dia, mes, ano, hora, minuto;
    nomeEst = (char*)malloc(BUFSIZ*sizeof(char));
    matricula1 = (char*)malloc(2*sizeof(char)); 
    matricula2 = (char*)malloc(2*sizeof(char));
    matricula3 = (char*)malloc(2*sizeof(char)); 
    if(i=sscanf(str,"%*c \"%[^\"]\"  %2s-%2s-%2s %2d-%2d-%4d %2d:%2d",
     nomeEst, matricula1, matricula2, matricula3, &dia, &mes, &ano, &hora, &minuto)!=9){
        i = sscanf(str, "%*c %s %2s-%2s-%2s %2d-%2d-%4d %2d:%2d",
        nomeEst, matricula1, matricula2, matricula3, &dia, &mes, &ano, &hora, &minuto );
    }   
    if(i!=9){
        printf("ERROS no E");
        free(nomeEst);
        free(matricula1);
        free(matricula2);
        free(matricula3);
    }
    if(!(verificaNome(nomeEst))){
        printf("%s: no such parking.\n", nomeEst);
        free(nomeEst);
        free(matricula1);
        free(matricula2);
        free(matricula3);
    }
    if(buscaEst(nomeEst)->lotAtual==buscaEst(nomeEst)->capacidade){
        printf("%s: parking is full\n", nomeEst);
        free(nomeEst);
        free(matricula1);
        free(matricula2);
        free(matricula3);
    }
    if(!(checaPares(matricula1, matricula2, matricula3))){
        printf("%s-%s-%s: invalid license plate", matricula1, matricula2, matricula3);
        free(nomeEst);
        free(matricula1);
        free(matricula2);
        free(matricula3);
    }
    Carro* novoCarro = criaCarro(matricula1, matricula2, matricula3,
     dia, mes, ano, hora, minuto, nomeEst);
    (buscaEst(nomeEst)->lotAtual)++; //incrementa o parametro da lotaçao no estacionamento
    printf("%s %d\n", nomeEst, (buscaEst(nomeEst)->capacidade - buscaEst(nomeEst)->lotAtual));

}
*/
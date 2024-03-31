/* iaed24 - ist1107278 - project */
#include <stdio.h>
#include <stdlib.h>
#include "header1.h"
#include "header2.h"
int main(){
    char str[BUFSIZ];
    fgets(str, BUFSIZ, stdin);
    char comando = str[0];
    switch(comando){
        case 'q':
            printf("voce selecionou q\n");
            return 0;
            break;
        case 'p':
            if(strlen(str)==2){
                printf("voce slecionou z\n");
                listaParque();
            }
            else{
            printf("voce slecionou p com argumentos\n");
            criaParque(str);
            }
            break;
        case 'e':
            printf("voce selecionou e\n");
            break;
        case 's':
            printf("voce selecionou s\n");
            break;
        case 'v':
            printf("voce selecionou v\n");
            break;
        case 'f':
            printf("voce selecionou f\n");
            break;
        case 'r':
            printf("voce selecionou r\n");
            break;
        default:
            printf("ma que cazzo fae\n");
    }
    return 0;
}
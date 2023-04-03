#include <stdio.h>
#include <stdlib.h>
#define MAXTAM 100

typedef struct{
    int item[MAXTAM];
    int topo;
    int t;
}Tpilha;


void iniciaPilha (Tpilha *p){
    (*p).topo = -1;
    (*p).t = 0;
}

int pilhaVazia(Tpilha *p){
    if((*p).topo == -1){
        return 1;
    } else {
        return 0;
    }
}
int pilhaCheia (Tpilha *p){
    if((*p).topo == MAXTAM-1){
        return 1;
    } else {
        return 0;
    }
}
void inserePilha(Tpilha *p, int x){
    if(pilhaCheia(p) == 1){
        printf("ERRO: A pilha ja esta cheia. ");
    } else {
        (*p).topo++;
        (*p).item[(*p).topo] = x;
        (*p).t++;
    }
}

void removePilha(Tpilha *p){

    if(pilhaVazia(p)== 1){
        printf("ERRO! A pilha está vazia");
    } else {
        (*p).topo--;
        (*p).t--;
    }}

int elementosNaPilha(Tpilha *p){
    return (*p).t + 1;
}
void exibirPilha(Tpilha *p){
    int i,M;
    M = elementosNaPilha(p);
    printf("\nPILHA PREENCHIDA: \n");
    for(i=0;i<M-1;i++){
        printf(" [%d] ",(*p).item[i]);
    }
    printf("\n");
}
int main()
{
    int valor,opcao;
    Tpilha *p = (Tpilha*)malloc(sizeof(Tpilha));

    iniciaPilha(p);
    printf("---- Programa pilha ----\n");
    while(opcao != 0){
            printf("\n1- inserir numero na pilha \n");
            printf("2- remover numero na pilha \n");
            printf("3- Exibir pilha\n");
            printf("0- Encerrar o programa \n");
            scanf("%d",&opcao);
        switch(opcao){
        case 1:
            printf("\nDigite um valor a ser inserido na pilha: ");
            scanf("%d",&valor);
            inserePilha(p,valor);
            break;
        case 2:
            removePilha(p);
            break;

        case 3:
            exibirPilha(p);
            break;
    }
}

    return 0;
}

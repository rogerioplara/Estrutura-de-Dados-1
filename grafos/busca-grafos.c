#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//numero maximo de vertices
#define MAXV 8

//estrutura de um no
typedef struct str_no{
    int id;
    struct str_no *proximo;
}str_no;

//grafo
struct str_no grafo[MAXV];

//funcao de busca em profundidade DFS
void buscaEmProfundidade(struct str_no g[], int inicio, int alvo){
    int pilha[MAXV]; //pilha
    bool visitado[MAXV]; //nos visitados
    int indice = 0; //indice do topo da pilha
    bool achou = false; //flag de controle (nao visitados)
    int corrente = inicio;
    struct str_no *ptr;
    int i;
    printf("=-=-=-= Busca em Profundidade =-=-=-=\n");
    //marcando os nos como nao visitados
    for(i=0; i<MAXV; i++){
        visitado[i] = false;
    }
    while(true){
        //no corrente nao visitado? marque como visitado
        //empilha o no corrente
        if(!visitado[corrente]){
            printf("VISITANDO: %d. \n", corrente);
            if(corrente == alvo){
                printf("Alvo encontrado!\n\n\n");
                return;
            }
        }
        //buscando por nós adjacentes, não visitados
        achou = false;
        for(ptr=g[corrente].proximo; ptr!=NULL; ptr=ptr->proximo){
            if(!visitado[ptr->id]){
                achou = true;
                break;
            }
        }
        if(achou){
            //atualizando o no corrente
            corrente = ptr->id;
        } else {
            //nao ha vertices adjacentes nao visitados
            //tentando desempilhar o vertice do topo
            indice--;
            if(indice==-1){
                //nao ha mais vertices nao visitados
                printf("Encerrando a busca. \n");
                break;
            }
            corrente=pilha[indice-1];
        }
    }
    return;
}

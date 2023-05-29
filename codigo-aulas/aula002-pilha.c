#include <stdio.h>
#include <stdlib.h>

#define tamanho 3

struct tipo_pilha {
    int dados[tamanho];
    int ini;
    int topo;
};

struct tipo_pilha pilha;

// a cada chamada da funcao, empilha o novo elemento na ultima posicao (push);
void empilha(int elemento){
    if(pilha.topo==tamanho){
        printf("Fila cheia.\n");
        system("pause");
    } else {
        pilha.dados[pilha.topo] = elemento;
        printf("Empilhado (%d).\n", elemento);
        pilha.topo++;
    }
}

// a cada chamada da funcao, desempilha o ultimo elemento na ultima posicao e retorna (pop);
int desempilha(){
    int elemento;
    if(pilha.topo==pilha.ini){
        printf("Fila vazia.\n");
        system("pause");
    } else {
        pilha.topo--;
        elemento = pilha.dados[pilha.topo];
        printf("Desempilhando (%d).\n", elemento);
        return elemento;
    }
}

int main(){
    empilha(10);
    empilha(20);

    for(int i=0; i<tamanho; i++){
        printf("[%d] = [%d].\n", i, pilha.dados[i]);
    }
    system("pause");

    printf("\n");
    empilha(30);
    empilha(40);

    for(int i=0; i<tamanho; i++){
        printf("[%d] = [%d].\n", i, pilha.dados[i]);
    }
    system("pause");

    desempilha();
    desempilha();
    printf("\n");

    empilha(5);
    empilha(6);
    for(int i=0; i<tamanho; i++){
        printf("[%d] = [%d].\n", i, pilha.dados[i]);
    }
    system("pause");
}




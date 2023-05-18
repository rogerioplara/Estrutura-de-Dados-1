#include <stdio.h>
#include <stdlib.h>

//Estrutura NÓ
typedef struct NO {
    int dado;
    struct NO* prox;
}NO;

//Estrutura Pilhas
typedef struct PILHA {
    NO* topo;
}PILHA;

//Variável do tipo PILHA
PILHA* p;

void empilha() {
    //aloca o novo nó ptr de tamanho struct nó e atribui ao ponteiro ptr
    NO* ptr = (NO*)malloc(sizeof(NO));
    //atribui um valor aleatório ao dado
    ptr->dado = rand() % 100;
    //atualiza o ponteiro prox para ser o novo topo
    ptr->prox = p->topo;
    //topo recebe o ptr (novo topo)
    p->topo = ptr;
}

int desempilha() {
    //cria um ponteiro apontando para o topo e cria uma variável de retorno
    NO* ptr = p->topo;
    int dado;

    //verifica se a pilha está vazia
    if (ptr != NULL) {
        //atualiza o valor do topo da pilha
        p->topo = ptr->prox;
        //desligar o elemento do topo
        ptr->prox = NULL;
        //armazena o valor do retorno
        dado = ptr->dado;
        //libera memória / destrói o elemento
        free(ptr);
        //retorno da função
        return dado;
    }
}

int main()
{
    printf("Olá mundo");
}

#include <stdlib.h>
#include <stdio.h>

typedef struct NO{
    int dado; //dado;
    struct NO* prox; //ponteiro para o próximo elemento da fila;
}NO;

typedef struct FILA{
    NO* inicio; //início da fila;
    NO* fim; //fim da fila;
}FILA;

FILA *p; //instância do tipo fila

void enfileira(){
    NO* ptr = (NO *) malloc(sizeof(NO));
    ptr->dado = rand()%100;
    ptr->prox = NULL;
    if(f->inicio == NULL)
        f->inicio = ptr;
    else
        f->fim->prox = ptr;
    f->fim = ptr;
}

int main(){

}

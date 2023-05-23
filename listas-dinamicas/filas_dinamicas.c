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
    //criação de um novo elemento dinamicamente
    NO* ptr = (NO *) malloc(sizeof(NO));
    //aloca o valor ao elemento
    ptr->dado = rand()%100;
    //proximo elemento passa a valer null
    ptr->prox = NULL;
    //se o inicio estiver vazio, aloca ptr ao inicio
    if(f->inicio == NULL)
        f->inicio = ptr;
    else
        //se nao estiver vazio, o ponteiro que esta no fim da fila aponta para o novo elemento ptr
        f->fim->prox = ptr;
    f->fim = ptr;
}

int desenfileira(){
    //aponta ptr para o final da fila
    NO* ptr = f->inicio;
    int dado;
    //testa se a fila nao esta vazia
    if(ptr != NULL){
        //inicio recebe o proximo elemento
        f->inicio = ptr->prox;
        //desligo o elemento que foi retirado
        ptr->prox = NULL;
        //recupero o valor do elemento retirado
        dado = ptr->dado;
        //libera a porcao de memoria
        free(ptr);
        return dado;
    }
}

int main(){

}

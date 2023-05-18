#include <stdio.h>
#include <stdlib.h>

#define tamanho 3

struct tipo_pilha {
    int dados[tamanho];
    int ini;
    int fim;
};

struct tipo_pilha fila;

//enfileirar (push_back);

//se o final da fila � igual ao tamanho, automaticamente a fila estar� cheia.
// caso contr�rio, o elemento ser� atribu�do � fila no �ndice final e o �ndice final ser� incrementado;
void enfileira(int elemento){
    if(fila.fim==tamanho){
        printf("Fila cheia.\n");
        system("pause");
    } else{
        fila.dados[fila.fim]=elemento;
        printf("Enfileirado (%d).\n", elemento);
        fila.fim++;
    }
}

//desenfileirar (pop);

//caso o fim da fila seja igual o in�cio, provavelmente teremos uma fila vazia;
//caso contr�rio, atribui-se o in�cio ao elemento, percorro o vetor e adiciono 1 ao �ndice do vetor -> arrastar o elemento em dire��o ao in�cio;
int desenfileira(){
    int elemento;
    if(fila.fim==fila.ini){
        printf("Fila vazia.\n");
        system("pause");
    } else {
        elemento = fila.dados[fila.ini];
        for(int i=0; i<tamanho; i++){
            fila.dados[i] = fila.dados[i+1];
        }
        fila.dados[fila.fim]=0;
        printf("Desenfileirado (%d).\n", elemento);
        fila.fim--;
        return elemento;
    }
}

int main(){
    enfileira(10);
    enfileira(20);

    for(int i=0; i<tamanho; i++){
        printf("[%d] = [%d].\n", i, fila.dados[i]);
    }
    system("pause");

    printf("\n");
    enfileira(30);
    enfileira(40);

    for(int i=0; i<tamanho; i++){
        printf("[%d] = [%d].\n", i, fila.dados[i]);
    }
    system("pause");

    desenfileira();
    desenfileira();
    printf("\n");

    enfileira(5);
    enfileira(6);
    for(int i=0; i<tamanho; i++){
        printf("[%d] = [%d].\n", i, fila.dados[i]);
    }
    system("pause");
}

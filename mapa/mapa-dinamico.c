#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//definindo a estrutura da lista
typedef struct no{
    char dado;
    struct no *proximo;
}no;

typedef struct FILA{
    no *inicio; //início da FILA;
    no *fim; //fim da FILA;
}FILA;

typedef struct PILHA {
    no *base;
    no *topo;
} PILHA;

//definindo variaveis
typedef no *ptr_no;
ptr_no pilha;
ptr_no fila;
PILHA *p;
FILA *f;
int op;
char letra;

void pilha_inserir(ptr_no pilha, char letra){
    while(pilha->proximo != NULL){
        pilha = pilha->proximo;
    }
    pilha->proximo = (ptr_no) malloc(sizeof(no));
    pilha = pilha->proximo;
    pilha->dado = letra;
    pilha->proximo = NULL;
}

void pilha_mostrar(ptr_no pilha){
    while (pilha->proximo != NULL){
        printf("%c", pilha->dado);
        pilha = pilha->proximo;
    }
    printf("%c", pilha->dado);
}

void fila_inserir(ptr_no fila, char letra){
    while (fila->proximo != NULL){
        fila = fila->proximo;
    }
    fila->proximo = (ptr_no) malloc(sizeof(no));
    fila = fila->proximo;
    fila->dado = letra;
    fila->proximo = NULL;
}

char fila_remover(ptr_no fila){
    ptr_no atual;
    atual = (ptr_no) malloc(sizeof(no));
    atual = fila;
    if(fila->proximo != NULL){
        fila = fila->proximo;
        atual->proximo = fila->proximo;
        return atual->dado;
    }
}

void fila_mostrar(ptr_no fila){
    while(fila->proximo != NULL){
        printf("%c", fila->dado);
        fila = fila->proximo;
    }
    printf("%c", fila->dado);
}

int main(){
    int n;

    printf("Quantidade de elementos que serao sequenciados: ");
    scanf("%d", &n);

    char sequencia[n];

    fflush(stdin);
    printf("Digite a sequencia (A, T, C, G): ");
    scanf("%s", sequencia);

    for (int i = 0; i < n; i++)
    {
        fila_inserir(&fila, sequencia[i]);
    }

    printf("Fila: ");
    fila_mostrar(&fila);

    for (int i = 0; i < n; i++) {
        char letra = fila_remover(fila);
        switch (letra) {
            case 'A':
                letra = 'T';
                break;
            case 'C':
                letra = 'G';
                break;
            case 'T':
                letra = 'A';
                break;
            case 'G':
                letra = 'C';
                break;
        }
        pilha_inserir(&pilha, letra);
    }

    printf("\nPilha: ");
    pilha_mostrar(&pilha);
}
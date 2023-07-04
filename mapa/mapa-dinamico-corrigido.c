#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    char dado;
    struct no* proximo;
} no;

typedef no* ptr_no;

typedef struct FILA {
    ptr_no inicio;
    ptr_no fim;
} FILA;

typedef struct PILHA {
    ptr_no base;
    ptr_no topo;
} PILHA;

void pilha_inserir(ptr_no pilha, char letra) {
    while (pilha->proximo != NULL) {
        pilha = pilha->proximo;
    }
    pilha->proximo = (ptr_no)malloc(sizeof(no));
    pilha = pilha->proximo;
    pilha->dado = letra;
    pilha->proximo = NULL;
}

void pilha_mostrar(ptr_no pilha) {
    while (pilha != NULL) {
        printf("%c", pilha->dado);
        pilha = pilha->proximo;
    }
}

void fila_inserir(ptr_no fila, char letra) {
    while (fila->proximo != NULL) {
        fila = fila->proximo;
    }
    fila->proximo = (ptr_no)malloc(sizeof(no));
    fila = fila->proximo;
    fila->dado = letra;
    fila->proximo = NULL;
}

char fila_remover(ptr_no fila) {
    ptr_no atual;
    atual = fila->proximo;
    fila->proximo = atual->proximo;
    char dado = atual->dado;
    free(atual);
    return dado;
}

void fila_mostrar(ptr_no fila) {
    while (fila != NULL) {
        printf("%c", fila->dado);
        fila = fila->proximo;
    }
}

int main() {
    int n;

    printf("Quantidade de elementos que serao sequenciados: ");
    scanf("%d", &n);

    char sequencia[n];

    printf("Digite a sequencia (A, T, C, G): ");
    scanf("%s", sequencia);

    ptr_no fila = (ptr_no)malloc(sizeof(no));
    fila->proximo = NULL;

    for (int i = 0; i < n; i++) {
        fila_inserir(fila, sequencia[i]);
    }

    printf("Fila: ");
    fila_mostrar(fila);

    ptr_no pilha = (ptr_no)malloc(sizeof(no));
    pilha->proximo = NULL;

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
        pilha_inserir(pilha, letra);
    }

    printf("\nPilha: ");
    pilha_mostrar(pilha);

    return 0;
}
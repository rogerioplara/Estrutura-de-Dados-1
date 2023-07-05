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
    ptr_no topo;
} PILHA;

void pilha_inserir(PILHA* pilha, char letra) {
    ptr_no novo_no = (ptr_no)malloc(sizeof(no));
    novo_no->dado = letra;
    novo_no->proximo = pilha->topo;
    pilha->topo = novo_no;
}

void pilha_mostrar(PILHA* pilha) {
    ptr_no atual = pilha->topo;
    while (atual != NULL) {
        printf("%c", atual->dado);
        atual = atual->proximo;
    }
}

void fila_inserir(FILA* fila, char letra) {
    ptr_no novo_no = (ptr_no)malloc(sizeof(no));
    novo_no->dado = letra;
    novo_no->proximo = NULL;

    if (fila->inicio == NULL) {
        fila->inicio = novo_no;
        fila->fim = novo_no;
    } else {
        fila->fim->proximo = novo_no;
        fila->fim = novo_no;
    }
}

char fila_remover(FILA* fila) {
    if (fila->inicio == NULL) {
        printf("A fila está vazia.\n");
        return '\0';
    }

    ptr_no atual = fila->inicio;
    char dado = atual->dado;
    fila->inicio = fila->inicio->proximo;

    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }

    free(atual);
    return dado;
}

void fila_mostrar(FILA* fila) {
    ptr_no atual = fila->inicio;
    while (atual != NULL) {
        printf("%c", atual->dado);
        atual = atual->proximo;
    }
}

int main() {
    char sequencia[999];
    printf("Digite a sequencia de DNA (A, T, C, G): ");
    scanf("%s", sequencia);

    int sequenciaTamanho = strlen(sequencia);

    FILA fila;
    PILHA pilha;
    fila.inicio = NULL;
    fila.fim = NULL;
    pilha.topo = NULL;

    for (int i = 0; i < sequenciaTamanho; i++) {
        fila_inserir(&fila, sequencia[i]);
    }

    printf("Fila: ");
    fila_mostrar(&fila);

    for (int i = 0; i < sequenciaTamanho; i++) {
        char letra = fila_remover(&fila);
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

    return 0;
}
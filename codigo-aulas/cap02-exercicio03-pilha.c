#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define tamanho 5

//Definicao da pilha
struct tpilha {
    int dados[tamanho];
    int ini;
    int fim;
};

//Instancia da pilha
struct tpilha pilha;
int op;

//Prototipacao
void pilha_entrar();
void pilha_sair();
void pilha_mostrar();
void menu_mostrar();

int main() {
    setlocale(LC_ALL, "Portuguese");
    op = 1;
    pilha.ini = 0;
    pilha.fim = 0;

    while (op != 0) {
        system("cls");
        pilha_mostrar();
        menu_mostrar();
        scanf("%d", &op);

        switch (op) {
        case 1:
            pilha_entrar();
            break;
        case 2:
            pilha_sair();
            break;
        }
    }
    return 0;
}

//Adicionar elemento na pilha
void pilha_entrar() {
    if (pilha.fim == tamanho) {
        printf("\nA A pilha de livros esta cheia!\n\n");
        system("pause");
    }
    else {
        printf("\nDigite o valor a ser empilhado: ");
        scanf("%d", &pilha.dados[pilha.fim]);
        pilha.fim++;
    }
}

//Remover elemento da pilha
void pilha_sair() {
    if (pilha.fim == pilha.ini) {
        printf("\nNao existem mais livros para guardar!");
        system("pause");
    }
    else {
        pilha.dados[pilha.fim - 1] = 0;
        pilha.fim--;
    }
}

//Mostrar o conteudo da pilha
void pilha_mostrar() {
    int i;
    printf("[");
    for (i = 0; i < tamanho; i++) {
        printf("( %s ), ", pilha.dados[i]);
    }
    printf("]\n\n");
}

void menu_mostrar() {
    printf("\nEscolha uma opcao:\n");
    printf("1 - Empilhar livro\n");
    printf("2 - Guardar livro\n");
    printf("0 - Sair\n");
}



#include <stdlib.h>
#include <stdio.h>
#include <time.h>

//definindo a estrutura da pilha
typedef struct no{
    int dado;
    struct no *proximo;
}no;

//definindo variaveis
typedef no *ptr_no;
ptr_no pilha;
int op;

//prototipacao
void menu_mostrar();
void menu_selecionar(int op);
void pilha_mostrar(ptr_no pilha);
void pilha_inserir(ptr_no pilha);
void pilha_remover(ptr_no pilha);

//mostra o menu de opcoes
void menu_mostrar(){
    pilha_mostrar(pilha);
    printf("\n\nEscolha uma das opcoes:\n");
    printf("1 - Inserir no final da pilha\n");
    printf("2 - Remover no final da pilha\n");
    printf("0 - Sair\n\n");
}

//executa a opcao escolhida no menu
void menu_selecionar(int op){
    switch(op){
        case 1:
            pilha_inserir(pilha);
            break;
        case 2:
            pilha_remover(pilha);
            break;
    }
}

//insere um elemento no final da pilha
void pilha_inserir(ptr_no pilha){
    while(pilha->proximo != NULL){
        pilha = pilha->proximo;
    }
    pilha->proximo = (ptr_no) malloc(sizeof(no));
    pilha = pilha->proximo;
    pilha->dado = rand()%100;
    pilha->proximo = NULL;
}

//remove um elemento da pilha
void pilha_remover(ptr_no pilha){
    ptr_no atual;
    atual = (ptr_no) malloc(sizeof(no));
    while (pilha->proximo != NULL){
        atual = pilha;
        pilha = pilha->proximo;
    }
    atual->proximo = NULL;
}

//desenha o conteudo da pilha na tela
void pilha_mostrar(ptr_no pilha){
    system("cls");
    while (pilha->proximo != NULL){
        printf("%d, ", pilha->dado);
        pilha = pilha->proximo;
    }
    printf("%d, ", pilha->dado);
}

//funcao principal
int main(){
    srand(time(NULL));
    op = 1;
    //criando o primeiro no da pilha
    pilha = (ptr_no) malloc(sizeof(no));
    pilha->dado = 0;
    pilha->proximo = NULL;

    //laco principal
    while(op != 0){
        system("cls");
        menu_mostrar();
        scanf("%d", &op);
        menu_selecionar(op);
    }
    system("Pause");
    return(0);
}
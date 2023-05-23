#include <stdlib.h>
#include <stdio.h>
#include <time.h>

//definindo a estrutura da fila
typedef struct no{
    int dado;
    struct no *proximo;
}no;

//definindo variaveis
typedef no *ptr_no;
ptr_no fila;
int op;

//prototipacao
void menu_mostrar();
void menu_selecionar(int op);
void fila_mostrar(ptr_no fila);
void fila_inserir(ptr_no fila);
void fila_remover(ptr_no fila);

void fila_inserir(ptr_no fila){
    while (fila->proximo != NULL){
        fila = fila->proximo;
    }
    fila->proximo = (ptr_no) malloc(sizeof(no));
    fila = fila->proximo;
    fila->dado = rand()%100;
    fila->proximo = NULL;
}

void fila_remover(ptr_no fila){
    ptr_no atual;
    atual = (ptr_no) malloc(sizeof(no));
    atual = fila;
    if(fila->proximo != NULL){
        fila = fila->proximo;
        atual->proximo = fila->proximo;
    }
}

void menu_mostrar(){
    fila_mostrar(fila);
    printf("\n\nEscolha uma das opcoes:\n");
    printf("1 - Inserir no final da fila\n");
    printf("2 - Remover no inicio da fila\n");
    printf("0 - Sair\n\n");
}

//executa a opcao escolhida no menu
void menu_selecionar(int op){
    switch(op){
        case 1:
            fila_inserir(fila);
            break;
        case 2:
            fila_remover(fila);
            break;
    }
}

void fila_mostrar(ptr_no fila){
    system("cls");
    while(fila->proximo != NULL){
        printf("%d, ", fila->dado);
        fila = fila->proximo;
    }
    printf("%d, ", fila->dado);
}

int main(){
    srand(time(NULL));
    op = 1;
    //criando o primeiro no da fila
    fila = (ptr_no) malloc(sizeof(no));
    fila->dado = 0;
    fila->proximo = NULL;

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
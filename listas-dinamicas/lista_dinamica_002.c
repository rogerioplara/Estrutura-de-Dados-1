#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// estrutura do no
typedef struct no {
  // valor do elemento
  int dado;
  // ponteiro para o proximo no
  struct no *proximo;
} no;

// criacao do ponteiro do tipo no para alocar dinamicamente na memoria para cada elemento da lista
typedef no *ptr_no;
// variavel que aponta para o inicio da lista;
ptr_no lista;

int op;

// prototipacao
void menu_mostrar();
void menu_selecionar(int op);
void lista_inserir(ptr_no lista);
void lista_remover(ptr_no lista);
void lista_mostrar(ptr_no lista);

void lista_mostrar(ptr_no lista) {
  system("cls");
  // laco para percorrer a lista ate o ultimo no
  while (lista->proximo != NULL) {
    printf("%d, ", lista->dado);
    lista = lista->proximo;
  }
  // imprime o ultimo elemento da lista pois o laco anterior imprime ate o penultimo
  printf("%d, ", lista->dado);
}

// insere um elemento no final da lista
void lista_inserir(ptr_no lista) {
  // laco para percorrer a lista ate o ultimo no
  while (lista->proximo != NULL) {
    lista = lista->proximo;
  }
  // criar um novo elemento (alocacao de memoria)
  lista->proximo = (ptr_no)malloc(sizeof(no));
  lista = lista->proximo;
  // atribui um valor ao elemento
  lista->dado = rand() % 100;
  // atribui um valor nulo ao seu ponteiro, ou seja, aponta para o final da lista
  lista->proximo = NULL;
}

// remove um item da lista
void lista_remover(ptr_no lista) {
  int dado;
  // guarda a posicao atual da lista
  ptr_no atual;
  atual = (ptr_no)malloc(sizeof(no));
  printf("\n\nEscolha um dos itens: \n");
  scanf("%d", &dado);
  while (lista->dado != dado) {
    if (lista->proximo == NULL) {
      break;
    }
    // atribui o elemento que deseja removar a variavel atual
    atual = lista;
    // atribui o proximo elemento da lista a variavel lista
    lista = lista->proximo;
  }
  if (lista->dado == dado) {
    atual->proximo = lista->proximo;
  }
}

// menu de opcoes
void menu_selecionar(int op) {
  switch (op) {
  case 1:
    lista_inserir(lista);
    break;
  case 2:
    lista_remover(lista);
    break;
  }
}

void menu_mostrar() {
  lista_mostrar(lista);
  printf("\n\nEscolha uma das opcoes: \n");
  printf("1 - Inserir no final da Lista\n");
  printf("2 - Remover um item da lista\n");
  printf("0 - Sair\n\n");
}

int main() {
  // inicializando maquina de numero randomicos
  srand(time(NULL));
  op = 1;
  // criando o primeiro no da lista
  lista = (ptr_no)malloc(sizeof(no));
  // atribui o valor 0 ao primeiro elemento da lista alocado anteriormente
  lista->dado = 0;
  // atribui a variavel proximo como sendo o final da fila, por isso recebe o valor NULL
  lista->proximo = NULL;

  // laco principal
  while (op != 0) {
    system("cls");
    menu_mostrar();
    scanf("%d", &op);
    menu_selecionar(op);
  }
  system("Pause");
  return (0);
}

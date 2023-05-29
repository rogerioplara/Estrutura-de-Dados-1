#include <stdio.h>
#include <stdlib.h>

#define tam 10

struct pilha{
   int dados[tam];
   int primeiro;
   int ultimo;
};

struct pilha p;
int op = 1;

void desempilhar();
void pilha_mostrar();
void pilha_entrar();
void menu();

void desempilhar(){
   p.dados[p.ultimo-1] = 0;
   p.ultimo--;
}

void pilha_mostrar(){
   int i;
   printf("[ ");
   for (i = 0; i < tam; i++){
      printf("%d ", p.dados[i]);
   }
   printf("]\n\n");
}

void pilha_entrar(){
   printf("\nDigite o valor a ser empilhado: ");
   scanf("%d", &p.dados[p.ultimo]);
   p.ultimo++;
}

void menu(){
   printf("\nEscolha uma opcao:\n"); 
   printf("1 - Empilhar\n"); 
   printf("2 - Desempilhar\n"); 
   printf("0 - Sair\n\n"); 
}

int main(){
   
   while (op != 0){
      menu();
      scanf("%d", &op);
      switch (op){
      case 1:
         pilha_entrar();
         pilha_mostrar();
         break;
      case 2:
         desempilhar();
         pilha_mostrar();
         break;
      default:
         break;
      }

   }
   

   return 0;
}

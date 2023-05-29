#include <stdio.h>
#include <stdlib.h>

#define MAXIMO 10

//estrutura de dados de matriz de adjacências
int ma[MAXIMO][MAXIMO];
int tamanho = 0;
int op;

int matriz_tamanho(){
    int tam;
    //testa se o tamanho não excede o máximo e se não é vazio
    while (tam > MAXIMO || tam < 1){
        printf("Escolha a quantidade de vertices: \n");
        scanf("%d", &tam);
    }
    return tam;    
}

void inserir_aresta_matriz(int num1, int num2){
    //testa se o valor de vértices é válido, nesse caso maior que 0 e menor que o tamanho;
    if(num1 > tamanho-1 || num2 > tamanho-1 || num1 < 0 || num2 < 0){
        printf("ERRO!\n");
        system("pause");
    } else {
        //insere nas posições que o usuário definiu
        ma[num1][num2] = 1;
        ma[num2][num1] = 1;
        system("cls");
    }
}

void remover_aresta_matriz(int num1, int num2){
    //testa se o valor de vértices é válido, nesse caso maior que 0 e menor que o tamanho;
    if(num1 > tamanho-1 || num2 > tamanho-1 || num1 < 0 || num2 < 0){
        printf("ERRO!");
        system("pause");
    } else {
        //remove posições que o usuário definiu
        ma[num1][num2] = 0;
        ma[num2][num1] = 0;
        system("cls");
    }
}

void exibir_matriz(){
    printf("Matriz de arestas: \n");
    for(int i=0; i<tamanho; i++){
        printf("%d [ ", i);
        for(int j=0; j<tamanho; j++){
            printf("%d ", ma[i][j]);
        }
        printf("]\n");
    }
}

void menu(){
    exibir_matriz();
    printf("DIGITE A OPCAO DESEJADA: \n");
    printf("1 - Inserir aresta\n");
    printf("2 - Remover aresta\n");
    printf("0 - Sair\n");
}

int main(){
    op = 1;
    int num1, num2;
    tamanho = matriz_tamanho();
    system("cls");
    while(op != 0){
        system("cls");
        printf("%d %d\n\n", num1, num2);
        menu();
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("Insira as arestas para adicionar: ");
            scanf("%d, %d", &num1, &num2);
            inserir_aresta_matriz(num1, num2);
            break;
        case 2:
            printf("Insira as arestas para remover: ");
            scanf("%d, %d", &num1, &num2);
            remover_aresta_matriz(num1, num2);
            break;
        }
    }
}
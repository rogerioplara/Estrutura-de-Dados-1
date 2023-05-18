#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int tam;
    int *vetor;
    int pot;
    printf("Escolha o tamanho do vetor: ");
    scanf("%d", &tam);
    printf("Escolha o valor da potencia: ");
    scanf("%d", &pot);
    vetor = (int *) malloc(sizeof(int)*tam);

    for(int i=0; i<tam; i++){
        vetor[i] = pow(pot, i);
        printf("Posicao %d^%d = %d\n", i, pot, vetor[i]);
    }

    system("pause");
    return 0;
}


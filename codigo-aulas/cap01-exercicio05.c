#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int x;
    int *px1;
    int *px2;
    int quadrado = 2;
    int cubo = 3;

    printf("Qual sera o tamanho do vetor? ");
    scanf("%d", &x);
    px1 = (int *) malloc(sizeof(int)*x);
    px2 = (int *) malloc(sizeof(int)*(x*2));

    printf("Ao quadrado\n");
    for(int i=1; i<=x; i++){
        px1[i] = pow(quadrado, i);
        printf("%d^%d = %d\n", i, quadrado, px1[i]);
    }

    printf("\nAo cubo\n");

    for(int i=1; i<=x*2; i++){
        px2[i] = pow(cubo, i);
        printf("%d^%d = %d\n", i, cubo, px2[i]);
    }
}

#include <stdio.h>
#include <stdlib.h>

int xi;
int *ptr_xi;

void imprimir()
{
    printf("Valor de xi = %d \n", xi);             // imprime o valor da vari�vel
    printf("Valor de &xi = %p \n", &xi);           // imprime o endere�o da vari�vel xi
    printf("Valor de ptr_xi = %p \n", ptr_xi);     // imprime o ponteiro para um iteiro
    printf("Valor de *ptr_xi = %d \n\n", *ptr_xi); // imprime o valor da vari�vel ptr_xi

    // ponteiros tambem tem tipo, eles apontam para uma vari�vel de determinado tipo e cada tipo tem suas caracteristicas;
}

int main()
{
    xi = 10;
    ptr_xi = &xi;
    imprimir();

    xi = 20;
    imprimir();

    *ptr_xi = 30;
    imprimir();

    system("Pause");
    return (0);
}

void ponteiros(){
    int *p;
    p = (int *) malloc(int);
    if(p==NULL){
        printf("Erro!\n");
    } else {
        *p = 10;
        printf("p: %d\n", *p);
        free(p);
    }
}
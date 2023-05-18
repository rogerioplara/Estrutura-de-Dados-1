#include <stdio.h>
#include <stdlib.h>

int *ptr;

int main()
{
    ponteiro1();

    ponteiro2();

    ponteiro3();
}

void ponteiro1(){
    printf ("Endereco: %p\n\n", ptr);
    ptr = (int *) malloc(sizeof (int));
    printf ("Endereco: %p \nValor: %d\n\n", ptr, *ptr);

    *ptr = 10;
    printf ("Endereco: %p \nValor: %d\n\n", ptr, *ptr);
}

void ponteiro2(){
    int x;
    x = 20;
    ptr = &x;
    printf("Endereco: %p \nValor: %d\n\n", ptr, *ptr);

    ptr = (int*) malloc(sizeof(int));
    printf("Endereco: %p \nValor: %d\n\n", ptr, *ptr);
}

void ponteiro3(){
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


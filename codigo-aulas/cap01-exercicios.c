#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct tipo_semafaro {
    char cor[10];
    int id;
};

struct tipo_semafaro s1 = {"Vermelho", 1};
struct tipo_semafaro s2 = {"Amarelo", 2};
struct tipo_semafaro s3 = {"Verde", 3};
struct tipo_semafaro *ptr_s;

int main(){
    //atribui o endere�o de s1 � vari�vel ptr_s -> dessa forma os outros ser�o alocados sequencialmente;
    ptr_s = &s1;
    printf("%d - %s\n", (*ptr_s).id, (*ptr_s).cor);
    ptr_s = ptr_s + 1;
    printf("%d - %s\n", (*ptr_s).id, (*ptr_s).cor);
    ptr_s = ptr_s + 1;
    printf("%d - %s\n", (*ptr_s).id, (*ptr_s).cor);

    system("Pause");
    return 0;
}

void ponteiroSimples(){
    int *point;
    point = (int *) malloc(sizeof(int));
    *point = 42;

    printf("%d\n", point);
    printf("%d\n", *point);
    printf("%p\n", &point);
}

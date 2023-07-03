#include <stdio.h>
#include <stdlib.h>

//solução com vetores simplificada;

int main(){
    int n;

    printf("Digite a quantidade de aminoacidos: ");
    scanf("%d", &n);

    char nucleotideos[n];
    char convertido[n];

    fflush(stdin);
    for (int i = 0; i < n; i++)
    {
        printf("Digite o aminoacido da posicao %d: ", i + 1);
        scanf("%c", &nucleotideos[i]);
        fflush(stdin);
    }

    printf("\n");

    for (int i = 0; i < n; i++)
    {
        if (nucleotideos[i] == 'A')
        {
            convertido[i] = 'T';
        } else if (nucleotideos[i] == 'C')
        {
            convertido[i] = 'G';
        } else if (nucleotideos[i] == 'T')
        {
            convertido[i] = 'A';
        } else if (nucleotideos[i] == 'G')
        {
            convertido[i] = 'C';
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%c", nucleotideos[i]);
    }  

    printf("\n");

    for (int i = n; i >= 0; i--)
    {    
        printf("%c", convertido[i]);
    }  

}
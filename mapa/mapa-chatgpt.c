#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura do nó da fila dinâmica
typedef struct No {
    char nucleotide;
    struct No* next;
} No;

// Definição da estrutura da fila dinâmica
typedef struct {
    No* front;
    No* rear;
} Queue;

// Função para inicializar a fila
void initializeQueue(Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

// Função para verificar se a fila está vazia
int isQueueEmpty(Queue* queue) {
    return (queue->front == NULL);
}

// Função para inserir um elemento na fila
void enqueue(Queue* queue, char nucleotide) {
    No* newNode = (No*)malloc(sizeof(No));
    newNode->nucleotide = nucleotide;
    newNode->next = NULL;

    if (isQueueEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Função para remover um elemento da fila
char dequeue(Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("A fila está vazia.\n");
        return '\0';
    }

    No* frontNode = queue->front;
    char nucleotide = frontNode->nucleotide;

    queue->front = frontNode->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(frontNode);
    return nucleotide;
}

// Função para imprimir a fila
void printQueue(Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("A fila esta vazia.\n");
        return;
    }

    No* currentNode = queue->front;
    while (currentNode != NULL) {
        printf("%c", currentNode->nucleotide);
        currentNode = currentNode->next;
    }
    printf("\n");
}

// Definição da estrutura da pilha dinâmica
typedef struct StackNode {
    char nucleotide;
    struct StackNode* next;
} StackNode;

// Função para inicializar a pilha
void initializeStack(StackNode** stack) {
    *stack = NULL;
}

// Função para verificar se a pilha está vazia
int isStackEmpty(StackNode** stack) {
    return (*stack == NULL);
}

// Função para inserir um elemento na pilha
void push(StackNode** stack, char nucleotide) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->nucleotide = nucleotide;
    newNode->next = *stack;
    *stack = newNode;
}

// Função para remover um elemento da pilha
char pop(StackNode** stack) {
    if (isStackEmpty(stack)) {
        printf("A pilha esta vazia.\n");
        return '\0';
    }

    StackNode* topNode = *stack;
    char nucleotide = topNode->nucleotide;

    *stack = topNode->next;
    free(topNode);
    return nucleotide;
}

// Função para imprimir a pilha
void printStack(StackNode** stack) {
    if (isStackEmpty(stack)) {
        printf("A pilha esta vazia.\n");
        return;
    }

    StackNode* currentNode = *stack;
    while (currentNode != NULL) {
        printf("%c", currentNode->nucleotide);
        currentNode = currentNode->next;
    }
    printf("\n");
}

int main() {
    char dnaSequence[100];
    printf("Digite a sequencia de DNA: ");
    scanf("%s", dnaSequence);

    int sequenceLength = strlen(dnaSequence);

    Queue dnaQueue;
    initializeQueue(&dnaQueue);

    for (int i = 0; i < sequenceLength; i++) {
        enqueue(&dnaQueue, dnaSequence[i]);
    }

    StackNode* dnaStack;
    initializeStack(&dnaStack);

    printf("Fila: ");
    printQueue(&dnaQueue);

    for (int i = 0; i < sequenceLength; i++) {
        char nucleotide = dequeue(&dnaQueue);
        switch (nucleotide) {
            case 'A':
                nucleotide = 'T';
                break;
            case 'C':
                nucleotide = 'G';
                break;
            case 'T':
                nucleotide = 'A';
                break;
            case 'G':
                nucleotide = 'C';
                break;
            default:
                printf("Sequencia de DNA invalida.\n");
                return 0;
        }
        push(&dnaStack, nucleotide);
    }

    printf("Pilha: ");
    printStack(&dnaStack);

    return 0;
}
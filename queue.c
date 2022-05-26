#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct Fila
{
    int topo, fim, tam;
    unsigned capacidade;
    int *vetor;
};

struct Fila *criarFila(unsigned capacidade)
{
    struct Fila *fila = (struct Fila *)malloc(sizeof(struct Fila));
    fila->capacidade = capacidade;
    fila->topo = fila->tam = 0;

    fila->fim = capacidade - 1;
    fila->vetor = (int *)malloc(fila->capacidade * sizeof(int));
    return fila;
}

int isFull(struct Fila *fila)
{
    return (fila->tam == fila->capacidade);
}

int isEmpty(struct Fila *fila)
{
    return (fila->tam == 0);
}

void enfileirar(struct Fila *fila, int item)
{
    if (isFull(fila))
        return;
    fila->fim = (fila->fim + 1) % fila->capacidade;
    fila->vetor[fila->fim] = item;
    fila->tam = fila->tam + 1;
    printf("%d adicionado a fila\n", item);
}

int removerTopo(struct Fila *fila)
{
    if (isEmpty(fila))
        return INT_MIN;
    int item = fila->vetor[fila->topo];
    fila->topo = (fila->topo + 1) % fila->capacidade;
    fila->tam = fila->tam - 1;
    return item;
}

int getTopo(struct Fila *fila)
{
    if (isEmpty(fila))
        return INT_MIN;
    return fila->vetor[fila->topo];
}

int getFim(struct Fila *fila)
{
    if (isEmpty(fila))
        return INT_MIN;
    return fila->vetor[fila->fim];
}

int main()
{
    struct Fila *fila = criarFila(10);

    enfileirar(fila, 10);
    enfileirar(fila, 20);
    enfileirar(fila, 30);
    enfileirar(fila, 40);

    printf("Ficha %d removida da fila\n\n", removerTopo(fila));

    printf("A ficha atual e %d\n", getTopo(fila));
    printf("A ficha mais recente e %d\n", getFim(fila));

    return 0;
}

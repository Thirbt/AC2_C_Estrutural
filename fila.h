#include<stdlib.h>
#include<stdio.h>
#define avanca(i) (i=(i+1) % F->max)
typedef struct controle_fila{
    int max; /*capacidade m�xima da fila*/
    int total; /*posi��o do topo*/
    int inicio; /*posi��o do inicio */
    int final; /*posi��o do final */
    int *item; /*armazena o primeiro endere�o de mem�ria da regi�o alocada para armazenar os �tens da fila*/
} *Fila;

Fila inicializaFila(int qtde_itens){ /*fun��o para inicializar a estrutura da pilha*/
    Fila F=malloc(sizeof(struct controle_fila)); /*alocando mem�ria dinamicamente para a struct controle_fila*/
    F->max=qtde_itens; /*definindo a quantidade m�xima de itens a serem manipulados na fila*/
    F->total=0; /*A fila est� vazia, n�o h� nenhum elemento armazenado inicialmente*/
    F->inicio=0; /*A fila est� vazia, n�o h� nenhum elemento no �nicio*/
    F->final=0; /*A fila est� vazia, n�o h� nenhum elemento no final*/
    F->item = malloc(qtde_itens*sizeof(int)); /*alocando mem�ria suficiente para a cole��o de itens da fila*/
    return F;
}

int filaVazia(Fila F){ /*Fun��o que verifica se a fila est� ou n�o vazia*/
    return(F->total==0);
}

int filaCheia(Fila F){ /*Fun��o que verifica se a fila est� ou n�o cheia*/
    return(F->total==F->max);
}

void enfileira(int valor, Fila F){ /*Fun��o que adiciona um item na fila*/
    if(filaCheia(F)) {printf("Fila cheia!!"); abort();}
    F->item[F->final] = valor;
    avanca(F->final);
    F->total++;
}

int desenfileira(Fila F){ /*Fun��o que remove um item da fila*/
    if(filaVazia(F)) {printf("Fila vazia!!"); abort();}
    int valor=F->item[F->inicio];
    avanca(F->inicio);
    F->total--;
    return valor;
}

void destroiFila(Fila *F){ /*Fun��o que libera a mem�ria alocada para os itens da fila e sua estrutura de controle*/
    free((*F)->item);
    free(*F);
    *F=NULL;
}

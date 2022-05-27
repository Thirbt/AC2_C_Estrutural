#include<stdlib.h>
#include<stdio.h>
#define avanca(i) (i=(i+1) % F->max)
typedef struct controle_fila{
    int max; /*capacidade máxima da fila*/
    int total; /*posição do topo*/
    int inicio; /*posição do inicio */
    int final; /*posição do final */
    int *item; /*armazena o primeiro endereço de memória da região alocada para armazenar os ítens da fila*/
} *Fila;

Fila inicializaFila(int qtde_itens){ /*função para inicializar a estrutura da pilha*/
    Fila F=malloc(sizeof(struct controle_fila)); /*alocando memória dinamicamente para a struct controle_fila*/
    F->max=qtde_itens; /*definindo a quantidade máxima de itens a serem manipulados na fila*/
    F->total=0; /*A fila está vazia, não há nenhum elemento armazenado inicialmente*/
    F->inicio=0; /*A fila está vazia, não há nenhum elemento no ínicio*/
    F->final=0; /*A fila está vazia, não há nenhum elemento no final*/
    F->item = malloc(qtde_itens*sizeof(int)); /*alocando memória suficiente para a coleção de itens da fila*/
    return F;
}

int filaVazia(Fila F){ /*Função que verifica se a fila está ou não vazia*/
    return(F->total==0);
}

int filaCheia(Fila F){ /*Função que verifica se a fila está ou não cheia*/
    return(F->total==F->max);
}

void enfileira(int valor, Fila F){ /*Função que adiciona um item na fila*/
    if(filaCheia(F)) {printf("Fila cheia!!"); abort();}
    F->item[F->final] = valor;
    avanca(F->final);
    F->total++;
}

int desenfileira(Fila F){ /*Função que remove um item da fila*/
    if(filaVazia(F)) {printf("Fila vazia!!"); abort();}
    int valor=F->item[F->inicio];
    avanca(F->inicio);
    F->total--;
    return valor;
}

void destroiFila(Fila *F){ /*Função que libera a memória alocada para os itens da fila e sua estrutura de controle*/
    free((*F)->item);
    free(*F);
    *F=NULL;
}

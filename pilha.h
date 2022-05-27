#include<stdlib.h>

typedef struct controle{ /*Criando a estrutura de controle da pilha*/
    int max; /*armazena a quantidade m�xima de itens da pilha*/
    int topo; /*armazena qual item est� no topo*/
    int *item; /*armazena o primeiro endere�o de mem�ria da regi�o alocada para armazenar os �tens da pilha*/
} *Pilha;

Pilha inicializaPilha(int qtde_itens){ /*fun��o para inicializar a estrutura da pilha*/
    Pilha P = malloc(sizeof(struct controle)); /*alocando mem�ria dinamicamente para a struct controle*/
    P->max=qtde_itens;  /*definindo a quantidade m�xima de itens a serem manipulados na pilha*/
    P->topo=-1; /*definindo que a fila est� vazia*/
    P->item=malloc(qtde_itens*sizeof(int)); /*alocando mem�ria suficiente para a cole��o de itens da pilha*/
    return P; /*retornando a estrutura da pilha criada*/
}

int pilhaVazia(Pilha P){ /*Fun��o que verifica se a pilha est� ou n�o vazia*/
    if(P->topo==-1) return 1;
    else return 0;
}

int pilhaCheia(Pilha P){ /*Fun��o que verifica se a pilha est� ou n�o cheia*/
    if(P->topo == P->max-1) return 1;
    else return 0;
}

void empilha(int valor, Pilha P){ /*Fun��o a ser chamada para colocar um item na pilha */
    if(pilhaCheia(P)) { printf("pilha cheia!"); abort();} /*Se a pilha estiver cheia, n�o ser� permitido colocar mais itens*/
    P->topo++; /*Ao empilhar um novo item, � preciso incrementar o valor que armazena o item que est� no topo*/
    P->item[P->topo] = valor; /*Incluindo o valor na pilha*/
}

int desempilha (Pilha P){ /*Fun��o respons�vel por desempilhar (retirar) o item da pilha que est� atualmente no topo*/
    if(pilhaVazia(P)) {printf("pilha vazia!"); abort();} /*se a pilha estiver vazia, n�o h� nada a se retirar da pilha*/
    int valor = P->item[P->topo]; /*Obtem o valor do item armazenado no topo da pilha*/
    P->topo--; /*decrementa o valor que indica o item que � o topo da pilha*/
    return valor; /*retorna o valor desempilhado*/
}

int topo (Pilha P){ /*Fun��o respons�vel por descobrir qual � o topo da pilha*/
    if(pilhaVazia(P)) {printf("pilha vazia!"); abort();} /*Se a pilha estiver vazia, n�o tem topo*/
    return P->item[P->topo]; /*retorna o topo atual da fila*/
}

void destroiPilha(Pilha *P){ /*Fun��o respons�vel por liberar a mem�ria alocada para os �tens e para a estrutura de controle*/
    free((*P)->item); /*Libera a mem�ria ocupada para os �tens da pilha*/
    free(*P); /*Libera a mem�ria ocupada para os �tens de controle da pilha*/
    *P=NULL; /*Coloca NULL no ponteiro para evitar apontar para uma regi�o desconhecida de mem�ria*/
}

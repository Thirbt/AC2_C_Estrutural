#include<stdlib.h>

typedef struct controle{ /*Criando a estrutura de controle da pilha*/
    int max; /*armazena a quantidade máxima de itens da pilha*/
    int topo; /*armazena qual item está no topo*/
    int *item; /*armazena o primeiro endereço de memória da região alocada para armazenar os ítens da pilha*/
} *Pilha;

Pilha inicializaPilha(int qtde_itens){ /*função para inicializar a estrutura da pilha*/
    Pilha P = malloc(sizeof(struct controle)); /*alocando memória dinamicamente para a struct controle*/
    P->max=qtde_itens;  /*definindo a quantidade máxima de itens a serem manipulados na pilha*/
    P->topo=-1; /*definindo que a fila está vazia*/
    P->item=malloc(qtde_itens*sizeof(int)); /*alocando memória suficiente para a coleção de itens da pilha*/
    return P; /*retornando a estrutura da pilha criada*/
}

int pilhaVazia(Pilha P){ /*Função que verifica se a pilha está ou não vazia*/
    if(P->topo==-1) return 1;
    else return 0;
}

int pilhaCheia(Pilha P){ /*Função que verifica se a pilha está ou não cheia*/
    if(P->topo == P->max-1) return 1;
    else return 0;
}

void empilha(int valor, Pilha P){ /*Função a ser chamada para colocar um item na pilha */
    if(pilhaCheia(P)) { printf("pilha cheia!"); abort();} /*Se a pilha estiver cheia, não será permitido colocar mais itens*/
    P->topo++; /*Ao empilhar um novo item, é preciso incrementar o valor que armazena o item que está no topo*/
    P->item[P->topo] = valor; /*Incluindo o valor na pilha*/
}

int desempilha (Pilha P){ /*Função responsável por desempilhar (retirar) o item da pilha que está atualmente no topo*/
    if(pilhaVazia(P)) {printf("pilha vazia!"); abort();} /*se a pilha estiver vazia, não há nada a se retirar da pilha*/
    int valor = P->item[P->topo]; /*Obtem o valor do item armazenado no topo da pilha*/
    P->topo--; /*decrementa o valor que indica o item que é o topo da pilha*/
    return valor; /*retorna o valor desempilhado*/
}

int topo (Pilha P){ /*Função responsável por descobrir qual é o topo da pilha*/
    if(pilhaVazia(P)) {printf("pilha vazia!"); abort();} /*Se a pilha estiver vazia, não tem topo*/
    return P->item[P->topo]; /*retorna o topo atual da fila*/
}

void destroiPilha(Pilha *P){ /*Função responsável por liberar a memória alocada para os ítens e para a estrutura de controle*/
    free((*P)->item); /*Libera a memória ocupada para os ítens da pilha*/
    free(*P); /*Libera a memória ocupada para os ítens de controle da pilha*/
    *P=NULL; /*Coloca NULL no ponteiro para evitar apontar para uma região desconhecida de memória*/
}

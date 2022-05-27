#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int num;
    struct no *prox;
}no;

void inicia(no *LISTA);/*Inicializa a lista*/
no *criaNo();
void insereInicio(no *LISTA, int num); /*Insere cada novo valor no inicio da lista*/
void exibe(no *LISTA); /*Imprime os valores existentes na lista encadeada */
void libera(no *LISTA); /*Faz a liberação da memória alocada para os nós criados */

no *criaNo(){

    no *L = malloc(sizeof(no));
    if(!L){ /*Testa se nã0 foi possível alocar a quantidade de memória solicitada para um nó*/
        printf("Sem memoria disponivel!\n");
        exit(1);
    }
    return (L);
}

void inicia(no *LISTA) /*Função responsável por inicializar a lista*/
{
    LISTA->prox = NULL;
}

int vazia(no *LISTA) /*Função responsável por verificar se a lista está vazia*/
{
    if(LISTA->prox == NULL)
        return 1;
    else
        return 0;
}

no *aloca(int numero) /*Função utilizada pela insereInicio para alocar um novo nó em memória */
{
    no *novo=malloc(sizeof(no)); /*Cria um novo nó alocando memória a ele*/
    if(!novo){
        printf("Sem memoria disponivel!\n");
        exit(1);
    }else{
         novo->num = numero; /*Coloca o valor informado dentro do campo num existente no novo nó criado*/
        return novo;
    }
}


void insereInicio(no *LISTA, int num) /*Função responsável por alocar memória e inserir um valor no inicio da lista */
{
    no *novo=aloca(num);
    no *oldHead = LISTA->prox;

    LISTA->prox = novo;
    novo->prox = oldHead;
}

void exibe(no *LISTA) /*Função responsável por imprimir os elementos existentes na lista*/
{
    if(vazia(LISTA)){
        printf("Lista vazia!\n\n");
        return ;
    }

    no *tmp;
    tmp = LISTA->prox;

    while( tmp != NULL){
        printf(" %d ", tmp->num);
        tmp = tmp->prox;
    }
 printf("\n\n");
}


void libera(no *LISTA) /*Função responsável por liberar os elementos existentes na lista*/
{
    if(!vazia(LISTA)){
        no *proxNo,
        *atual;

        atual = LISTA->prox;
        while(atual != NULL){
            proxNo = atual->prox;
            free(atual);
                atual = proxNo;
        }
    }
}

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
void libera(no *LISTA); /*Faz a libera��o da mem�ria alocada para os n�s criados */

no *criaNo(){

    no *L = malloc(sizeof(no));
    if(!L){ /*Testa se n�0 foi poss�vel alocar a quantidade de mem�ria solicitada para um n�*/
        printf("Sem memoria disponivel!\n");
        exit(1);
    }
    return (L);
}

void inicia(no *LISTA) /*Fun��o respons�vel por inicializar a lista*/
{
    LISTA->prox = NULL;
}

int vazia(no *LISTA) /*Fun��o respons�vel por verificar se a lista est� vazia*/
{
    if(LISTA->prox == NULL)
        return 1;
    else
        return 0;
}

no *aloca(int numero) /*Fun��o utilizada pela insereInicio para alocar um novo n� em mem�ria */
{
    no *novo=malloc(sizeof(no)); /*Cria um novo n� alocando mem�ria a ele*/
    if(!novo){
        printf("Sem memoria disponivel!\n");
        exit(1);
    }else{
         novo->num = numero; /*Coloca o valor informado dentro do campo num existente no novo n� criado*/
        return novo;
    }
}


void insereInicio(no *LISTA, int num) /*Fun��o respons�vel por alocar mem�ria e inserir um valor no inicio da lista */
{
    no *novo=aloca(num);
    no *oldHead = LISTA->prox;

    LISTA->prox = novo;
    novo->prox = oldHead;
}

void exibe(no *LISTA) /*Fun��o respons�vel por imprimir os elementos existentes na lista*/
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


void libera(no *LISTA) /*Fun��o respons�vel por liberar os elementos existentes na lista*/
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

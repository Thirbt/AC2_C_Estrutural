#include <stdio.h>
#include "Lista.h"
#include "pilha.h"
#include "fila.h"
#include "arv.h"


void main(){

    int valorSwitch = 0;
    int valor, valorOpcao, valorCinco, telaInicial;
    int qtdLista = 0;
    int qtdPilha = 0;
    int qtdFila = 0;
    Pilha P = inicializaPilha(20);
    Fila F = inicializaFila(10);
    no *L = criaNo();
    inicia(L);
    NoArv *A = arv_criavazia();

    do{

    printf("=== Menu Principal ===\n");
    printf("Digite (01) para inserir valores\n");
    printf("Digite (02) para manipular uma pilha\n");
    printf("Digite (03) para manipular uma fila\n");
    printf("Digite (04) para manipular uma lista\n");
    printf("Digite (05) manipular arvore\n");
    printf("======================\n");
    printf("Numero: ");
    scanf("%d", &valorSwitch);

    switch(valorSwitch){

case 1:

    printf("=== CASO 1 ===\n");

    do{

        printf("Digite valores a serem inseridos na estrutura (0 para sair)\n");
        printf("Numero: ");
        scanf("%d", &valor);
        getchar();
        printf("\n");

        if(valor > 0 && valor % 2 == 0){

            empilha(valor, P);
            qtdPilha++;

        }else if(valor > 0 && valor % 2 != 0){

             enfileira(valor, F);
             qtdFila ++;

        }else if(valor < 0){

            insereInicio(L, valor);
            qtdLista++;

        }

    }while(valor != 0);

    printf("%d valores na pilha: ", qtdPilha);
    while(!pilhaVazia(P)){

        printf("%d, ", desempilha(P));

    }

    printf("\n%d Valores da fila: ", qtdFila);
    while(!filaVazia(F)){

    printf("%d, ", desenfileira(F));

    }

    printf("\n %d valores na Lista: ", qtdLista);

    exibe(L);
    free(F);
    free(P);
    free(L);

    break;

case 2:

    printf("=== CASO 2 ===\n");

    do{

    printf("\n(01) para inserir na Pilha, e (02) para remover da Pilha\n");

    scanf("%d", &valorOpcao);

    if(valorOpcao == 2){

    printf("Elemento removido: %d \n",desempilha(P));

    }else if(valorOpcao == 1){

    printf("\nDigite um numero qualquer: ");
    scanf("%d", &valor);
    empilha(valor,P);

    }

    }while(valor != 0);

    break;

case 3:

    printf("=== CASO 3 ===\n");

    do{

    printf("\n(01) para inserir na Fila, e (02) para remover da Fila\n");

    scanf("%d", &valorOpcao);

    if(valorOpcao == 2){

    printf("Elemento removido: %d \n",desenfileira(F));

    }else if(valorOpcao == 1){

    printf("\nDigite um numero qualquer: ");
    scanf("%d", &valor);
    enfileira(valor,F);

    }

    }while(valor != 0 && valorOpcao != 0);

    break;

case 4:

    printf("=== CASO 4 ===\n");


    do{

    printf("\n(01) para inserir na Lista, e (02) para remover da Lista\n");

    scanf("%d", &valorOpcao);

    if(valorOpcao == 2){

    exibe(L);

    }else if(valorOpcao == 1){

    printf("\nDigite um numero qualquer: ");
    scanf("%d", &valor);
    insereInicio(L,valor);

    }

    }while(valor != 0 && valorOpcao != 0);

    break;

case 5:

  do{
  printf("\n=== CASO 5 ===\n");
  printf("Digite (01) para inserir elemento na arvore\n");
  printf("Digite (02) para imprimir os valores em pre-ordem\n");
  printf("Digite (03) para imprimir os valores em ordem\n");
  printf("Digite (04) para os valores em pos-ordem\n");
  printf("==============\n");
  printf("Numero: ");
  scanf("%d", &valorOpcao);
  switch(valorOpcao){
  case 1:
      printf("Digite o elemento a ser inserido na arvore\n");
      printf("Numero: ");
      scanf("%d", &valor);
      A = arv_insere(A, valor);

    break;

  case 2:

      arv_imprimePreOrdem(A);

    break;

  case 3:

      arv_imprimeOrdemSimetrica(A);

    break;

  case 4:

      arv_imprimePosOrdem(A);

    break;

  }

}while(valorOpcao != 0);

printf("Gostaria de sair :\n");
printf("Sim - (01), Não - (02)\n");
scanf("%d", &telaInicial);
if(telaInicial == 1)
     return 0;
}

    }while(telaInicial != 0);

}




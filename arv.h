#include<stdlib.h>

struct noArv{
    int info;
    struct noArv* esq;
    struct noArv* dir;
};
typedef struct noArv NoArv;

//NoArv* arv_criavazia (void);
//NoArv* arv_cria (char c, NoArv* e, NoArv* d);
//NoArv* arv_libera (NoArv* a);
//int arv_vazia (NoArv* a);
//int arv_pertence (NoArv* a, char c);
//void arv_imprime (NoArv* a);
//NoArv* arv_insere (NoArv* a, int v)

NoArv* arv_criavazia (void)
{
 return NULL;
}

NoArv* arv_cria (int v, NoArv* sae, NoArv* sad)
{
 NoArv* p=(NoArv*)malloc(sizeof(NoArv));
 if(p==NULL) exit(1);
 p->info = v;
 p->esq = sae;
 p->dir = sad;
 return p;
}

int arv_vazia (NoArv* a)
{
 return a==NULL;
}

NoArv* arv_libera (NoArv* a){
 if (!arv_vazia(a)){
 arv_libera(a->esq); /* libera sae */
 arv_libera(a->dir); /* libera sad */
 free(a); /* libera raiz */
 }
 return NULL;
}

int arv_pertence (NoArv* a, int v)
{
 if (arv_vazia(a))
 return 0;
 else
 return a->info==v ||
 arv_pertence(a->esq,v) ||
 arv_pertence(a->dir,v);
}

void arv_imprimePreOrdem (NoArv* a)
{
 if (!arv_vazia(a)){
 printf("%d ",a->info); /* mostra raiz */
 arv_imprimePreOrdem(a->esq); /* mostra sae */
 arv_imprimePreOrdem(a->dir); /* mostra sad */
 }
}
void arv_imprimeOrdemSimetrica (NoArv* a)
{
 if (!arv_vazia(a)){
 arv_imprimeOrdemSimetrica(a->esq); /* mostra sae */
 printf("%d ",a->info); /* mostra raiz */
 arv_imprimeOrdemSimetrica(a->dir); /* mostra sad */
 }
}
void arv_imprimePosOrdem (NoArv* a)
{
 if (!arv_vazia(a)){
 arv_imprimePosOrdem(a->esq); /* mostra sae */
 arv_imprimePosOrdem(a->dir); /* mostra sad */
 printf("%d ",a->info); /* mostra raiz */
 }
}

NoArv* arv_insere (NoArv* a, int v)
{
 if(arv_vazia(a)){
     a = arv_cria(v, NULL, NULL);
 }
 else if (v < a->info)
 a->esq = arv_insere(a->esq,v);
 else /* v >= a->info */
 a->dir = arv_insere(a->dir,v);
 return a;
}

NoArv* arv_busca (NoArv* r, int v)
{
 if (r == NULL)
    return NULL;
 else if (r->info > v)
    return arv_busca (r->esq, v);
 else if (r->info < v)
    return arv_busca (r->dir, v);
 else return r;
}







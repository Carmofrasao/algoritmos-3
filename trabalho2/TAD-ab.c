#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"TAD-ab.h"

tNo *inicia (int valor){
//Função para inicialização do nó, com alocação de memória e atribuição de valores para os componentes do nó.
  tNo *n = (tNo *)malloc (sizeof (tNo));
  n->valor = valor;
  n->dir = NULL;
  n->esq = NULL;
  return n;
}

tNo* montaarvore(const char *str, int *i){
//Função que monta uma árvore binária recebendo como entrada uma árvore com parênteses aninhados. Não há suporte a erros de entrada, por isso a árvore passada como parâmetro deve estar correta.
    tNo *no = NULL;
    
  if (str[*i] == '(') {
        (*i)++;
        char val[1024];
        memset(val, 0, sizeof(val));
        int cont = 0;
        int aux = 0;
        
        while((str[*i] != '(') && (str[*i] != ')'))
        {
        	val[cont] = str[*i];
        	cont++;
        	(*i)++;
        }
        aux = atoi(val);
        no = inicia (aux);    
        no -> esq = montaarvore(str, i);
        no -> dir = montaarvore(str, i);            
        (*i)++;
    }
    return no;        
}

void preordem(tNo * no){
//Percurso da árvore em PRÉ-ORDEM.
    if (no !=NULL){
    	printf("(");
    	if (no->valor != 0)
    		printf("%d", no->valor);
        preordem(no->esq);
        preordem(no->dir);
        printf(")");
    }
}


void emordem(tNo * no){  
//Percurso da árvore em ORDEM.  
    if (no !=NULL){
    	printf("(");
        emordem(no->esq);
        if (no->valor != 0)
    		printf("%d", no->valor);
        emordem(no->dir);
        printf(")");
    }
}

void posordem(tNo * no){
//Percurso da árvore em PÓS-ORDEM.
    if (no !=NULL){   
    	printf("("); 
        posordem(no->esq);        
        posordem(no->dir);
        if (no->valor != 0)
    		printf("%d", no->valor);
        printf(")");
    }
}

int contaNos(tNo *no){
//Conta o número de nós da árvore
    if (no!=NULL) {
        return contaNos(no->esq) + contaNos(no->dir) + 1;
    } else
        return 0;
}

int altura (tNo *p) {
//Calcula a altura da árvore. Retorna -1 para considerar a altura da raiz como 0.
    int he, hd;
    if (p == NULL) return -1;
    he = altura (p->esq);
    hd = altura (p->dir);
    if (he > hd)
        return he+1;
    else
        return hd+1;    
}

void limpar(tNo * no)
//Limpa a memoria alocada
{
	if (no == NULL)
		return;
    limpar(no->esq);
    limpar(no->dir);
    free(no);
    no = NULL;
}

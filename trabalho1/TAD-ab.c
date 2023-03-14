//O código abaixo ilustra uma árvore binária, com operações para criação da árvore, criação de nó e percursos.
#include <stdio.h>
#include<stdlib.h>
#include"TAD-ab.h"

//Função para inicialização do nó, com alocação de memória e atribuição de valores para os componentes do nó.
tNo *inicia (char valor){
  tNo *n = (tNo *)calloc (1, sizeof (tNo));
  n->valor = valor;
  n->dir = NULL;
  n->esq = NULL;
  return n;
}

//Função que monta uma árvore binária recebendo como entrada uma árvore com parênteses aninhados. Não há suporte a erros de entrada, por isso a árvore passada como parâmetro deve estar correta.
tNo* montaarvore(const char *str, int *i){
    tNo *no = NULL;
    
	if (str[*i] == '(') {
        (*i)++;
        no = inicia (str[*i]);    
        (*i)++;
        no -> esq = montaarvore(str, i);
        no -> dir = montaarvore(str, i);            
        (*i)++;
    }
    return no;        
}

//Percurso da árvore em PRÉ-ORDEM.
void preordem(tNo * no){
    if (no !=NULL){
    	printf("%c ", no->valor);
        preordem(no->esq);
        preordem(no->dir);
    }
}

//Percurso da árvore em ORDEM.
void emordem(tNo * no){    
    if (no !=NULL){
        emordem(no->esq);
        printf("%c ", no->valor);
        emordem(no->dir);
    }
}

//Percurso da árvore em PÓS-ORDEM.
void posordem(tNo * no){
    if (no !=NULL){    
        posordem(no->esq);        
        posordem(no->dir);
        printf("%c ", no->valor);
    }
}

//Conta o número de nós da árvore
int contaNos(tNo *no){
    if (no!=NULL) {
        return contaNos(no->esq) + contaNos(no->dir) + 1;
    } else
        return 0;
}

//Calcula a altura da árvore. Retorna -1 para considerar a altura da raiz como 0.
int altura (tNo *p) {
    int he, hd;
    if (p == NULL) 
    	return -1;
    he = altura (p->esq);
    hd = altura (p->dir);
    if (he > hd)
        return he+1;
    else
        return hd+1;    
}

//Limpa a memoria alocada
void limpar(tNo * no)
{
	if (no !=NULL){
        limpar(no->esq);
        limpar(no->dir);
        free(no);
    }
}

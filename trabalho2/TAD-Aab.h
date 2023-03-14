#ifndef _TAD_AAB_H
#define _TAD_AAB_H

#include<stdio.h>
#include"TAD-ab.h"

typedef struct DARVORE
{
	tNo* chave;
	struct DARVORE *esq, *dir, *pai;
	int fb;
}DARVORE;

int soma_no(tNo *n);
//funcao para somar os nos da arvore

DARVORE *criaNo (tNo *chave);
//Função para inicialização do nó, com alocação de memória e atribuição de valores para os componentes do nó.

DARVORE *rotEsquerda(DARVORE *p);
//Rotação à esquerda do nó, retorna o novo nó. Tem ponteiro para o pai.

DARVORE *rotDireita(DARVORE *p);
//Rotação à direita do nó, retorna o novo nó. Tem ponteiro para o pai.

int Altura (DARVORE *p);
//Altura da árvore

void ajustaNoPai(DARVORE *no, DARVORE *novo);
//Função para ajustar ponteiro pai da árvore binária, usada na função de exclusão.

DARVORE* ajustaAVL(DARVORE * no, int *calcula_fb);
//Função que ajusta um nó desbalanceado em uma árvore AVL. Um nó está desbalanceado quando a diferença de altura entre a subárvore da direita e da esquerda do nó é maior que 1.

DARVORE* inclui (DARVORE *no, tNo* c, int *calcula_fb);
//Funcão para inclusão de novo nó na árvore AVL, dado um nó raiz.

DARVORE* montaaarvore(tNo **str);
//Função que monta uma árvore binária recebendo como entrada uma árvore com parênteses aninhados. Não há suporte a erros de entrada, por isso a árvore passada como parâmetro deve estar correta.

void visita(tNo * no);
//Operação de visita do nó.

void preorde(DARVORE *no);
//Percurso da árvore em PRÉ-ORDEM

void emorde(DARVORE *no);
//Percurso da árvore em ORDEM.

void posorde(DARVORE * no);
//Percurso da árvore em PÓS-ORDEM.

DARVORE *min(DARVORE *no);
//Função que retorna o nó mínimo de uma sub-árvore. O nó mínimo de uma subárvore é o nó com a menor chave.

DARVORE *sucessor (DARVORE *no);
//Função que retorna o nó sucessor de um determinado nó. 

DARVORE *busca(DARVORE *no, int chave);
//Busca em árvore binária.

DARVORE *ajustaFBPai(DARVORE *p);
//Ajusta fator de balanceamento do pai.

DARVORE* exclusao (DARVORE *no, DARVORE *raiz);
//Função que exclui um nó da árvore AVL.

void limpa(DARVORE * n);
//funcao para free

#endif

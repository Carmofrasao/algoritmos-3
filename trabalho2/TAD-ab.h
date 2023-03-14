#ifndef _TAD_AB_H
#define _TAD_AB_H

typedef struct tNo
{
  int valor; // pode ser modificado paraqualquer tipo de dado
  struct tNo *esq, *dir;
}tNo;

tNo *inicia (int valor);
//Função para inicialização do nó, com alocação de memória e atribuição de valores para os componentes do nó.

tNo* montaarvore(const char *str, int *i);
//Função que monta uma árvore binária recebendo como entrada uma árvore com parênteses aninhados. Não há suporte a erros de entrada, por isso a árvore passada como parâmetro deve estar correta.

void preordem(tNo * no);
//Percurso da árvore em PRÉ-ORDEM.

void emordem(tNo * no);
//Percurso da árvore em ORDEM.

void posordem(tNo * no);
//Percurso da árvore em PÓS-ORDEM.

int contaNos(tNo *no);
//Conta o número de nós da árvore

int altura (tNo *p);
//Calcula a altura da árvore. Retorna -1 para considerar a altura da raiz como 0.

void limpar(tNo * no);
//Limpa a memoria alocada

#endif

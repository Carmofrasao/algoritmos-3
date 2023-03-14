#ifndef _TAD_AB_
#define _TAD_AB_

//Estrutura para uma árvore binária simples.
typedef struct tNo {
  char valor; // pode ser modificado paraqualquer tipo de dado
  struct tNo *esq, *dir;
} tNo;

tNo *inicia (char valor);

tNo* montaarvore(const char *str, int *i);

void preordem(tNo * no);

void emordem(tNo * no);

void posordem(tNo * no);

int contaNos(tNo *no);

int altura (tNo *p);

void limpar(tNo * no);
#endif

#include<stdio.h>
#include<stdlib.h> 
#include"TAD-Aab.h"

int soma_no(tNo *n)
//funcao para somar os nos da arvore
{
	if ((n->dir != NULL) || (n->esq != NULL)){
		int esq = 0;
		int dir = 0;
		if(n->dir != NULL)
			dir = soma_no(n->dir);
		if(n->esq != NULL)
			esq = soma_no(n->esq);
		return n->valor + esq + dir;
    }
    else
    {
    	if(n == NULL)
    		return 0;
    	else
    		return n->valor;
    }
}

DARVORE *criaNo (tNo *chave)
//Função para inicialização do nó, com alocação de memória e atribuição de valores para os componentes do nó.
{
  DARVORE *n = (DARVORE *)malloc (sizeof (DARVORE));
  n->chave = chave;
  n->esq = NULL;
  n->dir = NULL;
  n->pai = NULL; 
  n->fb = 0;
  return n;
}

DARVORE *rotEsquerda(DARVORE *p){
//Rotação à esquerda do nó, retorna o novo nó. Tem ponteiro para o pai.
    DARVORE *q = p->dir;
    p->dir = q->esq;
    q->pai = p->pai;
    p->pai = q;
    if (q->esq != NULL)
        q->esq->pai = p;
    q->esq = p;
    return q;
}

DARVORE *rotDireita(DARVORE *p){
//Rotação à direita do nó, retorna o novo nó. Tem ponteiro para o pai.
    DARVORE *q = p->esq;
    p->esq = q->dir;
    q->pai = p->pai;
    p->pai = q;
    if (q->dir != NULL)
        q->dir->pai = p;
    q->dir = p;
    return q;
}

int Altura (DARVORE *p) {
//Altura da árvore
    int he, hd;
    if (p == NULL) return -1;
    he = Altura (p->esq);
    hd = Altura (p->dir);
    if (he > hd)
        return he+1;
    else
        return hd+1;    
}

void ajustaNoPai(DARVORE *no, DARVORE *novo)
//Função para ajustar ponteiro pai da árvore binária, usada na função de exclusão.
{
    if (no->pai != NULL) 
    {
        if (no->pai->esq == no)
            no->pai->esq = novo;
        else
            no->pai->dir = novo;
        if (novo != NULL)
           novo->pai = no->pai;
    }
}

DARVORE* ajustaAVL(DARVORE * no, int *calcula_fb){
//Função que ajusta um nó desbalanceado em uma árvore AVL. Um nó está desbalanceado quando a diferença de altura entre a subárvore da direita e da esquerda do nó é maior que 1.
    DARVORE *noAjuste;//, *pai = no->pai;
    if (no->fb == -2) { //desbalanceado na  esquerda
        if (no->esq != NULL && no->esq->fb > 0) {
            no->esq = rotEsquerda(no->esq);
        } 
        noAjuste = rotDireita(no);        
    } else {        
        if (no->dir->fb < 0){
            no->dir = rotDireita(no->dir);
        }
        noAjuste = rotEsquerda(no);
        
    }
    if (noAjuste->pai != NULL){
        if (noAjuste->pai->esq == no)
            noAjuste->pai->esq = noAjuste;
        else
            noAjuste->pai->dir = noAjuste;  
    }
    noAjuste->fb = 0;
    noAjuste->esq->fb = (Altura(noAjuste->esq->dir) - Altura(noAjuste->esq->esq));
    noAjuste->dir->fb = (Altura(noAjuste->dir->dir) - Altura(noAjuste->dir->esq));
    *calcula_fb = 0;
    return noAjuste;
}

DARVORE* inclui (DARVORE *no, tNo* c, int *calcula_fb){
//Funcão para inclusão de novo nó na árvore AVL, dado um nó raiz.
    if (no == NULL) {
        no = criaNo(c);        
        (*calcula_fb) = 1;
        return no;    
    }
    if (soma_no(c) < soma_no(no->chave)){
        no->esq = inclui(no->esq, c, calcula_fb);
        no->esq->pai = no;
        if (*calcula_fb) no->fb --;
    }
    else {
        no->dir = inclui(no->dir, c, calcula_fb);
        no->dir->pai = no;
        if (*calcula_fb) no->fb ++;
    }
    if (*calcula_fb){
        if (no->fb == 0) *calcula_fb = 0;
    }
    return no;
}

DARVORE* montaaarvore(tNo **str){
//Função que monta uma árvore binária recebendo como entrada uma árvore com parênteses aninhados. Não há suporte a erros de entrada, por isso a árvore passada como parâmetro deve estar correta.
    DARVORE *raiz = NULL;
    int i = 0, calcula_fb = 0;
    while (str[i]!=NULL){
        raiz = inclui (raiz, str[i], &calcula_fb);
        i++;                
    }
    return raiz;        
}

void visita(tNo * no)
//Operação de visita do nó.
{
	preordem(no);
    printf(": %d\n", soma_no(no));
}

void preorde(DARVORE *no)
//Percurso da árvore em PRÉ-ORDEM
{
	printf("[");
    if ((no != NULL) && (no->chave != NULL))
    {
        visita(no->chave);
        preorde(no->esq);
        preorde(no->dir);
    }
    printf("\n]");
}

void emorde(DARVORE *no)
//Percurso da árvore em ORDEM.
{   
    printf("[");
    if ((no != NULL) && (no->chave != NULL))
    {
        emorde(no->esq);
        visita(no->chave);
        emorde(no->dir);
    }
    printf("\n]");
}


void posorde(DARVORE * no)
//Percurso da árvore em PÓS-ORDEM.
{
	printf("[");
    if ((no != NULL) && (no->chave != NULL)){    
        posorde(no->esq);        
        posorde(no->dir);
        visita(no->chave);
    }
    printf("\n]");
}

DARVORE *min(DARVORE *no)
//Função que retorna o nó mínimo de uma sub-árvore. O nó mínimo de uma subárvore é o nó com a menor chave.
{
    if (no->esq == NULL) 
    	return no;
    else
        return min(no->esq);
}

DARVORE *sucessor (DARVORE *no)
//Função que retorna o nó sucessor de um determinado nó.
{
    DARVORE *s = NULL;
    if (no->dir != NULL) 
    	return min (no->dir);
    else 
    {
        s = no->pai;
        while (s != NULL && no == s->dir) 
        {
            no = s;
            s = s->pai;
        }        
    }
    return s;
}

DARVORE *busca(DARVORE *no, int chave)
//Busca em árvore binária.
{
	while ((no != NULL) && (soma_no(no->chave) != chave))
	{
        if (chave < soma_no(no->chave))
            no = no->esq;
        else
            no = no->dir;
    }
    return no;
}

DARVORE *ajustaFBPai(DARVORE *p){
//Ajusta fator de balanceamento do pai.
    DARVORE *no = p;
    while (no->pai != NULL && no->fb != -2 && no->fb != 2){
        if (no->pai->esq == no)
            no->pai->fb++;
        else
            no->pai->fb--;
        no = no->pai;
    }
    return no;
}

DARVORE* exclusao (DARVORE *no, DARVORE *raiz) {
//Função que exclui um nó da árvore AVL.
    DARVORE *s, *novaRaiz = raiz;
    if (no == NULL) return NULL;    
    if (no->esq == NULL && no->dir == NULL) { //nó folha
        if (no == raiz) {//exclusao da raiz em árvore com 1 nó
            limpar(no->chave);
            no->chave = NULL;
            raiz = NULL;
            free(raiz);
            return NULL;
        }
        if (no->pai->esq == no)
            no->pai->fb++;
        else
            no->pai->fb--;           
        ajustaNoPai(no,NULL);
        limpar(no->chave);
        free(no);     
        no = NULL; 
    } else {
        if (no->esq == NULL){ // nó com 1 filho direito
            ajustaNoPai(no, no->dir);
            if (no->pai == NULL) novaRaiz = no->dir;
            limpar(no->chave);
            no->chave = no->dir->chave;
            free(no->dir);
            no->dir = NULL;
        } else {
            if (no->dir == NULL){ //nó com 1 filho esquerdo
                ajustaNoPai(no, no->esq);
                if (no->pai == NULL) novaRaiz = no->esq;
                limpar(no->chave);
                no->chave = no->esq->chave;
                free(no->esq);
                no->esq = NULL;
            }
            else {            //nó com 2 filhos
                int ultimoSucessor;
                s = sucessor (no);
                ultimoSucessor = s->esq == NULL && s->dir == NULL;
                ajustaNoPai(s, s->dir);
                s->esq = no->esq;
                s->dir = no->dir;
                s->fb = no->fb;
                ajustaNoPai(no, s);   
                s->esq->pai = s;                       
                if (ultimoSucessor) {//ultimo sucessor
                    s->fb --;
                } else
                    s->dir->pai = s;
                if (no == raiz) {
                    novaRaiz = s;
                    s->pai = NULL; //verificar essa linha. já deveria ser NULL
                }
                limpar(no->chave);
                free(no);
                no = NULL;
            }
        }
    } 
    return novaRaiz;
}

void limpa(DARVORE * n)
//funcao para free
{
	if (n == NULL)
		return;
    limpa(n->esq);
    limpa(n->dir);
    limpar(n->chave);
    n->chave = NULL;
    free(n);
    n = NULL;
}

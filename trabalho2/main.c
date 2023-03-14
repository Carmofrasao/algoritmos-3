#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"TAD-ab.h"
#include"TAD-Aab.h"

void imprime_busca(DARVORE *no, tNo* no_aux)
//funcao para imprimir as arvore encontradas na busca
{
    while ((no != NULL) && (soma_no(no->chave) != soma_no(no_aux)))
	{
        if (soma_no(no_aux) < soma_no(no->chave))
        {
        	visita(no->chave);
            no = no->esq;
        }
        else
        {
        	visita(no->chave);
            no = no->dir;
    	}
    }
    visita(no->chave);
}

void insercao(DARVORE **arv, char *cod, int *i, char *str, FILE *entrada)
//funcao para inserir arvores
{
	int k = 0;
	printf("inserindo!\n\n");
    while((*cod != EOF) && (*cod == 'i'))
    {
    	*arv = inclui (*arv, montaarvore(str, i), &k);
   		
   		memset(str, 0, sizeof(*str));
   		*i = 0;
   		*cod = '\0';
   		
   		*cod = fgetc(entrada);
   		fgetc(entrada);
    	fgets(str, 1024, entrada);
    	preorde(*arv);
    	printf("\n\n");
    }
}

void buscar(DARVORE **arv, char *cod, int *i, char *str, FILE *entrada)
{
	printf("\nbuscando!\n\n");
	tNo* aux = NULL;
	while((*cod != EOF) && (*cod == 'b'))
   	{
   		aux = montaarvore(str ,i);
   		
   		if (((aux != NULL) && (busca(*arv, soma_no(aux)) != NULL)))
   		{
   			imprime_busca(*arv, aux);
   			printf("\n");
   		}
   		else if (busca(*arv, soma_no(aux)) == NULL)
   		{
   			printf("Arvore não encontrada\n\n");
   		}
   		
   		limpar(aux);
   		aux = NULL;
   		memset(str, 0, sizeof(*str));
   		*i = 0;
   		*cod = '\0';
   		
   		*cod = fgetc(entrada);
   		fgetc(entrada);
    	fgets(str, 1024, entrada);
   	}
}

void remover(DARVORE **arv, char *cod, int *i, char *str, FILE *entrada, tNo *n)
{
	printf("\nremovendo!\n\n");
   	while((*cod != EOF) && (*cod == 'r'))
   	{
   		n=montaarvore(str ,i);
   		
   		exclusao (busca(*arv, soma_no(n)), *arv);
   		limpar(n);
   		
   		memset(str, 0, sizeof(*str));
   		*i = 0;
   		*cod = '\0';
   		n = NULL;
   		
   		*cod = fgetc(entrada);
   		fgetc(entrada);
    	fgets(str, 1024, entrada);  		
   		preorde(*arv);
   		printf("\n\n");
   	}
}

void iniciaprograma(int argc, char** argv){
//funcao geral
    tNo *n = NULL; 
    DARVORE *arv = NULL;
    char cod = '\0';
    int i = 0;
    
    char str[1024];
    memset(str, 0, sizeof(str));
    FILE *entrada = NULL;
    
    if (argc > 1)
    {
    	entrada = fopen(argv[1], "r");
    }
    else
    {
    	entrada = stdin;
    }
    if ( ! entrada )
  	{
		perror ("Erro ao abrir arquivo") ;
		exit (1) ;
	}
	
    cod = fgetc(entrada);
    fgetc(entrada);
    fgets(str, 1024, entrada);
    
    insercao(&arv, &cod, &i, str, entrada);
    //funcao para inserir arvores
    
   	buscar(&arv, &cod, &i, str, entrada);
    //funcao para buscar arvores
    
   	remover(&arv, &cod, &i, str, entrada, n);
   	//funcao para remover arvore	
   	
    limpa(arv);
    
   	fclose(entrada);
}

int main(int argc, char **argv)
{
	iniciaprograma(argc, argv);
}

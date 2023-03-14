#include<stdio.h>
#include<string.h>
#include"TAD-ab.h"

int calcula(tNo *no)
{
    if(strcmp(&no->valor, "*") == 0)
    {
    	int dir = calcula(no->esq);
    	int esq = calcula(no->dir);
    	printf("%d * %d\n", esq, dir);
    	return esq * dir;
    }
    else if(strcmp(&no->valor, "/") == 0)
    {
    	int dir = calcula(no->dir);
    	int esq = calcula(no->esq);
    	printf("%d / %d\n", esq, dir);
    	return esq / dir;
    }
    else if(strcmp(&no->valor, "-") == 0)
    {
    	int dir = calcula(no->dir);
    	int esq = calcula(no->esq);
    	printf("%d - %d\n", esq, dir);
    	return esq - dir;
    }
    else if(strcmp(&no->valor, "+") == 0)
    {
    	int dir = calcula(no->dir);
    	int esq = calcula(no->esq);
    	printf("%d + %d\n", esq, dir);
    	return esq + dir;
    }
    else
    	return no->valor-48;
}

void iniciaprograma(){
     tNo *n = NULL; 
    int i = 0;
    i=0;   
    char str[1024];
    scanf("%s", str);
    printf("\n");
    n=montaarvore(str, &i);
    int resul = calcula(n);
    printf("%d\n", resul);
	limpar(n);
}

int main()
{
	printf("Digite a expressão aritimética.\n");
	iniciaprograma();
}

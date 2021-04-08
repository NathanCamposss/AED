#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "prototipo.h"



int main(void)
{
    Aluno *a, *alunos, *aux=&a;
    int tam=0,*t=&tam, mat,r;

    
    tamanho(t);
    a=(Aluno*) malloc((tam+1)*sizeof(Aluno));
    pegaLista(a,t);
    imprimir(a,tam);
    
    
    free(a);
    
     
    


    
    
}
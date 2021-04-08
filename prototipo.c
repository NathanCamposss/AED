#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "prototipo.h"




int main(void)
{
    Aluno *a;
    int tam=0;

    
    tamanho(&tam);
    a=(Aluno*) malloc((tam+2)*sizeof(Aluno));
    
    cadastrar(&a[tam], tam, a);
    tam++;
    a=(Aluno*) realloc(a,(tam+2)*sizeof(Aluno));
    cadastrar(&a[tam], tam, a);
    salvaLista(a,tam+1);
    
    
    free(a);
    
     
    


    
    
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "prototipo.h"

#define FALHA 0
#define SUCESSO 1


int main(void)

{
     char texto[] = "SISTEMA DE DADOS MATRICULAR E AVERIGUACAO DE SITUACAO ACADEMICA";
                char texto1[] = "-INSTITUTO DE EDUCACAO-";//Passar por referencia dentro da funçaõ cadastra aluno, para colocar o nome o instituto
                char texto2[] = "BEM-VINDO";
                char campo[76];

                printf("%s\n\n", centralizarTexto(campo, sizeof campo, texto));
                printf("%s\n\n", centralizarTexto(campo, sizeof campo, texto1));
                printf("%s\n\n", centralizarTexto(campo, sizeof campo, texto2));
                printf("%s\n\n", centralizarTexto(campo, sizeof campo, "----------------------------------------------------"));


    //INTERRFACE

    Aluno *a, *aux;
    int tam=0, entrada, usuario, matricula, r;
    tamanho(&tam);

    a=(Aluno*) malloc((tam+2)*sizeof(Aluno));
    pegaLista(a,&tam);

    printf("ENTRAR COMO:\n1-DISCENTE\n2-ADMINISTRADOR DA PLATAFORMA\n3-SAIR\n");
    scanf("%d", &usuario);


    while(usuario!=3)
    {
        switch(usuario)
        {
            case 1:

            printf("INFORME A MATRICULA QUE DESEJA CONSULTAR: ");

            scanf("%d", &matricula);
            r=consultaMatricula(a,tam,matricula);

                if(r==FALHA)
                    printf("MATRICULA NAO ENCONTRADA, VOLTANDO PARA O MENU DE ENTRADA\n\n");

            break;

            case 2:

            printf("INFORME A OPERACAO QUE DESEJA FAZER\n1-CADASTRAR ALUNO\n2-REMOVER ALUNO\n3-MUDAR UM ALUNO DE DISCIPLINA\n");

            scanf("%d", &entrada);

            switch(entrada)
            {
                case 1:

                    aux=&a[tam];
                    cadastrar(aux,tam,a);
                    tam++;
                    a=(Aluno*) realloc(a,(tam+2)*sizeof(Aluno));

                break;

                case 2:

                printf("INFORME O NUMERO DE MATRICULA: ");
                scanf("%d", &matricula);
                r=removeAluno(a,matricula, tam);
                    if(r==FALHA)
                    {
                        printf("MATRICULA NAO ENCONTRADA, RETORNANDO AO MENU DE ENTRADA\n\n");
                    }
                        if(r==SUCESSO)
                        {
                        tam--;
                        a=(Aluno*) realloc(a,(tam+2)*sizeof(Aluno));

                }
                break;

                case 3:

                    alteraMateria(a,tam);

                break;

                default:

                    printf("OPERACAO NAO EXISTENTE, VOLTANDO AO MENU DE ENTRADA\n\n");

                break;
            }

        }

        printf("INFORME QUE TIPO DE USUARIO VOCE E OU SE DESEJA SAIR:\n1-ALUNO\n2-FUNCIONARIO DA INSTITUICAO DE ENSINO\n3-SAIR\n");
        scanf("%d", &usuario);
    }
    salvaLista(a, tam);
    free(a);

     printf("\nFIM DE SESSAO\n");
        return 0;

}
    

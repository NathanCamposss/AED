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
                char texto1[] = "-INSTITUTO DE EDUCACAO-";//Passar por referencia dentro da funÃ§aÃµ cadastra aluno, para colocar o nome o instituto
                char texto2[] = "BEM-VINDO";
                char campo[76];

                printf("%s\n\n", centralizarTexto(campo, sizeof campo, texto));
                printf("%s\n\n", centralizarTexto(campo, sizeof campo, texto1));
                printf("%s\n\n", centralizarTexto(campo, sizeof campo, texto2));
                printf("%s\n\n", centralizarTexto(campo, sizeof campo, "----------------------------------------------------"));


    //INTERRFACE

    Aluno *a, *aux;
    int tam=0, entrada, usuario, matricula, r, muda=0, permissao, bloqueio=0;

    tamanho(&tam);

    if(tam!=0)
    {
    a=(Aluno*) malloc((tam+2)*sizeof(Aluno));
    pegaLista(a,tam);
    }
    if(tam==0)
    {
        a=(Aluno*) malloc(2*sizeof(Aluno));

    }

    //printf("%s\n", a[0].nome);

    printf("ENTRAR COMO:\n1-DISCENTE\n2-ADMINISTRADOR DA PLATAFORMA\n3-SAIR\n");
    scanf("%d", &usuario);

    while(usuario!=3)
    {
        limpaTela();

        switch(usuario)
        {
            case 1:

            printf("\nINFORME A MATRICULA QUE DESEJA CONSULTAR: ");

            scanf("%d", &matricula);
            r=consultaMatricula(a,tam,matricula);

                if(r==FALHA)
                    printf("MATRICULA NAO ENCONTRADA, VOLTANDO PARA O MENU DE ENTRADA\n\n");

            break;

            case 2:
            permissao=entradaDocente();
            if(permissao==FALHA)
            {
                bloqueio++;
                if(bloqueio==3)
                {
                    limpaTela();
                    printf("LIMITE DE TENTATIVAS UTILIZADO, BLOQUEANDO/ENCERRANDO SESSAO\n");
                    return 0;
                }
                break;
            }

            if(permissao==SUCESSO)
            {
                bloqueio=0;
                entrada=1;

            while(entrada<=5 && entrada>=1)
            {
            printf("\nINFORME A OPERACAO QUE DESEJA FAZER\n1-CADASTRAR ALUNO\n2-REMOVER ALUNO\n3-MUDAR UM ALUNO DE DISCIPLINA\n4-ALTERAR MEDIA DE UM ALUNO\n5-VER LISTA DE TODOS OS ALUNOS DA INSTITUICAO\n6-SAIR\n");

            scanf("%d", &entrada);

            switch(entrada)
            {
                case 1:

                    //aux=&a[tam];
                    cadastrar(a,tam,a);
                    tam++;
                    a=(Aluno*) realloc(a,(tam+2)*sizeof(Aluno));

                break;

                case 2:

                printf("\nINFORME O NUMERO DE MATRICULA: ");
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

                printf("\nINFORME O NUMERO DE MATRICULA: ");
                scanf("%d", &matricula);
                r=procuraMatricula(a,tam,matricula);
                    if(r==FALHA)
                    {
                        printf("MATRICULA NAO ENCONTRADA, RETORNANDO AO MENU DE ENTRADA\n\n");
                    }


                    alteraMateria(a,tam,matricula);

                break;

                case 4:
                printf("\nINFORME O NUMERO DE MATRICULA: ");
                scanf("%d", &matricula);
                r=procuraMatricula(a,tam,matricula);
                if(r==FALHA)
                {
                    printf("\nMATRICULA NAO ENCONTRADA, VOLTANDO AO MENU PRINCIPAL\n");
                }

                if(r==SUCESSO)
                {
                    arrumaMedia(a,matricula);
                }

                break;

                case 5:
                imprimir(a,tam);
                break;

                case 6:
                printf("\nRETORNANDO AO MENU PRINCIPAL\n");
                break;

                default:

                    printf("OPERACAO NAO EXISTENTE, VOLTANDO AO MENU DE ENTRADA\n\n");

                break;
            }
            }
            }

        }

        printf("\nINFORME QUE TIPO DE USUARIO VOCE E OU SE DESEJA SAIR:\n1-ALUNO\n2-ADMINISTRADOR DA PLATAFORMA\n3-SAIR\n");
        scanf("%d", &usuario);
    }

    salvaLista(a, tam);
    free(a);

    limpaTela();

     printf("---------------------\nFIM DE SESSAO\n");
        return 0;

}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "prototipo.h"

#define FALHA 0
#define SUCESSO 1

int main(void)

{

    int comandoUsuario=0;

    while(comandoUsuario!=3){

                char texto[] = "SISTEMA DE DADOS MATRICULAR E AVERIGUACAO DE SITUACAO ACADEMICA";
                char texto1[] = "-INSTITUTO DE EDUCACAO-";//Passar por referencia dentro da funçaõ cadastra aluno, para colocar o nome o instituto
                char texto2[] = "BEM-VINDO";
                char campo[76];

                printf("%s\n\n", centralizarTexto(campo, sizeof campo, texto));
                printf("%s\n\n", centralizarTexto(campo, sizeof campo, texto1));
                printf("%s\n\n", centralizarTexto(campo, sizeof campo, texto2));
                printf("%s\n\n", centralizarTexto(campo, sizeof campo, "----------------------------------------------------"));

                //INTERRFACE

            printf("Escolha a opcao numerica de entrada:\n");
            printf("1 - ENTRAR COMO DISCENTE\n");
            printf("2 - ENTRAR COMO ADMINISTRADOR\n");
            printf("3 - ENCERRAR SESSAO\n");
            scanf("%d", &comandoUsuario);

        switch(comandoUsuario)
        {
            int comandoAluno=0;
            int comandoProfessor=0;
            Aluno *a;
            Aluno al[1000];
            int tam=0;
            int matricula=0;

            tamanho(&tam);

            a=(Aluno*) malloc((tam+2)*sizeof(Aluno));
            al=(Aluno*) malloc((tam+2)*sizeof(Aluno));

        case 1://Caso Aluno

            printf("1 - CONSUTAR MATRICULA\n");
            printf("2 - CONSULTAR SITUACAO ACADEMICA\n");
            printf("3 - VISUALIZAR MEDIA\n");

                scanf("%d", &comandoAluno);

                    if(comandoAluno==1)
                    {
                        printf("Infome o numero da martricula:");
                        scanf("%d", &matricula);

                        if(procuraMatricula( a, tam, matricula)==1)
                        {
                            printf("Matricula encontrada!\n");
                        } else
                        {
                            printf("Matricula nao encontrada!\n");
                        }
                    }
                    if(comandoAluno==2)
                    {
                        printf("Infome o numero da martricula:");
                        scanf("%d", &matricula);
                        consultaMatricula(a, tam, matricula);
                    }
                    if(comandoAluno==3)
                    {
                        consultaMedia(&a);
                    }




            break;

        case 2://Caso Professor

            printf("1 - CADATRAR ALUNO\n");
            printf("2 - REMOVER ALUNO\n");
            printf("2 - REMOVER ALUNO\n");

                scanf("%d", &comandoProfessor);

                    if(comandoProfessor==1)
                    {
                        cadastrar(&a, tam, a1[tam]);
                        tam++;
                    }
                    if(comandoProfessor==2)
                    {
                        printf("Infome o numero da martricula:");
                        scanf("%d", &matricula);

                        removeAluno(&a, matricula, tam);

                    if(comandoProfessor==3)
                    {

                    }

            break;
        }
    }

        printf("\nFIM DE SESSAO\n");
        return 0;

}
    

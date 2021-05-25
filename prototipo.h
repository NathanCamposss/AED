#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define FALHA 0
#define SUCESSO 1

typedef struct horarios_materias
{
    char disciplina[5][4];
    char horarios[5][4][10];


}HORARIOS_MATERIAS;

typedef struct ALUNOS
{
    char nome[50];
    int matricula;
    double media[5];
    HORARIOS_MATERIAS dis_hr;
}Aluno;

void limpaTela();

int entradaDocente();

int removeAluno(Aluno *a, int matricula, int tam);

void arrumaHorarios(Aluno *a, char mate[4]);

void limpaHorario(Aluno *a);

int procuraMatricula(Aluno a[], int tam, int matricula);

int procuraNome(Aluno a[], int tam, char nome[50]);

int procuraMateria( Aluno *a, int tam, char mat[4]);

void cadastrar( Aluno *a, int tam, Aluno a1[tam]);

void arrumaMedia(Aluno *a, int martricula);

void salvaLista(Aluno *a, int tam);

void tamanho(int *tam);

void pegaLista(Aluno *a, int tam);

void alteraMateria(Aluno *a, int tam, int matricula);

void imprimir(Aluno *a, int tam);

int consultaMatricula(Aluno a[], int tam, int matricula);

void consultaMedia(Aluno a);

void imprimiHorarios(Aluno a);

const char *centralizarTexto(char *field, unsigned int fieldWidth, const char *text);



/*================================================================================================
==================================================================================================*/



void limpaTela()
{
    system("cls");
}

int removeAluno(Aluno *a, int matricula, int tam)
{
    int i, j, x, y, cod=0, aux=0, c=0;

    for(i=0;i<=tam;i++)
    {
        if(a[i].matricula==matricula)
        {
            c=1;
            for(j=i;j<=tam;j++)
            {
                strcpy(a[j].nome,a[j+1].nome);
                a[j].matricula=a[j+1].matricula;
                for(x=0;x<5;x++)
                {
                     a[j].media[x]=a[j+1].media[x];

                }

                for(x=0;x<5;x++)
                {
                    strcpy(a[j].dis_hr.disciplina[x],a[j+1].dis_hr.disciplina[x]);
                    for(y=0;y<4;y++)
                    {
                        strcpy(a[j].dis_hr.horarios[x][y],a[j+1].dis_hr.horarios[x][y]);

                    }
                }

            }
        }

    }
    if(c==0)
    return FALHA;

    for(i=0;i<=tam;i++)
    {
        if(a[i].matricula==matricula)
        {
            cod=1;
        }

    }

    if(cod==0)
    {
    return SUCESSO;
    }
    if(cod==1)
    {
    return FALHA;
    }

}

void arrumaHorarios(Aluno *a, char mate[4])
{
    if(strcmp(mate,"AED")==0)
    {
        strcpy(a->dis_hr.horarios[3][0],"18:50-AED");
        strcpy(a->dis_hr.horarios[3][1],"19:35-AED");
        strcpy(a->dis_hr.horarios[3][2],"20:30-AED");
        strcpy(a->dis_hr.horarios[3][3],"21:15-AED");
    }

    if(strcmp(mate,"LM")==0)
    {
        strcpy(a->dis_hr.horarios[1][0],"18:50-LM");
        strcpy(a->dis_hr.horarios[1][1],"19:35-LM");
        strcpy(a->dis_hr.horarios[1][2],"20:30-LM");
        strcpy(a->dis_hr.horarios[1][3],"21:15-LM");

    }

    if(strcmp(mate,"AC")==0)
    {
        strcpy(a->dis_hr.horarios[4][0],"18:50-AC");
        strcpy(a->dis_hr.horarios[4][1],"19:35-AC");
        strcpy(a->dis_hr.horarios[4][2],"20:30-AC");
        strcpy(a->dis_hr.horarios[4][3],"21:15-AC");

    }
    if(strcmp(mate,"AL")==0)
    {
        strcpy(a->dis_hr.horarios[0][2],"20:30-AL");
        strcpy(a->dis_hr.horarios[0][3],"21:15-AL");
        strcpy(a->dis_hr.horarios[2][2],"20:30-AL");
        strcpy(a->dis_hr.horarios[2][3],"21:15-AL");

    }
    if(strcmp(mate,"PE")==0)
    {
        strcpy(a->dis_hr.horarios[0][0],"18:50-PE");
        strcpy(a->dis_hr.horarios[0][1],"19:35-PE");
        strcpy(a->dis_hr.horarios[2][0],"18:50-PE");
        strcpy(a->dis_hr.horarios[2][1],"19:35-PE");

    }


}

void limpaHorario(Aluno *a)
{
    int i, y;
     for(i=0;i<5;i++)
    {
        for(y=0;y<4;y++)
        {
        strcpy(a->dis_hr.horarios[i][y],"--");
        }
    }
}

int procuraMatricula(Aluno a[], int tam, int matricula)
{
    int i;
    for(i=0;i<tam;i++)
    {
        if(matricula==a[i].matricula)
        {

        return 1;
        }
    }
    return 0;
}

int procuraNome(Aluno a[], int tam, char nome[50])
{
    int i;
    for(i=0;i<tam;i++)
    {
        if(strcmp(nome,a[i].nome)==0)
        return 1;
    }
    return 0;
}

int procuraMateria( Aluno *a, int tam, char mat[4])
{
    int i;
    for(i=0;i<tam;i++)
    {
        if(strcmp(a->dis_hr.disciplina[i],mat)==0)
        {
        return 1;
        }
    }
    return 0;

}
void cadastrar( Aluno *a, int tam, Aluno a1[tam])
{

    int mat,i,y, r=0, cod=1;
    char j[4];

    printf("\nInforme o nome completo do aluno: ");
    scanf(" %[^\n]s", a[tam].nome);
    if(tam!=0)
    {
    r=procuraNome(a1,tam,a[tam].nome);
    while(r==1)
    {
        printf("Nome ja cadastrado, tente outro nome: ");
        scanf(" %[^\n]s", a[tam].nome);
        r=procuraNome(a1,tam,a[tam].nome);
    }
    }
    r=0;

    printf("Informe o numero de matricula: ");
    scanf("%d", &a[tam].matricula);
    if(tam!=0)
    {
     r=procuraMatricula(a,tam,a[tam].matricula);
     while(r==1)
    {
        printf("Matricula ja cadastrada, tente outro numero de matricula: ");
        scanf(" %d", &a[tam].matricula);
        r=procuraMatricula(a,tam,a[tam].matricula);
    }
    }
    printf("Informe em quantas das 5 materias o aluno esta cadastrado: ");
    scanf("%d", &mat);
    while(mat<1 || mat>5)
    {
        printf("Valor invalido, tente novamente: ");
        scanf("%d", &mat);
    }
    limpaHorario(a);
    for(i=0;i<5;i++)
    {
        strcpy(a[tam].dis_hr.disciplina[i],"-");
    }
    printf("\n");
    r=0;

    for(i=0;i<mat;i++)
    {

        printf("Informe qual a materia esta matriculado:\nAlgoritmo e Estrutura de Dados(AED)\nLogica Matematica(LM)\nProbabilidade e Estatistica(PE)\nArquitetura de Computadores(AC)\nAlgebra Linear(AL)\n");
        scanf(" %s", j);
        r=procuraMateria(&a[tam],cod,j);
        while((strcmp(j,"AED")!=0 && strcmp(j,"LM")!=0 && strcmp(j,"AC")!=0 && strcmp(j,"PE")!=0 && strcmp(j,"AL")!=0) || r==1)
        {
            printf("Materia invalida, tente novamente: ");
            scanf(" %s", j);
            r=procuraMateria(&a[tam],cod,j);

        }
        printf("\n");
        cod++;
        strcpy(a[tam].dis_hr.disciplina[i],j);
        arrumaHorarios(a,j);
    }



    for(i=0;i<mat;i++)
    {
        printf("Informe a media da materia de %s: ", a[tam].dis_hr.disciplina[i]);
        scanf("%lf", &a[tam].media[i]);
        if(a[tam].media[i]<0 || a[tam].media[i]>10)
        {
            printf("Numero invalido, tente novamente: ");
            scanf("%lf", &a[tam].media[i]);
        }
    }
    if(mat<5)
    for(i=mat;i<5;i++)
    {
        a[tam].media[i]=-1;
    }

}

void arrumaMedia(Aluno *a, int matricula)
{

    int i=0, r, max=0, ind=0;
    while(a[ind].matricula!=matricula)
    {
        if(a[ind].matricula!=matricula)
        ind++;

    }

    double d;
    printf("Informe o numero da disciplina cuja media precisa ser modificada\n");
    while(i<5 || i>=0)
    {
        printf("%d - %s\n",i+1,a[ind].dis_hr.disciplina[i]);
        max++;
        i++;
        if(strcmp(a[ind].dis_hr.disciplina[i],"-")==0)
        break;

    }
    scanf("%d", &r);
    while(r>max || r<1)
    {
        printf("Numero invalido, tente novamente: ");
        scanf("%d", &r);

    }
    printf("Informe o valor da nova media: ");
    scanf("%lf", &d);
    while(d<0 || d>10)
    {
        printf("Nota invalida, tente novamente: ");
        scanf("%lf", &d);
    }
    a[ind].media[r-1]=d;
}

void salvaLista(Aluno *a, int tam)
{
    int i, j;
    FILE *f;

    f=fopen("Alunos.txt", "w");
    for(i=0;i<tam;i++)
    {

        fprintf(f,"%s %d ", a[i].nome, a[i].matricula);
        for(j=0;j<5;j++)
        {
            if(strcmp(a[i].dis_hr.disciplina[j],"-")!=0)
            fprintf(f,"%s ", a[i].dis_hr.disciplina[j]);
        }
        for(j=0;j<5;j++)
        {
            if(a[i].media[j]!=-1)
            {
                fprintf(f,"%.2lf ", a[i].media[j]);
            }
        }

        fprintf(f,"\n");

    }
    fclose(f);
}

void tamanho(int *tam)
{
    FILE *f;
    char c;
    f=fopen("Alunos.txt","r");
    if(f!=NULL)
    {
    while(!feof(f))
    {
        c=getc(f);
        if(c=='\n')
        {
            *tam=*tam+1;
        }
    }
    }
    else
    *tam=0;
    fclose(f);
}

void pegaLista(Aluno *a, int tam)
{
    FILE *f;

    char c, char_aux[100];
    int j, i=0, x, len, y;

    f=fopen("Alunos.txt","r");


    for(i=0;i<tam;i++)
    {
        for(y=0;y<5;y++)
        {
            strcpy(a[i].dis_hr.disciplina[y],"-");
            a[i].media[y]=-1;
        }
    }

    for(i=0;i<tam;i++)
    {
        strcpy(a[i].nome,"");
        while(1)
        {
            fscanf(f," %s", char_aux);

            if(isalpha(char_aux[0]))
            {
                strcat(a[i].nome,char_aux);
                strcat(a[i].nome," ");

            }
            if(isdigit(char_aux[0]))
            {
                len=strlen(char_aux);
                fseek(f,-len,SEEK_CUR);
                fscanf(f,"%d", &a[i].matricula);
                break;

            }
        }
        j=0;
        strcpy(char_aux,"-");

        while(1)
        {
            fscanf(f," %s", char_aux);
            if(isalpha(char_aux[0]))
            {
                strcpy(a[i].dis_hr.disciplina[j],char_aux);
                j++;

            }
            if(isdigit(char_aux[0]))
            {
                len=strlen(char_aux);
                fseek(f,-len,SEEK_CUR);
                for(y=0;y<j;y++)
                {
                    fscanf(f, "%lf", &a[i].media[y]);
                }
                break;
            }

        }



    }
    fclose(f);
    for(i=0;i<tam;i++)
    {
        for(j=0;j<5;j++)
        {
            for(y=0;y<4;y++)
            {
            strcpy(a[i].dis_hr.horarios[j][y],"--");
            }
        }
    }
    Aluno *aux;

    for(i=0;i<tam;i++)
    {
        aux=&a[i];
        for(j=0;j<5;j++)
        {
            if(strcmp(a[i].dis_hr.disciplina[j],"-")!=0)
            {
                arrumaHorarios(aux,a[i].dis_hr.disciplina[j]);
            }
        }
    }





}

void alteraMateria(Aluno *a, int tam, int matr)
{
    int r, i, ind, cod, tamM=0, resp;
    char j[4];

    for(i=0;i<tam;i++)
    {
        if(a[i].matricula==matr)
        {
            ind=i;
            break;
        }

    }
    printf("Informe o que deseja fazer:\n1-Alterar o cadastro de uma das disciplinas e cadastrar em outra materia\n2-Se cadastrar em uma nova materia\n");
    scanf("%d", &cod);
    while(cod!=2 && cod!=1)
    {
        printf("Operacao invalida, tente novamente: ");
        scanf("%d", &cod);

    }
    if(cod==1)
    {
    printf("Escolha a materia que deseja modificar:\n");
    for(i=0;i<5;i++)
    {
        if(a[ind].media[i]!=-1)
        {
            printf("%d - %s\n", i+1, a[ind].dis_hr.disciplina[i]);
            tamM++;
        }


    }

    scanf("%d", &resp);
    while(resp<=0 || resp>tamM)
    {
        printf("Operacao invalida, tente novamente: ");
        scanf("%d", &resp);

    }
    printf("Informe em qual a materia esta matriculado:\nAlgoritmo e Estrutura de Dados(AED)\nLogica Matematica(LM)\nProbabilidade e Estatistica(PE)\nArquitetura de Computadores(AC)\nAlgebra Linear(AL)\n");
        scanf(" %s", j);
        r=procuraMateria(&a[ind],tamM,j);
        while((strcmp(j,"AED")!=0 && strcmp(j,"LM")!=0 && strcmp(j,"AC")!=0 && strcmp(j,"PE")!=0 && strcmp(j,"AL")!=0) || r==1)
        {
            printf("Materia invalido, tente novamente: ");
            scanf(" %s", j);
            r=procuraMateria(&a[ind],tamM,j);

        }
        strcpy(a[ind].dis_hr.disciplina[resp-1], j);
        limpaHorario(a);
        for(i=0;i<tamM;i++)
        {
            arrumaHorarios(a,a[ind].dis_hr.disciplina[i]);
        }
        printf("Informe a media da nova materia: ");
        scanf("%lf", &a[ind].media[resp-1]);
    }
    if(cod==2)
    {
        for(i=0;i<5;i++)
        {
            if(a[ind].media[i]!=-1)
            tamM++;
        }
        if(tamM==5)
        {
            printf("O aluno ja esta matriculado em todas as disciplinas, impossivel cadastrar em outra materia\n");
            return ;
        }


        for(i=0;i<5;i++)
        {
            if(a[ind].media[i]==-1)
            {
                printf("Informe em qual a materia esta matriculado:\nAlgoritmo e Estrutura de Dados(AED)\nLogica Matematica(LM)\nProbabilidade e Estatistica(PE)\nArquitetura de Computadores(AC)\nAlgebra Linear(AL)\n");
                scanf(" %s", j);
                r=procuraMateria(&a[ind],tamM,j);
                while((strcmp(j,"AED")!=0 && strcmp(j,"LM")!=0 && strcmp(j,"AC")!=0 && strcmp(j,"PE")!=0 && strcmp(j,"AL")!=0) || r==1)
                {
                    printf("Valor invalido, tente novamente: ");
                    scanf(" %s", j);
                    r=procuraMateria(&a[ind],tamM,j);

                }
                printf("Informe a media da nova disciplina cadastrada: ");
                scanf("%lf", &a[ind].media[i]);
                while(a[ind].media[i]<0 || a[ind].media[i]>10)
                {
                    printf("Nota invalida, tente novamente: ");
                    scanf("%lf", &a[ind].media[i]);

                }
                strcpy(a[ind].dis_hr.disciplina[tamM], j);
                arrumaHorarios(a,a[ind].dis_hr.disciplina[tamM]);
                break;

            }
        }
    }
}

void imprimir(Aluno *a, int tam)
{
    int i, j, x;
    printf("\n----------------------------------------------------\n");
    for(i=0;i<tam;i++)
    {
    printf("Nome: %s\nMatricula: %d\n",a[i].nome, a[i].matricula);
    printf("Materias e medias:\n");
    for(j=0;j<5;j++)
    {
        if(a[i].media[j]!=-1)
        {
            printf("%s - %.2lf\n", a[i].dis_hr.disciplina[j], a[i].media[j]);
        }

    }

    //imprimiHorarios(a[i]);
    printf("----------------------------------------------------\n");

    }
}

int consultaMatricula(Aluno a[], int tam, int matricula)
{
    int i, cod=0, ind, r;
    for(i=0;i<tam;i++)
    {
        if(a[i].matricula==matricula)
        {
            cod=1;
            ind=i;
        }
    }
    if(cod==0)
    {
    return FALHA;
    }
    printf("\nInforme o que deseja consultar:\n1-Media\n2-Disciplinas\n3-Horarios\n4-Sair\n");
    scanf("%d", &r);
    while(r<1 || r>4)
    {
        printf("Operacao invalida, tente novamente: ");
        scanf("%d", &r);
    }
    while(r!=4)
    {
        if(r==1)
        {
            consultaMedia(a[ind]);

        }
        if(r==2)
        {
            printf("\nVoce esta matriculado nas seguintes disciplinas:\n");
            for(i=0;i<5;i++)
            {
                if(strcmp(a[ind].dis_hr.disciplina[i],"AED")==0)
                {
                    printf("Algoritmo e Estrutura de Dados\n");
                }
                if(strcmp(a[ind].dis_hr.disciplina[i],"AC")==0)
                {
                    printf("Arquitetura de Computadores\n");
                }

                if(strcmp(a[ind].dis_hr.disciplina[i],"LM")==0)
                {
                    printf("Logica Matematica\n");
                }

                if(strcmp(a[ind].dis_hr.disciplina[i],"AL")==0)
                {
                    printf("Algebra Linear\n");
                }

                if(strcmp(a[ind].dis_hr.disciplina[i],"PE")==0)
                {
                    printf("Probabilidade e Estatistica\n");
                }

            }

        }
        if(r==3)
        {
            imprimiHorarios(a[ind]);

        }

        printf("\nInforme o que deseja consultar:\n1-Media\n2-Disciplinas\n3-Horarios\n4-Sair\n");
        scanf("%d", &r);
        while(r<1 || r>4)
        {
        printf("Operacao invalida, tente novamente: ");
        scanf("%d", &r);
        }



    }

}

void consultaMedia(Aluno a)
{
    int i, r, x=0;
    printf("\nInforme qual media deseja ver:\n");
    for(i=0;i<5;i++)
    {
        if(strcmp(a.dis_hr.disciplina[i],"-")!=0)
        {
            x++;
            printf("%d - media de %s\n",i+1,a.dis_hr.disciplina[i]);
        }
    }
    scanf("%d", &r);
    while(r<0 || r>x)
    {
        printf("Invalido, tente novamente: ");
        scanf("%d", &r);
    }

    printf("A sua media em %s e %.2lf\n",a.dis_hr.disciplina[r-1], a.media[r-1]);
    if(a.media[r-1]<6)
    {
        printf("Situacao academica atual: REPROVADO\n");
    }

    else
    {
        printf("Situacao academica atual: APROVADO\n");
    }
}

void imprimiHorarios(Aluno a)
{
    int x, j;
    printf("\nHorarios:\n");
    for(j=0;j<5;j++)
    {
        if(j==0)
        printf("Segunda-Feira\n");
        if(j==1)
        printf("Terca-Feira\n");
        if(j==2)
        printf("Quarta-Feira\n");
        if(j==3)
        printf("Quinta-Feira\n");
        if(j==4)
        printf("Sexta-Feira\n");
        for(x=0;x<4;x++)
        {
            printf("%s\n",a.dis_hr.horarios[j][x]);
        }

    }
}

const char *centralizarTexto(char *field, unsigned int fieldWidth, const char *text)
{
    if (fieldWidth == 0 || field == NULL) return "";

    fieldWidth--;
    unsigned int len = strlen(text);
    unsigned int padding = fieldWidth > len ? (fieldWidth+1 - len)/2 : 0;
    sprintf(field, "%*s%.*s%*s", padding, "", fieldWidth-1, text, padding>0 && len%2!=fieldWidth%2 ? padding-1 : padding, "");

    return (const char *)field;
}

int entradaDocente()
{
    char l1[10][3], l2[10][3], l3[10][3],a='a', b='z', c='A', d='Z', e='M', f='n';
    char respos[3][7], escolha[7];
    strcpy(escolha,"");

    int i, j, r;
    for(i=0;i<10;i++)
    {
        strcpy(l1[i],"");
        strcpy(l2[i],"");
        strcpy(l3[i],"");

    }

    for(i=0;i<10;i++)
    {

        l1[i][0]=a;
        l1[i][1]=b;
        l1[i][2]='\0';
        a++;
        b--;
        l2[i][0]=d;
        l2[i][1]=c;
        l2[i][2]='\0';
        c++;
        d--;

        l3[i][0]=e;
        l3[i][1]=f;
        l3[i][2]='\0';
        f++;
        e--;
    }

    strcpy(respos[0],l1[2]);
    strcat(respos[0],l2[0]);
    strcat(respos[0],l3[4]);

    strcpy(respos[1],l1[5]);
    strcat(respos[1],l2[7]);
    strcat(respos[1],l3[1]);

    strcpy(respos[2],l1[9]);
    strcat(respos[2],l2[9]);
    strcat(respos[2],l3[8]);

    printf("PARA ENTRAR COMO ADM, SELECIONE AS PARTES DE SUA SENHA\nINFORME O NUMERO DA PRIMEIRA PARTE\n");
    for(i=0;i<10;i++)
    {
        printf("%d - %s\n", i+1, l1[i]);

    }
    scanf("%d", &r);
    if(r<1 || r>10)
    {
        printf("INVALIDO, ENTRADA NEGADA\n");
        return FALHA;
    }
    strcat(escolha,l1[r-1]);
    printf("\nINFORME A SEGUNDA PARTE\n");
    for(i=0;i<10;i++)
    {
        printf("%d - %s\n", i+1, l2[i]);

    }
    scanf("%d", &r);
    if(r<1 || r>10)
    {
        printf("INVALIDO, ENTRADA NEGADA\n");
        return FALHA;
    }
    strcat(escolha,l2[r-1]);

    printf("\nINFORME A TERCEIRA PARTE\n");
    for(i=0;i<10;i++)
    {
        printf("%d - %s\n", i+1, l3[i]);

    }
    scanf("%d", &r);
    if(r<1 || r>10)
    {
        printf("INVALIDO, ENTRADA NEGADA\n");
        return FALHA;
    }
    strcat(escolha,l3[r-1]);

    if(strcmp(escolha,respos[0])==0 || strcmp(escolha,respos[1])==0 || strcmp(escolha,respos[2])==0)
    {
        printf("ENTRADA PERMITIDA, ENTRANDO COMO ADM\n");
        return SUCESSO;
    }
    else
    {
        printf("ENTRADA NEGADA, VOLTANDO AO MENU\n");
        return FALHA;
    }



}

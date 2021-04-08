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

int removeAluno(Aluno *a, int matricula, int tam)
{
    int i, j, x, y, cod=0, aux=0, c=0;
    
    for(i=0;i<tam;i++)
    {
        if(a[i].matricula==matricula)
        {
            c=1;
            for(j=i;j<tam;j++)
            {
                strcpy(a[j].nome,a[j+1].nome);
                a[j].matricula=a[j+1].matricula;
                for(x=0;x<5;x++)
                {
                     a[j].media[x]=a[j+1].media[x];

                }
                
                for(x=0;x<5;x++)
                {
                    strcpy(a[j].dis_hr.disciplina[x],a[j+1].dis_hr.disciplina);
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

    for(i=0;i<tam;i++)
    {
        if(a[i].matricula==matricula)
        {
            cod=1;
        }

    }

    if(cod=0)
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
        return 1;
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
void cadastrar( Aluno *a, int tam, Aluno a1[tam])
{
    
    int mat,i,y, r=0;
    char j[4];
    
    printf("Informe o nome completo do aluno: ");
    scanf(" %[^\n]s", a->nome);
    r=procuraNome(a1,tam,a->nome);
    while(r==1)
    {
        printf("Nome ja cadastrado, tente outro nome: ");
        scanf(" %[^\n]s", a->nome);
        r=procuraNome(a1,tam,a->nome);
    }
    r=0;

    printf("Informe o numero de matricula: ");
    scanf("%d", &a->matricula);
     r=procuraMatricula(a1,tam,a->matricula);
     while(r==1)
    {
        printf("Matricula ja cadastrada, tente outro numero de matricula: ");
        scanf(" %d", &a->matricula);
        r=procuraMatricula(a1,tam,a->matricula);
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
        strcpy(a->dis_hr.disciplina[i],"-");
    }
    printf("\n");

    for(i=0;i<mat;i++)
    {
        
        printf("Informe qual a materia esta matriculado:\nAlgoritmo e Estrutura de Dados(AED)\nLogica Matematica(LM)\nProbabilidade e Estatistica(PE)\nArquitetura de Computadores(AC)\nAlgebra Linear(AL)\n");
        scanf(" %s", j);
        while(strcmp(j,"AED")!=0 && strcmp(j,"LM")!=0 && strcmp(j,"AC")!=0 && strcmp(j,"PE")!=0 && strcmp(j,"AL")!=0)
        {
            printf("Valor invalido, tente novamente: ");
            scanf(" %s", j);

        }
        printf("\n");
        strcpy(a->dis_hr.disciplina[i],j);
        arrumaHorarios(a,j);
    }
    
        

    for(i=0;i<mat;i++)
    {
        printf("Informe a media da materia de %s: ", a->dis_hr.disciplina[i]);
        scanf("%lf", &a->media[i]);
        if(a->media[i]<0 || a->media[i]>10)
        {
            printf("Numero invalido, tente novamente: ");
            scanf("%lf", &a->media[i]);
        }
    }
    if(mat<5)
    for(i=mat;i<5;i++)
    {
        a->media[i]=-1;
    }

}

void arrumaMedia(Aluno *a)
{
    
    int i=0, r;
    double d;
    printf("Informe o numero da disciplina cuja media precisa ser modificada\n");
    while(i<5 || i<1)
    {
        printf("%d - %s\n",i+1,a->dis_hr.disciplina[i]);
        i++;
        if(strcmp(a->dis_hr.disciplina[i],"-")==0)
        break;
    }
    scanf("%d", &r);
    printf("Informe o valor da nova media: ");
    scanf("%lf", &d);
    a->media[r-1]=d;
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

void pegaLista(Aluno *a, int *tam)
{
    FILE *f;
    
    char c, char_aux[100];
    int j, i=0, x, len, y;
    
    f=fopen("Alunos.txt","r");

    
    for(i=0;i<*tam;i++)
    {
        for(y=0;y<5;y++)
        {
            strcpy(a[i].dis_hr.disciplina[y],"-");
            a[i].media[y]=-1;
        }
    }
    
    for(i=0;i<*tam;i++)
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
    for(i=0;i<*tam;i++)
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

    for(i=0;i<*tam;i++)
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

void imprimir(Aluno *a, int tam)
{
    int i, j, x;
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

    imprimiHorarios(a[i]);
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
    printf("Informe o que deseja consultar:\n1-Media\n2-Disciplinas\n3-Horarios\n4-Sair\n");
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
            printf("Voce esta matriculado nas seguintes disciplinas:\n");
            for(i=0;i<5;i++)
            {
                if(strcmp(a[ind].dis_hr.disciplina[i],"-")!=0)
                {
                    printf("%s\n",a[ind].dis_hr.disciplina[i]);
                }

            }

        }
        if(r==3)
        {
            imprimiHorarios(a[ind]);

        }
        printf("Informe o que deseja consultar:\n1-Media\n2-Disciplinas\n3-Horarios\n4-Sair\n");
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
    printf("Informe qual media deseja ver:\n");
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
}

void imprimiHorarios(Aluno a)
{
    int x, j;
    printf("Horarios:\n");
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
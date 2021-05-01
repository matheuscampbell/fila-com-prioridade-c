#include "fila.h"
#include "fila.c"
int main()
{
    Fila FILA;
    new_fila(&FILA);
    int op;
    char os[1];
    do{
       op = menu();
       if(op == 1){
        cabecalho();
        cadastrarPessoa(&FILA);
       }else if(op == 2){
           cabecalho();
           print_fila(&FILA);
           printf("\n\n\t Digite 1 para voltar ao menu\n\tDigite 0 para sair do programa\nSua Escolha: ");
           scanf("%d",&op);
       }else if(op == 3){
            cabecalho();
            printf("================================== Selecione Abaixo uma Opcao=======================================\n");
            printf("\t\t1-Fase 1\n");
            printf("\t\t2-Fase 2\n");
            printf("\t\t3-Fase 3\n\n");
            printf("\t\t4-Fase 4\n\n");
            printf("\tSua opcao: ");
            scanf("%d",&op);
            cabecalho();
            print_fila_by_fase(&FILA, op);
            printf("\n\n\t Digite 1 para voltar ao menu\n\tDigite 0 para sair do programa\nSua Escolha: ");
            scanf("%d",&op);
       }
    }while(op !=0);
    printf("\a");
    return 0;
}



void cadastrarPessoa(Fila *f){
    char nome[100];
    int idade;
    int fase = 0;
    int op;
    Pessoa p;
    printf("==============================================\n");
    printf("============ Cadastro de Pasciente ===========\n");
    printf("Nome: ");
    scanf("%s",&nome);
    printf("Profissao:\n\t 1-Profissional da Saude\n\t 2-Outros\nSua Resposta: ");
    fflush(stdin);
    scanf("%d",&op);
    fflush(stdin);
    if(op == 1){
        fase = 1;
        p.prof_saude = 1;
    }else{
        p.prof_saude = 2;
    }
    printf("Idade: ");
    scanf("%d",&idade);
    fflush(stdin);
    if(idade < 60){
        if(fase == 0){
            printf("Possui alguma Comorbidade?\n\t 1- Sim \n\t 2-Nao\nSua Resposta: ");
            scanf("%d",&op);
            fflush(stdin);
            if(op == 1){
                fase = 3;
            }else{
                fase = 4;
            }
        }
    }else{
        if(idade >= 75){
            fase = 1;
        }
        if(fase == 0){
            fase = 2;
        }
    }
    strcpy(p.nome, nome);
    p.idade = idade;
    p.fase = fase;
    enqueue(f, p);
}

int menu(){

        int op=0;
        cabecalho();
        printf("================================== Selecione Abaixo uma Opcao=======================================\n");
        printf("\t\t1-Cadastrar Pasciente\n");
        printf("\t\t2-Listar Todos Pascientes\n");
        printf("\t\t3-Listar Pascientes Por Fase\n\n");
        printf("\t\t0-Sair\n\n");
        printf("\tSua opcao: ");
        scanf("%d",&op);
        if(op == 0){
                cabecalho();
                printf("==================================  Realmente deseja Sair?   =======================================\n");
                printf("\t\t0-Sim, Sair.\n\n");
                printf("\t\t1-Nao\n\n");
                printf("\tSua opcao: ");
                scanf("%d",&op);
                system("cls");
        if(op == 0){
            return 0;
        }else{
            menu();
        }
        }else{
            return op;
        }
}

void cabecalho(){
    system("cls");
     printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||            |||||||||||||||||||||||||||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||            |||||||||||||||||||||||||||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||            |||||||||||||||||||||||||||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||            |||||||||||||||||||||||||||\n");
        printf("|||||||||||||||||       ||    ||||  |       |||||                                   ||||||||||||||||\n");
        printf("||||||||||||||||    ||||||    ||||  |    ||||||||                                   ||||||||||||||||\n");
        printf("|||||||||||||||||        |    ||||  |        ||||                                   ||||||||||||||||\n");
        printf("|||||||||||||||||||||    |    ||||  ||||||   ||||                                   ||||||||||||||||\n");
        printf("||||||||||||||||        |||         ||       ||||                                   ||||||||||||||||\n");
        printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||             |||||||||||||||||||||||||||\n");
        printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||             |||||||||||||||||||||||||||\n");
        printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||             |||||||||||||||||||||||||||\n");
        printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||             |||||||||||||||||||||||||||\n");
        printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("====================================================================================================\n");
}

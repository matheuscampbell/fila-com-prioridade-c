#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int primeiro, ultimo;
int MAXTAM = 10;
primeiro = 0;
ultimo = 0;
typedef struct pessoa{
    char nome[25];
    int idade;
    int prioridade;
}pessoa;

pessoa array[10+1];
//Variaveis globais

void start(){
primeiro = ultimo = 0;
}

void mover(int i){
    for(pessoa a = array[i],aux;i!=ultimo;i++){
        aux = array[i+1];
        array[i+1] = a;
        a = aux;
    }
    //move a fila a partir da posicao recebida como parametro
}

void inserir_prioridade_1(pessoa x){
int i;
for(i=primeiro;i!=ultimo;i++){
    if(array[i].prioridade > 1)
        break;
}
//encontra o local correto para insersao da pessoa

mover(i);

//chama funcao que move a fila para incercao da nova pessoa
array[i] = x;

//coloca pessoa no lugar adequado na fila
}

void inserir_prioridade_2(pessoa x){
int i;
for(i=primeiro;i!=ultimo;i++){
    if(array[i].prioridade > 2)
        break;
}
//encontra o local correto para insersao da pessoa

mover(i);

//chama funcao que move a fila para incercao da nova pessoa
array[i] = x;

//coloca pessoa no lugar adequado na fila
}

void inserir_prioridade_3(pessoa x){
int i;
for(i=primeiro;i!=ultimo;i++){
    if(array[i].prioridade > 3)
        break;
}
//encontra o local correto para insersao da pessoa

mover(i);

//chama funcao que move a fila para incercao da nova pessoa
array[i] = x;

//coloca pessoa no lugar adequado na fila
}

void inserir_prioridade_4(pessoa x){
int i;
for(i=primeiro;i!=ultimo;i++){
    if(array[i].prioridade > 4)
        break;
}
//encontra o local correto para insersao da pessoa

mover(i);

//chama funcao que move a fila para incercao da nova pessoa
array[i] = x;

//coloca pessoa no lugar adequado na fila
}

void inserir_sem_prioridade(pessoa x) {
array[ultimo] = x;
}

void inserir(pessoa x) {
if (((ultimo + 1) % MAXTAM) == primeiro)
exit(1);
//Sai caso a fila esteja cheia
if(x.prioridade == 1)
    inserir_prioridade_1(x);
if(x.prioridade == 2)
    inserir_prioridade_2(x);
if(x.prioridade == 3)
    inserir_prioridade_3(x);
if(x.prioridade == 4)
    inserir_prioridade_4(x);
if(x.prioridade == 5)
    inserir_sem_prioridade(x);
//chama a funcao adequada para o tipo de prioridade da pessoa
ultimo = (ultimo + 1) % MAXTAM;
//acressenta uma unidade a "ultimo" de forma circular com a fila
}

pessoa remover() {
if (primeiro == ultimo)
exit(1);
pessoa resp = array[primeiro];
primeiro = (primeiro + 1) % MAXTAM;
return resp;
}

void mostrar_prioridade(int p){
    bool existe = false;
    int i = primeiro;
    system("cls");
    printf("Fase %d:\n\n",p);
    while (i != ultimo) {
        if(array[i].prioridade==p){
            printf("%s",array[i].nome);
            existe = true;
        }
        i = ((i + 1) % MAXTAM);
    }
    //imprime apenas os paciente do numero da fase recebido como parametro
    if(!existe)
        printf("Nao ha mais pacientes nessa fase a serem vacinados\n");
    //imprime essa mensagem caso nao haja mais pacientes na faze

}

void mostrar_fase (){
    int opc;
    system("cls");
    printf("[1]Listar primeira fase   [2]Listar segunda fase   [3]Listar terceira fase   [4]Listar quarta fase   [5]Listar quinta fase(pacientes sem prioridade)\n");
    scanf("%d",&opc);
    mostrar_prioridade(opc);
}

void mostrar (){
int i = primeiro;
while (i != ultimo) {
printf("%s",array[i].nome);
i = ((i + 1) % MAXTAM);
}
//imprime todos os registros da fila
}

pessoa completar(){
    int aux;
    pessoa ativo;
    printf("Digite o nome:  ");
    fgets(ativo.nome,25,stdin);
    //coleta o nome
    printf("Digite a idade:  ");
    scanf("%d",&ativo.idade);
    //coleta a idade
    if(ativo.idade>74){
        ativo.prioridade = 1;
        return ativo;
    }
    //Atribui nivel de proioridade 1 e retorna caso a pessoa tenha mais de 74 anos
    //////////////////////////////////////////////////////////////////////////////
    printf("Eh profissional da saude?\n[1]S [2]N :");
    scanf("%d",&aux);
    if(aux==1){
        ativo.prioridade = 1;
        return ativo;
    }
    //Atribui nivel de proioridade 1 e retorna caso a pessoa seja profissonal da saude
    //////////////////////////////////////////////////////////////////////////////////
     if(ativo.idade>59){
        ativo.prioridade = 2;
        return ativo;
    }
    //Atribui nivel de proioridade 2 e retorna caso pessoa tenha mais de 59 anos
    ////////////////////////////////////////////////////////////////////////////
    printf("Possui alguma comorbidade?\n[1]S [2]N :");
    scanf("%d",&aux);
    if(aux==1){
        ativo.prioridade = 3;
        return ativo;
    }
    //Atribui nivel de proioridade 3 e retorna caso pessoa tenha comorbidades
    /////////////////////////////////////////////////////////////////////////
     printf("Realiza servico essencial?\n[1]S [2]N :");
    scanf("%d",&aux);
    if(aux==1){
        ativo.prioridade = 4;
        return ativo;
    }
    //Atribui nivel de proioridade 4 e retorna caso pessoa realize servico essencial
    ////////////////////////////////////////////////////////////////////////////////
        ativo.prioridade = 5;
        return ativo;
    //Retorna com nivel de prioridade 5 e retorna caso a pessoa nao seja de nunhum grupo prioritario
}

void main(){

    int opc;
    start();
    system("color 02");
    while(opc != 5){
    system("cls");
    printf("[1]Inserir novo paciente a fila   [2]Remover paciente da fila   [3]Mostrar fila completa  [4]Mostrar fila por fase   [5]Sair\n");
    scanf("%d",&opc);
    getchar();
    system("cls");
    switch (opc)
    {
    
    case 1:
        inserir(completar());


        break;
    
    case 2:
        
        remover();
        
        break;
    
    case 3:
        mostrar();
        system("pause");
        break;
    case 4:
        mostrar_fase();
        system("pause");
        break;
    default:
        break;
    }
    }








}

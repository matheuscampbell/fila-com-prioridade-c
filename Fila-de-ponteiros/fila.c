#include "fila.h"
//========================================
void print_pessoa(Pessoa p){
  printf("{nome: %s, idade: %d, fase: %d}\n", p.nome, p.idade, p.fase);
}
//========================================
Celula *new_celula(){
  Celula *tmp = (Celula*) malloc(sizeof(Celula));
  tmp->prox = NULL;
  return tmp;
}
//========================================
void new_fila(Fila *f){

  Celula *nova = new_celula();

  f->inicio = nova;
  f->fim = nova;
  f->tam = 0;
}
//========================================
void enqueue(Fila *f, Pessoa dado){

  Celula *nova = new_celula();
  nova->dado = dado;

  if(dado.fase < 4 && size_fila(f) > 0) {
    Celula *ant = f->inicio;
    Celula *tmp = f->inicio->prox;
    while(tmp!=NULL && ((tmp->dado.fase <= dado.fase && tmp->dado.idade >= dado.idade ) || (tmp->dado.prof_saude != dado.prof_saude ))){
      ant = ant->prox;
      tmp = tmp->prox;
    }
    nova->prox = tmp;
    ant->prox = nova;
    f->tam++;
    if(tmp == NULL){
      f->fim = nova;
    }
  }else{
    f->fim->prox = nova;
    f->fim = nova;
    f->tam++;
  }
}


void print_fila_by_fase(Fila *f, int fase){
    Celula *tmp = f->inicio->prox;
    while(tmp != NULL){
        if(tmp->dado.fase == fase){
            print_pessoa(tmp->dado);
        }
        tmp = tmp->prox;
    }

}

//========================================
void print_fila(Fila *f){
  Celula *tmp = f->inicio->prox;
  while(tmp != NULL){
    print_pessoa(tmp->dado);
    tmp = tmp->prox;
  }
}
//========================================
int size_fila(Fila *f){
  return f->tam;
}
//========================================

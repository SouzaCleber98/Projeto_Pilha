#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "pilha.h"

// Variáveis
char pl_pilha_string[TAMANHO][TAMANHO_STRING];
double pl_pilha_double[TAMANHO];
int pl_posicao_string = 0; 
int pl_posicao_double = 0;

// Funções
bool push_string(char *valor) {
    if (pl_posicao_string == TAMANHO) {
        return false; // Pilha de strings cheia
    }
    strcpy(pl_pilha_string[pl_posicao_string], valor);
    pl_posicao_string++;
    return true;
}

bool push_double(double valor) {
    if (pl_posicao_double == TAMANHO) {
        return false; // Pilha de doubles cheia
    }
    pl_pilha_double[pl_posicao_double] = valor;
    pl_posicao_double++;
    return true;
}

bool pop_string(char *valor) {
    if (pl_posicao_string == 0) {
        return false; // Pilha de strings vazia
    }
    pl_posicao_string--;
    strcpy(valor, pl_pilha_string[pl_posicao_string]);
    return true;
}

bool pop_double(double *valor) {
    if (pl_posicao_double == 0) {
        return false; // Pilha de doubles vazia
    }
    pl_posicao_double--;
    *valor = pl_pilha_double[pl_posicao_double];
    return true;
}

bool estaCheia_string() {
    return pl_posicao_string == TAMANHO;
}

bool estaCheia_double() {
    return pl_posicao_double == TAMANHO;
}

bool estaVazia_string() {
    return pl_posicao_string == 0;
}

bool estaVazia_double() {
    return pl_posicao_double == 0;
}

void imprimir_string() {
    printf("Pilha de strings:\n");
    for (int i = pl_posicao_string - 1; i >= 0; i--) {
        printf("| %s |\n", pl_pilha_string[i]);
    }
    printf("+---+\n");
}

void imprimir_double() {
    printf("Pilha de doubles:\n");
    for (int i = pl_posicao_double - 1; i >= 0; i--) {
        printf("| %.2f |\n", pl_pilha_double[i]);
    }
    printf("+------+\n");
}
char pilhatopo_string()
{
  if (estaVazia_string()){
    return 'N';
  }
  else
  {
return pl_pilha_string[pl_posicao_string - 1][0];
}
}
double pilhatopo_double()
{
  if (estaVazia_double())
  {
    return 0;
  }
  else{
  return pl_pilha_double[pl_posicao_double - 1];
}
}
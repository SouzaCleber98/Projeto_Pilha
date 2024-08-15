// pilha.h
#ifndef PILHA_H
#define PILHA_H

#include <stdbool.h>
#include <string.h>
// Constantes
enum { 
TAMANHO = 20, 
TAMANHO_STRING = 2 };

// Variáveis
extern char pl_pilha_string[TAMANHO][TAMANHO_STRING];
extern double pl_pilha_double[TAMANHO];
extern int pl_posicao_string;
extern int pl_posicao_double;

// Protótipos
bool push_string(char *valor);
bool pop_string(char *valor);
bool estaCheia_string();
bool estaVazia_string();
void imprimir_string();
bool push_double(double valor);
bool pop_double(double *valor);
bool estaCheia_double();
bool estaVazia_double();
void imprimir_double();
char pilhatopo_string();
double pilhatopo_double();

#endif // PILHA_H

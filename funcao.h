#ifndef FUNCAO_H
#define FUNCAO_H
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
void stringParaVetor(char *line, char vec[][20], int tamanho);
int tamanhoString(char entrada[]);
bool precedencia(char op1);
bool find(char letra, char *str);
void resolverEquacao(char entrada[][20]);
#endif // FUNCAO_H

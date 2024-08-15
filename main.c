#include <stdio.h>
#include "pilha.h"
#include "funcao.h"

// Constantes



// Variáveis


int main() {

  char exp[100] = "";
  char vec[100][20] = {'\0'};


  
  strcpy(exp,"(((22+3)*2+25-43)/2)");

  stringParaVetor(exp, vec, TAMANHO);

  for(int i = 0; i < 100 && (strcmp(vec[i], "") !=  0); i++)
  {
      printf("%s\n", vec[i]);
  }
  resolverEquacao(vec);

  printf ("O resultado é %.2lf",pilhatopo_double());

 

  return 0;
}





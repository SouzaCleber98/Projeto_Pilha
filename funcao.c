
#include <stdio.h>
#include "funcao.h"
#include "pilha.h"


bool find(char letra, char *str)
{
    for(int i = 0; i < strlen(str); i++)
    {
        if(str[i] == letra)
        {
            return true;
        }
    }
    return false;
}
void stringParaVetor(char *line, char vec[][20], int tamanho)
{

    char trab[tamanho];
    char operacoes[] = "+-*/()";
    char letra;
    bool numero = false;
    bool str = false;
    int vecI = 0;
    int aux = 0;
    strcpy(trab, "");

    for(int i = 0; i < tamanho; i++)
    {
        letra = line[i];
        if((isdigit(letra) || letra=='.')  && !str)
        {
            if(!numero)
            {
                if(strlen(trab)!=0)
                {
                    strcpy(vec[vecI++],trab);
                    strcpy(trab, "");
                }
                numero = true;
                str = false;
            }
            aux = strlen(trab);
            trab[aux] = letra;
            trab[aux+1] = '\0';
        }
        else if(letra == ' ')
        {
            if(!str)
            {
                if(strlen(trab)!=0)
                {
                    strcpy(vec[vecI++],trab);
                    strcpy(trab, "");
                    numero = false;
                    str = false;
                }
            }
        }
        else if(find(letra, operacoes) != 0)
        {
            if(strlen(trab)!=0)
            {
                strcpy(vec[vecI++],trab);
                strcpy(trab, "");
            }
            aux = strlen(trab);
            trab[aux] = letra;
            trab[aux+1] = '\0';
            strcpy(vec[vecI++],trab);
            strcpy(trab, "");
            numero = false;
            str = false;
        }
    }
    if(strlen(trab)!=0)
    {
        strcpy(vec[vecI++],trab);
    }
}

int tamanhoString(char entrada[]) {
    return strlen(entrada);
}

  bool precedencia(char op1) {
      switch(op1) {
        case '*':
        case '/':
          return false; 
          break;
        case '+':
        case '-':
          return true;
          break;
        default:
          return false;
      }
  }

  void resolverEquacao(char entrada[][20]) {
      double numero;
      char caracter;
      double conta = 0;
      int i = 0;

      while (entrada[i][0] != '\0') {
          if (entrada[i][0] == '(') {
              push_string(entrada[i]);
              i++;
          }
            else if (!precedencia(entrada[i][0]) && entrada[i][0] != ')') {
                if (isdigit(entrada[i][0])) {
                    numero = atof(entrada[i]);
                    push_double(numero);
                }
                else if (entrada[i][0] == '/') {
                    if (isdigit(entrada[i + 1][0])) {
                        pop_double(&numero);
                        numero /= atof(entrada[i + 1]);
                        push_double(numero);
                        i++; // Avança para o próximo operador
                    } else {
                       push_string(entrada[i]);
                    }
                }
                else {
                    if (isdigit(entrada[i + 1][0])) {
                        pop_double(&numero);
                        numero *= atof(entrada[i + 1]);
                        push_double(numero);
                        i++; // Avança para o próximo operador
                    } else {
                        push_string(entrada[i]);
                    }
                }
                i++; // Avança para o próximo operando ou parêntese
           
            }

          
          else if (precedencia(entrada[i][0])) {
              push_string(entrada[i]);
              i++;
          }
          else if (entrada[i][0] == ')') {
              while (!estaVazia_string() && pl_pilha_string[pl_posicao_string - 1][0] != '(') {
                  pop_string(&caracter);
                  if (caracter == '+') {
                      pop_double(&numero);
                      conta = numero;
                      pop_double(&numero);
                      conta += numero;
                      push_double(conta);
                   
                  }
                  else {
                      pop_double(&numero);
                    conta=0;
                      conta = numero;
                      pop_double(&numero);
                    conta = numero-conta;
                      push_double(conta);
                    
                  }
              }
              // Remover o '(' da pilha de strings
              pop_string(&caracter);
              i++;
          }
          else {
              i++;
          }
      }

      // Processar o restante da pilha de strings e calcular o resultado final
    
      while (!estaVazia_string()) {
          pop_string(&caracter);
        if (precedencia(caracter)){
          if (caracter == '+') {
              pop_double(&numero);
              conta = numero;
              pop_double(&numero);
              conta += numero;
              push_double(conta);
          }
          else {
              pop_double(&numero);
              conta = numero;
              pop_double(&numero);
              conta = numero-conta;
              push_double(conta);
          }
      }else
        {
          if (caracter == '/') {
           
                pop_double(&numero);
                conta=numero;
                pop_double(&numero);
                conta=numero/conta;
                push_double(conta);
                
            } 
          else if(caracter == '*')  {
            
                pop_double(&numero);
                conta=numero;
                pop_double(&numero);
                conta=numero*conta;
                push_double(conta);
                
              
            }
          }
         
        }
   
  }
  

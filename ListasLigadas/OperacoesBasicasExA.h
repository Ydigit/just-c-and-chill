
typedef struct{
  int   numAluno;
  float notas[4];
  int   notaFinal;
}INFO;

void mostrarElemento(INFO);

INFO criarElemento();

// compara��o de 2 elementos do tipo INFO, segundo o campo numAluno (chave)
// devolve -1 se primeiro < segundo, 0 se iguais, 1 se primeiro > segundo
int compararElementos(INFO, INFO);




#include "OperacoesBasicasExA.c"


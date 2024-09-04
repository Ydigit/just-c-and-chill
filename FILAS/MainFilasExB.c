
#include <stdio.h>
#include <stdlib.h>

#include "Aleatorio.h"
#include "OperacoesBasicasFilasExB.h"
#include "EADFila.h"

#include "OperacoesFilasExB.h"

int main()
{
  PNodoFila Q;
  
  // A.1
  Q = criarFilaAleatoria(0, 15);
  printf("Mostrar fila da frente para a cauda:\n");
  mostrarFila(Q);
  printf("\n");
  //AII
  printf("Mostrar 2 elemento molestado\n");
  INFOF A = get2ndelementotouch(&Q);
  mostrarElementoF(A);

  printf("\n");
  printf("Mostrar fila da frente para a cauda:\n");
  mostrarFila(Q);
  printf("\n");
  

  //AIII
  printf("Mostrar 2 elemento nao molestado\n");
  INFOF B = get2ndelementonotouch(Q);
  mostrarElementoF(B);
  printf("\n");\

  printf("\n");
  printf("Mostrar fila da frente para a cauda:\n");
  mostrarFila(Q);
  printf("\n");
}
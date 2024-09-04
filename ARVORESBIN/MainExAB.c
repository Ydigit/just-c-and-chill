
#include <stdio.h>
#include <stdlib.h>

#include "Aleatorio.h"
#include "OperacoesBasicasExAB.h"
#include "EADArvoreBinaria.h"
#include "ABPorNiveis.h"
#include "OperacoesExAB.h"

int main()
{
  /*
  PNodoAB T;
  int N;

  // A.1
  T = criarABAleatoria(0, 15);

  // A.2
  printf("Mostrar AB em-ordem:\n");
  mostrarEmOrdemAB(T);
  printf("Mostrar AB pre-ordem:\n");
  mostrarPreOrdemAB(T);
  printf("Mostrar AB pos-ordem:\n");
  mostrarPosOrdemAB(T);
  printf("Mostrar AB por niveis:\n");
  mostrarPorNiveisAB(T);

  float numero = qunatidadeNodosAB(T);
  printf("numero de elementos:%f\n", numero);

  int numero2 = quantidadeNotaFinalIgualK(T, 10);
  printf("numero de elementos igual a 10 :%d\n", numero2);

  float media = somaNotaFinaldeT(T) / qunatidadeNodosAB(T);
  printf("media : %f\n", media);

  int maiornota= maiorValornotafinal(T);
  printf("maior nota : %d\n", maiornota);

  int menor=menornumAluno(T);
  printf("menor numero : %d\n", menor);

  PNodoAB copia= copy(T);
  mostrarEmOrdemAB(copia);

  int iguais=compararArvores(T,copia);
  printf("sao iguais:%d\n", iguais);

  int quant= quantidadeFolhas(T);
  printf("nr de folhas: %d\n", quant);

   int filho= quantiddade1filho(T);
  printf("nr de 1 flho: %d\n", filho);
  */

 //estudo
 PNodoAB T=criarTaleatoria(0,8);
 PNodoAB dif=criarABAleatoria(0,4);
 mostrarPreOrdemAB(T);

int es1=qntdnds(T);
printf("%d\n", es1);

int esigual10=qntK(T, 10);
printf("%d\n", esigual10);

float es11= (float)(alls(T))/(float)(qntdnds(T));
int soma=alls(T);
printf("soma = %d\n", soma);
printf("media = %f\n", es11);

int es12=best(T);
printf("melhro nota = %d\n", es12);

/*
INFOAB es33 = menorelemtno(T);
mostrarElementoAB(es33);

INFOAB less = lessnumelement(T);
mostrarElementoAB(less);

int menornum=menorNumAl(T);
printf("menor num = %d\n", menornum);
printf("\n");




PNodoAB seg = second(T);
mostrarPreOrdemAB(seg);
*/

//por if de nao vazios
int vali=igualdade(dif, T);
printf("ser igual:%d\n", vali);

/*
mostrarPorNiveisAB(T);
printf("\n");
int nc=child(T);
printf("numero de folhas e de %d", nc);
*/

int qqq = contaigK(T, 10);
printf("nuemro de elem entod omc nota igual a 10 = %d\n", qqq);

int maioroooo = maiore(T);
printf("maior nota %d", maioroooo);


}



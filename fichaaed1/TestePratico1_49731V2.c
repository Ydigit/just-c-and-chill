#include <stdio.h>
#include <stdlib.h>

#include "Aleatorio.h"
#include "OperacoesBasicasTeste.h"
#include "EADListasLigadasSimples.h"

// implementação das operações/funções pedidas

PNodo criarListaAleatoria(int inf, int sup)
{
  int N, k;
  PNodo L;
  INFO X;
  
  N = gerarNumeroInteiro(inf, sup);
  L = criarLista();
  k = 1;
  while(k <= N){
    X = criarElemento();
    if (pesquisarLista(X, L) == 0){
      L = inserirListaInicio(X, L);
      k = k + 1;
    }
  }
  return L;
}

//A1
int K1K2(PNodo L, int K1, int K2)
{
  int count = 0;
  while(L != NULL){
    if(L->Elemento.notaFinal >= K1 && L->Elemento.notaFinal <= K2){
      count++;
    }
    L = L->Prox;
  }
  
  return count;
}
//A.2




// implementação do programa principal (main)

int main()
{
  PNodo Lista;
  int nota;
  Lista=criarListaAleatoria(1,20);
  printf("mostrar lista:");
  mostrarListaInicio(Lista);
  printf("notas mto:");
  printf("Notas do primeiro elemento: %f, %f\n", Lista->Elemento.notasMTP, Lista->Elemento.notasTE);
  nota=Lista->Elemento.notaFinal;//cabeca pois e po elemento onde aponta

  int conta = 0;
  if (nota >= 9 && nota <= 10) {
    conta = K1K2(Lista, 10, nota) + K1K2(Lista, 9, nota);
  }
  printf("numero de elementos entre 10 e anota e o 9 e anota: %d\n", conta);


}

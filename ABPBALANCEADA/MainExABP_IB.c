
#include <stdio.h>
#include <stdlib.h>

#include "OperacoesBasicasExABP_IB.h"
#include "EADArvoreBinariaPesquisa.h"
#include "ABP_IBPorNiveis.h"
#include "ABPBalanceada_IB.h"

int main()
{
  PNodoABP T;
  INFOABP *Lista, X;
  int opcao;

  T = criarABP();
  do{
    printf("\nOpcoes a realizar: Inserir [1], Remover[2] e Terminar [< 0]: ");
    scanf("%d", &opcao);
    switch(opcao){
      case 1:
      	printf("INSERIR ELEMENTO.\n");
        X = criarElementoABP();		  
		if(pesquisarABP(X,T) != NULL){
		  printf("Elemento ja existe na ABP.\n");
		  break;
		}
        T = inserirABP(X,T);
        printf("Mostrar por niveis:\n");
        mostrarPorNiveisABP(T);
        if (ABPBalanceada(T) == 1)
          printf("\nARVORE BALANCEADA.\n");
        else{
  	      printf("\nARVORE NAO BALANCEADA: APLICAR INSERCAO BINARIA.\n");
          T = criarABPBalanceadaIB(T);
          printf("Mostrar por niveis:\n");
          mostrarPorNiveisABP(T);
          printf("\n");
        }
        break;
      case 2:
      	if (ABPVazia(T)){
      	  printf("ABP vazia: operacao remover invalida!\n");
      	  break;
	    }
        printf("REMOVER ELEMENTO.\n");
        X = criarElementoABP();		  
		if(pesquisarABP(X,T) == NULL){
		  printf("Elemento nao existe na ABP.\n");
		  break;
		}
        T = removerABP(X,T);
        printf("Mostrar por niveis:\n");
        mostrarPorNiveisABP(T);
        if (ABPBalanceada(T) == 1)
          printf("\nARVORE BALANCEADA.\n");
        else{
  	      printf("\nARVORE NAO BALANCEADA: APLICAR INSERCAO BINARIA.\n");
          T = criarABPBalanceadaIB(T);
          printf("Mostrar por niveis:\n");
          mostrarPorNiveisABP(T);
          printf("\n");
        }
        break;
      default:
      	break;
    }
  }while(opcao >= 0);

}


#include <stdio.h>
#include <stdlib.h>

#include "Aleatorio.h"
#include "OperacoesBasicasPilhasExA.h"
#include "EADPilha.h"

#include "OperacoesPilhasExA.h"

int main()
{

  /*
  int a;


  PNodoPilha S;
  
  // A.1
  S = criarPilhaAleatoria(0, 15);

  printf("Mostrar pilha do topo para o fundo:\n");
  mostrarPilha(S);
  printf("\n");
  */

  /*
  //A.II
  printf("mostrar o 2nd from top com alteracao\n");
  devolve2ndtopSalterando(S);
  printf("\n");

  printf("Mostrar nova pilha");
  mostrarPilha();
  */
 /*
   //A.III
  printf("mostrar o 2nd from top\n");
  devolve2ndtopS(S);
  printf("\n");


  printf("mostrar o nesimo elemento\n");
  printf("INDICA O NUMERO N:");
  scanf("%d", &a);
  //returnesimoeelemento(S, a); funciona bem
  INFOP nel= returnesimoeelementomain(&S, a);//aqui sem & encviaria uma copia de S
  mostrarElementoP(nel);
  printf("\n");

  printf("Mostrar pilha do topo para o fundo:\n");
  mostrarPilha(S);
  printf("\n");

  printf("nesimoe lemento novamente\n");
  INFOP nelnottouch= returnnelementnotouching(S, a);
  mostrarElementoP(nelnottouch);
  printf("\n");
 */
/*
  printf("\n");
  printf("Mostrar pilha do topo para o fundo sem tocar:\n");
  mostrarPilha(S);
  printf("\n");
*/
  ///returnNthElementmain(S, a);//esta mal
/*
  printf("Mostrar pilha do topo para o fundo:\n");
  mostrarPilha(S);
  printf("\n");
  */
/*
 //AVI
printf("deep down is released without toucking stack\n");
INFOP deepp =forkdeepdownnotouching(S);
mostrarElementoP(deepp);
printf("\n");


printf("mostra o r3d from deep no touching\n");
INFOP r3eed = fork3rdfromdeep(S);
mostrarElementoP(r3eed);

printf("\n");
  printf("Mostrar pilha do topo para o fundo sem tocar:\n");
  mostrarPilha(S);
  printf("\n");
  printf("mostrar 3 elemento e tocar:\n");
  INFOP rreedd = touch3rd(S);
  mostrarElementoP(rreedd);

  printf("\n");
  printf("Mostrar pilha do topo para o fundo :\n");
  mostrarPilha(S);
printf("\n");

printf("mostrar trocado ini e fim\n");
trocatopunder(S);
printf("\n");

printf("vamos ordenar\n");
rearrange(S);
*/

//estudo

//1
PNodoPilha Pilha=criarpilha(0,8);
printf("mostrar topo baixo\n");
mostrarP(Pilha);
printf("\n");


int es1=calctam(Pilha);
printf("tamanho %d\n", es1);




INFOP top2inal=devolve2topINAL(Pilha);
mostrarElementoP(top2inal);
printf("\n");
printf("mostrar topo baixo\n");
mostrarP(Pilha);

int a;
printf("mostrar o nesimo elemento\n");
  printf("INDICA O NUMERO N:");
  scanf("%d", &a);
  mostrarElementoP(devolveNeleAlterar(Pilha, a));
  printf("\n");

  mostrarPilha(Pilha);
  printf("\n");
  printf("TIREI O %d elemento:\n", a);
  mostrarElementoP(devolveNeleAlterarpop(Pilha, a));
  printf("\n");
  mostrarPilha(Pilha);
  printf("\n");

printf("N from bwll");
  mostrarElementoP(Nfrombellow(Pilha));
    printf("\n");
  mostrarPilha(Pilha);


printf("\n");
Change(Pilha);
mostrarPilha(Pilha);







}




















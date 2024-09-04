
#include <stdio.h>
#include <stdlib.h>
#include "Aleatorio.h"
#include "OperacoesBasicasExA.h"
#include "EADListasLigadasSimples.h"
#include "OperacoesExA.h"

int main()
{
  PNodo Lista; //Lista e um ponteiro para nodo, PNodo e um typedef que aponta para um nodo
  int tam;
  int N;
  int num;
  int NM;
  int nummaiores;
  int NMR;
  int nummaiores2;
  int maiornotafinal;
  int maiornotafinaliter;
  int numAlmelhor34;
  int numAlmelhor34headtails;
  int piorTP1TP2;
  float media;
  int elementomeiorigualK; //sera um numero
  int elementomenoriagualmaiorK;
  int K;
  int menorNoatFialMIKrecheadtail1;
  int menorNoatFinaklrec;
  int K1,K2;
  int containtervalo;
  int num2;
  int num3;
  int k69;
  int k4;
  int k5;
  int k6;
  int k9;
  int k10;
  int maior4;
  int K101;
  int K102;

  
  // A.1
 Lista=criarListaAleatoria(0, 8); //cria lista ate 15 elementos
 // A.2
 printf("Mostrar lista do inicio para o fim:\n");
 mostrarListaInicio(Lista);
 printf("Mostrar do fim ao inicio \n");//recursiva
 mostrarListaFimRec(Lista);

 //A.3
 tam = tamanhoLista(Lista);
 printf("Tamanho da Lista: %d\n", tam);
int tamrec = tamanhoListaRec(Lista);
 printf("Tamanho da Lista: %d\n", tamrec);


 //A.4
 printf("Insere nota :");
 scanf("%d", &N);
 num = numElementosIguaisN(Lista, N);
 printf("Numero de elementos com nota final de%d de : %d\n", N, num);
printf("\n");
/*
 //A.5
printf("cardinalidade de notas superiores >=\n");
printf("Insere nota :");
scanf("%d", &NM);
nummaiores=numElementosMaiorIgual(Lista, NM);
printf("Numero de elementos com nota final >= de %d  e de : %d\n", NM, nummaiores);

printf("cardinalidade de notas superiores recursiva\n");
printf("Insere nota :");
scanf("%d", &NMR);
nummaiores2=numElementosMaiorIgualREC(Lista, NMR);
printf("Numero de elementos com nota final >= de %d  e de : %d\n", NMR, nummaiores2);

//A.6
maiornotafinal=MaiorNumeroListaREC(Lista);
printf("Maior notafinalrec : %d\n", maiornotafinal);

maiornotafinaliter=MaiorNumeroListaITER(Lista);
printf("Maior notafinaliter : %d\n", maiornotafinaliter);

//A.7
numAlmelhor34=numAlunoBetsfreq2E3(Lista);
printf("Aluno cm melhora classificao na fre 3 e 4: %d \n", numAlmelhor34);
numAlmelhor34headtails=numAlunoBetsfreq2E3TaisHead(Lista);
printf("Aluno cm melhora classificao na fre 3 e 4: %d \n", numAlmelhor34headtails);

piorTP1TP2=numAlunoPiorNotaTP1TP2Rec(Lista);
printf("Aluno cm pior classificao de tp1 ou tp2: %d \n", piorTP1TP2);

media=valormedioNotaFinal(Lista);
printf("Media de notas finais: %-2f \n", media);
*/


/*
//A.X iter
printf("indica um k:\n");
scanf("%d", &K);
elementomenoriagualmaiorK=menorNoatFialMIK(Lista, K);
printf("menor elemento maior ou igual a %d: %d\n",K, elementomenoriagualmaiorK);
menorNoatFialMIKrecheadtail1=menorNoatFialMIKrecheadtail(Lista,K);
printf("com rec menor elemento maior ou igual a %d: %d\n",K, menorNoatFialMIKrecheadtail1);

menorNoatFinaklrec=menorNoatFinal(Lista, K);
printf("com rec menor nota maior ou igual a %d: %d\n",K, menorNoatFinaklrec);

printf("indica um intervalo K1 e K2 (incluido ):\n");
scanf("%d",&K1);
scanf("%d",&K2);
containtervalo=contaelementosnotafinalentrek1k2(Lista, K1, K2);
printf("numero de elementos presentes no intervalo %d - %d is %d \n",K1, K2, containtervalo);

printf("numAl para remover:\n");
scanf("%d", &num2);
Lista=removerNodeIgualNum(Lista,num2);
printf("Mostrar lista do inicio para o fim:\n");
mostrarListaInicio(Lista);

printf("numAl para remover:\n");
scanf("%d", &num3);
Lista=removerelementonumALUNO(Lista,num3);
printf("Mostrar lista do inicio para o fim:\n");
mostrarListaInicio(Lista);

printf("remover alunos com notas menor ou igual a k:\n");
scanf("%d", &k69);
Lista=removeallunderKnotafinal(Lista,k69);
printf("Mostrar lista do inicio para o fim:\n");
mostrarListaInicio(Lista);

printf("remover alunos com notas menor ou igual a k:\n");
scanf("%d", &k4);
Lista=removeunderKnotafinaliterativa(Lista,k4);
printf("Mostrar lista do inicio para o fim:\n");
mostrarListaInicio(Lista);

printf("remover alunos com notas igual a k:\n");
scanf("%d", &k5);
Lista=removeralligualaK(Lista,k5);
printf("Mostrar lista do inicio para o fim:\n");
mostrarListaInicio(Lista);

printf("remover alunos com notas igual a k:\n");
scanf("%d", &k6);
Lista=removeralligualaKrec(Lista,k6);
printf("Mostrar lista do inicio para o fim:\n");
mostrarListaInicio(Lista);

printf("remover os primeiro n elementosk:\n");
scanf("%d", &k9);
Lista=removerosNelementos(Lista,k9);
printf("Mostrar lista do inicio para o fim:\n");
mostrarListaInicio(Lista);

printf("inicializar uma lista apartir do num aluno:\n");
scanf("%d", &k10);
Lista=alistadivididaemnum(Lista,k10);
printf("Mostrar lista do inicio para o fim:\n");
mostrarListaInicio(Lista);
if(listaVazia(Lista)==0){
maior4=maiorelementolistaligada(Lista);
printf("maior de todos: %d \n", maior4);
}
int maior69=maiorelementolistaligadaheadtail(Lista);
printf("maior de todos: %d \n", maior69);
*/
//estudo

//showinfin(Lista);
/*
int es =containfimrec(Lista);
printf("tam = %d\n", es);


int es2 =coantfimini(Lista);
printf("tam = %d\n", es2);

int es3 =contaigNrecHe(Lista, 10);
printf("tam = N = %d\n", es3);

int es4 =contaifNTails(Lista, 10);
printf("tam = N = %d\n", es4);

int es5 =contamaiorigualrechead(Lista, 10);
printf("tam >= N = %d\n", es5);

int es6 =contamaiorigualrectail(Lista, 10);
printf("tam >= N = %d\n", es6);

int es7 =maiorvaliter(Lista);
printf("maior  = %d\n", es7);


int es8 =MNFH(Lista);
printf("maior  = %d\n", es8);

int es9 =numalmelhor23(Lista);
printf("maior 2 e 3  = %d\n", es9);

int es10 =nummelhrorec23recTails(Lista);
printf("maior 2 e 3  = %d\n", es10);

int es11 =numpiorAluno(Lista);
printf("maior 2 e 3  = %d\n", es11);

INFO es12 =pioraluno(Lista);
mostrarElemento(es12);


INFO es13 =pioralunorec(Lista);
mostrarElemento(es13);

float es14 =mediaa(Lista);
printf("media e  = %f\n", es14);

float es15 =mediarec(Lista);
float tam22 = (float)tamanhoLista(Lista);
es15 = es15/tam22;
printf("mediar e  = %f\n", es15);


int es16 =quantidadek1k2(Lista, 14, 16);
printf("quna k1 k2  = %d\n", es16);

int es17 =numentrk1k2(Lista, 14, 16);
printf("quna k1 k2  = %d\n", es17);
*/

/*
int numall;
printf("escolher numal\n");
scanf("%d", &numall);
removenumAlunoiter(Lista, numall);
printf("Mostrar do fim ao inicio \n");//recursiva
mostrarListaFimRec(Lista);
*/

/*
PNodo LL=removerigualaK(Lista, 10);
mostrarListaInicio(LL);
printf("\n");
mostrarListaInicio(Lista);
printf("\n");
*/

/*
PNodo LLL = removernota(Lista, 10);
printf(" sem o 10\n");
mostrarListaInicio(LLL);


printf("\n");
mostrarListaInicio(Lista);
printf("\n");

printf("eliminar os primeiros3\n");
PNodo LLLL=removerosNelementos2(Lista, 3);
mostrarListaInicio(LLLL);
printf("\n");
*/

/*
printf("indica um numal para dividir a lista\n");
int aaa;
scanf("%d", &aaa);

//printf("listas:\n");
//dividirlistaem2(Lista, aaa);

*/

printf("dghfgh\n");
mostrarListaInicio(Lista);
printf("\n");

/*
printf("eliminar os primeiros3\n");
PNodo LLLL=removerosNelementos2(Lista, 3);
mostrarListaInicio(LLLL);
printf("\n");
*/

/*
int somaiagualanum=somarec(Lista, 10);
printf("SOMA %d\n", somaiagualanum);
*/


PNodo listasem =removerprimeriomaiorquen(Lista, 10);
mostrarListaInicio(listasem);





return 0;

}

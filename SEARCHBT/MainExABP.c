
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "Aleatorio.h"
#include "OperacoesBasicasExABP.h"
#include "EADArvoreBinariaPesquisa.h"
#include "ABPPorNiveis.h"
#include "OperacoesExABP.h"

int main()
{
  PNodoABP T;
  
  // 1.
  T = criarABPAleatoria(0, 15);
  printf("Mostrar ABP por niveis:\n");
  mostrarPorNiveisABP(T);
  mostrarEmOrdemABP(T);

  imprimeraiz_and_emtravessia(T);
  printf("\n");
  //raizemordem(T);
    /*
    int hhhh=altura(T);
    printf("altura-> %d\n", hhhh);

    INFOABP maiornnuummaluno = maiornumalunorec(T);
    mostrarElementoABP(maiornnuummaluno);
    printf("\n");
    */

    int contaMAtestestyle=numMAtesteStyle(T,30000);
    printf("numero defolhas  elementos maiores que 30000:  %d\n", contaMAtestestyle);

    int contaMAmIN=numeleMAeMN(T, 30000, 32000);
    printf("numero de elementos maiores que 30000 e menors oun iguas a 32000:  %d\n", contaMAmIN);

    printf("Indica o numde aluno para PEGAR O ELEMENTO COMPLETO  \n");
    int numAlforpersquisa;
    scanf("%d", &numAlforpersquisa);


    INFOABP elementoeqA=numAleq(T,numAlforpersquisa);
    mostrarElementoABP(elementoeqA);

    

    int contaENTREAeB=numeroeleMIAoumIB(T, 30000, 32000);
    printf("numero de elementos maiores e iguais que 30000 e menors ou iguais a 32000:  %d\n", contaENTREAeB);

  
    int contamAouMB=numelemAouMB(T, 30000, 32000);
    printf("numero de elementos menores que 30000 ou maiores a 32000:  %d\n", contamAouMB);










/*
if(T!=NULL){
  INFOABP maior= maiorelemento(T);
  printf("maior elemento\n");
  mostrarElementoABP(maior);
  printf("\n");
  INFOABP mairorec = maiorrec(T);
  printf("maior elemento rec\n");
  mostrarElementoABP(mairorec);
  printf("\n");
  displayRootAndInOrderTraversal(T);
  printf("\n");
  raizemordem(T);
}

int cardinalidadedeniveis=niveis(T);
printf("numero de niveis %d\n",cardinalidadedeniveis);

printf("menoriter\n");
INFOABP menor = menoriter(T);
mostrarElementoABP(menor);

printf("menorrec\n");
INFOABP mnrec = menorrec(T);
mostrarElementoABP(mnrec);
printf("\n");
/*
printf("Indica o valor N par sup em numAl\n");
int NN;
scanf("%d", &NN);
int contagemnumsupN=contasupN(T, NN);
printf("contagem superior a %d == %d\n", NN, contagemnumsupN);


int scontasupeinf =contaelesupAinfN(T, NN, 10);
printf("contagem superior e inferior == %d\n", scontasupeinf);

INFOABP numeroa = numeroigA(T, NN);
mostrarElementoABP(numeroa);

int cardinalidadesupainfb=contamaiorAmenorBig(T, 0, NN);
printf("maiores igual a 0 e menores q %d e de = %d\n", NN, cardinalidadesupainfb);


int numeroinverso=contamenoeqAmaiorB(T, 5, 15 );//acima de 15 e  abaixo de 5
printf("numero de elementos acima de 15 e abaixo de 5 = %d\n\n",numeroinverso);

PNodoABP TT = removerABP2(mnrec, T);
mostrarEmOrdemABP(TT);
*/

/*
    INFOABP* array = BSTtoArray(TT);
    int n = countNodes(TT);

    // Print the elements of the array
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i].numAluno);
    }

    // Free the memory allocated for the array
    free(array);
*/


/*
 
 printf("\n\n");
int numeronodos= contanodos(T);
printf("numero de nodos e de %d", numeronodos);

printf("\n");
INFOABP* array = transformBSTtoArray(T);
    for (int i = 0; i < numeronodos; i++) {
        printf("%d ", array[i].numAluno);
    }
    free(array);

folhaproxraizafastadoraiz(T);

printf("\n\n");
printf("sem o maior\n");
PNodoABP semmaior = removiomaior(T);
mostrarEmOrdemABP(T);
printf("\n\n");
PNodoABP semmenor= removemenor(T);
printf("sem o menor\n");
mostrarEmOrdemABP(T);

printf("insercao\n\n\n");
printf("valor a inserir:\n");
INFOABP ainseriri = criarElementoABP();
mostrarElementoABP(ainseriri);
printf("\n\n");

PNodoABP Novaarv = inseriratoa(ainseriri, T);
mostrarEmOrdemABP(Novaarv);



int levelss= levelup(T);
printf("quanridade de niveis = %d\n", levelss);

INFOABP menorinfo = lesser(T);
mostrarElementoABP(menorinfo);

INFOABP menorinforec = lesserrec(T);
mostrarElementoABP(menorinforec);

int numsup10= numelementosupA(T, 20000);
printf("numero de elementos maiores que 20000 e de %d\n", numsup10);

int niggggr= numelementosupAmenN(T, 20000, 10);
printf("numero de elementos maiores que 2000 e de %d\n", niggggr);

*/











    return 0;
}


#include <limits.h>


/* ------------------------------------------------------- */
/* ---- prot�tipos/headers das fun��es da biblioteca ----- */
/* ------------------------------------------------------- */
PNodoAB criarABAleatoria (int, int);

int qunatidadeNodosAB(PNodoAB );

int quantidadeNotaFinalIgualK(PNodoAB , int );

int somaNotaFinaldeT(PNodoAB );

int maiorValornotafinal(PNodoAB );

int menornumAluno(PNodoAB );

PNodoAB copy(PNodoAB);

int compararArvores(PNodoAB, PNodoAB);

int quantidadeFolhas(PNodoAB);

int quantiddade1filho(PNodoAB );

//estudo
PNodoAB criarTaleatoria(int , int );

int qntdnds(PNodoAB);

int qntK(PNodoAB , int );

int alls(PNodoAB );

int best(PNodoAB);

int menorNumAl(PNodoAB );

PNodoAB second(PNodoAB);

int validator(PNodoAB , PNodoAB );

int child(PNodoAB );

int igualdade(PNodoAB , PNodoAB );

INFOAB lessnumelement(PNodoAB );


int piornota(PNodoAB );


int melhornota(PNodoAB );

int qntdndoos1filho(PNodoAB );

int contaigK(PNodoAB , int );


int maiore(PNodoAB );




/* ------------------------------------------------------- */
/* -------------- implementa��o das fun��es -------------- */
/* ------------------------------------------------------- */

PNodoAB criarABAleatoria (int inf, int sup)
{
  int k, N;
  INFOAB X;
  PNodoAB T;
  
  N = gerarNumeroInteiro(inf, sup);
  T = criarAB();
  k = 1;
  while (k <= N){
  	X = criarElementoAB();
  	if (pesquisarAB(X,T) == NULL){
  	  T = inserirPorAlturaAB(X,T);
  	  k = k + 1;
	}
  }
  return T;
}

int qunatidadeNodosAB(PNodoAB T){
  int qEsq = 0;
  int qDir = 0;
  if(T==NULL)
  return 0;
  qEsq = qunatidadeNodosAB(T->Esquerda);//chamada recursiva
  qDir = qunatidadeNodosAB(T->Direita);
  return 1 + qEsq + qDir; //raiz
}

//A4
int quantidadeNotaFinalIgualK(PNodoAB T, int K){
  int countEsq = 0;
  int countDir = 0;
  int countAtual = 0;
  if(T == NULL)
    return 0;
    //raiz pode nao ser igual a K
  if(T->Elemento.notaFinal == K)
    countAtual = 1;//o primeiro sera
  //podiam por a recursividade antes ou depois das condicoess
  countEsq = quantidadeNotaFinalIgualK(T->Esquerda, K);
  countDir = quantidadeNotaFinalIgualK(T->Direita, K);
  //a cada recursividade recebo o calor de contador contador 
  //de todos
  return countAtual + countEsq + countDir;
}

//A5
//retorna o int dda soma das notas finais
int somaNotaFinaldeT(PNodoAB T){
  int somDir=0;
  int somEsq=0;
  int somAtual=0;
  int tam;

  if(T==NULL)
    return 0;
  somAtual=T->Elemento.notaFinal;

  somEsq=somaNotaFinaldeT(T->Esquerda);
  somDir=somaNotaFinaldeT(T->Direita);
   return somAtual+somDir+somEsq;

}

//A6
int maiorValornotafinal(PNodoAB T){
  int maiordir=0;
  int maioresq=0;
  int Maior=0;
  if(T==NULL)
    return -1;//nao tem amis onde puxar
  Maior=T->Elemento.notaFinal;
  maioresq=maiorValornotafinal(T->Esquerda);
  maiordir=maiorValornotafinal(T->Direita);
  if(maioresq>Maior)
    Maior=maioresq;
  if(maiordir>Maior)
    Maior=maiordir;
  return Maior;
}
//prof
int NoLord(PNodoAB T){
  int compes=0;
  int compdr=0;
  int X = T->Elemento.notaFinal;
  if(T==NULL)
    return -1;
  compes=NoLord(T->Esquerda);
  compdr=NoLord(T->Direita);
  if(compes>X)
    X = compes;
  if(compdr>X)
    X=compdr;
  return X;
}

//7
int menornumAluno(PNodoAB T){
  if(T==NULL)
    return INT_MAX;
  int menor=T->Elemento.numAluno;
  int menoresq=menornumAluno(T->Esquerda);
  int menordir=menornumAluno(T->Direita);
  if(menoresq<menor)
    menor=menoresq;
  if(menordir<menor)
    menor=menordir;
  return menor;
}
//7 prof
INFOAB menorelemtno(PNodoAB T){
  INFOAB Dir,Esq,X;
  //caso terminal base: T só com 1 elemento
  if(T->Esquerda == NULL && T->Direita == NULL){
    return T->Elemento;
  }
  //caso final: tem pelo menos 1 filho
  if(T->Esquerda == NULL){
    Dir = menorelemtno(T->Direita);
    if(Dir.numAluno < T->Elemento.numAluno)
      return Dir;
    else
      return T-> Elemento;   
  }

  if(T->Direita == NULL){
    Esq = menorelemtno(T->Esquerda);
    if(Esq.numAluno < T->Elemento.numAluno)
      return Esq;
    else
      return T-> Elemento;   
  }

  Esq = menorelemtno(T->Esquerda);
  Dir = menorelemtno(T->Direita);

  X = T -> Elemento;

  if(X.numAluno > Esq.numAluno)
    X = Esq;

  if(X.numAluno > Dir.numAluno)
    X = Dir;

  return X;
}

/*
INFOAB menorelemtno(PNodoAB T){
  INFOAB Dir;
  INFOAB Esq;
  if(T->Esquerda==NULL && T->Direita == NULL)
    return T->Elemento;
  //casogeral sao 3 casos, 1 filjo, 2 filhos, 1 filho noutro lado, nao de 0 filhos
  if(T->Esquerda==NULL){//ver com dir and atual
    Dir=menorelemtno(T->Direita);
    if(Dir.numAluno<T->Elemento.numAluno)
      return Dir;
    else
      return T->Elemento;

    if(T->Direita==NULL)
      Esq=menorelemtno(T->Esquerda);
    if(Esq.numAluno>T->Elemento.numAluno)
      return Esq;
    else
      return T->Elemento;
  }
  else  
    return T->Elemento;
    Esq=menorelemtno(T->Esquerda);
    Dir=menorelemtno(T->Direita);
    INFOAB X=T->Elemento;
    if(X.numAluno<Esq.numAluno)
      X=Esq;
    if(X.numAluno<Dir.numAluno)
      X=Dir;
    return X;
}
*/

//8
PNodoAB copy(PNodoAB T){
  PNodoAB copia;//crio a arvore
  if(T == NULL) //se o atual e vazio
    return NULL;  //

  copia=criarNodoAB(T->Elemento);

  copia->Esquerda=copy(T->Esquerda);
  copia->Direita=copy(T->Direita);

  return copia;
}

//9
int compararArvores(PNodoAB T1, PNodoAB T2){
  if(T1==NULL && T2 == NULL){
    return 1;
  }
  if(T1==NULL || T2 == NULL){
    return 0;
  }
  if(T1->Elemento.numAluno != T2->Elemento.numAluno){
    return 0;
  }
  
  int esq=compararArvores(T1->Esquerda, T2->Esquerda);
  int dir=compararArvores(T1->Direita, T2->Direita);

  return esq && dir;
}

int quantidadeFolhas(PNodoAB T){
  if(T==NULL)
    return 0;
  if(T->Esquerda==NULL&&T->Direita==NULL)
  return 1;

  return quantidadeFolhas(T->Esquerda)+quantidadeFolhas(T->Direita);
}
//AXI
int quantiddade1filho(PNodoAB T){
  if(T==NULL)
    return 0;
  if(T->Esquerda==NULL&&T->Direita!=NULL)
    return 1;
  if(T->Direita==NULL&&T->Esquerda!=NULL)
    return 1;
  return quantiddade1filho(T->Esquerda)+quantiddade1filho(T->Direita);
}

int Levelup(PNodoAB T, INFOAB X){
  if(T==NULL)
    return -1;//flags
  if(T->Elemento.numAluno==X.numAluno)
    return 0;
  int nivelesq=Levelup(T->Esquerda, X);
  int niveldir=Levelup(T->Direita, X);

  if(nivelesq!=-1)//se for 0 por exemplo
    return nivelesq+1;
  if(niveldir!=-1)
    return niveldir+1;
  return -1;
}


PNodoAB mirror(PNodoAB T) {
    if (T == NULL)
        return NULL;

    // Cria um no com o mesmo atual
    PNodoAB newT = criarNodoAB(T->Elemento);
    newT->Elemento = T->Elemento;

    // Faz a troca das subtreess
    newT->Esquerda = mirror(T->Direita);
    newT->Direita = mirror(T->Esquerda);

    return newT;
}

//study
PNodoAB criarTaleatoria(int inf, int sup){
  PNodoAB T=NULL;
  INFOAB X;
  int k, N;
  N=gerarNumeroInteiro(inf,sup);
  k=1;
  while(k<=N){
    X=criarElementoAB();
    if(pesquisarAB(X,T)==NULL){
      T=inserirPorAlturaAB(X, T);
      k++;
    }
  }
  return T;
}

//qntnds
int qntdnds(PNodoAB T){
  int qntes=0;
 int qntdir=0;
  if(T==NULL){
    return 0;
  }
  qntes= qntes+qntdnds(T->Esquerda);
  qntdir= qntdir+qntdnds(T->Direita);
  
  return 1+qntes+qntdir;
}

int qntK(PNodoAB T, int K){
  int qntes=0;
  int qntdir=0;
  if(T==NULL){
    return 0;
  }
  qntes=qntK(T->Esquerda, K);
  qntdir=qntK(T->Direita, K);
  if(T->Elemento.notaFinal==K){
    return 1+qntes+qntdir;
  }
  else{
    return qntes+qntdir;
  }
}

int alls(PNodoAB T){
  int nfes=0;
  int nfdir=0;
  if(T==NULL){
    return 0;
  }
  nfes=alls(T->Esquerda);
  nfdir=alls(T->Direita);
  return T->Elemento.notaFinal+nfes+nfdir;
}

int best(PNodoAB T){
  int besq;
  int bdir;
  int maior=-1;
    if(T==NULL){
    return -1;
  }
  maior= T->Elemento.notaFinal;

  besq=best(T->Esquerda);
  bdir=best(T->Direita);
  if(besq>maior)
    maior=besq;
  if(bdir>maior)
    maior=bdir;
  return maior;
}

INFOAB lessnumelement(PNodoAB T){
    INFOAB mesq;
    INFOAB mdir;
    INFOAB menor; 
  if(T->Direita==NULL&&T->Esquerda==NULL){
    menor = T->Elemento;
    return menor;
  }
  mesq=lessnumelement(T->Esquerda);
  mdir=lessnumelement(T->Direita);
  if(mesq.numAluno<menor.numAluno){
    menor=mesq;
  }
  if(mdir.numAluno<menor.numAluno){
    menor = mdir;
  }
  if(T->Elemento.numAluno<menor.numAluno){
    menor=T->Elemento;
  }
  return menor;
}
/*
int menorNumAl(PNodoAB T){
  int menor;
  if(T->Esquerda==NULL&&T->Direita==NULL){
    menor=T->Elemento.numAluno;
    return menor;
  }
  
  int esq=menorNumAl(T->Esquerda);
  int dir=menorNumAl(T->Direita);

  if(esq<menor){
    menor=esq;
  }
  if(T->Elemento.numAluno<menor){
    menor=T->Elemento.numAluno;
  }
  if(dir<menor){
    menor=dir;
  }
  return menor;
}
*/

int menorNumAl(PNodoAB T){
  if(T == NULL){
    return INT_MAX; // Return maximum integer value if node is NULL
  }

  int menor = T->Elemento.numAluno;
  
  if(T->Esquerda != NULL){
    int esq = menorNumAl(T->Esquerda);
    if(esq < menor){
      menor = esq;
    }
  }
  
  if(T->Direita != NULL){
    int dir = menorNumAl(T->Direita);
    if(dir < menor){
      menor = dir;
    }
  }

  return menor;
}

PNodoAB second(PNodoAB T){
  PNodoAB T2 = malloc(sizeof(struct NodoAB));
  if(T==NULL){
    return NULL;
  }
  T2=criarNodoAB(T->Elemento);
  T2->Esquerda=second(T->Esquerda);
  T2->Direita=second(T->Direita);

  return T2;
}


int validator(PNodoAB T1, PNodoAB T2){
  if(T1==NULL&&T2==NULL){
    return 1;//yes
  }
  if(T1==NULL||T2==NULL){
    return 0;
  }
  int finalesq=validator(T1->Esquerda, T2->Esquerda);
  int finaldir=validator(T1->Direita, T2->Direita);

  if(finalesq==1&&finaldir==1){
    return 1;
  }else
    return 0;

}

int child(PNodoAB T){//fls
  if(T==NULL)
    return 0;
  if(T->Esquerda==NULL&&T->Direita==NULL)
    return 1;
  int qntesq=child(T->Esquerda);
  int qntddir=child(T->Direita);
  return qntddir=qntesq;
}



//stor 8
PNodoAB copiaAB(PNodoAB T){
  PNodoAB TC;
  //caso terminal
  if(T==NULL){
    return NULL;
  }
  //casogeral quando t e nao null
  TC=criarNodoAB(T->Elemento);
  TC->Esquerda=copiaAB(T->Esquerda),
  TC->Direita=copiaAB(T->Direita);

  return TC;
}

//stor 9
int igualdade(PNodoAB T1, PNodoAB T2){
  if(T1==NULL&&T2==NULL){
    return 1;
  }
  if(T1==NULL||T2==NULL){
    return 0;
  }
  if(compararElementosAB(T1->Elemento, T2->Elemento)!=0){
    return 0;
  }
  if(igualdade(T1->Esquerda,T2->Esquerda)==0)
    return 0;
  if(igualdade(T1->Direita,T2->Direita)==0)
    return 0;
  return igualdade(T1->Direita,T2->Direita);

  int igesq=igualdade(T1->Esquerda, T2->Esquerda);
  int igdir=igualdade(T1->Direita, T2->Direita);
}


int piornota(PNodoAB T){
  if(T==NULL){
    return INT_MAX;
  }
  int menor=T->Elemento.notaFinal;
  int esq=piornota(T->Esquerda);
  int dir=piornota(T->Direita);
    if(esq<menor)
      menor= esq;
    if(dir<menor)
      menor= dir;
    return menor;
}



int melhornota(PNodoAB T){
  if(T==NULL){
    return -1;
  }
  int esq, dir, maior;
  maior = T->Elemento.notaFinal;
  esq = melhornota(T->Esquerda);
  dir = melhornota(T->Direita);
    if(esq>maior)
      maior = esq;
    if(dir>maior)
      maior = dir;
    return maior;
}

int qntdndoos1filho(PNodoAB T){
  if(T==NULL)
    return 0;

  int qntesq, qntdir;
    if((T->Direita==NULL && T->Esquerda==NULL))  
    return 0;
  if(T->Direita==NULL || T->Esquerda==NULL)
    return 1;
  qntesq =  qntdndoos1filho(T->Esquerda);
  qntdir= qntdndoos1filho(T->Direita);

  return qntdir+qntesq;  
}

//contar igual a k
int contaigK(PNodoAB T, int K){
  if(T==NULL){
    return 0;
  }
  int esq,dir;
  esq=contaigK(T->Esquerda,  K);
  dir=contaigK(T->Direita,  K);
  if(T->Elemento.notaFinal==K){
    return 1 + esq + dir;
  }
  else
    return esq + dir;
}


int numfilhas(PNodoAB T){
  if(T==NULL)
    return 0;

  if(T->Esquerda == NULL && T->Esquerda==NULL){
    return 1;
  }
  return numfilhas(T->Esquerda)+numfilhas(T->Direita);
}

int nods(PNodoAB T){
  if(T==NULL)
    return 0;
  int esq, dir;
  esq=nods(T->Esquerda);
  dir=nods(T->Direita);
  return 1 + esq + dir;
}

int maiore(PNodoAB T){
  if(T==NULL){
    return -1;
  }
  int maior=T->Elemento.notaFinal;
  int esq, dir;
  esq=maiore(T->Esquerda);
  dir=maiore(T->Direita);
  if(esq>maior)
    maior=esq;
  if(dir>maior)
    return dir;
  return maior;
}

int contafolhas(PNodoAB T){
  if(T==NULL)
    return 0;
  int esq, dir;
  if(T->Esquerda==NULL&&T->Direita==NULL)
    return 1;
  return contafolhas(T->Esquerda)+contafolhas(T->Direita);
}







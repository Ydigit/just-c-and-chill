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

int tamanhoLista(PNodo L)
{
  PNodo P = L;
  int tam = 0;
  while(P != NULL)
  {
    tam = tam + 1;
    P = P ->Prox;
  }
  return tam;
}

int tamanhoListaRec(PNodo L){
  int num=0;
  if(L==NULL){
  return 0;
  }
  return 1 + tamanhoListaRec(L->Prox); //soma do return da propria funcao em 0 para e de resto i crementa
}


int numElementosIguaisN (PNodo L, int N){
  int num;
    if(L == NULL) //caso base
    return 0;
    num = numElementosIguaisN(L->Prox, N);
    if(L->Elemento.notaFinal == N)
    return num + 1;
    else 
    return num; //efeito de desdobrar
}

//A.5 correto

int numElementosMaiorIgual(PNodo L, int N){
  int num=0;
  while(L!=NULL){
    if(L->Elemento.notaFinal >= N){
      num++;
      L=L->Prox;
    }
    else{
      L=L->Prox;
    }
  }
  return num;

}
//correto
int numElementosMaiorIgualREC (PNodo L, int N){
  int num;
    if(L == NULL) //caso base
    return 0;
    num = numElementosMaiorIgualREC(L->Prox, N);
    if(L->Elemento.notaFinal >= N)
    return num + 1;
    else 
    return num; //efeito de desdobrar
}

//A.6 rec
int MaiorNumeroListaREC(PNodo L){
  int num;
    if(L->Prox == NULL) //caso base se o meu nodo aponta par anulo retorno logo a info
    return L->Elemento.notaFinal;//retorno o utlimo numero para ocm3ear de traxz para a frente  

    num = MaiorNumeroListaREC(L->Prox); //num na ultima chamada retorna o ultimo valor
    if(L->Elemento.notaFinal > num) //comparoa nota do elemento anterior com a do num(maior)
    return L->Elemento.notaFinal;//se o anterior for maior que a do num, num agora e L->Elemento
    else 
    return num;
}
//A.6 iter
int MaiorNumeroListaITER(PNodo L){
  int num=L->Elemento.notaFinal;//declaracao do primerio da lista
  while(L!=NULL){
      if(L->Elemento.notaFinal > num){
        num=L->Elemento.notaFinal;
      }
      L=L->Prox;//so fora da verificacao e que o Prox arranca
  }
  return num;
}

//A.7 rec head tail correta
int numAlunoBetsfreq2E3(PNodo L){ 
  static float somamaisalta = -1; // static variable to keep track of the highest sum
  static int numAlmelhor = 0; // static variable to keep track of the student with the highest sum

  if(L != NULL){
    float soma = L->Elemento.notas[2] + L->Elemento.notas[3]; // sum of the third and fourth grades

    if(soma > somamaisalta){
      somamaisalta = soma; // se soma e maior que somamaisalta, soma mais alta atualiza o val
      numAlmelhor = L->Elemento.numAluno; // update the student with the highest sum
    }

    numAlunoBetsfreq2E3(L->Prox); // recursive call
  }

return numAlmelhor;
}

//A.7 rec tail head correta
int numAlunoBetsfreq2E3TaisHead(PNodo L){
  static float somamaisalta=-1;
  static int numAlmelhor=-1;
  if(L->Prox==NULL){//case base last node
    somamaisalta=L->Elemento.notas[2] + L->Elemento.notas[3];//static info collected
    numAlmelhor=L->Elemento.numAluno;
    return numAlmelhor; //final retunr  must be a numAluno type
  }
  numAlmelhor=numAlunoBetsfreq2E3TaisHead(L->Prox);//do ultimo a head
    if((L->Elemento.notas[2] + L->Elemento.notas[3])>somamaisalta){
      somamaisalta=L->Elemento.notas[2] + L->Elemento.notas[3];
      numAlmelhor=L->Elemento.numAluno;
      return numAlmelhor;
    }
    else{
      return numAlmelhor;
    }
}

//A.9 rec correta tails->head
int numAlunoPiorNotaTP1TP2Rec(PNodo L){
  static float menorvalorpossivelA=-1;
  static float menorvalorpossivelB=-1;
  static float notahorrosa=-1;
  static int numAluno=-1;
  if(L->Prox == NULL){ //caso base
    menorvalorpossivelA=L->Elemento.notas[0];
    menorvalorpossivelB=L->Elemento.notas[1];
    numAluno=L->Elemento.numAluno;
      if(menorvalorpossivelA<menorvalorpossivelB)
        notahorrosa=menorvalorpossivelA;
      else
      notahorrosa=menorvalorpossivelB;
    return numAluno;//return do numaluno na tail e comparar com as outras notas
  }
  numAluno=numAlunoPiorNotaTP1TP2Rec(L->Prox); //iteracoes ate a tail

  if(L->Elemento.notas[0]<notahorrosa){
    notahorrosa=L->Elemento.notas[0];
    return L->Elemento.numAluno;
  }
  if(L->Elemento.notas[1]<notahorrosa){
    notahorrosa=L->Elemento.notas[1];
    return L->Elemento.numAluno;
  }
  return numAluno;
}
//A.9 rec fazer head tails & itersativa


/*

float valormedioNotaFinal(PNodo L){
  float media=0;
  int contador=0;
  int sumfl=0;
  while(L!=NULL){
    contador++;
    sumfl+=L->Elemento.notaFinal;
    L=L->Prox;
  }
  printf("contador %d\n", contador);
  printf("soma finais %d\n", sumfl);
  media=(float)sumfl/(float)contador;
  return media;
}
*/
//A.10 iterativa correta

//A.10fazer recursiva

//A.11
//condicao >=k && menor de todos os notas finais
int menorNoatFialMIK(PNodo L, int K){ //retunr do numAluno
  int numALUNO=-1;
  int menorNota = __INT_MAX__;
  while(L!=NULL){
    if(L->Elemento.notaFinal>=K && L->Elemento.notaFinal<menorNota){//maior que k && menor que anteriror menor
    menorNota=L->Elemento.notaFinal;
    numALUNO=L->Elemento.numAluno;
  }
  L=L->Prox;
  }
  return numALUNO;
}

int menorNoatFialMIKrecheadtail(PNodo L, int K){//devolve numero
  static int numAluno=-1;
  static int notamaispequena=__INT_MAX__; //preserva a manipulacao em recursoes
  if(L!=NULL){
    if(L->Elemento.notaFinal>=K && L->Elemento.notaFinal<notamaispequena){
      notamaispequena=L->Elemento.notaFinal;
      numAluno=L->Elemento.numAluno;
    }
    //caso nao entre na condicao, vou prosseguir a recursiva, onde recorro a iteracao do elemento seguinte
    menorNoatFialMIKrecheadtail(L->Prox, K);
  }
  return numAluno;
}

//A.11
int menorNoatFinal(PNodo L, int K){//retorna a menor nota final
  int notamenormairoqueK=__INT_MAX__;
  if(L->Prox==NULL){//caso base
    if(L->Elemento.notaFinal >= K){
      notamenormairoqueK=L->Elemento.notaFinal;
      return notamenormairoqueK;
    }
    else{
      return notamenormairoqueK;///retorna o intmax
    }
  }//case base tail treatment
  notamenormairoqueK = menorNoatFinal(L->Prox, K);
  //enroll the carpet
  if(L->Elemento.notaFinal<notamenormairoqueK&&L->Elemento.notaFinal>=K){
    notamenormairoqueK=L->Elemento.notaFinal;
    return notamenormairoqueK;
  }
  return notamenormairoqueK;
}

//AXII
int contaelementosnotafinalentrek1k2(PNodo L, int K1, int K2){//head tails
  int cont=0;
  if(L==NULL){//caso nulo
    return 0;
  }
  if(L->Elemento.notaFinal>=K1 && L->Elemento.notaFinal<=K2){
    cont++;
  }
  cont += contaelementosnotafinalentrek1k2(L->Prox,K1, K2);
  //static logo ao recursar consigo ir sempre atualizando a contagem
  return cont;
}

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

//A13
  
PNodo removerelementonumALUNO(PNodo L, int num){
  PNodo anterior=NULL;
  PNodo atual=L;//L mantem a integridade

  while(atual!=NULL){//porque o atual vai aumentando ate 
    if(atual->Elemento.numAluno==num){//encontrou no pointer de atual
      if(anterior==NULL){//na cabeca
        L=L->Prox; //LIGACAO
      }
      else{//se nao estiver na cabeca
        anterior->Prox=atual->Prox; //LIGACAO
      }
      //se encontra faz o remove
      PNodo temporario=atual;//atual e que tem o num=
      libertarNodo(temporario);
    }
    else{//se nao encontrar atualiza a variavel para andar para a frente
    anterior=atual;//onde eles apontam
    atual=atual->Prox;
    }

  }
  return L;
}



PNodo removerNodeIgualNum(PNodo L, int num){//verficacao pendente sobre remover 1 nodo pois o numero de aluno e singular
  PNodo anterior=NULL;
  PNodo atual=L;
  while(atual != NULL){
    if(atual->Elemento.numAluno==num){
      if(anterior==NULL){
        L=atual->Prox;
      } else {
        anterior->Prox=atual->Prox;
      } 
      PNodo temp = atual;
      atual = atual->Prox;
      libertarNodo(temp);
    } else {
      anterior = atual;
      atual = atual->Prox;
    }
  }
  return L;
}

//A14
//funciona
PNodo removeunderKnotafinaliterativa(PNodo L, int K){
PNodo anterior=NULL;
PNodo atual=L;
  while(atual!=NULL){
    if(atual->Elemento.notaFinal<=K){
      if(anterior==NULL){//cabeca
        L=atual->Prox;
      }
      else{
        anterior->Prox=atual->Prox;
      }
      PNodo temp=atual;
      atual=atual->Prox;
      libertarNodo(temp);  
    }
    else{//se nao encontrar
    anterior=atual;
    atual=atual->Prox;
    }
  }
  return L;
}

PNodo removeallunderKnotafinal(PNodo L, int K){
  if(L == NULL)
    return NULL;

  if(L->Elemento.notaFinal <= K){//encontrou
    PNodo temp = L;
    L = L->Prox;
    libertarNodo(temp);
    return removeallunderKnotafinal(L, K);
  }
  else{//se o atual nao verificar a condicao
    L->Prox = removeallunderKnotafinal(L->Prox, K);
    return L;
  }
}

//A15 iter funciona bem
PNodo removeralligualaK(PNodo L,int K){
  PNodo anterior=NULL;
  PNodo atual=L;
  if(L==NULL){
    return NULL;
  }
  while(atual!=NULL){
    if(atual->Elemento.notaFinal==K){//encontrar no elemento
        if(anterior==NULL){
          L=atual->Prox;
        }
        else{
          anterior->Prox=atual->Prox;
        }
      //se encontrar
      PNodo temp=atual;
      atual=atual->Prox;
      libertarNodo(temp);
    } else { //se nao encontrar
      anterior=atual;
      atual=atual->Prox;
    }
  }
  return L;
}
//a15 +professor
PNodo remoervarios(PNodo L, int nota){
  PNodo P, Paux;
  //cabeca
  while(L!=NULL && L->Elemento.notaFinal==nota){
    Paux=L;
    L=L->Prox;
    Paux=libertarNodo(Paux);
  }
  if(L==NULL){
    return L;
  }
  //remover restantes elementos
  P=L;
  while(P->Prox!=NULL){
    if(P->Prox->Elemento.notaFinal==nota){
      Paux=P->Prox;
      P->Prox=Paux->Prox;
      Paux=libertarNodo(Paux);
    }
  }
}

//A15 rec funciona 
PNodo removeralligualaKrec(PNodo L, int K){
  if(L==NULL)
    return NULL;
  if(L->Elemento.notaFinal==K){
    PNodo temp=L->Prox;
    libertarNodo(L);
    return removeralligualaKrec(temp, K);
  }
  else{
    L->Prox = removeralligualaKrec(L->Prox, K);
    return L;
  }
}

//A.16
PNodo removerosNelementos(PNodo L, int N){
  PNodo atual=L;
  int contador=0;

  while(atual!=NULL && contador<N){
    PNodo temp = atual;
    atual = atual->Prox;
    libertarNodo(temp);
    contador++;
  }

  return atual;
}
//A.17
PNodo alistadivididaemnum(PNodo L, int num){
  PNodo atual=L;
  PNodo NOVALISTA=NULL;
  if(L==NULL)
  return NULL;
    while(atual!=NULL){
      if(atual->Elemento.numAluno==num){//se encontrar
          NOVALISTA=atual;//a segunda lista aponta para atual onde encontra
          break;//break the cicle
        }
      else{//se nao encontrar incrementa
        atual=atual->Prox;
      }
    }
    return NOVALISTA;
}
/*
PNodo BUBBLESORTLISTA(PNodo L){
  PNodo anterior=NULL;
  PNodo atual=L;
  PNodo maiornota=NULL;
  if(L=NULL){
    return NULL;
  }
  while(atual!=NULL){
    if(anterior==NULL){//pegar na cabeca
      maiornota=atual->Elemento.notaFinal;
    }
    else{
      if(anterior= )
    }
  }
}
*/

//Exercicio6
int maiorelementolistaligada(PNodo L){

  static int maior;
  if(L==NULL)
    return -1;
  //casobase
  if(L->Prox==NULL){
    maior=L->Elemento.notaFinal;
    return maior;
  }
  maior=maiorelementolistaligada(L->Prox);
  if(L->Elemento.notaFinal>maior){
    maior=L->Elemento.notaFinal;
    return maior;
  }

}


int maiorelementolistaligadaheadtail(PNodo L){
  static int maior;
  if(L==NULL){
    return -1;
  }
  if(L!=NULL){//iteracao recursiva ate utlimo
    if(L->Elemento.notaFinal>maior){
    maior=L->Elemento.notaFinal;
  }
}
maiorelementolistaligadaheadtail(L->Prox);
return maior;
}


//estudo
void showinfin(PNodo L){
  PNodo P=L;
  while(P!=NULL){
    mostrarElemento(P->Elemento);
    P=P->Prox;
  }
}

int containfimrec(PNodo L){
  static int conta=0;
  if(L!=NULL){
    conta++;
    containfimrec(L->Prox);
  }
  return conta;
}

int coantfimini(PNodo L){
  static int conta=0;
  if(L!=NULL){
    coantfimini(L->Prox);
    conta++;
  }
  return conta;
}

int contaigNrecHe(PNodo L, int N){
  static int conta=0;
  if(L!=NULL){
    if(L->Elemento.notaFinal==N){
      conta++;
      contaigNrecHe(L->Prox, N);
    }else{
      contaigNrecHe(L->Prox, N);
    }
    return conta;
  }
}

int contaifNTails(PNodo L, int N){
  static int conta =0;
  if(L!=NULL){
    contaifNTails(L->Prox, N);
      if(L->Elemento.notaFinal==N){
        conta++;
      }
      return conta;
  }
}

int contamaiorigualrechead(PNodo L, int N){\

  static int conta=0;
  if(L!=NULL){
    if(L->Elemento.notaFinal>=N){
      conta++;
    }
    contamaiorigualrechead(L->Prox, N);
  }
  return conta;
}

int contamaiorigualrectail(PNodo L, int N){
  static int conta;
  if(L!=NULL){
    contamaiorigualrectail(L->Prox, N);
    if(L->Elemento.notaFinal>=N)
      conta++;
  }
  return conta;
}


int maiorvaliter(PNodo L){
    if(L==NULL){
        return -1;
    }
    int maior = L->Elemento.notaFinal;
    PNodo P = L->Prox;
    if(P==NULL){
        return maior;
    }
    while(P!=NULL){
        if(P->Elemento.notaFinal>maior){
            maior = P->Elemento.notaFinal;
        }
        P=P->Prox;
    }
    return maior;
}

int MNFH(PNodo L){
int num;
if(L==NULL){
  return -1;
}
if(L->Prox==NULL){//ultimo elemento
  return L->Elemento.notaFinal;
}
num=MNFH(L->Prox);
if(L->Elemento.notaFinal>num){
  return L->Elemento.notaFinal;
}
else
return num;
}

//iter
int numalmelhor23(PNodo L){
  if(L==NULL)
    return -1;

  float maior;
  int num;

  PNodo P=L->Prox;
  maior ==L->Elemento.notas[2] + L->Elemento.notas[3]; //primeiro

  num = L->Elemento.numAluno;//primeiro

  if(P==NULL){ //so um elemento
    return L->Elemento.numAluno;
  }

  while(P!=NULL){
    if(P->Elemento.notas[2] + P->Elemento.notas[3]>maior){
      maior = P->Elemento.notas[2] + P->Elemento.notas[3];
      num=P->Elemento.numAluno;
    }
    P=P->Prox;
  }
  return num;
}

//rec bneste caso com maiorevou tails
int nummelhrorec23recTails(PNodo  L){
  static float somamaisalta = -1; // static variable to keep track of the highest sum
  static int numAlmelhor = -1; // static variable to keep track of the student with the highest sum

  if(L != NULL)
  {
    float soma = L->Elemento.notas[2] + L->Elemento.notas[3]; // sum of the third and fourth grades

    if(soma > somamaisalta){
      somamaisalta = soma; // se soma e maior que somamaisalta, soma mais alta atualiza o val
      numAlmelhor = L->Elemento.numAluno; // update the student with the highest sum
    }

    nummelhrorec23recTails(L->Prox); // recursive call
  }

return numAlmelhor;

}


int numpiorAluno(PNodo L){
  static float piornota = 21.0;
  static int pior=-1;

  if(L!=NULL){
    float soma=L->Elemento.notas[0]+L->Elemento.notas[1];
    if(soma<piornota){
      piornota=soma;
      pior=L->Elemento.numAluno;
    }
    numpiorAluno(L->Prox);
  }
  return pior;
}

INFO pioraluno(PNodo L){
  if(L==NULL)
    exit(0);
  INFO pioraluno;
  pioraluno=L->Elemento;
  PNodo P=L->Prox;
  int menor=L->Elemento.notas[0]+L->Elemento.notas[1];
  
  while(P!=NULL){
    if(P->Elemento.notas[0] + P->Elemento.notas[1]<menor){
      menor=P->Elemento.notas[0] + P->Elemento.notas[1];
      pioraluno=P->Elemento;
    }
    P=P->Prox;
  }
  return pioraluno;
}
//recursiva
INFO pioralunorec(PNodo L){
  INFO piro;
  static float nota=0;
  if(L==NULL)
    exit(0);

  if(L->Prox==NULL){
    nota=L->Elemento.notas[0]+L->Elemento.notas[1];
    return L->Elemento;
  }

  if(L!=NULL){
    piro=pioralunorec(L->Prox);
    if(L->Elemento.notas[0]+L->Elemento.notas[1]<nota){
      nota = L->Elemento.notas[0]+L->Elemento.notas[1];
      piro = L->Elemento;
      return piro;
    }
    else{
      return piro;
    }
  }
}

float mediaa(PNodo L){
  float soma=0.0;
  PNodo P=L;
  if(L==NULL){
    perror(0);
    return -1;
  }
  while(P!=NULL){
    soma+=P->Elemento.notaFinal;
    P=P->Prox;
  }
  int tam = tamanhoLista(L);
  float fintam =(float)tamanhoLista(L);
  return soma/tam;
}

float mediarec(PNodo L){
  float soma=0.0;
  if(L==NULL)
  {
    return 0.0;
  }
  soma = soma + L->Elemento.notaFinal + mediarec(L->Prox);//acumulador+nota+soam dos outros
  return soma;
}

//12 iter
int numentrk1k2(PNodo L,int k1, int k2){
  int contador=0;
  PNodo P=L;
  while(P!=NULL){
    if(P->Elemento.notaFinal>=k1&&P->Elemento.notaFinal<=k2){
      contador++;
    }
    P=P->Prox;
  }
  return contador;

}

int quantidadek1k2(PNodo L, int k1, int k2){
  int conta=0;
  if(L!=NULL){
    if(L->Elemento.notaFinal>=k1&&L->Elemento.notaFinal<=k2){
      conta++;
    }
    conta +=quantidadek1k2(L->Prox, k1, k2);
  }
  return conta;
}

//13 primeirro remove
void removenumAlunoiter(PNodo L, int N){
  PNodo aux=L->Prox;
    if(L->Elemento.numAluno==N&&L->Prox==NULL){
    L==NULL;
    exit(0);
  }
  if(L->Elemento.numAluno==N){
    L=L->Prox;
  }
  while(aux!=NULL){
    if(aux->Elemento.numAluno==N){
      L->Prox=aux->Prox;
    }
    L=L->Prox;
    aux=aux->Prox;
  }
}



//14 ligar+removerelibertar
PNodo removerigualaK(PNodo L, int K){
  PNodo anterior=NULL;
  PNodo atual=L;
  while(atual!=NULL){
    if(atual->Elemento.notaFinal<K){
      if(anterior==NULL){//sera a cabeca
        L=L->Prox;//liga
      }
      else{
        anterior->Prox=atual->Prox;//liga
      }
      //hora de remover depois de ligar
      PNodo temp=atual;
      atual=atual->Prox;
      libertarNodo(temp);
    }
    else{
      anterior=atual;
      atual=atual->Prox;
    }
  }
  return L;
}


//15
PNodo removernota(PNodo L, int K){
  PNodo anterior=NULL;
  PNodo atual=L;
  while(atual!=NULL){
    if(atual->Elemento.notaFinal==K){
      if(anterior==NULL){
        L=atual->Prox;
      }
      else{
        anterior->Prox=atual->Prox;
      }
      PNodo temp = atual;
      atual=atual->Prox;
      libertarNodo(temp);
    }
    else{
      anterior=atual;
      atual=atual->Prox;
    }
  }
  return L;
}

//16
PNodo removerosNelementos2(PNodo L, int N){
  PNodo atual=L;
  int conta=1;
  while(atual!=NULL&&conta<=N){
    PNodo temp = atual;
    L=atual->Prox;
    atual = atual->Prox;
    libertarNodo(temp);
    conta++;
  }
  return L;
}

//17 divir
void dividirlistaem2(PNodo L, int numal){
  PNodo Primeira=L;
  PNodo atual= L;
  PNodo Segunda=NULL;
  while(atual!=NULL){
    if(atual->Elemento.numAluno==numal){
      Segunda=atual->Prox;
      Primeira->Prox=NULL;
      break;
    }
    Primeira=Primeira->Prox;
  }
  printf("primeira\n");
  mostrarListaInicio(Primeira);
  printf("segunda\n");
  mostrarListaInicio(Segunda);
}



int somarec(PNodo L,int num){
  int soma=0;
if(L==NULL){
  return 0;
}
if(L->Elemento.notaFinal>=num){
  return L->Elemento.notaFinal+somarec(L->Prox, num);
}else
  return somarec(L->Prox, num);
}


//remover o noido mais na cabeca maior que n
PNodo removerprimeriomaiorquen(PNodo L, int N){
  if(L==NULL){
    return NULL;
  }
  PNodo atual=L;
  PNodo anterior=NULL;
  int status=0;
  while(atual!=NULL){
    if(status==0){
      if(atual->Elemento.notaFinal>N){
        if(anterior==NULL){
          L=L->Prox;
        }
        else{
          anterior->Prox=atual->Prox;
        }
        PNodo temp = atual;
        atual=atual->Prox;
        libertarNodo(temp);
        status = 1;
      }else{

      anterior=atual;
      atual=atual->Prox;
      }
    }else
      break;
  }
    return L;
}



































































//7 prof
/*
INFO melhorsomafreq(PNodo L){
  INFO X;
  X.numAluno = -1;

  if(L==NULL){
    return X;
  }
  X=melhorsomafreq(L->Prox);
  if(L->Elemento.notas[2]+L->Elemento.notas[3]>X.notas[2] + X.notas[3])
    return L->Elemento;
    else
    return X;
}
*/
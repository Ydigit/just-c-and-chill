
/* ------------------------------------------------------- */
/* ---- prot�tipos/headers das fun��es da biblioteca ----- */
/* ------------------------------------------------------- */

PNodoABP criarABPAleatoria (int, int);

void displayRootAndInOrderTraversal(PNodoABP );

void raizemordem(PNodoABP );

int niveis(PNodoABP );

INFOABP maiorelemento(PNodoABP );

INFOABP maiorrec(PNodoABP );

INFOABP menoriter(PNodoABP );

INFOABP menorrec(PNodoABP);

int contasupN(PNodoABP , int );

int contaelesupAinfN(PNodoABP , int , int );

INFOABP numeroigA(PNodoABP , int );

int contamaiorAmenorBig(PNodoABP , int , int );

int contamenoeqAmaiorB(PNodoABP , int , int );

PNodoABP removerABP2 (INFOABP , PNodoABP );

void BSTtoArray(PNodoABP , INFOABP* , int* );

INFOABP* transformBSTtoArray(PNodoABP );

void folhaproxraizafastadoraiz(PNodoABP );


int countNodes(PNodoABP );

int contanodos(PNodoABP );

PNodoABP removiomaior(PNodoABP );

PNodoABP removemenor(PNodoABP );

PNodoABP inseriratoa (INFOABP , PNodoABP );

int howlev(PNodoABP );

int levelup(PNodoABP );

INFOABP lesser(PNodoABP );

INFOABP lesserrec(PNodoABP );

int numelementosupA(PNodoABP , int );

int numelementosupAmenN(PNodoABP , int , int );

//-------------------stude------------------


void imprimeraiz_and_emtravessia(PNodoABP T);

int altura(PNodoABP );

INFOABP maiornumalunorec(PNodoABP );

int numMAtesteStyle(PNodoABP , int );

int numeleMAeMN(PNodoABP , int , int );

INFOABP numAleq(PNodoABP , int );

int numeroeleMIAoumIB(PNodoABP , int , int );

int numelemAouMB(PNodoABP , int , int );









/* ------------------------------------------------------- */
/* -------------- implementa��o das fun��es -------------- */
/* ------------------------------------------------------- */

PNodoABP criarABPAleatoria (int inf, int sup)
{
  int k, N;
  INFOABP X;
  PNodoABP T;
  
  N = gerarNumeroInteiro(inf, sup);
  T = criarABP();
  k = 1;
  while (k <= N){
  	X = criarElementoABP();
  	if (pesquisarABP(X,T) == NULL){
  	  T = inserirABP(X,T);
  	  k = k + 1;
	}
  }
  return T;
}

//2
// Função para exibir a raiz da árvore e todos os elementos usando a travessia em ordem
// Função para exibir a raiz da árvore e todos os elementos usando a travessia em ordem
void displayRootAndInOrderTraversal(PNodoABP T) {
    static int rootDisplayed = 0; // Variável para verificar se a raiz já foi exibida

    if (T != NULL) {
        if (!rootDisplayed) {
            printf("Root of T: ");
            mostrarElementoABP(T->Elemento);
            printf("\n");
            rootDisplayed = 1; // Marque a raiz como exibida
        }

        displayRootAndInOrderTraversal(T->Esquerda); // Primeiro, visite a subárvore esquerda

        // Para outros nós (não-raiz), apenas exiba o elemento
        if (rootDisplayed) {
            mostrarElementoABP(T->Elemento);
        }

        displayRootAndInOrderTraversal(T->Direita); // Finalmente, visite a subárvore direita
    }
}

void raizemordem(PNodoABP T){
  int static flagaberto = 0;
  if(T!=NULL){
    if(flagaberto==0){
      printf("raiz =");
      mostrarElementoABP(T->Elemento);
      flagaberto=1;
    }
    raizemordem(T->Esquerda);
    if(flagaberto==1){
      mostrarElementoABP(T->Elemento);
    }
    raizemordem(T->Direita);
 }
}










/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%  ESTUDO  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
void imprimeraiz_and_emtravessia(PNodoABP T){
  int static flag =0;
  //primeira interacao na rec, seguida nas outras
  if(T!=NULL){
    if(flag==0){//uma vez em fal g 0 r para a razi unica
      printf("raizz - > ");
      mostrarElementoABP(T->Elemento);
      printf("\n");
      flag =1;
    }
    imprimeraiz_and_emtravessia(T->Esquerda);
    if(flag==1)
      mostrarElementoABP(T->Elemento);
    imprimeraiz_and_emtravessia(T->Direita);
  }
}

/*
int numMAtesteStyle(PNodoABP T, int A)
{
  int esq, dir;
  // caso terminal/base
  if (T == NULL)
    return 0;
  // caso geral
  if (T->Elemento.numAluno <= A)
    return numMAtesteStyle(T->Direita, A);
  esq = numMAtesteStyle(T->Esquerda, A);
  dir = numMAtesteStyle(T->Direita, A);
  return 1 + esq + dir;
}
*/
int numMAtesteStyle(PNodoABP T, int A)
{
  //dec
  int esq=0, dir=0;
  //terminal
  if(T==NULL){
    return 0;
  }
  //orientar
  if(T->Elemento.numAluno<=A)
    return numMAtesteStyle(T->Direita,A);
  //preencher esq e dir
  esq =numMAtesteStyle(T->Esquerda,A);
  dir=numMAtesteStyle(T->Direita,A);
    if(T->Elemento.numAluno>A&&T->Esquerda==NULL && T->Direita==NULL)
      return 1 + esq + dir;
  else
    return esq + dir;

}

int menorval(PNodoABP T){
  int esq, dir;
  if(T==NULL){
    return -1;
  }
  else
    return T->Elemento.numAluno;
  if(T->Elemento.numAluno<=0){
    return menorval(T->Direita);
    esq = menorval(T->Esquerda);
    dir= menorval(T->Direita);
    if(T->Elemento.numAluno>0)
      return esq;
    else
    return dir;
  }
}

//entre o A e o N
//>A e <=N
/*
int numeleMAeMN(PNodoABP T, int A, int N){
  //declaracao
  int esq, dir;
  //TERMINAL
  if(T==NULL){
    return 0;
  }
  //orientar
  if(T->Elemento.numAluno<=A)
    return numeleMAeMN(T->Direita, A, N);
  //preencher as declaracoes
  esq=numeleMAeMN(T->Esquerda, A, N);
  dir=numeleMAeMN(T->Direita, A, N);
  //ja verifiquei que o o A sera menor por isso desce
  //falta o N
  //o primeiro if destes sera a comparacao dos ultimos elementos
  if(T->Elemento.numAluno<=N)
    return 1+esq+dir;
  else  
    return esq + dir;
}
*/
//>A&&<=N
//1condicao e com o N
int numeleMAeMN(PNodoABP T, int A, int N){
  //declaracao
  int esq, dir;
  //TERMINAL
  if(T==NULL){
    return 0;
  }
  //orientar
  if(T->Elemento.numAluno>N)
    return numeleMAeMN(T->Esquerda, A, N);
  //preencher as declaracoes
  esq=numeleMAeMN(T->Esquerda, A, N);
  dir=numeleMAeMN(T->Direita, A, N);
  //ja verifiquei que o o A sera menor por isso desce
  //falta o N
  //o primeiro if destes sera a comparacao dos ultimos elementos
  if(T->Elemento.numAluno>A)
    return 1+esq+dir;
  else  
    return esq + dir;
}
//VIII
INFOABP numAleq(PNodoABP T, int A){
  //n preciso declaracoes, so vou a um aldo , so um elemento
  //terminal
  if(T==NULL){
    INFOABP naoha;
    naoha.numAluno=-99;
    return naoha;
  }
  //orientacao
  if(T->Elemento.numAluno<A)
    return numAleq(T->Direita, A);
  if(T->Elemento.numAluno>A)
    return numAleq(T->Esquerda,A);
  //condicoes de verificacopes
  if(T->Elemento.numAluno==A)
    return T->Elemento;
}

int numeroeleMIAoumIB(PNodoABP T, int A, int B){
  //dec para ir para os dois lados
  int esq, dir;
  //terminal 
  if(T==NULL)
    return 0;
  //orientacoes neste caso >=A&&<=B   mas ponho so uma
  if(T->Elemento.numAluno<A)
    return numeroeleMIAoumIB(T->Direita, A, B);
  //encher as dec
  esq=numeroeleMIAoumIB(T->Esquerda, A, B);
  dir= numeroeleMIAoumIB(T->Direita, A, B);
  //condicao da segunda parte, no caso de B
  //pois ja me certifiquei que tenho o T>=A
  if(T->Elemento.numAluno<=B)
    return 1 + esq + dir;
  else
    return esq + dir;
}
//como e uma contasgem verfico mais que uma vez se preciso
//tenho dew fazer declaracoes
int numelemAouMB(PNodoABP T, int A, int B){
  //dec
  int esq, dir;
  //terminal
  if(T==NULL){
    return 0;
  }
  //orientar
  //primeiro para o A e na seguinte incluir
  //na verificacao ja tenho tudo maior q A logo trato so para B
  
  if(T->Elemento.numAluno>=A)//rota menores que A
    return numelemAouMB(T->Esquerda,A, B);
  if(T->Elemento.numAluno<=B)//rota mairoes que B
    return numelemAouMB(T->Direita,A,B);
  //prencher as decs
  esq=numelemAouMB(T->Esquerda, A, B);
  dir=numelemAouMB(T->Direita, A, B);
  //condicoes de verificacao com returns
  //tenho de por 2 orientacoes, uma para B
  if(T->Elemento.numAluno<A||T->Elemento.numAluno>B)//cobre as duas rotas
    return 1+esq+dir;//puca as que foram verificadas
  else
    return esq + dir;//puxa os que nao foram verificados pelo if, ex:NULL
}
//ser avore binaria de pesquisan ao faz diferenca











/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% stor %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
/*
PNodoABP criarABPAleatoria (int inf, int sup)
{
  int k, N;
  INFOABP X;
  PNodoABP T;
  
  N = gerarNumeroInteiro(inf, sup);
  T = criarABP();
  k = 1;
  while (k <= N){
  	X = criarElementoABP();
  	if (pesquisarABP(X,T) == NULL){
  	  T = inserirABP(X,T);
  	  k = k + 1;
	}
  }
  return T;;
}


// ABP não vazia
INFOABP maiorElemento_It (PNodoABP T)
{
  while (T->Direita != NULL)
    T = T->Direita;
  return T->Elemento;
}

// ABP não vazia
INFOABP maiorElemento_Rec (PNodoABP T)
{
  // caso terminal/base
  if (T->Direita == NULL)
    return T->Elemento;
  // caso geral
  return maiorElemento_Rec(T->Direita);
}

int numElementosNASupA (PNodoABP T, int A)
{
  int esq, dir;
  // caso terminal/base
  if (T == NULL)
    return 0;
  // caso geral
  if (T->Elemento.numAluno <= A)
    return numElementosNASupA(T->Direita, A);
  esq = numElementosNASupA(T->Esquerda, A);
  dir = numElementosNASupA(T->Direita, A);
  return 1 + esq + dir;
}

int numElementosNA_NF (PNodoABP T, int A, int N)
{
  int esq, dir;
  // caso terminal/base
  if(T == NULL)
    return 0;
  // caso geral
  if(T->Elemento.numAluno <= A)
    return numElementosNA_NF(T->Direita, A, N);
  esq = numElementosNA_NF(T->Esquerda, A, N);
  dir = numElementosNA_NF(T->Direita, A, N);
  if(T->Elemento.notaFinal <= N)
    return 1 + esq + dir;
  else
    return esq + dir;
}
*/















/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
//3  mostrar a quantidade de niveis e altura
//um calculo para a arvore da esquerda e uma da direita
/*
int niveis(PNodoABP T) {
    if (T == NULL) {
        return 0;
    } else {
        int esq = niveis(T->Esquerda);
        int dir = niveis(T->Direita);
        if (esq > dir) {
            return esq + 1;
        } else {
            return dir + 1;
        }
    }
}

int niveis(PNodoABP T){
  if(T==NULL){
    return 0;
  }
  int esq=niveis(T->Esquerda);
  int dir=niveis(T->Direita);
  if(esq>dir)
    return esq + 1;
  else
    return dir+1;
}

/*estudo/ niveissera o numero de niveis desde o 0
int niveis
int numeroniveis(PNodoABP T){
  if(T==NULL){
    return 0;
  }
  int esq = numeroniveis(T->Esquerda);
  int dir= numeroniveis(T->Direita);
  if(esq>dir)
    return esq +1;
  else
    return dir+1;
}



//4 T nao null
INFOABP maiorelemento(PNodoABP T){
  INFOABP maior;
  while(T->Direita!=NULL){
    T=T->Direita;
  }
  return T->Elemento;
}
//4rec
INFOABP maiorrec(PNodoABP T){
  INFOABP resultado;
  if(T->Direita==NULL){
    return T->Elemento;
  }
  resultado=maiorrec(T->Direita);
  return resultado;
}

/*prof!!!!!***************
INFOABP maiorrec(PNodoABP T){
  if(T->Direita==NULL)
    return T->Elemento;
  INFOABP maior = T->Elemento;
  maior=maiorrec(T->Direita);
  return maior;
}



//iter

INFOABP menoriter(PNodoABP T){
INFOABP menor;
  if(T==NULL){
    return  menor;
  }
  while(T->Esquerda!=NULL){
    T=T->Esquerda;
  }
  return T->Elemento;
}



//rec
/*
INFOABP menorrec(PNodoABP T){
  INFOABP menor;
  if(T==NULL)
    return menor;
  if(T->Esquerda==NULL){
    return T->Elemento;
  }
  menor=menorrec(T->Esquerda);
  return menor;
}


INFOABP menorrec(PNodoABP T){
  INFOABP menro;
  if(T==NULL)
    return menro;
  if((T->Esquerda==NULL))
    return T->Elemento;
  menro = menorrec(T->Esquerda);
  return menro;
}

//superior a N
//6
int contasupN(PNodoABP T, int N){
  if(T==NULL){
    return 0;
  }
  int conta =0;
  INFOABP atual=T->Elemento;
  int esq = contasupN(T->Esquerda, N);
  int dir  = contasupN(T->Direita, N);
  if(atual.numAluno>N)
    conta = 1;
  return conta + esq + dir;
}

//7
int contaelesupAinfN(PNodoABP T, int A, int N){
  if(T==NULL){
    return 0;
  }
  INFOABP atual = T->Elemento;
  int conta =0;
  int esq = contaelesupAinfN(T->Esquerda, A, N);
  int dir = contaelesupAinfN(T->Direita, A, N);
  if(atual.numAluno>A&&atual.notaFinal<=N)
    conta =1;
  return conta + esq + dir;
}

//8
INFOABP numeroigA(PNodoABP T, int A) {
    if (T == NULL) {
        INFOABP negativo;
        negativo.numAluno = -1;
        return negativo;
    }

    INFOABP atual = T->Elemento;

    if (atual.numAluno == A) {
        return atual;
    } else if (A < atual.numAluno) {
        return numeroigA(T->Esquerda, A);
    } else {
        return numeroigA(T->Direita, A);
    }
}

int contamaiorAmenorBig(PNodoABP T, int A, int B){
  if(T==NULL){
    return 0;
  }
  int conta=0;
  INFOABP atual = T->Elemento;
  int esq = contamaiorAmenorBig(T->Esquerda, A, B);
  int dir = contamaiorAmenorBig(T->Direita, A, B);
  if(atual.numAluno>=A&&atual.numAluno<=B){
    conta =1;
  }
  return conta + esq + dir;
  
}

//CONTADOR TAMBEM 
int contamenoeqAmaiorB(PNodoABP T, int A, int B){
  if(T==NULL){
    return 0;
  }
  //verifiar p atual
  int atual=T->Elemento.numAluno;
  int conta=0;
  int esq = contamenoeqAmaiorB(T->Esquerda, A, B);
  int dir = contamenoeqAmaiorB(T->Direita, A, B);
  if(atual < A || atual>B){
    conta =1;
  }
  return conta+esq+dir;
}

//11 remover um elemento X

PNodoABP removerABP2 (INFOABP X, PNodoABP T)
{
if (compararElementosABP(X, T->Elemento) == 0) { // X == T®Elemento
T = removerNodoABP(T);
return T;
}
if (compararElementosABP(X, T->Elemento) == -1) // X < T®Elemento
T->Esquerda = removerABP2(X, T->Esquerda);
else
T->Direita = removerABP2(X, T->Direita);
return T;
}



int countNodes(PNodoABP T) {
    if (T == NULL) {
        return 0;
    }
    return 1 + countNodes(T->Esquerda) + countNodes(T->Direita);
}

void BSTtoArray(PNodoABP T, INFOABP* array, int* i) {
    if (T != NULL) {
        BSTtoArray(T->Esquerda, array, i);
        array[*i] = T->Elemento;
        (*i)++;
        BSTtoArray(T->Direita, array, i);
    }
}

INFOABP* transformBSTtoArray(PNodoABP T) {
    int n = countNodes(T);
    INFOABP* array = (INFOABP*)malloc(n * sizeof(INFOABP));
    int i = 0;
    BSTtoArray(T, array, &i);
    return array;
}

int contanodos(PNodoABP T){
  if(T==NULL)
    return 0;
return 1 + contanodos(T->Esquerda )+contanodos(T->Direita) ;
}
//nivel folha mais longe
int nivelfolhamaislongap(PNodoABP T){
  if(T==NULL)
    return 0;
  int esq=nivelfolhamaislongap(T->Esquerda);
  int dir = nivelfolhamaislongap(T->Direita);
  if(esq>dir)
    return 1 + esq;
  else
    return dir+1; 
  }


//13 nivel de folha mais proxima e mais afastado
//
void folhaproxraizafastadoraiz(PNodoABP T) {
    int minLevel = 0;
    int maxLevel = 0;

    if (T == NULL) {
        printf("A árvore está vazia.\n");
        return;
    }
    else{

      if (T->Esquerda == NULL && T->Direita == NULL) {
          printf("o nivel da mais proxima da raiz e %d\n", minLevel);
          printf("o nivel da mais longe e  %d\n", maxLevel);
          return;
      }

      // Se a árvore tem mais de um nó
      int longe = nivelfolhamaislongap(T);

      printf("o nivel da mais proxima da raiz e %d\n", minLevel);
      printf("o nivel da mais longe e  %d\n", longe-1);
    }

}


//14 remover maior com numAluno, o maior será o da direita
PNodoABP removiomaior(PNodoABP T){
  if(T==NULL)
    return NULL;
  if(T->Direita==NULL){ // agarrei o maior
    PNodoABP temp = T->Esquerda;
    T = removerNodoABP(T);
    return temp;
  }

  T->Direita = removiomaior(T->Direita);
  return T;
}

PNodoABP removere(PNodoABP T){
  if(T==NULL)
    return NULL;
  if(T->Direita==NULL){
    PNodoABP temp = T->Esquerda;
    T=removerNodoABP(T);
    return temp;
  }
  //ja removi o T direito falta ligar oa meu t final odne os finais estao
  T->Direita=removere(T->Direita);
  //o removere tdireito vai retornar o esqeurdo filho do uktimo

}


PNodoABP removemenor(PNodoABP T){
  if(T==NULL)
    return NULL;
  if(T->Esquerda==NULL){//spoiler e o menor, este return via oreecher o meu esq
  PNodoABP temp = T->Direita;
  T=removerNodoABP(T);
  return temp;
  }
  T->Esquerda=removemenor(T->Esquerda);
}

//16
PNodoABP inserirABP2 (INFOABP X, PNodoABP T)
{
  if (T == NULL){
    T = criarNodoABP(X);
    return T;
  }
  if (compararElementosABP(X, T->Elemento) == -1)   // X < T->Elemento
    T->Esquerda = inserirABP(X, T->Esquerda);
  else
    T->Direita = inserirABP(X, T->Direita);
  return T;
}


PNodoABP inseriratoa(INFOABP X, PNodoABP T){
  if(T==NULL){
    T=criarNodoABP(X);
    return T;
  }
  if(compararElementosABP(X,T->Elemento)==-1){//X e menor que atual
    T->Esquerda=inseriratoa(X,T->Esquerda);
  }
  else
  T->Direita= inseriratoa(X,T->Direita);
  return T;
}

//st      ********PROFESSOR*********
int levelup(PNodoABP T){
  if(T==NULL){
    return 0;
  }
  int esq = levelup(T->Esquerda);
  int dir = levelup(T->Direita);
  if(esq>dir)
    return esq + 1;
  else
    return dir + 1;
}

//lesser
INFOABP lesser(PNodoABP T){
  INFOABP m;
  if(T==NULL)
    return m;
  while(T->Esquerda!=NULL){
    T=T->Esquerda;
  }
  if(T->Esquerda==NULL)
    return T->Elemento;
}

INFOABP lesserrec(PNodoABP T){
  INFOABP mm;
  if(T==NULL){
    return mm;
  }
  if(T->Esquerda==NULL)
    return T->Elemento;
  mm=lesserrec(T->Esquerda);
  return mm;
}

int numelementosupA(PNodoABP T, int A){
  int esq, dir;
  //casobase
  if(T==NULL)
    return 0;
    //casegeral
    //se o t for maior que A vai a esq e direita,
    //se for menor, vous o a adireita e nao somo nada
  if(T->Elemento.numAluno<=A)
    return numelementosupA(T->Direita, A);

  esq=numelementosupA(T->Esquerda, A);
  dir=numelementosupA(T->Direita, A);

    return 1+esq+dir;
}


int numelementosupAmenN(PNodoABP T, int A, int N){
  int esq, dir;
  //casobase
  if(T==NULL)
    return 0;
    //casegeral
    //se o t for maior que A vai a esq e direita,
    //se for menor, vous o a adireita e nao somo nada
  if(T->Elemento.numAluno<=A)
    return numelementosupAmenN(T->Direita, A, N);

  esq=numelementosupAmenN(T->Esquerda, A, N);
  dir=numelementosupAmenN(T->Direita, A, N);

  if(T->Elemento.notaFinal>=N)
    return 1+esq+dir;
  else
    return esq + dir;
}


int multiplicarFolhas(PNodoABP T) {
    // Caso base: se a árvore é nula, retorna 1
    if (T == NULL) {
        return 1;
    }

    // Se o nó atual é uma folha (não tem filhos)
    if (T->Esquerda == NULL && T->Direita == NULL) {
        // Retorna o valor do nó
        return T->Elemento.numAluno;
    }

    // Caso geral: multiplica os valores das folhas da subárvore esquerda e da subárvore direita
    return multiplicarFolhas(T->Esquerda) * multiplicarFolhas(T->Direita);
}

*/
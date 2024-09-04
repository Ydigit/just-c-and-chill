
/* ------------------------------------------------------- */
/* ---- prot�tipos/headers das fun��es da biblioteca ----- */
/* ------------------------------------------------------- */

// opera��o apenas para controlo
//   - n�o faz parte da EAD Pilha
//   - mostra a Pilha do topo para o fundo
void mostrarPilha (PNodoPilha);

PNodoPilha criarPilhaAleatoria (int, int);


/* ------------------------------------------------------- */
/* -------------- implementa��o das fun��es -------------- */
/* ------------------------------------------------------- */

// opera��o apenas para controlo
//   - n�o faz parte da EAD Pilha
//   - mostra a Pilha do topo para o fundo
void mostrarPilha (PNodoPilha S)
{
  PNodoPilha P = S;
  while (P != NULL){
    mostrarElementoP(P->Elemento);
    P = P->Anterior;
  }
}

PNodoPilha criarPilhaAleatoria(int inf, int sup)
{
  int N, k;
  PNodoPilha S;
  INFOP X;

  N = gerarNumeroInteiro(inf, sup);
  S = criarPilha();
  k = 1;
  while(k <= N){
    X = criarElementoP();
    S = push(X, S); //enfio o x criado,elemento em S
    k = k + 1;
  }
  return S;
}

//AII
void devolve2ndtopSalterando(PNodoPilha S) {
  if (S == NULL || S->Anterior == NULL) {
    // Stack has less than 2 elements
    printf("Stack has less than 2 elements\n");
    return;
  }
  // aqui retiro o de cima
  PNodoPilha popedpile = pop(S);
  // Display the popedpile element
  mostrarElementoP(popedpile->Elemento); //mostra o anterior
  free(popedpile);
  // Display the new top element


  
}

//AIII
//prof
void devolve2ndtopS(PNodoPilha S) {
  if (S == NULL || S->Anterior == NULL) {
    // Stack has less than 2 elements
    printf("Stack has less than 2 elements\n");
    exit(0);
  }
  // Return the data in the second element from the top
  mostrarElementoP(S->Anterior->Elemento);//o elem do anterior onde s aponta
}

//AIV deveria retornar o infop
INFOP returnesimoeelemento(PNodoPilha S, int n){
  int contador=1;
  if(S==NULL || n <= 0)
    exit(0);
  while(contador!=n){
    S=S->Anterior;
    contador++;
  }
  mostrarElementoP(S->Elemento);
  return S->Elemento;
}

//AIV com return e print na main do elemento em questao
//aqui tenho double pointer
INFOP returnesimoeelementomain(PNodoPilha *S, int N){//entra endereco de ponteiro para ponteiro para a pilha
  int contador=1;
  if(*S==NULL||N<=0)
    exit(0);
  while(contador<N){
    *S=pop(*S);
    contador++;
  }
  if(*S==NULL){
    printf("ups tampas removidas ficou vazio");
    exit(0);
  }
  else{
    return (*S)->Elemento;
  }
}

//----------------------------------------------------
//AV
//return do element de n
//dar pop ate ao n-1
INFOP returnnelementnotouching(PNodoPilha S, int N){
  INFOP resultado;
  int contador=1;
  PNodoPilha auxStack = NULL; // pilha auxiliar

  if(S==NULL || N<1){
    printf("tamanho mini ou lista vazia");
    exit(0);
  }
  // pop out
  while(contador<=N && S != NULL){
    auxStack = push(topo(S), auxStack);
    S = pop(S);
    contador++;
  }//enche o aux ate ao topo ser o meu n

  if(contador == N+1 && auxStack != NULL){
    resultado = topo(auxStack);
  }
  // pop in 
  while(auxStack != NULL){//esvaziar completa
    S = push(topo(auxStack), S);
    auxStack = pop(auxStack);
  }
  return resultado;
}
//VI e VII
INFOP forkdeepdownnotouching(PNodoPilha S){
  INFOP deep;
  PNodoPilha aux=NULL;
  if(S==NULL){
    exit(0);
  }
  while(S!=NULL){
    aux = push(topo(S), aux);
    S=pop(S);
  }
  if(S==NULL)//se S esta vazia topo de aux tem o deep
    deep=topo(aux);
  //pop in
  while(aux!=NULL){
    S=push(topo(aux), S);
    aux=pop(aux);
  }
  return deep;
}

INFOP fork3rdfromdeep(PNodoPilha S){
  INFOP r3rdeep;
  int miniconta=1;
  PNodoPilha auxStack=NULL; //iuniciar com NULL para nao escrever mal sem querer
  
  if(S==NULL){
    exit(0);
  }
  //primeiro pop out elimino todos
  while(S!=NULL){//ate tirar tudo
    auxStack=push(topo(S), auxStack);
    S=pop(S);
  }
  //meter os 3top de aux
  while(auxStack!=NULL){//mete ate na terceira
    S=push(topo(auxStack), S);
    auxStack=pop(auxStack);
      if(miniconta==3)
        r3rdeep=topo(S);
    miniconta++;
  }//aqui S ja tem no topo o 3 elemento
  //meter o resto ate aux tar vazio
  while(auxStack!=NULL){
    S=push(topo(auxStack), S);
    auxStack=pop(auxStack);
  }
  return r3rdeep;
}

INFOP touch3rd(PNodoPilha S){
  INFOP result;
  int size = 0;
  PNodoPilha temp = S;

  // Calculate the size of the stack
  while(temp != NULL){
    temp = temp->Anterior;
    size++;
  }

  // Calculate the target index
  int target = size - 3;
  // If the stack has less than 3 elements, return NULL
  if(target < 0){
    exit(0);
  }
  // Iterate to the target element
  for(int i = 0; i < target; i++){
    S = S->Anterior;
  }

  // Get the target element
  result = S->Elemento;

  return result;
}

//DUVIDA PPROF
void trocatopunder(PNodoPilha S){
  if(S==NULL||S->Anterior==NULL){//nao pode ter 1 ele
    exit(0);
  }

  PNodoPilha aux=NULL;
  INFOP fim;
  INFOP inicio = S->Elemento;//feito

  while(S!=NULL){
    //definir fim
    if(S->Anterior==NULL){
      fim=S->Elemento;
    }
    aux=push(topo(S),aux);
    S=pop(S);
  }
  //repor S
  while(aux!=NULL){
    INFOP topoAux = topo(aux);
    if(compararElementosP(topoAux, fim) == 0){
      S=push(inicio, S);
    }
    else if(aux->Anterior == NULL){
          S=push(fim, S);
        }
    else {
      S=push(topoAux, S);
    }
    
    aux=pop(aux);
  }
  mostrarPilha(S);
}

void rearrange(PNodoPilha S) {
    PNodoPilha aux1 = NULL, aux2 = NULL;
    while (S != NULL) {
        INFOP elem = topo(S);
        S = pop(S);
        if (elem.notaFinal < 10) {
            aux1 = push(elem, aux1);
        } else {
            aux2 = push(elem, aux2);
        }
    }

    while (aux1 != NULL) {
        S = push(topo(aux1), S);
        aux1 = pop(aux1);
    }
    while (aux2 != NULL) {
        S = push(topo(aux2), S);
        aux2 = pop(aux2);
    }
    mostrarPilha(S);
}

//estudo

int calctam(PNodoPilha P){
  PNodoPilha L=P;
  int conta=0;
  while(L!=NULL){
    conta++;
    L=L->Anterior;
  }
  return conta;
}


//1
PNodoPilha criarpilha(int inf, int sup){
  PNodoPilha S = criarPilhaAleatoria(inf, sup);
  return S;
}
//2 
void mostrarP(PNodoPilha P){
  PNodoPilha A=P;
  while(A!=NULL){
    mostrarElementoP(A->Elemento);
    A=A->Anterior;
  }
}

//3 2 topo inalterada
INFOP devolve2topINAL(PNodoPilha P){
  if(P==NULL||P->Anterior==NULL){
    perror("tamanho reduzido");
    exit(0);
  }
  else{
    return P->Anterior->Elemento;
  }
}

INFOP devolveNeleAlterar(PNodoPilha S, int n){
  PNodoPilha P=S;
  int contador=1;
  if(P==NULL || n <= 0)
    exit(0);
  while(contador!=n){
    P=S->Anterior;
    contador++;
  }
  return P->Elemento;
}

INFOP devolveNeleAlterarpop(PNodoPilha S, int n){//topo do S
  PNodoPilha aux=NULL;
  INFOP Nele;
  if(S==NULL||n<0){
    perror("size is little");
    exit(0);
  }
  int cont=1;
  while(cont <= n){
    cont++;
    aux=push(topo(S), aux);
    S=pop(S);
  }
  Nele=aux->Elemento;
  //pop in

  while(aux!=NULL){
    S=push(topo(aux),S);
    aux=pop(aux);
  }

  return Nele;

}

INFOP lastpointeralterando(PNodoPilha P){
  INFOP last;
  PNodoPilha S=P;
  int ta=0;
  int cont=1;
  while(S!=NULL){
    ta++;
    S=S->Anterior;
  }
  while(cont<ta){
    cont++;
    P=pop(P);

  }
  return P->Elemento;
}

INFOP elnotouch(PNodoPilha P){
  if(P==NULL){
    exit(0);
  }
  INFOP res;
  PNodoPilha aux=NULL;
  while(P!=NULL){
    aux=push(topo(P),aux);
    P=pop(P);
  }
  res=aux->Elemento;
  while(aux!=NULL){
    P=push(topo(aux),P);
    aux=pop(aux);
  }
  return res;
}

INFOP Nfrombellow(PNodoPilha P){
  if(P==NULL){
    exit(0);
  }
  INFOP res;
  PNodoPilha paralela=P;
  PNodoPilha aux=NULL;
  int a;
  int conta=1;
  printf("seleciona o numero desde cima\n");
  scanf("%d", &a);
  int grandeza=0;
  while(paralela!=NULL){
    grandeza++;
    paralela=paralela->Anterior;
  }
  if(a>grandeza){
    perror("numero de posiciao e > ao tam\n");
    exit(0);
  }
  while(P!=NULL){
    aux=push(topo(P), aux);
    P=pop(P);
  }
  while(conta<a ){//aqui ele so me vai tirar da tampa ate ao anterior quye quero desde cima
    P=push(topo(aux), P);
    aux=pop(aux);
    conta++;
  }
  res=aux->Elemento;
  while(aux!=NULL){
    P=push(topo(aux), P);
    aux = pop(aux);
  }
  return res;
}

void Change(PNodoPilha P){
  if(P==NULL){
    exit(0);
  }
  PNodoPilha aux=NULL;
  INFOP cima;
  INFOP baixo;

  cima = P->Elemento;
  P=pop(P);

  while(P!=NULL){
    aux=push(topo(P), aux);
    P=pop(P);
  }

  baixo=aux->Elemento;
  aux=pop(aux);

  P=push(cima, P);
  while(aux!=NULL){
    P=push(topo(aux), P);
    aux=pop(aux);
  }
  P=push(baixo,P);

}


PNodoPilha trocar(PNodoPilha P){
  if(P==NULL){
    return NULL;
  }
  INFOP cima, baixo;
  PNodoPilha aux;
}
//prox, fazer com return pilha.




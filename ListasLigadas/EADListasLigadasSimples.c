
PNodo criarNodo(INFO X) //entra a info X e retorna um pointer que aponra para a struct Nodo
{
  PNodo P; //declara o pointer to nodo
  P = (PNodo) malloc(sizeof(struct Nodo)); //aloca memoria para o nodo
  if (P == NULL) //se o pointer for null, retorna null, i.e. nao foi possivel alocar memoria
    return NULL; //retorna null ou seja nao foi alocado nada
  P->Elemento = X; //caso seja alocado, o elemento do nodo vai ter o valor de X qeu e uma struct
  P->Prox = NULL;
  return P;
}

PNodo libertarNodo(PNodo P)
{
  P->Prox = NULL;
  free(P);
  P = NULL;
  return P;
}

PNodo criarLista()//pointer para uma nova lista, que e NULL, retorna para uma pointer de NODO
{
  PNodo L; //cria um ponteiro para um nodo
  L = NULL; //esse ponteiro aponta para null (vazio)
  return L; //retorna o ponteiro, mas criou a lista sem nada
}

// liberta todos os nodos da lista, devolvendo-a vazia
PNodo libertarLista(PNodo L)
{
  PNodo P;
  while (L != NULL){
    P = L;
    L = L->Prox;
    P = libertarNodo(P);
  }
  return  L;
}

int listaVazia(PNodo L)
{
  if (L == NULL)
    return 1;
  else
    return 0;
}

void mostrarListaInicio(PNodo L)
{
  PNodo P = L;
  while (P != NULL){
    mostrarElemento(P->Elemento);
    P = P->Prox;
  }
}

void mostrarListaInicioRec(PNodo L)
{
  if (L != NULL){
    mostrarElemento(L->Elemento);
    mostrarListaInicioRec(L->Prox);
  }
}

void mostrarListaFimRec(PNodo L)
{
  if (L != NULL){
    mostrarListaFimRec(L->Prox);
    mostrarElemento(L->Elemento);
  }
}

int pesquisarLista(INFO X, PNodo L)
{ 
  while (L != NULL && compararElementos(L->Elemento, X) != 0)
    L = L->Prox;
  if (L == NULL)
    return 0;
  else
    return 1;
} 

int pesquisarListaRec(INFO X, PNodo L)
{
  if (L == NULL) 
    return  0;
  if (compararElementos(L->Elemento, X) == 0) 
    return  1; 
  return pesquisarListaRec(X, L->Prox);
}

// atualiza os dados do elemento da lista que tem a chave de X
void atualizarLista(INFO X, PNodo L)
{
  PNodo P = L;
  while (P != NULL && compararElementos(P->Elemento, X) != 0)
    P = P->Prox;
  if (P != NULL)  //  existe um elemento com a chave de X
    P->Elemento = X;
}

PNodo inserirListaInicio(INFO X, PNodo L)
{
  PNodo P;
  P = criarNodo(X);
  if (P == NULL)
    return L;
  P->Prox = L;
  L = P;
  return L;
}

PNodo inserirListaFim(INFO X, PNodo L)
{ 
  PNodo Fim, P;
  P = criarNodo(X);  // P aponta para o novo nodo (com X)
  if (P == NULL) 
    return L; 
  if (L == NULL) // lista vazia, logo X � o �nico elemento da lista
    return P;
  Fim = L; 
  while (Fim->Prox != NULL)  // marcar o elemento do fim de L
    Fim = Fim->Prox;
  Fim->Prox = P; // ligar �ltimo nodo da lista L ao novo nodo (com o X)
  return L;
}

// assume-se que a lista est� ordenada por ordem crescente

PNodo inserirListaOrdem(INFO X, PNodo L)
{
  PNodo Ant, P, Aux;
  P = criarNodo(X);
  if (P == NULL)
    return L; 
  if (L == NULL){  // o novo nodo � o �nico da lista
  	L = P;		// bastava colocar:
    return L;	//   return P;
  }
  // procurar pelo nodo que ser� antecessor do novo nodo (com X)
  Ant = NULL;
  Aux = L;
  while (Aux != NULL && compararElementos(Aux->Elemento, X) < 0){
    Ant = Aux;
    Aux = Aux->Prox;
  }
  if (Ant == NULL){   // inserir o novo nodo no in�cio de L
    P->Prox = L; 
    L = P;
    return L;
  }
  // inserir o novo nodo depois do in�cio
  P->Prox = Ant->Prox;
  Ant->Prox = P;
  return L;
}

// remover X da lista L, em que X est� na lista
PNodo removerLista(INFO X, PNodo L)
{ 
  PNodo P, Ant;
  
  if (compararElementos(L->Elemento, X) == 0)
    Ant = NULL;
  else{
    Ant = L;
    while (compararElementos(Ant->Prox->Elemento, X) != 0)
      Ant = Ant->Prox;
  }
  if (Ant == NULL){   // remover o nodo do in�cio da lista
    P = L;
    L = L->Prox;
  } 
  else{
    P = Ant->Prox;
    Ant->Prox = P->Prox; // ou (= Ant->Prox)->Prox
  } 
  P = libertarNodo(P);
  return L;
}


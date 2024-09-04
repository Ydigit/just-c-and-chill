
// tipos de dados

struct NodoPilha {
  INFOP  Elemento;
  struct NodoPilha *Anterior;
};
typedef struct NodoPilha *PNodoPilha;

/* ------------------------------------------------------- */
/* ---- prot�tipos/headers das fun��es da biblioteca ----- */
/* ------------------------------------------------------- */

// Opera��es sobre um nodo (NodoPilha)

PNodoPilha criarNodoPilha (INFOP);

PNodoPilha libertarNodoPilha (PNodoPilha);

// Opera��es sobre uma Pilha (PNodoPilha)

PNodoPilha criarPilha ();

int pilhaVazia (PNodoPilha);

PNodoPilha push (INFOP, PNodoPilha);

PNodoPilha pop (PNodoPilha);

INFOP topo (PNodoPilha);

//AII

void devolve2ndtopSalterando(PNodoPilha);

void devolve2ndtopS(PNodoPilha);

INFOP returnesimoeelemento(PNodoPilha , int );

INFOP returnNthElement(PNodoPilha, int);

//expeirmentar return main
INFOP returnesimoeelementomain(PNodoPilha *, int);

INFOP returnnelementnotouching(PNodoPilha , int );

INFOP forkdeepdownnotouching(PNodoPilha );

INFOP fork3rdfromdeep(PNodoPilha);

INFOP touch3rd(PNodoPilha);

void trocatopunder(PNodoPilha);

void rearrange(PNodoPilha );

//estudo

int calctam(PNodoPilha);

PNodoPilha criarpilha(int, int);

void mostrarP(PNodoPilha );

INFOP devolve2topINAL(PNodoPilha );

INFOP devolveNeleAlterar(PNodoPilha , int );

INFOP devolveNeleAlterarpop(PNodoPilha , int );

INFOP lastpointeralterando(PNodoPilha );

INFOP elnotouch(PNodoPilha );

INFOP Nfrombellow(PNodoPilha );

void Change(PNodoPilha );
















/* ------------------------------------------------------- */
/* -------------- implementa��o das fun��es -------------- */
/* ------------------------------------------------------- */

// Opera��es sobre um nodo (NodoPilha)

PNodoPilha criarNodoPilha (INFOP X)
{
  PNodoPilha P;
  P = (PNodoPilha) malloc(sizeof(struct NodoPilha)); //P agora e um apontador
  if (P == NULL)
    return NULL;
  P->Elemento = X;
  P->Anterior = NULL; //este espaco agora vai ser alterado quando fizer o push
  return P;
}

PNodoPilha libertarNodoPilha (PNodoPilha P)
{
  P->Anterior = NULL;
  free(P);
  P = NULL;
  return P;
}

// Opera��es sobre uma EAD Pilha (PNodoPilha)

PNodoPilha criarPilha ()
{
  PNodoPilha S;
  S = NULL;
  return S;
}

int pilhaVazia (PNodoPilha S)
{
  if (S == NULL)
    return 1;
  else
    return 0;
}

PNodoPilha push (INFOP X, PNodoPilha S)
{
  PNodoPilha P;
  P = criarNodoPilha(X);
  if (P == NULL)
    return S; //se nao criou retorna  a mesma sem push
  P->Anterior = S; //o block anterior da ATUAL APONTA PARA S, se P for criado
  S = P; //S agora aponta para o topo, se o P for criado
  return S;
}

PNodoPilha pop (PNodoPilha S)
{
  PNodoPilha P;
  P = S;
  S = S->Anterior;
  P = libertarNodoPilha(P);
  return S;
}

INFOP topo (PNodoPilha S)
{
  return S->Elemento;
}



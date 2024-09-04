// tipos de dados

struct NodoFila {
  INFOF   Elemento;
  struct NodoFila *Seguinte;
};

typedef struct NodoFila *PNodoFila;


/* ------------------------------------------------------- */
/* ---- prot�tipos/headers das fun��es da biblioteca ----- */
/* ------------------------------------------------------- */

// Opera��es sobre um nodo (NodoFila)

PNodoFila criarNodoFila (INFOF);

PNodoFila libertarNodoFila (PNodoFila);

// Opera��es sobre uma EAD Fila (PNodoFila)

PNodoFila criarFila ();

int filaVazia (PNodoFila);

PNodoFila juntar (INFOF, PNodoFila);

PNodoFila remover (PNodoFila);

INFOF frente (PNodoFila);
//meu

INFOF get2ndelementotouch(PNodoFila *);


INFOF get2ndelementonotouch(PNodoFila );


/* ------------------------------------------------------- */
/* -------------- implementa��o das fun��es -------------- */
/* ------------------------------------------------------- */

// Opera��es sobre um nodo (NodoFila)

PNodoFila criarNodoFila (INFOF X)
{
  PNodoFila P;
  P = (PNodoFila) malloc(sizeof(struct NodoFila));
  if (P == NULL)
    return NULL;
  P->Elemento = X;
  P->Seguinte = NULL;
  return P;
}

PNodoFila libertarNodoFila (PNodoFila P)
{ 
  P->Seguinte = NULL;
  free(P);
  P = NULL;
  return P;
}

// Opera��es sobre uma EAD Fila (PNodoFila)

PNodoFila criarFila ()
{
  PNodoFila Q;
  Q = NULL;
  return Q;
}

int filaVazia (PNodoFila Q)
{
  if (Q == NULL)
    return 1;
  else
    return 0;
}

PNodoFila juntar (INFOF X, PNodoFila Q)
{
  PNodoFila P, Novo;
  Novo = criarNodoFila(X);
  if (Novo == NULL)
    return Q;
  if (filaVazia(Q)){
    Q = Novo;
    return Q;
  }
  P = Q;
  while(P->Seguinte != NULL)
    P = P->Seguinte;
  P->Seguinte = Novo;
  return Q;
}

PNodoFila remover (PNodoFila Q)
{
  PNodoFila P;
  P = Q;
  Q = Q->Seguinte;
  P = libertarNodoFila(P);
  return Q;
}

INFOF frente (PNodoFila Q)
{
  return Q->Elemento;
}




/* ------------------------------------------------------- */
/* ---- prot�tipos/headers das fun��es da biblioteca ----- */
/* ------------------------------------------------------- */

// opera��o apenas para controlo:
//   - n�o faz parte da EAD Fila
//   - mostra a Fila da frente para a cauda
void mostrarFila(PNodoFila);

PNodoFila criarFilaAleatoria (int, int);


/* ------------------------------------------------------- */
/* -------------- implementa��o das fun��es -------------- */
/* ------------------------------------------------------- */

// opera��o apenas para controlo:
//   - n�o faz parte da EAD Fila
//   - mostra a Fila da frente para a cauda
void mostrarFila(PNodoFila Q)
{
  PNodoFila P = Q;
  while (P != NULL){
    mostrarElementoF(P->Elemento);
    P = P->Seguinte;
  }
}

PNodoFila criarFilaAleatoria(int inf, int sup)
{
  int N, k;
  PNodoFila Q;
  INFOF X;

  N = gerarNumeroInteiro(inf, sup);
  Q = criarFila();
  k = 1;
  while(k <= N){
    X = criarElementoF();
    Q = juntar(X, Q);
    k = k + 1;
  }
  return Q;
}

INFOF get2ndelementotouch(PNodoFila *Q){
  INFOF resultado;
  if(*Q==NULL||(*Q)->Seguinte==NULL)
    exit(0);
  (*Q)=remover(*Q);
  resultado = (*Q)->Elemento;
  return resultado;

}


//A3
INFOF get2ndelementonotouch(PNodoFila Q){
  INFOF resultado;
  if(Q==NULL||Q->Seguinte==NULL)
  exit(0);

  Q=Q->Seguinte;
  resultado=Q->Elemento;
  return resultado;
}




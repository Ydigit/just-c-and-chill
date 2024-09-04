
// tipo de dados

typedef struct{
  int   numAluno;
  float notas[4];
  int   notaFinal;
}INFOAB;


/* ------------------------------------------------------- */
/* ---- prot�tipos/headers das fun��es da biblioteca ----- */
/* ------------------------------------------------------- */

void mostrarElementoAB (INFOAB);

INFOAB criarElementoAB ();

// compara��o de 2 elementos do tipo INFOab, 
//   segundo o campo numAluno (chave)
//   devolve -1 se X < Y, 0 se X = Y, 1 se X > Y
int compararElementosAB (INFOAB, INFOAB);


/* ------------------------------------------------------- */
/* -------------- implementa��o das fun��es -------------- */
/* ------------------------------------------------------- */

void mostrarElementoAB (INFOAB X)
{
  printf("%d - ", X.numAluno);
  printf("%.2f + %.2f + %.2f + %.2f - ", X.notas[0], X.notas[1], X.notas[2], X.notas[3]);
  printf("%2d\n",  X.notaFinal);
}

INFOAB criarElementoAB ()
{
  INFOAB X;
  float soma;
  X.numAluno = gerarNumeroInteiro(25000, 35000);
  X.notas[0] = gerarNumeroReal(0.0, 2.0);
  X.notas[1] = gerarNumeroReal(0.0, 2.0);
  X.notas[2] = gerarNumeroReal(0.0, 8.0);
  X.notas[3] = gerarNumeroReal(0.0, 8.0);
  soma = X.notas[0] + X.notas[1] + X.notas[2] + X.notas[3];
  X.notaFinal = (int)(soma + 0.5);
  return X;
}

// compara��o de 2 elementos do tipo INFO, segundo o campo NFatura (chave)
//   devolve -1 se X < Y, 0 se X = Y, 1 se X > Y
int compararElementosAB (INFOAB X, INFOAB Y)
{
  if (X.numAluno > Y.numAluno)
    return 1;
  if (X.numAluno < Y.numAluno)
    return -1;
  return 0;
}






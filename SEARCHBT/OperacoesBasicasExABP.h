
// tipo de dados

typedef struct{
  int   numAluno;
  float notas[4];
  int   notaFinal;
}INFOABP;


/* ------------------------------------------------------- */
/* ---- protótipos/headers das funções da biblioteca ----- */
/* ------------------------------------------------------- */

void mostrarElementoABP (INFOABP);

INFOABP criarElementoABP ();

// comparação de 2 elementos do tipo INFOABP,
//   segundo o campo numAluno (chave)
//   devolve -1 se X < Y, 0 se X = Y, 1 se X > Y
int compararElementosABP (INFOABP, INFOABP);


/* ------------------------------------------------------- */
/* -------------- implementação das funções -------------- */
/* ------------------------------------------------------- */

void mostrarElementoABP (INFOABP X)
{
  printf("%d - ", X.numAluno);
  printf("%.2f + %.2f + %.2f + %.2f - ", X.notas[0], X.notas[1], X.notas[2], X.notas[3]);
  printf("%2d\n",  X.notaFinal);
}

INFOABP criarElementoABP ()
{
  INFOABP X;
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

// comparação de 2 elementos do tipo INFO, segundo o campo NFatura (chave)
//   devolve -1 se X < Y, 0 se X = Y, 1 se X > Y
int compararElementosABP (INFOABP X, INFOABP Y)
{
  if (X.numAluno > Y.numAluno)
    return 1;
  if (X.numAluno < Y.numAluno)
    return -1;
  return 0;
}





typedef struct{
  int   numAluno;
  float notas[4];
  int   notaFinal;
}INFOF;


/* ------------------------------------------------------- */
/* ---- prot�tipos/headers das fun��es da biblioteca ----- */
/* ------------------------------------------------------- */

void mostrarElementoF (INFOF);

INFOF criarElementoF();

// compara��o de 2 elementos do tipo INFOF, 
//   segundo o campo numAluno (chave)
// devolve -1 se primeiro < segundo,
//   0 se iguais, 1 se primeiro > segundo
int compararElementosF(INFOF, INFOF);


/* ------------------------------------------------------- */
/* -------------- implementa��o das fun��es -------------- */
/* ------------------------------------------------------- */

void mostrarElementoF (INFOF X)
{
  printf("%d - ", X.numAluno);
  printf("%.2f + %.2f + %.2f + %.2f - ", X.notas[0], X.notas[1], X.notas[2], X.notas[3]);
  printf("%2d\n",  X.notaFinal);
}

INFOF criarElementoF()
{
  INFOF X;
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

// compara��o de 2 elementos do tipo INFOF, segundo o campo numAluno (chave)
//   devolve -1 se X < Y, 0 se X = Y, 1 se X > Y
int compararElementosF (INFOF X, INFOF Y)
{
  if (X.numAluno > Y.numAluno)
    return 1;
  if (X.numAluno < Y.numAluno)
    return -1;
  return 0;
}



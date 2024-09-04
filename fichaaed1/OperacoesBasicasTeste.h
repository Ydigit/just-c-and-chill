
// tipo de dados INFO

typedef struct{
  int   numAluno;
  float notasMTP;
  float notasTE;
  int   notaFinal;
}INFO;


/* ------------------------------------------------------- */
/* ---- prototipos/headers das funcoes da biblioteca ----- */
/* ------------------------------------------------------- */

void mostrarElemento(INFO);

INFO criarElemento();

// comparacao de 2 elementos do tipo INFO, 
//   segundo o campo numAluno (chave)
// devolve -1 se primeiro < segundo,
//   0 se iguais, 1 se primeiro > segundo
int compararElementos(INFO, INFO);


/* ------------------------------------------------------- */
/* -------------- implementacao das funcoes -------------- */
/* ------------------------------------------------------- */

void mostrarElemento(INFO X)
{
  printf("%d - ", X.numAluno);
  printf("%.2f + %.2f - ", X.notasMTP, X.notasTE);
  printf("%2d\n",  X.notaFinal);
}

INFO criarElemento()
{
  INFO X;
  float soma;
  X.numAluno = gerarNumeroInteiro(25000, 35000);
  X.notasMTP = gerarNumeroReal(0.0, 4.0);
  X.notasTE  = gerarNumeroReal(0.0, 16.0);
  soma = X.notasMTP + X.notasTE;
  X.notaFinal = (int)(soma + 0.5);
  return X;
}

// comparacao de 2 elementos do tipo INFO,
//   segundo o campo numAluno (chave)
//   devolve -1 se X < Y, 0 se X = Y, 1 se X > Y
int compararElementos(INFO X, INFO Y)
{
  if (X.numAluno > Y.numAluno)
    return 1;
  if (X.numAluno < Y.numAluno)
    return -1;
  return 0;
}



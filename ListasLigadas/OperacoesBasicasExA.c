void mostrarElemento(INFO X)
{
  printf("%d - ", X.numAluno);
  printf("%.2f + %.2f + %.2f + %.2f - ", X.notas[0], X.notas[1], X.notas[2], X.notas[3]);
  printf("%2d\n",  X.notaFinal);
}

INFO criarElemento() //apenas cria o elemento para depois printar ATENCOA  SO CRIA 1 ALUNO
{
  INFO X;//declara INFO(ELEMENTO) X
  float soma;
  X.numAluno = gerarNumeroInteiro(25000, 35000); //numero
  X.notas[0] = gerarNumeroReal(0.0, 2.0); // cada nota
  X.notas[1] = gerarNumeroReal(0.0, 2.0); // cada nota
  X.notas[2] = gerarNumeroReal(0.0, 8.0); // cada nota
  X.notas[3] = gerarNumeroReal(0.0, 8.0); // cada nota
  soma = X.notas[0] + X.notas[1] + X.notas[2] + X.notas[3];
  X.notaFinal = (int)(soma + 0.5); //soma das notas com arredondamento
  return X;
}

// compara��o de 2 elementos do tipo INFO, segundo o campo numAluno (chave)
//   devolve -1 se X < Y, 0 se X = Y, 1 se X > Y
int compararElementos(INFO X, INFO Y)
{
  if (X.numAluno > Y.numAluno)
    return 1;
  if (X.numAluno < Y.numAluno)
    return -1;
  return 0;
}





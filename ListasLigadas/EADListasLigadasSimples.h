
struct Nodo{
  INFO   Elemento;
  struct Nodo *Prox;
};

typedef struct Nodo *PNodo;

// operações sobre os nodos

PNodo criarNodo(INFO);

PNodo libertarNodo(PNodo);


// Operações sobre as listas

PNodo criarLista();

PNodo libertarLista(PNodo);

int listaVazia(PNodo);

void mostrarListaInicio(PNodo);
void mostrarListaInicioRec(PNodo);

void mostrarListaFimRec(PNodo);

int pesquisarLista(INFO, PNodo);
int pesquisarListaRec(INFO, PNodo);

void atualizarLista(INFO, PNodo);

PNodo inserirListaInicio(INFO, PNodo);

PNodo inserirListaFim(INFO, PNodo);

// a lista está ordenada por ordem crescente
PNodo inserirListaOrdem(INFO, PNodo);

// remover elemento da lista, em que o elemento está na lista
PNodo removerLista(INFO, PNodo);


#include "EADListasLigadasSimples.c"


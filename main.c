#include <stdio.h>
#include <stdlib.h>

#define MAX_NOS 1000

int grafo[MAX_NOS][MAX_NOS];
int visitado[MAX_NOS];
int n; // Número de nós no grafo

void ln();
void adicionarAresta(int de, int para);
void DFS(int vertice);
void BFS(int verticeInicial);
void iniciarArrayVisitados();
void imprimirMatrizAdjacencia();

int main() {
  printf("Digite o número de nós: ");
  scanf("%d", &n);
  ln();

  int arestas, de, para;
  printf("Digite o número de arestas: ");
  scanf("%d", &arestas);
  ln();

  for (int i = 0; i < arestas; i++) {
    printf("Digite a aresta (de para; ex: '0 2'; min: 0; max: %d): ", n - 1);
    scanf("%d %d", &de, &para);
    adicionarAresta(de, para);
  }
  ln();

  // Zerar os visitados para DFS
  iniciarArrayVisitados();

  // Inicia DFS
  printf("DFS iniciando a partir do nó 0: ");
  DFS(0);
  ln();
  ln();

  // Zerar os visitados para BFS
  iniciarArrayVisitados();

  // Inicia BFS
  printf("BFS iniciando a partir do nó 0: ");
  BFS(0);
  ln();
  ln();

  // Imprime a matriz de adjacência
  imprimirMatrizAdjacencia();
  ln();

  return 0;
}

void ln() { printf("\n"); }

void adicionarAresta(int de, int para) {
  grafo[de][para] = 1; //*//*//*//
}

void DFS(int vertice) {
  visitado[vertice] = 1;
  printf("%d ", vertice);

  for (int i = 0; i < n; i++) {
    if (grafo[vertice][i] == 1 && visitado[i] == 0) {
      DFS(i);
    }
  }
}

void BFS(int verticeInicial) {
  int fila[MAX_NOS], inicio = 0, fim = 0;
  fila[fim++] = verticeInicial;
  visitado[verticeInicial] = 1;

  while (inicio < fim) {
    int verticeAtual = fila[inicio++];
    printf("%d ", verticeAtual);

    for (int i = 0; i < n; i++) {
      if (grafo[verticeAtual][i] == 1 && visitado[i] == 0) {
        fila[fim++] = i;
        visitado[i] = 1;
      }
    }
  }
}

void iniciarArrayVisitados() {
  for (int i = 0; i < n; i++)
    visitado[i] = 0;
}

void imprimirMatrizAdjacencia() {
  printf("Matriz de adjacência: ");
  ln();
  ln();

  printf("    ");
  for (int i = 0; i < n; i++) {
    printf("%d ", i);
  }
  ln();

  printf("    ");
  for (int i = 0; i < n; i++) {
    printf("- ");
  }
  ln();

  // Imprime a matriz de adjacência
  for (int i = 0; i < n; i++) {
    printf("%d | ", i);
    for (int j = 0; j < n; j++) {
      printf("%d ", grafo[i][j]);
    }
    ln();
  }
  ln();
}
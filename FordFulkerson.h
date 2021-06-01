#include <bits/stdc++.h>

using namespace std;

struct FFgraph
{
    int V;
    int E;
    vector<vector<int>> adj_list;
} typedef FFgraph;

bool bfs(FFgraph grafo, vector<vector<int>> res, int vinicial, int vfinal, int par[]){

  bool visitados[grafo.V];
  memset(visitados, false, sizeof(bool) * grafo.V);
  visitados[vinicial] = true;
  queue<int> fila;
  fila.push(vinicial);

  int sfila;

  while(!fila.empty()){
    sfila = fila.front();
    fila.pop();

    for(int i = 0; i < grafo.V; i++){
      if(res[sfila][i] > 0 && !visitados[i]){
        par[i] = sfila;
        visitados[i] = true;
        fila.push(i);
      }
    }
  }

  return visitados[vfinal];
}


int my_ff(FFgraph grafo, int vinicial, int vfinal){
  int u, v, fluxoMaximo = 0;

  int *par = new int[grafo.V];

  vector<vector<int>> res;

  res.resize(grafo.V);

  for(int i = 0; i < grafo.V; i++){
    res[i].resize(grafo.V);

    for(int j = 0; j < grafo.V; j++){
      res[i][j] = grafo.adj_list[i][j];
    }
  }

  while(bfs(grafo, res, vinicial, vfinal, par)){
    int caminho = 99999;

    for (v = vfinal; v != vinicial; v = par[v]){
      u = par[v];
      if(res[u][v] < caminho){
        caminho = res[u][v];
      }
    }

    for(v = vfinal; v != vinicial; v = par[v]){
      u = par[v];
      res[u][v] -= caminho;
      res[v][u] += caminho;
      }
    fluxoMaximo += caminho;

  }

  return fluxoMaximo;
}

int FordFulkerson(){  
  FFgraph grafo;

  int u, v, peso, vinicial, vfinal;

  cin >> grafo.V >> grafo.E;

  cin >> vinicial >> vfinal;

  grafo.adj_list.resize(grafo.V);

  for (int i = 0; i < grafo.V; i++){
    grafo.adj_list[i].resize(grafo.V);
  }

  for (int i = 0; i < grafo.E; i++){
    cin >> u >> v >> peso;
    grafo.adj_list[u][v] = peso;
  }

  cout << "O maior fluxo possivel: " << my_ff(grafo, vinicial, vfinal) << "\n";
    
  return 0;
}
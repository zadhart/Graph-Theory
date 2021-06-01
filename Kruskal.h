#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;


vector<int> par;
vector<int> krk;

struct KruskalGraph
{
    int V;
    int E;
    vector <vector<pair <int,int>>> listaAdjacencia;
    vector <pair<int, pair <int,int>>> listaAresta;
} typedef KruskalGraph;


int fset(int x){
  if(par[x] != x){
    par[x] = fset(par[x]);
  }
  return par[x];
}

void uset(int x, int y){
  if(krk[x] >= krk[y]){
    par[y] = x;

    if(krk[x] == krk[y]){
      krk[x]++;
    }
  }
  else{
    par[x] = y;
  }
}

vector <pair<int, pair<int,int>>> kruskal(vector <vector<pair<int,int>>> listaAdjacencia, vector <pair<int, pair<int,int>>> listaAresta, int m){

  vector <pair<int, pair<int,int>>> T;

  for(int v = 0; v < listaAdjacencia.size(); v++){
    par[v] = v;
    krk[v] = 0;;
  }
  for(auto uv : listaAresta){
    if(fset(uv.second.first) != fset(uv.second.second)){
      T.push_back(uv);
      uset(fset(uv.second.first),fset(uv.second.second));
    }
  }
  return T;
}

int Kruskal(){

    int u, v, peso;

    KruskalGraph grafo;

    cin >> grafo.V >> grafo.E;

    grafo.listaAdjacencia.resize(grafo.V);
    par.resize(grafo.V);
    krk.resize(grafo.V);

    for (int i = 0; i < grafo.E; ++i){
      cin >> u >> v >> peso;
      grafo.listaAdjacencia[u].push_back( pair<int,int>(v, peso) );
      grafo.listaAdjacencia[v].push_back( pair<int,int>(u, peso) );
      grafo.listaAresta.push_back(make_pair(peso, pair<int,int>(u,v)));
    }

    sort(grafo.listaAresta.begin(), grafo.listaAresta.end());

    vector <pair<int, pair<int,int>>> arvore = kruskal(grafo.listaAdjacencia, grafo.listaAresta, grafo.E);

    for(int i = 0; i < arvore.size(); i++){
      cout << "Arestas da arvore geradora: " << arvore[i].second.first << ", " << arvore[i].second.second << "\n";  
    }

    return 0;
}
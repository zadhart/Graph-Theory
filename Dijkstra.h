#include <bits/stdc++.h>

using namespace std;

#define DMAX 99999999

int menorCaminho(int &n, vector<vector<pair<int, int>>> &grafo, vector<int> &distancia, vector<bool> &visitados, int s, int d){

  for (int i = 0; i < n; i++){
    distancia[i] = DMAX;
    visitados[i] = false;
  }

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> filaP;

  distancia[s] = 0;

  filaP.push({distancia[s], s});

  while (!filaP.empty()){

    int v = filaP.top().second;

    filaP.pop();
    
    if (visitados[v]) continue;

    visitados[v] = true;

    for (auto const &proximo : grafo[v]){
      int peso = proximo.first;
      int u = proximo.second;

      if (distancia[u] > distancia[v] + peso){

        distancia[u] = distancia[v] + peso;
        filaP.push({distancia[u], u});
      }
    }
  }

return distancia[d];
}


void Dijkstra()
{
    int n, m;

    vector<vector<pair<int, int>>> grafo;
    vector<int> distancia;
    vector<bool> visitados;

    cin >> n >> m;

    grafo.resize(n);
    visitados.resize(n);
    distancia.resize(n);

    int u, v, peso;

    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> peso;
        grafo[u].push_back({peso, v});
        grafo[v].push_back({peso, u});
    }

    int vinicial, vfinal;

    cin >> vinicial >> vfinal;

    cout << "A menor distancia entre os vertices: " << menorCaminho(n, grafo, distancia, visitados, vinicial, vfinal) << "\n";

}
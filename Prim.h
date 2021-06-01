#include <bits/stdc++.h>

#define PMAX 99999

using namespace std;

int n, m;
int pesos[PMAX];
bool verticesVisitados[PMAX];
vector<pair<int, int>> grafo[PMAX];

int my_prim(){

    for (int i = 0; i < n; i++) {
        pesos[i] = PMAX;
    }

    pesos[0] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> filaP;

    filaP.push({pesos[0], 0});

    while(true){
        int atual = -1;

        while (!filaP.empty()){

            int va = filaP.top().second;
            filaP.pop();

            if (!verticesVisitados[va]){
                atual = va;
                break;
            }
        }
        if(atual == -1){
            break;
        }

        verticesVisitados[atual] = true;

        for (int i = 0; i < grafo[atual].size(); i++){

            int dt = grafo[atual][i].first;

            int va = grafo[atual][i].second;

            if (pesos[va] > dt && !verticesVisitados[va]){
                pesos[va] = dt;
                filaP.push({pesos[va], va});
            }
        }
    }

    int resposta = 0;

    for (int i = 0; i < n; i++)
        resposta += pesos[i];

    return resposta;
}

int Prim()
{
    cin >> n >> m;

    int u, v, peso;

    for (int i = 0; i < m; ++i){

        cin >> u >> v >> peso;

        grafo[u].push_back({peso, v});
        grafo[v].push_back({peso, u});
    }

    cout << my_prim() << "\n";

    return 0;
}
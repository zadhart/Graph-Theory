#include <iostream>
#include "Kruskal.h"
#include "FordFulkerson.h"
#include "Prim.h"
#include "Dijkstra.h"

using namespace std;

int main(int argc, char const *argv[]) {

    string algoritmo = argv[1];

    if(algoritmo == "Prim"){
        Prim();
    }

    if(algoritmo == "Kruskal"){
        Kruskal();
    }

    if(algoritmo == "FordFulkerson"){
        FordFulkerson();
    }

    if(algoritmo == "Dijkstra"){
        Dijkstra();
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
// grafo
vector<vector<int>> g;

/**
 * Visita del grafo in profondità
 */
void dfs(int i, vector<bool> &visited){
    visited[i] = true;
    for (int v : g[i]){
        if(!visited[v])
            dfs(v, visited);
    }
}

/**
 * Trova il numero di componenti connesse del grafo g
 */
int get_cc_number(){
    // visited[i] = true se il nodo i è già stato visitato
    vector<bool> visited(g.size(), false);

    int n_cc = 0;
    for(int i = 0; i < g.size(); i++){
        if(!visited[i]){
            // ogni volta che devo fare ripartire una visita
            // è perchè il nodo i non faceva parte delle 
            // componenti connesse visitate prima
            n_cc++;
            dfs(i, visited);
        }
    }
    return n_cc;
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    // leggo il grafo
    int n, m, a, b;
    in >> n >> m;
    g.resize(n);
    for(int i = 0; i < m; i++){
        in >> a >> b;
        // aggiungo gli archi in entrambe le direzioni
        // siccome il grafo è non orientato (bidirezionale) 
        g[a].push_back(b);
        g[b].push_back(a);
    }
    // trovo il numero di componenti connesse (isole)
    int n_cc = get_cc_number(); 
    // posso connetterle con (n_cc - 1) ponti
    out << (n_cc - 1) << endl;
}
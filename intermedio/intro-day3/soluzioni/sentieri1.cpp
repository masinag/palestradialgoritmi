#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ga, // archi non bollenti 
                    gb; // archi bollenti

/**
 * Visita partendo da s sugli archi non bollenti.
 * Se trovo un cammino minimo per un nodo lo inserisco
 * anche nella coda "q" della BFS "esterna".
 * Ritorno true se ho raggiunto il nodo d
 */
bool espandi(int s, int d, vector<int> &dst, queue<int>& q){
    q.push(s);
    if (s == d) return true;
    // local_q è una coda usata per la visita degli archi non bollenti
    // a partire dal nodo s
    queue<int> local_q({s});

    while(!local_q.empty()){
        int e = local_q.front();
        local_q.pop();
        for (int v : ga[e]){
            if (v == d) return true;
            // percorso minimo
            if (dst[v] == -1){
                q.push(v);
                local_q.push(v);
                // non incremento la distanza
                dst[v] = dst[s]; 
            }
        }
    }
    return false;
}
/**
 * BFS sul grafo, in quanto devo ritornare "una distanza minima" 
 * (numero di archi bollenti). Implemento quindi una versione "modificata"
 * di una classica BFS per trovare i cammini minimi:
 * Faccio una visita in ampiezza sugli archi bollenti e, ogni volta che trovo 
 * un cammino minimo per un nodo passante per un arco bollente, 
 * visito tutti i percorsi fatti di soli archi non bollenti che partono
 * da quel nodo, senza incrementare la distanza.
 * Ci sono quindi due BFS annidate, una per visitare gli archi bollenti e 
 * l'altra che viene eseguita ogni volta che trovo un arco bollente che fa parte
 * di un cammino minimo. 
 */ 
int sentieri(int s, int d){
    vector<int> dst(ga.size(), -1);
    queue<int> q;
    dst[s] = 0;
    // per prima cosa visito gli archi non bollenti
    // che partono dal nodo s
    if (espandi(s, d, dst, q)) {
        return 0;
    }
    // bfs sugli archi bollenti (gb)
    while(!q.empty()){
        int e = q.front();
        q.pop();
        for(int v : gb[e]){
            // se trovo un cammino minimo per v
            if(dst[v] == -1){ 
                dst[v] = dst[e] + 1;
                // metto in coda tutti i nodi raggiungibili
                // (con distanza minima) da v attraverso archi
                // non bollenti
                if(espandi(v, d, dst, q)){
                    return dst[v];
                }
            }
        }
    }

}
int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");
    int n, a, b, x, y;
    in >> n >> a >> b;
    ga.resize(n), gb.resize(n);
    for(int i = 0; i < a; i++){
        in >> x >> y;
        ga[x-1].push_back(y-1);
        ga[y-1].push_back(x-1);
    }
    for(int i = 0; i < b; i++){
        in >> x >> y;
        gb[x-1].push_back(y-1);
        gb[y-1].push_back(x-1);
    }
    out << sentieri(0, n-1) << endl;
}
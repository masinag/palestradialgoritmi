#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> supermercati;

/**
 * Trova la distanza minima tra il nodo s ed 
 * ogni altro nodo.
 */
void min_dist_bfs(int s, vector<int> &dst){
    dst.assign(g.size(), -1);
    dst[s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int i = q.front();
        q.pop();
        for(int v : g[i]) {
            if(dst[v] == -1) {
                dst[v] = dst[i] + 1;
                q.push(v);
            }
        }
    }
}
/**
 * Trova la distanza minima tra i nodi s e d passando per un supermercato.
 * Idea: il supermercato migliore è quello per cui il percorso
 *      s ~~(d1)~~~> miglior supermercato ~~~(d2)~~~> d
 * ha distanza d1 + d2 minima. 
 * Siccome il grafo è non orientato, per calcolare quanto ci costa passare 
 * per il supermercato 'super', possiamo sommare la distanza tra s e super
 * alla distanza tra d e super.
 * Infatti, il percorso più corto tra d e super è lo stesso (ma invertito)
 * che tra super e d.
 */
int get_min_dist(int s, int d){
    vector<int> dstS(g.size()), dstD(g.size());
    min_dist_bfs(s, dstS);
    min_dist_bfs(d, dstD);
    int best_path = -1; // lunghezza del percorso migliore
    for (int super : supermercati) {
        if (best_path == -1 || best_path > dstS[super] + dstD[super]) {
            best_path = dstS[super] + dstD[super];
        }
    }
    return best_path;
}
int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");
    int n, m, k, a, b;
    in >> n >> m >> k;
    g.resize(n + 1);

    // leggo i supermercati
    supermercati.resize(k);
    for(int i = 0; i < k; i++){
        in >> supermercati[i];
    }
    // leggo il grafo
    for(int i = 0; i < m; i++){
        in >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    // trovo la distanza minima tra 1 ed n passando per un supermercato
    int min_dist = get_min_dist(1, n);
    out << min_dist;
}
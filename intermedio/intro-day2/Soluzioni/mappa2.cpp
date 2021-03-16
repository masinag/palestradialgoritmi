#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> m;
int FREE = 0, OBS = -1;

struct cella{
    int i, j;
};

bool valida(int i, int j){
    return i>=0 && i<m.size() && j>=0 && j<m[0].size();
}
void visita(int i, int j, int d){
    /**
     * inserire -> push(elemento)
     * guardare il primo -> front()
     * rimuovere il primo -> pop()
     * q    {(0,1),(1,1),(1,0),(0,2),(1,2),...}
     * c = (0,0) 
     */
    queue<cella> q; 
    // sistemo il primo elemento
    m[i][j] = d;
    cella c = {i, j};
    q.push(c); // push (0, 0)
    bool finito = false;
    while(!finito){
        cella c = q.front();
        // cout << c.i << ", " << c.j << endl;
        q.pop();
        if (c.i == m.size()-1 && c.j == m[0].size()-1){
            finito = true;
        } else {
            // per ogni vicino libero aggiorno la sua distanza e lo pusho
            int inc[3] = {-1, 0, 1};
            for(int x = 0; x < 3; x++){
                for(int y = 0; y < 3; y++){
                    if (!(inc[x] == 0 && inc[y] == 0)){
                        // nuovo vicino
                        int n_i = c.i + inc[x];
                        int n_j = c.j + inc[y];
                        if (valida(n_i, n_j) && m[n_i][n_j] == FREE){
                            m[n_i][n_j] = m[c.i][c.j] + 1; // aggiorno la distanza
                            q.push({n_i, n_j});// lo pusho
                        }
                    }
                }

            }
        }
    }
}
int main(){
    ifstream in("input.txt");
    int n;
    in >> n;
    m.resize(n, vector<int>(n));
    char c;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            in >> c;
            if (c == '*') {
                m[i][j] = FREE;
            } else {
                m[i][j] = OBS;
            }
        }
    }
    visita(0, 0, 1);
    ofstream out("output.txt");
    out << m[n-1][n-1] << endl;
}
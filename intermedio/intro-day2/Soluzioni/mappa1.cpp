#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> m;
int FREE = 0, OBS = -1;

bool valida(int i, int j){
    return i>=0 && i<m.size() && j>=0 && j<m[0].size();
}

void visita(int i, int j, int d){
    if (valida(i, j) && (m[i][j] == FREE || d < m[i][j] )){
        m[i][j] = d;
        // visita(i-1,   j, d+1); // su
        // visita(i-1, j+1, d+1); // su dx
        // visita(  i, j+1, d+1); // dx
        // visita(i+1, j+1, d+1); // dx giu
        // visita(i+1,   j, d+1); // giu
        // visita(i+1, j-1, d+1); // giu sx
        // visita(  i, j-1, d+1); // sx
        // visita(i-1, j-1, d+1); // sx su

        int inc[3] = {-1, 0, 1};
        for(int x = 0; x < 3; x++){
            for(int y = 0; y < 3; y++){
                if (!(inc[x] == 0 && inc[y] == 0)){
                    int n_i = i + inc[x];
                    int n_j = j + inc[y];
                    visita(n_i, n_j, d+1);
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
#include <bits/stdc++.h>
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");

vector<vector<int>> grafo;
vector<int> altezza; // altezza[i] è l'altezza del nodo i

/**
 * Idea (Pseudo-codice)
 * while il giro non è terminato
 *   - trovo il prossimo nodo: nodo_successivo
 *       nodo_successivo non trovato
 *       per ogni nodo vicino "nodo_vicino" a nodo_corrente che non sia nodo_precedente:
 *           if (nodo_successivo non trovato) oppure altezza[nodo_vicino] < altezza[nodo_successivo]:
 *               nodo_successivo = nodo_vicino
 *   - if (nodo_successivo è già visitato)            ----> ciclo
 *              oppure (nodo_successivo non esiste)   ----> vicolo cieco
 *       termino il giro e in nodo_corrente salvo il nodo in cui mi sono fermato:
 *       quello corrente se sono in un vicolo cieco oppure quello successivo 
 *       se sono entrato in un ciclo
 *   - else
 *       nodo_precedente = nodo_corrente
 *       nodo_corrente = nodo_successivo
 *       segno nodo_corrente come visitato
 */
int giro_in_bici(int partenza){
    // nodo_corrente 
    // nodo_precedente
    int nodo_corrente = partenza, nodo_precedente = -1;
    bool stop = false;
    vector<bool> visitato(grafo.size(), false);
    visitato[nodo_corrente] = true;

    while (!stop){
        int nodo_successivo = -1;
        for (int nodo_vicino : grafo[nodo_corrente]){
            if (nodo_vicino != nodo_precedente) {
                if (nodo_successivo == -1 || altezza[nodo_vicino] < altezza[nodo_successivo]){
                    nodo_successivo = nodo_vicino;
                }
            }
        }
        if (nodo_successivo == -1 || visitato[nodo_successivo]) {
            if (nodo_successivo != -1)
                nodo_corrente = nodo_successivo;
            stop = true;
        } else {
            nodo_precedente = nodo_corrente;
            nodo_corrente = nodo_successivo;
            visitato[nodo_corrente] = true;
        }
    }  
    return nodo_corrente;   

}
int main(){
    
    int n, m;
    in >> n >> m;
    // leggo le altezze
    altezza.resize(n);
    for (int i = 0; i < n; i++)
        in >> altezza[i];
    // leggo le strade
    grafo.resize(n);
    int incrocio1, incrocio2;
    for (int i = 0; i < m; i++) {
        in >> incrocio1 >> incrocio2;
        // le aggiungo al grafo
        grafo[incrocio1].push_back(incrocio2);
        grafo[incrocio2].push_back(incrocio1);
    }
    int ultimo_incrocio = giro_in_bici(0);
    out << ultimo_incrocio << endl;
}
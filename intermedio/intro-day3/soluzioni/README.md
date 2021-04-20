# Soluzioni Day3
* ## Ciclismo
### Breve spiegazione del testo
Ci viene dato un grafo non orientato di incroci collegati da strade, dove ogni incrocio ha un'altezza. Partendo dal nodo 0 "facciamo un giro" spostandoci ogni volta nell'incrocio vicino di altezza minima, escluso quello da cui proveniamo. Continuiamo così finchè entriamo in un ciclo, oppure in un "vicolo cieco".

### Idee generali per risolvere l'esercizio
Dobbiamo solamente implementare l'algoritmo che ci viene indicato: partendo dal nodo 0, ad ogni step scelgo il nodo successivo secondo la regola indicata. Continuo così finchè entro in un "vicolo cieco" oppure torno in un nodo già visitato.
Nel codice delle soluzioni è presente anche uno pseudo-codice che indica ad alto livello quali sono gli step da implementare.

* ## Dijkstra e MST
### Breve spiegazione del testo
Questi due problemi sono abbastanza dei classici in teoria dei grafi: cammini minimi e albero di copertura minimo in un grafo, entrambi gli esercizi richiedono di implementare gli algoritmi.

### Idee generali per risolvere l'esercizio
Trovate delle referenze all'interno del codice delle soluzioni, sono problemi che vanno imparati e capitano abbastanza di frequente alle olimpiadi.

* ## Ponti

### Breve spiegazione del testo
E' dato in input un grafo non orientato e possibilmente non connesso. Bisogna trovare il minimo numero di archi da aggiungere per far diventare il grafo connesso.

### Idee generali per risolvere l'esercizio
Ricavare il numero di componenti connesse: scorro ogni nodo, se non l'ho visitato faccio partire una dfs e visiterò tutti i nodi della sua componente connessa, se l'ho già visitato lo ignoro.
Una volta ricavato il numero di componenti connesse, è solo questione di matematica da scuola elementare :)


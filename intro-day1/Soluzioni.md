# Soluzioni Day1


## Easy 1

### Breve spiegazione del testo
Il problema richiede di trovare il massimo di una sequenza di numeri interi compresi tra -1000 e 1000; è dato il numero di interi (N) nella sequenza contenuta nel file di input.

### Idee generali per risolvere l'esercizio
Per risolvere l'esercizio si sfrutta l'idea del massimo parziale, ovvero:
* Inizializziamo la variabile ```maxn``` con il valore del primo numero letto.
* Alla lettura dell'i-esimo numero si aggiorna il massimo del sotto-vettore [0..i] soltanto se questo è maggiore del massimo già calcolato per il sotto-vettore [0..i-1]
* Alla lettura dell'ultimo intero la variabile ```maxn``` conterrà il valore massimo dell'intera sequenza di elementi (da 0 a N-1).

### Link al codice

Dove trovare il codice della soluzione


### Idee alternative
Anziché calcolare il massimo parziale subito dopo la lettura di ogni numero si può usare un array per memorizzare l'intera sequenza e poi calcolare il massimo iterando sull'array. Questa soluzione è accettabile, bisogna tuttavia fare attenzione allo spreco di memoria dato dal fatto di mantenere in memoria tutti i valori, anche quando questi non sono più necessari.
Soluzioni che effettuano tutti i possibili confronti (O(n^2)) invece non sono sufficientemente efficienti, come non lo sono quelle che prevedono di stampare l'ultimo elemento dell'array precedentemente ordinato (O(n log n)).

## Easy 2
### Breve spiegazione del testo
Il problema richiede, date N coppie di numeri interi positivi, di trovare quale sia la massima somma tra i due numeri delle coppie che è anche pari. Se tale somma non esiste bisogna stampare -1.

### Idee generali per risolvere l'esercizio
La risoluzione si basa sempre sui massimi parziali, come nell'esercizio precedente. Le differenze sono:
* Inizializziamo la variabile ```maxn``` a -1 per fare in modo che se non esiste nessuna somma pari il nostro programma stampi il valore atteso dal correttore
* Prima di aggiornare la variabile che contiene il massimo effettuiamo la lettura di entrambi i numeri della coppia e controlliamo se la loro somma è pari (```(a + b) % 2 == 0```)

__NOTA:__ se non esiste alcuna somma pari allora ```(a + b) % 2 == 0``` restituirà sempre ```false``` e il valore di ```maxn``` rimarrà -1 fino alla fine del ciclo, quando la variabile viene stampata sul file.

### Link al codice

Dove trovare il codice della soluzione

### Idee alternative
Come in Easy 1, anche in questo caso si potevano salvare tutti i valori prima di elaborarli, le implicazioni sono le stesse già citate per il problema precedente.
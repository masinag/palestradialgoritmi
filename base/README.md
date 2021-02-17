# Corso base di C++

## Indice:
1. [Creare un file C++](#creare-un-file-c)
2. [Hello world (stampa a video)](#hello-world-stampa-a-video)
3. [Le variabili](#le-variabili)
4. [Input e output](#input-e-output)
5. [Operazioni con le variabili](#operazioni-con-le-variabili)
6. [Le istruzioni if e else](#le-istruzioni-if-e-else)
7. [Gli operatori booleani booleani](#gli-operatori-booleani-booleani)
8. [Lo switch](#lo-switch)
9. [Input e output su file](#input-e-output-su-file)
10. [Il ciclo while](#il-ciclo-while)
11. [Il ciclo for](#il-ciclo-for)
12. [Il ciclo do-while](#il-ciclo-do-while)
13. [Array](#array)
14. [Matrici](#matrici)
15. [Funzioni](#funzioni)

[//]: # (l'eserizio sul moduolo [1.3 è molto carino])

[//]: # (Le funzioni le facciamo la prossima lezione. faremmo funzioni semplici: implementiamo la max, int void ecc... e poi facciamo risolvere alcuni problemi già risolti in precedenza con una funzione "solve")

[//]: # (Dividi sempre le lezioni in una mezz'oretta di teoria, un esercizio o due sulla teoria, e poi tanti esercizi pratici stile olimpiadi)

[//]: # (15. [Puntatori])

[//]: # (15. [Struct])


## Creare un file C++
Il programma che usiamo si chiama **CodeBlocks**. Se volete scaricarlo sul vostro computer ecco il link: http://www.codeblocks.org/downloads/26, scaricate la versione codeblocks-17.12mingw-setup.exe.

Per creare un nuovo file selezionate dal menù "File" la voce "New" e quindi "Empty file". Quando lo salvate ricordate di scrivere "nomefile.cpp", perchè stiamo programmando in C++, se fosse salvato come "nomefile.c", dovremmo usare C come linguaggio. 

**Nota:** C++ è un estensione del linguaggio C.

## Hello world (stampa a video)

```cpp
#include<iostream>
using namespace std;

int main() {
    cout << "Ciao mondo!" << endl;
    return 0;
}
```
Per stampare un messaggio a video si usa l'istruzione cout, *cout << "Messaggio"*; oppure *cout << nomediunavariabile;*

**NB:** Tutto il codice va scritto dentro al main e prima del return (per ora, poi vedremo cosa può essere scritto fuori).

## Le variabili

**Esempio:**
```cpp
#include<iostream>
using namespace std;

int main() {
    int a = 5;
    double b = 3.5;
    float c = 7.2;
    char d = 'a';
    
    cout << a << " " << b << " " << c << " " << d;

    return 0;
}
```
Ci sono quattro tipi principali di variabili: int (numeri interi), double e float (numeri decimali), char (caratteri). I caratteri vengono sempre rappresentati tra apici, come nell'esempio: 'a'.

Per quanto riguarda la stampa a video, ricordo che (ad esempio) con *cout << a;* viene stampato il valore che ha la variabile a in questo punto preciso del programma.

## Input e output

**Esempio:**
```cpp
#include<iostream>
using namespace std;

int main() {
    int a, b;
    cout << "Inserire a: ";
    cin >> a;
    cout << "\nInserire b: ";
    cin >> b;
    
    return 0;
}
```
L'istruzione *cin >> a* legge il numero inserito da tastiera e lo salva nella variabile a.

## Operazioni con le variabili

**Esempio:**
```cpp
#include<iostream>
using namespace std;

int main() {
    int a = 3, b = 2;
    int somma = a+b;
    int differenza = a-b;
    int prodotto = a*b;
    int rapporto = a/b;
    int resto = a%b;

    cout << somma << " " << differenza << " " << prodotto << " " << rapporto << " " << resto;
    
    return 0;
}
```
**Esercizio**: scrivere un programma che, inseriti due numeri da tastiera, calcoli e stampi somma, differenza, prodotto, quoziente e resto della divisione del primo per il secondo. Potete calcolare anche la radice: basta aggiungere la libreria *math.h* (quindi all'inizio mettere *#include<math.h>*) e usare l'operazione *sqrt()*.

## Le istruzioni if e else

**Esempio:**
```cpp
#include<iostream>
using namespace std;

int main() {
    int a = 3, b = 2;
    if(a>b){
        cout << "a e' maggiore di b";
    }else{
        cout << "a e' minore (o uguale) di b";
    }
    
    return 0;
}
```
In generale l'istruzione if controlla la *condizione*, se è vera esegue le *istruzioni 1*, altrimenti esegue le *istruzioni 2*: 

```cpp
if(condizione){
    istruzioni1;
}else{
    istruzioni2;
}
```

**Esercizio**: scrivere un programma che, inserito un numero da tastiera, stampi se è pari o dispari.

## Gli operatori booleani booleani

Gli operatori servono per combiare le varie condizioni logiche. In particolare abbiamo i seguenti operatori logici:
- !	Utilizzo: !var		(NOT, se una condizione è vera la rende falsa)
- &&	Utilizzo: var1 && var2	(AND, ritorna vero se e solo se entrambe le condizioni sono vere)
- ||	Utilizzo: var1 || var2	(OR,  ritorna falso se e solo se entrambe le condizioni sono false)
 
Qui sotto vengono riportate le tabelle i verità degli operatori booleani sopra citati (dove 0 equivale a falso e 1 equivale a vero):

| var | `!var` |
|:---:|:----:|
| 0   |   1  | 
| 1   |   0  | 

| var1 | var2 | `var1 && var2` | <code>var1 &#124;&#124; var2</code> |
|:----:|:----:|:------------:|:--------------:|
|  0   |  0   |      0       |       0        |
|  0   |  1   |      0       |       1        |
|  1   |  0   |      0       |       1        |
|  1   |  1   |      1       |       1        |


**Esempio:**
```cpp
#include<iostream>
using namespace std;

int main() {
    int a, b;

    cout << "Inserisci due interi a, b: ";
    cin >> a >> b;

    if((a >= 2 && a <= 7) || b >= 3){
        cout << "La variabile 'a' è copresa tra 2 e 7 (estremi inclusi)"
             << " oppure 'b' è maggiore o uguale a 3 (l'estremo 3 è incluso perché c'è"
             << " scritto \"maggiore o uguale\")." << endl;
    } else {
        cout << "La variabile 'a' non è compresa tra 2 e 7 (estremi esclusi)"
             << " e 'b' è minore di 3." << endl;
    }

    return 0;
}
```

Come nelle equazioni il '*' ha precedenza sul '+', anche nelle operazioni booleane ci sono delle precedenze: '!' ha precedenza su '&&' e '&&' ha precedenza su '||'. Ovviamente se non ve le ricordate non c'è problema perché potete sempre usare le parentesi.

Infatti nell'esempio sopra scrivere "(a >= 2 && a <= 7) || b >= 3" oppure "a >= 2 && a <= 7 || b >= 3" darà lo stesso risultato.

Un altro esempio: "!(A) || (B && C)" è equivalente a scrivere "!A || B && C".

ATT: Se si vuole scrivere "(A || B) && C" le parentesi sono necessarie, in quanto invece "A || B && C" equivale a "A || (B && C)".

ATT: Se si vuole scrivere "!(A || B)" le parentesi sono necessarie, in quanto invece "!A || B" equivale a "!(A) || B".

Inoltre può essere utile ricordare il teorema che afferma che 

1. "!(a && b)" è equivalente a "!a || !b" 
e che
2. "!(a || b)" è equivalente a "!a && !b".

Provate a dimostrarlo scrivendo le relative tabelle di verità!

## Lo switch
```cpp
switch(espressione intera) { 
case (valore costante 1): 
    istruzioni1;
    break; 
case (valore costante 2):
    istruzioni2;
    break;  
...
default:    // è opzionale 
    istruzioni default;
 } 
```
Lo switch si usa per eseguire istruzioni diverse a seconda del valore di una precisa espressione. Per lo stesso scopo potrebbero essere utilizzati svariati if con molte condizioni, ma in queste situazioni l'uso dello switch semplifica di molto il codice. Lo switch valuta il valore dell'espressione passata come parametro e se il valore corrisponde ad uno di quelli specificati nei *case* viene eseguito il blocco di istruzioni corrispondente. Se il blocco individuato termina con un'istruzione break allora il programma esce dallo switch, altrimenti, vengono eseguiti anche i blocchi successivi finchè non viene trovato un *break* o non si raggiunge l'ultimo blocco dello switch. Se nessun blocco corrisponde al parametro passsato allora viene eseguito il blocco default, se presente. 

**Esercizio (la calcolatrice)**: scrivere un programma che dati due interi A e B ed un'operazione (quindi un simbolo tra +, -, * ,/) stampi a video il risultato dell'operazione (A+B oppure A-B eccetera).

## Input e output su file
Se il nostro programma, invece che leggere da tastiera e stampare a video, dovesse scrivere e leggere da file (solitamente file di estensione .txt), deve usare nuovi oggetti al posto di *cin* e *cout*. Ci serve la libreria *fstream*, che contiene tutto il necessario per lavorare con oggetti di tipo *filestream*. Useremo *ifstream* per leggere dati da file e *ofstream* per scrivere. 

Prima di tutto dobbiamo creare un file di input (ad esempio "input.txt") nella stessa cartella in cui è salvato il programma. In questo file scriviamo i dati da leggere. 

Ora nel nostro programma possiamo aprire il file da cui leggere e il file su cui scrivere (se non esiste viene creato automaticamente).
Con il comando ***ifstream in ("input.txt");*** andiamo ad aprire "input.txt", da cui possiamo leggere con il comando *in* (che funziona allo stesso modo del *cin*). Con ***ofstream out ("output.txt");*** viene creato o aperto (se già esistente) un file "output.txt" su cui possiamo scrivere con il comando *out* (analogo al *cout*).

```cpp
#include<fstream>
using namespace std;

int main(){
	ifstream in ("input.txt");
	ofstream out ("output.txt");

	int a;
	in >> a; //inserisco quello che leggo nella variabile a

	out << "Ciao! La variabile a vale " << a;
	
	in.close();
	out.close();
    
	return 0;
}

```

## Il ciclo while
```cpp
while(condizione) { 
    istruzioni;
} 
```
Il while serve per eseguire ripetutamente un insieme di istruzioni, finchè una certa condizione è vera. La condizione rappresenta un controllo booleano (vero/falso) che viene effettuato ad ogni iterazione (cioè ad ogni "giro", "ciclo"). All'inizio di ogni iterazione viene fatto un controllo: se la condizione è falsa il while termina, se è vera vengono eseguite le istruzioni e poi viene controllata nuovamente la condizione, e così via...

**Esempio:**

```cpp
#include<iostream>
using namespace std;

int main(){
    int a = 10;
    while(a>0){
        cout << " a = " << a << endl;
        a--;
    }
    
    return 0;
}
```


**Esercizio**: scrivere un programma che faccia continuare ad inserire un numero da tastiera fino a che questo non è pari.

## Il ciclo for
```cpp
int i;
for(i = valore iniziale; condizione; incremento della variabile i) { 
    istruzioni; 
} 
```
I cicli for seguono un meccanismo simile al while, vengono solitamente usati quando si conosce il numero di iterazioni da fare (mentre il while solitamente quando questo numero non è conosciuto).

Il for fa uso di una variabile, in questo caso la variabile i, come contatore del numero di iterazioni. Come prima cosa, a questa variabile viene dato un valore iniziale. Finchè il valore di i rispetta la condizione, vengono eseguite le istruzioni contenute tra la parentesi graffe. Eseguito il blocco di istruzioni, la variabile i, viene incrementata secondo l'incremento e, se la condizione è soddisfatta, il ciclo viene ripetuto. 

**Esempio:**

```cpp
#include<iostream>
using namespace std;

int main(){
    int a;
    do {
        cout << " " << i << endl;
    } while();
    
    return 0;
}
```


## Il ciclo do-while
```cpp
do {
    istruzioni;
} while (condizione);
```
Il ciclo do-while si utilizza quando si vuole che la condizione sia controllata alla fine del ciclo e non all'inizio. Se la condizione è soddisfatta, il ciclo viene ripetuto.

Solitamente i cicli più utilizzati sono il ciclo for e il ciclo while e con questi due cicli si può fare tutto, tanto che alcuni linguaggi di programmazione implementano solo questi due tipi di cicli. Però in alcune situazioni può tornare utile anche il ciclo do-while, ad esempio quando si prendono dati in input e si vuole controllare la loro correttezza prima di continuare.

**Esempio:**

```cpp
#include<iostream>
using namespace std;

int main(){
    int a;
    do {
        cout << "Inserire un numero pari maggiore di zero: ";
	cin >> a;
    } while (!(a > 0 && a % 2 == 0));

    return 0;
}
```
In questo esempio verrà chiesto all'utente di inserire un numero finché tale numero non sarà pari e maggiore di zero.


## Array
Un array rappresenta una sequenza di dati dello stesso tipo.
Gli elementi sono identificati dalla loro posizione (detta anche indice) nell'array, dove il primo elemento ha indice 0. Per accedere all'`i`-esimo elemento dell'array `v` scriviamo `v[i]`.

Gli array hanno dimensione statica, nota a tempo di compilazione, e perciò non può dipendere da una variabile il cui valore sarà noto solo durante l'esecuzione del programma (anche se alcuni compilatori permettono di usare una variabile come dimensione, ma dovrebbe essere evitato).

Per aggirare il problema, dichiariamo un array con dimensione massima molto grande (la più grande specificata dal problema) e teniamo in una variabile la dimensione effettiva `n`, che sarà minore o uguale a quella massima. 

Quindi utilizziamo solamente il sotto-array fino alla posizione `n`. 

**Esempio:**
```cpp
#include<iostream>
using namespace std;

const int N_MAX = 10000000;
int v[N_MAX];  // ambiente globale -> inizializzato a zero
// oppure:
// int v[10000000];

int main(){
    int n;

    cout << "Inserire N (minore o uguale a "<<N_MAX<<"): ";
    cin >> n;
    // ATT:
    // ERRORE: int vv[n]; (i c-array devono avere dimensione dichiarata a compile-time)
    // OK: int vv[5];  // però se si dichiara l'array nel main ( o in una funzione) i valori non vengono inizializzati
    // ALTERNATIVA: vector<int> vv(n);

    cout << "Inserire "<<n<<" interi:" << endl;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v[i] = tmp;
        // --- Questo equivale a: ---
        // cin >> v[i];
    }

    cout << "Gli interi inseriti sono:" << endl;
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}
```


# Matrici
Una matrice è un array di array, detto anche array bidimensionale. Può essere immaginata come una tabella formata da righe e colonne, dove possiamo accedere alla cella della matrice `m` che si trova alla `i`-esima riga nella `j`-esima colonna con l'istruzione `m[i][j]`. Gli indici di riga e colonna partono da 0.

Come per gli array monodimensionali, la dimensione deve essere nota a tempo di compilazione.

**Esempio:**
```cpp
#include<iostream>
using namespace std;

const int N_MAX = 1000;
const int M_MAX = 500;

int main(){

    int n, m;
    // valgono le stesse regole della dichiarazione di array monodimensionali
    int matrice[N_MAX][M_MAX];

    cout << "Inserire N ( <= "<< N_MAX <<" ) e M ( <= " << M_MAX << " ): ";
    cin >> n >> m;
    
    // in ogni cella scrivo il suo 'numero'
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++){
            matrice[i][j] = i * m + j ;
        }
    }

    // stampo la matrice
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++){
            cout << matrice[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
```



## Funzioni:
Una funzione è un sotto-programma che può essere utilizzato ripetutamente in un programma.

In un programma è sempre opportuno e conveniente strutturare il codice raggruppandone delle sue parti in sotto-programmi autonomi, che vengono eseguiti in ogni punto in cui è richiesto.

L’organizzazione in funzioni ha moltissimi vantaggi, tra cui:
* Miglior strutturazione e organizzazione del codice
* Maggior leggibilità del codice
* Maggior mantenibilità del codice
* Riutilizzo di sotto-parti di uno stesso programma più volte
* Utilizzo di codice fatto da altri/librerie

In C++ è possibile definire e chiamare funzioni come nei seguenti esempi.

**Esempio 1:**
```cpp
#include<iostream>
using namespace std;

double max(double a, double b) {
    double res;
    if (a > b) {
        res = a;
    } else {
        res = b;
    }
    return res;
}

int main(){
    double x, y;
    cout << "Inserire due numeri reali: " << endl;
    cin >> x >> y;
    cout << "Il maggiore tra " << x << " e " << y << " è: " << max(x, y) << endl;
    return 0;
}
```

**Esempio 2:**
```cpp
#include<iostream>
using namespace std;

double max(double a, double b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int main(){
    double x, y;
    cout << "Inserire due numeri reali: " << endl;
    cin >> x >> y;
    cout << "Il maggiore tra " << x << " e " << y << " è: " << max(x, y) << endl;
    return 0;
}
```

**Esempio 3:**
```cpp
#include<iostream>
using namespace std;

int sommaElementiArray(int array[], int n) {
    int somma = 0;
    for (int i=0; i<n; i++) {
        somma += array[i];
    }
    return somma;
}

int main(){
    int n = 5;
    int v1[] = {1, 2, 3, 4, 5};
    int v2[] = {6, 7, 8, 9, 5};
    
    int sum1 = sommaElementiArray(v1, n);
    int sum2 = sommaElementiArray(v2, n);
    cout << "La somma degli elementi in 'v1' è: " << sum1 << endl;
    cout << "La somma degli elementi in 'v2' è: " << sum2 << endl;
    return 0;
}
```

**Esempio 4:**
```cpp
#include<iostream>
using namespace std;

// void significa che la procedura non ritorna un risultato
void stampaElementiArray(int array[], int n);
// se voglio solo dichiarare una funzione, senza però definire subito come svolgere il suo lavoro, 
// posso fare come qui sopra e definire il corpo della funzione successivamente.

int main(){
    int n = 5;
    int v1[] = {1, 2, 3, 4, 5};
    int v2[] = {6, 7, 8, 9, 5};
    
    cout << "Stampa a scermo gli elementi in 'v1': " << endl;
    stampaElementiArray(v1, n);
    cout << "Stampa a scermo gli elementi in 'v2': " << endl;
    stampaElementiArray(v2, n);
    return 0;
}

void stampaElementiArray(int array[], int n) {
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}
```

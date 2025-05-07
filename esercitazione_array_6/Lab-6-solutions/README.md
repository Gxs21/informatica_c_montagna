# Esercizi su array e stringhe

Per ogni esercizio bisogna realizzare, oltre alle funzioni richieste, anche un `main` che ne esemplifichi il corretto funzionamento.

> Si consiglia di partire dagli esercizi marchiati con un asterisco.

## Esercizio 1*: Inizializzazione del vettore da input

Si realizzi una funzione 
```c
void prompt_array(int array[], int size);
```
che chieda all'utente di inserire una quantità di interi pari a `size`.
La funzione deve disporre gli interi forniti dall'utente all'interno dell'`array` fornito come parametro, __nello stesso ordine in cui sono forniti dall'utente__.
Si assuma che l'array sia stato allocato dal chiamate ad una dimensione (almeno) pari a `size`.

> Il `main` di prova può chiedere a sua volta la dimensione dell'array (`size`) all'utente.

## Esercizio 2*: Stampa vettore al contrario

Si realizzi una funzione 
```c
void inverse_print(int array[], int size);
```
che stampa i `size` elementi dell'`array` __in ordine inverso__.
I numeri devono apparire sepatarati da `", "` e tra parentesi quadre, __senza spazi né virgole di troppo__. 

Ad esempio, il seguente programma:
```c
int numbers[] = { 1, 2, 3 };
inverse_print(numbers, 3);
```
deve stampare `[3, 2, 1]`.

## Esercizio 3*: Prodotto scalare

Si realizzi una funzione 
```c
double scalar_product(double x[], double y[], int size);
```
atta a calcolare il prodotto scalare tra i vettori reali `x` e `y` (supposti di dimensione `size`).
Si assuma che gli array siano stati allocati dal chiamate ad una dimensione (almeno) pari a `size`.

Si ricorda che il prodotto scalare è definito come la sommatoria del prodotto tra l'`i`-esima componente di `x` e l'`i`-esima componente di `y`.
Si consulti [Wikipedia](https://it.wikipedia.org/wiki/Prodotto_scalare#Espressione_analitica) per i dettagli.

## Esercizio 4: Minimo con parametro di output

Si realizzi una funzione 
```c
int min(double array[], int size, double result[]);
```
atta a ricercare l'elemento di tipo `int` _minimimo_ (cioè più piccolo) contenuto in `array` (e a dire quale sia e dove si trova nell'array).
La funzione deve, in particolare:

- restituire in uscita l'__indice dell'elemento minimo__

- oltre a depositare in `result` il __valore effettivo dell'elemento minimo__

Si assuma che `array` sia stato allocato dal chiamate ad una dimensione (almeno) pari a `size`.
Si assuma anche che `result` sia stato allocato dal chiamante ad una dimensione opportuna.

> (Nel fare il `main` di prova, è responsabilità dello studente capire quale sia questa "dimensione opportuna").

## Esercizio 5: Due massimi con parametro di output

Si realizzi una funzione 
```c
int twomax(long array[], int size, int indexes[], long results[]);
```
atta a ricercare i due `long` _massimi_ (cioè più grandi) contenuti in `array` (e a dire quali siano e dove si trovano nell'array).
La funzione deve, in particolare:

- restituire in uscita il numero di valori trovati (0, 1, o 2)

- depositare in `indexes` gli __indici__ dei due valori trovati

- depositare in `results` gli __effettivi valori__ trovati

Si assuma che `array` sia stato allocato dal chiamate ad una dimensione (almeno) pari a `size`.
Si assuma anche che `indexes`, e `results` siano stati allocati dal chiamante ad una dimensione opportuna.

> (Nel fare il `main` di prova, è responsabilità dello studente capire quale sia questa "dimensione opportuna").

## Esercizio 6: K occorrenze con parametro di output

Si realizzi una funzione 
```c
int has_k_occurrences(int array[], int size, int k, int indexes[], int results[]);
```
atta a determinare se esiste un intero _N_ che figuri __esattamente__ `k` volte all'interno di un `array` (e a dire quali siano e dove si trovano nell'array).
La funzione deve, in particolare:

- restituire `1` se un _N_ siffatto esiste all'interno di `array`

- depositare in `indexes` i `k` __indici__ corrispondenti alle `k` occorrenze di _N_ trovate

- depositare in `results` il valore effettivo di _N_

Si assuma che `array` sia stato allocato dal chiamate ad una dimensione (almeno) pari a `size`.
Si assuma anche che `indexes`, e `results` siano stati allocati dal chiamante ad una dimensione opportuna.

> (Nel fare il `main` di prova, è responsabilità dello studente capire quale sia questa "dimensione opportuna").

> Si suggerisce realizzare una funzione di appoggio per il computo del numero di occorrenze di un elemento in un array.

## Esercizio 7*: Lunghezza stringa

> Si ricorda che le stringhe in C non sono altro che array di `char` in cui l'ultimo elemento è il carattere `'\0'`.

Si realizzi una funzione 
```c
int string_length(char string[]);
```
atta a determinare la lunghezza della `string`a fornita in ingresso.
La funzione deve restituire in uscita il numero di caratteri contenuto nella stringa passata come parametro, escluso il carattere di terminazione `'\0'`.

Ad esempio, seppure la stringa `"ciao"` corrisponda all'array di 5 caratteri `{'c', 'i', 'a', 'o', '\0'}`, il risultato di `string_length("ciao")` __deve essere 4__.

> __Nota__: negli esercizi successivi, laddove sia _strettamente_ necessario, è possibile impiegare la funzione `string_length` prodotta in questo esercizio, copincollandone il codice.

## Esercizio 8*: Inversione stringa

Si realizzi una funzione 
```c
void invert_string(char string[], char result[]);
```
atta ad invertire la `string`a fornita in ingresso, depositando la stringa invertita in `result` (e lasciando quindi la `string`a originale __intonsa__).

Si noti che la funzione `invert_string` __deve__ mantenere in coda a `result` il carattere di terminazione `'\0'`.
Quindi, ad esempio, l'inversione di `{'c', 'i', 'a', 'o', '\0'}` deve produrre `{'o', 'a', 'i', 'c', '\0'}`.
In altre parole, il carattere di terminazione `'\0'` __non è soggetto all'inversione__.

## Esercizio 9*: Conteggio delle occorrenze di un carattere in una stringa

Si realizzi una funzione 
```c
int string_occurrences(char string[], char character);
```
atta a contare il numero di occorrenze del carattere `character` all'interno della `string`a fornita come primo argomento.

Si noti che la funzione `string_occurrences` __deve__ ignorare il carattere di terminazione `'\0'`, anche qualora ne venga richiesto esplicitamente il conteggio.
Quindi, ad esempio, il conteggio delle occorrenze di `'\0'` nella stringa `{'c', 'i', 'a', 'o', '\0'}` deve produrre 0.
In altre parole, il carattere di terminazione `'\0'` __non è soggetto al conteggio__.

## Esercizio 10*: Ricerca del carattere CASE INSENSITIVE

Si realizzi una funzione 
```c
int string_find(char string[], char character);
```
atta a cercare la _prima_ posizione (cioé l'indice più basso) di `character` nella `string`a fornita come primo argomento.
La funzione deve restituire `-1` nel caso in cui `character` non sia nella `string`a.

In particolare, è __fondamental__ che la ricerca sia condotta in maniera __case insensitive__.
Ossia: lettere minuscole e maiuscole sono da considerarsi uguali.
Ad esempio `'A'` è da considerarsi uguale ad `'a'`. 
A tal fine, si suggerisce di creare una funzione di appoggio con la firma simile alla seguente:
```c
int char_equal(char c1, char c2);
```
atta a controllare che due caratteri `c1` o `c2` siano uguali o meno (ignorando eventuali divergenze di caso per le lettere).

> Si noti che nella [tabella ASCII][ascii] la distanza tra ogni lettera maiuscola e la corrispondente lettera minuscola è fissa.

## Esercizio 11*: Ordinamento dei caratteri in una parola

Si realizzi una funzione 
```c
void char_sort(char string[]);
```
atta a ordinare i caratteri contenuti nella `string`a passata come primo argomento, secondo l'ordine con cui i carrateri appaiono nella [tabella ASCII][ascii].

Nello svolgere l'esercizio si può (ma non si deve per forza) usare l'algoritmo ["selection sort"](https://it.wikipedia.org/wiki/Selection_sort) visto a lezione. 

Si noti che la funzione `char_sort` __deve__ ignorare il carattere di terminazione `'\0'` in fase di ri-ordinamento.
In altre parole, il carattere di terminazione `'\0'` __deve__ rimanere alla fine della `string`a fornita in ingresso, __anche a valle dell'ordinamento__.
Quindi, ad esempio, l'ordinamento di `{'c', 'i', 'a', 'o', '\0'}` deve produrre `{'a', 'c', 'i', 'o', '\0'}`.

## Esercizio 12: Istogramma

Si realizzi una funzione 
```c
void histogram(unsigned int array[], unsigned int size, unsigned int occurrences[]);
```
atta contare quante volte ogni diverso numero presente in `array` occorre all'interno di `array` stesso.
Si assuma che `array` abbia al suo interno `size` numeri compresi tra 0 e un certo valore massimo _M_.
In quest'ipotesi, la funzione `histogram` deve in particolare assegnare all'`i`-esimo elemento di `occurrences` il numero di volte in cui il numero `i` appare all'interno di `array`.

Si assuma che l'array `occurrences` sia già stato inizializzato dal chiamante alla dimensione _M_, ed in maniera tale da avere uno 0 in ogni elemento. 

## Esercizio 13: Esercizi su matrici

Si realizzino le sequenti funzioni
```c
#define N 10

void print_matrix(int matrix[][N]);

void set_all_to(int matrix[][N], int value);
void set_top_right_half_to(int matrix[][N], int value);
void set_diagonal_to(int matrix[][N], int value, int thickness);
void set_antidiagonal_to(int matrix[][N], int value);
```
atte a formare le matrici raffigurate sotto, se utilizzate come indicato dal seguente programma:
```c
int main(void) {
    int matrix[N][N];

    printf("All zeros:\n");
    set_all_to(matrix, 0);
    print_matrix(matrix);
    printf("\n");

    printf("Top-right half to 1\n");
    set_all_to(matrix, 0);
    set_top_right_half_to(matrix, 1);
    print_matrix(matrix);
    printf("\n");

    printf("Thick diagonal to 1\n");
    set_all_to(matrix, 0);
    set_diagonal_to(matrix, 1, 1);
    print_matrix(matrix);
    printf("\n");

    printf("Antidiagonal to 1\n");
    set_all_to(matrix, 0);
    set_antidiagonal_to(matrix, 1);
    print_matrix(matrix);
}
```

Esempi di output attesi:

- Tutti zero
    ```
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    ```

- Metà superiore destra
    ```
    0, 1, 1, 1, 1, 1, 1, 1, 1, 1
    0, 0, 1, 1, 1, 1, 1, 1, 1, 1
    0, 0, 0, 1, 1, 1, 1, 1, 1, 1
    0, 0, 0, 0, 1, 1, 1, 1, 1, 1
    0, 0, 0, 0, 0, 1, 1, 1, 1, 1
    0, 0, 0, 0, 0, 0, 1, 1, 1, 1
    0, 0, 0, 0, 0, 0, 0, 1, 1, 1
    0, 0, 0, 0, 0, 0, 0, 0, 1, 1
    0, 0, 0, 0, 0, 0, 0, 0, 0, 1
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    ```

- Diagonale con spessore
    ```
    1, 1, 0, 0, 0, 0, 0, 0, 0, 0
    1, 1, 1, 0, 0, 0, 0, 0, 0, 0
    0, 1, 1, 1, 0, 0, 0, 0, 0, 0
    0, 0, 1, 1, 1, 0, 0, 0, 0, 0
    0, 0, 0, 1, 1, 1, 0, 0, 0, 0
    0, 0, 0, 0, 1, 1, 1, 0, 0, 0
    0, 0, 0, 0, 0, 1, 1, 1, 0, 0
    0, 0, 0, 0, 0, 0, 1, 1, 1, 0
    0, 0, 0, 0, 0, 0, 0, 1, 1, 1
    0, 0, 0, 0, 0, 0, 0, 0, 1, 1
    ```

- Anti-diagonale
    ```
    0, 0, 0, 0, 0, 0, 0, 0, 0, 1
    0, 0, 0, 0, 0, 0, 0, 0, 1, 0
    0, 0, 0, 0, 0, 0, 0, 1, 0, 0
    0, 0, 0, 0, 0, 0, 1, 0, 0, 0
    0, 0, 0, 0, 0, 1, 0, 0, 0, 0
    0, 0, 0, 0, 1, 0, 0, 0, 0, 0
    0, 0, 0, 1, 0, 0, 0, 0, 0, 0
    0, 0, 1, 0, 0, 0, 0, 0, 0, 0
    0, 1, 0, 0, 0, 0, 0, 0, 0, 0
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0
    ```

## Esercizio 14: Prodotto matriciale

Si realizzi una funzione 
```c
void matrix_product(double m1[M][N], double m2[N][P], double result[M][P]);
```
che, data una matrice reale `m1` con dimensioni `M*N` ed un'altra matrice reale `m2` con dimensioni `N*P`, computi il __prodotto matriciale__ (righe per colonne) tra `m1` ed `m2`, depositando il risultato in `result` (che dovrà quindi essere una matrice reale `M*P`).

Nell'esemplificare il funzionamento della funzione, si definiscano 3 costanti `N`, `M` e `P` tramite la direttiva `#define`.  

## Esercizio 15: Ricerca di stringhe

Si realizzi una funzione 
```c
int string_search(char strings[][MAX_LENGTH], int n, char key[]);
```
atta a cercare la stringa `key` all'interno dell'array di stringhe `strings`, che si suppone contenere `n` stringhe.
La funzione, in particolare, deve restituire l'indice di `key` all'interno di `strings`.
Nel caso in cui `key` non sia presente all'interno di `strings`, la funzione deve restituire `-1`.

Si assuma che le stringhe in `strings` __non__ siano ordinate.
Si assuma che _tutte_ le stringhe in `strings` abbiano una lunghezza minore o uguale a `MAX_LENGTH`.

Nell'esemplificare il funzionamento della funzione, si definisca una costante `MAX_LENGTH` tramite la direttiva `#define`.  

> Si suggerisce realizzare una funzione di appoggio per controllare se due stringhe siano uguali o meno.

Si utilizzi un programma simile al seguente per testare il corretto funzionamento della funzione `string_search`:
```c
#include <stdio.h>

#define MAX_LENGTH 9

int string_search(char strings[][MAX_LENGTH], int n, char key[]);

int main(void) {
    char contacts[][MAX_LENGTH] = {"andrea", "mirko", "giovanni", "matteo", "roberto", "danilo"};
    const int n = sizeof(contacts) / MAX_LENGTH;

    int indexOfGiovanni = string_search(contacts, "giovanni");
    int indexOfAlessandro = string_search(contacts, "alessandro");

    printf("Giovanni è in posizione %d\n.", indexOfGiovanni); // 2

    printf("Alessandro è in posizione %d\n.", indexOfAlessandro); // -1
}
```

[ascii]: https://it.wikipedia.org/wiki/ASCII#Stampabili

/*Scrivere una funzione int sqrtint(int n) che accetta come parametro un intero n >= 0, 
e restituisce la radice quadrata intera (approssimata per difetto) di n. 
Più in dettaglio, la funzione deve restituire il massimo intero q >= 0 
per cui si abbia q * q <= n. Alcuni esempi:

sqrtint(0) restituisce 0;

sqrtint(1) restituisce 1;

sqrtint(2) restituisce 1;

sqrtint(13) restituisce 3.

Predisporre una funzione main() che invoca la funzione precedente, e si controlli la correttezza 
dei risultati.

(Domanda: dato il risultato q restituito da sqrtint per un certo n, 
come faccio a controllare che q sia il risultato corretto senza dover calcolare esplicitamente 
la radice quadrata intera? In altre parole, esiste un modo semplice per controllare la 
correttezza del risultato che non richieda il calcolo della radice quadrata intera?)*/
#include <stdio.h>
#include <math.h>
int sqrtint (int n){
    int q;
    for (q=0; q*q<=n; q++);
    return q-1;
}
int main (void){
    int n;
    do{
    printf ("inserire un numero positivo:");
    scanf ("%d", &n);
    }while (n<0);
    printf ("la radice quadrata di %d, è: %d", n, sqrtint(n));
return 0;
}
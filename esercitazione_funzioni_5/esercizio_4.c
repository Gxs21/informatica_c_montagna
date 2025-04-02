/*Scrivere una funzione void lanci(int n) che accetta in input un intero n ≥ 1 e simula n lanci di una moneta; la funzione deve stampare il numero di teste e croci ottenute. 
Per simulare il lancio di una moneta è possibile usare la funzione int rand(void) definita nel file stdlib.h che va incluso all’inizio del programma (#include <stdlib.h>). 
La funzione rand() restituisce un intero pseudocasuale compreso tra 0 e una qualche costante “grande”.
 Per simulare l’esito di un lancio si può valutare se il numero pseudoca- suale è pari o dispari usando l’espressione rand()%2. 
 Nel caso sia pari si può ad esempio conteggiare l’esito “testa”, nel caso sia dispari come “croce”.*/

 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>
void lanci (int n){
    int testa=0;
    int croce=0;
    srand (time(NULL));
    for (int i=1;i<=n;i++){
        if((rand())%2){
            testa++;

        }else{
            croce++;
        }
    }
    printf ("il risultato di %d lanci e':  %d volte testa, %d volte croce \n ", n, testa, croce);
    }
int main (){
    int n;
    do{
        printf("inserire un numero maggiore di 1: \n");
        scanf("%d", &n);        
    }while (n<1);
    lanci(n);
    return 0;
}
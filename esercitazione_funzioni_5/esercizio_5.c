/*A partire dal sorgente riportato sotto, scrivere un programma che indovina un numero tra 1 e 100 scelto in modo pseudo casuale dal computer usando la funzione rand() (definita in stdlib.h).

Nel sorgente vi vengono fornite le funzionalità di base per scegliere a caso un numero intero x compreso tra 1 e 100 (estremi inclusi). Completare il programma chiedendo all'utente di immettere ripetutamente un numero intero,
 compreso tra 1 e 100, finché il numero non viene indovinato. Il programma può fornire all'utente informazioni che possano guidarlo nella scelta del prossimo numero. Ad esempio, 
 una possibile interazione tra il programma e l'utente potrebbe essere la seguente:

Scegli un intero tra 1 e 100: 50
Il valore che ho scelto e' maggiore di 50
Scegli un intero tra 1 e 100: 75
Il valore che ho scelto e' maggiore di 75
Scegli un intero tra 1 e 100: 90
Il valore che ho scelto e' maggiore di 90
Scegli un intero tra 1 e 100: 95
Il valore che ho scelto e' minore di 95
Scegli un intero tra 1 e 100: 93
Il valore che ho scelto e' minore di 93
Scegli un intero tra 1 e 100: 92
Hai indovinato in 6 tentativi: ho scelto proprio 92
 Sorgente di partenza
#include <stdio.h>
#include <stdlib.h> /* per la funzione rand() 
#include <time.h>   /* per la funzione time() 

// Genera un numero casuale nel range dal min a max (estremi inclusi)
int rand_min_max(int min, int max) {
    return min + rand() % (max - min + 1);
}

int main(void) {
    int number_of_attempts = 0;
    int last_guess;

    // inizializza generatore pseudocasuale in maniera che restituisca numeri diversi ogni volta 
    srand(time(NULL)); 

    // Il computer sceglie a caso un numero intero x compreso tra 1 e 100 (estremi inclusi). 
    int x = rand_min_max(1, 100);

    // scrivere qui di seguito la vostra soluzione; se serve e' possibile definire altre variabili.

    printf("Hai indovinato in %d tentativi: ho scelto proprio %d\n", number_of_attempts, last_guess);
    return 0;
}*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int rand_min_max(int min, int max) {
    srand (time(NULL));
    return min + rand() % (max - min + 1);
}
int main(){
    int min,max;
    int number_of_attemps=0;
    printf ("inserisci i valori minimo e massimo del range dal quale estrarre valori casuali separati da uno spazio; \n");
    scanf ("%d %d", &min, &max);
    int num_generato = rand_min_max(min,max);
    printf("prova a indovinare il numero generato dal computer, spoiler: %d \n", num_generato );
    int last_guess;
    do{
        
        scanf ("%d", &last_guess);
        printf ("l'ultimo tentativo e' stato: %d \n", last_guess);
        if (last_guess<num_generato){
            printf ("hai inserito un numero piu' piccolo del numero generato, riprova: \n");
        }else{
            printf ("hai inserito un numero piu' grande del numero generato, riprova: \n ");
        }
    number_of_attemps += 1;
    }while (last_guess!=num_generato);
    printf ("hai indovinato il numero %d in %d tentativi \n", num_generato, number_of_attemps);
    
}
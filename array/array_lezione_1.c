#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define N 7 //uso un simbolo che verrà sostituito con il valore 7 prima della compilazione
int main (void){
    double ts[30] = {122.0,21.0,19.5,20.0,18.0,25,13.0}; //in questo modo tutti i valori dalla posizione 8 alla 30 vengono messi a 0, quindi, se non assegnati, i valori dell'arrey vengono assunti 0, vengono riservate 30 celle di memoria double contigue
    double ta[365]; //non essendo inizializzato l'array, in questo caso non viene assegnato nulla 
    //int N=30;
    double t[N]; //array variable lenght, non è consentita in tutte le versioni del linguaggio di programmazione, in c99 è ammesso
    //se non esplicito la dimensione dell'array, viene assunta la dimensione associata al numero di elementi che inserisco nell'array
    printf ("dammi la temperatura del lunedì: %f", ts[0]); //legge il valore in posizione 0 dell'array

    ts[0] =22; //modifica il valore in posizione 0
    printf ("dammi la temperatura del lunedì: %f", ts[0]);
    printf ("dammi la temperatura del primo giorno dell'anno: %f \n", ta[0]);

    double max=0.0;
    int imax=0;
    for (int i=0; i<7; i++){
        printf ("dammi la temperatura del giorno i: %d, %f\n", i, ts[i]);
        if (max < ts[i]){
            max=ts[i];
            imax=i;
        }
    }
    srand (time(NULL));
    for (int i=0; i<7; i++){
        printf("%f \n", ts[i]=5 + rand() % (25-5+1));

    }
    // conviene spesso iniziare per esempio imax o max alla posizione 0 dell'array in modo da confrontare tutti i valori con il primo valore, in tal caso va modificato il primo estremo nel for 
    printf ("temperatura piu' alta registrata = %f\n", max);
    printf ("giorno con temperatura più alta registrata = %d\n", imax);

    //usare i variable lenght arrays conviene, in tal caso si usa defin N n e si usa N come estremo superiore nei cicli for, in modo tale che sia sufficiente cambiare il valore di define N senza toccare i cicli for
}
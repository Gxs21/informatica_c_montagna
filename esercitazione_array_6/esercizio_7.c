/*Si realizzi una funzione

int has_k_occurrences(int array[], int size, int k, int indexes[], int results[]);
atta a determinare se esiste un intero N che figuri esattamente k volte all'interno di un array 
(e a dire quali siano e dove si trovano nell'array). La funzione deve, in particolare:

restituire 1 se un N siffatto esiste all'interno di array

depositare in indexes i k indici corrispondenti alle k occorrenze di N trovate

depositare in results il valore effettivo di N

Si assuma che array sia stato allocato dal chiamate ad una dimensione (almeno) pari a size. 
Si assuma anche che indexes, e results siano stati allocati dal chiamante ad una dimensione opportuna.

(Nel fare il main di prova, è responsabilità dello studente capire quale sia questa "dimensione opportuna").

Si suggerisce realizzare una funzione di appoggio per il computo del numero di occorrenze 
di un elemento in un array.*/
#include<stdio.h>
int occorrenze (int array[],int n, int size, int indexes[]){
    int occorrence=0;
    for (int j=0; j<size; j++){
        if (array[j]==n){
            indexes[occorrence]=j;
            occorrence++;
        }
    }
    return occorrence;
}
int has_k_occurrences(int array[], int size, int k, int indexes[], int results[]){
   for (int i=0; i<size; i++){
        if (occorrenze(array, array[i], size, indexes)==k && array[i]!=results[0]){
            results[0]=array[i];            
            return 1;
        }
    }
    return 0;
}

int main(){
    int array[]={0,1,2,3,4,2};
    int k=3;
    int size=6;
    int indexes[6];
    int results[1];
    printf("%d", has_k_occurrences(array, size, k, indexes, results ));
    return 0;
}
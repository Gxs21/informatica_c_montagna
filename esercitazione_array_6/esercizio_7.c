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

int has_k_occurrences(int array[], int size, int k, int indexes[], int results[]){
    int t=0;
    int s=0;
    for (int i=0; i <size; i++){
        int count=0;
        int actual=array[i];
        for (int j=0; j<size;j++){
            if(array[j]==actual){
                count++;
                indexes[s]=j;
                s++;
                if (count==k){
                    results[t]=actual;
                    t++;
                    return 1;
                }else{
                    return 0;
                }
            }
        }
    }
    
}
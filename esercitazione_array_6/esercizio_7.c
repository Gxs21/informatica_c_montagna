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
#include<stdlib.h>
#define SIZE 100
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
    int already_checked[size];
    int checked=0;
    
   for (int i=0; i<size; i++){
    int check=1;
        for(int j=0;j<100;j++){
            if (already_checked[j]==array[i]){
                check=0;
            }
        if (check) {
            already_checked[checked++]=array[i];
            
            }
        }
        if (occorrenze(array, array[i], size, indexes)==k && check){
            results[0]=array[i];            
            return 1;
        }
        
    }
    return 0;
}
void rand_init(int array[], int size){
    for (int i=0;i<size;i++){
        array[i]=(rand()%100);
    }
}
void print_array(int array[], int size){
    for (int i=0;i<size;i++){
        printf("%d", array[i]);
    }
}
int main(){
    
    int array[SIZE];
    rand_init(array, SIZE);
    printf("inserire quante volte deve essere presente il numero: ");
    int k=0;
    scanf("%d", &k);
    print_array(array, SIZE);
    int indexes[k];
    int results[1]={0};
    printf("\n %d", has_k_occurrences(array, SIZE, k, indexes, results ));
    return 0;
}
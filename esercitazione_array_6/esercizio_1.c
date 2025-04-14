/* Si realizzi una funzione

void prompt_array(int array[], int size);
che chieda all'utente di inserire una quantità di interi pari a size. 
La funzione deve disporre gli interi forniti dall'utente all'interno dell'array fornito 
come parametro, nello stesso ordine in cui sono forniti dall'utente. Si assuma che l'array 
sia stato allocato dal chiamate ad una dimensione (almeno) pari a size.

Il main di prova può chiedere a sua volta la dimensione dell'array (size) all'utente. */
#include <stdio.h>
#include <stdlib.h>
void prompt_array(int array[], int size){
    for (int i=0; i<size; i++){
        printf("inserire un numero intero\n");
        scanf("%d", &array[i]);
        printf("%d \n", array[i]);
    }
    for(int i=0; i<size; i++){
        printf("\n %d ", array[i]);
    }
}
int main(){
    int size=0;
    printf("inserire quanti interi si vogliono inserire:\n");
    scanf("%d", &size);
    int array[size];
    prompt_array(array, size);
    for(int i=0; i<size; i++){
        printf("\n %d ", array[i]);
    
    }
    return 0;
}
//chiedigli come funziona il paddaggio del parametro da riempire per non avere un ritorno di tipo array
//chiedi perchè non puoi usare la sintassi che hai usato 
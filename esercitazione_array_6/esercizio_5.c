/*Si realizzi una funzione

int min(double array[], int size, double result[]);
atta a ricercare l'elemento di tipo int minimo (cioè più piccolo) contenuto in array 
(e a dire quale sia e dove si trova nell'array). La funzione deve, in particolare:

restituire in uscita l'indice dell'elemento minimo

oltre a depositare in result il valore effettivo dell'elemento minimo

Si assuma che array sia stato allocato dal chiamate ad una dimensione (almeno) pari a size. 
Si assuma anche che result sia stato allocato dal chiamante ad una dimensione opportuna.

(Nel fare il main di prova, è responsabilità dello studente capire quale sia questa "dimensione opportuna").*/
#include <stdlib.h>
#include <stdio.h>

int min(double array[], int size, double result[]){
    int index=0;
    result[0]=array[0];
    for (int i=0;i<size;i++){
        if(array[i]<result[0]){
            result[0]=array[i];
            index=i;
        }
    }
    return index;
}

void prompt_array(double array[], int size){
    for (int i=0; i<size; i++){
        printf("inserire un numero intero\n");
        scanf("%lf", &array[i]);
    }
}
int main(){
    int size=0;
    printf("digitare il numero di elementi da inserire:");
    scanf("%d", &size);
    double *array=malloc(sizeof(double)*size);
    double *result=malloc(sizeof(double));
    prompt_array(array, size);
    printf("il valore minimo tra quelli inseriti si trova nella posizione: %.d", min(array, size, result));
    free (array);
    free (result);


    return 0;
}
/*si realizzi una funzione

int twomax(long array[], int size, int indexes[], long results[]);
atta a ricercare i due long massimi (cioè più grandi) contenuti in array 
(e a dire quali siano e dove si trovano nell'array). La funzione deve, in particolare:

restituire in uscita il numero di valori trovati (0, 1, o 2)

depositare in indexes gli indici dei due valori trovati

depositare in results gli effettivi valori trovati

Si assuma che array sia stato allocato dal chiamate ad una dimensione (almeno) pari a size.
 Si assuma anche che indexes,
 e results siano stati allocati dal chiamante ad una dimensione opportuna.

(Nel fare il main di prova, è responsabilità dello studente capire quale sia questa "dimensione opportuna").
*/
#include <stdio.h>
#include <stdlib.h>
int twomax(long array[], int size, int indexes[], long results[]){
    if(size==0){
        return 0;
    }else if(size==1){
        return 1;
    }
    
    int index1=0, index2=1;
    long max1=array[index1], max2=array[index2];
    if (array[index1] > array[index2]){
        max1=array[index2], max2=array[index1];
        index1=1;
        index2=0;
    }
    for (int i=2; i<size; i++){
        if(array[i]>max2){
            max1=max2;
            max2=array[i];
            index1=index2;      
            index2=i;
                  
        }else if(array[i]>max1){
            max1=array[i];
            index1=i;
        }
    }
    indexes[0]=index1;
    indexes[1]=index2;
    results[0]=max1;
    results[1]=max2;
    return 2;
}
void prompt_array(long array[], int size){
        for (int i=0; i<size; i++){
        printf("inserire un numero intero\n");
        scanf("%ld", &array[i]);
        }
    }

int main(){
    int size=0;
    printf("inserire il numero di elementi desideratt: ");
    scanf ("%d", &size);
    long *array=malloc(sizeof(long)*size);
    int *indexes=malloc(sizeof(int)*2);
    long *results=malloc(sizeof(long)*2);
    prompt_array(array, size);
    printf("sono stati trovat %d valori massimi", twomax(array, size, indexes, results));
    free (array); free(indexes); free(results);
    return 0;
}
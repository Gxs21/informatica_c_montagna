/*Si realizzi una funzione

void inverse_print(int array[], int size);
che stampa i size elementi dell'array in ordine inverso. 
I numeri devono apparire sepatarati da ", " e tra parentesi quadre, senza spazi né virgole di troppo.

Ad esempio, il seguente programma:

int numbers[] = { 1, 2, 3 };
inverse_print(numbers, 3);
deve stampare [3, 2, 1].*/
#include <stdio.h>
#include <stdlib.h>

void inverse_print(int array[], int size){
    for (int i=size-1; i>=0; i--){
        printf("%d \n", array[i]);
    }
}
void prompt_array(int array[], int size){
    for (int i=0; i<size; i++){
        printf("inserire un numero intero\n");
        scanf("%d", &array[i]);
    }
}

int main(){
    int size=0;
    printf("inserire il numero di elementi che si vogliono memorizzare: \n");
    scanf ("%d", &size);
    int array[size];
    prompt_array(array, size);
    inverse_print(array, size);
    return 0;
}

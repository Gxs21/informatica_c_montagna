/* Si progetti ed implementi una funzione sumsq per il calcolo della somma S(x) 
dei quadrati degli interi da 1 a x, assumendo x >= 1:

S(1) = 1^2 
S(2) = 1^2 + 2^2 
S(3) = 1^2 + 2^2 + 3^2 
...
Si definisca opportunamente la firma della funzione. 
Si crei un main() per testare la funzione controllando la correttezza dei risultati calcolati. */

#include <stdio.h>
#include <math.h>
int sumsq (int x){
    int somma=0;
    for (int i=1; i<=x; i++){
        somma += pow (i,2);
    }
    return somma;
}
int main (void){
    int n;
    do{
        printf ("inserire un numero positivo:");
        scanf (" %d", &n);
    }while (n<1);
    printf ("la somma dei quadrati da 1 a %d = %d",n, sumsq(n));
    return 0;
}
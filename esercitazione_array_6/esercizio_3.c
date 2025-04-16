/*Si realizzi una funzione

double scalar_product(double x[], double y[], int size);
atta a calcolare il prodotto scalare tra i vettori reali x e y (supposti di dimensione size). 
Si assuma che gli array siano stati allocati dal chiamate ad una dimensione (almeno) pari a size.

Si ricorda che il prodotto scalare è definito come la sommatoria del prodotto tra 
l'i-esima componente di x e l'i-esima componente di y. Si consulti Wikipedia per i dettagli.*/
#include<stdio.h>
double scalar_product(double x[], double y[], int size){
    double scalar=0;
    for (int i=0; i<size; i++){
        scalar+=(x[i]*y[i]);

    }
    return scalar;
}
void prompt_array(double x[], double y[], int size){
    for (int i=0; i<size; i++){
        printf("inserire un valore da inserire nel primo array\n");
        scanf("%lf", &x[i]);
    }
    for (int i=0; i<size; i++){
        printf("inserire un valore da inserire nel secondo array\n");
        scanf("%lf", &y[i]);
    }
}

int main(){
    int size=0;
    printf("inserire il numero di elementi che si vogliono memorizzare in entrambi nei due array: \n");
    scanf ("%d", &size);
    double x[size],y[size];
    prompt_array(x, y, size);
    printf("%.2lf", scalar_product(x,y,size));
    return 0;
}
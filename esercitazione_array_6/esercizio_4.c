/*Scrivere un programma che, dati 6 cassetti di resistenze etichettati 
con i seguenti valori (in Ohm): 10, 15, 22, 33, 47, 68, stabilisca dove riporre una nuova resistenza
 di valore misurato R.

Si assuma che i valori assegnati a ciascuna cassetto abbiano una tolleranza di +/- 10% ovvero, 
il cassetto etichettato 15 possa contenere resistenze con 15 × 0.9 ≤ R ≤ 15×1.1

Nota: gli intervalli NON si sovrappongono: è possibile che R sia tale da non poter essere inserito 
in alcun cassetto; in tal caso il programma lo deve segnalare con un opportuno messaggio d’errore

Assumere che tutti i valori siano di tipo float o double*/
#include<stdio.h>
#include<stdlib.h>

void ohm(double r10[], double r15[], double r22[], double r33[], double r47[], double r68[], int size){
    double resistenza=0;
    for (int i=0; i<size; i++){
        printf("inserisci il valore della resistenza\n");
        scanf("%lf", &resistenza);
        if((10*0.9)<=resistenza && resistenza<=(10*1.1)){
            r10[i]=resistenza;
        }else if((15*0.9)<=resistenza && resistenza<=(15*1.1)){
            r15[i]=resistenza; 
        }else if((22*0.9)<=resistenza && resistenza<=(22*1.1)){
            r22[i]=resistenza;         
        }else if((33*0.9)<=resistenza && resistenza<=(33*1.1)){
            r33[i]=resistenza;         
        }else if((47*0.9)<=resistenza && resistenza<=(47*1.1)){
            r47[i]=resistenza;         
        }else if((68*0.9)<=resistenza && resistenza<=(68*1.1)){
            r68[i]=resistenza;         
        }else{
            printf("il valore %.2lf non è catalogabile\n", resistenza);
        }
    }
}
void print_array(double r10[], double r15[], double r22[], double r33[], double r47[], double r68[], int size){
    for (int i=0; i<size; i++){
        if(r10[i]!=0){
            printf("%.2lf \n", r10[i]);
        }else if(r15[i]!=0){
            printf("%.2lf \n", r15[i]);
        }else if(r22[i]!=0){
            printf("%.2lf \n", r22[i]);
        }else if(r33[i]!=0){
            printf("%.2lf \n", r33[i]);
        }else if(r47[i]!=0){
            printf("%.2lf \n", r47[i]);
        }else if(r68[i]!=0){
            printf("%.2lf\n", r68[i]);
        }
    }
}
int main(){
int size=0;
printf("inserire il numero di resistenze da catalogare\n");
scanf("%d", &size);
double *r10 = malloc(sizeof(double)*size);
double *r15 = malloc(sizeof(double)*size);
double *r22 = malloc(sizeof(double)*size);
double *r33 = malloc(sizeof(double)*size);
double *r47 = malloc(sizeof(double)*size);
double *r68 = malloc(sizeof(double)*size);
ohm (r10, r15, r22, r33, r47, r68, size);
print_array(r10, r15, r22, r33, r47, r68, size);
free(r10); free(r15); free(r22); free(r33); free(r47); free(r68);
    return 0;
//va finito usando i puntatori
}
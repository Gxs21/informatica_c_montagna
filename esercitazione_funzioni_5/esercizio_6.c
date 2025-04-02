/*Una città decide di assegnare un numero identificativo a tre suoi uffici:

p (polizia)

s (ospedale)

f (pompieri)

Ogni ufficio può ricevere un numero compreso tra 1 e 7, estremi inclusi, soggetti ai vincoli seguenti:

Ogni ufficio deve avere un numero diverso dagli altri;

La somma dei numeri assegnati ai tre uffici deve essere 12 (p+s+f = 12);

La polizia (p) deve avere un numero pari

Scrivere un programma che elenchi tutte le possibili combinazioni di valori p, s, f che soddisfano i requisiti precedenti (dovrebbero esserci esattamente 14 combinazioni valide).
 Suggerimento: esaminare tutte le combinazioni e stampare solo quelle valide; a tale scopo si possono utilizzare tre cicli "for" annidati. (Fonte: RosettaCode)*/

#include <stdio.h>
#include <stdlib.h>
void assegnazione (){
    int p,s,f;
    int count =0;
    for (int i=1; i<=7; i++){
        p=i;
        for (int j=1; j<=7; j++){
            s=j;
            for (int k=1; k<=7;k++){
                f=k;
                if(p!=s && p!=f && s!=f && ((p%2)==0) && (p+s+f==12)){
                    printf ("%d \t  %d \t %d \n", p, s, f);
                    count += 1;
                }
                }
            }
            
        
    }
    printf("il numero di combinazioni corrette equivale a %d", count );
}
int main(){
    assegnazione();
    return 0;
}
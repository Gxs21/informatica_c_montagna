/*Scrivere un programma che calcola la differenza (in minuti) tra due orari t_1 e t_2, specificati tramite ora e minuti da richiedere all'utente. 
Se il secondo orario precede il primo, deve intendersi come appartenente al giorno successivo. Ad esempio:

la differenza tra t_1 = 10:21 e t_2 = 10:22 deve dare 1;

la differenza tra t_1 = 11:23 e t_2 = 15:12 deve dare 229;

la differenza tra t_1 = 15:12 e t_2 = 11:23 deve dare 1211 (il secondo orario precede il primo quindi si assume appartenente al giorno successivo).

Si noti che la differenza tra un orario e se stesso è zero. Si assuma che gli orari inseriti siano sempre corretti (non è necessario fare la verifica).

Segue scheletro del programma che è possibile modificare.*/

#include <stdio.h>

// calcola il valore assoluto di un numero
//int abs(int x) {  
  //  int abs_x=
 // }

// restituisce la differenza in minuti tra due orari in minuti
int time_diff(int h1, int m1, int h2, int m2) { 
    int differenza=0;
    if(h2<=h1 && m2<m1){
        differenza=(((h2*60)+m2+60*24)-((h1*60)+m1));
    }else{
         differenza=(((h2*60)+m2)-((h1*60)+m1)); 
    }
    return differenza;
  }

int main(void) {
    int h1, m1, h2, m2;

    printf("Inserire primo orario (h1.m1): ");
    scanf("%d.%d", &h1, &m1);
    printf("Inserire secondo orario (h2.m2): ");
    scanf("%d.%d", &h2, &m2);

    int diff = time_diff(h1,m1,h2,m2);

    printf("Ci sono %d minuti tra %d.%d e %d.%d\n", diff, h1, m1, h2, m2);
    return 0;
}
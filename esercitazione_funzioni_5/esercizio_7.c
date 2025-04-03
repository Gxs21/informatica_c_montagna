/*Il primo gennaio dell'anno 0 Augustus deposita in banca l'equivalente di un euro nella valuta allora in uso.
 Il primo gennaio di ogni anno successivo la banca versa un interesse pari al 5% dell'importo presente all'inizio dell'anno precedente. 
 Quindi il primo gennaio dell'anno 1 in banca ci sono 1 * 1.05 = 1.05 Euro. Al primo gennaio dell'anno 2 in banca ci sono 1.05 * 1.05 = 1.1025 Euro. 
  Al primo gennaio dell'anno 3 in banca ci sono 1.1025 * 1.05 = 1.157625 Euro, e così via. Il primo gennaio dell'anno 0 Claudia deposita 100 euro, nel suo caso con un tasso annuo del 4%.

Determinare l'anno all'inizio del quale la somma sul conto di Augustus risulta strettamente maggiore di quella di Claudia (Fonte: prof. Thomas H. Cormen)*/
#include <stdio.h>
int conti (){
    double augustus=1;
    double claudia=100;
    int year=0;
    do{
        augustus= (augustus*1.05);
        claudia=(claudia*1.04);
        year++;
    }while(augustus<=claudia);
    return year;
}

int main(){
    printf ("augustus risulta piu' ricco di chiara a partire dall'anno: %d", conti());
}
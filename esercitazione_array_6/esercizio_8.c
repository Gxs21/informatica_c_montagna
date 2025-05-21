/*Si ricorda che le stringhe in C non sono altro che array di char in cui l'ultimo elemento 
è il carattere '\0'.

Si realizzi una funzione

int string_length(char string[]);
atta a determinare la lunghezza della stringa fornita in ingresso. La funzione deve restituire 
in uscita il numero di caratteri contenuto nella stringa passata come parametro,
 escluso il carattere di terminazione '\0'.

Ad esempio, seppure la stringa "ciao" corrisponda all'array di 5 caratteri {'c', 'i', 'a', 'o', '\0'},
 il risultato di string_length("ciao") deve essere 4.

Nota: negli esercizi successivi, laddove sia strettamente necessario, è possibile impiegare la funzione 
string_length prodotta in questo esercizio, copincollandone il codice.*/
#include<stdio.h>

int string_lenght(char string[]){
    int i=0;
    while((string[i]!='\0')){
        i++;
    }
    return i;
}
int main(){
    char string[100];
    printf("inserire una stringa di meno di 100 caratteri: \n");
    ///scanf("%s", string); la scanf ferma la lettura al primo spazio inserito da tastiera
    scanf("%s", string);
    printf("la stringa inserita ha %d caratteri", string_lenght(string));
    return 0;
}
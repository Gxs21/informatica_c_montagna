/*Si realizzi una funzione

void invert_string(char string[], char result[]);
atta ad invertire la stringa fornita in ingresso, depositando la stringa invertita in result
 (e lasciando quindi la stringa originale intonsa).

Si noti che la funzione invert_string deve mantenere in coda a result il carattere di terminazione '\0'.
 Quindi, ad esempio, l'inversione di {'c', 'i', 'a', 'o', '\0'} deve produrre {'o', 'a', 'i', 'c', '\0'}.
  In altre parole, il carattere di terminazione '\0' non è soggetto all'inversione.*/

void invert_string(char string[], char result[]){
    int j=0;
    for (int i=len_string(string)-1; i>=0; i--){
        result[j]=string[i];
        j++;
    }
    result[len_string(string)]='\0';
}
int len_string(char string[]){
    int len=0;
    for (int i=0; string[i]!='\0'; i++){
        len++;
    } 
    return len;
}
/*
Si realizzi una funzione
int string_occurrences(char string[], char character);
atta a contare il numero di occorrenze del carattere character all'interno della stringa fornita 
come primo argomento.

Si noti che la funzione string_occurrences deve ignorare il carattere di terminazione '\0', 
anche qualora ne venga richiesto esplicitamente il conteggio. Quindi, ad esempio, 
il conteggio delle occorrenze di '\0' nella stringa {'c', 'i', 'a', 'o', '\0'} deve produrre 0. 
In altre parole, il carattere di terminazione '\0' non è soggetto al conteggio.
*/
#include <stdio.h>
int len_string(char string[]);
int string_occurrences(char string[], char character);
int string_occurreces (char string[], char character){
    int occurrences=0;
    for (int i=0; i<(len_string(string)); i++){
        if (string[i]==character){
            occurrences++;
        }
    }
    return occurrences;
}
int len_string(char string[]){
    int len=0;
    for (int i=0; string[i]!='\0'; i++){
        len++;
    }
    return len;
}
int main(){
    char string[100];
    char character='a';
    printf("inserire una stringa di caratteri di meno di 100 caratteri: ");
    scanf("%s", string);
    printf("inserire il carattere da cercare:");
    scanf(" %c", &character);
    printf("%d", string_occurreces(string, character));
    return 0;
}
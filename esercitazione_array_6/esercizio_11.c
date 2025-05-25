/*Si realizzi una funzione

int string_find(char string[], char character);
atta a cercare la prima posizione (cioé l'indice più basso) di character nella stringa fornita come primo argomento. La funzione deve restituire -1 nel caso in cui character non sia nella stringa.

In particolare, è fondamental che la ricerca sia condotta in maniera case insensitive. 
Ossia: lettere minuscole e maiuscole sono da considerarsi uguali. Ad esempio 'A' è da considerarsi uguale ad 'a'. A tal fine, si suggerisce di creare una funzione di appoggio con la firma simile alla seguente:

int char_equal(char c1, char c2);
atta a controllare che due caratteri c1 o c2 siano uguali o meno (ignorando eventuali divergenze di caso per le lettere).

Si noti che nella tabella ASCII la distanza tra ogni lettera maiuscola e la corrispondente lettera minuscola è fissa.*/

#include<stdio.h>
#define SIZE 100
int string_find(char string[], char character);
int equal_let(char c1, char c2);


int string_find(char string[], char character){
    for (int i=0; string[i]!='\0'; i++){
        if(equal_let(string[i], character)){
            return i;
        }else{
            continue;
        }
        
    }
    return -1;
}
int equal_let(char c1, char c2){
    if ((c1-c2)==0 || (c1-c2)== ('a'-'A') || (c1-c2)== ('A'-'a')){
        return 1;
    }else{ 
        return 0;
    }
}
int main(){
    char string[SIZE];
    char character='a';
    printf("inserire una stringa di meno di 100 caratteri: ");
    scanf("%s", string);
    printf("inserire il carattere da cercare: ");
    scanf(" %c", &character);
    printf("\n %d", string_find(string, character));
    return 0;
}
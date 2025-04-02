/*Scrivere e testare la funzione void solve_equation(double a, double b, double c) 
che calcola e stampa a video le soluzioni dell'equazione ax² + bx + c, 
se queste esistono nell'insieme dei numeri reali, altrimenti stampa "nessuna soluzione". 
La funzione non deve ritornare un valore (il tipo di ritorno deve essere void). 
Si assuma che a != 0, altrimenti non si tratterebbe di un'equazione di secondo grado. Allora:

Non esiste soluzione reale quando b² - 4ac < 0

Esiste una sola soluzione -b / 2a quando (b² - 4ac) == 0

Se b² - 4ac > 0 esistono due soluzioni reali distinte:

(-b + sqrt(b² - 4ac) / (2a)
(-b - sqrt(b² - 4ac) / (2a)
Si usi il tipo double per i parametri e per i calcoli. Per il calcolo della radice quadrata
 di un numero reale x si usi la funzione double sqrt(double x) definita in math.h, 
 che va incluso all'inizo del programma (#include <math.h>).
*/
#include <stdio.h>
#include <math.h>
void solve_equation(double a, double b, double c){
    double delta=((pow (b,2))-(4*a*c));
    if (delta<0){
        printf ("nessuna soluzione");
    }else if (delta==0){
        double soluzioni = (-b /(2*a));
        printf("l'unica soluzione reale doppia dell'equazione nei parametri: %.2f,%.2f,%.2f, è:%.2f", a, b, c, soluzioni);    
    }else{
        double soluzione_1= ((-b + (sqrt(delta))) / (2*a));
        double soluzione_2= ((-b - (sqrt(delta))) / (2*a));
        printf("le due soluzioni reali dell'equazione nei parametri: %.2f,%.2f,%.2f, sono:%.2f,%.2f", a, b, c, soluzione_1, soluzione_2);    
    }
    
}
int main (void){
    double a, b, c;
    do{
        printf ("inserire il primo coefficiente dell'equazione: \n");
        scanf ("%lf", &a);
    }while(a==0);
    printf ("inserire il secondo coefficiente dell'equazione: \n");
    scanf ("%lf", &b);
    printf ("inserire il terzo coefficiente dell'equazione: \n");
    scanf ("%lf", &c);
    solve_equation(a,b,c);
    return 0;
}
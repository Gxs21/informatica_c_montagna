#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main(){
    srand (time(NULL));
    int a = rand ();
    int b = rand ();
    printf ("%d, %d \n",a,b);
}
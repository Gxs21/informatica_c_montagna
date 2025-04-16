#include <stdio.h>

#define N 100
#define R 3
#define C 3

int max_array_ind(int pippo[], int size, int indexes[])
{
    int max=0;
    int j=0;
    for (int i=0; i<size; i++){
        if (pippo[i]>max){
            max=pippo[i];
        }
    }

    for(int i =0; i<size; i++){
        if(pippo[i]==max){
            indexes[j]=i;
            j++;
        }
    }

    return max;
}

void print_array (int pippo[], int size)
{
    for (int i=0; i<size; i++){
        printf("%d\n", pippo[i]);
    }
}

/* void modify_array(int pippo[], int size){
    for (int i=0; i<size; i++){
        pippo[i]=2;
    }
} */

int main(){
    int a[4]={10,20,30,40};
    int indexes[4]={0};
    print_array(indexes,4);
    max_array_ind(a,4, indexes);
    print_array(indexes,4);

}
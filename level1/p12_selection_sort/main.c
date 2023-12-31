#include <stdio.h>

void selection_sort(int* array,  int length){
    int min_index, temp;
    for (int i = 0;i < length; i++){

        min_index =  i;
        for (int j = i+1; j < length; j++){
            if (array[j] < array[min_index]){min_index = j;}
        }

        temp = array[i];
        array[i] = array[min_index];
        array[min_index] = temp;

    }
}

int main(){
    int a[] = {12,28,4,46,54,12,34,91,614,5,14,3,5,6,21,6,10};
    int n = sizeof(a)/sizeof(a[0]);
    selection_sort(a, n);
    for(int p = 0; p < n; p++){printf("%d ", a[p]);}
    return 0;
}



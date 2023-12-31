#include <stdio.h>

void insertion_sort(int* array, int length){
    int min_index, temp;

    for (int i = 0; i< length; i++){
        min_index = i;
        for (int j = i+1; j < length; j++){
            if (array[j] < array[min_index]){
                min_index = j;
            }
        }
        temp = array[min_index];
        array[i] = temp;
        for(int p = min_index; p > i+1; p--){
            array[p] = array[p-1];
        }
    }

}


void main(){
    int a[] = {42, 68, 35, 1, 70, 25, 79, 59, 63, 65, 6, 46, 82, 28, 62, 92, 96, 43, 28, 37, 92, 5, 3, 54, 93, 83, 22, 17, 19, 96, 48,27, 72, 39, 70, 13, 68, 100, 36, 95, 4, 12, 23, 34, 74, 65, 42, 12, 54, 69};
    int length = sizeof(a)/sizeof(a[0]);
    insertion_sort(a, length);
    for (int i = 0; i < length; i++){
        printf("%d ", a[i]);}
}
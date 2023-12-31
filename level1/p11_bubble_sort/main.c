#include <stdio.h>

int main(){
    int array[11] = {5,894,2,5,4,-5,13,4,6,-10,5,};
    int temp;
    int sorted = 1;
    int length =  sizeof(array)/sizeof(array[0]);
    while(sorted != 0){
        sorted = 0;
        for(int i = 0; i < length-1; i++){
            if (array[i] > array[i+1]){
                temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
                sorted++;
            }
        }
    }
    for(int j = 0;j<length;j++){
        printf("%d ",array[j]);
    }
    return 0;
}

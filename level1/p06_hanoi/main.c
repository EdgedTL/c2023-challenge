#include <stdio.h>

int hanoi(int n, char start, char assist, char target){
    if(n==1){
        printf("%c=>%c\n", start, target);
    }
    else{
        hanoi(n-1, start, target, assist);
        printf("%c=>%c\n", start, target);
        hanoi(n-1, assist, start, target);
    }
    return 0;
}

int main(){
    int N_layer;
    printf("Level of hanoi tower: ");
    scanf_s("%d",&N_layer);
    hanoi(N_layer, 'A', 'B', 'C');
    return 0;
}
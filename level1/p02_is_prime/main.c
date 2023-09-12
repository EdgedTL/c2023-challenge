#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main() {
    int a;
    printf("Input an integer\n");
    scanf("%d",&a);
    if(a == 0 || a == 1){
        printf("The number %d is not a prime",a);
        return 0;
    }
    int sqrt_a = (int)floor(sqrt(a));
    for (int i = 1; i<=sqrt_a;i++){
        if (a%i ==0){
            printf("The number %d is not a prime",a);
            return 0;
        }

    }
    printf("The number %d is a prime",a);
    return 0;
}
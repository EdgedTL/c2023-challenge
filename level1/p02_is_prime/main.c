#include <stdio.h>
#include <stdlib.h>
# include "prime.h"
#include <string.h>
#include <time.h>


int main() {
    int a;
    scanf("%d", &a);
    bool result = is_prime(a);
    if(result){
        printf("%d is prime", a);
    }
    else{
        printf("%d is not prime", a);
    }
    return 0;
}
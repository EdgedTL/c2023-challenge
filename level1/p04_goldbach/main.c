#include <stdio.h>
#include <stdbool.h>
#include "prime.h"

//int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};

int prime[];
void Even(int num){

    int index;
    int a,b;
    for (index = 0; index < 26;index++){
        if (num < prime[index]){
            index--;
            break;
        }
    }
    while(true){
        for (int i = 0; i<=index;i++){
            if (prime[index]+prime[i]==num){
                a = prime[index];
                b = prime[i];
                goto print_even;
            }
            else if(prime[index]+prime[i]>num){
                break;
            }
        }
        index--;
    }
    print_even:
    printf("%d = %d + %d\n", num,a,b);
}
void Odd(int num){
    int a,b,c;
    int index;
    for (index = 0; index < 26;index++){
        if (num < prime[index]){
            index--;
            break;
        }
    }
    while(true){
        for (int i = 0; i<index;i++){
            for (int j = 0;j<=i;j++){
                if (prime[index]+prime[i]+prime[j]==num){
                    a = prime[index];
                    b = prime[i];
                    c = prime[j];
                    goto print_odd;
                }
                else if(prime[index]+prime[i]>num){
                    break;
                }
            }
        }
        index--;
    }
    print_odd:
    printf("%d = %d + %d + %d\n", num,a,b,c);
}
void main() {
    int i = 0;
    for(int primes = 2; primes <= 2000; primes++){
        if (is_prime(primes)){
            prime[i] = primes;
            i++;
        }

    }

    printf("4 = 2 + 2\n5 = 3 + 2\n");
    for (int num = 6;num<=1000;num++){
        if (num%2 == 0){
            Even(num);
        }
        else{
            Odd(num);
        }
    }
}
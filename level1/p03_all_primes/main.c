#include <stdio.h>
#include <time.h>

long long GetTime(){
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    long long time = (ts.tv_sec * 1000LL) + (ts.tv_nsec / 1000000LL);
    return time;
}

int main() {
    long long start_time = GetTime();
    int prime[168] ;
    prime[0]=2;
    int previous_prime = 1;
    printf("2, ");
    for (int num = 3; num <= 1000; num+=2){

        int factor = 0;
        for (int i=0;i<previous_prime;i++){
            if (num%prime[i]==0){
            factor++;
            }
        }
        if(factor == 0){
            printf("%d, ",num);
            prime[previous_prime] = num;
            previous_prime ++;
        }

    }
    long long end_time = GetTime();
    printf("\n Time used: %lld milliseconds", (end_time - start_time));
}

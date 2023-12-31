#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>
#define target 100000
long long GetTime(){
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    long long time = (ts.tv_sec * 1000LL) + (ts.tv_nsec / 1000000LL);
    return time;
}

int main() {
   // int size = (int)floor(sqrt(target))*2;
    long long start_time = GetTime();
    int prime[target/2];
    prime[0]=2;
    int previous_prime = 1;
    printf("2, ");
    for (int num = 3; num <= target; num+=2){

        bool factor = false;
        for (int i=0;i<previous_prime;i++){
            if (num%prime[i]==0){
                factor = true;
                break;
            }
        }
        if(!factor){
            printf("%d, ",num);
            prime[previous_prime] = num;
            previous_prime ++;
        }

    }
    long long end_time = GetTime();
    printf("\n Time used: %lld milliseconds", (end_time - start_time));
}

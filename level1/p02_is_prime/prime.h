//
// Created by Admin on 25/9/2023.
//

#ifndef C2023_CHALLENGE_PRIME_H
#define C2023_CHALLENGE_PRIME_H

#include <stdbool.h>
#include <math.h>

bool is_prime(int input){
    if(input == 0 || input == 1){
        return false;
    }
    int sqrt_input = (int)floor(sqrt(input));
    for (int i = 2; i<=sqrt_input;i++){
        if (input%i ==0){
            return false;
        }

    }
    return true;
}

#endif //C2023_CHALLENGE_PRIME_H

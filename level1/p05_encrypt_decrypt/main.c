/*#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

char base64_chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

char* base64_encode(const unsigned char* input, size_t length) {
    size_t encoded_length = 4 * ((length + 2) / 3);
    char* encoded_data = (char*)malloc(encoded_length + 1);
    if (!encoded_data) return NULL;

    size_t i = 0;
    size_t j = 0;
    while (i < length) {
        uint32_t octet_a = i < length ? input[i++] : 0;
        uint32_t octet_b = i < length ? input[i++] : 0;
        uint32_t octet_c = i < length ? input[i++] : 0;

        uint32_t triple = (octet_a << 0x10) + (octet_b << 0x08) + octet_c;

        encoded_data[j++] = base64_chars[(triple >> 3 * 6) & 0x3F];
        encoded_data[j++] = base64_chars[(triple >> 2 * 6) & 0x3F];
        encoded_data[j++] = base64_chars[(triple >> 1 * 6) & 0x3F];
        encoded_data[j++] = base64_chars[(triple >> 0 * 6) & 0x3F];
    }

    // Add padding characters if needed
    for (size_t k = 0; k < (3 - length % 3) % 3; k++) {
        encoded_data[encoded_length - 1 - k] = '=';
    }

    encoded_data[encoded_length] = '\0';
    return encoded_data;
}

int main() {
    const char* originalText = "Hello, World!";
    const size_t originalLength = strlen(originalText);

    char* base64Encoded = base64_encode((const unsigned char*)originalText, originalLength);
    printf("Base64 Encoded: %s\n", base64Encoded);

    free(base64Encoded);

    return 0;
}*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

char letters[] = {' ','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',',','.','!','?','@','#','(',')','[',']','{','}','1','2','3','4','5','6','7','8','9','0','+','-','*','/','=','-','_','&','^','%','$','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
int random(int min,int max) {
    srand(time(NULL));
    int random_number = rand() % (max - min + 1) + min;
    return random_number;
}
char* encrypt (char* input){
    int r = 0;
    r = random(15, 86);
    int len = strlen(input);
    char* output = (char*)malloc(len + 2);

    if (output == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);  // Handle memory allocation failure
    }

    output[len + 1] = '\0';
    output[len] = (char )(r);


    for(int index = 0;index < len ;index++){
        int pointer = 0;
        for (pointer = 0;pointer <= 85; pointer++){
            if (input[index]==letters[pointer]){
                output[index]=letters[(pointer+r)%86];
                break;
            }

        }

    }
    return output;
}
char* decrypt(char* input){
    int jump = 0;
    int len = strlen(input)-1;
    static char output[(sizeof (input)-2)];
    jump = (int)(input[len]);
    jump = 86-jump;
    for(int index = 0;index < len;index++){
        int pointer = 0;
        for (pointer = 0;pointer < 86; pointer++){
            if (input[index]==letters[pointer]){
                output[index]=letters[(pointer+jump)%86];
                break;
            }

        }

    }
    output[len] = '\0';
    return output;
}
void main ()
{
    char input[] = {};
    gets(input);
    char* coded;
    char* output;
    coded = encrypt(input);
    printf("%s\n", coded);
    output = decrypt(coded);
    printf("%s", output);

}
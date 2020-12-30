//
//  main.c
//  keygen
//
//  Created by Will Koury on 12/30/20.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned char generateRandomChar(void);

int main(int argc, const char * argv[]) {
    
    const int DEFAULT_LENGTH = 64;
    
    unsigned char ret[DEFAULT_LENGTH];
    
    //initialize the random number generator
    time_t t;
    srand((unsigned) time(&t));
    
    for(int i = 0; i < DEFAULT_LENGTH; ++i){
        unsigned char rando = generateRandomChar();
        ret[i] = rando;
    }
    
    printf("%s\n", ret);
    
    return 0;
}

//generate a random character, recursively disallowing invalid characters
unsigned char generateRandomChar(){
    unsigned char ret = (unsigned char)(rand() % 126 + 1);
    if(ret < 33 || ret > 126){ //return a different character if we get one that is not allowed
        return generateRandomChar();
    }
    
    return ret;
}

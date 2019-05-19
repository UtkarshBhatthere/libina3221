#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include "inc/inaRegisterMap.h"
#include "inc/inaTypes.h"

int tenBit[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

void printBinary(int number){
    bool bit;
    int index = 16;
    while(number > 0){
        bit = number%2;
        number = number/2;
        tenBit[index--] = bit;
    }
    printf("\nnumber is ");
    for (int i = 0 ; i <= 16; i++){
        printf("%d", tenBit[i]);
    }
}

void main(){
    inaChannel_t chan = ChannelOne;
    inaAveragingMode_t averagingMode = avgModeSamples4;
    int a = (averagingMode << (ina_EnMaskSummationControlShiftMask + (3-chan)));
    printf("%d\n", a);
    printBinary(a);
}
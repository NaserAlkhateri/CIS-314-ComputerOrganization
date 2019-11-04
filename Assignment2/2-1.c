//2-1.c

#include <stdio.h>

int mask(int n){
    
    unsigned int mask;
    printf("mask(%d): ",n);
    mask =  (1 << n) - 1; //shift to the left and leave the 1s
    // - 1 will help because its 0 to 31 for the 32 bit
    return mask;
}

int main()
{
    
    printf("0x%X\n",mask(0)); //0x0
    printf("0x%X\n",mask(1)); //0x1
    printf("0x%X\n",mask(2)); //0x3
    printf("0x%X\n",mask(3)); //0x7
    printf("0x%X\n",mask(5)); //0x1F
    printf("0x%X\n",mask(8)); //0xFF
    printf("0x%X\n",mask(16)); //0xFFFF
    printf("0x%X\n",mask(31)); //0x7FFFFFFF
    return 0;
}
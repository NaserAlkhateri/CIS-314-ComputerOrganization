//2-2.c
#include <stdio.h>
unsigned int extract (unsigned int x, int i){
    
    int n,y,bitNum;
    printf("extract(0x%08X, %d): ",x,i);
	
	bitNum = (3 - i) << 3; //creates the ideal number required for shifting without arithmetic operator.
    n = x << bitNum; //left shift upto where indicated
    y = n >> 24; //right shift it back leaving only the last 2 bytes, 24 works with all.
    return y;
}
int main()
{
	
    printf("0x%08X\n",extract(0x12345678, 0)); //0x00000078
    printf("0x%08X\n",extract(0xABCDEF00, 2)); //0xFFFFFFCD
    
    return 0;
}
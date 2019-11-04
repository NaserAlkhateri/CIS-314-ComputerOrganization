//7-2.c
#include <stdio.h>

//manipulated bytes using mask, to return the 
//specified requirments
unsigned int getOffset(unsigned int address){
	return (address & 0x0000000F);
}
unsigned int getSet(unsigned int address){
	return (address & 0x000000F0) >> 4;
}
unsigned int getTag(unsigned int address){
	return (address & 0xFFFFFF00) >> 8;
}
int main(){
	unsigned int num = 0x12345678;
	printf("0x%X: offset: %X - tag: %X - set: %X\n",num,getOffset(num),getTag(num),getSet(num));

    num = 0x87654321;
    printf("0x%X: offset: %X - tag: %X - set: %X\n",num,getOffset(num),getTag(num),getSet(num));
	return 0;
}
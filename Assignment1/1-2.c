//this is 1-2.c Assignment 1 q2

#include <stdio.h>


unsigned int combine(unsigned int x, unsigned int y){

	unsigned int z;
	printf("replace(0x%X, 0x%X): ",x,y); //since it will be altered, print first. 
	x = x & 0xffff0000; // makes one half masked
	y = y & 0x0000ffff; // same, but with the other half
	z = x | y; // combines
	

	return z;
}

//unsigned int combineT(usigned int x, unsigned int y){}
int main(){

  printf("0x%X\n",combine(0x12345678, 0xABCDEF00));// outputs the returned value.
  printf("0x%X\n",combine(0xABCDEF00, 0x12345678));
  return 0;

}


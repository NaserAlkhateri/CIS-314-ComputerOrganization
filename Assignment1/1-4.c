//this is 1-4.c
#include <stdio.h>

int oddBit(unsigned int x){

  unsigned int mask = 0xAAAAAAAA;// hex representation of 101010101.. basically even bits of a 32 bit number
  printf("oddBit(%X): ", x);//prints the value that is being checked
  x = x & mask;// isolates the bits
 
  return (x && mask); //returns true or false
}
int main(){

  printf("%d\n",oddBit(0x1));
  printf("%d\n",oddBit(0x2));
  printf("%d\n",oddBit(0x3));
  printf("%d\n",oddBit(0x4));
  printf("%d\n",oddBit(0xFFFFFFFF));
  printf("%d\n",oddBit(0xAAAAAAAA));
  printf("%d\n",oddBit(0x55555555));

  
  return 0;
}

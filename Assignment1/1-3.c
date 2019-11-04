// this is 1-3.c

#include <stdio.h>
unsigned int replace(unsigned int x, int i, unsigned char b){
  int num1;
  unsigned int num2;
  unsigned int mask;
  unsigned int outputNum;
  
  num1 = 4 << i; //gets the bit value without using arethmetics
  mask = 0xFF << num1; // mask the byte thats intended
  num2 = (x & ~mask); // creats the zeros  where indicated
  outputNum = (num2 | (b << num1)); // brings the values that need to be added and combines to create the final result

  printf("replace(0x%X, %d, 0x%X): " ,x,i,b); // to make the output like the test run
  
  return outputNum;
  }

int main(){
  
  printf(" 0x%X\n",replace(0x12345678, 2, 0xAB)); //prints out the returned value
    // should output 0x12AB5678
  //replace(0x12345678, 0, 0xAB)
  return 0;
}

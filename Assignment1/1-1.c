// this is 1-1.c

#include <stdio.h>


void printBytes(unsigned char *start, int len){
	for (int i = 0; i < len; ++i) {
		printf(" %.2x", start[i]);
	}
	printf("\n");
}

void printInt(int x){
	printBytes((unsigned char *) &x, sizeof(int));
}
void printFloat(float x){
	printBytes((unsigned char *) &x, sizeof(float));
}
void printShort(short x){
	printBytes((unsigned char *) &x, sizeof(short));
}
void printLong(long x){
	printBytes((unsigned char *) &x, sizeof(long));
}
void printDouble(double x){
	printBytes((unsigned char *) &x, sizeof(double));
}
int main(){
 
	printInt(12345);
	printFloat(12345.0);
	printShort(40000);
	printLong(211111111);
	printDouble(1.11);
	
	/*
	  This c code outputs the byte representation of the the value using different  
	  types. From the observation of the output, sizes are different and so the byte
	  representaion. I used the same number that is used in the book, it matched with
	  book's outputs.
	 */

	
	return 0;
}

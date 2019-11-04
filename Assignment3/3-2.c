//this is 3-2.c
#include <stdio.h>

long f(long a, long b, long c){
    //these where all obtained from following the format and computations needed
    b = b - c;  
    a = a * b;
    b = b << 63;
    b = b >> 63;
    long a1 = a; //%rax (dest) is another number
    a1 = a1 ^ b;
    
    return a1;
}
int main(){
    
    printf("decode(1, 2, 4): %d\n", f(1,2,4));
    printf("decode(3, 5, 7): %d\n", f(3, 5, 7));
    printf("decode(10, 20, 30): %d\n", f(10, 20, 30));
    return 0;
}
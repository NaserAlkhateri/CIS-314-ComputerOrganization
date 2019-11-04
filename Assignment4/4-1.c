#include <stdio.h>
#include <stdlib.h>
long loop(long a, long b) {
    long result = 0;
    for (long mask = 1; mask != 0 ; mask <<= (b & 0xFF) ) {
        result |= (mask & a);}
    return result;
}
/*
loop:
	movq %rsi, %rcx     :: movq a, b
	movl $1, %edx		:: movl $1, mask
	movl $0, %eax		:: movl $0, result
.L2:
	testq %rdx, %rdx	:: testq mask, mask
	je	.L4				:: condition !=
	movq %rdx, %r8		:: movq mask, a
	andq %rdi, %r8		:: andq a, a
	orq %r8, %rax		:: orq a, result
	salq %cl, %rdx		:: salq b, mask
	jmp .L2				:: condition loop
.L4:
	ret					:: return
*/
int main()
{
    printf("loop(1,5): %d \n",loop(1,5));//1
    printf("loop(2,4): %d \n",loop(2,4));//0
    printf("loop(3,3): %d \n",loop(3,3));//1
    printf("loop(4,2): %d \n",loop(4,2));//4
    printf("loop(1,5): %d \n",loop(5,1));//5
    return 0;
}

//this is 4-2.c
#include <stdio.h>
long sum(long from, long to) {
long result = 0;
// Ensure that argument *from* is in %rdi, 
// argument *to* is in %rsi, *result* is in %rax -do not modify.
__asm__ ("movq %0, %%rdi # from in rdi;" :: "r" ( from )); 
__asm__ ("movq %0, %%rsi # to in rsi;" :: "r" ( to )); 
__asm__ ("movq %0, %%rax # result in rax;" :: "r" ( result )); 
// Your x86-64 code goes below -comment each instruction...
//__asm__("movq %rsi, %rax # For example, this sets result = to;");
__asm__ (".L2:");
__asm__("addq %rdi, %rax");// result +=from; add from to result, save in result
__asm__("addq $1, %rdi"); // ++from; adds 1 to the variable
__asm__("cmpq %rsi, %rdi");// compare from and to
__asm__("jle .L2");// <= for the above
// Ensure that *result* is in %rax for return -do not modify.
__asm__ ("movq %%rax, %0 #result in rax;" : "=r" ( result )); 
return result;
}
int main(){
	
	printf("sum(1,6): %d\n",sum(1,6));
	printf("sum(3,5): %d\n",sum(3,5));
}
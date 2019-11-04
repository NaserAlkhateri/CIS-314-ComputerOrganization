//this is 4-3.c
/*.L3:
movq (%rax), %rcx :: movq *t1, a        pointer of rax to rcx
movq (%rdx), %rsi :: movq *t2, a        pointer of rdx in rsi
movq %rsi, (%rax) :: movq a,*t1         pointer of rax to rsi
movq %rcx, (%rdx) :: movq a,*t2         pointer of rdx to rcx
addq $8, %rax	  :: addq $8, t1         8 to the address of rax
addq $32, %rdx	  :: addq $32,t2        32 to the address of rdx
cmpq %r9, %rax	  :: compare
jne .L3           ::  */
#include <stdio.h>
#include <stdlib.h>
#define N 4
typedef long array_t[N][N];

void transpose(array_t a){
	//iterate to print array
        printf("The input:\n");
        for (long i = 0; i < N; i++) {
            printf("{");
            for (long j = 0; j < N; j++) {
                printf("%d", a[i][j]);
                if (j < N - 1)
                    printf(", ");
            }
            printf("}");
            if (i < N - 1)
                printf(", ");
        }
    printf("}\n");

    for (long i=0; i<N; ++i){
		//take the address of the row and col
        long *col = &a[0][i];
        long *row = &a[i][0];
        for (long j = 0; j < i; ++j){
			//swap
            long t1 = *row;
            long t2 = *col;
            *row = t2;
            *col = t1;
            row++;//increment by 1 becuase we divide the number of bits by 8 
            col += 4;//by using the number from x86_64
            
        }
    }
        printf("\nTransposed as:\n");
        for (long i = 0; i < N; i++) {
            printf("{");
            for (long j = 0; j < N; j++) {
                printf("%d", a[i][j]);
                if (j < N - 1)
                    printf(", ");
            }
            printf("}");
            if (i < N - 1)
                printf(", ");
        }
    printf("}\n");
    
}
int main()
{

    long array_t[N][N] = {{1,2,3,4},{5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    transpose(array_t);
    return 0;
}
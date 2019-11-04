//6-2.c
#include <stdio.h>
#include <time.h>
void inner(float *u, float *v, int length, float *dest) { 
    int i; 
    float sum = 0.0f;
    for (i = 0; i < length; ++i) { 
        sum += u[i] * v[i]; 
    } 
    *dest = sum; 
}
void inner2(float *u, float *v, int length, float *dest){
    
    int i;
    
    //4 accumalators
    float sum1, sum2, sum3, sum4 = 0.0f;
    for (i = 0; i < length; i+=4){
        sum1 += u[i] * v[i];
        sum2 += u[i+1] * v[i+1];
        sum3 += u[i+2] * v[i+2]; 
        sum4 += u[i+3] * v[i+3]; 
    }
    for (; i < length; ++i){
        sum1 = sum1 * v[i];
    }
    *dest = (sum1 + sum2 + sum3 + sum4);
}

int main()
{
    float x,y,dest,*ptrX,*ptrY,*ptrDest;
    clock_t start, end;
	double total_time;
    x = 4.0f;
    y = 5.0f;
    ptrX = &x;
    ptrY = &y;
    ptrDest = &dest;
    start = clock();
    inner(ptrX,ptrY,6,ptrDest);
	end = clock();
	total_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("inner speed: %f\n",total_time);
    start = clock();
    inner2(ptrX,ptrY,6,ptrDest);
    end = clock();
	total_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("inner2 speed: %f\n",total_time);
    return 0;
}
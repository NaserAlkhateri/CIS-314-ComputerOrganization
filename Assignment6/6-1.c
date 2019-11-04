//6-1.c
#include <stdio.h>
#define N 4
typedef int array_t[N][N];

//removed dim()
//replaced with N
void f(array_t a, int z) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            a[i][j] = i * z + j; 
        }
    } 
}
void displayArray(array_t a){
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < N; ++j){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
int main()
{
//multiplied the two numbers before calling f
    array_t a;
    int x = 1;
    int y = 2;
    int z = x * y;
    f(a,z);
	displayArray(a);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct{// defined that IntArray is a struct;therefore no need to keep typing struct is needed - shown in lab
int length;
int *dataPtr;
}IntArray;

IntArray* mallocIntArray(int length){
	IntArray * array = (IntArray*) malloc(sizeof(IntArray)); //malloc for the struct
	array->length = length; //setting the length given with the array
	array->dataPtr = (int *) malloc(sizeof(int) * length);//malloc for the array using the size given
	return array;
	
}
void freeIntArray(IntArray *arrayPtr){
    free(arrayPtr->dataPtr);//freeing memory
	free(arrayPtr);
}
void readIntArray(IntArray *array){
    /*
    in this function, using the size that is given by the user
    the code will ask for the user for positive numbers and adding    
    them to the array. the numbers will start at index 0 and goes upto but not 
    including the length of the array.
    */
    int i, num1, size;
    char str;
    size = array->length;
	for(i = 0;i < size;i++)
    {
        printf("Enter int: ");//validates input
		while (scanf("%d", &num1) != 1 || num1 < 0){
            while ((str = getchar()) != '\n')
                putchar(str);
            printf("\nInvalid Input!\nEnter int:");
    }
        array->dataPtr[i] = num1;
    }
    
}
void swap(int *xp, int *yp){
	//simply making a variable that takes a referenced xp value so that keeps
	//and use it to swap with  yp while xp is directly swapped with yp
	int numXP = *xp;
	*xp = *yp;
	*yp = numXP;
}

void sortIntArray(IntArray *array){
//source for the sort:
//https://www.geeksforgeeks.org/selection-sort/

	int n = array->length;
	int i, j;
	int minNum = 0;
	for (i = 0; i < n - 1; i++){//to iterate on the length of the array, n -1 because of the index e.g if length is 5, 5th number's index is 4
	    minNum = i;//minNum will be used as "temp" to be used as index to compare the other array nums.
		for(j = i + 1; j < n; j++)//starts in different index so its useful to compare
			if (array->dataPtr[j] < array->dataPtr[minNum])
				minNum = j;//if the number is smaller with index num J will pass the one
				            //it will be given to minNum, otherwise just swap as-is because it will be already smaller
		//swap will be called the each time in the iterator, but minNum will always be smaller
		swap(&array->dataPtr[minNum], &array->dataPtr[i]);
	}
}
void printIntArray(IntArray *array){
    //simply iterates through the array and print each number
	int n = array->length;
	printf("[");
	for(int i = 0; i < n; i++){
		printf("%d ", array->dataPtr[i]);
	}
	printf("]\n");
}

int main()
{

	int userInput,num1;
	printf("Enter length: ");
//source for input validation
//https://www.9wy.net/onlinebook/CPrimerPlus5/ch08lev1sec6.html
    /*
    
    */
    char str;//useful to take the letters from the userInput
    //this also handles situations when numbers and strings are typed
    while (scanf("%d", &userInput) != 1 || userInput < 0)
    {//takes input and checks if its not int and if its positive
        while ((str = getchar()) != '\n')//this will get rid of the invalid input if it issn int
            putchar(str);//'\n' is another way of saying ENTER, therefore if the user only
            //typed numbers after that comes normally comes '\n' by default which is in the code, therefore the 2nd loop
			//will start if its not \n which is supposed to be if only an integer was given.
        printf("\nInvalid Input!\nEnter length:");
    }

	IntArray * array = mallocIntArray(userInput);
    readIntArray(array);
	sortIntArray(array);
	printIntArray(array);
    freeIntArray(array);
    return 0;
}
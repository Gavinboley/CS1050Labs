/*
 * Gavin Boley
 * CS1050
 * Lab6
 * Oct 8 2021
 * Fall 2021
 * gzbkxc
 */

#include <stdio.h>

void declareArray( int begin, int end, int step, int a1[]); //down
void MultArrays(int array1[], int array2[], int arrayOut[], int size); //declarations for the functions i use
void printArray(int a1[], int a2[], int a3[], int size); //up
int main(void) //this is the main function of the code
{
	printf("First Arrays:\n");
	
	int a1[100] = {0}; int a2[100] = {0}; int a3[100] = {0}; //declare the arrays with 100 spaces
	declareArray( 1, 31, 3, a1); //starts at 1, goes to 31, goes by step of 3
	declareArray( 2, 52, 5, a2); //same idea
	MultArrays(a1, a2, a3, 11); //makes array 3 by multiplying array 1 and 2 at i
	printArray(a1, a2, a3, 11); //this prints the first set of arrays
	
	printf("Second Arrays:\n");	

	declareArray( 22, 0, -2, a1); //starts at 22, goes to zero, goes by step of -2
        declareArray( 84, 7, -7, a2); //same idea
        MultArrays(a1, a2, a3, 12); //makes array 3 by multiplying secpmd set of arrays
        printArray(a1, a2, a3, 12); //this prints set 2 of arrays
}

void declareArray(int begin, int end, int step, int array[]) //declares for array 1 and 2 by the predefined step and start/end values.
{
	int number = begin;
	if(step > 0)
	{
		for(int i = 0; number <= end; i++) //loop that changes the values of the array at i
		{
			array[i] = number;
			number += step;
		}
	}
	else if (step < 0) //when the step is negative instead, it goes down
	{
		for(int i = 0; number >= end; i++)
		{
			array[i] = number;
			number += step;
		}
	}
}

void MultArrays(int array1[], int array2[], int arrayOut[], int size)
{
	for(int i = 0; i <= size; i++) //replaces values in array 3 at i with value of array1 and array 2 multiplied there
	{
		arrayOut[i] = array1[i] * array2[i];
	}
}

void printArray(int a1[], int a2[], int a3[], int size) 
{
	for(int i = 0; i < size; i++)
        {
                printf("Array 1 Element  %d = %d  Array 2 Element  %d = %d Array 3 Element %d = %d\n", i, a1[i], i, a2[i], i, a3[i]); //print yes
        }

}

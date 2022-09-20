/*
 * Gavin Boley
 * CS1050
 * Fall 2021
 * 10/15/21
 * gzbkxc
 */
#include <stdio.h>

void GetIntArray(int *outputArray, int * count);
void PrintArray(int * array, int count);                //declarations of method functions
int TotalArray(int * array, int count);
float AvgArray(int * array, int count);
int main(void)
{
	int numofvalues;
	int values[100] = {0}; //declare blank array
	printf("Welcome to Lab 7-8 \n");
	GetIntArray(values,&numofvalues); //user inputs count and array values
	PrintArray(values,numofvalues); //prints the array given by user
	printf("\nTotal of array = %d\n", TotalArray(values, numofvalues)); //prints sum of values in array
	printf("Average of array = %.2f\n", AvgArray(values, numofvalues)); //prints the average of values in array 
}
void GetIntArray(int *outputArray, int * count)
{
	printf("\nEnter the number of elements in the array: ");
	scanf("%d", count );      //gets number of values from user
	for(int i =0; i< *count; i++)
	{
		printf("\nEnter element #%d: ", i);  //asks user for that number of values then assigns them to the array for later use
		scanf("%d", outputArray);
		outputArray++;
	}
}
void PrintArray(int * array, int count)
{
	printf("\nHere are the %d elements of your array:", count);
	for(int i=0; i<count; i++)
	{
		printf("\nElement %d = %d",i, *array ); //prints the array of values by value
		array++;
	}
}
int TotalArray(int * array, int count)
{
	int total = 0;
	for(int i=0; i< count; i++)
	{
		total += *array; //individually adds each value of an array at a number
		array++;
	}
	return total;
}
float AvgArray(int * array, int count)
{
	float average = 0.00;
	float numerator = 0.00;
	for(int i=0; i<count; i++)
	{
		numerator += (float) *array; //gets the sum of values and then divides by total to get all average
		array++;
	}
	average = numerator / count;
	return average;
}

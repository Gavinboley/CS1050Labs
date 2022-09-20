/******************************************************************************
 * Course: CS 1050
 * Semester: Fall 2021
 * Data: September 3,2021
 * Lab: Lab 2
 * Author: Gavin Boley
 * Pawprint: gzbkxc
 ******************************************************************************/

#include <stdio.h>

int main(void)
{
	//declaring int values the user will input later
	int A;
	int B;
	int C;
	int D;
	
	//asking the user for 4 numbers
	printf("Enter four whole numbers seperated by a space:\n");
	scanf("%d %d %d %d", &A, &B, &C, &D );
	
	//printing either a sum, product, quotient, remainder of quotient, or fraction calculation using the numbers the user input.	
	printf("A = %d, B = %d, C = %d, D = %d\n", A, B, C, D);
	printf("A plus D = %d\n" , A+D);
	printf("B times C = %d\n", B*C);
	printf("C divided by A = %d\n", C/A);
	printf("integer remainder of D divided by C = %d\n", D%C);
	printf("A times B divided by the quantity of D plus D = %d\n", (A*B)/(C+D));
}
	

/*
 *Gavin Boley
 *CS1050
 *Lab5
 *Fall 2021
 *10/1/21
 */

#include <stdio.h>

long factorial(int n);
double getE(void);

int main(void)
{
	printf("\n");
	printf("%.10f", getE());//printing the double of e to 10 places
	printf("\n");
}

long factorial(int n) //determines the denominator of the factorial at i
{
	long result=1;

	for (int i=n;i>1;i--)
	{
		result*=i;
	}
	
	return result;
}

double getE(void) //determines factorial given the denominator from factorial and estimates to 10 places
{
	double e;

	for (int i = 0; i < 40; i++)	
	{
		e+=(1.0/factorial(i));
	}
	return e; //sends back to print
}

/**********************************************
 * Gavin Boley
 * gzbkxc
 * CS1050
 * LAB 3
***********************************************/
#include <stdio.h>

int main(void)
{
	int i = 50; //loop int declaration
	
	while (i >= 2)
	{
		if (i%5 == 0) //if its divisible by 5
		{
			if (i%3 == 0)	//if its divisible by 5 then 3
			{
				printf("XY\n");
			}
			else	//if only divisible by 5
			{
				printf("X\n");
			}
		}
		else if (i%3 == 0) //if not divisible by 5 and only 3
		{
			printf("Y\n");
		}
		else //every other number
		{
			printf("%d\n" , i );
		}
		
		i -=2 ;
	}
}

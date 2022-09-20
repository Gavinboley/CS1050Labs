/*
 * Gavin Boley
 * gzbkxc
 * CS1050
 * Lab 4
 * */

#include <stdio.h>

int main(void)
{
	int start;
	int limit;	//declare start and limit values for later user input
	
	for(int isstartgood = 0; isstartgood != 1 ; isstartgood +=0 ) //while the value of user inputted start is not between 1 and 150
	{								//ask them again for new values until they are
	
		printf("Enter Start:");
		scanf("%d", &start);
		isstartgood = (start >= 1 ? (start <= 150 ? 1 : 0)  : 0 );
	}

	for(int islimitgood = 0; islimitgood != 1 ; islimitgood +=0 ) //while the value of user unputted limit value is not between 1-150
        {								//ask them again for new values until they are

                printf("Enter Limit:");
                scanf("%d", &limit);
                islimitgood = (limit >= 1 ? (limit <= 150 ? 1 : 0)  : 0 );
        }
	for(int step = start; step <= limit; step += 3) //start the loop at start and print every number plus 3 until limit is reached
	{	
		printf("%d ", step);
	}
	printf("\n");
}

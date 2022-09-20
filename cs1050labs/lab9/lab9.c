/*
 * Gavin Boley
 * gzbkxc
 * 10/29/2021
 * CS1050
 * Jim Ries
 * Fall 2021
 *
 * */
#include <stdio.h>

void getString(char*);
int calculateSegment(char *string);
void reverseSegment(char *origstring, int segments);

int main(void)
{
	printf("*** Welcome to Lab 9 *** \n");
	char original[100];
	getString(original);
	printf("You entered: %s\n",original);
	int segments = calculateSegment(original);
	reverseSegment(original, segments);
	printf("There are %d segments in the string. ", segments);
	printf("The modified string is: %s\n",original);
	printf("*** Thanks for doing Lab 9 ***\n ");
}

void getString(char *string)
{
	printf("Please enter a string: \n"); //assigns user string to pointer of string delcared in main
	scanf("%s",string);
}

int calculateSegment(char *string)
{
	int segments;
	int size = 0;
	while(*string != '\0') //manually counts the size of the string
	{	
		size++;
		string++;
	}	
        if(size%5==0)
        {
               segments = size/5;
        }
        else                        //segments counted
        {
                segments = (size/5)+1;
        }
	return segments;
}

void reverseSegment(char *origstring, int segments)
{
	char tempstorage[200] = {'\0'}; 
	char *tempSPtr = tempstorage;
	int charnum = 0;
	origstring += (5*segments) - 5;
	for(int i = 1;i<=segments;i++) //comb through the segments
	{
		for(int p = 0;p<5;p++) //comb through each segment individually
		{
			if(*origstring != '\0') //when the string isnt done
			{
				*tempSPtr = *origstring; //assign to the temp string the value of original
				tempSPtr++;
				charnum++;
			}
			origstring++;
		}
		origstring -= 10; //offset
	}
	origstring += 5;
	tempSPtr -= charnum;
	for(int i=0;i<(5*segments);i++) //each segment
	{
		*origstring = *tempSPtr; //reordering the segments
		origstring++;
		tempSPtr++;
	}
}


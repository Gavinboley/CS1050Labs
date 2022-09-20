/* 
 * Gavin Boley
 * CS1050
 * 11/19/1021
 * gzbkxc
 * Lab 12
 */

#include<stdio.h>
#include<string.h>

typedef struct
{
	char title[60];
	long gross;
	int year;
} movie;

int getMovies(char filename[], movie movies[]);
int sortMovies(char paramater[], movie movies[], int argc, int nummovie);
void printMovies(movie movies[],int nummovie);

int main(int argc, char *argv[])
{
	movie movies[30];
	//char filename[] = "movies.dat";
	getMovies(argv[1], movies);
	int nummovie = getMovies(argv[1], movies);
	if(sortMovies(argv[2], movies, argc, nummovie))
		printMovies(movies, nummovie);
}

int getMovies(char filename[], movie movies[])
{
	FILE *fp;
	fp = fopen(filename,"r");
	int i = 0;
	if(fp == NULL)
	{
		printf("AAAAAAAAAAAAAAAAAAAAAAAAAAA file broke\n");
		return 0;
	}
	else
	{
		//printf("TITLE\t\tGROSS:\t\tYEAR:\t\n");
		while(!feof(fp))
		{
			char title[200] = {"\0"};
			long gross;
			int year;
			fscanf(fp,"%[^ ] %ld %d\n", title, &gross, &year);
			//printf("%40s %20ld %4d", title, gross, year);
			movie temp;
			strcpy(temp.title, title);
			temp.gross = gross;
			temp.year = year;
			movies[i] = temp;
			i++;
		}
		fclose(fp);
		return i;
	}
	return 0;
}

int sortMovies(char paramater[], movie movies[], int argc, int nummovie)
{
	if(argc == 3)
	{
		if(!strcmp(paramater,"Gross"))
		{
			movie temp;
			int length = nummovie;// sizeof(movies)/ sizeof(movies[0]);
			for(int i = 0; i < length-1; i++)
			{
				for(int j = 0; j < length-1-i; j++)
				{
					if(movies[j].gross > movies[j + 1].gross)
					{
						temp = movies[j];
						movies[j] = movies[j + 1];
						movies[j + 1] = temp;
					}
				}
			}
			return 1;
		}
		if(!strcmp(paramater,"Year"))
		{
			movie temp;
	                int length = nummovie;// sizeof(movies)/ sizeof(movies[0]);
	                for(int i = 0; i < length-1; i++)
	                {
				 for(int j = 0; j < length-1-i; j++)
                	        {
         	                       if(movies[j].year > movies[j + 1].year)
                	                {
                        	                temp = movies[j];
                        	                movies[j] = movies[j + 1];
                        	                movies[j + 1] = temp;
                        	        }
				}
	                }
			return 1;
		}
		if(!strcmp(paramater,"Title"))
                {
                        movie temp;
                        int length = nummovie;// sizeof(movies)/ sizeof(movies[0]);
                        for(int i = 0; i < length-1; i++)
                        {
                                 for(int j = 0; j < length-1-i; j++)
                                {
                                       if(strcmp(movies[j].title,movies[j+1].title) > 0)
                                        {
                                                temp = movies[j];
						movies[j] = movies[j + 1];
                                                movies[j + 1] = temp;
                                        }
                                }
                        }
			return 1;
                }

		else
		{
			printf("bruh you typed bad parameter\n");
			return 0;
		}
	}
	else
	{
		movie temp;
                int length = nummovie;// sizeof(movies)/ sizeof(movies[0]);
                for(int i = 0; i < length-1; i++)
                {
                       for(int j = 0; j < length-1-i; j++)
                       {
                              if(strcmp(movies[j].title,movies[j+1].title) > 0)
                              {
                                    temp = movies[j];
                                    movies[j] = movies[j + 1];
                                    movies[j + 1] = temp;
                              }
                       }
                }
		return 1;
	}
}

void printMovies(movie movies[],int nummovie)
{
	printf("\t\t\t\t  TITLE:\t\t\t\tGROSS:\tYEAR:\n");
	int i;
	while(i<nummovie)// && !feof(fp))
	{
		printf("%60s %20ld %4d\n",movies[i].title, movies[i].gross, movies[i].year);
		i++;
	}
}

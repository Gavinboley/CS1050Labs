/*****************************************************************************
 * CS1050
 * 11/12/2021
 * Lab 11
 * By Gavin Boley
 * gzbkxc
 *****************************************************************************/
#include <stdio.h>
#include <string.h>
#include "fight.h"
#define FILENAME "monster.csv"

int main(int argc, char * argv[])
{
    FILE * fp;
    char monster1[256] = {'\0'};
    char monster2[256] = {'\0'};
    int hb1; int hb2; 
    int armor1; int armor2; int hp1; int hp2; char attackdamage11[256] = {'\0'}; char attackdamage12[256] = {'\0'}; char attackdamage21[256] = {'\0'}; char attackdamage22[256] = {'\0'};
    
   	  fp = fopen(FILENAME,"r");
          if (NULL!=fp)
          {
             fgets(monster1,255,fp);
             monster1[255]='\0';
	     if(fp && !feof(fp))
	     {
		fscanf(fp, " %d,%d,%d,%[^,],%[^,],%s,", &armor1, &hp1, &hb1, attackdamage11, attackdamage21, monster1);
		while(!feof(fp))
		{
			int armortemp; int hptemp; int crittemp; 
			char attack1temp[256] = {'\0'};
			char attack2temp[256] = {'\0'};
			char nametemp[256] = {'\0'};
			fscanf(fp, " %d,%d,%d,%[^,],%[^,],%s,", &armortemp, &hptemp, &crittemp, attack1temp, attack2temp, nametemp); //this reads the file
			if(!strcmp(nametemp, "FrostGiant"))
			{
				armor2 = armortemp; hp2 = hptemp; hb2 = crittemp;
				strcpy(attackdamage12, attack1temp);  strcpy(attackdamage22, attack2temp); strcpy(monster2, nametemp);
			}
		}
	     }
	     SetSeed(0); //it is random pog
	     Fight(monster1, armor1, hp1, hb1, attackdamage11, attackdamage21, monster2, armor2, hp2, hb2, attackdamage12, attackdamage22);
             fclose(fp);
          }
  	  else
	  {
		printf("Something went wrong");
	  }
}

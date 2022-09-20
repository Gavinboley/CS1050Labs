/*
 * CS1050
 * Fall 2021
 * Lab 10
 * Gavin Boley
 * Nov 5 2021
 * gzbkxc
 */


// includes
#include <stdio.h>
#include <ctype.h>
// Need any other includes?


// Symbolic Constants
#define CLEARTEXT \
"Haven't felt right in a week\n"\
"And I'm thinning out\n"\
"And it hurts bad\n"\
"I gotta get back\n"\
"\n"\
"Hot head and dreamless sleep\n"\
"I could just slip down\n"\
"And on the wrong track\n"\
"I gotta get back\n"\
"\n"\
"I wanna spend the entire year\n"\
"Just face down\n"\
"And on my own time\n"\
"I wanna waste mine\n"\
"\n"\
"And spend the rest of it asking myself\n"\
"\"Is this who you are?\"\n"\
"And I don't know\n"\
"It just feels gross\n"\
"\n"\
"I don't think there's anything wrong\n"\
"I don't think there's anything wrong\n"\
"And I don't think there's anything wrong\n"\
"I don't think there's anything wrong\n"\
"\n"\
"Sunlight on the back of my arms\n"\
"Just thins me out\n"\
"To a different time\n"\
"I wanna waste mine\n"\
"\"\\\?\n\n\t\t- Snail Mail"



// Prototypes
void Encrypt(const char * in, char * out, int displacement);
void Decrypt(const char * in, char * out, int displacement);



// Main
int main(void)
{
	printf("cleartext: \n %s\n",CLEARTEXT);
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	char out[999] = {'\0'};
	Encrypt(CLEARTEXT, out, 5);
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("%s\n",out);
	char new[500] = {'\0'};                         //declares out value to encyrpt to and then new value to decrypt encrypt
	Decrypt(out, new, 5);
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("%s\n",new);
}



// Function implementations               
void Encrypt(const char * in, char * out, int displacement)
{
        while(*in != '\0') //sift through input 
        {
                if(isalpha(*in))
                {
                        *out = *in + displacement;
                        if(islower(*in) && *out > 'z')
                        {
                                *out = *out - 26;      //string in pointer for char is displaced by amount
                        }				//if statements are for wraparound 
                        if(isupper(*in) && *out > 'Z')
                        {
                                *out = *out - 26;
                        }
                }

        else
        {
                *out = *in; //if it's not a character of any kind keep it the same

        }
        out++;
        in++;
        }
	*out = '\0';
}
void Decrypt(const char * in, char * out, int displacement) //basically inverse function of encrypt
{
        while(*in != '\0')
        {
                if(isalpha(*in))
                {
                        *out = *in - displacement;
                        if(islower(*in) && *out < 'a')
                        {
                                *out = *out + 26;
                        }
                        if(isupper(*in) && *out < 'A')
                        {
                                *out = *out + 26;
                        }
                }

        else
        {
                *out = *in;

        }
        out++;
        in++;
        }
	*out = '\0';
}


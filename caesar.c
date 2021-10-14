#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

//Prompt user for key
int main(int argc, string argv[])
{
    //Prompt for 1 command line argument
    if(argc == 2)
    {
        //Prompt for digits only
        bool valid_key = false;
        for (int i = 0, n = strlen(argv[1]);i<n;i++)
        {
            if (isdigit(argv[1][i]) != 0)
             {
                valid_key = true;
             }
            else
             {
                printf("Usage: ./caesar key\n");
                return (1);
             }
        }
        //Cipher text:
        if (valid_key==true)
        {
            string plain = get_string("plaintext: ");
            int key = atoi(argv[1]);
            for (int i = 0, o = strlen(plain);i<o;i++)
            {
                if (isupper(plain[i]))
                {
                    plain[i] = ((plain[i]-65+key) % 26)+65;
                }
                else if (islower(plain[i]))
                {
                    plain[i] = ((plain[i]-97+key) % 26)+97;
                }
            }
            printf("ciphertext: %s\n",plain);
        }
    }
    else
    {
        printf("Error\n");
        return (1);
    }
}

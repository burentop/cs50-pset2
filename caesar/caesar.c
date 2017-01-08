#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define UPPERA 65
#define LOWERA 97

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Please enter only one argument for the program.\n");
        return 1;
    }
    
    string message;
    int k, length;
    char ciphered;
    
    k = atoi(argv[1]);
    
    printf("plaintext: ");
    message = get_string();
    length = strlen(message);
    
    printf("ciphertext: ");
    
    for (int i = 0; i < length; i++)
    {
        if (isalpha(message[i]))
        {
            if (isupper(message[i]))
            {
                ciphered = UPPERA + (((message[i] - UPPERA) + k) % 26);
            }
            else
            {
                ciphered = LOWERA + (((message[i] - LOWERA) + k) % 26);
            }
            printf("%c", ciphered);
        }
        else
        {
            printf("%c", message[i]);
        }
    }
    printf("\n");
}
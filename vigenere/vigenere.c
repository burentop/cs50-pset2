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
    
    int argumentlength = strlen(argv[1]);
    
    for (int i = 0; i < argumentlength; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Please use only alphanumeric for your key.\n");
            return 1;
        }
    }
    
    string message, key;
    int length, keylength, keycode, keyindex;
    char ciphered;
    
    printf("plaintext: ");
    message = get_string();
    length = strlen(message);
    key = argv[1];
    keylength = strlen(key);
    keyindex = 0;
    
    printf("ciphertext: ");
    
    for (int i = 0; i < length; i++)
    {
        if (isalpha(message[i]))
        {
            keycode = tolower(key[keyindex % keylength]) - LOWERA;
            if (isupper(message[i]))
            {
                ciphered = UPPERA + (((message[i] - UPPERA) + keycode) % 26);
            }
            else
            {
                ciphered = LOWERA + (((message[i] - LOWERA) + keycode) % 26);
            }
            printf("%c", ciphered);
            keyindex++;
        }
        else
        {
            printf("%c", message[i]);
        }
    }
    printf("\n");
}
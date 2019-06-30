#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Declare prototype for function that will convert characters into correct shift value
int shift(char c);

int main(int argc, string argv[])
{
    // Terminate if not 1 keyword
    if (argc != 2)
    {
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }
      
    // Check if each character in key is alphabetical
    for (int n = 0; n < strlen(argv[1]); n++)
    {   
        // Terminate program if non-digit input
        if (isalpha(argv[1][n]) == 0)
        {
            printf("Usage: ./vigenere keyword\n");
            return 1;   
        }       
    }
    
    // Convert each character of keyword to number
    int key = 0;
    for (int j = 0; j < strlen(argv[1]); j++)
    {    
        key = shift(argv[1][j]);
    }
    
    // Prompt user for plaintext
    string plaintext = get_string("plaintext: ");
    
    // Print ciphertext
    printf("ciphertext: ");

    // Iterate over every character in plaintext
    for (int i = 0; i < strlen(plaintext); i++)
    {
        // Create variable for each character of plaintext
        char c = plaintext[i];
        
        // Apply to alphabetical characters only
        if (isalpha(c) > 0)
        {

            // Capital letters
            if (isupper(c) > 0)
            {

                if (c + key > 90)
                {
                    // ASCII 64 is the character before 'A'
                    printf("%c", ((c + key) % 90) % 26 + 64);
                }
                else
                {
                    printf("%c", c + key);
                }  
            }
            
            // Lowercase letters
            else if (islower(c) > 0) 
            {
                if (c + key > 122)
                {
                    // ASCII 96 is the character before 'a'
                    printf("%c", ((c + key) % 122) % 26 + 96);
                }
                else
                {
                    printf("%c", c + key);
                }
            }
        }
        
        // Print symbols as they are
        else
        {
           printf("%c", c);
        }   
    }  
    printf("\n");
    return 0;
}

// Define shift function
int shift(char c)
{
    if isupper(c)
    {
        return c - 'A';
    }
    else
    {
        return c - 'a';
    }
}



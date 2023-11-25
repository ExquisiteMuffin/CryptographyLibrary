#include "include/SymmetricKeyAlgorithms.hpp"
#include "tools/Tools.h"
#include "tools/MathFunctions.h"

SymmetricKeyAlgorithm::SymmetricKeyAlgorithm() 
{
    // Constructor implementation
}

char **SymmetricKeyAlgorithm::SymmetricEncrypt() //Returns the encrypted message
{
    // Encryption
    int length = len_string(message);
    char **EncryptedMessage = (char **)malloc(length * sizeof(char *)); //Check later

    int len = 0;
    int temp;
    char *final = (char *)malloc(sizeof(char *));

    for (int i = 0; i < length; i++)
    {
        temp = message[i];
        int tlen = 0;
        if (is_prime(temp))
        {
            temp *= 2;
            temp += 1;
            final = int_to_str(temp);
            len = len_string(final);
            final[len] = 'e'; //append 'e' to final
            final[len + 1] = NUL; //Sets the end of the string to '\0'
            EncryptedMessage[i] = final; //Sets the ith element of the encrypted message to the encrypted value
        }
        else if (is_prime(temp + 1) || is_prime(temp + 3) || is_prime(temp + 3))
        {
            temp = alpha(temp) + 3; //Ecnryption method for this conditional
            tlen = len_digit(temp);
            final = (char *)malloc(tlen + 2); //Allocates tlen amount of bytes for the encrypted char
            final[0] = '_'; //add '_' to final
            memcpy(final + 1, int_to_str(temp), tlen); //Copies the final string into the specified range 1, length of digit
            len = len_string(final);
            final[len] = 'e'; //Append 'e' to the final string
            final[len + 1] = NUL; //Set the end of the string to '\0'
            EncryptedMessage[i] = final; //Sets the ith element of the encrypted message to the encrypted value
        }
        else if (temp % 8 == 0)
        {
            temp = 3 * (temp + 1) + 6;
            final = int_to_str(temp);
            len = len_string(final);
            final[len] = 'f';
            final[len + 1] = NUL; //Append NUL to final
            EncryptedMessage[i] = final;
        }
        else if (temp % 2 == 0)
        {
            temp = alpha(temp) - 1;
            tlen = len_digit(temp);
            final = (char *)malloc(tlen + 3);
            final[0] = '_';
            memcpy(final + 1, int_to_str(temp), tlen);
            len = len_string(final);
            final[len] = 'f';
            final[len + 1] = NUL;
            EncryptedMessage[i] = final;
        }
        else if (temp  % 3 == 0)
        {
            temp = beta(temp) + 6;
            final = int_to_str(temp); 
            len = len_string(final);
            final[len] = 't';
            final[len + 1] = NUL;
            EncryptedMessage[i] = final;
        }
        else
        {
            temp = beta(alpha(temp));
            tlen = len_digit(temp); 
            final = (char *)malloc(tlen + 3);
            final[0] = '_'; 
            // memcpy(final + 1, int_to_str(temp), tlen);
            len = len_string(final);
            final[len] = 't';
            final[len + 1] = NUL;
            EncryptedMessage[i] = final;
        }

        len += len_string(final);
    }
    free(final);
    return EncryptedMessage;
}

char *SymmetricKeyAlgorithm::SymmetricDecrypt() //Returns the decrypted message
{
    // Decryption logic
}

void SymmetricKeyAlgorithm::FreeEncryptedMessage(char **EncryptedMessage, int length)
{
    for (int i = 0; i < length; i++)
    {
        free(EncryptedMessage[i]); //Frees each string
    }
    free(EncryptedMessage); //Frees the overall list of strings after all strings are gone
}

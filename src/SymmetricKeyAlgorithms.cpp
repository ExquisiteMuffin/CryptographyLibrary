#include "include/SymmetricKeyAlgorithms.hpp"
#include "tools/tools.h"

SymmetricKeyAlgorithm::SymmetricKeyAlgorithm() 
{
    // Constructor implementation
}

std::string SymmetricKeyAlgorithm::encrypt() //Returns the encrypted message
{
    // Encryption
    char EncryptedMessage[99];
    int length = len_string(message);
    for (int i = 0; i < length; i++)
    {
        int temp;
        if (message[i] % 4 ==  0)
        {
            char final;
            temp = message[i];
            temp /= 4;
            temp += 2;
            final = int_to_str(temp);
        }
        else if (message[i]) //ADJUST LATER TO CHECK IF MESSAGE[i] IS PRIME
        {
            
        }
        else if (message[i] % 2 == 0)
        {
            message[i] /= 2;
            message[i] += 3;
        }
    }
}

std::string SymmetricKeyAlgorithm::decrypt() //Returns the decrypted message
{
    // Decryption logic
}

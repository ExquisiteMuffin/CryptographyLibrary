#include "include/SymmetricKeyAlgorithms.hpp"
#include <string>

SymmetricKeyAlgorithm::SymmetricKeyAlgorithm() 
{
    // Constructor implementation
}

std::string SymmetricKeyAlgorithm::encrypt() //Returns the encrypted message
{
    // Encryption
    char *EncryptedMessage = "";
    for (int i = 0; i < 5; i++) //ADJUST LOOP LATER
    {
        if (message[i] % 4 ==  0)
        {
            int temp = message[i];
            temp /= 4;
            temp += 2;
            if (temp % 2 == 0)
            {
                to_string()
            }
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

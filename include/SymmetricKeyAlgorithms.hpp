#ifndef SYMMETRIC_KEY_ALGORITHMS_HPP
#define SYMMETRIC_KEY_ALGORITHMS_HPP

#include <string>

class SymmetricKeyAlgorithm 
{
    public:
        SymmetricKeyAlgorithm();
        char **SymmetricEncrypt(); //Encrypt the message
        char *SymmetricDecrypt(); //Decrypt the message
        void FreeEncryptedMessage(char **EncryptedMessage, int length); //Frees the encrypted message
    private:
        char *message; //Message subject to encryption
};

#endif

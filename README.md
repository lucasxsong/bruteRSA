# crypt

A few assorted tools that I'm working on to help understand cryptography better. As of current, most of this code is in regards to RSA encryption. Disclaimer: based upon secure principles but is not secure at all. 😆


## keygen.cpp

Takes in two primes and a chosen e that is relatively prime to the product of the two primes. Spits back out the public and private keys.

Need to add some sort of primality test so that auto keygen will work.

## encrypt.cpp

Encrypts and decrypts a message in the form of an integer with the public and private key pair. Simplifies exponents that may result in integer overflow using an implementation of Fermat's Little Theorem. (FLT)

## decrypt.cpp

Decrypts a message in the form of an integer based upon the public and private key pair.

### decryptToFile.cpp

Allows user to enter a series of integers to be decrypted and writes the decrypted messages to a file that user specifies.

### intToChar

Uses a int to char map to translate a file full of integers to their char equivalents. 

## helper functions

### exponentFactorization

Helper function that factorizes large exponents to be used in encrypt and decrypt functions.

### fermatsLittleTheorem

Uses FLT to find the inverse mod.


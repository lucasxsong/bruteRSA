# crypt

A few assorted tools that I'm working on to help understand cryptography better. Disclaimer: works upon secure principles but is not secure at all. 

## rsaKeygen

Takes in two primes and a chosen e that is relatively prime to the product of the two primes. Spits back out the public and private keys.

Need to add some sort of primality test so that auto keygen will work.

## rsaEncrypt

Encrypts and decrypts a message in the form of an int with the public and private key pair. Simplifies exponents that may result in integer overflow using an implementation of Fermat's Little Theorem.

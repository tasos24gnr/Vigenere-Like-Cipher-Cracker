# Vigenere-Like-Cipher-Cracker
The Vigenere-Like Cipher Cracker is a tool designed to decrypt ciphertexts encrypted using a Vigenere-like cipher, where byte-wise XOR is used instead of traditional addition modulo 26. This program aims to aid in the decryption of encrypted messages without prior knowledge of the encryption key.

# Introduction

This repository contains a C program that can crack ciphertexts generated using a Vigenere-like cipher, where byte-wise XOR is used instead of addition modulo 26. The program employs a brute-force approach to find the correct key and decrypt the ciphertext.
How it Works

The program works by iterating through different key lengths and trying all possible bytes as the key. For each key, it performs XOR decryption with the ciphertext and checks if the resulting plaintext appears to be English-like based on statistical analysis of printable ASCII characters. If a suitable decryption is found, the decrypted plaintext and the corresponding key are printed.

# Usage
Clone the repository

    git clone https://github.com/tasos24gnr/Vigenere-Like-Cipher-Cracker.git



Compile the C program:

    gcc vigenere_cracker.c -o vigenere_cracker

Create a file named ciphertext.txt containing the ciphertext in hexadecimal format.

Run the program:

    ./vigenere_cracker

    The program will attempt to crack the ciphertext and print the decrypted plaintext along with the corresponding key.

# Example

Suppose you have a ciphertext stored in ciphertext.txt. After running the program, it may output something like this:

vbnet

Decrypted plaintext: JACK AND JILL WENT UP THE HILL TO FETCH A PAIL OF WATER JACK FELL DOWN AND BROKE HIS CROWN AND JILL CAME TUMBLING AFTER
Key: 01 01

